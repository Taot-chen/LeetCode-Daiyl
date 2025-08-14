#include <iostream>
#include <algorithm>
#include <vector>

bool cmp(const std::pair<int, int>x, const std::pair<int, int>y) {
    // 对于相同的时间点，使终点在起点前面
    if (x.first == y.first) return x.second > y.second;
    return x.first < y.first;
}

int main() {
    int n, s, t;
    n = 10;
    std::vector<std::pair<int, int>> vals;
    for (int i = 0; i < n; i++) {
        vals.push_back({i + 1, 0});
        vals.push_back({i + 8, 1});
    }
    sort(vals.begin(), vals.end(), cmp);
    int ret = 0;
    int cnt = 0;
    for (int i = 0; i < vals.size(); i++) {
        if (vals[i].second == 0) {
            cnt += 1;
            ret = ret > cnt ? ret : cnt;
        } else {
            cnt--;
        }
    }
    std::cout << "ret: " << ret << std::endl;
    return 0;
}
