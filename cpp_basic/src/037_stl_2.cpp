#include <iostream>
#include <tr1/array>

int main () {
    std::tr1::array<int, 10> a;
    std::cout << a.size() << std::endl;

    std::tr1::array<int, 0> b;
    std::cout << b.size() << std::endl;

    return 0;
}