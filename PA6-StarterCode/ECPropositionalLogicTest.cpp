// Test propositional logic
// To build: g++ ECPropositionalLogicTest.cpp ECPropositionalLogic.cpp -o test
#include <iostream>
#include "ECPropositionalLogic.h"

using namespace std;

// Test utility
template<class T>
void ASSERT_EQ(T x, T y)
{
  if( x == y )
  {
    cout << "Test passed: equal: " << x << "  " << y << endl;
  }
  else
  {
    cout << "Test FAILED: equal: " << x << "  " << y << endl;
  }
}

// test case 1
static void Test1()
{
    cout << "\n***** Test 1\n";
    ECPropositionalLogicExpr ea("a"), eb("b"), ec("c");
    ECPropositionalLogicExpr e1 = ea || eb;
    ASSERT_EQ(e1.IsSatisfiable(), true);
    ASSERT_EQ(e1.IsTautology(), false);

    ECPropositionalLogicExpr e2 = (ea && !ea) || (eb && !eb);    
    ASSERT_EQ(e2.IsSatisfiable(), false);
    ASSERT_EQ(e2.IsTautology(), false);

    ECPropositionalLogicExpr e3 = (!ea || ea) || (!ec);    
    ASSERT_EQ(e3.IsSatisfiable(), true);
    ASSERT_EQ(e3.IsTautology(), true);
}

// test case 2
static void Test2()
{
    cout << "\n***** Test 2\n";
    ECPropositionalLogicExpr ea("a"), eb("b"), ec("c"), ed("d"), ee("e");
    ECPropositionalLogicExpr e1 = (ea || eb) && (  ea || !ec) && (!ea || ec);
    ASSERT_EQ(e1.IsSatisfiable(), true);
    ASSERT_EQ(e1.IsTautology(), false);

    ECPropositionalLogicExpr e2 = (!ea || eb) || (!eb || ec);    
    ASSERT_EQ(e2.IsSatisfiable(), true);
    ASSERT_EQ(e2.IsTautology(), true);

    // A larger instance of tautology
    ECPropositionalLogicExpr e3 = (!ea || !eb) || !(!(ea || ec) || ed) || !(!(eb && ed) || ee) || ee;     
    ASSERT_EQ(e3.IsSatisfiable(), true);
    ASSERT_EQ(e3.IsTautology(), true);
}

// test 3: a formula with many clauses (terms) but relatively small number of variables
void Test3()
{
    cout << "\n***** Test 3\n";
    const int NUM_VARS = 10;

    // create basic expressions
    vector<ECPropositionalLogicExpr *> listExpSingle;
    for(int i=0; i<NUM_VARS; ++i)
    {
        string name = "x" + std::to_string(i);
        listExpSingle.push_back(new ECPropositionalLogicExpr( name ));
    }

    // now create a large formula
    ECPropositionalLogicExpr ex1; 
    const int NUM_REPEATS = 50;
    for(int k=0; k<NUM_REPEATS; ++k)
    {
        for(int i=0; i<NUM_VARS; ++i)
        {
            for(int j=i+1; j<NUM_VARS; ++j)
            {
                ex1 = ex1 && ( !(*listExpSingle[i]) || (*listExpSingle[j]) );
            }
        }
    }
    ASSERT_EQ(ex1.IsSatisfiable(), true);
    ASSERT_EQ(ex1.IsTautology(), false);

    // now add a term to make it un-satisiable
    ex1 = ex1 && ( *listExpSingle[0] && !(*listExpSingle[0]));
    ASSERT_EQ(ex1.IsSatisfiable(), false);
    ASSERT_EQ(ex1.IsTautology(), false);

    for(auto x : listExpSingle )
    {
        delete x;
    }
}

int main()
{
    Test1();
    Test2();
    Test3();

    return 0;
}