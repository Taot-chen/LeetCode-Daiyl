#include <iostream>

class Box {
    public:
        double length;
        double breadth;
        double height;
        double getV(void);
        void setShape(double len, double bre, double hei);
};

double Box::getV(void) {
    return length * breadth * height;
}

void Box::setShape(double len, double bre, double hei) {
    length = len;
    breadth = bre;
    height = hei;
}


int main() {
    Box box1;
    Box box2;
    double v = 0.0;

    box1.height = 10.0;
    box1.length = 12.0;
    box1.breadth = 13.0;
    v = box1.height * box1.length * box1.breadth;
    std::cout << "V of box1: " << v << std::endl;

    box2.setShape(4.0, 5.0, 6.0);
    v = box2.getV();
    std::cout << "V of box2: " << v << std::endl;
    return 0;
}
