/// [string_include]
#include <string>
/// [string_include]

int main(){

    /// [char]
    char une_lettre = 'a';
    /// [char]

    /// [string]
    std::string une_chaine = "coucou tout le monde";
    /// [string]

    /// [string_sum]
    std::string debut = "Hello tout le monde";
    std::string fin = "vous allez bien ?";

    std::string phrase1 = debut + ", " + fin; // Hello tout le monde, vous allez bien ? 
    /// [string_sum]

    /// [selection]

    std::string phrase2 = "Hello tout le monde";
    bool start = phrase2.starts_with("Hel"); // start = true;
    bool end = phrase2.ends_with("!");       // end = false;
    
    /// [selection]


    return EXIT_SUCCESS;
}