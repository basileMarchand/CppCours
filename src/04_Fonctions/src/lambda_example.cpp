#include <functional>
#include <iostream>
#include <vector>
#include <ranges>
#include <concepts>


auto forEach( std::ranges::common_range auto values, auto f){
    using ValueType = std::ranges::range_value_t<decltype(values)>;
    std::vector<ValueType> ret;
    ret.reserve(values.size());
    for( const ValueType& x: values ){
        ret.push_back( f(x) );
    }
    return ret; 
}

int main(){
    {
    //! [lambda_no_capture]
    int a {0};

    auto my_lambda = []() -> void {
        std::cout << "Hello from lambda" << std::endl;
    };

    my_lambda();
    //! [lambda_no_capture]
    }
    {
    //! [lambda_copy_capture]
    int a {0};

    auto my_lambda = [a]() -> void {
        std::cout << "Hello from lambda" << std::endl;
        std::cout << "a = " << a << std::endl;
    };

    my_lambda();
    //! [lambda_copy_capture]
    }
    {
    //! [lambda_ref_capture]
    int a {0};

    auto my_lambda = [&a]() -> void {
        std::cout << "Hello from lambda" << std::endl;
        a = 10;
    };

    my_lambda();
    std::cout << "a = " << a << std::endl;
    //! [lambda_ref_capture]
    }

    {
    //! [lambda_copy_all_capture]
    int a {0};
    int b {1};
    auto my_lambda = [=]() -> void {
        std::cout << "Hello from lambda" << std::endl;
        std::cout << "a = " << a << " ; b = " << b << std::endl; 
    };

    my_lambda();
    //! [lambda_copy_all_capture]
    }
    {
    //! [lambda_ref_all_capture]
    int a {0};
    int b {1};
    auto my_lambda = [&]() -> void {
        std::cout << "Hello from lambda" << std::endl;
        a = 10;
        b = 20;
    };

    my_lambda();
    std::cout << "a = " << a << std::endl;
    std::cout << "a = " << a << " ; b = " << b << std::endl;
    //! [lambda_ref_all_capture]
    }


    {
    //! [mutable]
    int counter = 42;
    auto lambda = [counter]() mutable -> void  { 
        counter++;
        std::cout <<"counter from lambda: " << counter << std::endl;
    };
    //! [mutable]

    //! [mutable_call]
    lambda();
    lambda();
    std::cout << "counter from main: " << counter << std::endl;
    //! [mutable_call]
    }


    {
    //! [for_each_call]
    std::vector<int> values {1,2,3,4,5};
    std::vector<int> values_square = forEach(values, [](int x) -> int { return x*x;});
    for( auto x: values_square){
        std::cout << x << ", ";

    }   
    //! [for_each_call]

    }

    return EXIT_SUCCESS;
}

