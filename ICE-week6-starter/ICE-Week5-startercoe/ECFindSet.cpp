#include <vector>
#include <set>
#include <iostream>
using namespace std;

bool ECFind(const set<int> &listNums, int x)
{
  /*
  // your code here
  for(auto y : listNums){
    if(x == y){
      return true;
    }
  }
  return false;
  */

  return listNums.find(x) != listNums.end();
}


