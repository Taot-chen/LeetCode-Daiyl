#include <iostream>
#include <vector>

#define MAXN 1005
int fa[MAXN], rank[MAXN];

inline void init(int n) {
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        rank[i] = 1;
    }
}

inline int find(int x) {
    return fa[x] == x ? x : (fa[x] = find(fa[x]));
}

inline void merge(int i, int j) {
    int x = find(i), y = find(j);
    if (rank[x] <= rank[y]) fa[x] = y;
    else fa[y] = x;
    if (rank[x] == rank[y] && x != y) rank[y] += 1;
}

bool next_to(int x1, int y1, int z1, int x2, int y2, int z2, int r) {
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2) <= 4 * r * r;
}


int main() {
    int r = 6;
    int h = 10;
    std::vector<int> x = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> y = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    std::vector<int> z = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    init(x.size());
    fa[1001] = 1001; // 用1001代表底部
    fa[1002] = 1002; // 用1002代表顶部
    for (int i = 1; i < x.size() - 1; i++) {
        if (z[i] <= r) merge(i, 1001);
        if (z[i] + r >= h) merge(i, 1002);
    }
    for (int i = 1; i < x.size() - 1; i++) {
        for (int j = i + 1; j < x.size(); j++) {
            if (next_to(x[i], y[i], z[i],  x[j], y[j], z[j], r)) {
                merge(i, j);
            }
        }
    }
    std::cout << (find(1001) == find(1002) ? "Yes" : "No") << std::endl;
    return 0;
}