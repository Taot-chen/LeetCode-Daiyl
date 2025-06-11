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

    Derived* ptr_derived = dynamic_cast<Derived*>(ptr_base);
    if (ptr_derived) {
        ptr_derived -> show();
    } else {
        std::cout << "Dynamic cast failed" << std::endl;
    }

    try {
        Derived& ref_derived = dynamic_cast<Derived&>(ref_base);
        ref_derived.show();
    } catch (const std::bad_cast& e) {
        std::cout << "Dynamic cast failed: " << e.what() << std::endl;
    }

    delete ptr_base;
    return 0;
}
