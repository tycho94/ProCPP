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
    boolean Deposit(int amount);
  private:
    ICoin * mCoin;
    int balance;
};

#endif
