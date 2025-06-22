#include <iostream>

// 基类 Shape，表示形状
class Shape {
    protected:
        int width, height;
    public:
        // 构造函数，带有默认参数
        Shape(int a = 0, int b = 0): width(a), height(b) {}

        // 虚函数 area，用于计算面积
        // 使用 virtual 关键字，实现多态
        virtual int area() {
            std::cout << "Shape class area: " << std::endl;
            return 0;
        }
};

// 派生类 Rectangle，表示矩形
class Rectangle: public Shape {
    public:
        // 构造函数，使用基类构造函数初始化 width 和 height
        Rectangle(int a = 0, int b = 0) : Shape(a, b) {}

        // 重写 area 函数，计算矩形面积
        int area() override {
            std::cout << "Rectangle class area: " << std::endl;
            return width * height;
        }
};

// 派生类 Triangle，表示三角形
class Triangle : public Shape {
    public:
        // 构造函数，使用基类构造函数初始化 width 和 height
        Triangle(int a = 0, int b = 0) : Shape(a, b) { }
 
        // 重写 area 函数，计算三角形面积
        int area() override { 
            std::cout << "Triangle class area: " << std::endl;
            return (width * height / 2); 
        }
};


int main() {
    Shape* shape;   // 基类指针
    Rectangle rec(10, 7);
    Triangle tri(10, 5);

    shape = &rec;
    std::cout << "Rectangle Area: " << shape->area() << std::endl;

    shape = &tri;
    std::cout << "Triangle Area: " << shape->area() << std::endl;
    return 0;
}
