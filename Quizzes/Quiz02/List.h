/************************************
 * List class definition
 * Written by Mark M Bowman
 ************************************/

#define ARRAY_MAX 16

class list
{ public:
    list();                      // Constructor
    ~list();                     // Destructor
    void display(ostream &out);  // Output
    void insert(string arg);     // Append to array
    int  remove(string arg);     // Remove from array
  private:
    int len;                     // # of elements
    string *data;                // Data storage
};
