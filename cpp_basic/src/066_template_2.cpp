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
