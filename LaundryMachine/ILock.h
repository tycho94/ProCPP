#ifndef ILOCK_H
#define ILOCK_H

class ILock
{
  public:
    // Inputs
    virtual boolean GetLockSwitch() = 0;
    // Outputs
    virtual void SetLock(int level) = 0;    // off = 0 on = 1
};

#endif
