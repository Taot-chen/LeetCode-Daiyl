#include <iostream>

void process(int&)  { std::cout << "Lvalue\n"; }
void process(int&&) { std::cout << "Rvalue\n"; }

template<typename T>
void relay(T&& arg) {
    process(std::forward<T>(arg));  // 正确传递值类别
}

int main() {
    int x = 10;
    relay(x);   // 输出 "Lvalue"（左值转发）
    relay(20);  // 输出 "Rvalue"（右值转发）
    relay(std::move(x));    // 输出 "Rvalue"（右值转发）
    return 0;
}
