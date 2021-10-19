/// [all]

#include <iostream>
#include <limits>

int main(){

    std::cout << "short int: " << std::numeric_limits<short int>::min() << " -> " 
                               << std::numeric_limits<short int>::max() << std::endl;
    std::cout << "int: " << std::numeric_limits<int>::min() << " -> " 
                         << std::numeric_limits<int>::max() << std::endl;
    std::cout << "unsigned int: " << std::numeric_limits<unsigned int>::min() << " -> " 
                                  << std::numeric_limits<unsigned int>::max() << std::endl;

    return EXIT_SUCCESS;
}

/// [all]