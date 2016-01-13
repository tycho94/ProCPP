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

int StubHardwareControl::GetMotorSpeed(){
    return motorSpeed;
}

int StubHardwareControl::GetMotorDir(){
    return motorDir;
}

int StubHardwareControl::GetTemperature() {
    return currentTemp;
}

void StubHardwareControl::SetSoap1(bool level) {
    //(void) level; // this does nothing, gets rid of compiler warning
    if (level)
        soap1 = true;
    else
        soap1 = false;
}

void StubHardwareControl::SetSoap2(bool level) {
    //(void) level; // this does nothing, gets rid of compiler warning
    if (level)
        soap2 = true;
    else
        soap2 = false;
}

void StubHardwareControl::SetDrain(int level) {
    drain = level;
}

void StubHardwareControl::SetDirection(int dir) {
    // LEFT or RIGHT
    if (dir == 0 || dir == 1)
        motorDir = dir;

}
void StubHardwareControl::SetMotor(int speedlevel) {
    //from LOW to HIG [0-4)
    if (speedlevel >= 0 && speedlevel < 4)
      motorSpeed = speedlevel;
}

void StubHardwareControl::SetProgramIndicator(int program) {
	if(program <= 2 && program >= 0)
	    programIndicator = program;
}

int StubHardwareControl::GetProgramIndicator(){
	return programIndicator;
}

void StubHardwareControl::SetBuzzer(bool level) {
    BuzzerButton = level;
}

bool StubHardwareControl::GetBuzzer() {
    return BuzzerButton;
}

bool StubHardwareControl::GetLockSwitch() {
    return SwitchLocker;
}

void StubHardwareControl::SetLock(int level) {
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
    //between 1 (COLD) and 3 (HOT)
    if (level > 0 && level < 4)
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
