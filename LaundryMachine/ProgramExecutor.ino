#include "ProgramExecutor.h"

ProgramExecutor::ProgramExecutor(IBuzzer * b, IMotor * m, ILock * l, ISoap * s, ITemperature * t, IWater * w, CoinWallet * c)
{
  mBuzzer = b;
  mMotor = m;
  mLock = l;
  mSoap = s;
  mTemperature = t;
  mWater = w;
  mCoinWallet = c;
}

bool ProgramExecutor::Start(Program program)
{
  if (program == PROGRAM_A) {
    programA();
  } else if (program == PROGRAM_B) {
    programB();
  } else if (program == PROGRAM_C) {
    programC();
  } else {
    return -1;
  }
}

bool ProgramExecutor::Step()
{
  return (true);
}

bool ProgramExecutor::IsReady()
{
  return (false);
}

// IMPLEMENT PROG A
void ProgramExecutor::programA() {
  if (check(360))
  {
    preWashA();
    mainWashAB();
    unlock();

  }

}

// IMPLEMENT PROG B
void ProgramExecutor::programB() {
  if (check(480))
  {
    preWashBC();
    mainWashAB();
    unlock();

  }
}

// IMPLEMENT PROG C
void ProgramExecutor::programC() {
  if (check(510))
  {
    preWashBC();
    mainWashC();
    unlock();

  }
}

bool ProgramExecutor::check(int money) {
  if (mCoinWallet->Withdraw(money))
  {
    if ((mLock->GetLockSwitch()) && (mSoap->GetSoap1Switch()) && ((mSoap->GetSoap1Switch())))
    {
      return true;
    }
  }
  return false;
}

void ProgramExecutor::preWashBC() {
  unsigned long t, current;
  // fill 50% with water
  while (!(mWater->GetWaterlevel() == WATER_50_PERCENT)) {
    mWater->SetWaterlevel(WATER_50_PERCENT);
  }
  mWater->SetWaterlevel(WATER_50_PERCENT);
  // heat to 50%
  while (!(mTemperature->GetTemperature() == MEDIUM)) {
    mTemperature->SetTemperature(MEDIUM);
  }
  // add soap1
  mSoap->SetSoap1(false);
  // rotate clockwise, at regular speed for 1 minute
  mMotor->SetDirection(CLOCK);
  mMotor->SetMotor(MOTOR_REGULAR);
  t = millis() + 5000;
  while (t > millis()) {
    mTemperature->SetTemperature(MEDIUM);
  }
  // rotate counterclockwise, at regular speed for 1 minute
  mMotor->SetDirection(COUNTERCLOCK);
  mMotor->SetMotor(MOTOR_REGULAR);
  t = millis() + 5000;
  while (t > millis()) {
    mTemperature->SetTemperature(MEDIUM);
  }
  // drain water
  mMotor->SetMotor(MOTOR_OFF);
  mTemperature->SetTemperature(COLD);

  while (!(mWater->GetWaterlevel() == WATER_0_PERCENT)) {
    mWater->SetWaterlevel(0);
  }
  mWater->SetWaterlevel(0);

}

void ProgramExecutor::mainWashAB() {
  int i;
  //===================== WASH =========================
  // fill 50% with water
  mWater->SetWaterlevel(WATER_50_PERCENT);
  // heat to 50%
  // add soap2
  for (i = 0; i < 1; i++)
  {
    // rotate clockwise, at regular speed for 1 minute
    // rotate counterclockwise, at regular speed for 1 minute
  }
  // drain water
  //===================== RINSE ========================
  // fill 50% with water
  for (i = 0; i < 1; i++)
  {
    // rotate clockwise, at regular speed for 1 minute
    // rotate counterclockwise, at regular speed for 1 minute
  }
  // drain water
  //===================== DRY ==========================
  // keep draining the water
  for (i = 0; i < 1; i++)
  {
    // rotate clockwise, at regular speed for 30s
    // rotate counterclockwise, at regular speed for 30s
  }
}
void ProgramExecutor::preWashA() {
  // fill 50% of water
  mWater->SetWaterlevel(2);
  // add soap1
  mSoap->SetSoap1(false);
  //
  mMotor->SetDirection(1);
  mMotor->SetMotor(MOTOR_REGULAR);
  delay(10000);
  mMotor->SetDirection(0);
  mMotor->SetMotor(MOTOR_REGULAR);
  delay(10000);
  // drain
  mWater->SetWaterlevel(0);
}
void ProgramExecutor::mainWashC() {
  int i;
  //===================== WASH =========================
  // fill 100% with water
  // heat to 100%
  // add soap2
  for (i = 0; i < 3; i++)
  {
    // rotate clockwise, at regular speed for 1 minute
    // rotate counterclockwise, at regular speed for 1 minute
  }
  // drain water
  //===================== RINSE ========================
  // fill 50% with water
  for (i = 0; i < 3; i++)
  {
    // rotate clockwise, at regular speed for 1 minute
    // rotate counterclockwise, at regular speed for 1 minute
  }
  // drain water
  //===================== DRY ==========================
  // keep draining the water
  for (i = 0; i < 2; i++)
  {
    // rotate clockwise, at regular speed for 30s
    // rotate counterclockwise, at regular speed for 30s
  }
}

void ProgramExecutor::unlock() {
  mLock->SetLock(false);
}
