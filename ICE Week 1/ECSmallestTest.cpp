// to build: c++ ECSmallestTest.cpp -o test
#include <iostream>
using namespace std;

extern int ECSmallest(int *arr, int sz);

int main()
{
  int test1[] = {1, 3, 2};
  cout << ECSmallest(test1, 3) << endl;
  int test2[] = {1, -3, 2};
  cout << ECSmallest(test2, 3) << endl;
  cout << ECSmallest(test2, 0) << endl;
  int test3[] = {-1};
  cout << ECSmallest(test3, 1) << endl;
}

