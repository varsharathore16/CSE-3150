#include "ECNumbers.h"
#include "ECCalculator.h"
#include <iostream>

using namespace std;
using namespace EC_NUMBER;

int main()
{
  // read in an integer n
  // your code here
  cout << "Enter an integer: ";
  int x = 0;
  cin >> x;

  // print out the square of it
  // your code here
  cout << "Square: " << EC_NUMBER::ECSquareN(x) << endl;

  // print out 2n  
  // your code here
  cout << "Double: " << EC_NUMBER::ECDoubleN(x) << endl;

  // print out 4 times of n by invoking ECCalculator's function
  // your code here
  cout << "Four Times: " << ECFourTimesN(x) << endl;

  return 0;
}
