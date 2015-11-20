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
  return (true);
}

boolean ProgramExecutor::Step()
{
  return (true);
}

boolean ProgramExecutor::IsReady()
{
  return (false);
}

