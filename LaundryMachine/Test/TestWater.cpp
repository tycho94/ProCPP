#include "StubHardwareControl.h"
#include "gtest/gtest.h"

TEST(Water, GetPressureSwitch) {
    StubHardwareControl c;

    EXPECT_EQ(c.GetPressureSwitch(), true);
}

TEST(Water, GetWaterLevel) {
    StubHardwareControl c;

    EXPECT_EQ(c.GetWaterlevel(), 0);
}

TEST(Water, SetWaterLevel) {
    StubHardwareControl c;

    c.SetWaterlevel(2);
    EXPECT_EQ(c.GetWaterlevel(), 2);
}

TEST(Water, SetDrain) {
    StubHardwareControl c;

    c.SetDrain(0);
}
