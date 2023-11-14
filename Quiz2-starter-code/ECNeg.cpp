// Return true if the first number in the passed-in vector is negative (less than zero), otherwise return false. If the vector is empty, return false
#include <vector>
using namespace std;

// Now define ECNeg here

bool ECNeg(const vector<int> v){

/*
3. A function that test whether the first number of the passed-in vector isnegative. 
Write a function called ECNeg, which takes a vector of integers and return true if the first number is negative, and false otherwise. 
If the vector is empty, return false. For example, for v=[-1,2,3], return true. For v1=[3,2,3], ECNeg(v1) returns false.

*/

    if(v.size() == 0){
        return false;
    } else if (v[0] < 0){
        return true;
    }

    return false;

    // return listNums.find(v[0]) < 0;


}