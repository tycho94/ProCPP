#ifndef HARDWARECONTROL_H
#define HARDWARECONTROL_H

#include "Centipede.h"

#include "IBuzzer.h"
#include "ICoin.h"
#include "ILock.h"
#include "IMotor.h"
#include "IProgram.h"
#include "ISoap.h"
#include "ITemperature.h"
#include "IWater.h"

class HardwareControl: public IBuzzer, public ICoin, public ILock, public IMotor, public IProgram, public ISoap, public ITemperature, public IWater
{
  public:
    HardwareControl();
    // Inputs

    // Buttons
    boolean GetCoin10Button();
    boolean GetCoin50Button();
    boolean GetCoin200Button();
    boolean GetCoinClearButton();
    boolean GetProgramButton();
    boolean GetStartButton();
    // Switches
    boolean GetPressureSwitch();
    boolean GetLockSwitch();
    boolean GetSoap1Switch();
    boolean GetSoap2Switch();
    // Settings
    int GetWaterlevel();   // 0=empty, 1=1/3, 2=2/3, 3=filled
    int GetTemperature(); // 0=cold, 1=medium, 2=hot

    // Outputs
    void SetCoin10(int leds);   // off = 0 - levels 1-2-3 = led 1-2-3
    void SetCoin50(int leds);   // off = 0 - levels 1-2-3 = led 1-2-3
    void SetCoin200(int leds);  // off = 0 - levels 1-2 = led 1-2
    void SetBuzzer(boolean level);  // off = 0 on = 1
    void SetLock(int level);    // off = 0 on = 1
    void SetSoap1(int level);   // off = 0 on = 1
    void SetSoap2(int level);   // off = 0 on = 1
    void SetWaterlevel(int waterlevel);
    //void SetSink(boolean state);     // off = 0 on = 1
    //void SetDrain(boolean state);    // off = 0 on = 1
    void SetMotor(int speedlevel);   // 0=off 1=slow 2=medium 3=high
    void SetTemperature(int level);  // off = 0 on = 1
    void SetDirection(int dir); // left = 0 right = 1
    void SetProgramIndicator(int program); // off = 0 - levels 1-2-3 = led 1-2-3

  private:
    Centipede centipede;
    void SetKeySelect(int value); // false = 0 true = 1
    void SetGroup(int group);   // group 1 = 00, 2 = 10, 3 = 01, 4 = 11
    void SetData(int data);     // data 0 = LOW 1 = DATAA 2 = DATAB 3 = DATAC
    void SetDataOff(int data);
    void Strobe();

};

#endif
