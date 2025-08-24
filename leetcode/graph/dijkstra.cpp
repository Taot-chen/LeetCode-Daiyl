#include <iostream>
#include <climits>
#include <vector>

template<class T>
inline void print_vector(std::vector<T> v) {
    for (auto item: v) std::cout << item << " ";
    std::cout << std::endl;
}

std::vector<int> dijkstra(std::vector<std::vector<int>> graph, int start_idx) {
    int num = graph.size();
    std::vector<int> ret(num, -1);
    std::vector<int> notFound(num, -1);
    for (int i = 0; i < num; i++) {
        notFound[i] = graph[start_idx][i];
    }
    ret[start_idx] = 0;
    notFound[start_idx] = -1;
    for (int i = 1; i < num; i++) {
        std::cout << "ret: ";
        print_vector(ret);
        std::cout << "notFound: ";
        print_vector(notFound);
        int min_dis = INT_MAX;
        int min_idx = -1;
        for (int j = 0; j < num; j++) {
            if (notFound[j] > 0 && notFound[j] < min_dis) {
                min_dis = notFound[j];
                min_idx = j;
            }
        }
        ret[min_idx] = min_dis;
        notFound[min_idx] = -1;
        for (int j = 0; j < num; j++) {
            if (graph[min_idx][j] > 0 && ret[j] == -1) {
                int new_dis = ret[min_idx] + graph[min_idx][j];
                if (new_dis < notFound[j] || notFound[j] == -1)
                    notFound[j] = new_dis;
            }
        }
    }
    return ret;
}



int main() {
    std::vector<std::vector<int>> graph = {
        {0 , 2, -1, 6},
        {2 , 0, 3, 2},
        {-1 , 3, 0, 2},
        {6 , 2, 2, 0},
    };
    std::vector ret = dijkstra(graph, 0);
    print_vector(ret);
    return 0;
}
