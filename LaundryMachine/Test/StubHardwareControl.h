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
    // public member variable to control the behaviour of the StubHardwareControl
    // e.g. TestCoinWallet sets Coin10Button, and GetCoin10Button() returns the value of this variable
    boolean Coin10Button;

    // Inputs
    boolean GetLockSwitch();
    boolean GetCoinClearButton();
    boolean GetCoin200Button();
    boolean GetCoin50Button();
    boolean GetCoin10Button();
    boolean GetStartButton();
    boolean GetProgramButton();
    boolean GetSoap1Switch();
    boolean GetSoap2Switch();
    boolean GetPressureSwitch();
    int GetWaterlevel();
    int GetTemperature();

    // Outputs
    void SetBuzzer(boolean level);
    void SetWaterlevel(int level);
    void SetTemperature(int level);
    void SetSoap1(int level);
    void SetLock(int level);
    void SetMotor(int speedlevel);
    void SetCoin10(int leds);
    void SetCoin200(int leds);
    void SetBuzzer(int level);
    void SetSoap2(int level);
    void SetDrain(int level);
    void SetDirection(int dir);
    void SetProgramIndicator(int program);
    void SetCoin50(int leds);

  private:
    int coins;
};

#endif // STUBHARDWARECONTROL_H
