// To build: g++ ECNegTest.cpp -o test

#include <vector>
#include <string>
#include <iostream>
using namespace std;

// directly include the source code
#include "ECCheckLen.cpp"

int main()
{
  vector<int> v1;
  v1.push_back(-3);
  v1.push_back(2);
  v1.push_back(3);
  try
  {
    ECCheckLen(v1);
  }
  catch(string ex)
  {
    // should NOT print it
    cout << "Exception1: " << ex  << "\n";
  }
  
  vector<int> v2;
  for(int i=0; i<150; ++i)
  {
    v2.push_back(i);
  }
  try
  { 
    ECCheckLen(v2);
  }
  catch(string ex)
  {
    // should print it
    cout << "Exception2: " << ex  << "\n";
  } 
 
}

