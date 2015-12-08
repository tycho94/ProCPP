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
static CoinWallet * mCoinWallet;
static HardwareControl * mControl;
static ProgramSelect * mProgramSelect;
static ProgramSettings * mProgramSettings;
static ProgramExecutor * mProgramExecutor;

void setup()
{
  Serial.begin(9600);
  Serial.println("start");
  //interface = new hardwarecontrol();
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
}

void loop()
{
  //TestBuzzer();
  //TestButtons();
  //TestFunctions();
  TestWater();
}


void TestWater()
{
  if (mWater->GetPressureSwitch()) {
    mWater->SetWaterlevel(WATER_66_PERCENT);
  }
  else {
    mWater->SetWaterlevel(WATER_0_PERCENT);
  }
  
}

void TestButtons()
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

  static int i = 1;
  if (mProgram->GetProgramButton())
  {
    mProgram->SetProgramIndicator(i);
    i++;
  }
  if (i > 3)
    i = 1;
}

void TestBuzzer() {
  mBuzzer->SetBuzzer(1);
}

void TestFunctions() {
  if (mControl->GetSoap2Switch()) {
    mSoap->SetSoap2(1);
    mControl->SetMotor(3);
  }
  else {
    mSoap->SetSoap2(0);
  }

  if (mControl->GetSoap1Switch()) {
    mSoap->SetSoap1(2);
    mControl->SetMotor(2);
  }
  else {
    mSoap->SetSoap1(0);
  }

  if (mControl->GetLockSwitch()) {
    mLock->SetLock(1);
    mControl->SetMotor(1);
  }
  else {
    mLock->SetLock(0);
  }

  if (mWater->GetPressureSwitch()) {
    mControl->SetMotor(0);
  }
  mTemperature->SetTemperature(2);
}
