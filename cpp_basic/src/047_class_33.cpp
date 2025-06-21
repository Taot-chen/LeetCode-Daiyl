/*
重载赋值运算符（ = ）
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
};

int main() {
    Distance d1(1, 2), d2(3, 4);

    std::cout << "First Distance : ";
    d1.displayDistance();

    std::cout << "Second Distance : ";
    d2.displayDistance();

    d1 = d2;
    std::cout << "First Distance : ";
    d1.displayDistance();

    return 0;
}


/*
输出：

First Distance : F: 1, I: 2
Second Distance : F: 3, I: 4
First Distance : F: 3, I: 4
*/
