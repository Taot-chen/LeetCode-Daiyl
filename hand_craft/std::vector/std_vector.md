## std::vector

std::vector，一维线性序列表结构，使用连续存储空间存储元素，支持 O(1)时间访问，大小可变，支持自动扩容。

* 自动扩容，初始化时 vector 内部先分配指定空间，当容器元素满的时候，数组扩容，一般 vs 是 1.5倍，gcc 是 2 倍，并将旧数组元素拷贝到新数组，旧数组释放。

* 实现的操作，push_back(), pop_back(), insert(), erase(), reverse(), resize()


```cpp
#include <iostream>
using namespace std;

namespace myvector{

template<class T>
class Vector {
    public:
        // 迭代器类型
        typedef T* iterator;
        // 指向 const 类型常量的迭代器类型
        typedef const T* const_iterator;
        
        // 默认构造函数
        explicit Vector(int n = 0): size(0), capcity(n + SPACE_MAX) {
            if (capcity > 0) data = new T[capcity];
        }

        // 复制构造函数
        // data 必须初始化为 nullptr, 否则在执行复制赋值函数中的 delete[] data 时会被判为非法
        Vector(const Vector& v): data(nullptr), capcity(0), size(0) {
            operator=(v);
        }

        // 默认析构函数
        ~Vector() {
            delete[] data;
        }

        // 复制赋值运算符
        Vector& operator=(const Vector<T>& v);

        // 下标运算符
        T& operator[](int idx) {
            if (idx < 0 || idx >= size) {
                Error("Index out of range");
            }
            return data[idx];
        }

        // 常量型下标运算符
        const T& operator[](int idx) const {
            if (idx < 0 || idx >= size) {
                Error("Index out of range");
            }
            return data[idx];
        }

        // 判空
        bool empty() const{
            return size == 0;
        }

        // 判满
        bool full() const{
            return size == capcity;
        }

        // 求数据个数
        int size() const {
            return size;
        }

        // 求数组容量
        int max_size() const {
            return capcity;
        }

        // 尾插
        void push_back(const T& val);
        // 尾删
        void pop_back();
        // 返回尾元素引用
        const T& back() const;
        // 返回起始元素引用
        const T& front() const;


        // 扩容至 newMax，保留原始数据
        void reserve(int newMax);

        // 扩大数据个数为newSize, 保留原来数据, 其余的值初始化为item
        // 如果newSize的值大于数组容量, 则需要先调用reverse函数, 扩大数组容量
        void resize(int newSize, const T& item = T());

        // 使迭代器指向容器的数据元素起始位置
        iterator begin() {
            return &data[0];
        }
        const_iterator begin() const {
            return &data[0];
        }

        // 使迭代器指向容器的数据元素结束位置
        iterator end() {
            return &data[size];
        }
        const_iterator end() const {
            return &data[size];
        }

        // 将元素item插入到指示器it指向的位置
        iterator insert(iterator it, const T& item = T());

        // 删除指示器 it 指向的元素
        iterator erase(iterator it);

        // ++/--和解引用*不需要提供, 因为vector为顺序存储结构, 编译器提供的默认运算与其正好等价

    private:
        T* data; // 动态数组
        int size;   // 实际大小
        int capcity;    // 容量
    
        void Error(const char& s) const {
            cout << s << endl;
            exit(1);
        }

        // 枚举常量
        enum ConstVatDef {
            SPACE_MAX = 16; // 表示数据的最小预留长度
        };
};


// 复制赋值函数
template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v) {
    if (capcity != v.max_size()) {
        delete[] data;
        capcity = v.max_size();
        data = new T[capcity];
    }

    size = v.size();
    for (int i = 0; i < size; i++) {
        data[i] = v.data[i];
    }
    return (*this);
}

// 尾插
template<class T>
void Vector<T>::push_back(const T& item) {
    if (size == capcity) {
        reserve(2 * capcity + 1);
    }
    data[size++] = item;
}

// 尾删
template<class T>
void Vector<T>::pop_back() {
    if (size == 0) {
        Error("Empty vector");
    }
    size--;
}

// 返回尾元素引用
template<class T>
const T& Vector<T>::back() const {
    if (size == 09) {
        Error("Empty vector");
    }
    return data[size - 1];
}

// 返回头元素引用
template<class T>
const T& Vector<T>::front() const {
    if (size == 0) {
        Error("Empty vector");
    }
    return data[0];
}


// 扩容
template<class T>
void Vector<T>::reserve(int newMax) {
    if (newMax < size) return;
    T* old_data = data;
    data = new T[newMax];
    for (int i = 0; i < size; i++) {
        data[i] = old_data[i];
    }
    capcity = newMax;
    delete[] data;
}

// resize
template<class T>
void Vector<T>::resize(int newSize, const T& item = T()) {
    if (newSize > capcity) {
        reserve(newSize * 2 + 1);
    }
    for (int i = size; i < newSize; i++) {
        data[i] = item;
    }
    size = newSize;
}

// 将元素item插入到指示器it指向的位置
template<class T>
typename Vector<T>::iterator Vector<T>::insert(iterator it, const T& item = T()) {
    if (size == capcity) reserve(capcity * 2 + 1);
    if (it < begin() || it > end()) Error("Insert: out of range");
    // 移动插入点后面的数据
    for (iterator iter = end(); iter > it; iter--) {
        *iter = *(iter - 1);
    }
    size += 1;
    *it = item;
    return it;
    
}

// 删除指示器 it 指向的元素
template<class T>
typename Vector<T>::iterator Vector<T>::erase(iterator it) {
    if (size == 0) Error("Erase: empty vector");
    if (it < begin() || it > end()) Error("Erase: out of range");
    // 移动删除点后面的数据
    for (iterator iter = it; iter < end(); iter++) {
        *iter = *(iter + 1);
    }
    size -= 1;
    return it;
}

}
```
