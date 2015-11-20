#ifndef STUBHARDWARECONTROL_H
#define STUBHARDWARECONTROL_H

#include "ArduinoWrapper.h"	// to be included before all other LaundryMachine include files

#include "IBuzzer.h"
#include "ICoin.h"
#include "ILock.h"
#include "IMotor.h"
#include "IProgram.h"
#include "ISoap.h"
#include "ITemperature.h"
#include "IWater.h"

class StubHardwareControl: public IBuzzer, public ICoin, public ILock, public IMotor, public IProgram, public ISoap, public ITemperature, public IWater
{
  public:
    // Inputs
    boolean GetCoin10Button();
    boolean GetStartButton();
    int GetTemperature();

    // Outputs
    void SetBuzzer(int level);
    void SetSoap2(int level);
    void SetDrain(int level);
    void SetDirection(int dir);
    void SetProgramIndicator(int program);
    void SetCoin50(int leds);

    // public member variable to control the behaviour of the StubHardwareControl
    // e.g. TestCoinWallet sets Coin10Button, and GetCoin10Button() returns the value of this variable
    boolean Coin10Button;
};

#endif // STUBHARDWARECONTROL_H
