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

        int ring_buffer_request_push(RingBufferToken<T>& token);
};

template<class T>
typedef struct RingBufferToken {
    RingBuffer* pbuffer;
    T* pitem;
    int idx;
} RingBufferToken;

T& ring_buffer_token_item(RingBufferToken& token);
int ring_buffer_token_finish(RingBufferToken& token);

enum ItemState {
    ITEM_BLANK;
    ITEM_WRITING;
    ITEM_WRITED;
}

}

#endif
