#include <iostream>
#include <string>


//! [point]
class Point{
    public:
        double x;
        double y;
        std::string name;


        void print(){
            std::cout << this->name << " (" << this->x << ", " << this->y << ")" << std::endl;
        }
};
//! [point]

int main(){

    //! [point_instance]
    Point p; 
    p.name = "A";
    p.x = 10.;
    p.y = 5.;
    //! [point_instance]

    //! [point_print]
    p.print();
    //! [point_print]

    return EXIT_SUCCESS;
}