#include "StubHardwareControl.h"

StubHardwareControl::StubHardwareControl() {
    AmountOfCoins = 0;
    BuzzerButton = false;
    Coin10Button = false;
    Coin50Button = false;
    Coin200Button = false;
    SwitchLocker = false;
    Soap1 = false;
    Soap2 = false;
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
    return (false);
}

int StubHardwareControl::GetTemperature() {
    return (0);
}

void StubHardwareControl::SetSoap2(bool level) {
    (void) level; // this does nothing, gets rid of compiler warning
}

void StubHardwareControl::SetDrain(int level) {
    (void) level; // this does nothing, gets rid of compiler warning
}

void StubHardwareControl::SetDirection(int dir) {
    (void) dir; // this does nothing, gets rid of compiler warning
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
    //how is suposed to test this without the hardware control thing
    //because we need need to set it and we will get diferent values
    (void) speedlevel; // this does nothing, gets rid of compiler warning
}

bool StubHardwareControl::GetProgramButton() {
    return true;
}

bool StubHardwareControl::GetSoap1Switch() {
    return Soap1;
}

bool StubHardwareControl::GetSoap2Switch() {
    return Soap2;
}

void StubHardwareControl::SetSoap1(bool level) {
    //(void) level; // this does nothing, gets rid of compiler warning
    Soap1 = level;
}

void StubHardwareControl::SetTemperature(bool level) {
    //(void) level; // this does nothing, gets rid of compiler warning
    Soap2 = level;
}

int StubHardwareControl::GetWaterlevel() {
    return 0;
}

bool StubHardwareControl::GetPressureSwitch() {
    return true;
}

void StubHardwareControl::SetWaterlevel(int level) {
    (void) level; // this does nothing, gets rid of compiler warning
}
