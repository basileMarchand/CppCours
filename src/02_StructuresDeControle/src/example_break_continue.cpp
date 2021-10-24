#include <iostream>

int main(){

    //! [continue]
    for( int i=0; i<10; i++){
        if( i == 3){
            continue;
        }
        std::cout << "i = " << i << std::endl;
    }
    //! [continue]

    //! [break]
    for( int i=0; i<10; i++){
        if( i == 3){
            break;
        }
        std::cout << "i = " << i << std::endl;
    }
    //! [break]





    return EXIT_SUCCESS;
}