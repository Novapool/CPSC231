/***********************************
 * MiniStack
 * Written by Laith Assaf
 ***********************************/

 template <class item>
 class ministack:public minilist<item>
 { public:
     ministack();                 // Constructor
     ~ministack();                // Destructor
     bool push(item arg);         // Add item at top
     void pop();                  // Remove item from top
     item top();                  // Get item at top
 };
 
 /**********************************
  * Constructor
  **********************************/
 template <class item>
 ministack<item>::ministack()
 { 
 // Initialize stack
 
   // Removed cerr output
 }
 
 /**********************************
  * Destructor
  **********************************/
 template <class item>
 ministack<item>::~ministack()
 { 
 // Clean up stack
 
   // Removed cerr output
 }
 
 /**********************************
  * Push
  **********************************/
 template <class item>
 bool ministack<item>::push(item arg)
 { 
 // Check for overflow
 
   if(minilist<item>::n >= minilist<item>::LIST_MAX)
     { cerr << "Stack Overflow" << endl;
       return false;
     };
 
 // Add to top
 
   minilist<item>::data[minilist<item>::n++] = arg;
 
 // Success
 
   return true;
 }
 
 /**********************************
  * Pop
  **********************************/
 template <class item>
 void ministack<item>::pop()
 { 
 // Check for underflow
 
   if(minilist<item>::n <= 0)
     { cerr << "Stack Underflow" << endl;
       return;
     };
 
 // Remove from top
 
   minilist<item>::n--;
 }
 
 /**********************************
  * Top
  **********************************/
 template <class item>
 item ministack<item>::top()
 { 
 // Check for underflow
 
   if(minilist<item>::n <= 0)
     { cerr << "Stack Underflow" << endl;
       return item();
     };
 
 // Return top value
 
   return minilist<item>::data[minilist<item>::n - 1];
 }