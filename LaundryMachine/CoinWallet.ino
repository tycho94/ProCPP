#include "CoinWallet.h"

CoinWallet::CoinWallet(ICoin * c)
{
  mCoin = c;
}

void CoinWallet::Poll()
{
}

int CoinWallet::Balance()
{
  return ();
}

boolean CoinWallet::Withdraw(int amount)
{
  return (false);
}

