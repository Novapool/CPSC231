/***********************************
 * MiniQueue
 * Written by Laith Assaf
 ***********************************/

 template <class item>
 class miniqueue:public minilist<item>
 { public:
     miniqueue();                 // Constructor
     ~miniqueue();                // Destructor
     bool push(item arg);         // Add item at end
     void pop();                  // Remove item from front
     item front();                // Get item at front
 };
 
 /**********************************
  * Constructor
  **********************************/
 template <class item>
 miniqueue<item>::miniqueue()
 { 
 // Initialize queue
 
   // Removed cerr output
 }
 
 /**********************************
  * Destructor
  **********************************/
 template <class item>
 miniqueue<item>::~miniqueue()
 { 
 // Clean up queue
 
   // Removed cerr output
 }
 
 /**********************************
  * Push
  **********************************/
 template <class item>
 bool miniqueue<item>::push(item arg)
 { 
 // Check for overflow
 
   if(minilist<item>::n >= minilist<item>::LIST_MAX)
     { cerr << "Queue Overflow" << endl;
       return false;
     };
 
 // Add to end
 
   minilist<item>::data[minilist<item>::n++] = arg;
 
 // Success
 
   return true;
 }
 
 /**********************************
  * Pop
  **********************************/
 template <class item>
 void miniqueue<item>::pop()
 { 
 // Check for underflow
 
   if(minilist<item>::n <= 0)
     { cerr << "Queue Underflow" << endl;
       return;
     };
 
 // Remove from front by shifting elements
 
   for(int i = 0; i < minilist<item>::n - 1; i++)
     minilist<item>::data[i] = minilist<item>::data[i + 1];
   minilist<item>::n--;
 }
 
 /**********************************
  * Front
  **********************************/
 template <class item>
 item miniqueue<item>::front()
 { 
 // Check for underflow
 
   if(minilist<item>::n <= 0)
     { cerr << "Queue Underflow" << endl;
       return item();
     };
 
 // Return front value
 
   return minilist<item>::data[0];
 }