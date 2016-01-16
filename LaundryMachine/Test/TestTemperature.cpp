#include "StubHardwareControl.h"
#include "gtest/gtest.h"

//Test setting the program
TEST(Temperature, SetTemperature) {
    StubHardwareControl c;

    c.SetTemperature(COLD);
    ASSERT_EQ(c.GetTemperature(), COLD);
    c.SetTemperature(WARM);
    ASSERT_EQ(c.GetTemperature(), WARM);
    //cant be hotter here
    ASSERT_NE(c.GetTemperature(), HOT);
    c.SetTemperature(HOT);
    ASSERT_EQ(c.GetTemperature(), HOT);

    ASSERT_EQ(c.GetHeater(), true);
}
