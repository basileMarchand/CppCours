
//! [node]
class Node{
    Node(const int& value);
    void append(const int& x);

    protected:
        int value_;
        Node next_;
};
//! [node]
