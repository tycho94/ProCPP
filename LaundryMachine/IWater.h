#ifndef IWATER_H
#define IWATER_H

enum WaterLevel
{
    WATER_0_PERCENT,
    WATER_33_PERCENT,
    WATER_66_PERCENT,
    WATER_100_PERCENT
};

class IWater
{
  public:
    // Inputs
  virtual void SetSink(boolean state) = 0;
  virtual void SetDrain(boolean state) = 0;

    // Outputs
    virtual void SetWaterlevel(int level) = 0;
    virtual WaterLevel GetWaterLevel()=0;   //level: 0=empty, 1=1/3, 2=2/3, 3=filled
    virtual boolean GetPressureSwitch() = 0;
};

#endif
