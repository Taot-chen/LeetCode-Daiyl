#include <iostream>

#define MKSTR(x)    #x

int main() {
    std::cout << MKSTR(HELLO C++) << std::endl;
    return 0;
}
