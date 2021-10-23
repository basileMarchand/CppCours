//! [all]
#include <iostream>

int main(){
    constexpr int age {30};

    if constexpr( age < 18 ){
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