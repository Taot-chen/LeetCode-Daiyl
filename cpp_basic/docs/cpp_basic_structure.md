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

