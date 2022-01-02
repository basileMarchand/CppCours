#include <iostream>

//! [Point]
class Point{
    public:
    Point() = default;
    Point(Point&) = default; 
    Point(const double& x, const double& y, const std::string& name);

    //! [assignement]
    Point& operator=(const Point& other); 
    //! [assignement]

    //! [equality]
    bool operator==(const Point& other);
    //! [equality]

    //! [comparison]
    bool operator<(const Point& other);
    bool operator>(const Point& other);
    bool operator<=(const Point& other);
    bool operator>=(const Point& other);
    //! [comparison]

    //! [operations]
    bool operator+(const Point& other);
    bool operator-(const Point& other);
    //! [operations]

    //! [access]
    double operator()(const std::size_t i) const ;

    //! [access]

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

//! [assignement_impl]
Point& Point::operator=(const Point& other ){
    this->x_ = other.x_;
    this->y_ = other.y_;
    this->name_ = other.name_;
    return *this;
}
//! [assignement_impl]





int main(){

    Point pa(10,20,"pA");

    Point pb = pa; 
    Point pc;

    pc = pb = pa;


    return EXIT_SUCCESS;
}