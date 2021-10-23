//! [all]
#include <iostream>

int main(int argc, char** argv){
    if( argc != 2 ){
        std::cerr << "Wrong input arguments " << std::endl;
        std::cout << "usage : " << std::end; 
        std::cout << "  ./programme.out fichier.csv" << std::endl; 
        return EXIT_FAILURE;
    }

    const std::string fileName = argv[1];

    // du code qui traite le fichier csv 

    return EXIT_SUCCESS;
}
//! [all]