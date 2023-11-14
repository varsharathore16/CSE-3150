// Throw an excepton of C++ string "TOO LONG" if the passed-in vector has 100 or more elements. Otherwise does nothing
#include <vector>
#include <string>
using namespace std;

// define your functon ECCheckLen here

void ECCheckLen(const vector<int> v){
/*
Write a function called ECCheckLen, which takes a vector v of integers; 
if v's length is longer than 100, throw an exception of C++ string "TOO LONG". 
Otherwise, it does nothing. Check the provided test code for examples. 
*/

    if (v.size() > 100){
        throw string("TOO LONG");
    }
}
