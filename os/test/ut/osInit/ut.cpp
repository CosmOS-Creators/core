#include <gtest/gtest.h>

#include "memoryProtection_mock.h"

#include "osInit.h"

TEST(osInit, executionFlow)
{

		MemoryProtection_TestFixture mock;
    // << "switchMemoryProtection_init has to be called at least one as part of osInit_Init"
    EXPECT_CALL(*mock._MemoryProtectionMock, memoryProtection_init()).Times(1);

    osInit_init();
}
