# C++ 基本语法结构


## 1 C++ 循环

一般情况下，语句是顺序执行的：函数中的第一个语句先执行，接着是第二个语句，依此类推。循环语句允许我们多次执行一个语句或语句组。


### 1.1 循环类型

C++ 编程语言提供了以下几种循环类型：

|循环类型|描述|
|---|---|
|while 循环|当给定条件为真时，重复语句或语句组。它会在执行循环主体之前测试条件。|
|for 循环|多次执行一个语句序列，简化管理循环变量的代码。|
|do...while 循环|除了它是在循环主体结尾测试条件外，其他与 while 语句类似|
|嵌套循环|可以在 while、for 或 do..while 循环内使用一个或多个循环|


#### 1.1.1 while 循环

C++ 中 while 循环的语法：

```cpp
while (condition) {
    statements;
}
```

在这里，statement(s) 可以是一个单独的语句，也可以是几个语句组成的代码块。condition 可以是任意的表达式，当为任意非零值时都为真。当条件为真时执行循环。

当条件为假时，程序流将继续执行紧接着循环的下一条语句。

while 循环的关键点是**循环可能一次都不会执行**。当条件被测试且结果为假时，会跳过循环主体，直接执行紧接着 while 循环的下一条语句。



#### 1.1.2 for 循环

C++ 中 for 循环的语法：

```cpp
for (init; condition; increment) {
    statements;
}
```

for 循环的控制流：

* init 会首先被执行，且只会执行一次。这一步允许声明并初始化任何循环控制变量。也可以不在这里写任何语句，只要有一个分号出现即可。
* 接下来，会判断 condition。如果为真，则执行循环主体。如果为假，则不执行循环主体，且控制流会跳转到紧接着 for 循环的下一条语句。
* 在执行完 for 循环主体后，控制流会跳回上面的 increment 语句。该语句允许更新循环控制变量。该语句可以留空，只要在条件后有一个分号出现即可。
* 条件再次被判断。如果为真，则执行循环，这个过程会不断重复（循环主体，然后增加步值，再然后重新判断条件）。在条件变为假时，for 循环终止。


**基于范围的for循环(C++11)**

for 语句允许简单的范围迭代：

```cpp
int arr[5] = {1, 2, 3, 4, 5};
for (int &x: arr) {
    x *= 2;
    cout << x << endl;
}

// auto 类型也是 C++11 新标准中的，用来自动获取变量的类型
for (auto& x: arr) {
    x *= 2;
    cout << x << endl;
}

string str("some string");  
// range for 语句
for (auto& c: str) {
    c = toupper(c);
}
```



#### 1.1.3 do...while 循环

do...while 循环在循环的尾部检查它的条件，do...while 循环会确保至少执行一次循环。

C++ 中 do...while 循环的语法：

```cpp
do {
    statements;
} while (condition);
```



#### 1.1.4 嵌套循环

一个循环内可以嵌套另一个循环。**C++ 允许至少 256 个嵌套层次**。

C++ 中 嵌套 for 循环 语句的语法：

```cpp
for ( init; condition; increment ) {
   for ( init; condition; increment ) {
      statement(s);
   }
   statement(s); // 可以放置更多的语句
}
```

C++ 中 嵌套 while 循环 语句的语法：

```cpp
while(condition) {
   while(condition) {
      statement(s);
   }
   statement(s); // 可以放置更多的语句
}
```

C++ 中 嵌套 do...while 循环 语句的语法：

```cpp
do {
   statement(s); // 可以放置更多的语句
   do {
      statement(s);
   } while ( condition );
 
} while ( condition );
```

可以在任何类型的循环内嵌套其他任何类型的循环。


### 1.2 循环控制语句


循环控制语句更改执行的正常序列。当执行离开一个范围时，所有在该范围中创建的自动对象都会被销毁。

C++ 提供了下列的控制语句。

|控制语句|描述|
|---|---|
|break 语句|终止 loop 或 switch 语句，程序流将继续执行紧接着 loop 或 switch 的下一条语句。|
|continue 语句|引起循环跳过主体的剩余部分，立即重新开始测试条件。|
|goto 语句|将控制转移到被标记的语句。但是不建议在程序中使用 goto 语句。|


#### 1.2.1 break 语句

C++ 中 break 语句有以下两种用法：

* 当 break 语句出现在一个循环内时，循环会立即终止，且程序流将继续执行紧接着循环的下一条语句。
* 用于终止 switch 语句中的一个 case。

如果使用的是嵌套循环，break 语句会停止执行最内层的循环，然后开始执行该块之后的下一行代码。

C++ 中 break 语句的语法：

```cpp
break;
```


#### 1.2.2 continue 语句

C++ 中的 continue 语句不是强迫终止循环，continue 会跳过当前循环中的代码，强迫开始下一次循环。

C++ 中 continue 语句的语法：

```cpp
continue;
```


#### 1.2.3 goto 语句

goto 语句允许把控制无条件转移到同一函数内的被标记的语句。

注意：*不建议使用 goto 语句。因为它使得程序的控制流难以跟踪，使程序难以理解和难以修改。任何使用 goto 语句的程序可以改写成不需要使用 goto 语句的写法*。

C++ 中 goto 语句的语法：

```cpp
goto label;
...
...
label: statement;
```

`label` 是识别被标记语句的标识符，可以是任何除 C++ 关键字以外的纯文本。标记语句可以是任何语句，放置在标识符和冒号（`:`）后边。


goto 语句一个很好的作用是退出深嵌套循环。例如：

```cpp
for(...) {
   for(...) {
      while(...) {
         if(...) goto stop;
         .
         .
         .
      }
   }
}
stop:
cout << "Error in program.\n";
```

这里想要从内层循环跳出来，一个 break 做不到，需要在每个循环内都进行测试判断 break，但是 goto 可以直接跳出来。


### 1.3 无限循环

如果条件永远不为假，则循环将变成无限循环。for 循环在传统意义上可用于实现无限循环。由于**构成 for 循环的三个表达式中任何一个都不是必需的，可以将某些条件表达式留空来构成一个无限循环**。

```cpp
for (; ; ) {
    cout << 0;
}
```

当条件表达式不存在时，它被假设为真。也可以设置一个初始值和增量表达式，但是一般情况下，C++ 程序员偏向于使用 `for(;;)` 结构来表示一个无限循环。

当然了，while 和 do...while 也都可以把 condition 置为 true 来实现死循环。



## 2 C++ 判断

判断结构要求程序员指定一个或多个要评估或测试的条件，以及条件为真时要执行的语句（必需的）和条件为假时要执行的语句（可选的）。


### 2.1 判断语句

C++ 编程语言提供了以下类型的判断语句：

|语句|描述|
|---|---|
|if 语句|一个 if 语句 由一个布尔表达式后跟一个或多个语句组成。|
|if...else 语句|一个 if 语句 后可跟一个可选的 else 语句，else 语句在布尔表达式为假时执行。|
|嵌套 if 语句|可以在一个 if 或 else if 语句内使用另一个 if 或 else if 语句。|
|switch 语句|一个 switch 语句允许测试一个变量等于多个值时的情况。|
|嵌套 switch 语句|可以在一个 switch 语句内使用另一个 switch 语句。|


#### 2.1.1 if 语句

C++ 中 if 语句的语法：

```cpp
if (boolean_expression) {
   // 如果布尔表达式为真将执行的语句
}
```

如果布尔表达式为 true，则 if 语句内的代码块将被执行。如果布尔表达式为 false，则 if 语句结束后的第一组代码（闭括号后）将被执行。

C++ 语言把任何非零和非空的值假定为 true，把零或 null 假定为 false。



#### 2.1.2 if...else 语句

C++ 中 if...else 语句的语法：

```cpp
if(boolean_expression) {
   // 如果布尔表达式为真将执行的语句
} else {
   // 如果布尔表达式为假将执行的语句
}
```

如果布尔表达式为 true，则执行 if 块内的代码。如果布尔表达式为 false，则执行 else 块内的代码。


**if...else if...else 语句**

一个 if 语句后可跟一个可选的 else if...else 语句，这可用于测试多种条件。

当使用 if...else if...else 语句时，以下几点需要注意：

* 一个 if 后可跟零个或一个 else，else 必须在所有 else if 之后。
* 一个 if 后可跟零个或多个 else if，else if 必须在 else 之前。
* 一旦某个 else if 匹配成功，其他的 else if 或 else 将不会被测试。



#### 2.1.3 嵌套 if 语句

C++ 中 嵌套 if 语句的语法：

```cpp
if( boolean_expression 1) {
   // 当布尔表达式 1 为 true 时执行
   if(boolean_expression 2) {
      // 当布尔表达式 2 为 ture 时执行
   }
}
```

可以嵌套 else if...else，方式与嵌套 if 语句相似。

```cpp
if (condition1) {
   // 如果 condition1 为 true，则执行此处的代码块
   if (condition2) {
      // 如果 condition2 也为 true，则执行此处的代码块
   }
   else {
      // 如果 condition2 为 false，则执行此处的代码块
   }
}
else {
   // 如果 condition1 为 false，则执行此处的代码块
}
```


#### 2.1.4 switch 语句

一个 switch 语句允许测试一个变量等于多个值时的情况。每个值称为一个 case，且被测试的变量会对每个 switch case 进行检查。

C++ 中 switch 语句的语法：

```cpp
switch(expression) {
   case constant-expression:
      statements;
      break;   // 可选的
   case constant-expression  :
       statement(s);
       break; // 可选的
   // 可以有任意数量的 case 语句
   default : // 可选的
       statement(s);
}
```

switch 语句必须遵循下面的规则：

* switch 语句中的 expression 必须是一个**整型或枚举类型，或者是一个 class 类型**，其中 class 有一个**单一的转换函数将其转换为整型或枚举类型**。
* 在一个 switch 中可以有任意数量的 case 语句。每个 case 后跟一个要比较的值和一个冒号。
* **case 的 constant-expression 必须与 switch 中的变量具有相同的数据类型，且必须是一个常量或字面量**。
* 当被测试的变量等于 case 中的常量时，case 后跟的语句将被执行，**直到遇到 break 语句为止**。
* 当遇到 break 语句时，switch 终止，控制流将跳转到 switch 语句后的下一行。
* **不是每一个 case 都需要包含 break**。如果 case 语句不包含 break，控制流将会 继续 后续的 case，直到遇到 break 为止。
* 一个 switch 语句可以有一个**可选的 default case**，出现在 switch 的结尾。default case 可用于在上面所有 case 都不为真时执行一个任务。**default case 中的 break 语句不是必需的**。


注：

* break 语句： 每个 case 语句末尾的 break 语句，用于跳出 switch 语句。如果缺少 break，程序将继续执行下一个 case，这叫做"贯穿"。
* default 语句： default 语句是可选的，但通常在所有 case 都不匹配时使用，处理所有未列出的情况。
* 表达式类型： switch 表达式通常是整数类型或枚举类型，**浮点数和字符串类型是不可行的**。
* 有时我们可能会有意使用贯穿，以下代码，如果 number 是 2 或 3，将会执行相同的代码块。

```cpp
int num = 2;
switch(num){
   case 1:
      std::cout << "1" << std::enndl;
      break;
   case 2:
   case 3:
      std::cout << "2 or 3" << std::enndl;
      break;
   default:
      std::cout << "Number is not 1, 2, or 3" << std::endl;
}
```



#### 2.1.5 嵌套 switch 语句

可以把一个 switch 作为一个外部 switch 的语句序列的一部分，即可以在一个 switch 语句内使用另一个 switch 语句。即使内部和外部 switch 的 case 常量包含共同的值，也没有矛盾。

C++ 中的 switch 语句允许至少 256 个嵌套层次。

C++ 中 嵌套 switch 语句的语法：

```cpp
switch(ch1) {
   case 'A':
      cout << "这个 A 是外部 switch 的一部分";
      switch(ch2) {
         case 'A':
            cout << "这个 A 是内部 switch 的一部分";
            break;
         case 'B':
            // 内部 B case 代码
      }
      break;
   case 'B':
      // 外部 B case 代码
}
```



### 2.2 `? :` 运算符

条件运算符 `? : ` 可以用来代替 if...else，它的一般形式如下：

```cpp
Exp1 ? Exp2 : Exp3;
```

其中，Exp1、Exp2 和 Exp3 是表达式。

等价于：

```cpp
if (Exp1) {
   Exp2;
} else {
   Exp3;
}
```



## 3 函数

函数是一组一起执行一个任务的语句。每个 C++ 程序都至少有一个函数，即主函数 main()。


### 3.1 定义函数

C++ 中的函数定义的一般形式如下：

```cpp
return_type function_name(parameter list) {
   body of the function
}
```

在 C++ 中，函数由一个函数头和一个函数主体组成

* 返回类型：**一个函数可以返回一个值**。return_type 是函数返回的值的数据类型。有些函数执行所需的操作而不返回值，在这种情况下，return_type 是关键字 void。
* 函数名称：这是函数的实际名称。**函数名和参数列表一起构成了函数签名**。
* 参数：参数就像是**占位符**。当函数被调用时，向参数传递一个值，这个值被称为实际参数。参数列表包括函数**参数的类型、顺序、数量**。参数是可选的，也就是说，函数可能不包含参数。
* 函数主体：函数主体包含一组定义函数执行任务的语句。


### 3.2 函数声明

函数声明会告诉编译器函数名称及如何调用函数。**函数的实际主体可以单独定义**。

函数声明包括以下几个部分：

```cpp
return_type function_name( parameter list );
```

在函数声明中，参数的名称并不重要，只有参数的类型是必需的，因此下面也是有效的声明：

```cpp
// int max(int num1, int num2);
int max(int, int);
```

当在一个源文件中定义函数且在另一个文件中调用函数时，函数声明是必需的。在这种情况下，应该在调用函数的文件顶部声明函数。



### 3.3 调用函数

当程序调用函数时，程序控制权会转移给被调用的函数。被调用的函数执行已定义的任务，当函数的返回语句被执行时，或到达函数的结束括号时，会把程序控制权交还给主程序。

调用函数时，传递所需参数，如果函数返回一个值，则可以存储返回值。



### 3.4 函数参数

如果函数要使用参数，则必须声明接受参数值的变量。这些变量称为函数的**形式参数**。形式参数就像函数内的其他局部变量，**在进入函数时被创建，退出函数时被销毁**。

当调用函数时，有三种向函数传递参数的方式：

|调用类型|描述|
|---|---|
|传值调用|该方法**把参数的实际值赋值给函数的形式参数**。在这种情况下，**修改函数内的形式参数对实际参数没有影响**。|
|指针调用|该方法**把参数的地址赋值给形式参数**。在函数内，该地址用于访问调用中要用到的实际参数。这意味着，**修改形式参数会影响实际参数**。|
|引用调用|该方法**把参数的引用赋值给形式参数**。在函数内，该引用用于访问调用中要用到的实际参数。这意味着，**修改形式参数会影响实际参数**。|



### 3.5 参数的默认值

当定义一个函数，可以为参数列表中后边的每一个参数指定默认值。当调用函数时，如果实际参数的值留空，则使用这个默认值。这是通过**在函数定义中使用赋值运算符来为参数赋值的**。调用函数时，如果未传递参数的值，则会使用默认值，如果指定了值，则会忽略默认值，使用传递的值。



### 3.6 Lambda 函数与表达式

C++11 提供了对匿名函数的支持,称为 Lambda 函数(也叫 Lambda 表达式)。

**Lambda 表达式把函数看作对象。Lambda 表达式可以像对象一样使用**，比如可以将它们赋给变量和作为参数传递，还可以像函数一样对其求值。

Lambda 表达式本质上与函数声明非常类似。Lambda 表达式具体形式如下:

```cpp
[capture](parameters)->return_type{body}

// [](int x, int y){return x < y;}
// [](int x, int y) -> int { int z = x + y; return z + x; }

// 没有返回值
[capture](parameters){body}

// []{++global_x;}
```

如果 lambda 函数没有传回值（例如 void），其返回类型可被完全忽略。在Lambda表达式内可以访问当前作用域的变量，这是Lambda表达式的闭包（Closure）行为。

`[capture]`：捕捉列表。捕捉列表总是出现在 lambda 表达式的开始处。事实上，`[]` 是 `lambda` 引出符。编译器根据该引出符判断接下来的代码是否是 lambda 函数。**捕捉列表能够捕捉上下文中的变量供 lambda 函数使用**。

```bash
[]      // 沒有捕获上下文的任何变量。
[x, &y] // x以值传递的方式捕获（默认），y以引用的方式捕获。
[&]     // 任何被使用到的外部变量都隐式地以引用的方式加以引用。
[=]     // 任何被使用到的外部变量都隐式地以值传递的方式加以引用。
[&, x]  // x 显式地以传值方式加以引用。其余变量以引用方式加以引用。
[=, &z] // z 显式地以引用方式加以引用。其余变量以传值方式加以引用。
```

对于`[=]`或`[&]`的形式，lambda 表达式可以直接使用 this 指针。但是，对于`[]`的形式，如果要使用 `this` 指针，必须显式传入：

```cpp
[this](){this->someFunc();}();
```


## 4 C++ numbers

### 4.1 定义数字

```cpp
// 数字定义
short s;
int i;
long l;
double d;
float f;
```


### 4.2 数学运算

数学头文件 <cmath>：

|序号|函数|描述|
|---|---|---|
|1|double cos(double);|该函数返回弧度角（double 型）的余弦。|
|2|double sin(double);|该函数返回弧度角（double 型）的正弦。|
|3|double tan(double);|该函数返回弧度角（double 型|）的正切。
|4|double log(double);|该函数返回参数的自然对数。|
|5|double pow(double, double);|假设第一个参数为 x，第二个参数为 y，则该函数返回 x 的 y 次方。|
|6|double hypot(double, double);|该函数返回两个参数的平方总和的平方根，也就是说，参数为一个直角三角形的两个直角边，函数会返回斜边的长度。|
|7|double sqrt(double);|该函数返回参数的平方根。|
|8|int abs(int);|该函数返回整数的绝对值。|
|9|double fabs(double);|该函数返回任意一个浮点数的绝对值。|
|10|double floor(double);|该函数返回一个小于或等于传入参数的最大整数。|



### 4.3 C++ 随机数

C++ 随机数主要使用 `rand()` 和 `srand()` 两个函数。前者返回一个伪随机数，后者设置随机数种子。

```cpp
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    int i, j;
    srand((unsigned)(time(NULL)));
    for (int i = 0; i < 10; i++) {
        j = rand();
        std::cout << j << std::endl;
    }
    return 0;
}
```


### 4.4 数学常数

从 C++20 开始，标准库引入了几个常用的数学常数：

* `std::numbers::pi`， 类型：`std::float32_t`、`std::float64_t`
* `std::numbers::e`, 类型：`std::float32_t`、`std::float64_t`
* `std::numbers::phi`, 类型：`std::float32_t`、`std::float64_t`

```cpp
#include <iostream>
#include <cmath>
#include <numbers>

int main() {
    std::cout << "pi: " << std::numbers::pi << std::endl;
    std::cout << "e: " << std::numbers::e << std::endl;
    std::cout << "phi: " << std::numbers::phi << std::endl;
    return 0;
}
```
