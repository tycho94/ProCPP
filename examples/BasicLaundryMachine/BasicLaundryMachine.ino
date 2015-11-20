// Example code for Centipede Library
// Works with Centipede Shield or MCP23017 on Arduino I2C port

#include <Wire.h>
#include "Centipede.h"

Centipede CS; // create Centipede object

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

void setup()
{
  Wire.begin(); // start I2C
  CS.initialize(); // set all registers to default
  for (int i = 0; i <= 15; i++) 
  {
    CS.pinMode(i, OUTPUT);
  }
  CS.digitalWrite(OUT_GROUP2, LOW);
  CS.digitalWrite(OUT_GROUP1, LOW);
  CS.digitalWrite(OUT_STROBE, LOW);
  CS.digitalWrite(OUT_KEYSELECT, HIGH);
  CS.digitalWrite(OUT_BUZZER, HIGH);
  CS.digitalWrite(OUT_HEATER, HIGH);
  CS.digitalWrite(OUT_SPEED2, HIGH);
  CS.digitalWrite(OUT_SPEED1, HIGH);
  CS.digitalWrite(OUT_DATAC, LOW);
  CS.digitalWrite(OUT_DATAB, LOW);
  CS.digitalWrite(OUT_DATAA, LOW);
  CS.digitalWrite(OUT_MOTOR_RL, LOW);
  CS.digitalWrite(OUT_SOAP1, LOW);
  CS.digitalWrite(OUT_SINK, LOW);
  CS.digitalWrite(OUT_DRAIN, LOW);
  CS.digitalWrite(OUT_LOCK, LOW);
}

void loop()
{
  CS.digitalWrite(OUT_BUZZER, !CS.digitalRead(IN_IN0));
  CS.digitalWrite(OUT_DRAIN,   CS.digitalRead(IN_IN1));
  CS.digitalWrite(OUT_SINK,    CS.digitalRead(IN_IN2));
  CS.digitalWrite(OUT_SPEED1, !CS.digitalRead(IN_IN3));
}

