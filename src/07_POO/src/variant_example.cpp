#include <memory>
#include <iostream>
#include <variant>


//! [classes]
class A{
    public:
    void print(){
        std::cout << "A::print" << std::endl;
    }
};

class B{
    public:
    void print(){
        std::cout << "B::print" << std::endl;
    }

};

class C{
    public:
    void print(){
        std::cout << "C::print" << std::endl;
    }

};
//! [classes]

int main(){
    //! [variant]
    using A_or_B_or_C = std::variant<std::shared_ptr<A>, std::shared_ptr<B>, std::shared_ptr<C> >;
    
    A_or_B_or_C ptr;
    //! [variant]

    //! [visitor]
    ptr = std::make_shared<B>();

    std::visit([](auto&& x){ x->print();}, ptr);

    //! [visitor]

    //! [again]
    ptr = std::make_shared<A>();
    std::visit([](auto x){ x->print();}, ptr);
    //! [again]

    return EXIT_SUCCESS;

}