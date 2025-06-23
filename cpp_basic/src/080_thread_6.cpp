#include <mutex>
#include <thread>

std::mutex mtx; // 全局互斥量

void safeFunc() {
    mtx.lock(); // 请求锁定互斥量
    // 访问或修改共享资源

    mtx.unlock();
}

int main() {
    std::thread t1(safeFunc);
    std::thread t2(safeFunc);

    t1.join();
    t2.join();

    return 0;
}
