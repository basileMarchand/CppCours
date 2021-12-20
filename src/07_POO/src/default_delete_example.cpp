#include <iostream>
#include <string>


#define DELETE
#ifdef DEFAULT
//! [default]
class Point{
    public:
        Point() = default; 
        Point(const Point& ) = default; 
        Point(const double& a, const double& b, std::string& name);

    protected:
        double x_ {0.};
        double y_ {0.};
        std::string name_ {"O"};
};
//! [default]
#endif 


#ifdef DELETE
//! [delete]
class Point{
    public:
        Point() = default; 
        Point(const Point& ) = delete; 

    protected:
        double x_ {0.};
        double y_ {0.};
        std::string name_ {"O"};
};
//! [delete]
#endif

int main(){

    return EXIT_SUCCESS;
}