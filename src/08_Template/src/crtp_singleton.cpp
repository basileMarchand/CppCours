#include <memory>
#include <iostream>

//! [singleton]
template <typename Base> 
class Singleton {
    public:
        static Base& GetInstance() {
            if ( Singleton<Base>::internal_ == nullptr){
                Singleton<Base>::internal_ = std::make_shared<Base>();
            }
            return *(Singleton<Base>::internal_);
        }

        Singleton(Singleton const &) = delete;
        Singleton &operator=(Singleton const &) = delete;

    protected:
        static std::shared_ptr<Base> internal_ ;

        Singleton(){};
};

template<typename Base>
std::shared_ptr<Base> Singleton<Base>::internal_ {nullptr};

//! [singleton]

//! [class]
class A : public Singleton<A> {
  // Rest of functionality for class A
  public: 
    
    void print() const {
        std::cout << "address(A) =  " << this << std::endl;
    }

    protected:
};

//! [class]

//! [usage]
int main(){

    auto& a = A::GetInstance();
    a.print();
    auto& b = A::GetInstance();
    b.print();

    return EXIT_SUCCESS;
}
//! [usage]