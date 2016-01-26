#ifndef HARDWARECONTROL_H
#define HARDWARECONTROL_H

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
    bool GetCoin10Button();
    bool GetCoin50Button();
    bool GetCoin200Button();
    bool GetCoinClearButton();
    bool GetProgramButton();
    bool GetStartButton();
    // Switches
    bool GetPressureSwitch();
    bool GetLockSwitch();
    bool GetSoap1Switch();
    bool GetSoap2Switch();
    // Settings
    int GetWaterlevel();   // 0=empty, 1=1/3, 2=2/3, 3=filled
    int GetTemperature(); // 0=cold, 1=medium, 2=hot
    int GetProgramMoney(Program program);

    // Outputs
    void SetCoin10(int leds);   // off = 0 - levels 1-2-3 = led 1-2-3
    void SetCoin50(int leds);   // off = 0 - levels 1-2-3 = led 1-2-3
    void SetCoin200(int leds);  // off = 0 - levels 1-2 = led 1-2
    void Buzz();  // off = 0 on = 1
    void SetLock(bool level);    // off = 0 on = 1
    void SetSoap1(bool level);   // off = 0 on = 1
    void SetSoap2(bool level);   // off = 0 on = 1
    void SetWaterlevel(int waterlevel);
    //void SetSink(bool state);     // off = 0 on = 1
    //void SetDrain(bool state);    // off = 0 on = 1
    void SetMotor(int speedlevel);   // 0=off 1=slow 2=medium 3=high
    int GetMotor();   // 0=off 1=slow 2=medium 3=high
    void SetTemperature(int level);  // off = 0 on = 1
    void SetDirection(bool dir); // left = 0 right = 1
    void SetProgramIndicator(Program program); // off = 0 - levels 1-2-3 = led 1-2-3

  private:
    Centipede centipede;
    void SetKeySelect(int value); // false = 0 true = 1
    void SetGroup(int group);   // group 1 = 00, 2 = 10, 3 = 01, 4 = 11
    void SetData(int data);     // data 0 = LOW 1 = DATAA 2 = DATAB 3 = DATAC
    void SetDataOff(int data);
    void Strobe();
    void PressureError();

};

#endif
