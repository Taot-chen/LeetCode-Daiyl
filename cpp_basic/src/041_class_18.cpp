#include <iostream>

class Box {
    private:
        double length;
        double heigth;
        double breadth;
    public:
        double getV(void) {
            return length * breadth * heigth;
        }
        void setLength(double len) {
            length = len;
        }
        void setBreadth(double bread) {
            breadth = bread;
        }
        void setHeigth(double heig) {
            heigth = heig;
        }
        Box operator + (const Box& b) {
            Box box;
            // 这里的bxo加法定义合理性不要在意
            box.length = this -> length + b.length;
            box.heigth = this -> heigth + b.heigth;
            box.breadth = this -> breadth + b.breadth;
            return box;
        }
};

int main() {
    Box box1;
    Box box2;
    Box box3;

    box1.setBreadth(1.1);
    box1.setHeigth(2.2);
    box1.setLength(3.3);

    box2.setBreadth(4.4);
    box2.setHeigth(5.5);
    box2.setLength(6.6);

    box3 = box1 + box2;

    std::cout << "V1: " << box1.getV() << std::endl;
    std::cout << "V2: " << box2.getV() << std::endl;
    std::cout << "V3: " << box3.getV() << std::endl;

    return 0;
}
