#include <set>
#include <vector>
#include <iostream>
using namespace std;

int ECSumList(const set<int> &listNums)
{
  // your code goes here ...
  int sum = 0;

  // can use iterator, but takes longer
  // can use indexing
  
  for(auto x : listNums){ // makes it more generic - range loop
    sum += x;
  }

  return sum;
}

