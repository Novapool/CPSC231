/************************************
 * Node.h
 ************************************/

// Node class

class node
{ friend node * build_tree();
  public:
    node(int arg=0);        // Constructor
    ~node();                // Destructor 
    void lmr();             // Display LMR order
    void leaves();          // Display leaves  
    void leaves(int);       // Display leaves and depth 
  private:
    int val;                // Stored value
    node *left,*right;      // Node pointers
};
