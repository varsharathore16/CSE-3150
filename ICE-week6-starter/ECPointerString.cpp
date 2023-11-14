#include "ECPointerString.h"
#include <iostream>
using namespace std;

ECStringPtr :: ECStringPtr() : ptr(NULL)
{
cout << "Default\n";
}

ECStringPtr :: ECStringPtr(const std::string &strInit)
{
// cout << "Custom\n";
  ptr = new string(strInit);
}

ECStringPtr :: ECStringPtr(const ECStringPtr &rhs)
{
// cout << "Copy\n";
  if( rhs.ptr != NULL )
  {
     ptr = new string( *rhs.ptr  );
  }
  else
  {
    ptr = NULL;
  }
 
}

ECStringPtr :: ECStringPtr(ECStringPtr &&rhs)
{
// cout << "Move\n";
  ptr = rhs.ptr;
  rhs.ptr = NULL;
}

ECStringPtr :: ~ECStringPtr()
{
  delete ptr;
}
        
ECStringPtr & ECStringPtr ::  operator=(const ECStringPtr &rhs)
{
// cout << "Assignment\n";
  if( &rhs == this )
  {
    return *this;
  }

  if( rhs.ptr != NULL )
  {
     ptr = new string( *rhs.ptr  );
  }
  else
  {
    ptr = NULL;
  }
  return *this;
}

std::string ECStringPtr ::  GetString() const
{
  string res;
  if( ptr != NULL )
  {
    res = *ptr;
  }
  return res;
}

void ECStringPtr ::  SetString(const std::string &strToSet)
{
  if( ptr == NULL )
  {
    ptr = new string;
  }
  *ptr = strToSet;
}

const std::string * ECStringPtr ::  GetPtr() const
{
  return ptr;
}

// Skip for the first pass. Create a string by duplicating itself, e.g. if this string is "abc", 
// the new string is "abcabc"
ECStringPtr ECStringPtr ::  Duplicate() const
{
  ECStringPtr res;
  string str;
  if( ptr != NULL )
  {
    str = *ptr + *ptr;
  }
  res.SetString( str );
  return res;
}

