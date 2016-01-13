#include "StubHardwareControl.h"
#include "gtest/gtest.h"

//Test setting the program
TEST(Motor, SetDirection) {
    StubHardwareControl c;
    //working with enums
    c.SetDirection(RIGHT);
    ASSERT_EQ(c.GetMotorDir(), 1);
    c.SetDirection(LEFT);
    ASSERT_EQ(c.GetMotorDir(), 0);

	  c.SetDirection(5);
	  ASSERT_EQ(c.GetMotorDir(), 0);
}
TEST(Motor, SetMotor) {
    StubHardwareControl c;

    c.SetMotor(MOTOR_OFF);
    ASSERT_EQ(c.GetMotorSpeed(),0);
    c.SetMotor(MOTOR_LOW);
    ASSERT_EQ(c.GetMotorSpeed(),1);
    ASSERT_NE(c.GetMotorSpeed(),3);
    c.SetMotor(MOTOR_REGULAR);
    ASSERT_EQ(c.GetMotorSpeed(),2);
    c.SetMotor(MOTOR_HIGH);
    ASSERT_EQ(c.GetMotorSpeed(),3);


}
