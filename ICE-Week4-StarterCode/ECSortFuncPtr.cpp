#include <iostream>
using namespace std;

// complete the definition of the sorting function ...
void ECSortFP(int *listNumbers, int size, bool (*fp) (int x, int y))
{
  // your code here
  for(int i=1; i<size; ++i){
    int a = i;
    //while (a >= 1 && listNumbers[a] < listNumbers[a-1]){
    while (a >= 1 && fp(listNumbers[a], listNumbers[a-1])){
      // swap [a] with [a-1]
      int temp = listNumbers[a];
      listNumbers[a] = listNumbers[a-1];
      listNumbers[a-1] = temp;
      --a;
    }
  }
}

// define compare function
bool Compare1(int x, int y){
  return x < y;
}
bool Compare2(int x, int y){
  return x > y;
}
bool Compare3(int x, int y){
  // return x%2 == 0;
  if (x%2 == 0 && y%2==1){
    return true;
  } 
  else if (x%2 == 1 && y%2==0){
    return false;
  } 
  else {
    return x < y;
  }
}

int main()
{
  const int NUM = 8;
  int arr[] = {1, 3, 2, 4, 5, 7, 8, 6};
  ECSortFP(arr, NUM, Compare3);

  // print it out
  for(int i=0; i<NUM; ++i)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

