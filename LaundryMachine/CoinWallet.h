#ifndef COINWALLET_H
#define COINWALLET_H

#include "ICoin.h"

class CoinWallet
{
  public:
    CoinWallet(ICoin * c);
    void ShowBalance(int group);
    boolean Withdraw(int amount);
    void Deposit(int amount);
    int Clear();
  private:
    ICoin * mCoin;
    int balance;
};

#endif
