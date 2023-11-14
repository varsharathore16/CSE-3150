#include "ECClass.h"
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Class for class
ECClass :: ECClass()
{
}

void ECClass :: AddStudent( const ECStudent &s)
{
  // your code
  listStu.push_back(s);
}

double ECClass :: GetAveMedian() const
{
  // your code
  if(listStu.size() == 0){
    return -100;
  }

  vector<double> scores;
  for (auto x : listStu){
    scores.push_back(x.GetAve());
  }

  std::sort(scores.begin(), scores.end());
  return scores[scores.size()/2];
}

std::string ECClass :: GetRankedStudentName(int n) const
{
  // your code
  vector<pair<double, string>> listSN;
  for ( auto x : listStu){
    listSN.push_back(std::make_pair(-1* x.GetAve(), x.GetName()));
  }
  std::sort(listSN.begin(), listSN.end());
  return listSN[n].second;
}

