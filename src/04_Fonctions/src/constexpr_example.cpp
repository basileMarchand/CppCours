#include <iostream>

//! [factorial]
constexpr int factorial(const int n){
    if(n<1){
        return 1;
    }
    return n*factorial(n-1);
}
//! [factorial]

int main(){

    auto f10 {factorial(10)};
    std::cout << f10 << std::endl;
    return EXIT_SUCCESS;
}