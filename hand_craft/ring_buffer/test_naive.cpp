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
