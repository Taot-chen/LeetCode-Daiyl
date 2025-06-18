#include <iostream>

class Box {
    double width;   // width 是一个私有成员
    public:
        double length;
        void setWidth(double wid);
        double getWidth( void );
};

// 成员函数定义
double Box::getWidth(void) {
    return width ;
}
 
void Box::setWidth( double wid ) {
    width = wid;
}

int main() {
    Box box;

    // 不使用成员函数设置长度
    box.length = 10.0;  // OK: 因为 length 是公有的
    std::cout << "lenght: " << box.length << std::endl;

    // 不使用成员函数设置宽度
    // box.width = 10.0; // Error: 因为 width 是私有的

    box.setWidth(10.0); // 使用成员函数设置宽度
    std::cout << "width: " << box.getWidth() << std::endl;  // 这里访问也只能通过成员函数进行

    return 0;
}
