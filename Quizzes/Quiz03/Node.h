/************************************
 * Node.h
 ************************************/

// Node class

class node
{ public:
    node(string arg="");          // Constructor
    ~node();                      // Destructor 
    void insert(string);          // Insert into tree
    void lmr();                   // Display LMR order
    void path(string);            // Display path to node
  private:
    string val;                   // Stored value
    node *left,*right;            // Node pointers
};

