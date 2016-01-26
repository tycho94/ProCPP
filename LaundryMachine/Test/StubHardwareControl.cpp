#include "StubHardwareControl.h"

StubHardwareControl::StubHardwareControl() {
    AmountOfCoins = 0;
    BuzzerButton = false;
    CoinClearButton = true;
    Coin10Button = true;
    Coin50Button = true;
    Coin200Button = true;
    SwitchLocker = false;
    waterLevel = 0;
    pressureSwitch = true;
    motorDir = 1;//right
    motorSpeed = 0;
    currentTemp = 1;//cold
    heater = false;
    soap1 = false;
    soap2 = false;
    startButton = true;
    programButton = true;

}

StubHardwareControl::~StubHardwareControl() {
    // nothing
}

bool StubHardwareControl::GetCoin10Button() {
    return Coin10Button;
}

bool StubHardwareControl::GetCoin50Button() {
    return Coin50Button;
}

bool StubHardwareControl::GetCoin200Button() {
    return Coin200Button;
}

bool StubHardwareControl::GetCoinClearButton() {
    return CoinClearButton;
}

void StubHardwareControl::SetCoin10(int leds) {
    (void) leds;
    AmountOfCoins += 10;
}

void StubHardwareControl::SetCoin50(int leds) {
    (void) leds;
    AmountOfCoins += 50;
}

void StubHardwareControl::SetCoin200(int leds) {
    (void) leds;
    AmountOfCoins += 200;
}

int StubHardwareControl::GetCoinAmount() {
    return AmountOfCoins;
}

void StubHardwareControl::ResetCoinAmount() {
    AmountOfCoins = 0;
}

bool StubHardwareControl::GetStartButton() {
    return startButton;
}

int StubHardwareControl::GetMotorDir(){
    return motorDir;
}

int StubHardwareControl::GetTemperature() {
    return currentTemp;
}

void StubHardwareControl::SetSoap1(bool level) {
    //(void) level; // this does nothing, gets rid of compiler warning
    soap1 = level;
}

void StubHardwareControl::SetSoap2(bool level) {
    //(void) level; // this does nothing, gets rid of compiler warning
    soap2 = level;
}

void StubHardwareControl::SetDrain(bool level) {
    drain = level;
}

void StubHardwareControl::SetDirection(bool dir) {
    // LEFT or RIGHT
        motorDir = dir;

}
void StubHardwareControl::SetMotor(int speedlevel) {
    //from LOW to HIG [0-4)
    if (speedlevel >= 0 && speedlevel < 4)
      motorSpeed = speedlevel;
}

void StubHardwareControl::SetProgramIndicator(Program program) {
	if(program <= 3 && program >= -1)
	    programIndicator = program;
}

int StubHardwareControl::GetProgramIndicator(){
	return programIndicator;
}

void StubHardwareControl::Buzz() {
    BuzzerButton = !BuzzerButton;
}

bool StubHardwareControl::GetBuzzer() {
    return BuzzerButton;
}

bool StubHardwareControl::GetLockSwitch() {
    return SwitchLocker;
}

void StubHardwareControl::SetLock(bool level) {
    SwitchLocker = level;
}

bool StubHardwareControl::GetProgramButton() {
    return programButton;
}

bool StubHardwareControl::GetSoap1Switch() {
    return soap1;
}

bool StubHardwareControl::GetSoap2Switch() {
    return soap2;
}

void StubHardwareControl::SetTemperature(int level) {
    if(GetTemperature() >= level)
	heater = false;
    else 
	heater = true;
	
    currentTemp = level;
}

bool StubHardwareControl::GetHeater(){
    return heater;
}

void StubHardwareControl::SetCurrentTemp(int level) {
    currentTemp = level;
}

int StubHardwareControl::GetWaterlevel() {
    return waterLevel;
}

bool StubHardwareControl::GetPressureSwitch() {
    return pressureSwitch;
}

void StubHardwareControl::SetWaterlevel(int level) {
    //(void) level; // this does nothing, gets rid of compiler warning
    if (level >= 0 && level < 4)
      waterLevel = level;
}
int StubHardwareControl::GetMotor(){
	return motorSpeed;
}

int StubHardwareControl::GetProgramMoney(Program program) {
  if (program == PROGRAM_A) {
    return 360;
    }
  else if (program == PROGRAM_B) {
    return 480;
    }
  else if (program == PROGRAM_C) {
    return 510;
    }
  else if(program == NO_PROGRAM){
	   return -1;
	}
	return -1;
}
