#include "StubHardwareControl.h"
#include "gtest/gtest.h"

//Test setting the program
TEST(Motor, SetDirection) {
    StubHardwareControl c;
    //working with enums
    c.SetDirection(CLOCK);
    ASSERT_EQ(c.GetMotorDir(), CLOCK);
    c.SetDirection(COUNTERCLOCK);
    ASSERT_EQ(c.GetMotorDir(), COUNTERCLOCK);
    EXPECT_NE(c.GetMotorDir(), CLOCK);
}
TEST(Motor, SetMotor) {
    StubHardwareControl c;

    c.SetMotor(MOTOR_OFF);
    ASSERT_EQ(c.GetMotor(),MOTOR_OFF);
    c.SetMotor(MOTOR_LOW);
    ASSERT_EQ(c.GetMotor(),MOTOR_LOW);
    ASSERT_NE(c.GetMotor(),MOTOR_HIGH);
    c.SetMotor(MOTOR_REGULAR);
    ASSERT_EQ(c.GetMotor(),MOTOR_REGULAR);
    c.SetMotor(MOTOR_HIGH);
    ASSERT_EQ(c.GetMotor(),MOTOR_HIGH);


}
