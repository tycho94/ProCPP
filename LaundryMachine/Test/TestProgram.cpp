#include "StubHardwareControl.h"
#include "gtest/gtest.h"

//Test setting the program
TEST(Program, SetProgramIndicator) {
    StubHardwareControl c;

    c.SetProgramIndicator(PROGRAM_B);
	ASSERT_EQ(c.GetProgramIndicator(), PROGRAM_B);
	
	c.SetProgramIndicator(PROGRAM_A);
	ASSERT_EQ(c.GetProgramIndicator(), PROGRAM_A);
	ASSERT_NE(c.GetProgramIndicator(), PROGRAM_B);
	
	c.SetProgramIndicator(NO_PROGRAM);
	ASSERT_EQ(c.GetProgramIndicator(), NO_PROGRAM);
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

//test the getprogramcost
TEST(Program, GetProgramMoney){
	StubHardwareControl c;
	
	ASSERT_EQ(c.GetProgramMoney(NO_PROGRAM), -1);
	EXPECT_EQ(c.GetProgramMoney(PROGRAM_A), 360);
	EXPECT_EQ(c.GetProgramMoney(PROGRAM_B), 480);
	EXPECT_EQ(c.GetProgramMoney(PROGRAM_C), 510);
}
