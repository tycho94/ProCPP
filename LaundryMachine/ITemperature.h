#ifndef ITEMPERATURE_H
#define ITEMPERATURE_H

enum Temperature
{
    COLD = 1,
    WARM,
    HOT = 3
};

class ITemperature
{
  public:
    // Inputs
    virtual int GetTemperature() = 0;   //temp: 0 - cold, 1 - medium, 2 - hot
    
    // Outputs  
    virtual void SetTemperature(int level) = 0;
};

#endif


