//
//  ECPropositionalLogic.cpp
//  

#include "ECPropositionalLogic.h"
#include <vector>
using namespace std;

// ****************************************************************************
// Your code here
// #include "ECPropositionalLogic.h"
#include <set>
#include <map>
#include <iostream>
#include <bitset>

// Constructor for an empty logic expression
ECPropositionalLogicExpr::ECPropositionalLogicExpr() : value(""), left(nullptr), right(nullptr) {}

// Constructor for a logic expression consisting of a single boolean variable
ECPropositionalLogicExpr::ECPropositionalLogicExpr(const std::string &varName) : value(varName), left(nullptr), right(nullptr) {}

// Copy constructor: deep copy
ECPropositionalLogicExpr::ECPropositionalLogicExpr(const ECPropositionalLogicExpr &rhs) {
    if (rhs.left) left = new ECPropositionalLogicExpr(*(rhs.left));
    if (rhs.right) right = new ECPropositionalLogicExpr(*(rhs.right));
    value = rhs.value;
}

// Assignment operator
ECPropositionalLogicExpr& ECPropositionalLogicExpr::operator=(const ECPropositionalLogicExpr &rhs) {
    if (this != &rhs) {
        delete left;
        delete right;
        left = nullptr;
        right = nullptr;
        if (rhs.left) left = new ECPropositionalLogicExpr(*(rhs.left));
        if (rhs.right) right = new ECPropositionalLogicExpr(*(rhs.right));
        value = rhs.value;
    }
    return *this;
}

// Destructor: release memory
ECPropositionalLogicExpr::~ECPropositionalLogicExpr() {
    delete left;
    delete right;
}

// Overload the NOT operator
ECPropositionalLogicExpr ECPropositionalLogicExpr::operator!() const {
    ECPropositionalLogicExpr result;
    result.value = "!";
    result.left = new ECPropositionalLogicExpr(*this);
    return result;
}

// Overload the AND operator
ECPropositionalLogicExpr ECPropositionalLogicExpr::operator&&(const ECPropositionalLogicExpr &rhs) const {
    ECPropositionalLogicExpr result;
    result.value = "&&";
    result.left = new ECPropositionalLogicExpr(*this);
    result.right = new ECPropositionalLogicExpr(rhs);
    return result;
}

// Overload the OR operator
ECPropositionalLogicExpr ECPropositionalLogicExpr::operator||(const ECPropositionalLogicExpr &rhs) const {
    ECPropositionalLogicExpr result;
    result.value = "||";
    result.left = new ECPropositionalLogicExpr(*this);
    result.right = new ECPropositionalLogicExpr(rhs);
    return result;
}

// Check if the expression is satisfiable
bool ECPropositionalLogicExpr::IsSatisfiable() const {
    std::set<std::string> variables = GetVariables();
    int numVariables = variables.size();

    for (int i = 0; i < (1 << numVariables); i++) {
        std::map<std::string, bool> assignment;
        int j = 0;
        for (const auto &var : variables) {
            assignment[var] = ((i >> j) & 1);
            j++;
        }
        if (evaluate(assignment)) {
            return true;
        }
    }

    return false;
}

// Check if the expression is a tautology
bool ECPropositionalLogicExpr::IsTautology() const {
    std::set<std::string> variables = GetVariables();
    int numVariables = variables.size();

    for (int i = 0; i < (1 << numVariables); i++) {
        std::map<std::string, bool> assignment;
        int j = 0;
        for (const auto &var : variables) {
            assignment[var] = ((i >> j) & 1);
            j++;
        }
        if (!evaluate(assignment)) {
            return false;
        }
    }

    return true;
}

// Helper function to get the set of variables
std::set<std::string> ECPropositionalLogicExpr::GetVariables() const {
    std::set<std::string> variables;

    if (value != "" && value != "!" && value != "&&" && value != "||") {
        variables.insert(value);
    }

    if (left) {
        std::set<std::string> leftVars = left->GetVariables();
        variables.insert(leftVars.begin(), leftVars.end());
    }

    if (right) {
        std::set<std::string> rightVars = right->GetVariables();
        variables.insert(rightVars.begin(), rightVars.end());
    }

    return variables;
}

// Helper function to evaluate the expression
bool ECPropositionalLogicExpr::evaluate(const std::map<std::string, bool> &assignment) const {
    if (value != "" && value != "!" && value != "&&" && value != "||") {
        return assignment.at(value);
    }

    if (value == "!") {
        return !left->evaluate(assignment);
    }

    if (value == "&&") {
        return left->evaluate(assignment) && right->evaluate(assignment);
    }

    if (value == "||") {
        return left->evaluate(assignment) || right->evaluate(assignment);
    }

    return false; // Default case, should not be reached
}