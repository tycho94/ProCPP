#ifndef TESTCOINWALLET_H
#define TESTCOINWALLET_H

#include "../HardwareControl.h"
#include "../CoinWallet.h"

#include "gtest/gtest.h"

class TestCoinWallet : public ::testing::Test{
    public:
    /*myTestFixture1( ) {
     // initialization code here
   }*/

   void SetUp( ) {

     CoinWallet * mCoinW = new HardwareControl();
     ICoin * iCoin = new CoinWallet(iCoin);
     
   }

   void TearDown( ) {

     delete mCoinW;
     mCoinW = NULL;
     delete iCoin;
     iCoin = NULL;

   }

   /*~myTestFixture1( )  {
     // cleanup any pending stuff, but no exceptions allowed
   }*/
   TestCoinWallet();
   virtual ~TestCoinWallet();

    private:

};

#endif // TESTCOINWALLET_H
