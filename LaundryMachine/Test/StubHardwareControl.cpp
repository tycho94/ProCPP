#include "ArduinoWrapper.h"

#include "StubHardwareControl.h"

boolean StubHardwareControl::GetCoin10Button()
{
  return (Coin10Button);
}

boolean StubHardwareControl::GetStartButton()
{
  return (false);
}

int StubHardwareControl::GetTemperature()
{
  return (0);
}


void StubHardwareControl::SetSoap2(int level)
{
}

void StubHardwareControl::SetDrain(int level)
{
}

void StubHardwareControl::SetDirection(int dir)
{
}

void StubHardwareControl::SetProgramIndicator(int program)
{
}

void StubHardwareControl::SetBuzzer(int level)
{
}

void StubHardwareControl::SetCoin50(int leds)
{
}

boolean StubHardwareControl::GetCoin50Button() {
    return true;
}

boolean StubHardwareControl::GetCoin200Button() {
    return true;
}

boolean StubHardwareControl::GetCoinClearButton() {
    return true;
}

void StubHardwareControl::SetCoin10(int leds) {
}

void StubHardwareControl::SetCoin200(int leds) {
}

boolean StubHardwareControl::GetLockSwitch() {
    return true;
}

void StubHardwareControl::SetLock(int level) {
}

void StubHardwareControl::SetMotor(int speedlevel) {
}

boolean StubHardwareControl::GetProgramButton() {
    return true;
}

boolean StubHardwareControl::GetSoap1Switch() {
    return true;
}

boolean StubHardwareControl::GetSoap2Switch() {
    return true;
}

void StubHardwareControl::SetSoap1(int level) {
}

void StubHardwareControl::SetTemperature(int level) {
}

int StubHardwareControl::GetWaterlevel() {
    return 0;
}

boolean StubHardwareControl::GetPressureSwitch() {
    return true;
}

void StubHardwareControl::SetWaterlevel(int level) {
}

void StubHardwareControl::SetBuzzer(boolean level) {
}
