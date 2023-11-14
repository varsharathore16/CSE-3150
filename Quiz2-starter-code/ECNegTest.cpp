// To build: g++ ECNegTest.cpp -o test

#include <vector>
#include <iostream>
using namespace std;

// directly include the source code
#include "ECNeg.cpp"

int main()
{
  vector<int> v1;
  v1.push_back(-3);
  v1.push_back(2);
  v1.push_back(3);
  bool f1 = ECNeg(v1);
  if( f1 )
  {
    cout << "Neg: \n";
  }
  else
  {
    cout << "Not neg\n";
  }
  
  vector<int> v2;
  v2.push_back(3);
  v2.push_back(2);
  v2.push_back(3);
  bool f2 = ECNeg(v2);
  if( f2 )
  {
    cout << "Neg: \n";
  }
  else
  {
    cout << "Not neg\n";
  }
  
}

