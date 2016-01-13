#include "StubHardwareControl.h"
#include "gtest/gtest.h"
//only options to set it to true or false and check it

TEST(Lock, SetLockerTrue) {
    StubHardwareControl c;

    c.SetLock(true);
    EXPECT_EQ(c.GetLockSwitch(), true);
}
//similar to Buzzer
//working this time with a sitch instead of a button.
TEST(Lock, SetLockerFalse) {
    StubHardwareControl c;

    c.SetLock(false);
    EXPECT_EQ(c.GetLockSwitch(), false);
}
