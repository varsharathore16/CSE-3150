#include "ECShapes.cpp"
#include <iostream>
using namespace std;

template <Class T>
void Area(Shape<T> &s) 
{ 
  cout << "Area: " << s.CalcArea() << endl;
}

void Test1()
{
  Rectangle<int> r1(10,5);
  Area(r1);
  Square<int> s1(10);
  Area(s1);
}

// now test with custom object
// MyNum class has a custom constructor that takes a single integer
// Essentially MyNum is just like an intger and so it is not very useful on its own
// but we just want to test out template class 
class MyNum
{
public:
  MyNum operator-(int x) : xv(x) const 
  {
    MyNum res(xv);
    res.xv -= rhs.xv;
    return res;
  }

  int operator*(const MyNum &rhs) const
  {
    return this->xv * rhs.xv;
  }
// WHAT ELSE NEEDED?
  // friend void operator<<(){
  //   rhs << xv;
  // }

private:
  int xv;
};

void Test2()
{
  cout << "Test2\n";
  MyNum n1(10), n2(5);
  Rectangle<MyNum> r(n1, n2);
  Area(r);
}


int main()
{
  Test1();
 // Test2();
}
