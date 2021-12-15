#include <iostream>
#include <string>

//! [point]

class Point{
    public:
        void setValues(const double&, const double&, const std::string&);
        void print();


    protected:
        void print_protected();

        double x {0.0};
        double y {0.0};
        std::string name; 
};


void Point::setValues(const double& a, const double& b, const std::string& pname){
    this->x = a;
    this->y = b;
    this->name = pname;
}

void Point::print(){
    this->print_protected();
}

void Point::print_protected(){
    std::cout << this->name << " (" << this->x << ", " << this->y << ")" << std::endl;
}

//! [point]


int main(){

    //! [point_inst]
    Point p;
    p.setValues(10., 15., "A");
    p.print();

    //! [point_inst]

    return EXIT_SUCCESS;

}