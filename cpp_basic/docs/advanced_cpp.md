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


