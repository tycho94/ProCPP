#ifndef TESTCOINWALLET_H
#define TESTCOINWALLET_H

#include "ArduinoWrapper.h"	// to be included before all other LaundryMachine include files

#include "StubHardwareControl.h"
#include "CoinWallet.h"

#include "gtest/gtest.h"

class TestCoinWallet : public ::testing::Test
{
    public:
        TestCoinWallet();
        virtual ~TestCoinWallet();
    protected:
        /// they must be protected instead of private, because Google Test makes subclasses for the tests
        CoinWallet *            mCoinWallet;
        StubHardwareControl *   mCoin;
    private:
};

#endif // TESTCOINWALLET_H
