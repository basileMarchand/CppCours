#include <iostream>
#include <limits>
#include <cmath>

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
    bool operator==(const Point& other) const;
    //! [equality]

    //! [comparison]
    bool operator<(const Point& other) const;
    bool operator>(const Point& other) const;
    bool operator<=(const Point& other) const;
    bool operator>=(const Point& other) const;
    //! [comparison]

    //! [operations]
    Point operator+(const Point& other);
    Point operator-(const Point& other);
    //! [operations]

    //! [access]
    std::string operator()() const;
    double operator()(const std::size_t i) const ;
    double& operator()(const std::size_t i);

    double operator[](const std::string& item) const;
    double& operator[](const std::string& item);
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

//! [equality_impl]
bool Point::operator==(const Point& other) const {
    bool test_x = std::fabs(this->x_ - other.x_) < std::numeric_limits<double>::epsilon();
    bool test_y = std::fabs(this->y_ - other.y_) < std::numeric_limits<double>::epsilon();
    return test_x && test_y; 
}
//! [equality_impl]

//! [comparison_impl]
bool Point::operator<(const Point& other) const {
    bool test_x = this->x_ < other.x_;
    bool test_y = this->y_ < other.y_;
    return test_x && test_y;
}

bool Point::operator>(const Point& other) const {
    return other < *this ;
}

bool Point::operator<=(const Point& other) const {
    bool test_x = this->x_ <= other.x_;
    bool test_y = this->y_ <= other.y_;
    return test_x && test_y;
}

bool Point::operator>=(const Point& other) const {
    return other <= *this ;
}

//! [comparison_impl]

//! [operations_impl]
Point Point::operator+(const Point& other){
    Point ret(*this);
    ret.x_ += other.x_;
    ret.y_ += other.y_;
    ret.name_ += "+" + other.name_;
    return ret;
}

Point Point::operator-(const Point& other){
    Point ret(*this);
    ret.x_ -= other.x_;
    ret.y_ -= other.y_;
    ret.name_ += "-" + other.name_;
    return ret;
}
//! [operations_impl]


//! [access_impl]
std::string Point::operator()() const {
    return this->name_;
}

double Point::operator()(const std::size_t i) const {
    if( i == 0){
        return this->x_;
    }
    else if (i==1){
        return this->y_;
    }
    else{
        // error 
    }
}

double& Point::operator()(const std::size_t i){
    if( i == 0){
        return this->x_;
    }
    else if (i==1){
        return this->y_;
    }
    else{
        // error 
    }
}

double Point::operator[](const std::string& item) const {
    if( item == "x"){
        return this->x_;
    }
    else if (item == "y"){
        return this->y_;
    }
    else{
        // Error - throw an exception 
    }    
}

double& Point::operator[](const std::string& item) {
    if( item == "x"){
        return this->x_;
    }
    else if (item == "y"){
        return this->y_;
    }
    else{
        // Error - throw an exception 
    }    
}
//! [access_impl]


int main(){

    Point pa(10,20,"pA");

    Point pb = pa; 
    Point pc;

    pc = pb = pa;


    return EXIT_SUCCESS;
}