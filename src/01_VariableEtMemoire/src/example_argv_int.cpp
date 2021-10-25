//! [all]
#include <iostream>

int main(int argc, char** argv){
    if( argc != 3 ){
        std::cerr << "Wrong input arguments " << std::endl;
        std::cout << "usage : " << std::endl; 
        std::cout << "  ./programme.out fichier.csv nbLineToTreat" << std::endl; 
        return EXIT_FAILURE;
    }

    const std::string fileName = argv[1];
    const std::string nbLineStr = argv[2];

    // du code qui traite le fichier csv 

    return EXIT_SUCCESS;
}
//! [all]
