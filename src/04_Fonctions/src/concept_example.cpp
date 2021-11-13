//! [include]
#include <concepts>
//! [include]
#include <vector>
#include <iostream>

//! [increment_base]
template<int N=1>
auto increment( auto  x ){
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

//! [increment_concept_template]
template<typename T, int N=1>
requires std::integral<T>
auto incrementConstrainedTemplate( T x ){
    using x_t = decltype(x);
    return x + static_cast<x_t>(N);
}
//! [increment_concept_template]

//! [increment_concept_convertible]
template<typename T, int N=1>
requires std::convertible_to<T, int>
auto incrementConstrainedTemplate( T x ){
    auto x_i = int(x);
    return x + N;
}
//! [increment_concept_convertible]




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

