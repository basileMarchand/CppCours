#include <iostream>

#define CONST  
#ifndef CONST 
//! [print_no_const]
class Point{
    public:
    Point() = default;
    Point(Point&) = default; 
    Point(const double& x, const double& y, const std::string& name);
    void print();

    protected:
        double x_; 
        double y_; 
        std::string name_;
};

Point::Point(const double& x, const double& y, const std::string& name): x_(x), y_(y), name_(name) {}

void Point::print(){
    std::cout << this->name_ << ": (" << this->x_ << ", " << this->y_ << ")" << std::endl;
}
//! [print_no_const]
#else
//! [print_const]
class Point{
    public:
    Point() = default;
    Point(Point&) = default; 
    Point(const double& x, const double& y, const std::string& name);
    void print() const ;

    protected:
        double x_; 
        double y_; 
        std::string name_;
};

Point::Point(const double& x, const double& y, const std::string& name): x_(x), y_(y), name_(name) {}

void Point::print() const {
    std::cout << this->name_ << ": (" << this->x_ << ", " << this->y_ << ")" << std::endl;
}
//! [print_const]





#endif

//! [const_arg]
void callPointPrint(const Point& p){
    p.print();
}
//! [const_arg]

int main(){

    Point pa(10,20,"pA");
    callPointPrint(pa);

    return EXIT_SUCCESS;
}