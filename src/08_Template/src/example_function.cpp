#include <vector>
#include <iostream>

//! [print]
template<typename T>
void printVector( const std::vector<T>& v){
    for( const T& x: v){
        std::cout << x << ", "; 
    }
    std::cout << std::endl; 
}
//! [print]

#if false
//! [type_info]
template<typename T>
std::string myType(){ return ""; }
//! [type_info]

//! [type_info_spec]
template<>
std::string myType<int>(){ return "int"; }
template<>
std::string myType<double>(){ return "double"; }
//! [type_info_spec]

#else 
//! [myType_cpp17]
template<typename T>
std::string myType(){
    if constexpr( std::is_same_v<T, int>){
        return "int";
    }
    else if constexpr(std::is_same_v<T, double>){
        return "double";
    }
    else{
        return "";
    }
}
//! [myType_cpp17]

#endif

//! [printVecType]
template<typename T>
void printVectorWithType( const std::vector<T>& v){
    std::cout << "std::vector<" << myType<T>() << ">: ";
    for( const T& x: v){
        std::cout << x << ", "; 
    }
    std::cout << std::endl; 
}
//! [printVecType]






//! [print_vecvec]
template<typename T, template <typename, typename> class Container>
void printVector(const std::vector<Container<T, std::allocator<T>>>& v){
    for( auto& x: v){
        for( const T& y: x){
            std::cout << y << ", ";
        }
        std::cout << std::endl;
    }
}

//! [print_vecvec]

int main(){
    {
    //! [usage_cpp]
    std::vector<int> v {1,2,3,4,5};
    printVector<int>(v);
    //! [usage_cpp]
    }
    {
    //! [usage_cpp1X]
    std::vector<int> v {1,2,3,4,5};
    printVector(v);
    //! [usage_cpp1X]
    }

    {
    //! [usage_type]
    std::vector<int> v {1,2,3,4,5};
    printVectorWithType(v);
    //! [usage_type]
    }

    {
    //! [usage_vecvec]
    std::vector<std::vector<int> > v { {1,2,3}, {4,5,6}, {7,8,9}};
    printVector(v);
    //! [usage_vecvec]
    }
}