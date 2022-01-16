#include <memory>
#include <iostream>

//! [base]
template<typename Derived>
class Base{
    public:
        void doSomething(){
            static_cast<Derived*>(this)->doSomethingSpecial();
        }
};
//! [base]

//! [derived]
class DerivedA: public Base<DerivedA>{

    public:
        void doSomethingSpecial(){
            std::cout << "In DerivedA::doSomethingSpecial" << std::endl;
        }
};

class DerivedB: public Base<DerivedB>{
    public:
        void doSomethingSpecial(){
            std::cout << "In DerivedB::doSomethingSpecial" << std::endl;
        }
};
//! [derived]

//! [usage]
int main(){

    DerivedA a;
    a.doSomething();

    DerivedB b;
    b.doSomething();
    return EXIT_SUCCESS;
}
//! [usage]