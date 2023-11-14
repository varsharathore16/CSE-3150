#include "ECMotorVehicle.h"
using namespace std;

// Generic vehicle
ECMotorVehicle :: ECMotorVehicle() : pe(nullptr) 
{
}
ECMotorVehicle ::  ~ECMotorVehicle()
{
  delete pe;
  for (auto x : listPWs)
  {
    delete x;
  }
  for (auto x : listPLs)
  {
    delete x;
  }
}

void ECMotorVehicle :: SetEngine(EC_ENGINE_TYPE t)
{
  this->pe = new ECEngine(t);
}

double ECMotorVehicle :: GetPrice() const
{
  int tot = 0;
  if (pe != nullptr) {
    tot += pe->GetCost();
  }
  for (auto x : listPWs)
  {
    tot += x->GetCost();
  }
  for (auto x : listPLs)
  {
    tot += x->GetCost();
  }
  return (tot*1.5 - GetDiscount()) * (1 + GetTaxRate());
}


void ECMotorVehicle :: AddWheel(int sz)
{
  listPWs.push_back(new ECWheel(sz));
}

void ECMotorVehicle :: AddLight()
{
  listPLs.push_back(new ECLight());
}

// Car
ECCar :: ECCar(EC_ENGINE_TYPE t, int szWheel)
{
  SetEngine(t);
  for (int i = 0; i < 4; ++i)
  {
    AddWheel(szWheel);
  }
  for (int i = 0; i < 4; ++i)
  {
    AddLight();
  }
}

// Truck 
ECTruck :: ECTruck(int numWheels, int szWheel)
{
  SetEngine(EC_ENGINE_6CYL);
  for (int i = 0; i < numWheels; ++i)
  {
    AddWheel(szWheel);
  }
  for (int i = 0; i < 8; ++i)
  {
    AddLight();
  }
}

// Motocycle
ECMotocycle :: ECMotocycle()
{
  SetEngine(EC_ENGINE_4CYL);
  for (int i = 0; i < 2; ++i)
  {
    AddWheel(17);
  }
  for (int i = 0; i < 2; ++i)
  {
    AddLight();
  }
}