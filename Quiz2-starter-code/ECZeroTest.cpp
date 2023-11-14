// To build: g++ ECZeroTest.cpp -o test

#include <vector>
#include <iostream>
using namespace std;

// directly include the source code
#include "ECZero.cpp"

int main()
{
  vector<int> v1;
  v1.push_back(-3);
  v1.push_back(2);
  v1.push_back(3);
  ECZero(v1);
  cout << "v1[0] (should be 0): " << v1[0] << endl;
  
  vector<int> v2;
  v2.push_back(3);
  v2.push_back(2);
  v2.push_back(3);
  ECZero(v2);
  cout << "v2[0] (should be 3): " << v2[0] << endl;
  
}

