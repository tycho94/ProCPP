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

class ProgramExecutor
{
  public:
    ProgramExecutor(IBuzzer *, IMotor *, ILock *, ISoap *, ITemperature *, IWater *, CoinWallet *);
    bool Start(Program program);
    bool Step();
    bool IsReady();

  public:
    void programA();
    void programB();
    void programC();
    void preWashBC();
    void mainWashAB();
    void preWashA();
    void mainWashC();
    void unlock();
    bool check(int money);
    

    IBuzzer * mBuzzer;
    IMotor * mMotor;
    ILock * mLock;
    ISoap * mSoap;
    ITemperature * mTemperature;
    IWater * mWater;
    CoinWallet * mCoinWallet;
    ProgramSettings * mProgramSettings;
    unsigned long t;
};

#endif
