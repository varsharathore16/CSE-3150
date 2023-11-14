// Starter code
#include <string>
#include <iostream>

char ECToLower(char ch){
  return ch - 'A' + 'a';
}

char ECToUpper(char ch){
  return ch + 'A'-'a';
}

bool ECIsLowerChar(char ch){
  return ch >= 'a' && ch <= 'z';
}

bool ECIsUpperChar(char ch){
  return ch >= 'A' && ch <= 'Z';
}

std::string ECSwapCaseAlt(std::string str)
{
  std::string res;
  for(unsigned int i=0; i<str.length(); ++i){
    if( ECIsLowerChar(str[i])){
      res += ECToUpper(str[i]);
    } else if (ECIsUpperChar(str[i])){
      res += ECToLower(str[i]);
    } else {
      res += str[i];
    }
  }
  return res;
}

std::string ECSwapCase(std::string str){
  return ECSwapCaseAlt(str);
}
