//! [all]
#include <iostream>

int main(){

    const int nbVals {10};
    {// Début d'un scope local
        const int another {12};
        std::cout << "another + nbVals = " << another + nbVals << std::endl;
    }// fin du scope locale 
    return EXIT_SUCCESS;
}
//! [all]