#include <iostream>

/*
一元运算符只对一个操作数进行操作。一元运算符通常出现在它们所操作的对象的左边，比如 !obj、-obj 和 ++obj，但有时它们也可以作为后缀，比如 obj++ 或 obj--。
*/

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

        void displayDistance() {
            std::cout << "F: " << this -> feet << "， I: " << this -> inches << std::endl;
        }

        // 重载负运算符（ - ）
        Distance operator - () {
            int feet = -1 * this -> feet;
            int inches = -1 * this -> inches;
            return Distance(feet, inches);
        }
};


int main() {
    Distance d1(11, 10), d2(-5, 11);

    d1.displayDistance();
    d1 = -d1;
    d1.displayDistance();

    d2.displayDistance();
    d2 = -d2;
    d2.displayDistance();
    return 0;
}

/*
输出：
F: 11， I: 10
F: -11， I: -10
F: -5， I: 11
F: 5， I: -11
*/
