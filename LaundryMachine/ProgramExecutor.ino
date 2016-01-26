
#include "ProgramExecutor.h"

//time values, easily editable for all cases
#define WASH_TIME 5000
#define CENT_TIME 2500

ProgramExecutor::ProgramExecutor(IBuzzer * b, IMotor * m, ILock * l, ISoap * s, ITemperature * t, IWater * w, CoinWallet * c)
{
  mBuzzer = b;
  mMotor = m;
  mLock = l;
  mSoap = s;
  mTemperature = t;
  mWater = w;
  mCoinWallet = c;
  looptime = 0;
}

bool ProgramExecutor::Start(Program program)
{
  if (program == PROGRAM_A) {
    programA();
  } else if (program == PROGRAM_B) {
    programB();
  } else if (program == PROGRAM_C) {
    programC();
  } else {
    return -1;
  }
}

// IMPLEMENT PROG A
void ProgramExecutor::programA() {
  //preWashA();
  mainWashAB();
  unlock();
}

// IMPLEMENT PROG B
void ProgramExecutor::programB() {
  preWashBC();
  mainWashAB();
  unlock();
}

// IMPLEMENT PROG C
void ProgramExecutor::programC() {
  preWashBC();
  mainWashC();
  unlock();
}



void ProgramExecutor::preWashA() {
  // fill 50% of water
  mWater->SetWaterlevel(WATER_50_PERCENT);
  // add soap1
  mSoap->SetSoap1(false);
  //

  mMotor->SetDirection(CLOCK);
  mMotor->SetMotor(MOTOR_REGULAR);

  looptime = millis() + WASH_TIME;
  while (looptime > millis()) {
  }
  StopMotor(true);
  mMotor->SetDirection(COUNTERCLOCK);
  mMotor->SetMotor(MOTOR_REGULAR);
  looptime = millis() + WASH_TIME;
  while (looptime > millis()) {
  }
  // drain
  StopMotor(false);
  mWater->SetWaterlevel(WATER_0_PERCENT);
}

void ProgramExecutor::preWashBC() {
  // fill 50% with water
  mWater->SetWaterlevel(WATER_50_PERCENT);
  // heat to 50%
  while (!(mTemperature->GetTemperature() == MEDIUM)) {
    mTemperature->SetTemperature(MEDIUM);
  }
  // add soap1
  mSoap->SetSoap1(false);
  // rotate clockwise, at regular speed for 1 minute
  mMotor->SetDirection(CLOCK);
  mMotor->SetMotor(MOTOR_REGULAR);

  looptime = millis() + WASH_TIME;
  while (looptime > millis()) {
    mTemperature->SetTemperature(MEDIUM);
  }
  // rotate counterclockwise, at regular speed for 1 minute
  StopMotor(true);
  mMotor->SetDirection(COUNTERCLOCK);
  mMotor->SetMotor(MOTOR_REGULAR);
  looptime = millis() + WASH_TIME;
  while (looptime > millis()) {
    mTemperature->SetTemperature(MEDIUM);
  }

  // drain water & turn off moter & set heater off
  StopMotor(false);
  mTemperature->SetTemperature(COLD);
  mWater->SetWaterlevel(WATER_0_PERCENT);
}


void ProgramExecutor::mainWashAB() {
  
    //===================== WASH =========================
    // fill 50% with water
    mWater->SetWaterlevel(WATER_50_PERCENT);
    // heat to 50%
    while (!(mTemperature->GetTemperature() == MEDIUM)) {
      mTemperature->SetTemperature(MEDIUM);
    }
    // add soap2
    mSoap->SetSoap2(false);
    for (int i = 0; i < 2; i++)
    {
      // rotate clockwise, at regular speed for 1 minute
      StopMotor(true);
      mMotor->SetDirection(CLOCK);
      mMotor->SetMotor(MOTOR_REGULAR);

      looptime = millis() + WASH_TIME;
      while (looptime > millis()) {
        mTemperature->SetTemperature(MEDIUM);
      }
      // rotate counterclockwise, at regular speed for 1 minute
      StopMotor(true);
      mMotor->SetDirection(COUNTERCLOCK);
      mMotor->SetMotor(MOTOR_REGULAR);
      looptime = millis() + WASH_TIME;
      while (looptime > millis()) {
        mTemperature->SetTemperature(MEDIUM);
      }
    }
    // drain water & turn off moter & set heater off
    StopMotor(false);
    mTemperature->SetTemperature(COLD);
    mWater->SetWaterlevel(WATER_0_PERCENT);

    //===================== RINSE ========================
    // fill 50% with water
    mWater->SetWaterlevel(WATER_50_PERCENT);
    for (int i = 0; i < 2; i++)
    {
      // rotate clockwise, at regular speed for 1 minute
      StopMotor(true);
      mMotor->SetDirection(CLOCK);
      mMotor->SetMotor(MOTOR_REGULAR);
      looptime = millis() + WASH_TIME;
      while (looptime > millis()) {
      }
      // rotate counterclockwise, at regular speed for 1 minute
      StopMotor(true);
      mMotor->SetDirection(COUNTERCLOCK);
      mMotor->SetMotor(MOTOR_REGULAR);
      looptime = millis() + WASH_TIME;
      while (looptime > millis()) {
      }
    }
    // drain water and turn off motor
    StopMotor(false);
    mWater->SetWaterlevel(WATER_0_PERCENT);
  
  //===================== DRY ==========================
  // keep draining the water
  mWater->SetWaterlevel(WATER_CONST);
  for (int i = 0; i < 2; i++)
  {
    // rotate clockwise, at regular speed for 30s
    StopMotor(true);
    mMotor->SetDirection(CLOCK);
    mMotor->SetMotor(MOTOR_HIGH);
    looptime = millis() + CENT_TIME;
    while (looptime > millis()) {
    }
    // rotate counterclockwise, at regular speed for 30s
    StopMotor(true);
    mMotor->SetDirection(COUNTERCLOCK);
    mMotor->SetMotor(MOTOR_HIGH);
    looptime = millis() + CENT_TIME;
    while (looptime > millis()) {
    }
  }
  //drain and motor off
  StopMotor(false);
  mWater->SetWaterlevel(WATER_0_PERCENT);
}

void ProgramExecutor::mainWashC() {
  int i;
  //===================== WASH =========================
  // fill 100% with water
  mWater->SetWaterlevel(WATER_100_PERCENT);
  // heat to 100%
  while (!(mTemperature->GetTemperature() == HOT)) {
    mTemperature->SetTemperature(HOT);
  }
  // add soap2
  mSoap->SetSoap2(false);
  for (int i = 0; i < 4; i++)
  {
    // rotate clockwise, at regular speed for 1 minute
    StopMotor(true);
    mMotor->SetMotor(MOTOR_REGULAR);
    mMotor->SetDirection(CLOCK);
    looptime = millis() + WASH_TIME;
    while (looptime > millis()) {
      mTemperature->SetTemperature(HOT);
    }
    // rotate counterclockwise, at regular speed for 1 minute
    StopMotor(true);
    mMotor->SetDirection(COUNTERCLOCK);
    mMotor->SetMotor(MOTOR_REGULAR);
    looptime = millis() + WASH_TIME;
    while (looptime > millis()) {
      mTemperature->SetTemperature(HOT);
    }
  }

  // drain water
  StopMotor(false);
  mTemperature->SetTemperature(COLD);
  mWater->SetWaterlevel(WATER_0_PERCENT);
  //===================== RINSE ========================
  // fill 50% with water
  mWater->SetWaterlevel(WATER_50_PERCENT);
  for (int i = 0; i < 4; i++)
  {
    // rotate clockwise, at regular speed for 1 minute
    StopMotor(true);
    mMotor->SetDirection(CLOCK);
    mMotor->SetMotor(MOTOR_REGULAR);
    looptime = millis() + WASH_TIME;
    while (looptime > millis()) {
    }
    // rotate counterclockwise, at regular speed for 1 minute
    StopMotor(true);
    mMotor->SetDirection(COUNTERCLOCK);
    mMotor->SetMotor(MOTOR_REGULAR);
    looptime = millis() + WASH_TIME;
    while (looptime > millis()) {
    }
  }
  // drain water
  StopMotor(false);
  mWater->SetWaterlevel(WATER_0_PERCENT);

  //===================== DRY ==========================
  // keep draining the water
  mWater->SetWaterlevel(WATER_CONST);
  for (int i = 0; i < 3; i++)
  {
    // rotate clockwise, at regular speed for 30s
    StopMotor(true);
    mMotor->SetDirection(CLOCK);
    mMotor->SetMotor(MOTOR_HIGH);
    looptime = millis() + CENT_TIME;
    while (looptime > millis()) {
    }
    // rotate counterclockwise, at regular speed for 30s
    StopMotor(true);
    mMotor->SetDirection(COUNTERCLOCK);
    mMotor->SetMotor(MOTOR_HIGH);
    looptime = millis() + CENT_TIME;
    while (looptime > millis()) {
    }
  }
  StopMotor(false);
  mWater->SetWaterlevel(WATER_0_PERCENT);
}

void ProgramExecutor::unlock() {
  mLock->SetLock(false);
}

void ProgramExecutor::StopMotor(bool turn) {
  if (mMotor->GetMotor() == MOTOR_OFF)
    return;

  if (mMotor->GetMotor() == MOTOR_LOW) {
    looptime = millis() + 900;
    while (looptime > millis()) {
    }
    mMotor->SetMotor(MOTOR_OFF);
    if (turn) {
      looptime = millis() + 400;
      while (looptime > millis()) {
      }
    }
    return;
  }
  if (mMotor->GetMotor() == MOTOR_REGULAR) {
    looptime = millis() + 1300;
    mMotor->SetMotor(MOTOR_LOW);
    while (looptime > millis()) {
    }
    mMotor->SetMotor(MOTOR_OFF);
    if (turn) {
      looptime = millis() + 400;
      while (looptime > millis()) {
      }
    }
    return;
  }
  if (mMotor->GetMotor() == MOTOR_HIGH) {
    looptime = millis() + 2000;
    int slow = millis() + 850;
    mMotor->SetMotor(MOTOR_REGULAR);
    while (looptime > millis()) {
      if (slow < millis())
        mMotor->SetMotor(MOTOR_LOW);
    }
  }
  mMotor->SetMotor(MOTOR_OFF);
  if (turn) {
    looptime = millis() + 400;
    while (looptime > millis()) {
    }
  }
  return;
}

