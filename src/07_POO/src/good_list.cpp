#include <memory>
#include <iostream>

#define imp5

#ifdef imp1
//! [node]
class Node{
    public:
        Node(const int& x): value_{x}, next_{nullptr} {}


    protected:
        int value_;
        std::unique_ptr<Node> next_;
};

//! [node]
#endif
#ifdef imp2 

//! [node2]
class Node{
    public:
        Node(const int& x): value_{x}, next_{nullptr} {}
    
    void append( const int& x){
        this->next_ = std::make_unique<Node>(x);
    }

    protected:
        int value_;
        std::unique_ptr<Node> next_;
};
//! [node2]
#endif
#ifdef imp3

//! [node3]
class Node{
    public:
        Node(const int& x): value_{x}, next_{nullptr} {}
    
        void append( const int& x){
            if( this->next_ == nullptr ){
                this->next_ = std::make_unique<Node>(x);
            }
            else{
                this->next_->append(x);
            }
        }

    protected:
        int value_;
        std::unique_ptr<Node> next_;
};
//! [node3]

#endif

#ifdef imp4

//! [node4]
class Node{
    public:
        Node(const int& x): value_{x}, next_{nullptr} {}
    
        void append( const int& x){
            if( this->next_ == nullptr ){
                this->next_ = std::make_unique<Node>(x);
            }
            else{
                this->next_->append(x);
            }
        }

        void print() const {
            std::cout << this->value_ << ", "; 
            if( this->next_){
                this->next_->print();
            }
        }

    protected:
        int value_;
        std::unique_ptr<Node> next_;
};
//! [node4]

#endif


int main(){
    {
    //! [usage1]
    Node list(1);
    list.append(2);
    list.append(3);
    //! [usage1]
    }

    {
    //! [usage2]
    Node list(1);
    list.append(2);
    list.append(3);
    list.print();
    //! [usage2]
    }



}