#include <iostream>
using namespace std;

class Box {
    public:
        static int objCnt;
        Box(double l=2.0, double b = 2.0, double h = 1.0) {
            cout <<"调用构造函数。" << endl;
            length = l;
            breadth = b;
            height = h;
            objCnt += 1;
        }
        double Volume() {
            return length * breadth * height;
        }
        int compare(Box box) {
            return this -> Volume() > box.Volume();
        }
    private:
        double length;
        double breadth;
        double height;
};

// 初始化类 Box 的静态成员
int Box::objCnt = 0;
int main() {
    Box Box1(3.3, 1.2, 1.5);    // 声明 box1
    Box Box2(8.5, 6.0, 2.0);    // 声明 box2

    cout << "Total objs: " << Box::objCnt << endl;
    cout << "Total objs: " << Box1.objCnt << endl;

    return 0;
}
