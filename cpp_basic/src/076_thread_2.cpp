#include <iostream>
#include <thread>

class PrintTask {
    public:
        void operator () (int count) const {
            for (int i = 0; i < count; i++) {
                std::cout << "Hello from thread (function object)!\n";
            }
        }
};

int main() {
    std::thread t2(PrintTask(), 5); // 创建线程，传递函数对象和参数
    t2.join(); // 等待线程完成
    return 0;
}
