// include the controller with the fake code
#include "StubHardwareControl.h"
// include gtest for definitions of stuff
#include "gtest/gtest.h"
// optionally include a thing you want to test that is *not* in the stubhardwarecontroller
#include "../CoinWallet.h"

// TEST - defines a new test that will be run
// coinwallet - says that this tests some function, can be arbitrary
// get10coins - says that this is a specific test case for that function, can be arbitrary
TEST(CoinWallet, get10coins) {
    StubHardwareControl c;
    CoinWallet wallet(&c);

    wallet.Deposit(10);
    EXPECT_EQ(c.GetCoin10Button(), true);
    EXPECT_EQ(c.GetCoinAmount(), 10);
}

// Again, we test coin wallet but in a different test case, now with 50 coins
TEST(CoinWallet, get50coins) {
    StubHardwareControl c;
    CoinWallet wallet(&c);

    wallet.Deposit(50);
    EXPECT_EQ(c.GetCoin50Button(), true);
    EXPECT_EQ(c.GetCoinAmount(), 50);
}

// Again, we test coin wallet but in a different test case, now with 200 coins
TEST(CoinWallet, get200coins) {
    StubHardwareControl c;
    CoinWallet wallet(&c);

    wallet.Deposit(200);
    EXPECT_EQ(c.GetCoin200Button(), true);
    EXPECT_EQ(c.GetCoinAmount(), 200);
}

// Be careful with names and such because you will get some very
// incomprehensible errors. If you do get some of these errors read them
// carefully because somewhere in those lines there's the real reason why the
// code doesn't compile.
//
// To add new tests follow the steps.
// 1) Copy the feature from the original code to the StubHardwareControl.
// 2) Create a new Test(INTERFACE).cpp file with the tests in it.
// 3) Add the new TEST(INTERFACE).cpp to the makefile.
// 4) Add tests and stuff to it to mimick the actions of the arduino code.
// 5) Make sure the tests compile and cover the whole interface.
// 6) Upload them to the repository.
// 7) ???
// 8) Profit!
//
// NOTES:
// Check the Buzzer to see how more examples + more comments.
//
// If you stop functions that accept or return `boolean` change that to `bool`
// because otherwise the tests will *not* compile without *A LOT* of effort.
// You don't need to modify the original HardwareControl after such changes
// because the arduino compiler can infer the types correctly but gcc cannot.
