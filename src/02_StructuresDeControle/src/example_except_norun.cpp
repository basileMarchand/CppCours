#include <stdexcept>
#include <iostream>

int main(){

    {
        //! [example1]
        int a, b;
        std::string buffer;
        std::cout << "valeur de a: ";
        std::cin >> buffer; a = std::stoi(buffer);
        std::cout << "valeur de b: ";
        std::cin >> buffer; b = std::stoi(buffer);
        
        int c = a / b ;
        //! [example1]
    }
    {
        //! [example2]
        int a, b;
        std::string buffer;
        std::cout << "valeur de a: ";
        std::cin >> buffer; a = std::stoi(buffer);
        std::cout << "valeur de b: ";
        std::cin >> buffer; b = std::stoi(buffer);
        if( b == 0){
            throw std::invalid_argument("Invalid value for b. Requires b != 0");
        }
        int c = a / b ;
        //! [example2]
    }




}