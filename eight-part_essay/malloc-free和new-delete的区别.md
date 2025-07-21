## malloc/free 和 new/delete 的区别

In One Word:

* malloc、free 是 C 语言的库函数，new、delete 是 C++ 的运算符
* new 自动计算需要分配内存的大小，malloc 需要手动计算
* new 返回的是对象类型指针，malloc 返回的是 void* 指针，使用时需要进行类型转换
* new 分配失败会抛出异常，malloc 分配失败返回 NULL
* new 在 free store 上分配内存，malloc 在堆上分配内存
* delete 需要对象类型指针，free 需要 void* 类型指针

