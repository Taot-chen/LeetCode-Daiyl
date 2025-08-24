## dijkstra 算法最短路径

Dijkstra 算法是求一个图中一个点到其他所有点的最短路径的算法。算法基于贪心、广度优先搜索、动态规划，来求图中一个点到其他所有位置的最短路径，时间复杂度 O(n^2)


每次从未求出最短路径的点中取出距离起点最小路径的点，以这个点位桥梁刷新未求出最短路径的点的距离。

对于邻接矩阵：

```cpp
int[][] graph  = new int[][]{
{0 , 2, ∞, 6}
{2 , 0, 3, 2}
{∞ , 3, 0, 2}
{6 , 2, 2, 0}
};
```

两个数组：

* result，已求出最小路径的顶点
* notFound，未求出最小路径的顶点，里面的值是到起点的距离

初始，result={A(0)}，result 中只有起点 A，notFound = {B(2),C(∞),D(6)}中包含除了起点A的其他所有点，里面的值是到起点 A 的距离。

然后，从未求出最短路径的点 notFound 中取出最短路径的点 B(2)，然后通过 B(2)为桥梁刷新未求出最短路径的点的距离（即未求出最短距离的点，经过 B 到 A 的距离）

  1) 取出最短路径的点：从未求出最短路径的点notFound 中取出 最短路径的点 B(2)，放入结果 result 中，结果如下：

  未求出最短路径的点 notFound={C(∞),D(6)}，已求出最短路径的点 result={A(0),B(2)}

  2) 刷新距离

  以 B(2)为桥梁，刷新距离，原本 AD = 6，AB+BD = 4，以 B为桥梁的距离更短，刷新未求出最短路径点 D(6) 为 D(4)，notFound = {C(∞),D(4)}

  同理刷新 C(∞) 的距离为 C(5) ，最后结果如下：

  未求出最短路径点 notFound={C(5),D(4)}, 已求出最短路径的点 result={A(0),B(2)}

然后继续从未求出最短路径的点notFound 中取出 最短路径的点 D(4) ，然后通过 D(4) 为桥梁 刷新未求出最短路径的点的距离

  同理，最后结果如下：未求出最短路径点 notFound={C(5)} ，已求出最短路径的点 result={A(0),B(2),D(4)}


然后，从未求出最短路径的点 notFound 中取出 最短路径的点 C(5) ，算法结束 result={A(0),B(2),D(4),C(5)} 就是最终所求的 最短距离

```cpp
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
```
