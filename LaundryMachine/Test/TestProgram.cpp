#include "StubHardwareControl.h"
#include "gtest/gtest.h"

//Test setting the program
TEST(Program, SetProgramIndicator) {
    StubHardwareControl c;

    	c.SetProgramIndicator(1);
    	ASSERT_EQ(c.GetProgramIndicator(), 1);
	c.SetProgramIndicator(0);
	ASSERT_EQ(c.GetProgramIndicator(), 0);
	ASSERT_NE(c.GetProgramIndicator(), 1);
	c.SetProgramIndicator(5);
	ASSERT_EQ(c.GetProgramIndicator(), 0);
}
//Check if program button work
TEST(Program, GetProgramButton) {
    StubHardwareControl c;

    EXPECT_EQ(c.GetProgramButton(), true);
}

//test start button
TEST(Program, GetStartButton) {
    StubHardwareControl c;

    EXPECT_EQ(c.GetStartButton(), true);
}
