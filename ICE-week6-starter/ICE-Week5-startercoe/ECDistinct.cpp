#include <vector>
#include <map>
#include <iostream>
using namespace std;

void ECCountDistinct(const vector<int> &listNums, map<int,int> &mapDistinct)
{
  // your code goes here
  mapDistinct.clear();
  for(auto x : listNums){
    if (mapDistinct.find(x) == mapDistinct.end()){
      mapDistinct[x] = 0;
    }

    ++mapDistinct[x];
  }
}

