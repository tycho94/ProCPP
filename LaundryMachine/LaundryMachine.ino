#include <Wire.h>
#include "Centipede.h"

#include "IBuzzer.h"
#include "ICoin.h"
#include "ILock.h"
#include "IMotor.h"
#include "IProgram.h"
#include "ISoap.h"
#include "ITemperature.h"
#include "IWater.h"

#include "HardwareControl.h"
#include "CoinWallet.h"
#include "ProgramExecutor.h"

//interfaces
static IBuzzer * mBuzzer;
static ICoin * mCoin;
static IMotor * mMotor;
static ILock * mLock;
static IProgram * mProgram;
static ISoap * mSoap;
static ITemperature * mTemperature;
static IWater * mWater;

//classes
static CoinWallet *mCoinWallet;
static HardwareControl *mControl;
static ProgramExecutor *mProgramExecutor;

Program selectedProgram;

void setup()
{
  // interfaces
  mBuzzer = new HardwareControl();
  mCoin = new HardwareControl();
  mMotor = new HardwareControl();
  mLock = new HardwareControl();
  mProgram = new HardwareControl();
  mSoap = new HardwareControl();
  mTemperature = new HardwareControl();
  mWater = new HardwareControl();

  //classes
  mCoinWallet = new CoinWallet(mCoin);
  mControl = new HardwareControl();
  mProgramExecutor = new ProgramExecutor(mBuzzer,
                                         mMotor,
                                         mLock,
                                         mSoap,
                                         mTemperature,
                                         mWater,
                                         mCoinWallet);
  selectedProgram = PROGRAM_A;
}

void loop()
{
  ButtonState();
  SwitchState();
  mProgramExecutor->Start(selectedProgram);
  mBuzzer->Buzz();
}

void ButtonState() {
  mProgram->SetProgramIndicator(selectedProgram);
  while (true) {
    if (mProgram->GetProgramButton()) {
      selectedProgram = (Program) ((selectedProgram + 1) % 3);
      mProgram->SetProgramIndicator(selectedProgram);
    }
    if (mCoin->GetCoin10Button()) {
      mCoinWallet->Deposit(10);
    }
    if (mCoin->GetCoin50Button()) {
      mCoinWallet->Deposit(50);
    }
    if (mCoin->GetCoin200Button()) {
      mCoinWallet->Deposit(200);
    }
    if (mCoin->GetCoinClearButton())
    {
      mCoinWallet->Clear();
    }

    if (mProgram->GetStartButton()
        && selectedProgram != NO_PROGRAM
        && mCoinWallet->Withdraw(mProgram->GetProgramMoney(selectedProgram))) {
      mBuzzer->Buzz();
      break;
    }
  }
}

void SwitchState() {
  while (true) {
    if (mSoap->GetSoap1Switch())
      mSoap->SetSoap1(true);
    else
      mSoap->SetSoap1(false);

    if (mSoap->GetSoap2Switch())
      mSoap->SetSoap2(true);
    else
      mSoap->SetSoap2(false);

    if (mLock->GetLockSwitch())
      mLock->SetLock(true);
    else
      mLock->SetLock(false);

    if ( mSoap->GetSoap1Switch() &&
         mSoap->GetSoap2Switch() &&
         mLock->GetLockSwitch()) {
      if (mProgram->GetStartButton()) {
        mCoinWallet->Clear();
        mBuzzer->Buzz();
        break;
      }
    }
  }
}
