
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


/// [print_coucou]
void print_coucou(){
    std::cout << "coucou" << std::endl;
}

/// [print_coucou]

int main(){
    print_coucou();
    
    return EXIT_SUCCESS;
}