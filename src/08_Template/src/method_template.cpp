#include <iostream>

//! [printer]
class MyPrinter{
    public:
        MyPrinter(const std::string& prefix): prefix_{prefix}{   
        }

        template<typename T>
        void info(const T& data){
            std::cout << this->prefix_ <<  data << std::endl; 
        }

    protected:
        std::string prefix_;
};
//! [printer]

//! [data]
class Data{
    public: 
        Data(const double&x, const int& n, const std::string& name): x{x}, n{n}, name{name}{}

        template<typename T> 
        T get(){
            if constexpr( std::is_same_v<T, double>){
                return this->x;
            }
            else if constexpr( std::is_same_v<T, int> ){
                return this->n;
            }
            else if constexpr( std::is_same_v<T, std::string>){
                return this->name;
            }
            else{
                throw std::invalid_argument("unsupported type");   
            }
        }

    protected:
        double x; 
        int n;
        std::string name;
};
//! [data]

int main(){

    //! [printer_usage]
    MyPrinter p("[Printer] - ");
    p.info(2.34);
    p.info("coucou");
    //! [printer_usage]

    //! [data_usage]
    Data d(1.27, 42, "toto");
    std::cout << d.get<double>() << std::endl;
    std::cout << d.get<int>() << std::endl;
    try{
        std::cout << d.get<bool>() << std::endl;
    } catch( std::invalid_argument& e){

    }
    //! [data_usage]

}