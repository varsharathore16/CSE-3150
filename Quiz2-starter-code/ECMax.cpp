// Find the maximum number of a vector of integers
#include <vector>
using namespace std;

int ECMax(vector<int> v)
{
  /*
  You are given a function ECMax that is to find the maximum number from a vector of integers and return this max. 
  Return 0 if the vector is empty.  This code passed the provided test cases. 
  However, it has a serious bug. Now fix the bug.
  */
  int res = v[0];
  
  if (v.size() == 0){
    return 0;
  }

  for(int i=1; i<(int)v.size(); ++i)
  {
    if( v[i] > res )
    {
      res = v[i];
    }
  }
  return res;
}

