#include <iostream>

int main(){

    //! [while_base]
    int counter {0};
    while( counter < 10 ){
        std::cout << counter << ", ";
        counter++;
    }
    //! [while_base]


    //! [do_while]
    do{
        std::cout << "dans le while";
    } while( false );
    //! [do_while]

    return EXIT_SUCCESS;
}