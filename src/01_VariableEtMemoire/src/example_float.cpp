/// [all]
#include <iostream>
#include <iomanip>
#include <limits>

int main(){

    {
    float a {0.1};
    float b {0.2};

    auto precision = std::numeric_limits<float>::digits10;
    std::cout << "precision : " << precision << std::endl;
    std::cout << std::setprecision(precision+2) << "a + b = " << a + b << std::endl;
    }

    {
    double a {0.1};
    double b {0.2};

    auto precision = std::numeric_limits<double>::digits10;
    std::cout << "precision : " << precision << std::endl;
    std::cout << std::setprecision(precision+2) << "a + b = " << a + b << std::endl;
    }

    return EXIT_SUCCESS;
}

/// [all]

