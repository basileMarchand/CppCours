#include <iostream>

int main(){

    //! [base]
    double monDouble {42.0};

    std::cout << "monDouble = " << monDouble << std::endl;
    //! [base]

    //! [address]
    std::cout << "adresse de monDouble: " << &monDouble << std::endl;
    //! [address]

    return EXIT_SUCCESS;
}