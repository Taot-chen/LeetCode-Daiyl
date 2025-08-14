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
    int ret = 0;
    std::vector<int> dp(vals.size(), 0);
    sort(vals.begin(), vals.end(), cmp);
    for (int i = 0; i < vals.size(); i++) {
        // 在已经计算过的范围内计算 dp[i] 最大值
        int max_dpj = 0;
        for (int j = 0; j < i; j++) {
            // 考虑安排 vals[i] 的前提是前面的会议的结束时间不能超过 vals[i]的开始时间
            if (vals[j].second <= vals[i].first) {
                max_dpj = max_dpj > dp[j] ? max_dpj : dp[j];
            }
        }
        dp[i] = vals[i].second - vals[i].first + max_dpj;
        ret = ret > dp[i] ? ret : dp[i];
    }
    std::cout << "ret: " << ret << std::endl;
    return ret;
}
