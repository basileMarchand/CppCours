#include <iostream>

template<typename Format>
class Logger: public Format{
public: 
    void message( const std::string& msg){
        std::cout << this->prefix() << msg << this->suffix() << std::endl;
    }

};


class Color {
    protected:
        std::string prefix(){
            return "\e[1;31m";
        }

        std::string suffix(){
            return "\e[0m";
        }
};

class Italic {
    protected:
        std::string prefix(){
            return "\e[3m";
        }

        std::string suffix(){
            return "\e[0m";
        }
};

int main(){

    Logger<Color> log_color;
    log_color.message("coucou");

     Logger<Italic> log_italic;
    log_italic.message("coucou");
}