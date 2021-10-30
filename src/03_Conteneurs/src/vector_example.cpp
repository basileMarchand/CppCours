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
    std::cout << std::endl;

    // 5. Ajouter/supprimer des valeurs 

    {
        //! [push_back]
        std::vector<int> vInt {1,2,3,4,5};
        vInt.push_back(6);  // vInt = {1,2,3,4,5,6};
        vInt.push_back(7);  // vInt = {1,2,3,4,5,6,7};
        auto sz = std::size(vInt); // sz = 7 
        //! [push_back]
    
        //! [pop_back]
        vInt.pop_back();
        //! [pop_back]

        //! [back_pop_back]
        auto last = vInt.back();
        vInt.pop_back();
        //! [back_pop_back]
    
    }

    {
        //! [insert]
        std::vector<double> vd {1.0, 2.0, 3.0, 4.0};
        vd.insert( vd.begin()+2, 2.5);
        //! [insert]
    }

    {
        //! [resize]
        std::vector<int> vInt {1,2,3,4,5};
        vInt.resize(10);
        for( auto x: vInt){
            std::cout << x << ",";
        }
        //! [resize]

    }
    std::cout << std::endl;
    {
        //! [resize2]
        std::vector<int> vInt {1,2,3,4,5};
        vInt.resize(3);
        for( auto x: vInt){
            std::cout << x << ",";
        }
        //! [resize2]

    }
    std::cout << std::endl;
    {
        //! [part1]
        std::vector<int> vInt;
        //! [part1]

        //! [part2]
        vInt.push_back(1);
        vInt.push_back(2);
        vInt.push_back(3);
        auto size = vInt.size();         // 3
        auto capacity = vInt.capacity(); // 4
        //! [part2]
        std::cout << "capa = " << capacity << std::endl;
        //! [part3]
        vInt.push_back(4);
        vInt.push_back(5);
        size = vInt.size();           // 5
        capacity = vInt.capacity();   // 8
        //! [part3]
        std::cout << "capa = " << capacity << std::endl;

    }


    return EXIT_SUCCESS;
}