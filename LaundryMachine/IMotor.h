#ifndef IMOTOR_H
#define IMOTOR_H

enum Direction
{
  LEFT = 0 ,
  RIGHT = 1
};

enum Speed
{
  MOTOR_OFF = 1,
  MOTOR_LOW,
  MOTOR_REGULAR,
  MOTOR_HIGH = 4
};

class IMotor
{
  public:
    // Outputs
    virtual void SetDirection(int dir) = 0; //0=left 1=right
    virtual void SetMotor(int speedlevel) = 0; //0=off 1=slow 2=medium 3=high

};

#endif
