#include<iostream>

int& getStaticRef() {
    static int a = 5;
    return a;
}

int main() {
    int& ref = getStaticRef();
    std::cout << "初始值： " << ref << std::endl;

    ref = 10;
    std::cout << "修改后： " << ref << std::endl;

    std::cout << "再次调用： " << getStaticRef() << std::endl;

    return 0;
}
