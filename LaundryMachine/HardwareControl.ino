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

boolean HardwareControl::GetCoin10Button()
{
  /*
    we need this to HIGH because is the comb to acces to the buttons
    Buttons --> KeySelect HIGH
  */

  this->SetKeySelect(1);

  if (centipede.digitalRead(IN_IN3) == HIGH && centipede.digitalRead(IN_IN2) == LOW && centipede.digitalRead(IN_IN1) == LOW) {
    return (true);
  }

  return (false);
}

boolean HardwareControl::GetCoin50Button()
{
  this->SetKeySelect(1);
  delay(20);
  if (centipede.digitalRead(IN_IN2) == HIGH && centipede.digitalRead(IN_IN1) == LOW && centipede.digitalRead(IN_IN3) == LOW) {
    return (true);
  }

  return (false);
}

boolean HardwareControl::GetCoin200Button()
{
  this->SetKeySelect(1);

  if (centipede.digitalRead(IN_IN1) == HIGH && centipede.digitalRead(IN_IN2) == LOW && centipede.digitalRead(IN_IN3) == LOW) {
    return (true);
  }
  return (false);
}

boolean HardwareControl::GetCoinClearButton() {

  this->SetKeySelect(1);
  if ((centipede.digitalRead(IN_IN1) == HIGH) && (centipede.digitalRead(IN_IN2) == HIGH) && (centipede.digitalRead(IN_IN3) == HIGH)) {
    return (true);
  }
  return (false);
}
boolean HardwareControl::GetStartButton() {

  this->SetKeySelect(1);
  if (centipede.digitalRead(IN_IN0) == HIGH && centipede.digitalRead(IN_IN3) == LOW) {

    return (true);
  }
  return (false);
}

boolean HardwareControl::GetProgramButton() {

  this->SetKeySelect(1);

  if ((centipede.digitalRead(IN_IN0) == HIGH) && (centipede.digitalRead(IN_IN3) == HIGH)) {

    return (true);
  }
  return (false);
}


boolean HardwareControl::GetPressureSwitch() {

  this->SetKeySelect(0);
  if (centipede.digitalRead(IN_IN0) == HIGH) {

    return (true);
  }
  return (false);
}
boolean HardwareControl::GetLockSwitch()
{
  this->SetKeySelect(0);
  if (centipede.digitalRead(IN_IN3) == HIGH) {

    return (true);
  }
  return (false);
}
boolean HardwareControl::GetSoap1Switch()
{
  this->SetKeySelect(0);
  if (centipede.digitalRead(IN_IN1) == HIGH) {
    return (true);
  }
  return (false);
}
boolean HardwareControl::GetSoap2Switch()
{
  this->SetKeySelect(0);
  if (centipede.digitalRead(IN_IN2) == HIGH) {
    return (true);
  }
  return (false);
}

//returning values

int HardwareControl::GetTemperature()
{
  return (0);
}

// setting outputs

void HardwareControl::SetCoin10(int leds)
{
  SetGroup(1);
  if (leds <= 0)
    SetData(0);
  if (leds > 0)
    SetData(1);
  if (leds > 1)
    SetData(2);
  if (leds > 2)
    SetData(3);
}

void HardwareControl::SetCoin50(int leds)
{
  SetGroup(2);
  if (leds <= 0)
    SetData(0);
  if (leds > 0)
    SetData(1);
  if (leds > 1)
    SetData(2);
  if (leds > 2)
    SetData(3);
}

void HardwareControl::SetCoin200(int leds)
{
  SetGroup(3);
  if (leds <= 0) {
    SetDataOff(1);
    SetDataOff(2);
  }
  else {
    if (leds > 0)
      SetData(1);
    if (leds > 1)
      SetData(2);

    SetDataOff(3);
  }
}


void HardwareControl::SetSoap1(int level)
{
  if (level <= 0)
    centipede.digitalWrite(OUT_SOAP1, LOW);
  else
    centipede.digitalWrite(OUT_SOAP1, HIGH);
}

void HardwareControl::SetSoap2(int level)
{
  SetGroup(3);
  if (level <= 0)
    SetDataOff(3);
  else
    SetData(3);
}



void HardwareControl::SetDrain(int level)
{
  if (level <= 0)
    centipede.digitalWrite(OUT_DRAIN, LOW);
  else
    centipede.digitalWrite(OUT_DRAIN, HIGH);
}

void HardwareControl::SetMotor(int speedlevel)
{
  if (speedlevel == 0)
  {
    centipede.digitalWrite(OUT_SPEED2, HIGH);
    centipede.digitalWrite(OUT_SPEED1, HIGH);
  }
  if (speedlevel == 1)
  {
    centipede.digitalWrite(OUT_SPEED2, HIGH);
    centipede.digitalWrite(OUT_SPEED1, LOW);
  }
  if (speedlevel == 2)
  {
    centipede.digitalWrite(OUT_SPEED2, LOW);
    centipede.digitalWrite(OUT_SPEED1, HIGH);
  }
  if (speedlevel == 3)
  {
    centipede.digitalWrite(OUT_SPEED2, LOW);
    centipede.digitalWrite(OUT_SPEED1, LOW);
  }
}

void HardwareControl::SetDirection(int dir)
{
  if (dir <= 0)
    centipede.digitalWrite(OUT_MOTOR_RL, LOW);
  else
    centipede.digitalWrite(OUT_MOTOR_RL, HIGH);
}

void HardwareControl::SetProgramIndicator(int program)
{
  SetGroup(4);
  SetData(program);
}//TODO

void HardwareControl::SetBuzzer(int level)
{
  if (level <= 0)
    centipede.digitalWrite(OUT_BUZZER, LOW);
  else
    centipede.digitalWrite(OUT_BUZZER, HIGH);
}//TODO

void HardwareControl::SetSink(int level)
{
  if (level <= 0)
    centipede.digitalWrite(OUT_SINK, LOW);
  else
    centipede.digitalWrite(OUT_SINK, HIGH);
}


void HardwareControl::SetHeater(int level)
{
  if (level <= 0)
    centipede.digitalWrite(OUT_HEATER, LOW);
  else
    centipede.digitalWrite(OUT_HEATER, HIGH);
}//TODO

void HardwareControl::SetLock(int level)
{
  if (level <= 0)
    centipede.digitalWrite(OUT_LOCK, LOW);
  else
    centipede.digitalWrite(OUT_LOCK, HIGH);
}




// private sets - used by gets/sets

void HardwareControl::SetKeySelect(int value)
{
  centipede.digitalWrite(OUT_KEYSELECT, value);
}

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

void HardwareControl::Strobe()
{
  centipede.digitalWrite(OUT_STROBE, LOW);
  delay(80);
  centipede.digitalWrite(OUT_STROBE, HIGH);
  delay(10);
}
