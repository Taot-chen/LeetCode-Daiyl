#include <iostream>

#define MIN(a, b) (a < b ? a : b)

int main() {
    int i, j;
    i = 100;
    j = 10;
    std::cout << "MIN(i, j): " << MIN(i, j) << std::endl;
    return 0;
}
