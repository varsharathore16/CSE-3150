// Test ECMax. To build: g++ ECMax.cpp ECMaxTest.cpp -o test
#include <vector>
#include <iostream>
#include "ECMax.cpp"

using namespace std;

extern int ECMax(vector<int> v);

int main()
{
  vector<int> v1;
  v1.push_back(3);
  v1.push_back(1);
  v1.push_back(4);
  v1.push_back(2);
  int max = ECMax(v1);
  cout << "Max (should be 4): " << max << endl;
}

