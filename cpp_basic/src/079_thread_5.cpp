#include <iostream>
#include <thread>

// 一个简单的函数，作为线程的入口函数
void foo(int Z) {
    for (int i = 0; i < Z; i++) {
        std::cout << "线程使用函数指针作为可调用参数\n";
    }
}

// 可调用对象的类定义
class ThreadObj {
public:
    void operator()(int x) const {
        for (int i = 0; i < x; i++) {
            std::cout << "线程使用函数对象作为可调用参数\n";
        }
    }
};

int main() {
    std::cout << "线程 1 、2 、3 独立运行" << std::endl;

    std::thread t1(foo, 3);
    std::thread t2(ThreadObj(), 3);
    std::thread t3([](int x){
        for (int i = 0; i < x; i++) {
            std::cout << "线程使用 lambda 表达式作为可调用参数\n";
        }
    }, 3);

    t1.join();
    t2.join();
    t3.join();
    return 0;
}
