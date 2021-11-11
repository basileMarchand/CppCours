#include <vector>
#include <iostream>
#include <tuple>

//! [ref_arg]
void maFonction( std::vector<int>& values){
    values[0] = 10;
}
//! [ref_arg]

//! [const_ref]
double mean(const std::vector<int>& v){
    double m {0.};
    for( auto& x: v){
        m += x;
    }
    m /= v.size();
    return m;
}
//! [const_ref]

//! [bad_idea]
double& badIdea(){
    double value {0.};

    return value;
}
//! [bad_idea]

//! [out11]
std::tuple<std::vector<double>, int> threshold(const std::vector<double>& v, const double& yield){
    int nbRemoved {0};
    std::vector<double> res;
    res.reserve(v.size());
    for( auto x: v){
        if( x < yield){
            res.push_back( x );
        }
        else{
            nbRemoved += 1;
        }
    }
    res.shrink_to_fit();
    return {res, nbRemoved};
}
//! [out11]

//! [in_out]
std::vector<double> threshold(const std::vector<double>& v, const double& yield, int& nbRemoved){
    nbRemoved = 0;
    std::vector<double> res;
    res.reserve(v.size());
    for( auto x: v){
        if( x < yield){
            res.push_back( x );
        }
        else{
            nbRemoved += 1;
        }
    }
    res.shrink_to_fit();
    return res;
}
//! [in_out]


int main(){
//! [ref_arg_call]
std::vector<int> v {1,2,3};
maFonction(v);
for( auto x: v){
    std::cout << x << ", ";
}
//! [ref_arg_call]

//! [in_out_call]
std::vector<double> values {1.0, 2.12, 19.1, 3.14, 17.8};
int nbDelete {0};
auto out = threshold(values, 10.0, nbDelete);
//! [in_out_call]
{
//! [out11_call]
auto out = threshold(values, 10.);
std::vector<double> v_inf_10 = std::get<0>(out);
int nbRemoved = std::get<1>(out);
//! [out11_call]
}

{
//! [out11_call17]
auto [v_inf_10, nbRemoved] = threshold(values, 10.);
//! [out11_call17]
}
    return EXIT_SUCCESS;
}