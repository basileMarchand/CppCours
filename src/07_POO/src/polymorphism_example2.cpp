#include <iostream>
#include <memory>

//! [classes]
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

class Jedi{
    public:
        Jedi(const std::string& color){
            this->weapon_ = std::make_unique<LightSaber>(color);
        }

        virtual void info() const {
            std::cout << "I am a Jedi with a " << this->weapon_->color() << " light saber" << std::endl;
        }

    protected:
        std::unique_ptr<LightSaber> weapon_ {nullptr};
};

class Padawan: public Jedi {
    public:
        Padawan(const std::string& color): Jedi(color){} 
        virtual void info() const {
            std::cout << "I am a Padawan with a " << this->weapon_->color() << " light saber" << std::endl;
        }
};

class Knight: public Jedi {
    public:
        Knight(const std::string& color): Jedi(color){}
        virtual void info() const {
            std::cout << "I am a Jedi Knight with a " << this->weapon_->color() << " light saber" << std::endl;
        }
};

class Master: public Jedi {
    public:
        Master(const std::string& color): Jedi(color){}
        virtual void info() const {
            std::cout << "I am a Jedi Master with a " << this->weapon_->color() << " light saber" << std::endl;
        }
};
//! [classes]

//! [call_info]
void callInfo( Jedi& j){
    std::cout << "In callInfo: ";
    j.info();
}
//! [call_info]


int main(){

{
//! [usage]
Padawan anakin("blue");
anakin.info();
callInfo(anakin);
Knight obiwan("blue");
obiwan.info();
callInfo(obiwan);
Master yoda("green");
yoda.info();
callInfo(yoda);
//! [usage]
}

{
//! [reference]
Padawan anakin("blue");
anakin.info();
Jedi& ref = anakin;
ref.info();
//! [reference]
}
    return EXIT_SUCCESS;
}
