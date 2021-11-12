//! [include]
#include <concepts>
//! [include]
#include <vector>
#include <iostream>

//! [increment_base]
template<int N=1>
auto increment( std::integral auto  x ){
    using x_t = decltype(x);
    return x + static_cast<x_t>(N);
}
//! [increment_base]

//! [increment_concept]
template<int N=1>
auto incrementConstrained( std::integral auto  x ){
    using x_t = decltype(x);
    return x + static_cast<x_t>(N);
}
//! [increment_concept]

//! [concept_is_iterable]
template<typename T>
concept IsIterable = requires(T a){
    {std::begin(a)};
    {std::end(a)};
};
//! [concept_is_iterable]

//! [print_with_concept]
void print( IsIterable auto container){
    std::cout << "( ";
    for( auto x: container){
        std::cout << x << ", ";
    }
    std::cout << ")" << std::endl;
}
//! [print_with_concept]

int main(){
    int x {42};
    auto y = increment(x);

    //auto z = incrementConstrained("coucou");


    std::vector<int> v {1,2,3,4,5};
    print(v);
    // print(10); // compilation error 
    return EXIT_SUCCESS;
}

