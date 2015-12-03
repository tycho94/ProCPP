#include "CoinWallet.h"

CoinWallet::CoinWallet(ICoin * c)
{
  mCoin = c;
  balance = 0;
}
void CoinWallet::showBalance()
{
  int remainder;
  int q;
  q= balance/200;
  remainder=balance%200;
  mCoin->Set
}

void CoinWallet::Poll()
{
}

int CoinWallet::Balance()
{
  return balance;
}

boolean CoinWallet::Withdraw(int amount)
{
  if ( amount<=balance)
  {
    balance=balance-amount;
    showBalance();
    return true;
  }
  else
  {
  return (false);
  }
}
boolean CoinWallet::Deposit( int amount){
  if( amount>0 && (balance+amount<=600) )
  {
    balance=balance+amount;
    showBalance();
    return true;
  }
  else
  {
    return false;
  }
}

