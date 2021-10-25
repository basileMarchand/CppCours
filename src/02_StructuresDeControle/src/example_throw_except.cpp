//! [include]
#include <stdexcept>
//! [include]

int main(){

//! [all]
throw std::runtime_error("Oups... il ne fallait pas faire ça!");
//! [all]
    return EXIT_SUCCESS;
}