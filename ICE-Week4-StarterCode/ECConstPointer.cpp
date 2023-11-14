#include <iostream>
using namespace std;

void ECSumArray(const int *listNums, int size)
{
  // You need to loop through the array using pointer. How to define this pointer? 
  
  const int * p = listNums;
  int sum = 0;
  for (int i=0; i<size; ++i){
    sum += *p;
    ++p;
  }

  cout << "sum: " << sum << endl;
}

int main()
{
  int array[] = {1,2,3,5};
  ECSumArray(array, 4);
  return 0;
}
