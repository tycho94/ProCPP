#ifndef ILOCK_H
#define ILOCK_H

class ILock
{
  public:
    // Inputs
    virtual bool GetLockSwitch() = 0;
    // Outputs
    virtual void SetLock(bool level) = 0;    // off = 0 on = 1
};

#endif
