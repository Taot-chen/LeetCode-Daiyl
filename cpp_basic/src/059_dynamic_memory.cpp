#include <iostream>

int main() {
    int i, j, k;    // p[2][3][4]

    int*** p;
    p = new int** [3];
    for (int i = 0; i < 3; i++) {
        p[i] = new int* [4];
        for (int j = 0; j < 4; j++) {
            p[i][j] = new int [5];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 5; k++) {
                p[i][j][k] = i + j + k;
                std::cout << p[i][j][k] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    // 释放内存
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            delete[] p[i][j];
        }
        delete[] p[i];
    }
    delete[] p;
    return 0;
}
