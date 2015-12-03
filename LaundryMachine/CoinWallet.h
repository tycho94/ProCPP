#ifndef COINWALLET_H
#define COINWALLET_H

#include "ICoin.h"

class CoinWallet
{
  public:
    CoinWallet(ICoin *);
    void Poll();
    void ShowBalance();
    boolean Withdraw(int amount);
    boolean Deposit(int amount);
    int Balance();
  private:
    ICoin * mCoin;
    int balance;
};

#endif
