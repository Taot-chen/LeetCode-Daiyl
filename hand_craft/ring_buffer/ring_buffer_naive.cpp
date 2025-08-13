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


