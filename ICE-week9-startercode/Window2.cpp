#include "Shape.h"

// define window class
class Window 
{
public:
  // Upper left (x1, y1), lower right (x2, y2)
  Window(int x1, int y1, int x2, int y2)
  {
    p = new Rectangle(x2-x1, y2-y1);
  }

  Window(int x1, int y1, double r)
  {
    p = new Circle(r);
  }
  double GetDisplayArea() const 
  {
    return p->GetArea();
  }

  ~Window()
  {
    delete p;
  }
  
  // other stuff: drawing, etc
  // skipped: no implementation for now

  Shape *p;
};