#include <iostream>


/*
平常使用的加运算符（ + ）、减运算符（ - ）、乘运算符（ * ）和除运算符（ / ）都属于二元运算符。
下面重载加运算符（ + ）
*/

class Box {
    double length;
    double breadth;
    double height;
    public:
        double getV(void) {
            return this->length * this->breadth * this->height;
        }
        void setLength(double len) {
            this->length = len;
        }
        void setBreadth(double bread) {
            this->breadth = bread;
        }
        void setHeight(double heig) {
            this->height = heig;
        }

        // 重载 + 运算符，用于把两个 Box 对象相加
        Box operator + (const Box& b) {
            Box box;
            box.length = this->length + b.length;
            box.breadth = this->breadth + b.breadth;
            box.height = this->height + b.height;
            return box;
        }
};

int main() {
    Box b1;
    Box b2;
    Box b3;
    b1.setLength(1.1);
    b1.setBreadth(2.1);
    b1.setHeight(3.1);

    b2.setLength(4.1);
    b2.setBreadth(5.1);
    b2.setHeight(6.1);

    std::cout << "V of b1: " << b1.getV() << std::endl;
    std::cout << "V of b2: " << b2.getV() << std::endl;

    b3 = b1 + b2;
    std::cout << "V of b3: " << b3.getV() << std::endl;

    return 0;
}


/*
输出：

V of b1: 7.161
V of b2: 127.551
V of b3: 344.448
*/