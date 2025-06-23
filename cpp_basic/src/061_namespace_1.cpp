#include <iostream>

// 第一个命名空间
namespace firt_space {
    int a = 0;
    void func() {
        std::cout << "Inside first_space" << std::endl;
    }
}

// 第二个命名空间
namespace second_space {
    double a = 1.1;
    void func() {
        std::cout << "Inside second_space" << std::endl;
    }
}

int main() {
    auto a = firt_space::a;
    std::cout << "a = " << a << std::endl;
    firt_space::func();

    second_space::a += 2.2;
    std::cout << "second_space::a: " << second_space::a << std::endl;
    second_space::func();

    return 0;
}
