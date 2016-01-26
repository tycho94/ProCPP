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

class ProgramExecutor
{
  public:
    ProgramExecutor(IBuzzer *, IMotor *, ILock *, ISoap *, ITemperature *, IWater *, CoinWallet *);
    bool Start(Program program);

  private:
    void programA();
    void programB();
    void programC();
    void preWashBC();
    void mainWashAB();
    void preWashA();
    void mainWashC();
    void unlock();
    void StopMotor(bool turn);

    IBuzzer * mBuzzer;
    IMotor * mMotor;
    ILock * mLock;
    ISoap * mSoap;
    ITemperature * mTemperature;
    IWater * mWater;
    CoinWallet * mCoinWallet;
    unsigned long looptime;
};

#endif
