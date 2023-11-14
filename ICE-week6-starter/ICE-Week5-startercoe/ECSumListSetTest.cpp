#include <set>
#include <vector>
#include <iostream>
using namespace std;

#include "ECSumListSet.cpp"

int main()
{
  set<int> ss;
  ss.insert(5);
  ss.insert(3);
  ss.insert(3); // sets cannot have copies, so the final answer will be 9, not 12
  ss.insert(0);
  ss.insert(1);
  int sum = ECSumList(ss);
  cout << "sum: " << sum << endl;
}
