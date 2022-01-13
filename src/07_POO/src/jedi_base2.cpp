#include <iostream>
#include <memory>

class LightSaber{
    public:
        LightSaber(const std::string& color): color_{color} {
        }
        std::string color() const {
            return this->color_;
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

        void info() const {
            std::cout << "I am a Jedi with a " << this->weapon_->color() << " light saber" << std::endl;
        }

    protected:
        std::unique_ptr<LightSaber> weapon_ {nullptr};
};
//! [jedi]

//! [padawan]
class Padawan: public Jedi {
    public:
        Padawan(const std::string& color): Jedi(color){} 
        void info() const {
            std::cout << "I am a Padawan with a " << this->weapon_->color() << " light saber" << std::endl;
        }
};
//! [padawan]

//! [knight]
class Knight: public Jedi {
    public:
        Knight(const std::string& color): Jedi(color){}
        void info() const {
            std::cout << "I am a Jedi Knight with a " << this->weapon_->color() << " light saber" << std::endl;
        }
};
//! [knight]


//! [master]
class Master: public Jedi {
    public:
        Master(const std::string& color): Jedi(color){}
        void info() const {
            std::cout << "I am a Jedi Master with a " << this->weapon_->color() << " light saber" << std::endl;
        }
};
//! [master]




//! [usage]
int main(){

    {
        Padawan anakin("blue");
        anakin.info();
        Knight obiwan("blue");
        obiwan.info();
        Master yoda("green");
        yoda.info();
    }
    return EXIT_SUCCESS;
}
//! [usage]