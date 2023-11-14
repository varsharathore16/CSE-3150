// Define a function ECZero, which set the first number of the passed-in vector to be zero if this number is negative; otherwise do nothing
#include <vector>
using namespace std;

// Now define your function

void ECZero(vector<int> &v){
/*
Write a function called ECZero, which takes a vector of integers and return void. 
This function would set the first number of this vector to be zero if this first number if negative (if there is such a number). 
After ECZero returns, the passed-in vector would have the property that its first number is non-negative. 
For example, suppose v=[-1, 2, 3], then after calling ECZero(v), v = [0, 2, 3]. If v1=[3, 2, 3], then after calling ECZero(v1), v1=[3,2,3].  
*/

    if (v[0] < 0){
        v[0] = (int)0;
    }

}