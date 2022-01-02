#include <memory>
#include <iostream>

//! [func]
void do_something(std::unique_ptr<int> ptr){
    // Je fais un truc avec ptr 
}
//! [func]

int main(){

    //! [decl]
    std::unique_ptr<int> ptrInt;
    //! [decl]

    //! [well_initialized]
    if( ptrInt == nullptr){
        std::cout << "Unique ptr is nullptr" << std::endl; 
    }
    //! [well_initialized]

    //! [make_unique]
    ptrInt = std::make_unique<int>();
    //! [make_unique]

    {
    //! [decl_alloc]
    auto ptr = std::make_unique<int>();
    //! [decl_alloc]
    }

    {
    //! [array]
    std::unique_ptr<int[]> ptr_array = std::make_unique<int[]>(10);
    //! [array]
    }

    {
    #if 0
    //! [error]
    auto ptrA = std::make_unique<int>();

    auto ptrB = ptrA;
    //! [error]
 
    //! [error2]
    auto aPtr = std::make_unique<int>();
    do_something(aPtr);
    //! [error2]
    #endif
    }

    //! [move_unique]
    std::unique_ptr<int> ptr2 = std::move(ptrInt);
    //! [move_unique]

    //! [released]
    if( ptrInt == nullptr){
        std::cout << "" << std::endl;
    }
    //! [released]

    {
    //! [move_func]
    auto ptr = std::make_unique<int>();
    do_something(std::move(ptr));
    //! [move_func]
    }

    return EXIT_SUCCESS;
}