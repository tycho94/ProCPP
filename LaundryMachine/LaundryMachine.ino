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
  mControl = new HardwareControl();
  Serial.begin(9600);
  Serial.println("start");

}

void loop()
{
  Test1();
}

void Test1()
{ 
  if (mControl->GetCoin10Button())
    mControl->SetCoin10(3);
  if (mControl->GetCoin50Button())
    mControl->SetCoin50(3);
  if (mControl->GetCoin200Button())
    mControl->SetCoin200(2);



  if (mControl->GetCoinClearButton())
  {
    mControl->SetCoin10(0);
    mControl->SetCoin50(0);
    mControl->SetCoin200(0);
  }

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
    mControl->SetDrain(1);
    mControl->SetSink(1);
    mControl->SetMotor(0);
  }
  else {
    mControl->SetDrain(0);
    mControl->SetSink(0);
  }
}

