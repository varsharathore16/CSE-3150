#include <vector>
#include <set>
#include <iostream>
using namespace std;

// I want to have a generic function that can work with any types of numbers 
// AND any type of container. Is this possible?

template <class Container>
typename Container::value_type ECSumList(const Container &listNums) // just a generic Container, no type specified after
{
  // your code goes here ...

  // this is supposed to be a generic, more versatile version - need to use TEMPLATES
  typename Container::value_type sum = 0;

  for(auto x : listNums){
    sum += x;
  }

  return sum;
}

