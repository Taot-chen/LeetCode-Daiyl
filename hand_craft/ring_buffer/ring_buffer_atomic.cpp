#include <iostream>
#include <cstalib>
#include "ring_buffer_atomic.h"

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
