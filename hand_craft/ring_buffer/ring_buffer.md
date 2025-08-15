## Ring Buffer

ring buffer，环形缓冲区，在处理生产者-消费者模型时，比较有优势。考虑这样的场景，在一个系统中，有多个线程不断地产生数据（生产者），同时又有其他线程持续的处理消耗这些数据（消费者），ring buffer 就能够很好地在两者之间起到缓冲和协调作用。

线程安全在多线程下是必须要考虑的问题，多个线程对 ring buffer 进行读写操作的时候，需要通过合理的机制来保证数据的一致性和操作的原子性。


一般构建一个环形缓冲区需要一段连续的内存空间以及四个指针：

* pHead，指向内存空间首地址
* pTail，指向内存空间的尾地址
* pRead，读指针
* pWrite，写指针


线程安全问题：

* 锁机制，在线程访问 ring buffer 之前，需要先获取锁，若无法获取锁，就需要等待，知道其他线程释放锁。但是锁机制会带来额外的开销，并且可能出现死锁的情况
* 原子操作，通过原子指令，保证对数据的操作不可分割，不被其他线程打断
* 无锁数据结构，通过巧妙设计，避免使用锁，提高并发性能，实现难度较大


### 1 naive 实现

在实现上，有两个指针，head和tail，在队尾写入，移动尾指针；在队头读取，移动头指针。使用数组来存储数据，一次性分配好，写入超过数组末尾时，会回绕到开始位置继续写入，读取也是类似的。

当头指针和尾指针相遇时，需要准确判断出，环形队列是空，还是满，从而决定是否可以继续写入，是否能够继续读取。

用一个变量 same_cycle，来完成对环形队列空/满的判断。

* 初始，head = 0, tail = 0，都指向环形队列的位置0处。把head或tail指针，在环形队列中转了完整一圈，叫一个轮次。初始，same_cycle = 1(true), 表示head和tail 两个指针是同一轮次的。
* 写入时，如果队列已满，则无法写入，直接返回失败。如果队列未满，则在tail 位置写入，tail移动至下一个位置(可能会回绕)。如果下一个位置为数组位置0，则表示开始了一个新的轮次，因此设置 same_cycle = 0(false)。
* 读取时，如果队列已空，则无法读取，直接返回失败。如果队列未空，则从head位置读取，head移动至下一个位置(可能会回绕)。如果下一个位置为数组位置0，则表示开始了一个新的轮次，与tail指针的轮次变得相同，因此设置 same_cycle = 1(true)。

因此环形队列为空的判断规则为：`(head == tail) && same_cycle`

环形队列已满的判断规则为：`(head == tail) && !same_cycle`


`ring_buffer_naive.h`

```cpp
#ifndef RING_BUFFER_NAIVE_H
#define RING_BUFFER_NAIVE_H

namespace my_ring_buffer {

template<class T>
class RingBuffer {
    private:
        T* pbuf;
        int capcity;
        int head;
        int tail;
        bool same_cycle;
    public:
        // 构造函数
        RingBuffer(int capcity): capcity(capcity), head(0), tail(0), same_cycle(true) {
            if (capcity > 0) {
                pbuf = new T[capcity];
            }
        }
        // 析构
        ~RingBuffer() {
            delete[] pbuf;
        }

        int push(const T& item);
        int pop(T& item);

        bool full();
        bool empty();
};

}

#endif
```

`ring_buffer_naive.cpp`

```cpp
#include <iostream>
#include "ring_buffer_naive.h"



namespace my_ring_buffer {

template<class T>
int RingBuffer<T>::push(const T& item) {
    if (full()) return -1;
    pbuf[tail] = item;
    tail = (tail + 1) % capcity;
    if (tail == 0) same_cycle = false;
    return 0;
}

template<class T>
int RingBuffer<T>::pop(T& item) {
    if (empty()) return -1;
    item = pbuf[head];
    head = (head + 1) % capcity;
    if (head == 0) same_cycle = 1;
    return 0;
}

template<class T>
bool RingBuffer<T>::full() {
    return (head == tail) && !same_cycle;
}

template<class T>
bool RingBuffer<T>::empty() {
    return (head == tail) && same_cycle;
}

}
```


测试：

`test_naive.cpp`

```cpp
#include <iostream>
#include "ring_buffer_naive.cpp"

int main() {
    my_ring_buffer::RingBuffer<int> ring_buffer(3);
    bool iret = ring_buffer.empty();
    printf("ring_queue is%s empty!\n", iret ? "" : " not");

    int val = 1;
    ring_buffer.push(val++);
    ring_buffer.push(val++);
    ring_buffer.push(val++);

    int pop_val;
    ring_buffer.pop(pop_val);
    std::cout << "pop val: " << pop_val << std::endl;
    ring_buffer.push(val++);

    iret = ring_buffer.empty();
    printf("ring_queue is%s empty!\n", iret ? "" : " not");

    ring_buffer.push(val++);
    ring_buffer.pop(pop_val);
    ring_buffer.pop(pop_val);
    ring_buffer.pop(pop_val);
    ring_buffer.pop(pop_val);

    return 0;
}
```



### 2 无锁高并发实现

在多线程场景下，多生产者并发写入、多消费者并发读取，通过 ring buffer 来解决并发问题。使用无锁的技术来实现，避免加锁解锁这种重操作对性能的影响。

无锁数据结构中，主要的技术实现手段是使用cpu的原子指令。

gcc提供了 一系列 builtin 的原子函数，我们要用的：

```cpp
bool __sync_bool_compare_and_swap(type *ptr, type oldval， type newval);
```

这个函数，会将 ptr指向内存中的值，与oldval 比较，如果相等，则把 ptr执行内存的值修改为 newval. 整个比较和修改的全过程，要以原子方式完成。如果比较相等，并且修改成功，则返回true。其它情况都返回false。

用原子指令，来增强一下环形队列，实现多生产多消费者并发读写。

* 对于写入，每个producer 必须先获得写锁。成功获得写锁之后，写入数据，将tail移动到下一个位置，最后释放写锁。
* 对于读取，每个consumer 必须先获得读锁。成功获得读锁之后，读取数据，将head移动到下一个位置，最后释放读锁。

与传统通过`mutex`控制对共享数据的读写是完全一样的，只是技术实现上用原子指令来实现，这种实现方式叫无锁数据结构。

对于`head`和`tail`这样的变量，由于多个线程会并发读写，因此需要用 `volatile` 来修饰它们，不让cpu core 缓存它们，避免读到旧数据。


稍作修改：

`ring_buffer_atomic.h`

```cpp
#ifndef RING_BUFFER_NAIVE_H
#define RING_BUFFER_NAIVE_H

namespace my_ring_buffer {

template<class T>
class RingBuffer {
    private:
        T* pbuf;
        int capcity;
        
        volatile int write;
        volatile int read;

        volatile int head;
        volatile int tail;
        volatile bool same_cycle;
    public:
        // 构造函数
        RingBuffer(int capcity): capcity(capcity), head(0), tail(0), same_cycle(true) {
            if (capcity > 0) {
                pbuf = new T[capcity];
            }
        }
        // 析构
        ~RingBuffer() {
            delete[] pbuf;
        }

        int push(const T& item);
        int pop(T& item);

        bool full();
        bool empty();
};

}

#endif
```



`ring_buffer_atomic.cpp`

```cpp
#include <iostream>
#include <cstalib>
#include "ring_buffer_naive.h"

#define CAS(ptr, oldptr, newptr) __sync_bool_compare_and_swap(ptr, oldptr, newptr)

namespace my_ring_buffer {

template<class T>
int RingBuffer<T>::push(const T& item) {
    // try to set write flag
    while (1) {
        if (full()) return -1;
        if (CAS(write, 0, 1)) break;    // set write flag successfully
    }
    pbuf[tail] = item;
    tail = (tail + 1) % capcity;
    if (tail == 0) same_cycle = false;

    // reset write flag
    CAS(write, 1, 0);
    return 0;
}

template<class T>
int RingBuffer<T>::pop(T& item) {
    // try to set read flag
    while (1) {
        if (empty()) return -1;
        if (CAS(read, 0, 1)) break; // set read flag successfully
    }
    item = pbuf[head];
    head = (head + 1) % capcity;
    if (head == 0) same_cycle = 1;

    // reset read flag
    CAS(read, 1, 0);
    return 0;
}

template<class T>
bool RingBuffer<T>::full() {
    return (head == tail) && !same_cycle;
}

template<class T>
bool RingBuffer<T>::empty() {
    return (head == tail) && same_cycle;
}

}
```


### 3 性能优化

目前的 ring buffer 已经能够支持多生产者和多消费者并发操作，数据操作模式为：

* 生产者准备好数据，然后push()方法放入环形队列中；
* 消费者准备好接收的缓冲区，然后调用pop()方法将数据写入接收缓冲区中。

这种模式下，生产者准备数据过程中，需要分配内存。把数据写入环形队列后，这个内存就不需要了，得释放掉。这样，会导致生产者频繁进行内存分配和释放的动作。

对性能要求更苛刻的系统，希望生产者能直接使用环形队列中的内存，直接写入，这样就不需要生产者再分配内存了。



这种思路下，环形队列和生产者之间的交互关系变为：

* 生产者调用 push 方法，获得一个可以写入的token；
* 生产者通过token 获取内存地址，向这个地址进行数据写入；
* 生产者调用 token.finish()方法, 通知环形队列已经完成写入。


多个producer(p1, p2, p3) 并发在环形队列尾部写入，它们的速度不一定相同，因此并发写入区域会形成正在写入区域、写入完成区域互相交错的情况。这种情况下，消费者读取时，把tail 作为上限，并且要判断区域是已写入完成状态，才可以读取进行消费。

