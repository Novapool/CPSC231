/***********************************
 * MiniVector
 * Written by Mark Bowman
 ***********************************/

 template <class item>
 class minivector:public minilist<item>
 { public:
     minivector();
     ~minivector();
     bool push_back(item arg);    // Add item at end
     item at(int arg);            // Get item
     item operator [] (int arg);  // Get item
 };
 
 /**********************************
  * Constructor
  **********************************/
 template <class item>
 minivector<item>::minivector()
 { 
 // Initialize vector
 
   // Removed cerr output
 }
 
 /**********************************
  * Destructor
  **********************************/
 template <class item>
 minivector<item>::~minivector()
 { 
 // Clean up vector
 
   // Removed cerr output
 }
 
 /**********************************
  * Push_Back
  **********************************/
 template <class item>
 bool minivector<item>::push_back(item arg)
 { 
 // Check for overflow
 
   if(minilist<item>::n >= minilist<item>::LIST_MAX)
     { cerr << "Vector Overflow" << endl;
       return false;
     };
 
 // Add to end
 
   minilist<item>::data[minilist<item>::n++] = arg;
 
 // Success
 
   return true;
 }
 
 /**********************************
  * At
  **********************************/
 template <class item>
 item minivector<item>::at(int arg)
 { 
 // Check bounds
 
   if(arg<0 || arg>=minilist<item>::n)
     { cerr << "Vector Out of Bounds" << endl;
       return item();
     };
 
 // Return value in array
 
   return minilist<item>::data[arg];
 }
 
 /**********************************
  * []
  **********************************/
 template <class item>
 item minivector<item>::operator [](int arg)
 { return at(arg);
 }