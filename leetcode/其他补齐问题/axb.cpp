/*
考虑寻找最接近的整数 a，b，使得 axb=300000
*/

#include <iostream>
#include <cmath>
#include <climits>

// O(sqrt(n))
std::pair<int, int> mindiff_ab_1(int n) {
    int mindiff = INT_MAX;
    std::pair<int, int> ret;
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        cnt += 1;
        if (n % i == 0 && mindiff > abs(i - n / i)) {
            mindiff = abs(i - n / i);
            ret = {i, n / i};
        }
    }
    std::cout << "cnt: " << cnt << std::endl;
    if (mindiff == INT_MAX) {
        std::cout << "无精确解" << std::endl;
    } else {
        std::cout << "最接近的整数对: (" << ret.first << ", " << ret.second << ")\n";
        std::cout << "乘积: " << ret.first * ret.second << " | 差值: " << mindiff << std::endl;
    }
    return ret;
}

std::pair<int, int> mindiff_ab_2(int n) {
    std::pair<int, int> ret;
    int sq = (int)sqrt(n);
    int r = sq, l = sq;
    int cnt = 0;
    while (l >=1 && l <= n) {
        cnt += 1;
        if (l * r < n) r++;
        else if (l * r > n) l--;
        else {
            ret = {l, r};
            break;
        }
    }
    std::cout << "cnt: " << cnt << std::endl;
    if (l * r != n) {
        std::cout << "无精确解" << std::endl;
    } else {
        std::cout << "最接近的整数对: (" << ret.first << ", " << ret.second << ")\n";
        std::cout << "乘积: " << ret.first * ret.second << " | 差值: " << r - l << std::endl;
    }
    return ret;
}

int main() {
    int n = 300000;
    std::pair<int, int> ret = mindiff_ab_1(n);
    ret = mindiff_ab_2(n);
    return 0;
}
