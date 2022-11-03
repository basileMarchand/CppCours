//! [all]
#include <iostream>

int main(){
    double x; 
    std::cout << "Saisir un nombre: "; 
    std::cin >> x; 
    if(std::cin.fail()){
        std::cout << "La valeur saisie est incorrect" << std::endl; 
        return EXIT_FAILURE;
    }
    std::cout << "x = " << x << std::endl; 
    return EXIT_SUCCESS;
}

//! [all]