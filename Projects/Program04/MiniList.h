/***********************************
 * MiniList
 * Written by Laith Assaf
 ***********************************/

 template <class item>
 class minilist
 { public:
     minilist();     // Constructor
     ~minilist();    // Destructor
     int size();     // Number of elements
   protected:
     int n;          // Elements used
     item *data;     // Data array
     static const int LIST_MAX = 10;
 };
 
 /**********************************
  * Constructor
  **********************************/
 template <class item>
 minilist<item>::minilist()
 { 
 // Initialize
 
   n = 0;
   data = new item[LIST_MAX];
   // Removed cerr output
 }
 
 /**********************************
  * Destructor
  **********************************/
 template <class item>
 minilist<item>::~minilist()
 { 
 // Clean up
 
   delete [] data;
   // Removed cerr output
 }
 
 /**********************************
  * Size
  **********************************/
 template <class item>
 int minilist<item>::size()
 { return n;
 }