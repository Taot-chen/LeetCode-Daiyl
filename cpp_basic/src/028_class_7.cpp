#include <iostream>
using namespace std;

class Line {
    public:
        void setLength(double len);
        double getLength(void);
        Line(double len);   // 构造函数
    private:
        double length;
};

Line::Line(double len) {
    length = len;
    cout << "Object is being created, length = " << length << endl;
}

void Line::setLength(double len) {
    length = len;
}

double Line::getLength(void) {
    return length;
}

int main() {
    Line line(10);

    // 获取默认设置的长度
   cout << "Length of line : " << line.getLength() <<endl;

   line.setLength(6);
   cout << "Length of line : " << line.getLength() <<endl;

   return 0;
}
