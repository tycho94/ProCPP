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
if(check(360))
{
  preWashA();
  mainWashAB();
  morestuff();
}
    return;
}

// IMPLEMENT PROG B
void ProgramExecutor::programB() {
    return;
}

// IMPLEMENT PROG C
void ProgramExecutor::programC() {
    return;
}

bool ProgramExecutor::check(int money) {
  if(mCoinWallet->Withdraw(money))
  {
      if((mLock->GetLockSwitch())&&(mSoap->GetSoap1Switch())&&((mSoap->GetSoap1Switch())
      {
        return true;
      }
  }
}

void ProgramExecutor::preWashBC(){
  // fill 50% with water
  mWater->SetWaterlevel(2);
  // heat to 50%
  mTemperature->SetTemperature(2);
  // add soap1
  mSoap->SetSoap1(false);
  // rotate clockwise, at regular speed for 1 minute
  mMotor->SetDirection(1);
  mMotor->SetMotor(MOTOR_REGULAR);
  delay(10000);
  // rotate counterclockwise, at regular speed for 1 minute
  mMotor->SetDirection(0);
  mMotor->SetMotor(MOTOR_REGULAR);
  delay(10000);
  // drain water
  mWater->SetWaterlevel(0);


}

void ProgramExecutor::mainWashAB(){
  int i;
  //===================== WASH =========================
  // fill 50% with water
  // heat to 50%
  // add soap2
  for (i=0; i < 1; i++)
  {
    // rotate clockwise, at regular speed for 1 minute
    // rotate counterclockwise, at regular speed for 1 minute
  }
  // drain water
  //===================== RINSE ========================
  // fill 50% with water
  for (i=0; i < 1; i++)
  {
    // rotate clockwise, at regular speed for 1 minute
    // rotate counterclockwise, at regular speed for 1 minute
  }
  // drain water
  //===================== DRY ==========================
  // keep draining the water
  for (i=0; i < 1; i++)
  {
    // rotate clockwise, at regular speed for 30s
    // rotate counterclockwise, at regular speed for 30s
  }
}
void ProgramExecutor::preWashA(){
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
void ProgramExecutor::mainWashC(){
  int i;
  //===================== WASH =========================
  // fill 100% with water
  // heat to 100%
  // add soap2
  for (i=0; i < 3; i++)
  {
    // rotate clockwise, at regular speed for 1 minute
    // rotate counterclockwise, at regular speed for 1 minute
  }
  // drain water
  //===================== RINSE ========================
  // fill 50% with water
  for (i=0; i < 3; i++)
  {
    // rotate clockwise, at regular speed for 1 minute
    // rotate counterclockwise, at regular speed for 1 minute
  }
  // drain water
  //===================== DRY ==========================
  // keep draining the water
  for (i=0; i < 2; i++)
  {
    // rotate clockwise, at regular speed for 30s
    // rotate counterclockwise, at regular speed for 30s
  }
}
