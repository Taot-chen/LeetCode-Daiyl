#include <iostream>
using namespace std;

class Box {
    double width;
    public:
        friend void printWidth(Box box);
        void setWidth(double wid);
};

void Box::setWidth(double wid) {
    width = wid;
}

// printWidth() 不是任何类的成员函数
void printWidth(Box box) {
    // 因为 printWidth() 是 Box 的友元，它可以直接访问该类的任何成员
    cout << "Width of box: " << box.width << endl;
}

int main() {
    Box box;

    // 使用成员函数设置宽度
   box.setWidth(10.0);
   
   // 使用友元函数输出宽度
   printWidth(box);

   return 0;
}
