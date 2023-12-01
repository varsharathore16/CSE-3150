// Modify the following code so that it uses lambda for compare
#include <vector>
#include <cmath>
using namespace std;

const double delta = 0.00001;

// bool compare(const double &x, const double &y)
// {
//   return fabs(x-y) < delta;
// }

bool lsearch(const vector<double> &vec, const double &x)
{
  bool res = false;
  for(unsigned int i=0; i<vec.size(); ++i)
  {
    auto cmp = [](const double &x, const double &y)->bool{ return fabs(x-y) < delta; };
    if( cmp(vec[i], x))
    {
      res = true;
      break;
    }
  }
  return res;
}
