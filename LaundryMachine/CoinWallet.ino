#include "CoinWallet.h"

CoinWallet::CoinWallet(ICoin * c)
{
  mCoin = c;
  balance = 0;
  Serial.println("start coinwallet");
}

//set the coin leds
void CoinWallet::ShowBalance(int group)
{
  int coins;

  //200 coins
  if (group == 200) {
    coins = balance / 200;
    mCoin->SetCoin200(coins);
    Serial.print("200: ");
    Serial.println(coins);

  }

  //50 coins
  if (group == 50) {
    coins = (balance % 200) / 50;
    mCoin->SetCoin50(coins);
    Serial.print("50: ");
    Serial.println(coins);
  }

  //10 coins
  if (group == 10) {
    coins = (balance % 50) / 10;
    mCoin->SetCoin10(coins);
    Serial.print("10: ");
    Serial.println(coins);

  }
}

//add money to the coinwallet, //check if leds are at their maximum, if so, do not add money
void CoinWallet::Deposit(int amount) {
  if ((((balance % 50) / amount) <= 2 && amount == 10) || (((balance % 200) / amount) <= 2 && amount == 50) || (balance / amount <= 1 && amount == 200))
  {
    balance += amount;
    Serial.print("balance: ");
    Serial.println(balance);
    ShowBalance(amount);
  }
}


//returns the money still in the coinwallet
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
boolean CoinWallet::Withdraw(int amount)
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


