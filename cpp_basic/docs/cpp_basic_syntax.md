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


