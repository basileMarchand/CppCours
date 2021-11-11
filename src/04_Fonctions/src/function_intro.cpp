
/**
 * @file function_intro.cpp
 * @author Basile Marchand (basile.marchand@mines-paristech.fr)
 * @brief 
 * @version 0.1
 * @date 2021-07-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include <iostream>
#include <vector>

/// [print_coucou]
void print_coucou(){
    std::cout << "coucou" << std::endl;
}

/// [print_coucou]

//! [mean_function]
double mean(std::vector<int> v){
    double m {0.};
    for( int x: v){
        m += x;
    }
    m /= v.size();
    return m;
}
//! [mean_function]

//! [mean_function_dbl]
double mean(std::vector<double> v){
    double m {0.};
    for( int x: v){
        m += x;
    }
    m /= v.size();
    return m;
}
//! [mean_function_dbl]

//! [copy_arg]
void maFonction( std::vector<int> values){
    values[0] = 10;
}
//! [copy_arg]

int main(){
    print_coucou();

    //! [mean_call]
    std::vector<int> values {1,2,3,4,5};
    double m = mean(values);
    //! [mean_call]
    {
    //! [mean_call_double]
    std::vector<int> vInt {1,2,3,4,5};
    double m = mean(vInt);
    std::vector<double> vDouble {1.,2.,3.,4.,5.};
    double m = mean(vDouble);
    //! [mean_call_double]
    }

    {
//! [copy_arg_call]
std::vector<int> v {1,2,3};
maFonction(v);
for( auto x: v){
    std::cout << x << ", ";
}
//! [copy_arg_call]

    }
    return EXIT_SUCCESS;
}