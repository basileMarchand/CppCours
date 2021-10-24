#include <iostream>

int main(){

    {
    //! [base]
    int counter {0};

    for( counter = 0; counter <10; counter++){
        std::cout << counter;
    }
    //! [base]
    }

    {
    //! [no_init]
    int counter {0};

    for( ; counter <10; counter++){
        std::cout << counter;
    }
    //! [no_init]
    }

    {
    //! [decl_in_for]

    for(int counter=0; counter <10; counter++){
        std::cout << counter;
    }
    //! [decl_in_for]
    }

    return EXIT_SUCCESS;
}