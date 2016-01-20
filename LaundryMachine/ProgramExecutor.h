#ifndef PROGRAMEXECUTOR_H
#define PROGRAMEXECUTOR_H

#include "IBuzzer.h"
#include "ILock.h"
#include "IMotor.h"
#include "IProgram.h"
#include "ISoap.h"
#include "ITemperature.h"
#include "IWater.h"
#include "CoinWallet.h"
#include "ProgramSettings.h"

enum ProgramState{
  PREWASH,
  MAIN_WASH,
  RINSE,
  CENTRIFUGATION
};

enum TimeAction{
  TAKE_WATER,
  HEAT,
  ROTATE_MOTOR,
  REVERSE_ROTATE_MOTOR,
  SINK_WATER
};

enum TimeActionDone{
  WATER_FILLED,
  WATER_HEATED,
  MOTER_ROTATED,
  MOTER_REVERSE_ROTATED,
  WATER_SINKED
};

enum Action{
  ADD_SOAP1,
  ADD_SOAP2,
  UNLOCK
};


class ProgramExecutor
{
  public:
    ProgramExecutor(IBuzzer *, IMotor *, ILock *, ISoap *, ITemperature *, IWater *, CoinWallet *);
    boolean Start(ProgramSettings *);
    boolean Step();
    boolean IsReady();
    
  private:
    IBuzzer * mBuzzer;
    IMotor * mMotor;
    ILock * mLock;
    ISoap * mSoap;
    ITemperature * mTemperature;
    IWater * mWater;
    CoinWallet * mCoinWallet;
    ProgramSettings * mProgramSettings;
};

#endif


