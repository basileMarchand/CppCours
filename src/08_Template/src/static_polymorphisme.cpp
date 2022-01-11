#include <memory>
#include <iostream>


template<typename Derived>
class Base{
    public:
        void doSomething(){
            static_cast<Derived*>(this)->doSomethingSpecial();
        }


};

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

int main(){

    DerivedA a;
    a.doSomething();

    DerivedB b;
    b.doSomething();
    return EXIT_SUCCESS;
}