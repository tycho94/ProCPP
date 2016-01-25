#define OUT_GROUP2      0
#define OUT_GROUP1      1
#define OUT_STROBE      2
#define OUT_KEYSELECT   3
#define OUT_BUZZER      4
#define OUT_HEATER      5
#define OUT_SPEED2      6
#define OUT_SPEED1      7
#define OUT_DATAC       8
#define OUT_DATAB       9
#define OUT_DATAA       10
#define OUT_MOTOR_RL    11
#define OUT_SOAP1       12
#define OUT_SINK        13
#define OUT_DRAIN       14
#define OUT_LOCK        15
#define IN_W2           16
#define IN_W1           17
#define IN_T2           18
#define IN_T1           19
#define IN_IN3          20
#define IN_IN2          21
#define IN_IN1          22
#define IN_IN0          23

HardwareControl::HardwareControl()
{
  Wire.begin(); // start I2C
  centipede.initialize(); // set all registers to default
  for (int i = 0; i <= 15; i++)
  {
    centipede.pinMode(i, OUTPUT);
  }
  centipede.digitalWrite(OUT_GROUP2, LOW);
  centipede.digitalWrite(OUT_GROUP1, LOW);
  centipede.digitalWrite(OUT_STROBE, LOW);
  centipede.digitalWrite(OUT_KEYSELECT, HIGH);
  centipede.digitalWrite(OUT_BUZZER, HIGH);
  centipede.digitalWrite(OUT_HEATER, HIGH);
  centipede.digitalWrite(OUT_SPEED2, HIGH);
  centipede.digitalWrite(OUT_SPEED1, HIGH);
  centipede.digitalWrite(OUT_DATAC, LOW);
  centipede.digitalWrite(OUT_DATAB, LOW);
  centipede.digitalWrite(OUT_DATAA, LOW);
  centipede.digitalWrite(OUT_MOTOR_RL, LOW);
  centipede.digitalWrite(OUT_SOAP1, LOW);
  centipede.digitalWrite(OUT_SINK, LOW);
  centipede.digitalWrite(OUT_DRAIN, LOW);
  centipede.digitalWrite(OUT_LOCK, LOW);
}


//getting buttons

bool HardwareControl::GetCoin10Button() {
  //set keyselect to 1(buttons)
  this->SetKeySelect(1);
  //check if coin 10 is clicked, since clear also clicks coin 10 + 50 + 200 check if btn 50,200 low
  return (centipede.digitalRead(IN_IN3) == HIGH && centipede.digitalRead(IN_IN2) == LOW && centipede.digitalRead(IN_IN1) == LOW);
}

bool HardwareControl::GetCoin50Button() {
  //set keyselect to 1(buttons)
  this->SetKeySelect(1);
  //check if coin 50 is clicked, since clear also clicks coin 10 + 50 + 200 check if btn 10,200 are low
  return (centipede.digitalRead(IN_IN2) == HIGH && centipede.digitalRead(IN_IN1) == LOW && centipede.digitalRead(IN_IN3) == LOW);
}

bool HardwareControl::GetCoin200Button() {
  //set keyselect to 1(buttons)
  this->SetKeySelect(1);
  //check if coin 200 is clicked, since clear also clicks coin 10 + 50 + 200 check if btn 10,50 are low
  return (centipede.digitalRead(IN_IN1) == HIGH && centipede.digitalRead(IN_IN2) == LOW && centipede.digitalRead(IN_IN3) == LOW);
}

bool HardwareControl::GetProgramButton() {
  //set keyselect to 1(buttons)
  this->SetKeySelect(1);
  //check if start is high and coin10 is high, this happens when programbutton is clicked
  return ((centipede.digitalRead(IN_IN0) == HIGH) &&
          (centipede.digitalRead(IN_IN3) == HIGH));

}

bool HardwareControl::GetCoinClearButton() {
  //set keyselect to 1(buttons)
  this->SetKeySelect(1);
  //check if button10,50,200 are pressed(this is the result of pressing coinclear)
  return ((centipede.digitalRead(IN_IN1) == HIGH) && (centipede.digitalRead(IN_IN2) == HIGH) && (centipede.digitalRead(IN_IN3) == HIGH));

}
bool HardwareControl::GetStartButton() {
  //set keyselect to 1(buttons)
  this->SetKeySelect(1);
  //check if start is high and coin10 is low - see program
  return (centipede.digitalRead(IN_IN0) == HIGH &&
          centipede.digitalRead(IN_IN3) == LOW);
}

//get switches

bool HardwareControl::GetPressureSwitch() {
  //set keyselect to 0(switches)
  this->SetKeySelect(0);
  //return pressure switch state
  return (centipede.digitalRead(IN_IN0) == HIGH);
}

bool HardwareControl::GetLockSwitch() {
  //set keyselect to 0(switches)
  this->SetKeySelect(0);
  return (centipede.digitalRead(IN_IN3) == HIGH);
}

bool HardwareControl::GetSoap1Switch() {
  //set keyselect to 0(switches)
  this->SetKeySelect(0);
  return (centipede.digitalRead(IN_IN1) == HIGH);
}

bool HardwareControl::GetSoap2Switch() {
  //set keyselect to 0(switches)
  this->SetKeySelect(0);
  return (centipede.digitalRead(IN_IN2) == HIGH);
}

//return waterLevel
int HardwareControl::GetWaterlevel()
{
  int waterLevel;

  if (centipede.digitalRead(IN_W2) == LOW && centipede.digitalRead(IN_W1) == LOW)
    waterLevel = 0;
  if (centipede.digitalRead(IN_W2) == LOW && centipede.digitalRead(IN_W1) == HIGH)
    waterLevel = 1;
  if (centipede.digitalRead(IN_W2) == HIGH && centipede.digitalRead(IN_W1) == LOW)
    waterLevel = 2;
  if (centipede.digitalRead(IN_W2) == HIGH && centipede.digitalRead(IN_W1) == HIGH)
    waterLevel = 3;

  return waterLevel;
}

//returning values

//retur temperature, 0 = cold, 1 = less cold, 2 = medium, 3 = hot
int HardwareControl::GetTemperature() {
  int temperature = 0;

  if (centipede.digitalRead(IN_T2) == LOW && centipede.digitalRead(IN_T1) == LOW)
    temperature = 0;
  if (centipede.digitalRead(IN_T2) == LOW && centipede.digitalRead(IN_T1) == HIGH)
    temperature = 1;
  if (centipede.digitalRead(IN_T2) == HIGH && centipede.digitalRead(IN_T1) == LOW)
    temperature = 2;
  if (centipede.digitalRead(IN_T2) == HIGH && centipede.digitalRead(IN_T1) == HIGH)
    temperature = 3;

  return temperature;
}

// setting outputs

//set the coin50 leds to 0, 1, 2 or 3
void HardwareControl::SetCoin10(int leds)
{
  //set group to 1
  SetGroup(1);
  if (leds <= 0) {
    SetData(0);
  }
  else if (leds == 1) {
    SetData(1);
    SetDataOff(2);
    SetDataOff(3);
  }
  else if (leds == 2) {
    SetData(1);
    SetData(2);
    SetDataOff(3);
  }
  else if (leds == 3) {
    SetData(1);
    SetData(2);
    SetData(3);
  }
}

//set the coin50 leds to 0, 1, 2 or 3
void HardwareControl::SetCoin50(int leds)
{
  //set group to 2
  SetGroup(2);
  if (leds <= 0) {
    SetData(0);
  }
  else if (leds == 1) {
    SetData(1);
    SetDataOff(2);
    SetDataOff(3);
  }
  else if (leds == 2) {
    SetData(1);
    SetData(2);
    SetDataOff(3);
  }
  else if (leds == 3) {
    SetData(1);
    SetData(2);
    SetData(3);
  }
}

//set coin200 leds to 0, 1 or 2
void HardwareControl::SetCoin200(int leds)
{
  //set group to 3
  SetGroup(3);
  if (leds <= 0) {
    //turn off data seperatly so that soap2 led isnt influenced
    SetDataOff(1);
    SetDataOff(2);
    SetDataOff(3);
  }
  else {
    if (leds == 1) {
      SetData(1);
      SetDataOff(2);
      SetDataOff(3);
    }
    else if (leds == 2) {
      SetData(1);
      SetData(2);
      SetDataOff(3);
    }
  }
}

//set the buzzer to true or false, 0 or 1
void HardwareControl::SetBuzzer(bool level)
{
  centipede.digitalWrite(OUT_BUZZER, !level);
}

//set the lock led to on or off, 0 or 1
void HardwareControl::SetLock(bool level)
{
  centipede.digitalWrite(OUT_LOCK, level);
}

//sets soap one to high or low, 0 or 1
void HardwareControl::SetSoap1(bool level)
{
  centipede.digitalWrite(OUT_SOAP1, level);
}

//set soap2 led, 0 off, 1 on
void HardwareControl::SetSoap2(bool level)
{
  //set group to 3
  //if level is 0 or lower the led is off else its high
  SetGroup(3);
  if (level <= 0)
    SetDataOff(3);
  else
    SetData(3);
}

//set waterlevel to 0 emtpy, 1 33%, 2 66%, 3 filled, -1 is constant draining
void HardwareControl::SetWaterlevel(int wantedWaterlevel)
{
  if (wantedWaterlevel < 0)
  {
    centipede.digitalWrite(OUT_SINK, HIGH);
    centipede.digitalWrite(OUT_DRAIN, LOW);
    return;
  }

  while (wantedWaterlevel != GetWaterlevel())
  {
    if (wantedWaterlevel < GetWaterlevel())
    {
      centipede.digitalWrite(OUT_SINK, HIGH);
      centipede.digitalWrite(OUT_DRAIN, LOW);
    }

    else if (wantedWaterlevel > GetWaterlevel())
    {
      centipede.digitalWrite(OUT_SINK, LOW);
      if (GetPressureSwitch()) {
        centipede.digitalWrite(OUT_DRAIN, HIGH);
      }
    }
  }
  if (wantedWaterlevel == GetWaterlevel())
  {
    centipede.digitalWrite(OUT_SINK, LOW);
    centipede.digitalWrite(OUT_DRAIN, LOW);
  }
}
//set speed to off, slow, medium or high respectivly to 0, 1, 2, 3
void HardwareControl::SetMotor(int speedlevel)
{
  if (speedlevel == 0)
  {
    centipede.digitalWrite(OUT_SPEED2, HIGH);
    centipede.digitalWrite(OUT_SPEED1, HIGH);
  }
  else if (speedlevel == 1)
  {
    centipede.digitalWrite(OUT_SPEED2, HIGH);
    centipede.digitalWrite(OUT_SPEED1, LOW);
  }
  else if (speedlevel == 2)
  {
    centipede.digitalWrite(OUT_SPEED2, LOW);
    centipede.digitalWrite(OUT_SPEED1, HIGH);
  }
  else if (speedlevel == 3)
  {
    centipede.digitalWrite(OUT_SPEED2, LOW);
    centipede.digitalWrite(OUT_SPEED1, LOW);
  }
}

//set the heater to keep temp at certain value, 0 = cold, 1 = less cold, 2 = medium, 3 = hot
void HardwareControl::SetTemperature(int level)
{
  if (GetTemperature() >= level)
    centipede.digitalWrite(OUT_HEATER, HIGH);
  else
    centipede.digitalWrite(OUT_HEATER, LOW);

}

//set dir, 0 is left, 1 is right
void HardwareControl::SetDirection(bool dir)
{
  centipede.digitalWrite(OUT_MOTOR_RL, dir);
}

//set the program led
void HardwareControl::SetProgramIndicator(Program program)
{
  SetGroup(4);
  if (program == PROGRAM_A)
  {
    SetData(1);
    SetDataOff(2);
    SetDataOff(3);
  }
  if (program == PROGRAM_B)
  {
    SetDataOff(1);
    SetData(2);
    SetDataOff(3);
  }
  if (program == PROGRAM_C)
  {
    SetDataOff(1);
    SetDataOff(2);
    SetData(3);
  }

}

// private sets - used by gets/sets

//set keyselct to true or false
void HardwareControl::SetKeySelect(int value)
{
  centipede.digitalWrite(OUT_KEYSELECT, value);
}

//group 1 = 00, group 2 = 01, group 3 = 10, group 4 = 11
void HardwareControl::SetGroup(int group)
{
  Strobe();
  if (group == 1)
  {
    centipede.digitalWrite(OUT_GROUP2, LOW);
    centipede.digitalWrite(OUT_GROUP1, LOW); //00
  }
  if (group == 2)
  {
    centipede.digitalWrite(OUT_GROUP2, LOW);
    centipede.digitalWrite(OUT_GROUP1, HIGH);  //01
  }
  if (group == 3)
  {
    centipede.digitalWrite(OUT_GROUP2, HIGH);
    centipede.digitalWrite(OUT_GROUP1, LOW); //10
  }
  if (group == 4)
  {
    centipede.digitalWrite(OUT_GROUP2, HIGH);
    centipede.digitalWrite(OUT_GROUP1, HIGH); //11
  }
}

//set data to 0 = all off, 1 DATA_A, 2 DATA_B, 3 DATA_C
void HardwareControl::SetData(int data)
{
  Strobe();
  if (data == 0) {
    centipede.digitalWrite(OUT_DATAA, LOW);
    centipede.digitalWrite(OUT_DATAB, LOW);
    centipede.digitalWrite(OUT_DATAC, LOW);
  }
  if (data == 1) {
    centipede.digitalWrite(OUT_DATAA, HIGH);
  }
  if (data == 2) {
    centipede.digitalWrite(OUT_DATAB, HIGH);
  }
  if (data == 3) {
    centipede.digitalWrite(OUT_DATAC, HIGH);
  }
}

//turn off data registries seperatly, 1=a, 2=b, 3=c
void HardwareControl::SetDataOff(int data)
{
  Strobe();
  if (data == 1) {
    centipede.digitalWrite(OUT_DATAA, LOW);
  }
  if (data == 2) {
    centipede.digitalWrite(OUT_DATAB, LOW);
  }
  if (data == 3) {
    centipede.digitalWrite(OUT_DATAC, LOW);
  }
}

//strobe method so we can use the centipede groups/data writing
void HardwareControl::Strobe()
{
  centipede.digitalWrite(OUT_STROBE, LOW);
  delay(80);
  centipede.digitalWrite(OUT_STROBE, HIGH);
  delay(10);
  centipede.digitalWrite(OUT_STROBE, LOW);
}

// Retuns the amount of money each program requires (check the gdocs)
bool HardwareControl::GetProgramMoney(Program program) {
  if (program == PROGRAM_A) {
    return 360;
  } else if (program == PROGRAM_B) {
    return 480;
  } else if (program == PROGRAM_C) {
    return 510;
  } else {
    // error
    return -1;
  }
}
