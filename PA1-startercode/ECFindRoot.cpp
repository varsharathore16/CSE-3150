// This function returns the smallest non-negative integral root of a polynomial (as specified by a list of coefficients and degree) that is no larger than xmax. Return -1 if there is no roots within the range.
//To be specific: for each integer 0 <=i <= degree, listCoeffs[d] = the coefficient of the degree d term. For example,

#include <math.h>
#include <ctype.h>
#include <iostream> 

int ECFindRoot(int *listCoeffs, int degree, int xmax)
{
  // listCoeffs: pointer to the array of integers as the coefficients of a polynomial; listCoeffs[0] is the constant term and so on
  // degree: highest degree term. That is, the number of coefficients in the array = degree+1
  // xmax: the largest value of root to search
  // your code here

  using namespace std;
  for(int i=0; i<=xmax && i<=abs(listCoeffs[0]); i++)
  {
    if(i==0){
      if((listCoeffs[0]==0))
      {
        return 0;
      } continue;
    };

    if((listCoeffs[0]%i !=0)){
      continue;
    }


  int32_t total = 0;
  bool a = false;
  for(int b=degree; b>=0; b--)
  {
    total = total * i + listCoeffs[b];
  }

  if (total==0)
  {
    return i;
  }

  } return -1;
}
