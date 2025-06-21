/*
s函数调用运算符 () 可以被重载用于类的对象。
当重载 () 时，不是创造了一种新的调用函数的方式，相反地，这是创建一个可以传递任意数目参数的运算符函数。
*/

#include <iostream>

class Distance {
    private:
        int feet;   // 0 到无穷
        int inches; // 0 到 12
    public:
        // 构造函数
        Distance() {
            feet = 0;
            inches = 0;
        }
        Distance(int f, int i) {
            feet = f;
            inches = i;
        }
        void operator = (const Distance& d) {
            this->feet = d.feet;
            this->inches = d.inches;
        }

        void displayDistance() {
            std::cout << "F: " << this->feet << ", I: " << this->inches << std::endl;
        }

        Distance operator () (int a, int b, int c) {
            Distance d;
            // 随便算一下
            d.feet = a + c + 10;
            d.inches = b + c + 10;
            return d;
        }
};

int main() {
    Distance d1(1, 2), d2;

    std::cout << "First Distance : ";
    d1.displayDistance();

    d2 = d1(3, 4, 5);
    std::cout << "Second Distance : ";
    d2.displayDistance();

    return 0;

}

/*
输出：

First Distance : F: 1, I: 2
Second Distance : F: 18, I: 19
*/
