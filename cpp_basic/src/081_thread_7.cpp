#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void workerThread() {
    std::unique_lock<std::mutex> ul(mtx);
    cv.wait(ul, []{return ready;}); // 等待条件
    // 当条件满足时执行工作
}

void mainThread() {
    {
        std::lock_guard<std::mutex> lk(mtx);
        // 准备数据
        ready = true;
    }   // 离开作用域时解锁
    cv.notify_one();    // 通知一个等待的线程
}


