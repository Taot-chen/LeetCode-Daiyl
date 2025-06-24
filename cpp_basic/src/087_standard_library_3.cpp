#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> a = {4, 3, 6, 7, 9, 0};
    std::sort(a.begin(), a.end());
    for (int i = 0; i < 6; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
    return 0;
}
