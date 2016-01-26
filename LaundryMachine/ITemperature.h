#ifndef ITEMPERATURE_H
#define ITEMPERATURE_H

typedef enum
{
  COLD = 0,
  COLD2 = 1,
  MEDIUM = 2 ,
  HOT = 3
} Temperature;

class ITemperature
{
  public:
    // Inputs
    virtual int GetTemperature() = 0;

    // Outputs
    virtual void SetTemperature(int level) = 0;
};

#endif


