// Given two arrays of integers, return true (and also store the smallest integer that is in both arrays). Return false if no such integer exists 
// For example, suppose A1={1, 5, 3, 1} and A2={3, 7, 2}. Then ECCommonNumber(A1, 4, A2, 3, val) would return true (and val would be 3 after function call returns). Here, A1 is the first array, 4 is the size of the first array, A2 is the second array and 3 is the size of the second array. 
// Note: you must implement your algorithm as efficiently as possible
// Also, you need to define the function yourself: how are you going to take
// Tip: don't reinvent the wheel; try to use C++ standard library functions

#include <cstring>
#include <algorithm>


using namespace std;


bool ECCommonNumber(int* a, int sizeA, int* b, int sizeB, int &value)
{
  // your code here...
  bool value_return = false;
  int pointA[sizeA];
  int pointB[sizeB];

  std::copy(a, a + sizeA, pointA);
  std::copy(b, b + sizeB, pointB);

  std::sort(pointA, pointA + sizeA);
  std::sort(pointB, pointB + sizeB);

  int max = __INT32_MAX__;

  for(int i=0; i<sizeA; i++){
    if(std::binary_search(pointB, pointB + sizeB, pointA[i]) && pointA[i] < max){
      max = pointA[i];
      value_return = true;
    }
  }

  if(value_return){
    value = max;
  }
  return value_return;
}


