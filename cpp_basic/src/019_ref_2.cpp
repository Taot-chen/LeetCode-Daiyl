#include <iostream>

double vals[] = {1.0, 2.0, 3.0, 4.0};

double& getref(int i) {
    double& ref = vals[i];
    return ref;
}

int main() {
    std::cout << "before:" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << vals[i] << " " << std::endl;
    }
    std::cout << std::endl;

    getref(1) = 20;
    getref(3) = 35;
    std::cout << "after:" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << vals[i] << " " << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
