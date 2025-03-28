// City class definition

class city
{ friend class list;
  public:
    city();                    // Constructor
    bool get(istream& in);     // Input name & location
    void put(ostream& out);    // Output data
  private:
    string name;               // Name
    float latitude,longitude;  // Location
};
