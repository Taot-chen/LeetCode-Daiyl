# C++ 的高级操作

## 1 文件和流

前面经常使用 iostream 标准库，它提供了 cin 和 cout 方法分别用于从标准输入读取流和向标准输出写入流。

这里学习如何从文件读取流和向文件写入流。这需要用到 C++ 中另一个标准库 fstream，它定义了三个新的数据类型：

* `ofstream`：该数据类型表示输出文件流，用于创建文件并向文件写入信息。
* `ifstream`：该数据类型表示输入文件流，用于从文件读取信息。
* `fstream`：该数据类型通常表示文件流，且同时具有 ofstream 和 ifstream 两种功能，可以创建文件，向文件写入信息，从文件读取信息。

要在 C++ 中进行文件处理，必须在 C++ 源代码文件中包含头文件 `<iostream>` 和 `<fstream>`


### 1.1 打开文件

在从文件读取信息或者向文件写入信息之前，必须先打开文件。`ofstream` 和 `fstream` 对象都可以用来打开文件进行写操作，如果只需要打开文件进行读操作，则使用 `ifstream` 对象。

open() 函数是 fstream、ifstream 和 ofstream 对象的一个成员:

```cpp
void open(const char* filename, ios::openmode mode);
```

open() 成员函数的第一参数指定要打开的文件的名称和位置，第二个参数定义文件被打开的模式:

* `ios::app`：追加模式。所有写入都追加到文件末尾
* `ios::ate`：文件打开后定位到文件末尾
* `ios::in`：打开文件用于读取
* `ios::out`: 打开文件用于写入
* `ios::trunc`: 如果该文件已经存在，其内容将在打开文件之前被截断，即把文件长度设为 0。


可以把以上两种或两种以上的模式结合使用。

例如，如果想要以写入模式打开文件，并希望截断文件，以防文件已存在，那么可以使用下面的语法：

```cpp
ofstream outfile;
outfile.open("file.dat", ios::out | ios::trunc );
```

类似地，如果想要打开一个文件用于读写，可以使用下面的语法：

```cpp
ifstream  afile;
afile.open("file.dat", ios::out | ios::in );
```



### 1.2 关闭文件

当 C++ 程序终止时，它会自动关闭刷新所有流，释放所有分配的内存，并关闭所有打开的文件。但程序员应该养成一个好习惯，在程序终止前关闭所有打开的文件。

close() 函数是 fstream、ifstream 和 ofstream 对象的一个成员：

```cpp
void close();
```


### 1.3 写入文件

在 C++ 编程中，使用流插入运算符（ `<<` ）向文件写入信息，就像使用该运算符输出信息到屏幕上一样。唯一不同的是，在这里使用的是 `ofstream` 或 `fstream` 对象，而不是 `cout` 对象。


### 1.4 读取文件

在 C++ 编程中，使用流提取运算符（ `>>` ）从文件读取信息，就像使用该运算符从键盘输入信息一样。唯一不同的是，在这里使用的是 `ifstream` 或 `fstream` 对象，而不是 `cin` 对象。

以读写模式打开一个文件，在向文件 `afile.dat` 写入用户输入的信息之后，程序从文件读取信息，并将其输出到屏幕上：

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    char data[100];

    // 以写模式打开文件
    ofstream outfile;
    outfile.open("afile.dat");

    cout << "Writing to the file" << endl;
    cout << "Enter your name: ";
    cin.getline(data, 100);

    // 向文件写入文件
    outfile << data << endl;

    cout << "Enter your age: ";
    cin >> data;
    cin.ignore();

    // 再次向文件写入用户输入的数据
    outfile << data << endl;

    // 关闭打开的文件
    outfile.close();

    // 以读模式打开文件
    ifstream infile;
    infile.open("afile.dat");

    cout << "Reading from the file: " << endl;
    infile >> data;

    // 在屏幕上写入数据
    cout << data << endl;

    // 再次从文件读取数据，并显示它
    infile >> data;
    cout << data << endl;

    // 关闭打开的文件
    infile.close();
    return 0;
}
```

说明：

* `cin.getline()`函数从外部读取一行
* `cin.ignore()` 函数会忽略掉之前读语句留下的多余字符



### 1.5 文件位置指针

`istream` 和 `ostream` 都提供了用于重新定位文件位置指针的成员函数。这些成员函数包括关于 `istream` 的 `seekg（"seek get"`）和关于 `ostream` 的 `seekp（"seek put"）`。

`seekg` 和 `seekp` 的参数通常是一个**长整型**。第二个参数可以用于指定查找方向。查找方向可以是 `ios::beg`（默认的，**从流的开头开始定位**），也可以是 `ios::cur`（**从流的当前位置开始定位**），也可以是 `ios::end`（**从流的末尾开始定位**）。

**文件位置指针是一个整数值，指定了从文件的起始位置到指针所在位置的*字节数***,

```cpp
// 定位到 fileObj 的第 n 个字节（ios::begin）
fileObj.seekg(n);

// 把文件的读指针从 fileObj 当前位置向后移 n 个字节
fileObj.seekg(n, ios::cur);

// 把文件的读指针从 fileObject 末尾往回移 n 个字节
fileObj.seekg(n, ios::end);

// 定位到 fileObject 的末尾
fileObj.seekg(0, ios::end);
```



## 2 异常处理

异常是程序在执行期间产生的问题。C++ 异常是指在程序运行时发生的特殊情况，比如尝试除以零的操作。

异常提供了一种转移程序控制权的方式。C++ 异常处理涉及到三个关键字：`try`、`catch`、`throw`。

* `throw`: 当问题出现时，程序会抛出一个异常。这是通过使用 `throw` 关键字来完成的。
* catch: 在想要处理问题的地方，通过异常处理程序捕获异常。`catch` 关键字用于捕获异常。
* `try`: `try` 块中的代码标识将被激活的特定异常。它后面通常跟着一个或多个 `catch` 块。

如果有一个块抛出一个异常，捕获异常的方法会使用 `try` 和 `catch` 关键字。**`try` 块中放置可能抛出异常的代码**，`try` 块中的代码被称为保护代码。使用 `try/catch` 语句的语法如下所示：

```cpp
try {
    // 保护代码，即可能发生错误的代码
} catch (ExceptionName e1) {
    // catch 块
} catch (ExcertionName e2) {
    // catch 块
} catch (ExceptionName eN) {
    // catch 块
}
```

如果 try 块在不同的情境下会抛出不同的异常，这个时候可以尝试罗列多个 catch 语句，用于捕获不同类型的异常。


### 2.1 抛出异常

可以使用 throw 语句在代码块中的任何地方抛出异常。throw 语句的操作数可以是任意的表达式，**表达式的结果的类型决定了抛出的异常的类型**。

以下是尝试除以零时抛出异常的实例：

```cpp
double division(int a, int b) {
    if (b == 0) {
        throw "Division by zero condition!";
    }
    return (a/b);
}
```


### 2.2 捕获异常

catch 块跟在 try 块后面，用于捕获异常。可以指定想要捕捉的异常类型，这是由 catch 关键字后的括号内的异常声明决定的。

```cpp
try {
    // 保护代码
} catch (ExceptionName e) {
  // 处理 ExceptionName 异常的代码
}
```

上面的代码会捕获一个类型为 ExceptionName 的异常。如果想让 catch 块能够处理 try 块抛出的任何类型的异常，则**必须在异常声明的括号内使用省略号 `...`**，如下所示：

```cpp
try {
   // 保护代码
} catch(...) {
  // 能处理任何异常的代码
}
```

抛出一个除以零的异常，并在 catch 块中捕获该异常:

```cpp
#include <iostream>

double division(int a, int b) {
    if (b == 0) {
        throw "Division by zero condition!";
    }
    return (a/b);
}

int main() {
    int x = 50;
    int y = 0;
    double z = 0;
    try {
        z = division(x, y);
        std::cout << z << std::endl;
    } catch (const char* msg) {
        std::cerr << msg << std::endl;
    }
    return 0;
}
```

由于在函数 `division` 抛出了一个类型为 `const char*` 的异常，因此，当捕获该异常时，必须在 `catch` 块中使用 `const char*`。

输出：

```bash
Division by zero condition!
```


### 2.3 C++ 标准的异常

C++ 提供了一系列标准的异常，定义在 `<exception>` 中，可以在程序中使用这些标准的异常。它们是以父子类层次结构组织起来的，如下所示：

![alt text](./images/image-5.png)


* `std::exception`: 该异常是所有标准 C++ 异常的父类
* `std::bad_alloc`: 该异常可以通过 `new` 抛出
* `std::bad_cast`: 该异常可以通过 `dynamic_cast` 抛出
* `std::bad_typeid`: 该异常可以通过 `typeid` 抛出
* `std::bad_exception`: 这在处理 C++ 程序中无法预期的异常时非常有用
* `std::logic_error`: 理论上可以通过读取代码来检测到的异常
* `std::domain_error`: 当使用了一个**无效的数学域**时，会抛出该异常
* `std::invalid_argument`: 当使用了**无效的参数**时，会抛出该异常
* `std::length_error`: **当创建了太长的 `std::string` 时**，会抛出该异常
* `std::out_of_range`: 该异常可以通过方法抛出，例如 `std::vector` 和 `std::bitset<>::operator[]()`
* `std::runtime_error`: 理论上不可以通过读取代码来检测到的异常
* `std::overflow_error`: 当发生**数学上溢**时，会抛出该异常
* `std::range_error`: 当**尝试存储超出范围的值时**，会抛出该异常。
* `std::underflow_error`: 当发生**数学下溢**时，会抛出该异常




### 2.4 自定义异常

可以通过继承和重载 `exception` 类来定义新的异常。使用 `std::exception` 类来实现自己的异常：

```cpp
#include <iostream>
#include <exception>

struct CustomException: public std::exception {
    const char* what() const throw() {
        return "C++ Exception";
    }
};


int main() {
    try {
        throw CustomException();
    } catch (CustomException& e) {
        std::cout << "Custon Excextion caught" << std::endl;
        std::cout << e.what() << std::endl;
    } catch (std::exception& e) {
        std::cout << "Other Error" << std::endl;
    }
    return 0;
}
```

输出：

```cpp
Custon Excextion caught
C++ Exception
```

说明：

* `what()` 是异常类提供的一个公共方法，它被所有子异常类重载, 返回异常产生的原因。




## 3 动态内存

C++ 程序中的内存分为两个部分：

* 栈：在函数内部声明的所有变量都将占用栈内存。
* 堆：这是程序中未使用的内存，在程序运行时可用于动态分配内存。

很多时候，无法提前预知需要多少内存来存储某个定义变量中的特定信息，所需内存的大小需要在运行时才能确定。在 C++ 中，可以使用 `new` 运算符为给定类型的变量在运行时分配堆内的内存，并返回所分配的空间地址。

在不再需要动态分配的内存空间时，可以使用 `delete` 运算符，删除之前由 `new` 运算符分配的内存。


### 3.1 new 和 delete 运算符

使用 new 运算符来为任意的数据类型动态分配内存的通用语法：

```cpp
new data-type;
```

data-type 可以是包括数组在内的任意内置的数据类型，也可以是包括类或结构在内的用户自定义的任何数据类型。

```cpp
double* pvalue = NULL;  // 初始化为 null 的指针
pvalue = new double;    // 为变量请求内存
```

如果自由存储区已被用完，可能无法成功分配内存。建议检查 new 运算符是否返回 NULL 指针，并采取以下适当的操作：

```cpp
double* pvalue = NULL;
if (!pvalue = new double) {
    std::cout << "Error: out of memory." << std::endl;
    exit(1);
}
```

`malloc()` 函数在 C 语言中就出现了，在 C++ 中仍然存在，但建议尽量不要使用 `malloc()` 函数。new 与 malloc() 函数相比，其主要的优点是，**new 不只是分配了内存，它还创建了对象**。

在任何时候，当某个已经动态分配内存的变量不再需要使用时，可以使用 `delete` 操作符释放它所占用的内存，如下所示：

```cpp
delete pvalue;  // 释放 pvalue 所指向的内存
```



### 3.2 数组的动态内存分配

假设要为一个字符数组（一个有 20 个字符的字符串）分配内存，可以使用上面的语法来为数组动态地分配内存，如下所示：

```cpp
char* pvalue = NULL;    // 初始化为 null 的指针
pvalue = new char[20];  // 为变量请求内存
```

删除刚才创建的数组，

```cpp
delete[] pvalue;   // 删除 pvalue 所指向的数组
```

new 操作符的通用语法，可以为多维数组分配内存:

```cpp
// 一维数组
// 动态分配,数组长度为 m
int *array = new int[m];

// 释放内存
delete[] array;


// 二维数组
int** array;
// 假定数组第一维长度为 m， 第二维长度为 n
// 动态分配空间
array = new int* [m];
for (int i = 0; i < m; i++) {
    array[i] = new int[n];
}

// 释放
for (int i = 0; i < m; i++) {
    delete[] array[i];
}
delete[] array;


// 三维数组
int*** array;
// 假定数组第一维为 m， 第二维为 n， 第三维为h
// 动态分配空间
array = new int** [m];
for (int i = 0; i < m; i++) {
    array[i] = new int* [n];
    for (int j = 0; j < n; j++) {
        array[i][j] = new int [h];
    }
}

// 释放
for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
        delete[] array[i][j];
    }
    delete[] array[i];
}
delete[] array;
```


### 3.3 对象的动态内存分配

对象与简单的数据类型类似：

```cpp
#include <iostream>

class Box {
    public:
        Box() {
            std::cout << "调用构造函数！" << std::endl;
        }
        ~Box() {
            std::cout << "调用析构函数！" << std::endl;
        }
};

int main() {
    Box* box = new Box[4];
    delete[] box;   // 删除数组
    return 0;
}
```

为一个包含四个 Box 对象的数组分配内存，构造函数将被调用 4 次，同样地，当删除这些对象时，析构函数也将被调用相同的次数（4次）。

输出：

```cpp
调用构造函数！
调用构造函数！
调用构造函数！
调用构造函数！
调用析构函数！
调用析构函数！
调用析构函数！
调用析构函数！
```



## 4 命名空间

命名空间可作为附加信息来区分不同库中相同名称的函数、类、变量等。使用了命名空间即定义了上下文。本质上，命名空间就是定义了一个范围。


### 4.1 定义命名空间

命名空间的定义使用关键字 namespace，后跟命名空间的名称，

```cpp
namespace namespace_name {
    // 代码
}
```

为了调用带有命名空间的函数或变量，需要在前面加上命名空间的名称，

```cpp
name::code; // code 可以是变量或函数
```

```cpp
#include <iostream>

// 第一个命名空间
namespace firt_space {
    int a = 0;
    void func() {
        std::cout << "Inside first_space" << std::endl;
    }
}

// 第二个命名空间
namespace second_space {
    double a = 1.1;
    void func() {
        std::cout << "Inside second_space" << std::endl;
    }
}

int main() {
    auto a = firt_space::a;
    std::cout << "a = " << a << std::endl;
    firt_space::func();

    second_space::a += 2.2;
    std::cout << "second_space::a: " << second_space::a << std::endl;
    second_space::func();

    return 0;
}
```



### 4.2 using 指令

可以使用 using namespace 指令，这样在使用命名空间时就可以不用在前面加上命名空间的名称。这个指令会告诉编译器，后续的代码将使用指定的命名空间中的名称。

```cpp
#include <iostream>

// 第一个命名空间
namespace firt_space {
    int a = 0;
    void func() {
        std::cout << "Inside first_space" << std::endl;
    }
}

// 第二个命名空间
namespace second_space {
    double a = 1.1;
    void func() {
        std::cout << "Inside second_space" << std::endl;
    }
}


using namespace std;
using namespace firt_space;
int main() {
    cout << "a = " << a << endl;
    func();

    return 0;
}
```

using 指令也可以用来指定命名空间中的特定项目。例如，如果只使用 std 命名空间中的 cout 部分，可以使用如下的语句：

```cpp
using std::cout;
```

随后的代码中，在使用 cout 时就可以不用加上命名空间名称作为前缀，但是 std 命名空间中的其他项目仍然需要加上命名空间名称作为前缀，

```cpp
#include <iostream>
using std::cout;

int main() {
    int a = 0;
    cout << "a = " << a << std::endl;

    return 0;
}
```

using 指令引入的名称遵循正常的范围规则。名称从使用 using 指令开始是可见的，直到该范围结束。此时，在范围以外定义的同名实体是隐藏的。


### 4.3 不连续的命名空间

命名空间可以定义在几个不同的部分中，一个命名空间的各个组成部分可以分散在多个文件中。所以，如果命名空间中的某个组成部分需要请求定义在另一个文件中的名称，则仍然需要声明该名称。下面的命名空间定义可以是定义一个新的命名空间，也可以是为已有的命名空间增加新的元素：

```cpp
namespace namespace_name {
   // 代码声明
}
```


### 4.4 嵌套的命名空间

命名空间可以嵌套，可以在一个命名空间中定义另一个命名空间，如下所示：

```cpp
namespace namespace_name1 {
   // 代码声明
   namespace namespace_name2 {
      // 代码声明
   }
}
```

可以通过使用 :: 运算符来访问嵌套的命名空间中的成员：

```cpp
using namespace namespace_name1::namespace_name2;
using namespace namespace_name1;
```

```cpp
#include <iostream>

// 第一个命名空间
namespace firt_space {
    int a = 0;
    void func() {
        std::cout << "Inside first_space" << std::endl;
    }
    // 第二个命名空间
    namespace second_space {
        double a = 1.1;
        void func() {
            std::cout << "Inside second_space" << std::endl;
        }
    }
}

using namespace firt_space::second_space;
int main() {

    // 调用第二个命名空间中的函数
    func();
    return 0;
}
```




## 5 模板

模板是泛型编程的基础，泛型编程以一种独立于任何特定类型的方式编写代码。

模板是创建泛型类或函数的蓝图或公式。库容器，比如迭代器和算法，都是泛型编程的例子，它们都使用了模板的概念。每个容器都有一个单一的定义，比如 向量，我们可以定义许多不同类型的向量，比如 `vector <int>` 或 `vector <string>`。


### 5.1 函数模板

模板函数定义的一般形式如下所示：

```cpp
template <typename type> ret-type func-name(parameter list) {
    // 函数主体
}
```

`type` 是函数所使用的数据类型的占位符名称。这个名称可以在函数定义中使用。

```cpp
#include <iostream>
#include <string>

template <typename T> inline T const& Max (T const& a, T const& b) {
    return a > b ? a : b;
}

int main() {
    int a = 22, b = 12;
    std::cout << "Max(a, b): " << Max(a, b) << std::endl;

    double c = 1.2;
    double d = 3.5;
    std::cout << "Max(c, d): " << Max(c, d) << std::endl;

    std::string e = "Hello";
    std::string f = "World";
    std::cout << "Max(e, f): " << Max(e, f) << std::endl;

    return 0;
}
```


### 5.2 类模板

泛型类声明的一般形式如下所示：

```cpp
template <class type> class class-name {
    ...
}
```

type 是占位符类型名称，可以在类被实例化的时候进行指定。可以使用一个逗号分隔的列表来定义多个泛型数据类型。

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <stdexcept>

template <class T>
class Stack {
    private:
        std::vector<T> elems;
    public:
        void push(T const&);
        void pop();
        T top();
        bool empty() const {
            return elems.empty();
        }
};

template <class T>
void Stack<T>::push(T const& elem) {
    this->elems.push_back(elem);
}

template <class T> void Stack<T>::pop() {
    if (this->elems.empty()) {
        throw std::out_of_range("Stack<>::pop(): empty stack");
    }
    elems.pop_back();
}

template <class T>
T Stack<T>::top() {
    if (this->elems.empty()) {
        throw std::out_of_range("Stack<>::top(): empty stack");
    }
    return elems.back();
}


int main() {
    try {
        Stack<int> intStack;
        Stack<std::string> stringStack;

        intStack.push(7);
        std::cout << intStack.top() << std::endl;

        stringStack.push("hello");
        std::cout << stringStack.top() << std::endl;
        stringStack.pop();
        stringStack.pop();
    } catch (std::exception const& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return -1;
    }
    return 0;
}
```



## 6 预处理器

预处理器是一些指令，指示编译器在实际编译之前所需完成的预处理。所有的预处理器指令都是以井号（`#`）开头，**只有空格字符可以出现在预处理指令之前**。**预处理指令不是 C++ 语句，所以它们不会以分号（;）结尾**。

`#include` 指令, 这个宏用于把头文件包含到源文件中。C++ 还支持很多预处理指令，比如 `#include`、`#define`、`#if`、`#else`、`#line` 等。


### 6.1 #define 预处理

`#define` 预处理指令用于**创建符号常量**。该符号常量通常称为宏，指令的一般形式是：

```cpp
#define macro-name replacement-text
```

当这一行代码出现在一个文件中时，在该文件中后续出现的所有宏都将会在程序编译之前被替换为 replacement-text。例如：

```cpp
#include <iostream>

#define PI 3.14159

int main() {
    std::cout << "Value of Pi: " << PI << std::endl;
    return 0;
}
```

测试这段代码，看看预处理的结果。使用 `-E` 选项进行编译，并把结果重定向到 `test.p`。

```bash
g++ -E test.cpp > test.p
```

`test.p` 文件已经包含大量的信息，而且在文件底部的值被改为如下：

```cpp
...
int main() {
    std::cout << "Value of Pi: " << 3.14159 << std::endl;
    return 0;
}
```



### 6.2 参数宏

可以使用 #define 来定义一个带有参数的宏，如下所示：

```cpp
#include <iostream>

#define MIN(a, b) (a < b ? a : b)

int main() {
    int i, j;
    i = 100;
    j = 10;
    std::cout << "MIN(i, j): " << MIN(i, j) << std::endl;
    return 0;
}
```


### 6.3 条件编译

可以有选择地对部分程序源代码进行编译。这个过程被称为条件编译。条件预处理器的结构与 if 选择结构很像。

```cpp
#ifdef NUMM
    #define NULL 0
#endif
```

可以只在调试时进行编译，调试开关可以使用一个宏来实现，如下所示：

```cpp
#ifdef DEBUG
    std::cerr << "Variable x = " << x << std::endl;
#endif
```

```cpp
#include <iostream>
using namespace std;

// #define DEBUG
#define MIN(a,b) (((a)<(b)) ? a : b)

int main() {
    int i, j;
    i = 100;
    j = 10;
    #ifdef DEBUG
        std::cerr << "Trace: Inside main function" << std::endl;
    #endif

    #if 0
        /* 这是注释部分 */
        cout << MKSTR(HELLO C++) << endl;
    #endif

    cout <<"The minimum is " << MIN(i, j) << endl;

    #ifdef DEBUG
        cerr <<"Trace: Coming out of main function" << endl;
    #endif
    return 0;
}
```

上面的代码输出：

```cpp
The minimum is 10
```

把 `// #define DEBUG`取消注释，输出：

```cpp
Trace: Inside main function
The minimum is 10
Trace: Coming out of main function
```


### 6.4 `#` 和 `##` 运算符

`#` 和 `##` 预处理运算符在 C++ 和 ANSI/ISO C 中都是可用的。


`#` 运算符会把 replacement-text 令牌转换为用引号引起来的字符串。

```cpp
#include <iostream>

#define MKSTR(x)    #x

int main() {
    std::cout << MKSTR(HELLO C++) << std::endl;
    return 0;
}
```

输出：

```cpp
HELLO C++
```

实际上，在编译之前，C++ 预处理器把 `std::cout << MKSTR(HELLO C++) << std::endl;` 替换成了 `std::cout << "HELLO C++" << std::endl;`



`##` 运算符用于连接两个令牌。

```cpp
#define CONCAT(x, y) x ## y
```

当 `CONCAT` 出现在程序中时，它的参数会被连接起来，并用来取代宏。例如，程序中 `CONCAT(HELLO, C++)` 会被替换为 `"HELLO C++"`，如下面实例所示。

```cpp
#include <iostream>
using namespace std;
 
#define concat(a, b) a ## b
int main() {
   int xy = 100;
   
   cout << concat(x, y);
   return 0;
}
```

输出：

```bash
100
```

在编译之前，C++ 预处理器把 `cout << concat(x, y);` 替换成了 `cout << xy;`



### 6.5 C++ 中的预定义宏

* `__LINE__`: 这会在程序编译时包含当前行号。
* `__FILE__`: 这会在程序编译时包含当前文件名。
* `__DATE__`: 这会包含一个形式为 `month/day/year` 的字符串，它表示把源文件转换为目标代码的日期。
* `__TIME__`: 这会包含一个形式为 `hour:minute:second` 的字符串，它表示程序被编译的时间。

```cpp
#include <iostream>

int main() {
    std::cout << "Value of __FILE__: " << __FILE__ << std::endl;
    std::cout << "Value of __LINE__: " << __LINE__ << std::endl;
    std::cout << "Value of __DATE__: " << __DATE__ << std::endl;
    std::cout << "Value of __TIME__: " << __TIME__ << std::endl;
    return 0;
}
```



## 7 信号处理

信号是由操作系统传给进程的中断，会提早终止一个程序。在 UNIX、LINUX、Mac OS X 或 Windows 系统上，可以通过按` Ctrl+C` 产生中断。

有些信号不能被程序捕获，下面的信号可以在程序中捕获，并可以基于信号采取适当的动作。这些信号是定义在 C++ 头文件 `<csignal>` 中:

* `SIGABRT`: 程序的异常终止，如调用 abort。
* `SIGFPE`: 错误的算术运算，比如除以零或导致溢出的操作。
* `SIGILL`:	检测非法指令。
* `SIGINT`:	程序终止(interrupt)信号。
* `SIGSEGV`: 非法访问内存。
* `SIGTERM`: 发送到程序的终止请求。


### 7.1 signal() 函数

C++ 信号处理库提供了 signal 函数，用来捕获突发事件。以下是 signal() 函数的语法：

```cpp
void (*signal (int sig, void (*func)(int)))(int);
```

等价于：

```cpp
signal(registered signal, signal handler);
```

这个函数接收两个参数：第一个参数是要设置的信号的标识符，第二个参数是指向信号处理函数的指针。函数返回值是一个指向先前信号处理函数的指针。如果先前没有设置信号处理函数，则返回值为 `SIG_DFL`。如果先前设置的信号处理函数为 SIG_IGN，则返回值为 SIG_IGN。

```cpp
#include <iostream>
#include <csignal>
#include <unistd.h>
using namespace std;

void signalHandler(int signum) {
    cout << "Interrupt signal (" << signum << ") revieived.\n";
    // 清理并关闭
    // 终止程序
    exit(signum);
}


int main() {
    // 注册信号 SIGINT 和信号处理程序
    signal(SIGINT, signalHandler);

    while(1) {
        cout << "Going to sleep..." << endl;
        sleep(1);
    }
    return 0;
}
```

输出结果：

```bash
Going to sleep....
Going to sleep....
Going to sleep....
```

按 `Ctrl+C` 来中断程序，会看到程序捕获信号，程序打印如下内容并退出：

```cpp
Going to sleep....
Going to sleep....
Going to sleep....
Interrupt signal (2) received.
```


### 7.2 raise() 函数

可以使用函数 raise() 生成信号，该函数带有一个整数信号编号作为参数，语法如下：

```cpp
int raise(signal sig);
```

在这里，`sig` 是要发送的信号的编号，这些信号包括：`SIGINT`、`SIGABRT`、`SIGFPE`、`SIGILL`、`SIGSEGV`、`SIGTERM`、`SIGHUP`。

使用 raise() 函数内部生成信号：

```cpp
#include <iostream>
#include <csignal>
#include <unistd.h>
using namespace std;

void signalHandler(int signum) {
    cout << "Interrupt signal (" << signum << ") received.\n";
    // 清理并关闭
    // 终止程序
    exit(signum);
}

int main() {
    int i = 0;
    // 注册信号 SIGINT 和信号处理程序
    signal(SIGINT, signalHandler);
    while (++i) {
        cout << "Going to sleep...." << endl;
        if(i == 3) {
            raise(SIGINT);
        }
        sleep(1);
    }
    return 0;
}
```

代码执行的时候，会自动退出：

```cpp
Going to sleep....
Going to sleep....
Going to sleep....
Interrupt signal (2) received.
```



## 8 多线程

线程是程序中的轻量级执行单元，允许程序同时执行多个任务。多线程是多任务处理的一种特殊形式，多任务处理允许让电脑同时运行两个或两个以上的程序。

一般情况下，两种类型的多任务处理：基于进程和基于线程。

* 基于进程的多任务处理是**程序的并发执行**。
* 基于线程的多任务处理是**同一程序的片段的并发执行**。


C++ 多线程编程涉及在一个程序中创建和管理多个并发执行的线程。C++ 提供了强大的多线程支持，特别是在 C++11 标准及其之后，通过 `<thread>` 标准库使得多线程编程变得更加简单和安全。


### 8.1 概念说明

#### 8.1.1 线程 (Thread)

* 线程是程序执行中的单一顺序控制流，多个线程可以在同一个进程中独立运行。
* 线程共享进程的地址空间、文件描述符、堆和全局变量等资源，但每个线程有自己的栈、寄存器和程序计数器。


#### 8.1.2 并发 (Concurrency) 与并行 (Parallelism)

* 并发：多个任务在时间片段内交替执行，表现出同时进行的效果。
* 并行：多个任务在多个处理器或处理器核上同时执行。

C++11 及以后的标准提供了多线程支持，核心组件包括：

* `std::thread`：用于创建和管理线程。
* `std::mutex`：用于线程之间的互斥，防止多个线程同时访问共享资源。
* `std::lock_guard` 和 `std::unique_lock`：用于管理锁的获取和释放。
* `std::condition_variable`：用于线程间的条件变量，协调线程间的等待和通知。
* `std::future` 和 `std::promise`：用于实现线程间的值传递和任务同步。


### 8.2 创建线程

C++ 11 之后添加了新的标准线程库 `std::thread`，`std::thread` 在 `<thread>` 头文件中声明，因此使用 `std::thread` 时需要包含 在 `<thread>` 头文件。

注意：之前一些编译器使用 C++ 11 的编译参数是 `-std=c++11`:

```bash
g++ -std=c++11 test.cpp
```

`std::thread`

```cpp
#include <thread>
std::thread thread_obj(callable, args...);
```

* callable：可调用对象，可以是**函数指针、函数对象、Lambda 表达式**等。
* args...：传递给 callable 的参数列表。


#### 8.2.1 使用函数指针

通过函数指针创建线程，这是最基本的方式：

```cpp
#include <iostream>
#include <thread>

void printM(int count) {
    for (int i = 0; i < count; i++) {
        std::cout << "Hello from thread (function pointer)!\n";
    }
}

int main() {
    std::thread t1(printM, 5);  // 创建线程，传递函数指针和参数
    t1.join();  // 等待线程完成
    return 0;
}
```


####  8.2.2 使用函数对象

通过类中的 `operator()` 方法定义函数对象来创建线程：

```cpp
#include <iostream>
#include <thread>

class PrintTask {
    public:
        void operator () (int count) const {
            for (int i = 0; i < count; i++) {
                std::cout << "Hello from thread (function object)!\n";
            }
        }
};

int main() {
    std::thread t2(PrintTask(), 5); // 创建线程，传递函数对象和参数
    t2.join(); // 等待线程完成
    return 0;
}
```



#### 8.2.3 使用 Lambda 表达式

Lambda 表达式可以直接内联定义线程执行的代码：

```cpp
#include <iostream>
#include <thread>

int main() {
    std::thread t3([](int count){
        for (int i = 0; i < count; i++) {
            std::cout << "Hello from thread (lambda)!\n";
        }
    }, 5);  // 创建线程，传递 Lambda 表达式和参数
    t3.join();
    return 0;
}
```


### 8.3 线程管理

#### 8.3.1 join()

`join()` 用于等待线程完成执行。**如果不调用 `join()` 或 `detach()` 而直接销毁线程对象，会导致程序崩溃**。

```cpp
t.join();
```


#### 8.3.2 detach()

`detach()` 将线程与主线程分离，线程在后台独立运行，主线程不再等待它。

```cpp
t.detach();
```


### 8.4 线程的传参

* 值传递：参数可以通过值传递给线程

```cpp
std::thread t(func, arg1, arg2);
```


* 引用传递:如果需要传递引用参数，需要使用 `std::ref`

```cpp
#include <iostream>
#include <thread>

void increment(int& x) {
    ++x;
}

int main() {
    int num = 0;
    std::thread t(increment, std::ref(num));    // 使用 std::ref 传递引用
    t.join();
    std::cout << "Value after increment: " << num << std::endl;
    return 0;
}
```



### 8.5 线程同步与互斥

在多线程编程中，线程同步与互斥是两个非常重要的概念，它们用于控制多个线程对共享资源的访问，以避免数据竞争、死锁等问题。

#### 8.5.1 互斥量（Mutex）

互斥量是一种同步原语，用于**防止多个线程同时访问共享资源**。当一个线程需要访问共享资源时，它首先需要锁定（lock）互斥量。如果互斥量已经被其他线程锁定，那么请求锁定的线程将被阻塞，直到互斥量被解锁（unlock）。

`std::mutex`：用于保护共享资源，防止数据竞争。

```cpp
std::mutex mtx;
mtx.lock(); // 锁定互斥锁
// 访问共享资源
...

mtx.unlock(); // 释放互斥锁
```

`std::lock_guard` 和 `std::unique_lock`：自动管理锁的获取和释放。

```cpp
std::lock_guard<std::mutex> lock(mtx);  // 自动锁定和解锁
// 访问共享资源
...
```

```cpp
#include <mutex>
#include <thread>

std::mutex mtx; // 全局互斥量

void safeFunc() {
    mtx.lock(); // 请求锁定互斥量
    // 访问或修改共享资源

    mtx.unlock();
}

int main() {
    std::thread t1(safeFunc);
    std::thread t2(safeFunc);

    t1.join();
    t2.join();

    return 0;
}
```


#### 8.5.2 锁（Locks）

C++提供了多种锁类型，用于简化互斥量的使用和管理。

常见的锁类型包括：

* `std::lock_guard`：作用域锁，当构造时自动锁定互斥量，当析构时自动解锁。
* `std::unique_lock`：与`std::lock_guard`类似，但提供了更多的灵活性，例如可以转移所有权和手动解锁。

```cpp
#include <mutex>

std::mutex mtx;

void safeFuncWithLockGuard() {
    std::lock_guard<std::mutex> lk(mtk);
    // 访问或修改共享资源
}

void safeFuncWithUniqueLock() {
    std::unique_lock<std::mutex> ul(mtk);
    // ul.unlock(); // 可选：手动解锁
    // ...
}
```


#### 8.5.3 条件变量（Condition Variable）

条件变量用于线程间的协调，允许一个或多个线程等待某个条件的发生。它通常与互斥量一起使用，以实现线程间的同步。

`std::condition_variable`用于实现线程间的等待和通知机制。

```cpp
std::condition_variable cv;
std::mutex mtx;
bool ready = false;

std::unique_lock<std::mutex> ul(mtx);
cv.wait(ul, []{return ready;}); // 等待条件满足
// 条件满足后执行
```



#### 8.5.4 原子操作（Atomic Operations）

原子操作确保对共享数据的访问是不可分割的，在多线程环境下，原子操作要么完全执行，要么完全不执行，不会出现中间状态。

```cpp
#include <atomic>
#include <thread>

std::atomic<int> count(0);

void increment() {
    count.fetch_add(1, std::memory_order_relaxed);
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);
    t1.join();
    t2.join();
    return count;   // 应返回2
}
```


#### 8.5.5 线程局部存储（Thread Local Storage, TLS）

线程局部存储**允许每个线程拥有自己的数据副本**。这可以通过`thread_local`关键字实现，避免了对共享资源的争用。


```cpp
#include <iostream>
#include <thread>

thread_local int threadData = 0;

void threadFunction() {
    threadData = 42; // 每个线程都有自己的threadData副本
    std::cout << "Thread data: " << threadData << std::endl;
}

int main() {
    std::thread t1(threadFunction);
    std::thread t2(threadFunction);
    t1.join();
    t2.join();
    return 0;
}
```


#### 8.5.6 死锁（Deadlock）和避免策略

死锁发生在**多个线程互相等待对方释放资源，但没有一个线程能够继续执行**。避免死锁的策略包括：

* 总是以相同的顺序请求资源。
* 使用超时来尝试获取资源。
* 使用死锁检测算法。



### 8.6 线程间通信

`std::future`和`std::promise`，实现线程间的值传递。

```cpp
std::promise<int> p;
std::future<int> f = p.get_funture();

std::thread t([&p](){
    p.set_value(10);    // 设置值，触发 future
});

int result = f.get();
```

消息队列（基于 `std::queue` 和 `std::mutex`）实现简单的线程间通信。C++17 引入了并行算法库（`<algorithm>`），其中部分算法支持并行执行，可以利用多核 CPU 提高性能。

```cpp
#include <algorithm>
#include <vector>
#include <execution>

std::vector<int> vec = {1, 2, 3, 4, 5};
std::for_each(std::execution::par, vec.begin(), vec.end(), [](int &n){
    n *= 2;
})
```




## 9 C++ Web 编程

### 9.1 GCI

* 公共网关接口（CGI），是一套标准，定义了信息是如何在 Web 服务器和客户端脚本之间进行交换的。
* CGI 规范目前是由 NCSA 维护的，NCSA 定义 CGI 如下：
    * 公共网关接口（CGI），是一种用于外部网关程序与信息服务器（如 HTTP 服务器）对接的接口标准。



### 9.2 Web 浏览

* 在通过点击超链接，浏览一个特定的网页或 URL 的时候，浏览器联系上 HTTP Web 服务器，并请求 URL，即文件名。

* Web 服务器将解析 URL，并查找文件名。如果找到请求的文件，Web 服务器会把文件发送回浏览器，否则发送一条错误消息，表明请求了一个错误的文件。

* Web 浏览器从 Web 服务器获取响应，并根据接收到的响应来显示文件或错误消息。以这种方式搭建起来的 HTTP 服务器，不管何时请求目录中的某个文件，**HTTP 服务器发送回来的不是该文件，而是以程序形式执行，并把执行产生的输出发送回浏览器显示出来**。

* 公共网关接口（CGI），是使得应用程序（称为 CGI 程序或 CGI 脚本）能够与 Web 服务器以及客户端进行交互的标准协议。这些 CGI 程序可以用 Python、PERL、Shell、C 或 C++ 等进行编写。


### 9.3 CGI 架构图

![alt text](./images/image-6.png)



### 9.4 Web 服务器配置

所有由 HTTP 服务器执行的 CGI 程序，都必须在预配置的目录中。该目录称为 CGI 目录，按照惯例命名为 `/var/www/cgi-bin`。虽然 CGI 文件是 C++ 可执行文件，但是按照惯例它的扩展名是 `.cgi`。

默认情况下，Apache Web 服务器会配置在 `/var/www/cgi-bin` 中运行 CGI 程序。如果您指定其他目录来运行 CGI 脚本，您可以在 `httpd.conf` 文件中修改以下部分：

```bash
<Directory "/var/www/cgi-bin">
   AllowOverride None
   Options ExecCGI
   Order allow,deny
   Allow from all
</Directory>
 
<Directory "/var/www/cgi-bin">
Options All
</Directory>
```


### 9.4 第一个 CGI 程序

```cpp
#include <iostream>

int main() {
    std::cout << "Content-type:text/html\r\n\r\n";
    std::cout << "<html>\n";
    std::cout << "<head>\n";
    std::cout << "<title>Hello World - 第一个 CGI 程序</title>\n";
    std::cout << "</head>\n";
    std::cout << "<body>\n";
    std::cout << "<h2>Hello World! 这是我的第一个 CGI 程序</h2>\n";
    std::cout << "</body>\n";
    std::cout << "</html>\n";
   
   return 0;
}
```

编译上面的代码，把可执行文件命名为 `cplusplus.cgi`，并把这个文件保存在 `/var/www/cgi-bin` 目录中。在运行 CGI 程序之前，使用 `chmod 755 cplusplus.cgi` UNIX 命令来修改文件模式，确保文件可执行。访问可执行文件，您会看到相应的输出。

上面的 C++ 程序是一个简单的程序，把它的输出写在 `STDOUT` 文件上，即显示在屏幕上。在这里，值得注意一点，第一行输出 `Content-type:text/html\r\n\r\n`。这一行发送回浏览器，并指定要显示在浏览器窗口上的内容类型。必须理解 CGI 的基本概念，这样才能进一步使用 Python 编写更多复杂的 CGI 程序。C++ CGI 程序可以与任何其他外部的系统（如 RDBMS）进行交互。


### 9.5 HTTP 头信息

行 `Content-type:text/html\r\n\r\n` 是 HTTP 头信息的组成部分，它被发送到浏览器，以便更好地理解页面内容。HTTP 头信息的形式如下：

```bash
HTTP 字段名称: 字段内容
 
例如
Content-type: text/html\r\n\r\n
```

一些重要的 HTTP 头信息:

* `Content-type`: MIME 字符串，定义返回的文件格式。例如` Content-type:text/html`。
* `Expires: Date`: 信息变成无效的日期。浏览器使用它来判断一个页面何时需要刷新。一个有效的日期字符串的格式应为 `01 Jan 1998 12:00:00 GMT`。
* `Location: URL`: 这个 URL 是指应该返回的 URL，而不是请求的 URL。可以使用它来重定向一个请求到任意的文件。
* `Last-modified: Date`: 资源的最后修改日期。
* `Content-length: N`: 要返回的数据的长度，**以字节为单位**。浏览器使用这个值来表示一个文件的预计下载时间。
* `Set-Cookie: String`: 通过 string 设置 cookie。



### 9.6 CGI 环境变量

所有的 CGI 程序都可以访问下列的环境变量。这些变量在编写 CGI 程序时扮演了非常重要的角色: 
* `CONTENT_TYPE`: 内容的数据类型。当客户端向服务器发送附加内容时使用。例如，文件上传等功能。
* `CONTENT_LENGTH`: 查询的信息长度。只对 POST 请求可用。
* `HTTP_COOKIE`: 以键 & 值对的形式返回设置的 cookies。
* `HTTP_USER_AGENT`: 用户代理请求标头字段，递交用户发起请求的有关信息，包含了浏览器的名称、版本和其他平台性的附加信息。
* `PATH_INFO`: CGI 脚本的路径。
* `QUERY_STRING`: 通过 GET 方法发送请求时的 URL 编码信息，包含 URL 中问号后面的参数。
* `REMOTE_ADDR`: 发出请求的远程主机的 IP 地址。这在日志记录和认证时是非常有用的。
* `REMOTE_HOST`: 发出请求的主机的完全限定名称。如果此信息不可用，则可以用 REMOTE_ADDR 来获取 IP 地址。
* `REQUEST_METHOD`: 用于发出请求的方法。最常见的方法是 GET 和 POST。
* `SCRIPT_FILENAME`: CGI 脚本的完整路径。
* `SCRIPT_NAME`: CGI 脚本的名称。
* `SERVER_NAME`: 服务器的主机名或 IP 地址。
* `SERVER_SOFTWARE`: 服务器上运行的软件的名称和版本。


...
