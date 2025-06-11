#include <iostream>

int main() {
    int a = 10;
    float b = static_cast<float>(a);
    float c = reinterpret_cast<float&>(a);
    std::cout << "a: " << a << std::endl;
    std::cout << "static_cast<float>(a): " << b << std::endl;
    std::cout << "reinterpret_cast<float&>(a): " << c << std::endl;
    return 0;
}
