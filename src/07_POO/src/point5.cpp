#include <iostream>
#include <string>


//! [point]
class Point{
    public:
        double x;
        double y;
        std::string name;


        void print(); // La déclaration ici 
};
//! [point]


//! [print_def]
void Point::print(){
    std::cout << this->name << " (" << this->x << ", " << this->y << ")" << std::endl;
}
//! [print_def]



int main(){

    //! [point_A]
    Point pA; 
    pA.name = "A";
    pA.x = 10.;
    pA.y = 5.;
    pA.print();
    //! [point_A]



    //! [point_B]
    Point pB {10., 5., "B"}; 
    pB.print();
    //! [point_B]


    //! [point_C]
    Point pC; 
    pC.print();
    //! [point_C]


    return EXIT_SUCCESS;
}