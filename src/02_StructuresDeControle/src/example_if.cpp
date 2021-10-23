//! [all]
#include <iostream>

int main(){
    std::cout << "Saisir votre age: ";
    std::string input;
    std::cin >> input;

    const unsigned int age { std::stoi(input) };

    if( age < 18 ){
        std::cout << "Mineur (mais pas du 60 bvd St. Michel)" << std::endl;
    }
    else if( (age >= 18) && (age<=30) ){
        std::cout << "Pas encore trop vieux" << std::endl; 
    }
    else {
        std::cout << "L'age de sagesse" << std::endl; 
    }
    return EXIT_SUCCESS;
}
//! [all]