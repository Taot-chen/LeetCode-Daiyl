#include <climits>
#include <cstdbool>
#include <iostream>
#include <vector>
#define NUMPOINT 7

int minKey(std::vector<int> key, std::vector<bool> mstSet) {
    int min_val = INT_MAX;
    int min_idx;
    for (int i = 0; i < NUMPOINT; i++) {
        if (mstSet[i] == false && key[i] < min_val) {
            min_val = key[i];
            min_idx = i;
        }
    }
    return min_idx;
}

template<class T>
void printVector(std::vector<T> v) {
    for (auto item: v) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}


void printMST (std::vector<int> parent, std::vector<std::vector<int>> graph) {
    std::cout << "Edge \tWeight\n";
    int total_cost = 0;
    for (int i = 1; i < NUMPOINT; i++) {
        std::cout << parent[i] << "->" << i << "\t" << graph[i][parent[i]] << std::endl;
        total_cost += graph[i][parent[i]];
    }
    std::cout << "TotalCost\t" << total_cost << std::endl;
}

void primMST(std::vector<std::vector<int>> graph) {
    std::vector<int> parent(NUMPOINT);
    std::vector<int> key(NUMPOINT);
    std::vector<bool> mstSet(NUMPOINT);

    for (int i = 0; i < NUMPOINT; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;

    for (int cnt = 0; cnt < NUMPOINT - 1; cnt++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
 
        for (int i = 0; i < NUMPOINT; i++) {
            if (graph[u][i] && mstSet[i] == false && graph[u][i] < key[i]) {
                parent[i] = u;
                // printVector(parent);
                key[i] = graph[u][i];
            }
        }
    }
    printMST(parent, graph);
}

int main() {
    std::vector<std::vector<int>> graph = {
        { 0, 5, 9, 0, 15, 6, 0 },
        { 5, 0, 7, 0, 0,  0, 0 },
        { 9, 7, 0, 8, 7,  0, 0},
        { 0, 0, 8, 0, 5,  0, 0 },
        { 15, 0, 7,5, 0,  8, 9 },
        { 6, 0, 0, 0, 8, 0, 11},
        { 0, 0, 0, 0, 9,11,0}
    };
    primMST(graph);
    return 0;
}
