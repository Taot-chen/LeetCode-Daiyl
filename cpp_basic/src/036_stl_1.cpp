#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec;

    // 显示 vec 的原始大小
    cout << "vector size = " << vec.size() << endl;

    for (int i = 0; i < 5; i++) {
        vec.push_back(i);
    }

    // 显示 vec 扩展后的大小
    cout << "extended vector size = " << vec.size() << endl;

    // 访问向量中的 5 个值
   for(int i = 0; i < 5; i++) {
        cout << "value of vec [" << i << "] = " << vec[i] << endl;
   }

   // 使用迭代器 iterator 访问值
   vector<int>::iterator v = vec.begin();
   while (v != vec.end()) {
        cout << "Value of v: " << *v << endl;
        v++;
   }

    // 观察 vector 扩容过程
    vector<int> a;
    for(int i = 0; i < 20; i++) {
        std::cout << "Element number: " << a.size() << ", vector size: " << a.capacity() << endl;
        a.push_back(i);
    }

   return 0;
}
