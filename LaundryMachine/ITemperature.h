#ifndef ITEMPERATURE_H
#define ITEMPERATURE_H

enum Temperature
{
    COLD = 1,
    MEDIUM =2,
    WARM =3 ,
    HOT = 4
};

class ITemperature
{
  public:
    // Inputs
    virtual int GetTemperature() = 0;   
    
    // Outputs  
    virtual void SetTemperature(int level) = 0;
};

#endif


