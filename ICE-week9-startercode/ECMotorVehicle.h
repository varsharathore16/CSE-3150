#ifndef _EC_MOTOR_VEHICLE_H
#define _EC_MOTOR_VEHICLE_H

#include <vector>
#include "ECVehicleParts.h"
using namespace std;

// Generic vehicle
class ECMotorVehicle
{
public:
  ECMotorVehicle();
  virtual ~ECMotorVehicle();
  double GetPrice() const;

protected:
  // your code here
  void SetEngine(EC_ENGINE_TYPE t);
  void AddWheel(int sz);
  void AddLight();

  virtual int GetDiscount() const {return 0;}
  virtual double GetTaxRate() const = 0;

private:
  // what to put here?

  ECEngine *pe;
  vector<ECWheel *> listPWs;
  vector<ECLight *> listPLs;
};

// Car
class ECCar : public ECMotorVehicle
{
public:
  ECCar(EC_ENGINE_TYPE t, int szWheel);

protected:
  virtual double GetTaxRate() const {return 0.1;}
};

// Truck 
class ECTruck : public ECMotorVehicle
{
public:
  ECTruck(int numWheels, int szWheel);

protected:
  virtual int GetDiscount() const {return 1000;}
  virtual double GetTaxRate() const {return 0.08;}
};

// Motocycle
class ECMotocycle : public ECMotorVehicle
{
public:
  ECMotocycle();

protected:
  virtual int GetDiscount() const {return 100;}
  virtual double GetTaxRate() const {return 0.15;}
};

#endif