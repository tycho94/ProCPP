#ifndef ICOIN_H
#define ICOIN_H

class ICoin
{
  public:
    // Inputs
    virtual boolean GetCoin10Button() = 0;

    // Outputs
    virtual void SetCoin50(int leds) = 0;
};

#endif


