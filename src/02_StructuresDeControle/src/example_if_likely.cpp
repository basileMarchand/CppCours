#include <random>

int main(){

    //! [random]
    std::random_device rd{};
    std::mt19937 gen{rd()};
    const double mean {5};
    const double dev  {2};
    std::normal_distribution<> d{mean,dev};
    auto value {d(gen)};
    //! [random]

    //! [if]
    if( value>= mean-3*dev && value<= mean+3*dev ) [[likely]] {
        // do something 
    } 
    else [[unlikely]] {
        // do other thing
    }
    //! [if]
    return EXIT_SUCCESS;
}