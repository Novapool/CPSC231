// Queue class definition

class node;

class Queue
{ public:
    Queue();                // Constructor
    ~Queue();               // Destructor
    void push(string);      // Push
    void pop();             // Pop
    string front();         // Front
    bool empty();           // Empty
  private:
    node *head,*tail;       // Linked list pointers
};

class node
{ friend class Queue;
  public:
    node(string arg);
    ~node();
  private:
    string value;
    node *next;
};
