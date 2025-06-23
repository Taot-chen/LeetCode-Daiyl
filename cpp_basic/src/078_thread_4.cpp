#include <iostream>
#include <thread>

void increment(int& x) {
    ++x;
}

int main() {
    int num = 0;
    std::thread t(increment, std::ref(num));    // 使用 std::ref 传递引用
    t.join();
    std::cout << "Value after increment: " << num << std::endl;
    return 0;
}
