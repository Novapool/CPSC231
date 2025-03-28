/************************************
 * Set class definition
 * Written by Mark M Bowman
 ************************************/

#define SET_MAX 16

template <class item>
class set
{ public:
    set();                        // Constructor
    void put(ostream &out);       // Output
    bool insert(item);            // Append item to array
    set operator +(const set &);  // Add a set
  private:
    int  n;                       // Size
    item data[SET_MAX];           // Data storage
};

