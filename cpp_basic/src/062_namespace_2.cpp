#include <iostream>

// 第一个命名空间
namespace firt_space {
    int a = 0;
    void func() {
        std::cout << "Inside first_space" << std::endl;
    }
}

// 第二个命名空间
namespace second_space {
    double a = 1.1;
    void func() {
        std::cout << "Inside second_space" << std::endl;
    }
}


using namespace std;
using namespace firt_space;
int main() {
    cout << "a = " << a << endl;
    func();

    return 0;
}
