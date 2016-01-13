#pragma once

// wrapper for the types that arduino has and we don't
#include "ArduinoWrapper.h"

// include all the interfaces that we're going to reimplement
#include "../IBuzzer.h"
#include "../ICoin.h"
#include "../ILock.h"
#include "../IMotor.h"
#include "../IProgram.h"
#include "../ISoap.h"
#include "../ITemperature.h"
#include "../IWater.h"

class StubHardwareControl: public IBuzzer, public ICoin, public ILock, public IMotor, public IProgram, public ISoap, public ITemperature, public IWater
{
  public:
    StubHardwareControl();
    virtual ~StubHardwareControl();


    // IBuzzer
    void SetBuzzer(bool level);
    // custom function for tests
    bool GetBuzzer();

    // IWater
    bool GetPressureSwitch();
    int GetWaterlevel();

    void SetWaterlevel(int level);
    void SetDrain(int level);

    // ITemperature
    int GetTemperature();
    void SetTemperature(int level);

    // ISoap
    void SetSoap1(int level);
    void SetSoap2(int level);

    bool GetSoap1Switch();
    bool GetSoap2Switch();

    // IProgram
    bool GetStartButton();
    bool GetProgramButton();
    void SetProgramIndicator(int program);

    // IMotor
    void SetMotor(int speedlevel);
    void SetDirection(int dir);

    // ILock
    bool GetLockSwitch();
    void SetLock(int level);

    // ICoin
    bool GetCoin10Button();
    bool GetCoin50Button();
    bool GetCoin200Button();
    bool GetCoinClearButton();

    // custom methods for testings
    int GetCoinAmount();
    void ResetCoinAmount();

    void SetCoin10(int leds);
    void SetCoin50(int leds);
    void SetCoin200(int leds);

  private:
    // Coin testing variables
    int AmountOfCoins;
    bool Coin10Button;
    bool Coin50Button;
    bool Coin200Button;
    bool CoinClearButton;

    // Buzzer testing variables
    bool BuzzerButton;

    // Lock testing variables
    bool SwitchLocker;

    // Water testing variables
    int waterLevel;
    bool pressureSwitch;

    // Motor testing variables
    int motorDir;
    int motorSpeed;

    // Temperature testing variables
    int currentTemp;

    // Soap testing variables
    bool soap1;
    bool soap2;

    //Program testing variables
    bool StartButton;
};
