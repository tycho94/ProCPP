#ifndef COINWALLET_H
#define COINWALLET_H

#include "ICoin.h"

class CoinWallet
{
  public:
    CoinWallet(ICoin *);
    void Poll();
    int Balance();
    boolean Withdraw(int amount);
  private:
    ICoin * mCoin;
};

#endif
