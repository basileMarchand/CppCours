#include <iostream>

/// [include_vector]
#include <vector>
/// [include_vector]


int main(){


    // 1. Declaration de vector 

    /// [create]
    std::vector<int> vInt;
    /// [create]

    /// [create_sized]
    std::vector<int> vIntSized(10);
    /// [create_sized]

    /// [create_sized_init]
    std::vector<int> vIntSizedInit(10, 2);
    /// [create_sized_init]


    /// [create_initializer_list]
    std::vector<int> vIntInitList {1, 2, 3, 4, 5};
    /// [create_initializer_list]

    {
    /// [create_initializer_list_without_type]
    std::vector vIntInitList {1, 2, 3, 4, 5};
    /// [create_initializer_list_without_type]
    }

    // 2. Acceder aux valeurs d'un std::vector 

    {
    /// [access_bracket]
    std::vector<int> v {1,2,3,4,5};
    // Acces a l'élements 0 
    int v0 = v[0];
    /// [access_bracket]
    

    /// [access_at]
    v0 = v.at(0);
    /// [access_at]
    }
    // 3. Modifier les valeurs 

    {
    /// [modify_bracket]
    std::vector<int> v {1,2,3,4,5};
    v[3] = 10;
    /// [modify_bracket]

    /// [modify_at]
    v.at(3) = 10;
    /// [modify_at]
    }
    // 4. Pourcourir les valeurs d'un std::vector 

    /// [parcour_old_school]
    std::vector<std::string> mots {"coucou", "tout", "le", "monde"};
    for( std::size_t i=0; i<mots.size(); i++){
        std::cout << mots[i] << " "; 
    }
    std::cout << std::endl;
    /// [parcour_old_school]

    /// [parcour_post_cpp11]
    for( auto m: mots){
        std::cout << m << " ";
    }
    /// [parcour_post_cpp11]





    return EXIT_SUCCESS;
}