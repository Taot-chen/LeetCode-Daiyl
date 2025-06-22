#include <iostream>

class Addr {
    private:
        // 对外隐藏的数据
        int total;
    public:
        Addr(int i = 0) {
            total = i;
        }

        // 对外的接口
        void addNum(int num) {
            total += num;
        }

        // 对外的接口
        int getTotal() {
            return total;
        }
};

int main() {
    Addr a;
    a.addNum(10);
    a.addNum(20);
    std::cout << "Total: " << a.getTotal() << std::endl;
    return 0;
}
