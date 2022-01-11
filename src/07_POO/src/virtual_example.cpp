#include <iostream>
#include <memory>

class LightSaber{
    public:
        LightSaber(const std::string& color): color_{color} {}

        const std::string color() const {
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

        void info(){
            std::cout << "I am a Jedi with a " << this->weapon_->color() << " lightsaber" << std::endl;
        }

    protected:
        std::unique_ptr<LightSaber> weapon_ {nullptr};
};
//! [jedi]

class Padawan: public Jedi{
    public: 
        Padawan(const std::string& color): Jedi(color){}

        void info(){
            std::cout << "I am a Padawan with a " << this->weapon_->color() << " lightsaber" << std::endl;
        }

};

void printJediInfo( Jedi& j){
    j.info();
}

int main(){
    
    {
    Jedi anakin("blue");
    Padawan ashoka("blue");

    anakin.info();
    ashoka.info();

    printJediInfo(anakin);
    printJediInfo(ashoka);

    }

    {
    auto anakin = std::make_shared<Jedi>("blue");
    auto ashoka = std::make_shared<Padawan>("blue");

    anakin->info();
    ashoka->info();
    }

    return EXIT_SUCCESS;
}