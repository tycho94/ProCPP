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

