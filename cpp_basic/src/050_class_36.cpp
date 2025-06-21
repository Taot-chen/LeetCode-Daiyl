/*
类成员访问运算符（ -> ）可以被重载，它被定义用于为一个类赋予"指针"行为。
运算符 -> 必须是一个成员函数。如果使用了 -> 运算符，返回类型必须是指针或者是类的对象。

运算符 -> 通常与指针引用运算符 * 结合使用，用于实现"智能指针"的功能。
这些指针是行为与正常指针相似的对象，唯一不同的是，当通过指针访问对象时，它们会执行其他的任务。比如，当指针销毁时，或者当指针指向另一个对象时，会自动删除对象。

间接引用运算符 -> 可被定义为一个一元后缀运算符。也就是说，给出一个类：

```cpp
class ptr {
    // ...
    X* operator->();
};
```

类 ptr 的对象可用于访问类 X 的成员，使用方式与指针的用法十分相似。例如：

```cpp
void func(ptr p) {
    p->m = 10;  // (p.operator->())->m = 10, 语句 p->m 被解释为 (p.operator->())->m。
```
*/

#include <iostream>
#include <vector>

class Obj {
    static int i, j;
    public:
        void func1() const {std::cout << i++ << std::endl;}
        void func2() const {std::cout << j++ << std::endl;}
};

// 静态成员定义
int Obj::i = 10;
int Obj::j = 15;

// 为上面的类实现一个容器
class ObjContainer {
    std::vector<Obj*> a;
    public:
        void add(Obj* obj) {
            a.push_back(obj);
        }
        friend class SmartPointer;
};

// 实现智能指针，用于访问类 Obj 的成员
class SmartPointer {
    ObjContainer oc;
    int index;
    public:
        SmartPointer(ObjContainer& objc) {
            this->oc = objc;
            this->index = 0;
        }

        // 返回值表示列表结束
        bool operator ++ () {   // 前缀
            if (index >= oc.a.size() - 1)   return false;
            if (oc.a[++index] == 0)    return false;
            return true;
        }
        bool operator ++ (int) {   // 后缀
            return operator ++ ();
        }

        // 重载运算符 ->
        Obj* operator -> () const {
            if (!oc.a[index]) {
                std::cout << "Zero value";
                return (Obj*)0;
            }
            return oc.a[index];
        }
};

int main() {
    const int sz = 5;
    Obj o[sz];
    ObjContainer oc;
    for (int i = 0; i < sz; i++) {
        oc.add(&o[i]);
    }

    SmartPointer sp(oc);    // 创建一个迭代器
    do {
        sp->func1();
        sp->func2();
    } while(sp++);
    return 0;
}

/*
输出：

10
15
11
16
12
17
13
18
14
19
*/
