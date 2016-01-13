#include "../CoinWallet.h"

CoinWallet::CoinWallet(ICoin * c)
{
  mCoin = c;
  balance = 0;
}

//set the coin leds

void CoinWallet::ShowBalance(int group)
{
  int coins;

  //200 coins
  if (group == 200) {
    coins = balance / 200;
    mCoin->SetCoin200(coins);
  }

  //50 coins
  if (group == 50) {
    coins = (balance % 200) / 50;
    mCoin->SetCoin50(coins);
  }

  //10 coins
  if (group == 10) {
    coins = (balance % 50) / 10;
    mCoin->SetCoin10(coins);
  }
}
//Adding money to the wallet
void CoinWallet::Deposit(int amount) {
  if ((((balance % 50) / amount) <= 2 && amount == 10) ||
      (((balance % 200) / amount) <= 2 && amount == 50) ||
      (balance / amount <= 1 && amount == 200))
  {
    balance += amount;
    ShowBalance(amount);
  }
}


//Returns the money
int CoinWallet::Clear()
{
  int temp = balance;
  balance = 0;
  mCoin->SetCoin10(0);
  mCoin->SetCoin50(0);
  mCoin->SetCoin200(0);
  return temp;
}

//take money for any program
bool CoinWallet::Withdraw(int amount)
{
  if ( amount <= balance)
  {
    balance -= amount;
    ShowBalance(10);
    ShowBalance(50);
    ShowBalance(200);
    return true;
  }
  else
  {
    return (false);
  }
}

