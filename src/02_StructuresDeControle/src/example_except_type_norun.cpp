#include <stdexcept>
#include <iostream>
#include <random>

int main(){

    {
        //! [base]
        std::string buffer; 
        std::cout << "Mean value: ";
        std::cin >> buffer; 
        const double mean = std::stod(buffer);
        std::cout << "sigma value: ";
        std::cin >> buffer;
        const double dev = std::stod(buffer);
        std::random_device rd{};
        std::mt19937 gen{rd()};
        std::normal_distribution<> d{mean,dev};
        auto value {d(gen)};
        auto log_value = std::log( value );
        //! [base]
    }

    {
        //! [base2]
        std::string buffer; 
        std::cout << "Mean value: ";
        std::cin >> buffer; 
        const double mean = std::stod(buffer);
        std::cout << "sigma value: ";
        std::cin >> buffer;
        const double dev = std::stod(buffer);
        if( dev <= 0){
            std::invalid_argument("Invalid value for dev. Requires dev > 0");
        }
        std::random_device rd{};
        std::mt19937 gen{rd()};
        std::normal_distribution<> d{mean,dev};
        auto value {d(gen)};

        if( value < 0){
            std::runtime_error("No chance, try again");
        }

        auto log_value = std::log( value );
        //! [base2]
    }



}