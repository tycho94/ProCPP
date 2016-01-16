#include "StubHardwareControl.h"
#include "gtest/gtest.h"

//Test setting the program
TEST(Motor, SetDirection) {
    StubHardwareControl c;
    //working with enums
    c.SetDirection(RIGHT);
    ASSERT_EQ(c.GetMotorDir(), RIGHT);
    c.SetDirection(LEFT);
    ASSERT_EQ(c.GetMotorDir(), LEFT);
    EXPECT_NE(c.GetMotorDir(), RIGHT);
}
TEST(Motor, SetMotor) {
    StubHardwareControl c;

    c.SetMotor(MOTOR_OFF);
    ASSERT_EQ(c.GetMotorSpeed(),MOTOR_OFF);
    c.SetMotor(MOTOR_LOW);
    ASSERT_EQ(c.GetMotorSpeed(),MOTOR_LOW);
    ASSERT_NE(c.GetMotorSpeed(),MOTOR_HIGH);
    c.SetMotor(MOTOR_REGULAR);
    ASSERT_EQ(c.GetMotorSpeed(),MOTOR_REGULAR);
    c.SetMotor(MOTOR_HIGH);
    ASSERT_EQ(c.GetMotorSpeed(),MOTOR_HIGH);


}
