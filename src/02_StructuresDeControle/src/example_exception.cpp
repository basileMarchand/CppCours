//! [include]
#include <stdexcept>
//! [include]

#include <iostream>
#include <cmath>

int main(){


    {
    //! [base] 
    double a ;
    double b ;
    std::string buffer;
    std::cout << "specify a: ";
    std::cin >> buffer;
    a = std::stod(buffer);
    std::cout << "specify b: ";
    std::cin >> buffer;
    b = std::stod(buffer);
    try
    {
        if( b < 0){
            throw std::runtime_error("b is negative");
        }
        double c = a * std::sqrt(b);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    //! [base]
    }
    return EXIT_SUCCESS;
}