
#include "ProgramExecutor.h"

//time values, easily editable for all cases
#define WASH_TIME 7000
#define CENT_TIME 3500

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
  preWashA();
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
  mMotor->SetDirection(COUNTERCLOCK);
  mMotor->SetMotor(MOTOR_REGULAR);
  looptime = millis() + WASH_TIME;
  while (looptime > millis()) {
    mTemperature->SetTemperature(MEDIUM);
  }

  // drain water & turn off moter & set heater off
  mMotor->SetMotor(MOTOR_OFF);
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
    mMotor->SetDirection(CLOCK);
    mMotor->SetMotor(MOTOR_REGULAR);

    looptime = millis() + WASH_TIME;
    while (looptime > millis()) {
      mTemperature->SetTemperature(MEDIUM);
    }
    // rotate counterclockwise, at regular speed for 1 minute
    mMotor->SetDirection(COUNTERCLOCK);
    looptime = millis() + WASH_TIME;
    while (looptime > millis()) {
      mTemperature->SetTemperature(MEDIUM);
    }
  }
  // drain water & turn off moter & set heater off
  mMotor->SetMotor(MOTOR_OFF);
  mTemperature->SetTemperature(COLD);
  mWater->SetWaterlevel(WATER_0_PERCENT);

  //===================== RINSE ========================
  // fill 50% with water
  mWater->SetWaterlevel(WATER_50_PERCENT);
  for (int i = 0; i < 2; i++)
  {
    // rotate clockwise, at regular speed for 1 minute
    mMotor->SetDirection(CLOCK);
    mMotor->SetMotor(MOTOR_REGULAR);
    looptime = millis() + WASH_TIME;
    while (looptime > millis()) {
    }
    // rotate counterclockwise, at regular speed for 1 minute
    mMotor->SetDirection(COUNTERCLOCK);
    looptime = millis() + WASH_TIME;
    while (looptime > millis()) {
    }
  }
  // drain water and turn off motor
  mMotor->SetMotor(MOTOR_OFF);
  mWater->SetWaterlevel(WATER_0_PERCENT);

  //===================== DRY ==========================
  // keep draining the water
  mWater->SetWaterlevel(WATER_CONST);
  for (int i = 0; i < 2; i++)
  {
    // rotate clockwise, at regular speed for 30s
    mMotor->SetDirection(CLOCK);
    mMotor->SetMotor(MOTOR_HIGH);
    looptime = millis() + CENT_TIME;
    while (looptime > millis()) {
    }
    // rotate counterclockwise, at regular speed for 30s
    mMotor->SetDirection(COUNTERCLOCK);
    looptime = millis() + CENT_TIME;
    while (looptime > millis()) {
    }
  }
  //drain and motor off
  mMotor->SetMotor(MOTOR_OFF);
  mWater->SetWaterlevel(WATER_0_PERCENT);
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

  looptime = millis() + WASH_TIME;
  mMotor->SetDirection(COUNTERCLOCK);
  while (looptime > millis()) {
  }
  // drain
  mMotor->SetMotor(MOTOR_OFF);
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
    mMotor->SetMotor(MOTOR_REGULAR);
    mMotor->SetDirection(CLOCK);
    looptime = millis() + WASH_TIME;
    while (looptime > millis()) {
      mTemperature->SetTemperature(HOT);
    }
    // rotate counterclockwise, at regular speed for 1 minute
    mMotor->SetDirection(COUNTERCLOCK);
    looptime = millis() + WASH_TIME;
    while (looptime > millis()) {
      mTemperature->SetTemperature(HOT);
    }
  }

  // drain water
  mMotor->SetMotor(MOTOR_OFF);
  mTemperature->SetTemperature(COLD);
  mWater->SetWaterlevel(WATER_0_PERCENT);
  //===================== RINSE ========================
  // fill 50% with water
  mWater->SetWaterlevel(WATER_50_PERCENT);
  for (int i = 0; i < 4; i++)
  {
    // rotate clockwise, at regular speed for 1 minute
    mMotor->SetMotor(MOTOR_REGULAR);
    mMotor->SetDirection(CLOCK);
    looptime = millis() + WASH_TIME;
    while (looptime > millis()) {
    }
    // rotate counterclockwise, at regular speed for 1 minute
    mMotor->SetDirection(COUNTERCLOCK);
    looptime = millis() + WASH_TIME;
    while (looptime > millis()) {
    }
  }
  // drain water
  mMotor->SetMotor(MOTOR_OFF);
  mWater->SetWaterlevel(WATER_0_PERCENT);

  //===================== DRY ==========================
  // keep draining the water
  mWater->SetWaterlevel(WATER_CONST);
  for (int i = 0; i < 3; i++)
  {
    // rotate clockwise, at regular speed for 30s
    mMotor->SetDirection(CLOCK);
    mMotor->SetMotor(MOTOR_HIGH);
    looptime = millis() + CENT_TIME;
    while (looptime > millis()) {
    }
    // rotate counterclockwise, at regular speed for 30s
    mMotor->SetDirection(COUNTERCLOCK);
    looptime = millis() + CENT_TIME;
    while (looptime > millis()) {
    }
  }
  mMotor->SetMotor(MOTOR_OFF);
  mWater->SetWaterlevel(WATER_0_PERCENT);
}

void ProgramExecutor::unlock() {
  mLock->SetLock(false);
}
