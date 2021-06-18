#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "osInit.h"

int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}

TEST_GROUP(osInit)
{
    void setup() {
    }


    void teardown() {
        mock().clear();
    }

};


TEST(osInit, simpleTest)
{
		mock().strictOrder();
    mock().expectOneCall("memoryProtection_init");
		mock().expectOneCall("os_getOsVar");
		mock().expectOneCall("CILcore_setCoreVar");
		mock().expectOneCall("core_getCoreVar");
		mock().expectOneCall("stackInit_init");
		mock().expectOneCall("coreSync_getBarrier");

    osInit_init();

    mock().checkExpectations();
}
