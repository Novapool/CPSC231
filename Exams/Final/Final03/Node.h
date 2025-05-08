/*********************************
 * Node.h
 * DO NOT CHANGE
 *********************************/

class node
{ public:
    node(string arg="");     // Constructor
    ~node();                 // Destructor
    void append(node *);     // Append
    void output(ostream &);  // Output
    node * copy();           // Copy
    string data;             // Data
    node *next;              // Next
};

typedef node * node_ptr;
