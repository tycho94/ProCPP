#ifndef IWATER_H
#define IWATER_H

class IWater
{
  public:
    // Inputs
  virtual void SetSink(boolean state) = 0;
  virtual void SetDrain(boolean state) = 0;
  virtual boolean GetWaterPressure()=0

    // Outputs
    virtual void SetWaterlevel(int level) = 0;
    virtual int GetWater()=0;
};

#endif


