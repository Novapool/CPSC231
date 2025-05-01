/*********************************
 * Node class declaration 
 *********************************/
#define ERR -1

class node
{ friend class hash_table;
  public:
    node();                  // Constructor
    bool get(istream &in);   // Get data
    void put(ostream &out);  // Put data
  private:
    int id;                  // ID number
    string first,last;       // First and Last names
    bool flag;               // Valid flag
};
