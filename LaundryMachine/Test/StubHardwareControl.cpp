#include "StubHardwareControl.h"

StubHardwareControl::StubHardwareControl() {
    AmountOfCoins = 0;
    BuzzerButton = false;
    Coin10Button = false;
    Coin50Button = false;
    Coin200Button = false;
    SwitchLocker = false;
    waterLevel = 0;
    pressureSwitch = true;
    motorDir = 1;
    motorSpeed = 0;
    currentTemp = 1;
    soap1 = false;
    soap2 = false;
    start_button = 0;
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
    Coin10Button = true;
    AmountOfCoins += 10;
}

void StubHardwareControl::SetCoin50(int leds) {
    (void) leds;
    Coin50Button = true;
    AmountOfCoins += 50;
}

void StubHardwareControl::SetCoin200(int leds) {
    (void) leds;
    Coin200Button = true;
    AmountOfCoins += 200;
}

int StubHardwareControl::GetCoinAmount() {
    return AmountOfCoins;
}

void StubHardwareControl::ResetCoinAmount() {
    AmountOfCoins = 0;
}

bool StubHardwareControl::GetStartButton() {
    return start_button;
}

int StubHardwareControl::GetTemperature() {
    return currentTemp;
}

void StubHardwareControl::SetSoap1(int level) {
    //(void) level; // this does nothing, gets rid of compiler warning
    if (level)
        soap1 = true;
    else
        soap1 = false;
}

void StubHardwareControl::SetSoap2(int level) {
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
    //(void) dir; // this does nothing, gets rid of compiler warning
    if (dir == 1)
        motorDir = dir;
    if (dir == 2)
        motorDir = dir;
}

void StubHardwareControl::SetProgramIndicator(int program) {
    (void) program; // this does nothing, gets rid of compiler warning
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

void StubHardwareControl::SetMotor(int speedlevel) {
    //(void) speedlevel; // this does nothing, gets rid of compiler warning
    if (speedlevel == 0)
      motorSpeed = speedlevel;
    else if (speedlevel == 1)
      motorSpeed = speedlevel;
    else if (speedlevel == 2)
      motorSpeed = speedlevel;
    else if (speedlevel == 3)
      motorSpeed = speedlevel;
}

bool StubHardwareControl::GetProgramButton() {
    return true;
}

bool StubHardwareControl::GetSoap1Switch() {
    return true;
}

bool StubHardwareControl::GetSoap2Switch() {
    return true;
}

void StubHardwareControl::SetTemperature(int level) {
    //(void) level; // this does nothing, gets rid of compiler warning
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
