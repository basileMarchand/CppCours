#include <iostream>

//! [point]
class Point{
    public:
    Point() = default;
    Point(Point&) = default; 
    Point(const double& x, const double& y, const std::string& name);

    ~Point();

    protected:
        double x_; 
        double y_; 
        std::string name_;
};

Point::Point(const double& x, const double& y, const std::string& name): x_(x), y_(y), name_(name) {}

Point::~Point(){
    std::cout << "Dans le destructeur de Point" << std::endl;
}
//! [point]

//! [usage]
int main(){

    std::cout << "start new scope" << std::endl;
    {
    Point pa(10,20,"pA");

    }
    std::cout << "stop new scope" << std::endl;

    return EXIT_SUCCESS;
}
//! [usage]