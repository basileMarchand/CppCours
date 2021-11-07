//! [include]
#include <tuple>
//! [include]

#include <iostream>

int main(){
    {
    //! [declaration]
    std::tuple<int, double, bool> tup {1,42.0,false};
    //! [declaration]
    }
    {
    //! [declaration2]
    auto tup = std::make_tuple(1, 42.0, false);
    //! [declaration2]
    }

    {
    //! [get_idx]
    auto tup = std::make_tuple(1, 42.0, false);
    int valInt;
    valInt = std::get<0>(tup);
    //! [get_idx]

    //! [get_type]
    valInt = std::get<int>(tup);
    //! [get_type]
    } 

    {
    //! [tie]
    auto tup = std::make_tuple(1, 42.0, false);
    int eleInt;
    double eleDouble;
    bool eleBool;
    std::tie(eleInt, eleDouble, eleBool) = tup;
    //! [tie]

    //! [tie_ignore]
    std::tie(eleInt, std::ignore, eleBool) = tup;
    //! [tie_ignore]
    }

    {
    //! [unpack]
    auto tup = std::make_tuple(1, 42.0, false);
    auto [e1, e2, e3] = tup;
    //! [unpack]

    //! [unpack_ignore]
    auto [e1, std::ignore, e2] = tup;
    //! [unpack_ignore]


    }




    return EXIT_SUCCESS;
}