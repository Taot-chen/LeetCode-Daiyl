#include <iostream>

// 基类 Shape
class Shape {
    public:
        void setWidth(int w) {
            width = w;
        }
        void setHeight(int h) {
            height = h;
        }
    protected:
        int width;
        int height;
};

// 基类 PaintCost
class PaintCost {
    public:
        int getCost(int area) {
            return area * 70;
        }
};

// 派生类
class Rectangle: public Shape, public PaintCost {
    public:
        int getArea() {
            return (width * height);
        }
};

int main() {
    Rectangle rect;
    int area;
    rect.setWidth(5);
    rect.setHeight(7);
    area = rect.getArea();

    std::cout << "Total area: " << area << std::endl;
    std::cout << "Total paint cost: $" << rect.getCost(area) << std::endl;

    return 0;
}
