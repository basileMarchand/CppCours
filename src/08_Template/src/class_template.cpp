#include <iostream>

//! [number]
template<typename T>
class Number{
    public:
        Number(const T& x): value_{x}{}

        T operator()() const {
            return this->value_;
        }

        T& operator()(){
            return this->value_;
        }

        Number<T> operator+(const Number<T>& other){
            Number<T> ret( this->value_ + other() );
            return ret;
        }

        template<typename U>
        Number<T> operator+(const Number<U>& other){
            return Number<T>( this->value_ + static_cast<T>(other()));
        }

    protected:
        T value_;
};
//! [number]

int main(){

//! [number_usage]
    Number<double> a(1.1);
    Number<double> b(2.2);
    Number<int> c(42);

    std::cout << "a+b = " << (a+b)() << std::endl;
    std::cout << "a+c = " << (a+c)() << std::endl;
    std::cout << "c+a = " << (c+a)() << std::endl;
//! [number_usage]


}