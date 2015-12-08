#include "CoinWallet.h"

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
  //when first led on means the sum is 200
  //when second led on means the sum is 400
  //when first and third led on means the sum is 600
  // wehn press one more time nothing happens
  if (group == 200) {
    coins = balance / 200;
    mCoin->SetCoin200(coins);
  }

  //50 coins
  //when first led on means the sum is 50
  //when second led on means the sum is 100
  //when third led on means the sum is 150
  //when press one more time means the sum is 200 so all coin50 indicator go off and one coin200 indicator goes on
  if (group == 50) {
    coins = (balance % 200) / 50;
    mCoin->SetCoin50(coins);
  }

  //10 coins
  //when the first led is on means the sum is 10
  //when the second led is on means the sum is 20
  //when the third led is on means the sum is 30
  //when the first and third led is on means the sum is 40
  //when press one more means the sum is now 50 so all coin10 indicators go off and one coin50 indicator goes on
  if (group == 10) {
    coins = (balance % 50) / 10;
    mCoin->SetCoin10(coins);
  }
}

//add money to the coinwallet, //check if leds are at their maximum, if so, do not add money
void CoinWallet::Deposit(int amount) {
  if ((((balance % 50) / amount) <= 2 && amount == 10) || (((balance % 200) / amount) <= 2 && amount == 50) || (balance / amount <= 1 && amount == 200))
  {
    balance += amount;
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


