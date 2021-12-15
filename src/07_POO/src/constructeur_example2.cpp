#include <string>

//! [point]
class Point{
    public: 
        Point();
        Point(const std::string& name);
        Point(const double& a, const std::string& pname );
        Point(const double& a, const double& b, const std::string& pname );

    protected:
        double x; 
        double y; 
        std::string name; 


};
//! [point]

//! [construct]
Point::Point(): x(0.), y(0.), name("Origine"){}
Point::Point(const std::string& pname): x(0.), y(0.), name(pname){}
Point::Point(const double& a, const std::string& pname): x(a), y(a), name(pname){}
Point::Point(const double& a, const double& b, const std::string& pname): x(a), y(b), name(pname){}
//! [construct]


int main(){

    //! [point_inst]
    Point p0;
    Point p1("test");
    Point p2(10., "B");
    Point p3(10., 20., "C");
    //! [point_inst]
}