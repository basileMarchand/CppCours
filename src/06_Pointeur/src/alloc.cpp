//! [main]
#include <iostream>

int* fois2(int a){
    int* res = new int;
    *res = 2*a;
    return res;
}

int main(){

    int unNombre = 42;

    int* ptr {nullptr};

    ptr = fois2( unNombre );

    std::cout << "*ptr: " << *ptr << std::endl;

    delete ptr;

    return EXIT_SUCCESS;
}
//! [main]