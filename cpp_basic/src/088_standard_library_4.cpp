#include <iostream>
#include <iomanip>

int main() {
    double pi = 3.14159;

    // 设置输出精度
    std::cout << std::setprecision(3) << pi << std::endl;

    // 设置输出宽度和对齐方式
    std::cout << std::setw(10) << std::left << pi << std::endl;
    std::cout << std::setw(15) << std::right << pi << std::endl;

    return 0;
}
