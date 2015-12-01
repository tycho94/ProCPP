#ifndef IMOTOR_H
#define IMOTOR_H

class IMotor
{
public:
  // Outputs
  virtual void SetDirection(int dir) = 0;
};

#endif


