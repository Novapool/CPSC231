/***********************************
 * Node class declaration
 * DO NOT CHANGE
 ***********************************/

class node
{ public:
    node(int arg);             // Constructor
    ~node();                   // Destructor
    void insert(int);          // Recursive insert
    void put(ostream &out);    // Output
    void lmr(ostream &out);    // In-order
    void mlr(ostream &out);    // Pre-order
    void rml(ostream &out);    // Post-order
  private:
    int sum();                 // Sum of subtree
    int data;                  // Stored value
    node *left,*right;         // Pointers to children
};

