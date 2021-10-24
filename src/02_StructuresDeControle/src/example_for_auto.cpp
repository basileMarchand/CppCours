#include <iostream>

int main(){
    //! [for_auto]
    const std::string value {"Hello World"};
    for( char c: value){
        std::cout << c << std::endl;
    }
    //! [for_auto]
    return EXIT_SUCCESS;
}