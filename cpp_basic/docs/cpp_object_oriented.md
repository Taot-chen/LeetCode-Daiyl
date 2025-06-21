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





### 1.4 类构造函数 & 析构函数


#### 1.4.1 类的构造函数

类的构造函数是类的一种特殊的成员函数，它会在每次创建类的新对象时执行。构造函数的名称与类的名称是完全相同的，**并且不会返回任何类型，也不会返回 void**。构造函数可用于为某些成员变量设置初始值。

默认的构造函数没有任何参数，但如果需要，构造函数也可以带有参数。这样在创建对象时就会给对象赋初始值：

```cpp
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
```


也可以使用初始化列表在构造函数中来初始化字段，下面的写法效果与上面等价：

```cpp
Line::Line(double len): length(len) {
    cout << "Object is being created, length = " << length << endl;
}
```

假设有一个类 C，具有多个字段 X、Y、Z 等需要进行初始化，同理地，可以使用上面的语法，

```cpp
C:C(double a, double b, double c): X(a), Y(b), Z(c) {
    ...
}
```



#### 1.4.2 类的析构函数

类的析构函数是类的一种特殊的成员函数，它会在每次删除所创建的对象时执行。

析构函数的名称与类的名称是完全相同的，只是在前面加了个波浪号（~）作为前缀，它不会返回任何值，也不能带有任何参数。析构函数有助于在跳出程序（比如关闭文件、释放内存等）前释放资源。

```cpp
#include <iostream>
using namespace std;

class Line {
    public:
        void setLength(double len);
        double getLength(void);
        Line();   // 构造函数
        ~Line();
    private:
        double length;
};

Line::Line(void) {
    cout << "Object is being created" << endl;
}

Line::~Line(void) {
    cout << "Object is being deleted" << endl;
}

void Line::setLength(double len) {
    length = len;
}

double Line::getLength(void) {
    return length;
}

int main() {
    Line line;

   line.setLength(6);
   cout << "Length of line : " << line.getLength() <<endl;

   return 0;
}
```

输出：

```cpp
Object is being created
Length of line : 6
Object is being deleted
```



### 1.5 拷贝构造函数

拷贝构造函数是一种特殊的构造函数，它在创建对象时，是**使用同一类中之前创建的对象来初始化新创建的对象**。拷贝构造函数通常用于：

* 通过**使用另一个同类型的对象来初始化新创建的对象**。
* 复制对象**把它作为参数传递给函数**。
* 复制对象，并**从函数返回这个对象**。

如果在类中没有定义拷贝构造函数，**编译器会自行定义一个**。如果**类带有指针变量，并有动态内存分配，则它必须有一个拷贝构造函数。**拷贝构造函数的最常见形式如下：

```cpp
classname (const classname& obj) {
    // 构造函数的主体
}
```

obj 是一个对象引用，该对象是用于初始化另一个对象的。


```cpp
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
```


输出：

```bash
调用构造函数    // 构造line触发构造函数
调用拷贝构造函数并为指针 ptr 分配内存   // Line line2 = line;通过使用另一个同类型的对象来初始化新创建的对象，触发拷贝构造函数
调用拷贝构造函数并为指针 ptr 分配内存   // display(line);  // 复制对象把它作为参数传递给函数，触发拷贝构造函数
line 大小 : 10
释放内存    // display(line); 结束，释放函数参数拷贝的对象
调用拷贝构造函数并为指针 ptr 分配内存   // display(line2);// 复制对象把它作为参数传递给函数，触发拷贝构造函数
line 大小 : 10
释放内存    // // display(line2); 结束，释放函数参数拷贝的对象
释放内存    // 主函数结束，释放 line
释放内存    // 主函数结束，释放 line2
```


### 1.6 友元函数

类的友元函数是定义在类外部，但有权访问类的所有私有（private）成员和保护（protected）成员。友元函数的原型有在类的定义中出现，但是**友元函数并不是成员函数**。

友元可以是一个函数，该函数被称为友元函数；友元也可以是一个类，该类被称为友元类，在这种情况下，整个类及其所有成员都是友元。

声明函数为一个类的友元，需要在类定义中该函数原型前使用关键字 friend，如下所示：

```cpp
class Box {
    double width;
    public:
        double length;
        friend void printWidthP(Box box);
        void setWidth(double wid);
};
```

声明类 ClassTwo 的所有成员函数作为类 ClassOne 的友元，需要在类 ClassOne 的定义中放置如下声明：

```cpp
friend class ClassTwo;
```


### 1.6 内联函数

C++ 内联函数是通常与类一起使用。如果一个函数是内联的，那么在编译时，编译器会把该函数的代码副本放置在每个调用该函数的地方。

对内联函数进行任何修改，都需要重新编译函数的所有客户端，因为编译器需要重新更换一次所有的代码，否则将会继续使用旧的函数。

在类定义中的定义的函数都是内联函数，即使没有使用 inline 说明符。

实际上，对于现代编译器而言，内联只是建议编译器把 inline 修饰的函数作为内联处理，最终是否内联，由编译器决定。




### 1.7 this 指针

在 C++ 中，this 指针是一个指向当前对象的指针实例。每一个对象都能通过 this 指针来访问自己的地址。

this是一个隐藏的指针，可以在类的成员函数中使用，它可以用来指向调用对象。当一个对象的成员函数被调用时，编译器会隐式地传递该对象的地址作为 this 指针。**友元函数没有 this 指针，因为友元不是类的成员，只有成员函数才有 this 指针**。

成员函数通过 this 指针来访问成员变量，可以明确地告诉编译器我们想要访问当前对象的成员变量，而不是函数参数或局部变量。通过使用 this 指针，可以在成员函数中访问当前对象的成员变量，即使它们与函数参数或局部变量同名，这样可以避免命名冲突，并确保我们访问的是正确的变量。


```cpp
#include <iostream>
using namespace std;

class Box {
    public:
        Box(double l=2.0, double b = 2.0, double h = 1.0) {
            cout <<"调用构造函数。" << endl;
            length = l;
            breadth = b;
            height = h;    
        }
        double Volume() {
            return length * breadth * height;
        }
        int compare(Box box) {
            return this -> Volume() > box.Volume();
        }
    private:
        double length;
        double breadth;
        double height;
};

int main() {
    Box Box1(3.3, 1.2, 1.5);    // 声明 box1
    Box Box2(8.5, 6.0, 2.0);    // 声明 box2
    if (Box1.compare(Box2)) {
        cout << "Box2 的体积比 Box1 小" << endl;
    } else {
        cout << "Box2 的体积大于或等于 Box1" << endl;
    }
    return 0;
}
```



### 1.8 指向类的指针

一个指向 C++ 类的指针与指向结构的指针类似，访问指向类的指针的成员，需要使用成员访问运算符 `->`。

```cpp
#include <iostream>
using namespace std;

class Box {
    public:
        Box(double l=2.0, double b = 2.0, double h = 1.0) {
            cout <<"调用构造函数。" << endl;
            length = l;
            breadth = b;
            height = h;    
        }
        double Volume() {
            return length * breadth * height;
        }
        int compare(Box box) {
            return this -> Volume() > box.Volume();
        }
    private:
        double length;
        double breadth;
        double height;
};

int main() {
    Box Box1(3.3, 1.2, 1.5);    // 声明 box1
    Box Box2(8.5, 6.0, 2.0);    // 声明 box2

    Box* ptr;
    ptr = &Box1;
    cout << "Volume of Box1: " << ptr->Volume() << endl;

    ptr = &Box2;
    cout << "Volume of Box2: " << ptr->Volume() << endl;

    return 0;
}
```




### 1.9 类的静态成员

可以使用 static 关键字来把类成员定义为静态的。当我们声明类的成员为静态时，这意味着无论创建多少个类的对象，静态成员都只有一个副本。**静态成员在类的所有对象中是共享的**。
如果不存在其他的初始化语句，在创建第一个对象时，所有的静态数据都会被初始化为零。**不能把静态成员的初始化放置在类的定义中，但是可以在类的外部通过使用范围解析运算符 `::` 来重新声明静态变量从而对它进行初始化**，

```cpp
#include <iostream>
using namespace std;

class Box {
    public:
        static int objCnt;
        Box(double l=2.0, double b = 2.0, double h = 1.0) {
            cout <<"调用构造函数。" << endl;
            length = l;
            breadth = b;
            height = h;
            objCnt += 1;
        }
        double Volume() {
            return length * breadth * height;
        }
        int compare(Box box) {
            return this -> Volume() > box.Volume();
        }
    private:
        double length;
        double breadth;
        double height;
};

// 初始化类 Box 的静态成员
int Box::objCnt = 0;
int main() {
    Box Box1(3.3, 1.2, 1.5);    // 声明 box1
    Box Box2(8.5, 6.0, 2.0);    // 声明 box2

    cout << "Total objs: " << Box::objCnt << endl;
    cout << "Total objs: " << Box1.objCnt << endl;

    return 0;
}
```


**静态成员函数**

如果把函数成员声明为静态的，就可以**把函数与类的任何特定对象独立开来**。**静态成员函数即使在类对象不存在的情况下也能被调用，静态函数只要使用类名加范围解析运算符 `::` 就可以访问**。

**静态成员函数只能访问静态成员数据、其他静态成员函数和类外部的其他函数**。静态成员函数有一个类范围，**他们不能访问类的 this 指针**。可以使用静态成员函数来判断类的某些对象是否已被创建。

静态成员函数与普通成员函数的区别：

* 静态成员函数没有 this 指针，只能访问静态成员（包括静态成员变量和静态成员函数）
    * 这个可以这么理解：静态成员函数可以类对象不存在的情况被调用，此时由于没有具体的类对象，那么**非静态成员变量和非静态成员函数还没有被创建，也没有指向类对象实例的 this，指针**。
* 普通成员函数有 this 指针，可以访问类中的任意成员；而静态成员函数没有 this 指针

```cpp
#include <iostream>
using namespace std;

class Box {
    public:
        static int objCnt;
        Box(double l=2.0, double b = 2.0, double h = 1.0) {
            cout <<"调用构造函数。" << endl;
            length = l;
            breadth = b;
            height = h;
            objCnt += 1;
        }
        double Volume() {
            return length * breadth * height;
        }
        int compare(Box box) {
            return this -> Volume() > box.Volume();
        }
        static int getCount(){
            return objCnt;
        }
    private:
        double length;
        double breadth;
        double height;
};

// 初始化类 Box 的静态成员
int Box::objCnt = 0;
int main() {
    // 在创建对象之前输出对象的总数
    cout << "Inital Stage Count: " << Box::getCount() << endl;

    Box Box1(3.3, 1.2, 1.5);    // 声明 box1
    Box Box2(8.5, 6.0, 2.0);    // 声明 box2

    // 在创建对象之后输出对象的总数
    cout << "Final Stage Count: " << Box::getCount() << endl;
    cout << "Final Stage Count: " << Box1.getCount() << endl;

    return 0;
}
```


**关于继承权限的实验：**

```cpp
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
```

结论：

* 基类的 private 成员变量在子类中不能直接访问

* 类的 private 成员变量在子类中不能直接访问，需要通过类的 public 方法来间接访问

* public 继承的子类，在外部可以直接访问基类的 public 成员
    * 这个可以认为是 public 继承的子类，会将父类的 public 成员继承为自己的 public 成员变量，因此可以在外部直接访问

* public 继承的子类，在外部可以不可以直接访问基类的 protected 成员
    * 这个可以认为是 public 继承的子类，会将父类的 protected 成员继承为自己的 protected 成员变量，因此不可以在外部直接访问

* protected 继承的子类，在外部不可以直接访问基类的 public 成员
    * 这个可以认为是 protected 继承的子类，会将父类的 public 成员继承为自己的 protected 成员变量，因此不可以在外部直接访问

* protected 继承的子类，在外部可以不可以直接访问基类的 protected 成员

* protected 继承的子类，在外部可以不可以直接访问基类的 private 成员

* private 继承的子类，在外部不可以直接访问基类的 public 成员; private 继承的子类，在外部可以不可以直接访问基类的 protected 成员; private 继承的子类，在外部可以不可以直接访问基类的 private 成员



**-->**

* 基类的 private 成员变量是基类独有的，无论是在外部的调用，还是子类中，都无法直接使用，可以通过基类的 public 方法来间接访问

* 基类的 protect 成员是为子类继承设计的，即在外部调用无法直接使用，在子类中可以直接使用，在外部和子类中都可以通过基类的 public 方法来间接访问

* 基类的 public 成员变量是为外部访问设计的，在外部访问和子类中都可以直接使用，也可以通过基类的 public 方法来间接访问

* 子类继承基类的方式，决定了子类从基类获取到的成员的权限类型，并且基类的 private 成员，子类实际上是没有直接继承的。


## 2 继承

面向对象程序设计中最重要的一个概念是继承。继承允许我们依据另一个类来定义一个类，达到了重用代码功能和提高执行效率的效果。

当创建一个类时，不需要重新编写新的数据成员和成员函数，只需指定新建的类继承一个已有的类的成员即可。这个已有的类称为基类，新建的类称为派生类。

```cpp
// 基类
class Animal {
    // eat() 函数
    // sleep() 函数
};

//派生类
class Dog: public Animal {
    // bark() 函数
}；
```



### 2.1 基类 & 派生类

一个类可以派生自多个类，可以从多个基类继承数据和函数。定义一个派生类，使用一个类派生列表来指定基类。类派生列表以一个或多个基类命名，形式如下：

```cpp
class derived_class: access_scifier base_class
```

访问修饰符 access-specifier 是 public、protected 或 private 其中的一个，base-class 是之前定义过的某个类的名称。**如果未使用访问修饰符 access-specifier，则默认为 private**。



### 2.2 访问控制和继承

**派生类可以访问基类中所有的非私有成员**。

出不同的访问类型:

|访问|public|protected|private|
|---|---|---|---|
|同一个类|yes|yes|yes|
|派生类|yes|yes|no|
|外部的类|yes|no|no|


一个派生类继承了所有的基类方法，但下列情况除外：

* 基类的构造函数、析构函数和拷贝构造函数
* 基类的重载运算符
* 基类的友元函数



### 2.3 继承类型

基类可以被继承为 public、protected 或 private 几种类型。继承类型是通过访问修饰符 access-specifier 来指定的。

几乎不使用 `protected` 或 `private` 继承，通常使用 `public` 继承。当使用不同类型的继承时，遵循以下几个规则：

* 公有继承（public）：当一个类派生自公有基类时，基类的公有成员也是派生类的公有成员，基类的保护成员也是派生类的保护成员，**基类的私有成员不能直接被派生类访问，但是可以通过调用基类的公有和保护成员来访问**。

* 保护继承（protected）： 当一个类派生自保护基类时，基类的公有和保护成员将成为派生类的保护成员。

* 私有继承（private）：当一个类派生自私有基类时，基类的公有和保护成员将成为派生类的私有成员。



### 2.4 多继承

多继承即一个子类可以有多个父类，它继承了多个父类的特性。

C++ 类可以从多个类继承成员，语法如下：

```cpp
class <派生类名>:<继承方式1><基类名1>,<继承方式2><基类名2>,… {
    <派生类类体>
};
```

访问修饰符继承方式是 public、protected 或 private 其中的一个，用来修饰每个基类，各个基类之间用逗号分隔，

```cpp
#include <iostream>

// 基类 Shape
class Shape {
    public:
        void setWidth(int w) {
            width = w;
        }
        void setHeight(int h) {
            height = h;
        }
    protected:
        int width;
        int height;
};

// 基类 PaintCost
class PaintCost {
    public:
        int getCost(int area) {
            return area * 70;
        }
};

// 派生类
class Rectangle: public Shape, public PaintCost {
    public:
        int getArea() {
            return (width * height);
        }
};

int main() {
    Rectangle rect;
    int area;
    rect.setWidth(5);
    rect.setHeight(7);
    area = rect.getArea();

    std::cout << "Total area: " << area << std::endl;
    std::cout << "Total paint cost: $" << rect.getCost(area) << std::endl;

    return 0;
}
```


## 3 重载

C++ 允许在同一作用域中的某个函数和运算符指定多个定义，分别称为函数重载和运算符重载。

重载声明是指一个与之前已经在该作用域内声明过的函数或方法**具有相同名称**的声明，但是**它们的参数列表和定义（实现）不相同**。

当调用一个重载函数或重载运算符时，编译器通过把使用的参数类型与定义中的参数类型进行比较，决定选用最合适的定义。**选择最合适的重载函数或重载运算符的过程，称为重载决策**。



### 3.1 函数重载

在同一个作用域内，可以声明几个功能类似的**同名函数**，但是这些同名函数的**形式参数（指参数的个数、类型或者顺序）必须不同**。**不能仅通过返回类型的不同来重载函数**。

重载 `print()` 用来输出不同的数据类型：

```cpp
#include <iostream>

class printData {
    public:
        void print(int i) {
            std::cout << "INT: " << i << std::endl;
        }

        void print(double f) {
            std::cout << "DOUBLE: " << f << std::endl;
        }

        void print(char c[]) {
            std::cout << "STRING: " << c << std::endl;
        }
};

int main() {
    printData pd;
    pd.print(5);
    pd.print(2.1);
    pd.print("Hello Cpp");
    return 0;
}
```



### 3.2 运算符重载

可以重定义或重载大部分 C++ 内置的运算符。

**重载的运算符是带有特殊名称的函数**，函数名是**由关键字 operator 和其后要重载的运算符符号构成的**。与其他函数一样，重载运算符有一个返回类型和一个参数列表。

```cpp
Box operator+(const Box&);
```

声明加法运算符用于把两个 Box 对象相加，返回最终的 Box 对象。

大多数的重载运算符可被定义为**普通的非成员函数**或者被定义为**类成员函数**。如果我们定义上面的函数为类的非成员函数，那么我们需要为每次操作传递两个参数，如下所示：

```cpp
Box operator+(const Box&, const Box&);
```

```cpp
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
```



### 3.3 可重载运算符/不可重载运算符

下面是可重载的运算符列表：

|双目算术运算符|+ (加)，-(减)，*(乘)，/(除)，% (取模)|
|---|---|
|关系运算符|==(等于)，!= (不等于)，< (小于)，> (大于)，<=(小于等于)，>=(大于等于)|
逻辑运算符|ll(逻辑或)，&&(逻辑与)，!(逻辑非)|
|单目运算符|+ (正)，-(负)，*(指针)，&(取地址)|
|自增自减运算符|++(自增)，--(自减)|
|位运算符| l (按位或)，& (按位与)，~(按位取反)，^(按位异或),，<< (左移)，>>(右移)|
|赋值运算符|=, +=, -=, *=, /= , % = , &=, |=, ^=, <<=, >>=|
|空间申请与释放|new, delete, new[ ] , delete[]|
|其他运算符|()(函数调用)，->(成员访问)，,(逗号)，[](下标)|


下面是不可重载的运算符列表：

* `.`：成员访问运算符
* `.*`, `->*`：成员指针访问运算符
* `::`：域运算符
* `sizeof`：长度运算符
* `?:`：条件运算符
* `#`： 预处理符号



### 3.4 各种运算符重载

* [一元运算符重载](https://github.com/Taot-chen/LeetCode-Daiyl/blob/main/cpp_basic/src/042_class_19.cpp)
* [二元运算符重载](https://github.com/Taot-chen/LeetCode-Daiyl/blob/main/cpp_basic/src/043_class_29.cpp)
* [关系运算符重载](https://github.com/Taot-chen/LeetCode-Daiyl/blob/main/cpp_basic/src/044_class_30.cpp)
* [输入/输出运算符重载](https://github.com/Taot-chen/LeetCode-Daiyl/blob/main/cpp_basic/src/045_class_31.cpp)
* [`++` 和 `--` 运算符重载](https://github.com/Taot-chen/LeetCode-Daiyl/blob/main/cpp_basic/src/046_class_32.cpp)
* [赋值运算符重载](https://github.com/Taot-chen/LeetCode-Daiyl/blob/main/cpp_basic/src/047_class_33.cpp)
* [函数调用运算符 `()` 重载](https://github.com/Taot-chen/LeetCode-Daiyl/blob/main/cpp_basic/src/048_class_34.cpp)
* [下标运算符 `[]` 重载](https://github.com/Taot-chen/LeetCode-Daiyl/blob/main/cpp_basic/src/049_class_35.cpp)
* [类成员访问运算符 `->` 重载](https://github.com/Taot-chen/LeetCode-Daiyl/blob/main/cpp_basic/src/050_class_36.cpp)
