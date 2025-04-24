/************************************
 * Node.h
 * Written by Mark M Bowman
 ************************************/

// Node Declarations

#define ERR       -1
#define NODE_MAX  20
#define EDGE_MAX  4

// Node class

class node
{ public:
    node();                  // Constructor
    void set_value(string);  // Set string value
    string get_value();      // Return string value
    void connect(node *);    // Connect this node to another
    void put(ostream &);     // Output node and neighbors
  private:
    string value;            // Node value
    node *edge[EDGE_MAX];    // Edges array
};
