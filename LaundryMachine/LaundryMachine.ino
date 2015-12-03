#include <Wire.h>
#include <Centipede.h>

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


static HardwareControl * mControl;
static IBuzzer * mBuzzer;
static ICoin * mCoin;
static IMotor * mMotor;
static ILock * mLock;
static IProgram * mProgram;
static ISoap * mSoap;
static ITemperature * mTemperature;
static IWater * mWater;
static CoinWallet * mCoinWallet;
static ProgramSelect * mProgramSelect;
static ProgramSettings * mProgramSettings;
static ProgramExecutor * mProgramExecutor;

void setup()
{
  Serial.begin(9600);
  Serial.println("start");
  mControl = new HardwareControl();
  mBuzzer = new HardwareControl();
  mCoin = new HardwareControl();
  mCoinWallet = new CoinWallet(mCoin);
}

void loop()
{
  //TestBuzzer();
  //TestCoinWallet();
  TestFunctions();
}

void TestCoinWallet()
{
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
    Serial.print("return: ");
    Serial.println(mCoinWallet->Clear());
    Serial.println();
  }
}

void TestBuzzer() {
  mBuzzer->SetBuzzer(0);
}

void TestFunctions() {
  if (mControl->GetSoap2Switch()) {
    mControl->SetSoap2(1);
    mControl->SetMotor(3);
  }
  else {
    mControl->SetSoap2(0);
  }

  if (mControl->GetSoap1Switch()) {
    mControl->SetSoap1(2);
    mControl->SetMotor(2);
  }
  else {
    mControl->SetSoap1(0);
  }



  if (mControl->GetLockSwitch()) {
    mControl->SetLock(1);
    mControl->SetMotor(1);
  }
  else {
    mControl->SetLock(0);
  }


  if (mControl->GetPressureSwitch()) {

    mControl->SetMotor(0);

  }

  mControl->SetWaterlevel(2);
  mControl->SetHeater(2);
}

