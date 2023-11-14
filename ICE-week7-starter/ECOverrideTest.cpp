#include <iostream>
using namespace std;

// Class A
class A 
{
public:
  virtual ~A() { cout << "DA\n";}

  virtual void foo() 
  {
    cout << "A\n";
  }
};

// Class B: subclass of A
class B : public A
{
public:
  ~B() { cout << "DB\n";}

  void foo() override
  {
    cout << "B\n";
    // return 0;
  }
};

void Test(A &a)
{
  a.foo();
}

int main()
{
  // B b;
  // Test(b);
 A *pa = new B;
 Test(*pa);
 delete pa;
}
