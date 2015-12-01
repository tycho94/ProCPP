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

    boolean GetCoin10Button();
    boolean GetCoin50Button();
    boolean GetCoin200Button();
    boolean GetCoinClearButton();
    boolean GetStartButton();
    int GetWaterlevel();
    int GetTemperature();

    // Outputs
    void SetBuzzer(int level);
    void SetSoap2(int level);
    void SetDrain(int level);
    void SetDirection(int dir);
    void SetProgramIndicator(int program);
    void SetCoin50(int leds);
  private:
    Centipede centipede;
    void SetKeySelect(int value);
    void SetGroup(int group);
    void SetData(int data);
    void Strobe();
};

#endif



