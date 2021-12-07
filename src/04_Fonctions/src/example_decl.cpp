
//! [computeArea]
double computeArea(const double& x, const double& y){
    return x*y ;
}
//! [computeArea]


int main(){

//! [main]
    double x, y; 
    x = 1.10;
    y = 1.20;

    decltype(computeArea(x,y)) a;
//! [main]


//! [main2]
using Area_t = decltype(computeArea(x,y));
Area_t b = computeArea(x,y);
//! [main2]


}