#include <iostream>


int main(){

    {
    int fake = 10;
    //! [no_init]
    int* ptrInt;
    std::cout << ptrInt << std::endl;
    //! [no_init]
    }
    {
    //! [init_null]
    int* ptrInt = NULL;
    std::cout << ptrInt << std::endl;
    //! [init_null]
    }
    {
    //! [init_nullptr]
    int* ptrInt = nullptr;
    std::cout << ptrInt << std::endl;
    //! [init_nullptr]
    }

    {
    //! [test_ptr]
    int* ptr {nullptr};
    if( ptr ){
        // le pointeur pointe vers quelque chose 
        // on peut l'utiliser 
    }
    else{
        // le pointeur ne pointe vers rien 
        // on ne peut donc pas l'utiliser 
    }
    //! [test_ptr]
    }

{
    //! [dereferencement]
    int unEntier {42};
    int* ptrInt = nullptr;

    ptrInt = &unEntier;
    std::cout << "ptrInt: " << ptrInt << std::endl;
    std::cout << "*ptrInt: " << *ptrInt << std::endl;

    //! [dereferencement]
}
    return EXIT_SUCCESS;
}
