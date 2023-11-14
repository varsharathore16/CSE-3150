#include <string>
#include <iostream>
using namespace std;

void foo(int n)
{
  if( n < 0 )
  {
    // your code goes here
    throw string("NEGATIVE");
  }
  // your code goes here
  else if (n==0){
    throw string("ZERO");
  }
}

string bar(int n)
{
  // your code goes here
  try {
    foo(n);
  }
  catch (string ex){
    return ex;
  }
  return "OK";
}

// int main()
// {
//   int n1 = -1;
//   string str1 = bar(n1);
//   //ASSERT_EQ(str1, "NEGATIVE");
//   cout << "str1:" << str1 << endl;

//   int n2 = 3;
//   string str2 = bar(n2);
//   //ASSERT_EQ(str2, "OK");
//   cout << "str2:" << str2 << endl;

//   int n3 = 0;
//   string str3 = bar(n3);
//   //ASSERT_EQ(str3, "ZERO");
//   cout << "str3:" << str3 << endl;

//   return 0;
// }
