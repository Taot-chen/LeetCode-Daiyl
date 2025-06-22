#include <iostream>

class Student {
    private:
        std::string name;
        int age;
    public:
        Student(std::string n, int a) {
            name = n;
            age = a;
        }

        // 访问器函数
        std::string getName() {
            return name;
        }

        int getAge() {
            return age;
        }

        // 修改器函数
        void setName(std::string n) {
            name = n;
        }

        void setAge(int a) {
            if (a > 0) {
                age = a;
            } else {
                std::cout << "Invalid ags!" << std::endl;
            }
        }

        void printInfo() {
            std::cout << "Name: " << name << ", Age: " << age << std::endl;
        }
    };

int main() {
    Student s1("Alice", 10);

    s1.printInfo();

    s1.setName("Bob");
    s1.setAge(15);
    s1.printInfo();
    return 0;
}
