#include <string>

//! [point]
class Point{
    public:
        Point(const double& a, const double& b, const std::string& pname );

    protected:
        double x; 
        double y; 
        std::string name; 
};
//! [point]

#define _CONSTRUCT_
#ifdef _CONSTRUCT_
//! [construct1]
Point::Point(const double& a, const double& b, const std::string& pname): x(a), y(b), name(pname){
    
}
//! [construct1]
#else
//! [construct2]
Point::Point(const double& a, const double& b, const std::string& name){
    this->x = a;
    this->y = b;
    this->name = pname;
}
//! [construct2]
#endif 




int main(){

    //! [point_inst]
    Point p(10., 20., "A");
    //! [point_inst]
}