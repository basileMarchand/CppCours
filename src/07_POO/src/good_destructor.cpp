#include <iostream>


//! [example]
class LightSaber{
    public:
        LightSaber() = default;
        LightSaber(const std::string& color): color_{color} {
            std::cout << "LightSaber " << color << " constructor" << std::endl;
        }
        ~LightSaber(){
            std::cout << "LightSaber " << this->color_ << " destructor" << std::endl;
        }
    protected:
        std::string color_ {"blue"};
};

class Jedi{
    public:
        Jedi(const std::string& color){
            std::cout << "Jedi with light saber " << color << " constructor " << std::endl;
            this->weapon_ = new LightSaber(color);
        }

        ~Jedi(){
            std::cout << "Jedi destructor" << std::endl;
            if( this->weapon_ != nullptr){
                delete this->weapon_;
            }
        }

    protected:
        LightSaber* weapon_ {nullptr};
};
//! [example]

//! [usage]
int main(){

    {
        Jedi obiwan("blue");
        Jedi yoda("green");
    }
    return EXIT_SUCCESS;
}
//! [usage]