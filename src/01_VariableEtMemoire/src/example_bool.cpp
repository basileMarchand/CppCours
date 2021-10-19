/// [all]
#include <iostream>

int main(){

    bool vrai = true;
    bool faux = false;

    std::cout << std::boolalpha << "vrai: " <<  vrai << std::endl;
    std::cout << std::boolalpha << "faux: " << faux << std::endl;
    std::cout << std::boolalpha << "!vrai: " << !vrai << std::endl;
    std::cout << std::boolalpha << "!faux:" << !faux << std::endl;
    std::cout << std::boolalpha << "vrai && faux:" << (vrai && faux) << std::endl;
    std::cout << std::boolalpha << "vrai||faux: " << (vrai || faux) << std::endl;

    return EXIT_SUCCESS;   
}

/// [all]