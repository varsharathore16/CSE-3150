//
#include <iostream>
using namespace std;

int main()
{
  // allocate an array of char in heap 
  char *px = new char[10];
  // set this array to 'a', 'b' and so on
  // your code here...
  for(char *py = px; py<px+10; ++py){
    *py = 'a'+(int)(py-px);
  }
  // print out
  for(int i=0; i<10; ++i)
  {
    cout << px[i];
    // cout << *(px+i)
  }
  cout << endl;
  //cout << "The array pointed by px is: " << *px << endl;

  delete [] px;
  //delete px;

  int x=0;
  char c = x;
  // cout<< c << endl;

  unsigned int y = 1;
  if(y < x){
    //cout << "Bad\n";
  }

  return 0;
}
 
