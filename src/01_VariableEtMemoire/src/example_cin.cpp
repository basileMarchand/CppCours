//! [all]
#include <iostream>

int main(){
    std::cout << "Name of the input file to process: ";
    std::string file_name;
    std::cin >> file_name; 
    std::cout << "The file name is: " << file_name << std::endl;
    double value; 
    std::cout << "Give a floating point value: ";
    std::cin >> value; 

    return EXIT_SUCCESS;
}
//! [all]