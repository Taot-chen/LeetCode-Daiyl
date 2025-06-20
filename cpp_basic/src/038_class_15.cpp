#include <iostream>
/*
实验 class 的不同权限的继承对基类的成员变量的权限

这里定义四个 class，a 为基类，b，c，d 分别 public，protected，private 继承自 a

*/
class a {
    public:
        int apub = 1;
        double getProtect() {
            return this->apro;
        }
        float getPrivate() {
            return this->apri;
        }
    protected:
        double apro = 1.1;
    private:
        float apri = 2.2;
};

class b: public a {
    public:
        int bpub = 3;
        double getCurrProtect() {
            return this->bpro;
        }
        float getCurrPrivate() {
            return this->bpri;
        }
        double getParProtect() {
            return this->apro;
        }
        float getParPrivate() {
            // 不可以直接访问 base class 的 private 成员变量
            // return this->apri;   // Error
            return this->getPrivate();
        }
    protected:
        double bpro = 4.4;
    private:
        float bpri = 5.5;
};


class c: protected a {
    public:
        int cpub = 6;
        double getCurrProtect() {
            return this->cpro;
        }
        float getCurrPrivate() {
            return this->cpri;
        }
        int getParPublic() {
            return this->apub;
        }
        double getParProtect() {
            return this->apro;
        }
        float getParPrivate() {
            // 不可以直接访问 base class 的 private 成员变量
            // return this->apri;    // Error
            return this->getPrivate();
        }
    protected:
        double cpro = 7.7;
    private:
        float cpri = 8.8;
};

class d: private a {
    public:
        int dpub = 9;
        double getCurrProtect() {
            return this->dpro;
        }
        float getCurrPrivate() {
            return this->dpri;
        }
        int getParPublic() {
            return this->apub;
        }
        double getParProtect() {
            return this->apro;
        }
        float getParPrivate() {
            // 不可以直接访问 base class 的 private 成员变量
            // return this->apri;   // Error
            return getPrivate();
        }
    protected:
        double dpro = 10.1;
    private:
        float dpri = 12.2;
};


int main() {
    a aa;
    b bb;
    c cc;
    d dd;

    // base
    std::cout << "\nbase class" << std::endl;
    std::cout << "public val: " << aa.apub << std::endl;
    // 也不可以直接使用类来访问成员变量
    // std::cout << "public val: " << a::apub << std::endl; // Error

    // 不可以在外部直接使用 class 的 protected 成员
    // std::cout << "protected val: " << aa.apro << std::endl; // Error
    // 需要使用 public 的成员函数间接访问
    std::cout << "protected val: " << aa.getProtect() << std::endl;

    // 不可以在外部直接使用 class 的 private 成员
    // std::cout << "private val: " << aa.apro << std::endl; // Error
    // 需要使用 public 的成员函数间接访问
    std::cout << "private val: " << aa.getPrivate() << std::endl;


    // public 继承
    std::cout << "\npublic inheritance" << std::endl;
    // public 继承的子类，在外部可以直接访问基类的 public 成员
    std::cout << "parent public val: " << bb.apub << std::endl;

    // public 继承的子类，在外部可以不可以直接访问基类的 protected 成员
    // std::cout << "parent protected val: " << bb.apro << std::endl; // Error
    std::cout << "parent protected val: " << bb.getParProtect() << std::endl;

    // public 继承的子类，在外部可以不可以直接访问基类的 private 成员
    // std::cout << "parent private val: " << bb.apri << std::endl; // Error
    std::cout << "parent private val: " << bb.getParPrivate() << std::endl;



    // protected 继承
    std::cout << "\nprotected inheritance" << std::endl;
    // protected 继承的子类，在外部不可以直接访问基类的 public 成员
    // std::cout << "parent public val: " << cc.apub << std::endl; // Error
    std::cout << "parent public val: " << cc.getParPublic() << std::endl;

    // protected 继承的子类，在外部可以不可以直接访问基类的 protected 成员
    // std::cout << "parent protected val: " << cc.apro << std::endl; // Error
    std::cout << "parent protected val: " << cc.getParProtect() << std::endl;

    // protected 继承的子类，在外部可以不可以直接访问基类的 private 成员
    // std::cout << "parent private val: " << cc.apri << std::endl; // Error
    std::cout << "parent private val: " << cc.getParPrivate() << std::endl;


    // private 继承
    std::cout << "\nprivate inheritance" << std::endl;
    // private 继承的子类，在外部不可以直接访问基类的 public 成员
    // std::cout << "parent public val: " << dd.apub << std::endl; // Error
    std::cout << "parent public val: " << dd.getParPublic() << std::endl;

    // private 继承的子类，在外部可以不可以直接访问基类的 protected 成员
    // std::cout << "parent protected val: " << dd.apro << std::endl; // Error
    std::cout << "parent protected val: " << dd.getParProtect() << std::endl;

    // private 继承的子类，在外部可以不可以直接访问基类的 private 成员
    // std::cout << "parent private val: " << dd.apri << std::endl; // Error
    std::cout << "parent private val: " << dd.getParPrivate() << std::endl;

    return 0;
}
