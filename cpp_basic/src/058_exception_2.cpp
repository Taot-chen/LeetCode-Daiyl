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
