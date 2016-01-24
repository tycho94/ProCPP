#ifndef IWATER_H
#define IWATER_H

enum WaterLevel
{
  WATER_0_PERCENT = 0,
  WATER_33_PERCENT = 1,
  WATER_50_PERCENT = 2,
  WATER_100_PERCENT = 3
};

class IWater
{
  public:
    // Inputs
    //virtual void SetSink(boolean state) = 0;
    virtual void SetDrain(boolean state) = 0;
    virtual int GetWaterlevel() = 0; //level: 0=empty, 1=1/3, 2=2/3, 3=filled
    virtual bool GetPressureSwitch() = 0;

    // Outputs
    virtual void SetWaterlevel(int level) = 0;

};

#endif
