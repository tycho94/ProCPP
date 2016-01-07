#include "StubHardwareControl.h"

bool StubHardwareControl::GetCoin10Button()
{
  return (Coin10Button);
}

bool StubHardwareControl::GetStartButton()
{
  return (false);
}

int StubHardwareControl::GetTemperature()
{
  return currentTemp;
}

void StubHardwareControl::SetDrain(int level)
{
}

void StubHardwareControl::SetDirection(int dir)
{
  if (dir == 1)
    motorDir = dir;
  if (dir == 2)
    motorDir = dir;
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

bool StubHardwareControl::GetCoin50Button() {
    return true;
}

bool StubHardwareControl::GetCoin200Button() {
    return true;
}

bool StubHardwareControl::GetCoinClearButton() {
    return true;
}

void StubHardwareControl::SetCoin10(int leds) {
}

void StubHardwareControl::SetCoin200(int leds) {
}

bool StubHardwareControl::GetLockSwitch() {
    return true;
}

void StubHardwareControl::SetLock(int level) {
}

// Added this to check if logic within the method
// gives the expected result (copy pasted)
void StubHardwareControl::SetMotor(int speedlevel) {
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

void StubHardwareControl::SetSoap1(int level) {
  if (level > 0)
    soap1 = true;
  else
    soap1 = false;
}

void StubHardwareControl::SetSoap2(int level) {
  if (level > 0)
    soap2 = true;
  else
    soap2 = false;
}

void StubHardwareControl::SetTemperature(int level) {
  if (level > 0 && level < 4)
      currentTemp = level;
}

int StubHardwareControl::GetWaterlevel() {
    return wLevel;
}

// I think we'll need to improve it for testing cases when watter 
// presure gets low during one of the programs
bool StubHardwareControl::GetPressureSwitch() {
    return pressureSwitch;
}

void StubHardwareControl::SetWaterlevel(int level) {
  if (level >= 0 && level < 4)
      wLevel = level;
}

void StubHardwareControl::SetBuzzer(bool level) {
}
