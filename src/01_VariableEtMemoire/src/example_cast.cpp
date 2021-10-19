#include <limits>
#include <iostream>

int main(){

    {
    /// [implicit]
    double value {1234.5678};
    int ivalue = value; 
    /// [implicit]
    }

    {
    /// [explicit]
    double value {1234.5678};
    int ivalue = static_cast<int>(value); 
    /// [explicit]
    }


    {
    /// [static_overflow]
    int value = std::numeric_limits<short int>::max()+10;
    std::cout << "value: " << value << std::endl;
    short int sivalue = static_cast<short int>(value); 
    std::cout << "sivalue: " << sivalue << std::endl;
    /// [static_overflow]
    }
}