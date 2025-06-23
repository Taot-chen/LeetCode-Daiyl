#include <iostream>
#include <string>

template <typename T> inline T const& Max (T const& a, T const& b) {
    return a > b ? a : b;
}

int main() {
    int a = 22, b = 12;
    std::cout << "Max(a, b): " << Max(a, b) << std::endl;

    double c = 1.2;
    double d = 3.5;
    std::cout << "Max(c, d): " << Max(c, d) << std::endl;

    std::string e = "Hello";
    std::string f = "World";
    std::cout << "Max(e, f): " << Max(e, f) << std::endl;

    return 0;
}
