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
#include "ProgramSelect.h"
#include "ProgramSettings.h"
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
static ProgramSelect *mProgramSelect;
static ProgramSettings *mProgramSettings;
static ProgramExecutor *mProgramExecutor;

int requiredMoney = 0;
Program selectedProgram = NO_PROGRAM;

void setup()
{
  Serial.begin(9600);
  Serial.println("start");
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

  mProgramExecutor->mainWashAB();
}

void loop()
{/*
  // select a program without going out of boundary
  if (mProgram->GetProgramButton()) {
    // cast the int to a program enum without going out of bounds
    selectedProgram = (Program) ((selectedProgram + 1) % 3);
  }

  // check if there is enough money and the program is selected
  requiredMoney = mProgram->GetProgramMoney(selectedProgram);
  if (requiredMoney) {
    if (mCoinWallet->Withdraw(requiredMoney)) {
      // start the program!
      mProgramExecutor->Start(selectedProgram);
    }
  }
*/}
