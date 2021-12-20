
#include <iostream>

int main(){


    //! [allocate]
    std::size_t size {10};

    int* tableau = new int[size];
    //! [allocate]


    //! [fill]
    for( std::size_t i=0; i<size; i++){
        tableau[i] = int(i);
    }
    //! [fill]


    //! [iterate]
    int* iter = tableau; 
    for( std::size_t i=0; i<size; i++){
        std::cout << *iter << std::endl;
        iter += 1; 
    }
    //! [iterate]


    //! [deallocate]
    delete[] tableau;
    //! [deallocate]


    return EXIT_SUCCESS;
}