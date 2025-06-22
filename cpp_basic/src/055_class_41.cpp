#include <iostream>

// 基类
class Shape {
    public:
        // 提供接口框架的纯虚函数
        virtual int getArea() = 0;
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

// 派生类
class Rectangle: public Shape {
    public:
        int getArea() { 
            return (width * height); 
        }
};

class Triangle: public Shape {
    public:
    int getArea() { 
        return (width * height)/2; 
    }
};

int main() {
    Rectangle rect;
    Triangle tria;

    rect.setWidth(5);
    rect.setHeight(7);
    std::cout << "Total Rectangle area: " << rect.getArea() << std::endl;

    tria.setWidth(5);
    tria.setHeight(7);
    std::cout << "Total Triangle area: " << tria.getArea() << std::endl;
    return 0;
}
