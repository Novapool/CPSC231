// Box class definition

class box
{ public:
    box();                      // Constructor - null
    box(int,int,int);           // Constructor - parameters
    ~box();                     // Destructor
    bool get(istream &in);      // Input dimensions
    void put(ostream &out);     // Output dimensions
    int volume();               // Calculate volume
    int surface();              // Calculate surface area
  private:
    int height,width,depth;     // Dimensions
};
