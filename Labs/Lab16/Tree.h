// Tree Declarations

#define TREE_MAX  1024
#define TREE_ERR  -1

class tree
{ public:
    tree();                       // Constructor
    bool insert(string);          // Insert string into tree
    void dump();                  // Dump contents of array
    int  depth();                 // Total depth
    void show(string);            // Display in order
  private:
    int  left(int pos);           // Left child
    int  right(int pos);          // Right child
    int  depth_recurse(int pos);  // Recursive depth function
    void lmr(int pos);            // Recursive LMR display
    string map[TREE_MAX];         // Data array
};
