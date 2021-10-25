//! [all]
#include <iostream>
#include <string>

int main(int argc, char** argv){
    if( argc != 3 ){
        std::cerr << "Wrong input arguments " << std::endl;
        std::cerr << "usage : " << std::endl; 
        std::cerr << "  ./programme.out fichier.csv nbLineToTreat" << std::endl; 
        return EXIT_FAILURE; // (pour afficher la valeurs dans un terminal shell faire: echo $?
    }

    const std::string fileName = argv[1];
    const std::string nbLineStr = argv[2];

    const int nbLines = std::stoi(nbLineStr);

    // du code qui traite le fichier csv 

    return EXIT_SUCCESS;
}
//! [all]
