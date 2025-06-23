#include <iostream>
#include <thread>

int main() {
    std::thread t3([](int count){
        for (int i = 0; i < count; i++) {
            std::cout << "Hello from thread (lambda)!\n";
        }
    }, 5);  // 创建线程，传递 Lambda 表达式和参数
    t3.join();
    return 0;
}
