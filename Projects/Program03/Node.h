/***********************************
 * Node Class Declaration
 * Written by Laith Assaf
 ***********************************/

class node
{
private:
    int id;             // Unique identifier for the node
    string firstName;   // First name of the person
    string lastName;    // Last name of the person
    int age;            // Age of the person
    double gpa;         // GPA of the person
    node* next;         // Pointer to the next node in the list

public:
    // Constructor with default values
    // Initializes a node with the given parameters
    node(int newId = 0, const string& newFirstName = "", 
        const string& newLastName = "", int newAge = 0, 
        double newGpa = 0.0, node* newNext = nullptr);

    // Destructor
    // Deletes the next node (which cascades to delete all following nodes)
    ~node();

    // Put function
    // Outputs the id, last name, first name, and age to the given output stream
    void put(ostream& out) const;

    // Fore function
    // Outputs the current node and all following nodes to the given output stream
    void fore(ostream& out) const;

    // Back function
    // Outputs all following nodes and then the current node to the given output stream
    void back(ostream& out) const;

    // Overloaded equality operator
    // Compares the node's id with the given integer
    // Returns true if they match, false otherwise
    bool operator==(int compareId) const;

    // Overloaded greater than operator
    // Compares the node with another node using name and age
    // Returns true if this node is greater than the other node, false otherwise
    bool operator>(const node& other) const;

    // Overloaded less than operator
    // Compares the node with another node using name and age
    // Returns true if this node is less than the other node, false otherwise
    bool operator<(const node& other) const;

    // Friend declaration for the list class to access private members
    friend class list;
};
