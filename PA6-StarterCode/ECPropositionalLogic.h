//
//  ECPropositionalLogic.h
//  
//
//  Created by Yufeng Wu on 9/6/23.
//

#ifndef ECPropositionalLogic_h
#define ECPropositionalLogic_h

#include <string>
#include <map>
#include <set>

// ****************************************************************************
// Propositional logic expression
// You are to implement a subset of propositional logic (which you have learned in CSE 2500)

class ECPropositionalLogicExpr
{
public:
    std::string value;
    ECPropositionalLogicExpr* left;
    ECPropositionalLogicExpr* right;

    // Create an empty logic expression
    ECPropositionalLogicExpr();

    // Create a logic expression consisting of a single bool variable
    ECPropositionalLogicExpr(const std::string &varName);

    // Copy constructor: perform deep copy
    ECPropositionalLogicExpr(const ECPropositionalLogicExpr &rhs);

    // assignment operator
    ECPropositionalLogicExpr& operator=(const ECPropositionalLogicExpr &rhs);

    // Destructor: make sure free memory
    virtual ~ECPropositionalLogicExpr();

    // Overload !, && and || logic operators
    // Your code here...
    ECPropositionalLogicExpr operator!() const;
    ECPropositionalLogicExpr operator&&(const ECPropositionalLogicExpr &rhs) const;
    ECPropositionalLogicExpr operator||(const ECPropositionalLogicExpr &rhs) const;

    // several important functions in propositional logic
    // Is this propositional logic expression satisifable?
    bool IsSatisfiable() const;

    // Is this propositional logic expression a tautlogy (i.e., always true no matter what values in its boolean variable)?
    bool IsTautology() const;

    std::set<std::string> GetVariables() const;

private:
    // Helper function to get the set of variables
    bool evaluate(const std::map<std::string, bool> &assignment) const;
    // Member variables or other data structures you may need
};

// You may add more helper classes
// I used a class hierarchy to represent different kinds of logic operations
// Your code here


#endif /* ECPropositionalLogic_h */
