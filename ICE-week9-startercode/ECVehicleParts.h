#ifndef _EC_VEHICLE_PARTS_H
#define _EC_VEHICLE_PARTS_H

// Engine type
enum EC_ENGINE_TYPE
{
  EC_ENGINE_4CYL = 0,
  EC_ENGINE_6CYL = 1,
  EC_ENGINE_ELECTRIC = 2
};

// Engine
class ECEngine 
{
public:
  ECEngine(EC_ENGINE_TYPE t ) : type(t) {}
  
  int GetCost() const
  {
    if (type == EC_ENGINE_4CYL)
    {
      return 1000;
    }
    else if (type == EC_ENGINE_6CYL)
    {
      return 1500;
    }
    else
    {
      return 3000;
    }
  }

private:
  EC_ENGINE_TYPE type;
};

// Wheel
class ECWheel 
{
public:
  ECWheel(int s) : size(s) {}
  int GetCost() const
  {
    if (size == 17)
    {
      return 100;
    }
    else {return 150;}
  }

private:
  int size;
};

// light
class ECLight 
{
public:
int GetCost() const
{
  return 50;
}

};

#endif