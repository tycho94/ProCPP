#ifndef IMOTOR_H
#define IMOTOR_H

enum Direction
{
  COUNTERCLOCK = 0 ,
  CLOCK = 1
};

enum Speed
{
  MOTOR_OFF = 0,
  MOTOR_LOW,
  MOTOR_REGULAR,
  MOTOR_HIGH = 3
};

class IMotor
{
  public:
    // Outputs
    virtual void SetDirection(bool dir) = 0; //0=left 1=right
    virtual void SetMotor(int speedlevel) = 0; //0=off 1=slow 2=medium 3=high
    virtual int GetMotor() = 0;

};

#endif
