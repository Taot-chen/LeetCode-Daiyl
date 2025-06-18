#include <iostream>

int main() {
    const char* names[3] = {
        "Zara Ali",
        "Hina Ali",
        "Nuha Ali"
    };
    for (int i = 0; i < 3; i++) {
        std::cout << names[i] << std::endl;
    }
    return 0;
}
