#include <iostream>
#include <string>


//! [point]
class Point{
    public:
        double x {0.0};
        double y {0.0};
        std::string name {"O"};


        void print(); // La déclaration ici 
};
//! [point]


//! [print_def]
void Point::print(){
    std::cout << this->name << " (" << this->x << ", " << this->y << ")" << std::endl;
}
//! [print_def]



int main(){
    //! [point_decl]
    Point p; 
    p.print();
    //! [point_decl]


    return EXIT_SUCCESS;
}