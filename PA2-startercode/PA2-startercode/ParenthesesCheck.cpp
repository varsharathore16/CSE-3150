//
//  ParenthesesCheck.cpp
//  
//
//  Created by Yufeng Wu on 11/13/19.
//
//
#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool isOpeningParenthesis(char c) {
    return (c == '(' || c == '[');
}

bool isClosingParenthesis(char c) {
    return (c == ')' || c == ']');
}

bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') || (opening == '[' && closing == ']');
}

// Check if the string has valid nested parentheses
// If so, return true; if not return false; if the string contains
// unexpected symbols, return false
bool ECParentheseCheck(const string &strInput)
{
  // your code goes here
    std::stack<char> parenthesesStack;

    for (char c : strInput) {
        if (isOpeningParenthesis(c)) {
            parenthesesStack.push(c);
        } else if (isClosingParenthesis(c)) {
            if (parenthesesStack.empty() || !isMatchingPair(parenthesesStack.top(), c)) {
                return false;
            }
            parenthesesStack.pop();
        }
    }

    return parenthesesStack.empty();
}


int main() {
    std::string s = "()[";
    if (ECParentheseCheck(s)) {
        std::cout << "Well-formed parentheses\n";
    } else {
        std::cout << "Not well-formed parentheses\n";
    }

    return 0;
}