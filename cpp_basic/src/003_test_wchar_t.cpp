#include <iostream>

int  main() {
    wchar_t ch = 'a';
    std::cout << "ch: " << ch << std::endl;
    std::cout << "sizeof(ch): " << sizeof(ch) << std::endl;
    std::cout << "sizeof(int): " << sizeof(int) << std::endl;
    std::cout << "sizeof(long long int): " << sizeof(long long int) << std::endl;
    std::cout << "sizeof(long int): " << sizeof(long int) << std::endl;
    std::cout << "sizeof(short int): " << sizeof(short int) << std::endl;
    return 0;
}
