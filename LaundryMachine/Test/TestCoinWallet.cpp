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
    mCoin
    EXPECT_EQ(10, 10);
}
