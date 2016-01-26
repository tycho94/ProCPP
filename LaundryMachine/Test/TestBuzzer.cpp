#include "StubHardwareControl.h"
#include "gtest/gtest.h"

TEST(Buzzer, SetBuzzerTrue) {
    StubHardwareControl c;

    c.Buzz();
    EXPECT_EQ(c.GetBuzzer(), true);
}

TEST(Buzzer, SetBuzzerFalse) {
    StubHardwareControl c;

    c.Buzz();
    c.Buzz();
    EXPECT_EQ(c.GetBuzzer(), false);
}

// Make sure to add your specific test variables and methods in the Stub.
// !!!! Make sure to initialize the variables in the Stub constructor. !!!!
