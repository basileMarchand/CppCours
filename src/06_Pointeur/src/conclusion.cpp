#include <memory>
#include <iostream>


int main(){

    #ifdef ONE

    {

    //! [bad_idea1]
    std::shared_ptr<int> sptr = std::make_unique<int>();
    *sptr = 42;

    int* iptr = sptr.get();

    std::cout << "*iptr = " << *iptr << std::endl;
    std::cout << "sptr.use_count() = " << sptr.use_count() << std::endl;

    delete iptr;
    //! [bad_idea1]

    }

    #else 

    {
    //! [bad_idea2]
    int* iptr = new int;
    *iptr = 42;

    {
        std::shared_ptr<int> sptr(iptr);
        std::cout << "sptr.use_count() = " << sptr.use_count() << std::endl;
    }

    delete iptr;
    //! [bad_idea2]
    }


    #endif


    return EXIT_SUCCESS;
}