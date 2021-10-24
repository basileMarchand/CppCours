#include <iostream>

int main(){
    const int maVariableDeTest {};
    //! [syntax]
    switch( maVariableDeTest ){
    case 7:
        std::cout << "ma variable de test vaut 7" << std::endl;
        break;
    case 42:
        std::cout << "ma variable de test vaut 42" << std::endl;
        break;
    default:
        std::cout << "ma variable de test vaut: " << maVariableDeTest << std::endl;
        break;
    }
    //! [syntax]
    return EXIT_SUCCESS;
}