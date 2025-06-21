/*
重载提取运算符 >> 和插入运算符 <<
*/

#include <iostream>
using namespace std;

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
        friend ostream& operator << (
            ostream& output,
            const Distance& d
        ) {
            output << "F: " << d.feet << ", I: " << d.inches;
            return output;
        }

        friend istream& operator >> (
            istream& input,
            Distance& d
        ) {
            input >> d.feet >> d.inches;
            return input;
        }
};


int main() {
    Distance d1(11, 10), d2(-5, 11);
    Distance d3;
    std::cout << "Enter the value of object : " << std::endl;
    std::cin >> d3;
    std::cout << "First Distance : " << d1 << std::endl;
    std::cout << "Second Distance :" << d2 << std::endl;
    std::cout << "Third Distance :" << d3 << std::endl;

    return 0;
}

/*
输出：

Enter the value of object :
1 -10
First Distance : F: 11, I: 10
Second Distance :F: -5, I: 11
Third Distance :F: 1, I: -10
*/
