// Code for modeling a university's various units: department, office,
// college, etc

// Generic interface. 
class ECUnit
{
public:
	double GetBudget() const ...
};

// Department
class ECDepartment : public ECUnit
{
public:
	ECDepartment(int b)  ...
	double GetBudget() const ...

private:
  ...
};

// Office
class ECOffice : public ECUnit
{
public:
  ECOffice(int b) ...
  double GetBudget() const ...

private:
  ...
};

// Composite
class ECCompositeUnit : public ECUnit
{
public:
  ECCompositeUnit()  {}
  ~ECCompositeUnit()
  ...
  
  double GetBudget() const 
  { 
...
  }
  void AddChild(ECUnit *pUnit)
  {
...
  }

private:
  // your code here

};

