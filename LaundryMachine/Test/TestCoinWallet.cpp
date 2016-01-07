#include "TestCoinWallet.h"
#include "StubHardwareControl.h"


TestCoinWallet::TestCoinWallet()
{
    mCoin = new StubHardwareControl();
    mCoinWallet = new CoinWallet(mCoin);
}

TestCoinWallet::~TestCoinWallet()
{
    delete mCoinWallet;
    mCoinWallet = NULL;
}

TEST_F(TestCoinWallet, test_coin10)
{
    //Pressing when running
    EXPECT_EQ(mCoin->GetCoin10Button(), true);
    EXPECT_EQ(mCoin->GetCoin10Button(), true);
    
    
}
