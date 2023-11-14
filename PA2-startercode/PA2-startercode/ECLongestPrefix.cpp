#include "ECLongestPrefix.h" 
#include <iostream>

using namespace std;

// Implement the longest prefix function here...
std::string ECLongestPrefix(int numStrings, const std::string arrayStrings[])
{
  // YW: this only serves as a starter code, which just print out the given array of strings
  // Replace with your own code here...

  if (numStrings == 0) return "";
  if (numStrings == 1) return arrayStrings[0];

  int counter = 0;
  int min_counter = 0;
  int max_length;

  string comparision_string = arrayStrings[0];
  for (int i = 1; i < numStrings; i++){
    if (comparision_string.length() >= arrayStrings[i].length()){
      max_length = arrayStrings[i].length();
    }
    else max_length = comparision_string.length();
    for (int j = 0; j < max_length; j++){
      if (comparision_string[j] == arrayStrings[i][j]){
        cout << comparision_string[j] << " " << arrayStrings[i][j] << endl;
        counter += 1;
      }
      else break;
    }
    if(counter < min_counter || min_counter == 0) min_counter = counter;
    counter = 0;
  }
  if (min_counter == 0) return "";
  cout << min_counter << endl;
  return comparision_string.substr(0, min_counter);
}
