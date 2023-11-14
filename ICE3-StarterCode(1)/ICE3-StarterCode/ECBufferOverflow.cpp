#include <iostream>
using namespace std;

int main()
{
  // try to change w to 0xfffffff;
  int w = 0;
  char arr[] = "hello";
  // vary i from 5 to 7
  int i=7;
  arr[i] = 'T';
  cout << "arr = " << arr << endl;
  cout << "w = " << w << endl;

  bitset<32> wb(w);
  cout << "Binary w = " << wb << endl;
  cout << "arr[i] int value = " << (int)arr[i] << endl;

  cout << "arr: " << (long)arr << endl;
  bitset<32> wa((long)arr);

  cout << "Binary arr (cast to long) = " << wa << endl;

  return 0;
}
