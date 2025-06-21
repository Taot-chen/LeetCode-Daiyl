#include <iostream>

/*
重载关系运算符
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
            std::cout << "F: " << this -> feet << ", I: " << this -> inches << std::endl;
        }

        // 重载负运算符（ - ）
        Distance operator - () {
            int feet = -1 * this -> feet;
            int inches = -1 * this -> inches;
            return Distance(feet, inches);
        }

        // 重载小于运算符（ < ）
      bool operator < (const Distance& d) {
        if (this->feet < d.feet) return true;
        if (this->feet == d.feet && this->inches < d.inches) return true;
        return false;
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

    if (d1 < d2) {
        std::cout << "d1 is less than d2 " << std::endl;
    } else {
        std::cout << "d2 is less than d1 " << std::endl;
    }
    return 0;
}

/*
输出：

F: 11, I: 10
F: -11, I: -10
F: -5, I: 11
F: 5, I: -11
d1 is less than d2
*/
