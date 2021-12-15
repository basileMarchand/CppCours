#include <string>

//! [point]
class Point{
    public: 
        Point();
        Point(const double& a, const double& b, const std::string& pname );

        #if false
        //! [bad_idea]
        Point( Point other );
        //! [bad_idea]
        #else
        //! [good_idea]
        Point( const Point& other);
        //! [good_idea]
        #endif


    protected:
        double x; 
        double y; 
        std::string name; 


};
//! [point]

Point::Point(): x(0.), y(0.), name("Origine"){}
Point::Point(const double& a, const double& b, const std::string& pname): x(a), y(b), name(pname){}

//! [copy_constructor]
Point::Point( const Point& other){
    this->x = other.x;
    this->y = other.y;
    this->name = other.name + "copy"; 
}
//! [copy_constructor]





int main(){

    //! [copy]
    Point p1(10,20, "A");
    Point p2(p1);
    //! [copy]

}