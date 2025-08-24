#include <climits>
#include <cstdbool>
#include <iostream>
#include <vector>
#include <algorithm>
#define NUMPOINT 7

std::vector<int> root(NUMPOINT);
std::vector<int> size(NUMPOINT);

template<class T>
void printVector(std::vector<T> v) {
    for (auto item: v) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

void init(int n) {
    for (int i = 0; i < n; i++) {
        root[i] = i;
        size[i] = 1;
    }
}

int find_root(int x) {
    return x == root[x] ? x : (root[x] = find_root(root[x]));
}

bool merge(int x, int y) {
    int a = find_root(x);
    int b = find_root(y);
    if (a == b) return false;
    if (size[a] >= size[b]) {
        root[b] = a;
        size[a] += size[b];
    } else {
        root[a] = b ;
        size[b] += size[a];
    }
    return true;
}

bool comp(std::vector<int> a, std::vector<int> b) {
    return a[2] < b[2];
}

void kruskalMST(std::vector<std::vector<int>> graph) {
    init(NUMPOINT);
    sort(graph.begin(), graph.end(), comp);
    int mincost = 0;
    std::vector<std::vector<int>> trace;
    for (int i = 0; i < graph.size(); i++) {
        if (merge(graph[i][0], graph[i][1])) {
            mincost += graph[i][2];
            trace.push_back({graph[i]});
        }
    }
    for (int i = 0; i < trace.size(); i++) printVector(trace[i]);
    std::cout << "mincost: " << mincost << std::endl;
}


int main() {
    std::vector<std::vector<int>> graph = {
        {0, 1, 5},
        {0, 2, 9},
        {0, 4, 15},
        {0, 5, 6},
        {1, 0, 5},
        {1, 2, 7},
        {1, 0, 5},
        {2, 0, 9},
        {2, 1, 7},
        {2, 3, 8},
        {2, 4, 7},
        {3, 2, 8},
        {3, 4, 5},
        {4, 0, 15},
        {4, 2, 7},
        {4, 3, 5},
        {4, 5, 8},
        {4, 6, 9},
        {5, 0, 6},
        {5, 4, 8},
        {5, 6, 11},
        {6, 4, 9},
        {6, 5, 11}
    };
    kruskalMST(graph);
    return 0;
}