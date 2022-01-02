#include <memory>
#include <iostream>


//! [func]
void do_something(std::shared_ptr<int> ptr){
    std::cout << "in do_something, ptr.use_count() = " << ptr.use_count() << std::endl;
}
//! [func]

int main(){

    {
    //! [decl]
    std::shared_ptr<int> ptr;
    //! [decl]
    }
    
    {
    //! [make_shared]
    auto ptr = std::make_shared<int>();
    //! [make_shared]


    //! [count1]
    std::cout << ptr.use_count() << std::endl;
    // affiche 1 
    //! [count1]

    //! [assignement]
    auto ptr2 = ptr;
    //! [assignement]

    //! [count2]
    std::cout << "ptr.use_count() = " << ptr.use_count() << std::endl;
    std::cout << "ptr2.use_count() = " << ptr2.use_count() << std::endl;
    //! [count2]


    //! [call_func]
    do_something(ptr);
    //! [call_func]


    std::cout << ptr.use_count() << std::endl;
    std::cout << ptr2.use_count() << std::endl;
    }


}