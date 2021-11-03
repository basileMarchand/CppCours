//! [all]
#include <iostream>

void print_coucou(); // déclaration

int main(){
    print_coucou();
    return EXIT_SUCCESS;
}

void print_coucou(){ // définition
    std::cout << "coucou" << std::endl;
}
//! [all]