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
        static int getCount(){
            return objCnt;
        }
    private:
        double length;
        double breadth;
        double height;
};

// 初始化类 Box 的静态成员
int Box::objCnt = 0;
int main() {
    // 在创建对象之前输出对象的总数
    cout << "Inital Stage Count: " << Box::getCount() << endl;

    Box Box1(3.3, 1.2, 1.5);    // 声明 box1
    Box Box2(8.5, 6.0, 2.0);    // 声明 box2

    // 在创建对象之后输出对象的总数
    cout << "Final Stage Count: " << Box::getCount() << endl;
    cout << "Final Stage Count: " << Box1.getCount() << endl;

    return 0;
}
