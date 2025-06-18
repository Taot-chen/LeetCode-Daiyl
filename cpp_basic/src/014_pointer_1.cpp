#include <iostream>

int main() {
    int var1;
    char var2[10];

    std::cout << "var1 变量的地址： " << &var1 << std::endl;
    std::cout << "var2 变量的地址： " << &var2 << std::endl;

    return 0;
}
