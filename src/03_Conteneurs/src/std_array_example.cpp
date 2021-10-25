/// [include]
#include <array> 
/// [include]


int main(){
    // 1. Create array 

    /// [create]
    std::array<double, 10> arr;
    /// [create]

    /// [create_initializer_list]
    std::array<int, 10> arr {1,2,3,4,5,6,7,8,9,10};
    /// [create_initializer_list]

    /// [create_and_fill]
    std::array<double, 4> arrDouble; 
    arrDouble.fill(1.5);
    /// [create_and_fill]

    {
    /// [size]
    std::array<double, 7> arrDouble; 
    auto sz = arrDouble.size(); // sz = 7;
    /// [size]

    }

    {
    /// [front_back]
    std::array<int, 6> arrInt {10,20,30,40,50,60};
    auto first = arrInt.front(); // first = 10
    auto last  = arrInt.back();  // last  = 60 
    /// [front_back]
    }

    {
    /// [swap]
    std::array<int, 4> arr1 {1, 2, 3, 4};
    std::array<int, 4> arr2 {10, 20, 30, 40};
    arr1.swap(arr2);
    /// [swap]
    }

    return EXIT_SUCCESS;
}