// Can you change the code to use buffer overflow to 
// change the flow control of the code?
#include <iostream>
using namespace std;

int main();

void foo()
{
  cout << "Enter foo\n";
  long arr[10];

  cout << "main: " << (long)main << endl;

  for (int j=0; j<5; ++j){
    cout << arr[10+j] << endl;
  }


  int i = 10;
  int offset = 4;

  arr[i+3] = (long)main+offset;
  cout << "Updated arr has: " << arr[i+3] << endl;
  cout << "Exit foo\n";

}

int main()
{
  foo();
  return 0;
}

