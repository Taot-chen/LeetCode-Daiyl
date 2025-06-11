# C++ 基本语法

C++ 程序可以定义为对象的集合，这些对象通过调用彼此的方法进行交互。

* 类：描述对象行为、状态的模板
* 对象：类的实例，具有状态和行为
* 方法：一个方法描述类的一种行为，一个类可以有多种方法。在方法中可以写入逻辑、操作数据等某个动作。
* 即时变量：每个对象都有其独特的即时变量。对象的状态由这些即时变量的值来创建。


## 1 Hello World

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World!\n";
    return 0;
}
```

编译 & 执行：

```bash
g++ 001_helloworld.cpp -o 001_helloworld.o
./001_helloworld.o

# Hello World!
```


## 2 基本语法

### 2.1 分号 & 语句块

在 C++ 中，分号是语句结束符。也就是说，每个语句必须以分号结束。它表明一个逻辑实体的结束。

语句块是一组使用大括号括起来的按逻辑连接的语句。

C++ 不以行末作为结束符的标识，因此，可以在一行上放置多个语句。

```cpp
// 分号结束的语句
x = y;
y = y+1;

// 语句块
{
   cout << "Hello World";
   return 0;
}

// 一行多个语句
x = y; y = y+1;
```


### 2.2 C++ 标识符

C++ 标识符是用来标识变量、函数、类、模块，或任何其他用户自定义项目的名称。

一个标识符以字母 A-Z 或 a-z 或下划线 _ 开始，后跟零个或多个字母、下划线和数字（0-9）。且 C++ 的标识符区分大小写。

C++11 之后，支持 unicode 标识符，因此标识符里面可以使用汉字了。


### 2.3 C++ 关键字

关键字，即保留字，保留字不能作为标识符名称。

|asm|auto|bool|break|case|
|---|---|---|---|---|
|catch|char|class|const|const_cast|
|continue|default|delete|do|double|
|dynamic_cast|else|enum|explicit|export|
|extern|false|float|for|friend|
|goto|if|inline|int|long|
|mutable|namespace|new|operator|private|
|protected|public|register|reinterpret_cast|return|
|short|signed|sizeof|static|static_cast|
|struct|switch|template|this|throw|
|true|try|typedef|typeid|typename|
|union|unsigned|using|virtual|void|
|volatile|wchar_t|while|



### 2.4 三字符组

三字符组就是**用于表示另一个字符的三个字符序列**，又称为三字符序列。三字符序列总是以两个问号开头。

三字符序列不太常见，但 C++ 标准允许把某些字符指定为三字符序列。之所以有这个模式因为以前这些字符键盘上没有，这是必不可少的一种方法。

三字符序列可以出现在任何地方，包括**字符串**、**字符序列**、**注释**和**预处理指令**。

最常用的三字符序列：

|三字符组|替换字符|
|---|---|
|??=|#|
|??/|\|
|??'|^|
|??(|[|
|??)|]|
|??!|l|
|??<|{|
|??>|}|
|??-|~|


如果希望在源程序中有两个连续的问号，且不希望被预处理器替换，这种情况出现在字符常量、字符串字面值或者是程序注释中，可选办法是用字符串的自动连接：`"...?""?..."`或者转义序列：`"...?\?..."`。

在较新的 g++ 里面，编译器默认不再自动替换三字符组。如果需要使用三字符组替换（如为了兼容古老的软件代码），需要设置编译器命令行选项 `-trigraphs`。如果没有这个编译选项，编译器会给出警告，并且会按照原样输出。

例如：

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "??=\nHello World!\n??< ??>";
    return 0;
}
```

g++14 使用编译命令:`g++ 002_test_trigraphs.cpp -o 002_test_trigraphs.o`

会出现 warning

```bash
002_test_trigraphs.cpp:5:14: warning: trigraph ??= ignored, use -trigraphs to enable [-Wtrigraphs]
    5 |     cout << "??=\nHello World!\n??< ??>";
      |
002_test_trigraphs.cpp:5:33: warning: trigraph ??< ignored, use -trigraphs to enable [-Wtrigraphs]
002_test_trigraphs.cpp:5:37: warning: trigraph ??> ignored, use -trigraphs to enable [-Wtrigraphs]
```

执行的时候会按照原样输出：

```bash
??=
Hello World!
??< ??>
```


g++14 使用编译命令:`g++ 002_test_trigraphs.cpp -o 002_test_trigraphs.o -trigraphs`，不会出现 warning，并且执行输出符合预期：

```bash
#
Hello World!
{ }
```


### 2.5 关于空格的说明

只包含空格的行，被称为空白行，可能带有注释，C++ 编译器会完全忽略它。

在 C++ 中，空格用于描述空白符、制表符、换行符和注释。空格分隔语句的各个部分，让编译器能识别语句中的某个元素（比如 int）在哪里结束，下一个元素在哪里开始。



### 2.6 注释

程序的注释是解释性语句，可以在 C++ 代码中包含注释，这将提高源代码的可读性。

C++ 支持单行注释和多行注释。注释中的所有字符会被 C++ 编译器忽略。

* 单行注释：以 `//` 开始，直到行末为止。
```cpp
int a; // 注释
```

* 多行注释：

```bash
int a;
/*
注释
注释
*/
int b;
```


### 2.7 数据类型

存储各种数据类型（比如字符型、宽字符型、整型、浮点型、双浮点型、布尔型等）的信息，操作系统会根据变量的数据类型，来分配内存和决定在保留内存中存储什么。


#### 2.7.1 基本的内置类型

* 七种基本的 C++ 数据类型：

|类型|关键字|
|---|---|
|布尔型|bool|
|字符型|char|
|整型|int|
|单精度浮点型|float|
|双精度浮点型|double|
|无类型|void|
|宽字符型|wchar_t|

`wchar_t`是这样来的：

```cpp
typedef int wchar_t;
```

`wchar_t`实际上的空间是和 `int` 一样。

例如：

```cpp
#include <iostream>

int  main() {
    wchar_t ch = 'a';
    std::cout << "ch: " << ch << std::endl;
    std::cout << "sizeof(ch): " << sizeof(ch) << std::endl;
    std::cout << "sizeof(int): " << sizeof(int) << std::endl;
    std::cout << "sizeof(long long int): " << sizeof(long long int) << std::endl;
    std::cout << "sizeof(long int): " << sizeof(long int) << std::endl;
    std::cout << "sizeof(short int): " << sizeof(short int) << std::endl;
    return 0;
}
```

输出如下：

```bash
ch: 97
sizeof(ch): 4
sizeof(int): 4
sizeof(long long int): 8
sizeof(long int): 8
sizeof(short int): 2
```


* 一些基本类型可以使用一个或多个类型修饰符进行修饰：

|修饰符|描述|示例|
|---|---|---|
|signed|表示有符号类型（默认）|`signed int x = -10;`|
|unsigned|表示无符号类型|`unsigned int y = 10;`|
|short|表示短整型|`short int z = 100;`|
|long|表示长整型|`long int a = 100000;`|
|const|表示常量，值不可修改|`const int b = 5;`|
|volatile|表示变量可能被意外修改，禁止编译器优化|`volatile int c = 10;`|
|mutable|表示类成员可以在 const 对象中修改|`mutable int counter;`|



* 各种变量类型在内存中存储值时需要占用的内存，以及该类型的变量所能存储的最大值和最小值：

*不同系统会有所差异，一字节为 8 位。*
*默认情况下，int、short、long都是带符号的，即 signed。*
*long int 8 个字节，int 都是 4 个字节。*
*哦豁，和之前学的时候不一样了。记忆中 int 和 long int 是一样的，64 位系统中都是 4 字节，long long int 是 8 字节；从上面的实验看，现在 long int 和 long long int 是一样的了。*

|数据类型|描述|大小（字节）|取值范围|
|---|---|---|---|
|bool|布尔类型，表示真或假|1|true 或 false|
|char|字符类型，通常用于存储 ASCII 字符|1|-128 到 127 或 0 到 255|
|signed char|有符号字符类型|1|-128 到 127|
|unsigned char|无符号字符类型|1|0 到 255|
|wchar_t|宽字符类型，用于存储 Unicode 字符|2 或 4|取决于平台|
|char16_t|16 位 Unicode 字符类型（C++11 引入）|2|0 到 65,535|
|char32_t|32 位 Unicode 字符类型（C++11 引入）|4|0 到 4,294,967,295|
|short|短整型|2|-32,768 到 32,767|
|unsigned short|无符号短整型|2|0 到 65,535|
|int|整型|4|-2,147,483,648 到 2,147,483,647|
|unsigned int|无符号整型|4|0 到 4,294,967,295|
|long|长整型|4 或 8|取决于平台|
|unsigned long|无符号长整型|4 或 8|取决于平台|
|long long|长长整型（C++11 引入）|8|-9,223,372,036,854,775,808 到 9,223,372,036,854,775,807|
|unsigned long long|无符号长长整型（C++11 引入）|8|0 到 18,446,744,073,709,551,615|
|float|单精度浮点数|4|约 ±3.4e±38（6-7 位有效数字）|
|double|双精度浮点数|8|约 ±1.7e±308（15 位有效数字）|
|long double|扩展精度浮点数|8、12 或 16|取决于平台|


* C++11 新增类型

|数据类型|描述|示例|
|---|---|---|
|auto|自动类型推断|`auto x = 10;`|
|decltype|获取表达式的类型|`decltype(x) y = 10;`|
|nullptr|空指针常量|`int* ptr = nullptr;`|
|std::initializer_list|初始化列表类型|`std::initializer_list<int> list = {1, 2, 3};`|
|std::tuple|元组类型，可以存储多个不同类型的值|`std::tuple<int, float, char> t(1, 2.0, 'a');`|

*各种类型的存储大小与系统位数有关，但目前通用的以64位系统为主。变量的大小会根据编译器和所使用的电脑而有所不同。*

* 32位系统与64位系统的存储大小的差别（windows 相同）：

![alt text](./images/image.png)

环境信息：

```bash
OS: Ubuntu 22.04.5 LTS x86_64
Host: X299X AORUS MASTER -CF
Kernel: 5.15.0-141-generic
CPU: Intel i9-10940X (28) @ 4.600GHz
```

在当前的环境下的各种类型的大小：

```bash
type:           ************size**************
bool:           所占字节数：1   最大值：1               最小值：0
char:           所占字节数：1   最大值          最小值：▒
signed char:    所占字节数：1   最大值          最小值：▒
unsigned char:  所占字节数：1   最大值：▒               最小值：
wchar_t:        所占字节数：4   最大值：2147483647              最小值：-2147483648
short:          所占字节数：2   最大值：32767           最小值：-32768
int:            所占字节数：4   最大值：2147483647      最小值：-2147483648
unsigned:       所占字节数：4   最大值：4294967295      最小值：0
long:           所占字节数：8   最大值：9223372036854775807     最小值：-9223372036854775808
unsigned long:  所占字节数：8   最大值：18446744073709551615    最小值：0
double:         所占字节数：8   最大值：1.79769e+308    最小值：2.22507e-308
long double:    所占字节数：16  最大值：1.18973e+4932   最小值：3.3621e-4932
float:          所占字节数：4   最大值：3.40282e+38     最小值：1.17549e-38
size_t:         所占字节数：8   最大值：18446744073709551615    最小值：0
string:         所占字节数：32
```


#### 2.7.2 派生数据类型

|数据类型|描述|示例|
|---|---|---|
|数组|相同类型元素的集合|int arr[5] = {1, 2, 3, 4, 5};|
|指针|存储变量内存地址的类型|int* ptr = &x;|
|引用|变量的别名|int& ref = x;|
|函数|函数类型，表示函数的签名|int func(int a, float b);|
|结构体 struct|用户定义的数据类型，可以包含多个不同类型的成员|struct Point {int x; int y;};|
|类 class|用户定义的数据类型，支持封装、继承和多态|class MyClass {...};|
|联合体union|多个成员共享同一块内存|union Data {int i; float f;};|
|枚举 enum|用户定义的整数常量集合|enum Color {READ, GREEN, BLUE};|


#### 2.7.3 类型别名

|别名|描述|示例|
|---|---|---|
|typedef|为现有类型定义别名|typedef int MyInt;|
|using|为现有类型定义别名（C++11 引入）|using MyInt = int;|


#### 2.7.4 标准库类型

|数据类型|描述|示例|
|---|---|---|
|std::string|字符串类型|std::string s = "Hello";|
|std::vector|动态数字|std::vector<int> v = {1, 2, 3};|
|std::array|固定大小数组（C++11 引入）|std::array<int, 3> a = {1, 2, 3};|
|std::pair|存储两个值的容器|std::pair<int, float> p(1, 2.0);|
|std::map|键值对容器|std::map<int, std::string> m;|
|std::set|唯一值集合|std::set<int> s = {1, 2, 3;}|


#### 2.7.5 typedef 声明

可以使用 typedef 为一个已有的类型取一个新的名字：

```cpp
typedef type newname; 

typedef int feet;
// 声明一个变量
feet distance;
```

#### 2.7.6 枚举类型

枚举类型(enumeration)是C++中的一种派生数据类型，它是由用户定义的若干枚举常量的集合。

如果一个变量只有几种可能的值，可以定义为枚举(enumeration)类型。所谓"枚举"是指将变量的值一一列举出来，变量的值只能在列举出来的值的范围内。

```cpp
enum 枚举名{
    标识符[=整型常数],
    标识符[=整型常数],
...
    标识符[=整型常数]
} 枚举变量;
```

如果枚举没有初始化, 即省掉 **=整型常数** 时, 则从第一个标识符开始。

定义了一个颜色枚举，变量 c 的类型为 color。最后，c 被赋值为 "blue"：

```cpp
enum color {red, green, bloe} c;
c = blue;
```

默认情况下，第一个名称的值为 0，第二个名称的值为 1，第三个名称的值为 2，以此类推。

也可以给名称赋予一个特殊的值，只需要添加一个初始值即可。

```cpp
enum color {red, green = 5, bloe} c;
```

green 的值为 5，blue 的值为 6，因为默认情况下，每个名称都会比它前面一个名称大 1，但 red 的值依然为 0。


#### 2.7.7 类型转换

类型转换是将一个数据类型的值转换为另一种数据类型的值。

C++ 中有四种类型转换：静态转换、动态转换、常量转换和重新解释转换。


* 静态转换（Static Cast）

静态转换是**将一种数据类型的值强制转换为另一种数据类型的值**。

静态转换**通常用于比较类型相似的对象之间的转换**，例如将 int 类型转换为 float 类型。

静态转换不进行任何运行时类型检查，因此可能会导致运行时错误。

```cpp
int i = 0;
float f = static_cast<float>(i); // int --> float
```



* 动态转换（Dynamic Cast）

动态转换（dynamic_cast）是 C++ 中用于**在继承层次结构中进行向下转换（downcasting）的一种机制**。

动态转换**通常用于将一个基类指针或引用转换为派生类指针或引用**。

动态转换在运行时进行类型检查。如果转换失败，**对于指针类型会返回 `nullptr`，对于引用类型则会抛出 `std::bad_cast` 异常**。

```cpp
dynamic_cast<目标类型>(表达式)

// 目标类型：必须是指针或引用类型。
// 表达式：需要转换的基类指针或引用。
```

例如：

```cpp
#include <iostream>

class Base {
    public:
        virtual ~Base() = default;
};

class Derived: public Base {
    public:
        void show() {
            std::cout << "Derived class method" << std::endl;
        }
};

int main() {
    Base* ptr_base = new Derived;
    Derived derived_obj;
    Base& ref_base = derived_obj;

    Derived* ptr_derived = dynamic_cast<Derived*>(ptr_base);    // Base* --> Derived*
    if (ptr_derived) {
        ptr_derived -> show();
    } else {
        std::cout << "Dynamic cast failed" << std::endl;
    }

    try {
        Derived& ref_derived = dynamic_cast<Derived&>(ref_base);    // Base& --> Derived&
        ref_derived.show();
    } catch (const std::bad_cast& e) {
        std::cout << "Dynamic cast failed: " << e.what() << std::endl;
    }

    delete ptr_base;
    return 0;
}
```

运行后输出：

```bash
Derived class method
Derived class method
```


dynamic_cast 性能开销较大，且要求基类必须有虚函数。



* 常量转换（Const Cast）

常量转换**用于将 const 类型的对象转换为非 const 类型的对象**。

常量转换**只能用于转换掉 const 属性，不能改变对象的类型**。

```cpp
const int i = 10;
int& r = const_cast<int&>(i);   // const int --> int
```


* 重新解释转换（Reinterpret Cast）

重新解释转换**将一个数据类型的值重新解释为另一个数据类型的值，通常用于在不同的数据类型之间进行转换**。

重新解释转换**不进行任何类型检查**，因此可能会导致未定义的行为。

```cpp
int i = 10;
float f = reinterpret_cast<float&>(i);  // 将int类型转换为float类型，把 int 型的内存按照 float 的方式来读取
```


例如：

```cpp
#include <iostream>

int main() {
    int a = 10;
    float b = static_cast<float>(a);
    float c = reinterpret_cast<float&>(a);
    std::cout << "a: " << a << std::endl;
    std::cout << "static_cast<float>(a): " << b << std::endl;
    std::cout << "reinterpret_cast<float&>(a): " << c << std::endl;
    return 0;
}
```


输出如下：

```bash
a: 10
static_cast<float>(a): 10
reinterpret_cast<float&>(a): 1.4013e-44
```



### 2.8 变量类型

C++ 中每个变量都有指定的类型，类型决定了变量存储的大小和布局，该范围内的值都可以存储在内存中，运算符可应用于变量上。

几种基本的变量类型:

* bool：布尔类型，存储值 true 或 false，占用 1 个字节。

* char: 字符类型，用于存储 ASCII 字符，通常占用 1 个字节。

* int: 	整数类型，通常用于存储普通整数，通常占用 4 个字节。

* float: 单精度浮点值，用于存储单精度浮点数。单精度是这样的格式: **1 位符号，8 位指数，23 位小数**，通常占用4个字节。
    ![alt text](./images/image-1.png)

* double: 双精度浮点值，用于存储双精度浮点数。双精度是 1 位符号，11 位指数，52 位小数，通常占用 8 个字节。
    ![alt text](./images/image-2.png)

* void: 表示类型的缺失。

* wchar_t: 宽字符类型，用于存储更大范围的字符，通常占用 2 个或 4 个字节。


C++ 也允许定义各种其他类型的变量，比如枚举、指针、数组、引用、数据结构、类等。



#### 2.8.1 变量定义

变量定义就是告诉编译器在何处创建变量的存储，以及如何创建变量的存储。

![alt text](./images/image-3.png)


变量定义指定一个数据类型，并包含了该类型的一个或多个变量的列表:

```cpp
type variable_list;

int i, j, k;
char c, ch;
float f;
double d;
```

在这里，type 必须是一个有效的 C++ 数据类型，可以是 char、wchar_t、int、float、double、bool 或任何用户自定义的对象，variable_list 可以由一个或多个标识符名称组成，多个标识符之间用逗号分隔。


变量可以在声明的时候被初始化（指定一个初始值）。初始化器由一个等号，后跟一个常量表达式组成:

```cpp
type variable_name = value;

extern int d = 3, f = 5;
int e = 2;
double z = 22.0;
char x = 'X';
```

不带初始化的定义：**带有静态存储持续时间的变量会被隐式初始化为 NULL（所有字节的值都是 0）**，其他所有变量的初始值是未定义的。



#### 2.8.2 变量声明

变量声明向编译器保证变量以给定的类型和名称存在，这样编译器在不需要知道变量完整细节的情况下也能继续进一步的编译。变量声明只在编译时有它的意义，在程序连接时编译器需要实际的变量声明。

当使用多个文件且只在其中一个文件中定义变量时（定义变量的文件在程序连接时是可用的），变量声明就显得非常有用。此时可以使用 extern 关键字在任何地方声明一个变量。虽然可以在 C++ 程序中多次声明一个变量，但变量只能在某个文件、函数或代码块中被定义一次。

同样的，在函数声明时，提供一个函数名，而函数的实际定义则可以在任何地方进行：

```cpp
// 函数声明
int func();

int main() {
    // 函数调用
    int i = func();
}

// 函数定义
int func() {
    return 0;
}
```

#### 2.8.3 C++ 中的左值（Lvalues）和右值（Rvalues）

C++ 中有两种类型的表达式：

* 左值（lvalue）：指向内存位置的表达式被称为左值（lvalue）表达式。左值可以出现在赋值号的左边或右边。
* 右值（rvalue）：右值（rvalue）指的是存储在内存中某些地址的数值。右值是不能对其进行赋值的表达式，也就是说，右值可以出现在赋值号的右边，但不能出现在赋值号的左边。

```cpp
// 有效
int g = 10;

// 无效
10 = 20;
```


### 2.9 变量作用域

一般来说有三个地方可以定义变量：

* 在函数或一个代码块内部声明的变量，称为**局部变量**。
* 在函数参数的定义中声明的变量，称为**形式参数**。
* 在所有函数外部声明的变量，称为**全局变量**。


作用域是程序的一个区域，变量的作用域可以分为以下几种：

* 局部作用域：在函数内部声明的变量具有局部作用域，它们只能在函数内部访问。局部变量在函数每次被调用时被创建，在函数执行完后被销毁。
* 全局作用域：在所有函数和代码块之外声明的变量具有全局作用域，它们可以被程序中的任何函数访问。全局变量在程序开始时被创建，在程序结束时被销毁。
* 块作用域：在代码块内部声明的变量具有块作用域，它们只能在代码块内部访问。**块作用域变量在代码块每次被执行时被创建，在代码块执行完后被销毁**。
* 类作用域：在类内部声明的变量具有类作用域，它们可以被类的所有成员函数访问。**类作用域变量的生命周期与类的生命周期相同**。

*如果在内部作用域中声明的变量与外部作用域中的变量同名，则内部作用域中的变量将覆盖外部作用域中的变量。*


#### 2.9.1 局部变量和全局变量初始化

当局部变量被定义时，系统不会对其初始化，必须自行对其初始化。定义全局变量时，系统会自动初始化为下列值：

|数据类型|初始化默认值|
|---|---|
|int|0|
|char|'\0'|
|float|0|
|double|0|
|pointer|NULL|



### 2.10 常量

常量是固定值，在程序执行期间不会改变。这些固定的值，又叫做**字面量**。

常量可以是任何的基本数据类型，可分为**整型数字**、**浮点数字**、**字符**、**字符串**和**布尔值**。


#### 2.10.1 整数常量

整数常量可以是*十进制*、*八进制*或*十六进制*的常量。前缀指定基数：`0x` 或 `0X` 表示十六进制，`0` 表示八进制，不带前缀则默认表示十进制。

整数常量也可以带一个后缀，后缀是 `U` 和 `L` 的组合，`U` 表示无符号整数（unsigned），`L` 表示长整数（long）。后缀可以是大写，也可以是小写，U 和 L 的顺序任意。

```cpp
212         // 合法的
215u        // 合法的
0xFeeL      // 合法的
078         // 非法的：8 不是八进制的数字
032UU       // 非法的：不能重复后缀

85         // 十进制
0213       // 八进制
0x4b       // 十六进制
30         // 整数
30u        // 无符号整数
30l        // 长整数
30ul       // 无符号长整数
```


#### 2.10.2 浮点常量

浮点常量由整数部分、小数点、小数部分和指数部分组成。可以使用小数形式或者指数形式来表示浮点常量。

当使用小数形式表示时，必须包含整数部分、小数部分，或同时包含两者；当使用指数形式表示时， 必须包含小数点、指数，或同时包含两者。

```cpp
3.14159       // 合法的
314159E-5L    // 合法的
510E          // 非法的：不完整的指数
210f          // 非法的：没有小数或指数
.e55          // 非法的：缺少整数或分数
```


#### 2.10.3 布尔常量

布尔常量共有两个，它们都是标准的 C++ 关键字：

* true 值代表真。
* false 值代表假。

*可以但不应该不应把 true 的值看成 1，把 false 的值看成 0。*



#### 2.10.4 字符常量

字符常量是括在**单引号**中。如果常量以 `L`（仅当大写时）开头，则表示它是一个**宽字符常量**（例如 `L'x'`），此时它必须存储在 `wchar_t` 类型的变量中。否则，它就是一个**窄字符常量**（例如 `'x'`），此时它可以存储在 `char` 类型的简单变量中。

字符常量可以是一个**普通的字符**（例如 'x'）、一个**转义序列**（例如 '\t'），或一个**通用的字符**（例如 '\u02C0'）。

转义序列码：

|转义序列|含义|
|---|---|
|`\\`|`\`|
|`\'`|`'`|
|`\"`|`"`|
|`\?`|`?`|
|`\a`|响铃|
|`\b`|退格符|
|`\f`|换页符|
|`\n`|换行符|
|`\r`|回车|
|`\t`|水平制表符|
|`\v`|垂直制表符|
|`\ooo`|一到三位的八进制数|
|`\xhh`|一个或多个数字的十六进制数|



#### 2.10.5 字符串常量

字符串字面值或常量是括在**双引号 `""`** 中的。**一个字符串包含类似于字符常量的字符**：普通的字符、转义序列和通用的字符。

可以使用 `\` 做分隔符，把一个很长的字符串常量进行分行:

```cpp
string greeting = "hello, \
    runoob";
```


#### 2.10.6 定义常量

在 C++ 中，有两种简单的定义常量的方式：

* 使用 `#define` 预处理器。
* 使用 `const` 关键字。


`#define` 预处理器:

```cpp
#define identifier value
```

`const` 关键字:

```cpp
const type variable = value;
```




### 2.11 修饰符类型

C++ 允许在 char、int 和 double 数据类型前放置修饰符。

修饰符用于改变变量类型的行为，更能满足各种情境的需求。

数据类型修饰符：

* signed：表示变量可以存储负数。对于整型变量来说，signed 可以省略，因为整型变量默认为有符号类型。
* unsigned：表示变量不能存储负数。对于整型变量来说，unsigned 可以将变量范围扩大一倍。
* short：表示变量的范围比 int 更小。short int 可以缩写为 short。
* long：表示变量的范围比 int 更大。long int 可以缩写为 long。
* long long：表示变量的范围比 long 更大。C++11 中新增的数据类型修饰符。

修饰符 `signed`、`unsigned`、`long` 和 `short` 可应用于整型; `signed` 和 `unsigned` 可应用于字符型; `long` 可应用于双精度型。这些修饰符也可以组合使用，修饰符 `signed` 和 `unsigned` 也可以作为 `long` 或 `short` 修饰符的前缀。例如：`unsigned long int`。

C++ 允许使用速记符号来声明无符号短整数或无符号长整数。可以不写 `int`，只写单词 `unsigned`、`short` 或 `long`，`int` 是隐含的。



#### 2.11.1 类型限定符

类型限定符提供了变量的额外信息，用于在定义变量或函数时改变它们的默认行为的关键字。

|限定符|含义|
|---|---|
|const|定义常量，表示该变量的值不能被修改|
|volatile|告诉该变量的值可能会被程序以外的因素改变，如硬件或其他线程|
|restrict|由 restrict 修饰的指针是唯一一种访问它所指向的对象的方式。只有 C99 增加了新的类型限定符 restrict。|
|mutable|用于修饰类的成员变量。被 mutable 修饰的成员变量可以被修改，即使它们所在的对象是 const 的。|
|static|用于定义静态变量，表示该变量的作用域仅限于当前文件或当前函数内，不会被其他文件或函数访问|
|register|用于定义寄存器变量，表示该变量被频繁使用，可以存储在CPU的寄存器中，以提高程序的运行效率|


```cpp
// const
const int NUM = 10; // 定义常量 NUM，其值不可修改
const int* ptr = &NUM;  // 定义指向常量的指针，指针所指的值不可修改
int const* ptr2 = &NUM; //  定义指向常量的指针，指针所指的值不可修改
// 上面的两个指针完全相同，因为 const 都是直接修饰的 *，即 const 修饰的是指针指向的内存

// 常量指针
int* const ptr3 = &NUM; // 这个就不一样了，const 直接修饰的是 ptr3，即指针本身是不可修改的


// volatile
volatile int num = 10;  // 定义变量 num，其值可能会在未知的时间被改变


// mutable
class Example {
public:
    int get_value() const {
        return value_; // const 关键字表示该成员函数不会修改对象中的数据成员
    }
    void set_value(int value) const {
        value_ = value; // mutable 关键字允许在 const 成员函数中修改成员变量
    }
private:
    mutable int value_;
};



// static
void example_function() {
    static int count = 0; // static 关键字使变量 count 存储在程序生命周期内都存在
    count++;
}


// register
void example_function(register int num) {
    // register 关键字建议编译器将变量 num 存储在寄存器中
    // 以提高程序执行速度
    // 但是实际上是否会存储在寄存器中由编译器决定
}
```
