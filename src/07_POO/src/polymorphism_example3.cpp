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

//! [jedi]
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
//! [jedi]

#if false
//! [padawan]
class Padawan: public Jedi {
    public:
        Padawan(const std::string& color): Jedi(color){} 
        virtual void info() {
            std::cout << "I am a Padawan with a " << this->weapon_->color() << " light saber" << std::endl;
        }
};
//! [padawan]

#elif false
//! [padawan2]
class Padawan: public Jedi {
    public:
        Padawan(const std::string& color): Jedi(color){} 
        virtual void info() override {
            std::cout << "I am a Padawan with a " << this->weapon_->color() << " light saber" << std::endl;
        }
};
//! [padawan2]
#else
//! [padawan3]
class Padawan: public Jedi {
    public:
        Padawan(const std::string& color): Jedi(color){} 
        virtual void info() const override {
            std::cout << "I am a Padawan with a " << this->weapon_->color() << " light saber" << std::endl;
        }
};
//! [padawan3]
#endif

//! [knight]
class Knight: public Jedi {
    public:
        Knight(const std::string& color): Jedi(color){}
        virtual void info() const override final {
            std::cout << "I am a Jedi Knight with a " << this->weapon_->color() << " light saber" << std::endl;
        }
};
//! [knight]

//! [knight_at_council]
class KnightAtJediCouncil: public Knight{
    public: 
        KnightAtJediCouncil(const std::string& color): Knight(color){}
        virtual void info() const {
            std::cout << "I am a Jedi Knight with a " << this->weapon_->color() << " light saber" << std::endl;
        }
};
//! [knight_at_council]


class Master: public Jedi {
    public:
        Master(const std::string& color): Jedi(color){}
        virtual void info() const {
            std::cout << "I am a Jedi Master with a " << this->weapon_->color() << " light saber" << std::endl;
        }
};
//! [classes]

int main(){

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
