#include <climits>
#include <cstdbool>
#include <iostream>
#include <vector>
#define NUMPOINT 7

void print_MST(std::vector<std::vector<int>> graph, std::vector<int> trace) {
    std::cout << "Edge \tWeight\n";
    int total_cost = 0;
    for (int i = 1; i < NUMPOINT; i++) {
        std::cout << trace[i] << "->" << i << "\t" << graph[i][trace[i]] << std::endl;
        total_cost += graph[i][trace[i]];
    }
    std::cout << "TotalCost\t" << total_cost << std::endl;
}

void primMST(std::vector<std::vector<int>> graph) {
    std::vector<int> trace(NUMPOINT);
    std::vector<bool> visited(NUMPOINT, false);
    std::vector<int> min_edge(NUMPOINT);
    int total_cost = 0;
    trace[0] = -1;
    visited[0] = true;
    min_edge[0] = 0;

    // init min_edge with node 0
    for (int i = 1; i < NUMPOINT; i++) {
        min_edge[i] = graph[0][i];
    }

    // select min edge with current node
    for (int i = 1; i < NUMPOINT; i++) {
        int min_val = INT_MAX;
        int min_idx = -1;

        // select min edge with node0
        for (int j = 0; j < NUMPOINT; j++) {
            if (visited[j] == false && min_val > min_edge[j] && min_edge[j] != -1) {
                min_val = min_edge[j];
                min_idx = j;
            }
        }
        // add into selected  graph
        visited[min_idx] = true;
        total_cost += min_edge[min_idx];
        std::cout << min_idx << "-" << min_edge[min_idx] << std::endl;

        // update min_edge with the selected graph
        for (int j = 0; j < NUMPOINT; j++) {
            if (visited[j] == false && graph[min_idx][j] != -1 && (min_edge[j] == -1 || min_edge[j] > graph[min_idx][j])) {
                min_edge[j] = graph[min_idx][j];
                trace[j] = min_idx;
            }
        }
    }
    std::cout << "mincost: " << total_cost << std::endl;
    print_MST(graph, trace);
}

int main() {
    std::vector<std::vector<int>> graph = {
        { 0, 5, 9, -1, 15, 6, -1 },
        { 5, 0, 7, -1, -1,  -1, -1 },
        { 9, 7, 0, 8, 7,  -1, -1},
        { -1, -1, 8, 0, 5,  -1, -1 },
        { 15, -1, 7,5, 0,  8, 9 },
        { 6, -1, -1, -1, 8, 0, 11},
        { -1, -1, -1, -1, 9,11,0}
    };
    primMST(graph);
    return 0;
}
