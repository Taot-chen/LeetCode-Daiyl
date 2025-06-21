/*
重载递增运算符（ ++ ）、递增运算符（ ++ ），包括前缀和后缀两种用法
*/

#include <iostream>

class Time {
    private:
        int hours;  // 0 到 23
        int minutes;    // 0 到 59
    public:
        // 构造函数
        Time() {
            hours = 0;
            minutes = 0;
        }
        Time(int h, int m): hours(h), minutes(m) {};

        void displayTime() {
            std::cout << "H: " << hours << " M: " << minutes << std::endl;
        }

        // 重载前缀递增运算符（ ++ ）
        Time operator ++ () {
            ++minutes;
            if (minutes >=60) {
                minutes -= 60;
                ++hours;
            }
            if (hours >= 24) {
                hours -= 24;
            }
            return Time(hours, minutes);
        }

        // 重载后缀递增运算符（ ++ ）
        Time operator ++ (int) {    // int 在 括号内是为了向编译器说明这是一个后缀形式，而不是表示整数
            // 保存原始值
            Time t(hours, minutes);
            ++minutes;
            if (minutes >=60) {
                minutes -= 60;
                ++hours;
            }
            if (hours >= 24) {
                hours -= 24;
            }
            // 返回旧的原始值
            return t;
        }

        // 重载前缀递减运算符（ -- ）
        Time operator -- () {
            --minutes;
            if (minutes < 0) {
                minutes += 60;
                --hours;
            }
            if (hours < 0) {
                hours += 24;
            }
            return Time(hours, minutes);
        }

        // 重载后缀递减运算符（ -- ）
        Time operator -- (int) {
            // 保存原始值
            Time t(hours, minutes);
            --minutes;
            if (minutes < 0) {
                minutes += 60;
                --hours;
            }
            if (hours < 0) {
                hours += 24;
            }
            // 返回旧的原始值
            return t;
        }
};

int main() {
    Time t1(11, 59), t2(23, 59), t3(0, 0), t4(23, 00);
    
    t1.displayTime();
    std::cout << "-->";
    ++t1;
    t1.displayTime();
    t2.displayTime();
    std::cout << "-->";
    t2 = t2++;
    t2.displayTime();

    t3.displayTime();
    std::cout << "-->";
    --t3;
    t3.displayTime();
    t4.displayTime();
    t4 = t4--;
    std::cout << "-->";
    t4.displayTime();

    return 0;
}

/*
输出：

H: 11 M: 59
-->H: 12 M: 0
H: 23 M: 59
-->H: 23 M: 59
H: 0 M: 0
-->H: 23 M: 59
H: 23 M: 0
-->H: 23 M: 0
*/
