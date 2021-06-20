#include <gtest/gtest.h>

#include "os_mock.h"
#include "core_mock.h"
#include "stack_mock.h"
#include "CILcore_mock.h"
#include "coreSync_mock.h"
#include "memoryProtection_mock.h"

#include "osInit.h"

TEST(osInit, executionFlow)
{
		MemoryProtection_TestFixture memoryProtectionMock;
		CoreSync_TestFixture coreSyncMock;
		CILcore_TestFixture CILcoreMock;
		Stack_TestFixture stackMock;
		Core_TestFixture coreMock;
		Os_TestFixture osMock;

    EXPECT_CALL(*memoryProtectionMock._MemoryProtectionMock, memoryProtection_init()).Times(1);
		EXPECT_CALL(*osMock._OsMock, os_getOsVar()).Times(1);
		//EXPECT_CALL(*CILcoreMock._CILcoreMock, os_getOsVar()).Times(1);
		EXPECT_CALL(*coreMock._CoreMock, core_getCoreVar()).Times(1);
		//EXPECT_CALL(*stackMock._StackMock, stackInit_init()).Times(1);
		//EXPECT_CALL(*coreSyncMock._CoreSyncMock, coreSync_getBarrier()).Times(1);

    osInit_init();

}
