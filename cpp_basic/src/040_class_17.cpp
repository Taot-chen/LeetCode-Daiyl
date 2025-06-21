#include <iostream>

class printData {
    public:
        void print(int i) {
            std::cout << "INT: " << i << std::endl;
        }

        void print(double f) {
            std::cout << "DOUBLE: " << f << std::endl;
        }

        void print(char c[]) {
            std::cout << "STRING: " << c << std::endl;
        }
};

int main() {
    printData pd;
    pd.print(5);
    pd.print(2.1);
    pd.print("Hello Cpp");
    return 0;
}
