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
    void SetDrain(bool level);

    // ITemperature
    int GetTemperature();
    void SetTemperature(int level);
    //testing functions
    void SetCurrentTemp(int level);
    bool GetHeater();

    // ISoap
    void SetSoap1(bool level);
    void SetSoap2(bool level);

    bool GetSoap1Switch();
    bool GetSoap2Switch();

    // IProgram
    bool GetStartButton();
    bool GetProgramButton();
    void SetProgramIndicator(int program);
    int GetProgramIndicator();

    // IMotor
    void SetMotor(int speedlevel);
    void SetDirection(bool dir);
    int GetMotorSpeed();
    int GetMotorDir();

    // ILock
    bool GetLockSwitch();
    void SetLock(bool level);

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
    bool drain;

    // Motor testing variables
    int motorDir;
    int motorSpeed;

    // Temperature testing variables
    int currentTemp;
    bool heater;    

    // Soap testing variables
    bool soap1;
    bool soap2;

    // Program testing variables
    bool startButton;
    bool programButton;
    int programIndicator;
};
