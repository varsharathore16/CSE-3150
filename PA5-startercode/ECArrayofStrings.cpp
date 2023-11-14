#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include "ECArrayofStrings.h"
using namespace std;

ECArrayofStrings ::ECArrayofStrings(){
}

ECArrayofStrings ::~ECArrayofStrings(){
  // your code goes here
}

void ECArrayofStrings ::AddString(const string &strToAdd){
  arrstrings.push_back(strToAdd);
}

int ECArrayofStrings ::GetNumofStrings() const{
  return arrstrings.size();
}

int ECArrayofStrings ::GetMaxLen() const{
  int maxLen = 0;
  for (auto str : arrstrings){
    if (str.size() > maxLen){
      maxLen = str.size();
    }
  }
  return maxLen;
}

string ECArrayofStrings ::GetLongestCommonPrefix() const{
  int numStrings = GetNumofStrings();
  
  // if there's nothing in the array, return ""
  if (numStrings == 0){
    return "";
  }
  
  // if there's only 1 string in the array, return that string
  if (numStrings == 1){
    return arrstrings[0];
  }
  
  // if there's more than 1 string in the array, find the smallest string
  std::string shortest = arrstrings[0];
  
  for (int i = 1; i < numStrings; ++i){
    if (arrstrings[i] < shortest){
      shortest = arrstrings[i];
    }
  }
  
  // use the smallest string in the array to find the longest common prefix
  std::string prefix = "";
  
  for (int i = 0; i < shortest.length(); ++i){
    for (int j = 0; j < numStrings; ++j){
      if (shortest[i] != arrstrings[j][i]){
        return prefix;
      }
    }
    
    prefix += shortest[i];
  }
  
  return prefix;
}

string ECArrayofStrings ::Concatnate() const{
  string output = "";
  for (auto str : arrstrings){
    copy(str.begin(), str.end(), back_inserter(output));
  }
  
  return output;
}

void ECArrayofStrings::Dump() const{
  for (auto str : arrstrings){
    cout << str << endl;;
  }
}