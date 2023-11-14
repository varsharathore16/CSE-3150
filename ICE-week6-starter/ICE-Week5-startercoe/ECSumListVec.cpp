#include <vector>
#include <iostream>
using namespace std;

// return the sum of the numbers
int ECSumList(const vector<int> &listNums)
{
  // your code goes here ...
  int sum = 0;

  /*
  for(int i=0; i<listNums.size(); ++i){
    sum += listNums[i];
  }
  */

  /*
  for(auto x : listNums){ // makes it more generic - range loop
    sum += x;
  }
  */

  // using iterator:
  for(auto it = listNums.begin(); it != listNums.end(); ++it){
    sum += *it;
  }

  return sum;
}

