/// [all]
#include <iostream>

int main(int argc, char** argv){

    if( argc != 3 ){
        return EXIT_FAILURE;
    }
    std::cout << "0: " << argv[0] << std::endl;
    std::cout << "1: " << argv[1] << std::endl;
    std::cout << "2: " << argv[2] << std::endl;

    return EXIT_SUCCESS;
}
/// [all]