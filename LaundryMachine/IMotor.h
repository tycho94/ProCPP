#ifndef IMOTOR_H
#define IMOTOR_H

enum Direction
{
  CLOCKWISE,
  ANTI_CLOCKWISE
};

enum Speed
{
  MOTOR_OFF,
  MOTOR_LOW,
  MOTOR_REGULAR,
  MOTOR_HIGH
};

class IMotor
{
  public:
    // Outputs
    virtual void SetDirection(int dir) = 0; //0=left 1=right
    virtual void SetMotor(int speedlevel) = 0; //0=off 1=slow 2=medium 3=high
  private:
    Speed motorSpeed;
};

#endif
