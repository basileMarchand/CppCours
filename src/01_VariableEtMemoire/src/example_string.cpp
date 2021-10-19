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

    std::string phrase = debut + ", " + fin; // Hello tout le monde, vous allez bien ? 
    /// [string_sum]

    /// [selection]

    std::string phrase = "Hello tout le monde";
    bool start = phrase.starts_with("Hel"); // start = true;
    bool end = phrase.ends_with("!");       // end = false;
    /// [selection]


    return EXIT_SUCCESS;
}