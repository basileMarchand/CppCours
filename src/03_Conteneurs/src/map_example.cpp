//! [include]
#include <map>
#include <unordered_map>
//! [include]

#include <iostream>
#include <string>

int main(){


    {
    //! [decl]
    std::map<std::string, int> age; 
    //! [decl]
    }

    {
    //! [initializer_list]
    std::map<std::string, int> age { {"jean", 30}, 
                                   {"michel", 36} };
    //! [initializer_list]
    }

    {
    //! [access_read]
    std::map<std::string, int> age { {"jean", 30}, 
                                   {"michel", 36} };
    int ageJean = age["jean"];
    //! [access_read]

    //! [access_read_no_check]  
    int ageMichelle = age["michelle"]; // ageMichelle = 0 
    //! [access_read_no_check]
    std::cout << "ageMichelle " << ageMichelle << std::endl;

    //! [access_read_check]
    try{
        int ageMichelleAgain = age.at("Michel"); 
    }
    catch( std::out_of_range e){
        std::cerr << "key Michel doesn't exists" << std::endl;
    }
    //! [access_read_check]
    }

    {
    //! [find]
    std::map<std::string, int> age { {"jean", 30}, 
                                   {"michel", 36} };

    bool exists = age.find("jean") != age.end();     
    //! [find]
    }
    {
    std::map<std::string, int> age { {"jean", 30}, 
                                   {"michel", 36} };
    //! [contains]
    bool exists = age.contains("jean");
    //! [contains]
    }

    {
    //! [add]
    std::map<std::string, int> age { {"jean", 30}, 
                                   {"michel", 36} };
    
    age["basile"] = 30;
    //! [add]

    //! [overwrite]
    age["basile"] = 31;
    //! [overwrite]

    //! [insert]
    auto out = age.insert({"basile", 30}); // do nothing 
    //! [insert]

    //! [insert_details]
    if( out.second ){
        std::cout << "value inserted" << std::endl;
    }
    else{
        std::cout << "value already exists, nothing done" << std::endl;
    }
    //! [insert_details]
    std::cout << std::boolalpha << out.second << std::endl;

    //! [insert_or_assign]
    auto ret = age.insert_or_assign("basile", 30);
    if( ret.second ){
        std::cout << "Valeur insérée" << std::endl; 
    }
    else{
        std::cout << "Valeur assignée" << std::endl;
    }
    //! [insert_or_assign]
    }
    {
    //! [loop_auto]
    std::map<std::string, int> ages {{"jean", 30}, {"michel", 42}};
    for( auto p: ages){
        // p is ??? 
    }
    //! [loop_auto]

    //! [loop_auto_details]
    for( auto p: ages){
        std::cout << p.first << " est agé de " << p.second << " ans" << std::endl;
    }
    //! [loop_auto_details]

    //! [loop_auto_17]
    for( auto [name, age]: ages){
        std::cout << name << " est agé de " << age << " ans" << std::endl;
    }
    //! [loop_auto_17]

    }
}