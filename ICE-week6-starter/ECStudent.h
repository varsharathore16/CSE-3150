#ifndef _EC_STUDENT_H
#define _EC_STUDENT_H

#include <string>

// Student class
class ECStudent
{
public:
  ECStudent(const std::string &nameIn) : name(nameIn), mt(0), f(0), hw(0) {} // dont forget to initialize with any list

  // never forget to initialize, especially with pointers!!!!

  double GetMT() const { return mt; }
  void SetMT(double s) { mt = s; }
  double GetFinal() const { return f; }
  void SetFinal(double s) { f = s; }
  double GetHW() const { return hw; }
  void SetHW(double s) {hw = s; }
  std::string GetName() const { return name; }
  // ave score: 20% HW, 30% Midterm, 50% Final
  double GetAve() const { return 0.2*hw+0.3*mt+0.5*f; }

private:
  std::string name;
  double mt;
  double f;
  double hw;
};


#endif
