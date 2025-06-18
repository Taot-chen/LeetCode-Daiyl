#include <iostream>

void swap(int& a, int& b);

int main() {
    int a = 1;
    int b = 2;
    std::cout << "Before:\n" << a << " " << b << std::endl;

    swap(a, b);
    std::cout << "After:\n" << a << " " << b << std::endl;
    return 0;
}

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
    return;
}
