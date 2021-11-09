#include <iostream>
#include <vector>

int main(){
    {
    //! [old_loop]
    std::vector<int> v {1,2,3,4,5};
    for(int i=0; i<v.size(); i++){
        int x = v[i];
    }
    //! [old_loop]
    }

    {
    //! [new_loop]
    std::vector<int> v {1,2,3,4,5};
    for(int x: v){
        
    }
    //! [new_loop]
    }

    {
    //! [iter]
    std::vector<int> v {1,2,3,4,5};
    std::vector<int>::iterator it;
    for(it=v.begin(); it!=v.end(); it++){
        int x = *it;
    }
    //! [iter]
    }

    {
    //! [iter_modif]
    std::vector<int> v {1,2,3,4,5};
    std::vector<int>::iterator it;
    for(it=v.begin(); it!=v.end(); it++){
        *it = 42;
    }
    //! [iter_modif]
    }

    {
    //! [iter_const]
    std::vector<int> v {1,2,3,4,5};
    std::vector<int>::const_iterator it;
    for(it=v.cbegin(); it!=v.cend(); it++){
        // *it = 42;   /// Compilation error 
    }
    //! [iter_const]
    }

    return EXIT_SUCCESS;
}