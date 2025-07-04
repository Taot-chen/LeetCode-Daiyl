#include <iostream>

int main() {
    for (int a = 0, b = 1; a < 100; a = std::exchange(b, a+b)) {
        std::cout << a<< " ";
    }
    return 0;
}
