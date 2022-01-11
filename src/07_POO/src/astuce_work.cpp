#include <memory>
#include <iostream>

//! [main]
class A;

class B {
    public:

        void registerA(std::shared_ptr<A> a){
            this->ptrA_ = a;
        }

    protected:
        std::shared_ptr<A> ptrA_;

};

class A: public std::enable_shared_from_this<A>{
    public:

        void attachMe(std::shared_ptr<B> b){
                        b->registerA( this->shared_from_this() );
        }
};

int main(){
    std::shared_ptr<B> ptr_b = std::make_shared<B>();
    std::shared_ptr<A> ptr_a = std::make_shared<A>();

    ptr_a->attachMe(ptr_b);

    return EXIT_SUCCESS;
}

//! [main]