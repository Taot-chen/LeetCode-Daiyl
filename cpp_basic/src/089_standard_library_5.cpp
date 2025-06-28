#include <iostream>

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    // 检查输入操作是否成功
    if (std::cin.fail()) {
        std::cerr << "Invalid input!" << std::endl;
    } else {
        std::cout << "You entered: " << num << std::endl;
    }
    return 0;
}
