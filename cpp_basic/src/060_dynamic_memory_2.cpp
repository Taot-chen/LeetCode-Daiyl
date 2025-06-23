#include <iostream>

class Box {
    public:
        Box() {
            std::cout << "调用构造函数！" << std::endl;
        }
        ~Box() {
            std::cout << "调用析构函数！" << std::endl;
        }
};

int main() {
    Box* box = new Box[4];
    delete[] box;   // 删除数组
    return 0;
}
