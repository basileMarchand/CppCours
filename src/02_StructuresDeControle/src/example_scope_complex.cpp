
#include <iostream>

int main(){
//! [all]    
    const int variable_level_1 {10};
    {
        const int variable_level_2 {11};
        {
            const int variable_level_3 {12};
            // ici je peux utiliser toutes les variables 
        }

        // ici variable_level_3 n'existe plus 
    } 

    // ici variable_level_2 n'existe plus 
//! [all]
    return EXIT_SUCCESS;
}
