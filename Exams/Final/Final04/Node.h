/************************************
 * Node.h
 ************************************/

// Node class

class node
{ public:
    node(string arg="");           // Constructor
    ~node();                       // Destructor 
    void insert(node *);           // Insert into tree
    void mlr();                    // Display LMR order
    void path(string);             // Display path to node
    int dump(string map[],int n);  // Add this node and children to array
    int count();                   // Count of subtree
    int depth();                   // Depth of subtree
  private:
    string val;                    // Stored value
    node *left,*right;             // Node pointers
};