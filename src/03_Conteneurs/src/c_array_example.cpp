#include <iostream>


/// [getSize]
constexpr int getSize(){
    return 2*10; 
}
/// [getSize]

int getSize2(){
    return 2*10;
}


int main(){

    // 1. Déclaration d'un tableau statique 

    /// [create]
    int tableau[10]; 
    /// [create]


    /// [create_constexpr]
    double tableauDouble[getSize()];
    /// [create_constexpr]

    /// [create_const]
    double tableauDouble2[getSize2()];
    /// [create_const]

    // 2. Acces aux valeurs 

    /// [acces_read]
    double v2 = tableauDouble[2];
    /// [acces_read]

    /// [acces_write]
    tableauDouble[2] = 10.34;
    /// [acces_write]

    {
    //! [list_init_1]
    int tableauInt[] {1,2,3,4,5};
    //! [list_init_1] 
    }

    {
    //! [list_init_2]
    int tableauInt[10] {1,2,3,4,5};
    //! [list_init_2] 
    }

    {
    //! [list_init_3]
    int tableauInt[10] {};
    //! [list_init_3] 
    }

 {
    //! [array_size]
    int tableauInt[10] {1,2,3,4,5};
    int sz = sizeof(tableauInt) / sizeof(tableauInt[0]);
    //! [array_size] 
    std::cout << sz << std::endl;
    }


    return EXIT_SUCCESS;
}