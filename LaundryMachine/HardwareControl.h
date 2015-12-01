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
    //Centipede centipede;
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
    int GetSpeed();
    int GetWaterlevel();
    int GetTemperature();

    // Outputs
    void SetBuzzer(int level);  // off = 0 on = 1
    void SetLock(int level);    // off = 0 on = 1
    void SetSoap1(int level);   // off = 0 on = 1
    void SetSoap2(int level);   // off = 0 on = 1
    void SetDrain(int level);   // off = 0 on = 1
    void SetSink(int level);    // off = 0 on = 1
    void SetMotor(int level);   // off = 0 on = 1
    void SetHeater(int level);  // off = 0 on = 1
    void SetDirection(int dir); // left = 0 right = 1
    void SetProgramIndicator(int program); // off = 0 - levels 1-2-3 = led 1-2-3
    void SetCoin10(int leds);   // off = 0 - levels 1-2-3 = led 1-2-3
    void SetCoin50(int leds);   // off = 0 - levels 1-2-3 = led 1-2-3
    void SetCoin200(int leds);  // off = 0 - levels 1-2 = led 1-2
  private:
    Centipede centipede;
    void SetKeySelect(int value); //TODO
    void SetGroup(int group);   // group 1 = 00, 2 = 10, 3 = 01, 4 = 11
    void SetData(int data);     // data 0 = LOW 1 = DATAA 2 = DATAB 3 = DATAC
    void Strobe();

    int motorSpeed;
    int waterLevel;
    int Temperature;
    
};

#endif



