#include <iostream>
using namespace std;

class Line {
    public:
        int getLength(void);
        Line(int len);  // 简单的构造函数
        Line(const Line& obj);  // 拷贝构造函数
        ~Line();    // 析构函数
    private:
        int* ptr;
};

Line::Line(int len) {
    cout << "调用构造函数" << endl;
    ptr = new int;
    *ptr = len;
}

Line::Line(const Line& obj) {
    cout << "调用拷贝构造函数并为指针 ptr 分配内存" << endl;
    ptr = new int;
    *ptr = *obj.ptr;    // 拷贝值
}

Line::~Line(void) {
    cout << "释放内存" << endl;
    delete ptr;
}

int Line::getLength(void) {
    return *ptr;
}

void display(Line obj) {
    cout << "line 大小 : " << obj.getLength() <<endl;
}

int main() {
    Line line(10);
    Line line2 = line;  // 这里调用了拷贝构造函数
    display(line);  // 复制对象把它作为参数传递给函数，触发拷贝构造函数
    display(line2);
    return 0;
}