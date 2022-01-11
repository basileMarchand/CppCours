#include <iostream>
#include <memory>

class LightSaber{
    public:
        LightSaber(const std::string& color): color_{color} {
            std::cout << "LightSaber " << color << " constructor" << std::endl;
        }
    protected:
        std::string color_ {"blue"};
};

//! [jedi]
class Jedi{
    public:
        Jedi(const std::string& color){
            this->weapon_ = std::make_unique<LightSaber>(color);
        }

    protected:
        std::unique_ptr<LightSaber> weapon_ {nullptr};
};
//! [jedi]

//! [padawan]
class Padawan: public Jedi {
};
//! [padawan]

//! [knight]
class Knight: public Jedi {
    public:
        Knight(const std::string& color): Jedi(color){}
};
//! [knight]


//! [master]
class Master: public Jedi {
    public:
        Master(const std::string& color): Jedi(color){}
};
//! [master]




//! [usage]
int main(){

    {
        Jedi obiwan("blue");
        Jedi yoda("green");
    }
    return EXIT_SUCCESS;
}
//! [usage]