#include <iostream>

int main(){

    /// [nomix]
    int int_a = 1;
    int int_b = 3;
    float f_a = 1.;
    float f_b = 3.; 

    std::cout << "int_a / int_b=" << int_a / int_b << std::endl;
    std::cout << "f_a / f_b=" << f_a / f_b << std::endl;
    /// [nomix]


    /// [mix]
    std::cout << "f_a / int_b=" << f_a / int_b << std::endl;
    std::cout << "int_a / f_b=" << int_a / f_b << std::endl;
    /// [mix]

}