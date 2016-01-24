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
void ProgramExecutor::preWashBC(){
  
}
void ProgramExecutor::mainWashAB(){
  
}
void ProgramExecutor::preWashA(){
  
}
void ProgramExecutor::mainWashC(){
  
}

