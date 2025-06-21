/*
下标操作符 [] 通常用于访问数组元素。重载该运算符用于增强操作 C++ 数组的功能。
*/

#include <iostream>

const int SIZE = 10;

class safeArray {
    private:
        int arr[SIZE];
    public:
        safeArray() {
            register int i;
            for (i = 0; i < SIZE; i++) {
                arr[i] = i;
            }
        }
        int operator [] (int i) {
            if (i >= SIZE) {
                std::cout << "索引超过最大值" << std::endl;
                // 返回第一个元素
                return arr[0];
            }
            return arr[i];
        }
};

int main() {
    safeArray a;

    std::cout << "a[2] 的值为 : " << a[2] << std::endl;
    std::cout << "a[9] 的值为 : " << a[9] << std::endl;
    std::cout << "a[15] 的值为 : " << a[15] << std::endl;

    return 0;
}

/*
输出：

a[2] 的值为 : 2
a[9] 的值为 : 9
a[15] 的值为 : 索引超过最大值
0
*/
