#include <iostream>
#include <algorithm>
#include <vector>


bool cmp(std::pair<int, int>x, std::pair<int, int>y) {
    // 结束时间相同的，按照开始时间升序
    if (x.second == y.second) return x.first < y.first;
    // 按结束时间升序
    return x.second < y.second;
}


int main() {
    int n, s, t;
    n = 10;
    std::vector<std::pair<int, int>> vals;
    for (int i = 0; i < n; i++) {
        vals.push_back({i + 1, i + 3});
    }

    sort(vals.begin(), vals.end(), cmp);
    int ret = 0, end_t = -1;
    for (int i = 0; i < vals.size(); i++) {
        if (vals[i].first >= end_t) {
            ret += 1;
            end_t = vals[i].second;
        }
    }
    std::cout << "ret: " << ret << std::endl;
    return ret;
}
