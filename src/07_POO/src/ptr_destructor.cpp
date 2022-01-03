#include <iostream>
#include <memory>

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

//! [example]
class Jedi{
    public:
        Jedi(const std::string& color){
            std::cout << "Jedi with light saber " << color << " constructor " << std::endl;
            this->weapon_ = std::make_unique<LightSaber>(color);
        }

        ~Jedi(){
            std::cout << "Jedi destructor" << std::endl;
        }

    protected:
        std::unique_ptr<LightSaber> weapon_ {nullptr};
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