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

boolean ProgramExecutor::Start(ProgramSettings * p)
{
  mProgramSettings = p;
  if (mCoinWallet->Withdraw(p->cost) && mLock->GetLockSwitch() && mSoap->GetSoap1Switch() && mSoap->GetSoap2Switch())
    return true;
  else
    return false;
}

boolean ProgramExecutor::Step()
{
  return (true);
}

boolean ProgramExecutor::IsReady()
{
  return (false);
}

