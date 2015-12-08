#ifndef ICOIN_H
#define ICOIN_H

class ICoin
{
  public:
    // Inputs
    virtual boolean GetCoin10Button() = 0;
    virtual boolean GetCoin50Button() = 0;
    virtual boolean GetCoin200Button() = 0;
    virtual boolean GetCoinClearButton() = 0;

    // Outputs
    virtual void SetCoin10(int leds) = 0;
    virtual void SetCoin50(int leds) = 0;
    virtual void SetCoin200(int leds) = 0;
};

#endif
