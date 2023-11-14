#include <iostream>
using namespace std;

void ECRemoveSpace(int nums[], int len, int val)
{
  // your code here
  // define two pointers i and j
  // i starts from left, j from right
  int i = 0, j = len-1;
  while (i < j){
    if(nums[i] != val){
      ++i;
    } else if (nums[j] == val){
      --j;
    } else {
      nums[i] = nums[j];
      nums[j] = val;
    }
  }

  for (int k =j; k < len; ++k){
    nums[k] = '_';
  }
}


