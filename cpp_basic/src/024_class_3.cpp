#include <iostream>

class Box {
    protected:
        double width;
};

class SmallBox: Box {
    public:
        void setSmallWidth(double wid);
        double getSmallWidth(void);
};

double SmallBox::getSmallWidth(void) {
    return width;
}

void SmallBox::setSmallWidth(double wid) {
    width = wid;
}

int main() {
    SmallBox box;

    // 使用成员函数设置宽度
    box.setSmallWidth(4.0);
    std::cout << "Width of box : " << box.getSmallWidth() << std::endl;

    // 使用成员函数设置宽度
    // box.width = 5.0;    // Error
    // std::cout << "Width of box : " << box.width << std::endl;   // Error

    return 0;
}
