#include "StubHardwareControl.h"
#include "gtest/gtest.h"
//only options to set it to true or false and check it

TEST(Soap1, SetSoap1True) {
    StubHardwareControl c;

    c.SetSoap1(true);
    EXPECT_EQ(c.GetSoap1Switch(), true);
}
//similar to Buzzer
//working this time with a sitch instead of a button.
TEST(Soap2, SetSoap2False) {
    StubHardwareControl c;

    c.SetSoap2(false);
    EXPECT_EQ(c.GetSoap2Switch(), false);
}
