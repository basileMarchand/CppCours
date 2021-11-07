#include <iostream>
//! [include_list]
#include <forward_list>
#include <list>
//! [include_list]

//! [include_queue]
#include <queue>
//! [include_queue]

//! [include_stack]
#include <stack>
//! [include_stack]

int main(){
    //! [list_decl]
    std::list<int> myList {1,2,3,4,5};
    //! [list_decl]

    //! [queue_decl]
    std::queue<int> myQueue;
    //! [queue_decl]

    //! [queue_push]
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    //! [queue_push]


    //! [queue_front]
    int x = myQueue.front();
    myQueue.pop();
    //! [queue_front]

    //! [queue_synthesis]
    std::queue<int> q;
    // Fill the queue 
    for( int i=0; i<5; i++){
        q.push(i);
    }
    while( !q.empty()){
        std::cout << q.front() << ", ";
        q.pop();
    }
    //! [queue_synthesis]

    {
    //! [stack_decl]
    std::stack<int> myStack;
    //! [stack_decl]

    //! [stack_push]
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    //! [stack_push]


    //! [stack_top]
    int x = myStack.top();
    myStack.pop();
    //! [stack_top]

    //! [stack_synthesis]
    std::stack<int> s;
    // Fill the queue 
    for( int i=0; i<5; i++){
        s.push(i);
    }
    while( !s.empty()){
        std::cout << s.top() << ", ";
        s.pop();
    }
    //! [stack_synthesis]
    }
}