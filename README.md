# data-structures-and-algorithms

Collage course with the subject of data structures and algorithms. Done in C language

Tasks:
  exercise_00
    - remake functions from the string.h library(strlen,strcpy,strcmp,strcat,strstr,reverse)
  exercise_01
    - write functions for an array of numbers
      int* subArr(int* arr, int start, int stop) - returns a new array which contains numbers from index start to index stop
      int* filterArr(int* arr, int arrLen, int numToCompare, int* newArrLen) - returns a new array which contains numbers that are less than numToCompare, saves the length of the new array into newArrLen
      int** devide(int* arr, int arrLen) - split the array into two new array which are of the same size, returns two pointers pointing to the first array and the second one
    - declare struct Point containing two floats x and y
    - declare struct Polygon containing an array of structs Point, and number of structs Point n
      Polygon* newPolygon(float* arrX, float* arrY, int n) - returns a polygon using points created from arrays arrX, and arrY
      Point** positive(Polygon* polygon, int* numOfPositive) - returns an array of pointers to Point structs which have positive coordinates x and y, saves the length of the new array into numOfPositive
      
