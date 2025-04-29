/************************************
 * Lab23.h
 * Written by Laith Assaf
 ************************************/

 #ifndef LAB23_H
 #define LAB23_H
 
 #include <string>
 using namespace std;
 
 // Constants
 #define CITY_MAX 8
 
 // City names array
 const string city[CITY_MAX] = {
     "0) Lansing",
     "1) Flint",
     "2) Detroit",
     "3) Jackson",
     "4) Grand Rapids",
     "5) Battle Creek",
     "6) Kalamazoo",
     "7) Clare"
 };
 
 // Distance table between cities
 const int DISTANCE[CITY_MAX][CITY_MAX] = {
     {0,  53, 80, 34, 75, 35, 0,  85},  // Lansing
     {53, 0,  77, 0,  0,  0,  0,  94},  // Flint
     {80, 77, 0,  68, 0,  0,  0,  0},   // Detroit
     {34, 0,  68, 0,  0,  30, 0,  0},   // Jackson
     {75, 0,  0,  0,  0,  0,  59, 109}, // Grand Rapids
     {35, 0,  0,  30, 0,  0,  47, 0},   // Battle Creek
     {0,  0,  0,  0,  59, 47, 0,  0},   // Kalamazoo
     {85, 94, 0,  0,  109,0,  0,  0}    // Clare
 };
 
 // Function prototypes
 void showCityList();
 void findPath(int start, int stop);
 void invalidateReturnPath(int map[][CITY_MAX], int from, int to);
 void invalidateCity(int map[][CITY_MAX], int city);
 
 #endif // LAB23_H