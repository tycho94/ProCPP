#include "StubHardwareControl.h"
#include "gtest/gtest.h"

//Test setting the program
TEST(Temperature, SetTemperature) {
    StubHardwareControl c;

    c.SetTemperature(COLD);
    ASSERT_EQ(c.GetTemperature(), 1);
    c.SetTemperature(WARM);
    ASSERT_EQ(c.GetTemperature(), 2);
    //cant be hotter here
    ASSERT_NE(c.GetTemperature(), 3);
    c.SetTemperature(HOT);
    ASSERT_EQ(c.GetTemperature(), 3);

}
