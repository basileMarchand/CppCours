#include <iostream>

int main(){

    {
    //! [ptr_affectation]
    int *pInt {nullptr};
    int unEntier {42};
    pInt = &unEntier;
    //! [ptr_affectation]

    //! [ptr_print]
    std::cout << "&unEntier : " << &unEntier << std::endl;
    std::cout << "pInt : " << pInt << std::endl;
    //! [ptr_print]
    }
    {
     //! [ptr_init]
    int unEntier {42};
    int *pInt {&unEntier};
    //! [ptr_init]
    }
    return EXIT_SUCCESS;
}