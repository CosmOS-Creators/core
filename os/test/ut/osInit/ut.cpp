#include <gtest/gtest.h>

#include "os_mock.h"
#include "osBoot_mock.h"
#include "core_mock.h"
#include "stack_mock.h"
#include "CILcore_mock.h"
#include "coreSync_mock.h"
#include "memoryManager_mock.h"
#include "memoryProtection_mock.h"

#include "osInit.h"


TEST(osInit, executionFlow)
{
		MemoryProtection_TestFixture memoryProtectionMock;
		MemoryManager_TestFixture memoryManagerMock;
		CoreSync_TestFixture coreSyncMock;
		CILcore_TestFixture CILcoreMock;
		Stack_TestFixture stackMock;
		Core_TestFixture coreMock;
		Os_TestFixture osMock;
		OsBoot_TestFixture osBootMock;

    EXPECT_CALL(*memoryProtectionMock._MemoryProtectionMock, memoryProtection_init()).Times(1);
		EXPECT_CALL(*osBootMock._OsBootMock, osBoot_bootValidate()).Times(1);
		EXPECT_CALL(*osMock._OsMock, os_getOsVar()).Times(1).WillOnce(Return((CosmOS_OsVariableType*)NULL));
		EXPECT_CALL(*CILcoreMock._CILcoreMock, CILcore_setCoreVar((CosmOS_OsVariableType*)NULL)).Times(1);
		EXPECT_CALL(*coreMock._CoreMock, core_getCoreVar()).Times(1).WillOnce(Return((CosmOS_CoreVariableType*)NULL));
		EXPECT_CALL(*stackMock._StackMock, stackInit_init((CosmOS_CoreVariableType*)NULL)).Times(1);
		EXPECT_CALL(*memoryManagerMock._MemoryManagerMock, memoryManager_heapInit()).Times(1);
		EXPECT_CALL(*coreSyncMock._CoreSyncMock, coreSync_getBarrier((CosmOS_CoreVariableType *)NULL, (BitWidthType)NULL)).Times(1);

    osInit_init(0);

}
