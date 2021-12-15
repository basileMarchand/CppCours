#include <string>


//! [point]
class Point{
    public:
        double x;
        double y;
        std::string name;
};
//! [point]

int main(){

    //! [point_instance]
    Point p; 
    p.name = "A";
    p.x = 10.;
    p.y = 5.;
    //! [point_instance]

    return EXIT_SUCCESS;
}