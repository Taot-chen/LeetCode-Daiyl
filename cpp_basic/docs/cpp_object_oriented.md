# C++  面向对象

## 1 类 & 对象

C++ 在 C 语言的基础上增加了面向对象编程，类是 C++ 的核心特性，类用于指定对象的形式，是一种用户自定义的数据类型，是一种封装了数据和函数的组合。


### 1.1 类定义

```cpp
class Box {
    public:
        double length;
        double breadth;
        double height;
};
```

关键字 public 确定了类成员的访问属性。在类对象作用域内，公共成员在类的外部是可访问的。


声明类的对象，就像声明基本类型的变量一样。

```cpp
Box box1;
Box box2;
```

类的对象的公共数据成员可以使用直接成员访问运算符 `.` 来访问。

```cpp
#include <iostream>

class Box {
    public:
        double length;
        double breadth;
        double height;
        double getV(void);
        void setShape(double len, double bre, double hei);
};

double Box::getV(void) {
    return length * breadth * height;
}

void Box::setShape(double len, double bre, double hei) {
    length = len;
    breadth = bre;
    height = hei;
}


int main() {
    Box box1;
    Box box2;
    double v = 0.0;

    box1.height = 10.0;
    box1.length = 12.0;
    box1.breadth = 13.0;
    v = box1.height * box1.length * box1.breadth;
    std::cout << "V of box1: " << v << std::endl;

    box2.setShape(4.0, 5.0, 6.0);
    v = box2.getV();
    std::cout << "V of box2: " << v << std::endl;
    return 0;
}
```

输出：

```bash
V of box1: 1560
V of box2: 120
```

私有的成员和受保护的成员不能使用直接成员访问运算符 (`.`) 来直接访问。



### 1.2 类成员函数

类的成员函数是指那些把定义和原型写在类定义内部的函数，就像类定义中的其他变量一样。。类成员函数是类的一个成员，它可以操作类的任意对象，可以访问对象中的所有成员。

成员函数可以定义在类定义内部，或者单独使用范围解析运算符 `::` 来定义。**在类定义中定义的成员函数把函数声明为内联的，即便没有使用 `inline` 标识符**:

```cpp
class Box {
    public:
        double length;
        double breadth;
        double height;
        void setShape(double len, double bre, double hei);
        double getV(void) {
            return length * height * breadth;
        }
};
```

也可以在类的外部使用范围解析运算符 `::` 定义该函数。在 `::` 运算符之前必须使用类名。用类名。调用成员函数是在对象上使用点运算符（`.`），这样它就能操作与该对象相关的数据，如下所示：

```cpp
Box myBox;
myBox.getV();
```



### 1.3 类访问修饰符

类成员可以被定义为 public、private 或 protected。一个类可以有多个 public、protected 或 private 标记区域。**每个标记区域在下一个标记区域开始之前或者在遇到类主体结束右括号之前都是有效的**。**成员和类的默认访问修饰符是 private**。

```cpp
class Base {
   public:
  // 公有成员

   protected:
  // 受保护成员

   private:
  // 私有成员
};
```

#### 1.3.1 公有（public）成员

公有成员在程序中类的外部是可访问的，可以不使用任何成员函数来设置和获取公有变量的值：

```cpp
class Line {
    public:
        double length;
        void setLength(double len);
        double getLength(void);
};

// 成员函数定义
double Line::getLength(void) {
    return length ;
}
 
void Line::setLength( double len ) {
    length = len;
}

Line line;
line.setLength(6.9);

// 不使用成员函数设置长度
line.length = 10.0;
```


#### 1.3.2 私有（private）成员

私有成员变量或函数在类的外部是不可访问的，甚至是不可查看的。只有类和友元函数可以访问私有成员。默认情况下，类的所有成员都是私有的。

```cpp
#include <iostream>

class Box {
    double width;   // width 是一个私有成员
    public:
        double length;
        void setWidth(double wid);
        double getWidth( void );
};

// 成员函数定义
double Box::getWidth(void) {
    return width ;
}
 
void Box::setWidth( double wid ) {
    width = wid;
}

int main() {
    Box box;

    // 不使用成员函数设置长度
    box.length = 10.0;  // OK: 因为 length 是公有的
    std::cout << "lenght: " << box.length << std::endl;

    // 不使用成员函数设置宽度
    // box.width = 10.0; // Error: 因为 width 是私有的

    box.setWidth(10.0); // 使用成员函数设置宽度
    std::cout << "width: " << box.getWidth() << std::endl;  // 这里访问也只能通过成员函数进行

    return 0;
}
```
一般会在私有区域定义数据，在公有区域定义相关的函数，以便在类的外部也可以调用这些函数。


#### 1.3.3 protected（受保护）成员

protected（受保护）成员变量或函数与私有成员十分相似，但有一点不同，protected（受保护）成员在派生类（即子类）中是可访问的。

```cpp
#include <iostream>

class Box {
    protected:
        double width;
};

class SmallBox: Box {
    public:
        void setSmallWidth(double wid);
        double getSmallWidth(void);
};

double SmallBox::getSmallWidth(void) {
    return width;
}

void SmallBox::setSmallWidth(double wid) {
    width = wid;
}

int main() {
    SmallBox box;

    // 使用成员函数设置宽度
    box.setSmallWidth(4.0);
    std::cout << "Width of box : " << box.getSmallWidth() << std::endl;

    // 使用成员函数设置宽度
    // box.width = 5.0;    // Error
    // std::cout << "Width of box : " << box.width << std::endl;   // Error

    return 0;
}
```
这里由于没有指明继承的方式，默认是按照 private 的方式来继承，因此继承到的 width 还是 protected。

#### 1.3.4 继承中的特点

有public, protected, private三种继承方式，它们相应地改变了基类成员的访问属性。

* public 继承：基类 public 成员，protected 成员，private 成员的访问属性在派生类中分别变成：public, protected, private（**public 继承不改变继承自父类的成员权限**）

* protected 继承：基类 public 成员，protected 成员，private 成员的访问属性在派生类中分别变成：protected, protected, private（**protected 继承，继承自父类的成员，权限不高于 protected**）

* private 继承：基类 public 成员，protected 成员，private 成员的访问属性在派生类中分别变成：private, private, private（**private 继承，继承自父类的成员，权限全部变成 private**）



但无论哪种继承方式，下面两点都没有改变：

* private 成员只能被本类成员（类内）和友元访问，不能被派生类访问；

* protected 成员可以被派生类访问。



public 继承：

```cpp
#include <iostream>
#include <assert.h>
using namespace std;

class A {
    public:
        int a;
        A() {
            a1 = 1;
            a2 = 2;
            a3 = 3;
            a = 4;
        }
        void func() {
            cout << a << endl;    //正确
            cout << a1 << endl;   //正确
            cout << a2 << endl;   //正确
            cout << a3 << endl;   //正确
        }
    public:
        int a1;
    protected:
        int a2;
    private:
        int a3;
};

class B: public A {
    public:
        int a;
        B(int i) {
            A();
            a = i;
        }
        void fun(){
            cout << a << endl;       //正确，public成员
            cout << a1 << endl;       //正确，基类的public成员，在派生类中仍是public成员。
            cout << a2 << endl;       //正确，基类的protected成员，在派生类中仍是protected可以被派生类访问。
            // cout << a3 << endl;       //错误，基类的private成员不能被派生类访问。
        }
};

int main() {
    B b(10);
    cout << b.a << endl;     // OK
    cout << b.a1 << endl;    // OK
    // cout << b.a2 << endl;    // 错误，类外不能访问protected成员
    // cout << b.a3 << endl;    // 错误，类外不能访问private成员
    return 0;
}
```


protected 继承:

```cpp
#include <iostream>
#include <assert.h>
using namespace std;

class A {
    public:
        int a;
        A() {
            a1 = 1;
            a2 = 2;
            a3 = 3;
            a = 4;
        }
        void func() {
            cout << a << endl;    //正确
            cout << a1 << endl;   //正确
            cout << a2 << endl;   //正确
            cout << a3 << endl;   //正确
        }
    public:
        int a1;
    protected:
        int a2;
    private:
        int a3;
};

class B: protected A {
    public:
        int a;
        B(int i) {
            A();
            a = i;
        }
        void fun(){
            cout << a << endl;       //正确，public成员
            cout << a1 << endl;       //正确，基类的public成员，在派生类中变成了protected，可以被派生类访
            cout << a2 << endl;       //正确，基类的protected成员，在派生类中仍是protected可以被派生类访问。
            // cout << a3 << endl;       //错误，基类的private成员不能被派生类访问。
        }
};

int main() {
    B b(10);
    cout << b.a << endl;     // OK
    // cout << b.a1 << endl;    //错误，protected成员不能在类外访问。
    // cout << b.a2 << endl;    // 错误，类外不能访问protected成员
    // cout << b.a3 << endl;    // 错误，类外不能访问private成员
    return 0;
}
```


private 继承:

```cpp
#include <iostream>
#include <assert.h>
using namespace std;

class A {
    public:
        int a;
        A() {
            a1 = 1;
            a2 = 2;
            a3 = 3;
            a = 4;
        }
        void func() {
            cout << a << endl;    //正确
            cout << a1 << endl;   //正确
            cout << a2 << endl;   //正确
            cout << a3 << endl;   //正确
        }
    public:
        int a1;
    protected:
        int a2;
    private:
        int a3;
};

class B: private A {
    public:
        int a;
        B(int i) {
            A();
            a = i;
        }
        void fun(){
            cout << a << endl;       //正确，public成员
            cout << a1 << endl;       //正确，基类public成员,在派生类中变成了private,可以被派生类访问。
            cout << a2 << endl;       //正确，基类的protected成员，在派生类中变成了private,可以被派生类访问
            // cout << a3 << endl;       //错误，基类的private成员不能被派生类访问。
        }
};

int main() {
    B b(10);
    cout << b.a << endl;     // OK
    // cout << b.a1 << endl;    ///错误，private成员不能在类外访问。
    // cout << b.a2 << endl;    //错误，private成员不能在类外访问。
    // cout << b.a3 << endl;    //错误，private成员不能在类外访问。
    return 0;
}
```
