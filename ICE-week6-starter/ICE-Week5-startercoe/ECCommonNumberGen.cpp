// Recall in PA3, you want to find a common number in two arrays
// That function only assumes integer type; what about others: char, string, long, etc?
// Now implement a more generic common number finding function that works for different types, and we change the input type to vector
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

template <class T>
bool ECCommonNumber(const vector<T> &listA, const vector<T> &listB, T &val)
{
  // your code here
  // copy elements of listA to a set (vector to a set)
  set<T> setA;
  copy( listA.begin(), listA.end(), inserter(setA, setA.begin()) );
  
  // search each element in listB
  for(auto x : listB){ // simple range loop
    if(setA.find(x) != setA.end()){
      val = x;
      return true;
    }
  }
  
  return false;
}

