#include "StubHardwareControl.h"
#include "gtest/gtest.h"

TEST(Buzzer, SetBuzzerTrue) {
    StubHardwareControl c;

    c.SetBuzzer(true);
    EXPECT_EQ(c.GetBuzzer(), true);
}

TEST(Buzzer, SetBuzzerFalse) {
    StubHardwareControl c;

    c.SetBuzzer(false);
    EXPECT_EQ(c.GetBuzzer(), false);
}

// Make sure to add your specific test variables and methods in the Stub.
// !!!! Make sure to initialize the variables in the Stub constructor. !!!!
