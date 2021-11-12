#include <iostream>
#include <vector>

//! [print_specific_int]
void printVector(const std::vector<int>& v){
    std::cout << "( ";
    for( auto x: v){
        std::cout << x << ", ";
    }
    std::cout << ")" << std::endl;
}
//! [print_specific_int]

//! [print_specific_double]
void printVector(const std::vector<double>& v){
    std::cout << "( ";
    for( auto x: v){
        std::cout << x << ", ";
    }
    std::cout << ")" << std::endl;
}
//! [print_specific_double]

//! [print_template]
template<typename T>
void print( const std::vector<T>& v){
    std::cout << "( ";
    for( auto x: v){
        std::cout << x << ", ";
    }
    std::cout << ")" << std::endl;
}
//! [print_template]

//! [print_auto]
void printAuto( const auto& v){
    std::cout << "( ";
    for( auto x: v){
        std::cout << x << ", ";
    }
    std::cout << ")" << std::endl;
}
//! [print_auto]

//! [increment]
template<typename T, int N>
T increment( const T& x){
    return x + static_cast<T>(N);
}
//! [increment]

//! [increment_default]
template<typename T, int N=1>
T incrementWithDefault( const T& x){
    return x + static_cast<T>(N);
}
//! [increment_default]

//! [increment_no_cast]
template<typename T, T N=T(1)>
T incrementNoCast( const T& x){
    return x + N;
}
//! [increment_no_cast]

//! [fibonacci]
template<int N>
int fibonacci(){
    if constexpr( N == 0){
        return 0;
    }
    else if constexpr( N == 1){
        return 1;
    }
    else{
        return fibonacci<N-1>() + fibonacci<N-2>();
    }
}
//! [fibonacci]


int main(){

    {
    //! [print_specific_int_call]
    std::vector<int> v_int {1, 2, 3, 4, 5};
    printVector(v_int);
    //! [print_specific_int_call]
    //! [print_specific_double_call]
    std::vector<double> v_double {1.1, 2.2, 3.3, 4.4, 5.5};
    printVector(v_double);
    //! [print_specific_double_call]
    }
    {
    //! [print_template_call]
    std::vector<int> v_int {1, 2, 3, 4, 5};
    print(v_int);
    std::vector<double> v_double {1.1, 2.2, 3.3, 4.4, 5.5};
    print(v_double);
    //! [print_template_call]
    }

    {
        //! [increment_call]
        double x = 42.42;
        auto y = increment<double, 10>(x);
        //! [increment_call]
    }

    {
        //! [increment_default_call]
        double x = 42.42;
        auto y = incrementWithDefault<double, 10>(x); // y = 52.42
        y = incrementWithDefault<double>(x);          // y = 43.42
        //! [increment_default_call]
    }

    {
    //! [increment_no_cast_call]
    std::int64_t x {1000};
    auto y = incrementNoCast<std::int64_t, 10000000>(x);
    //! [increment_no_cast_call]
    }

}