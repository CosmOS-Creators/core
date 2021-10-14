#include <gtest/gtest.h>

#include "os_mock.h"
#include "osBoot_mock.h"
#include "core_mock.h"
#include "CILcore_mock.h"
#include "coreSync_mock.h"
#include "memoryManager_mock.h"
#include "memoryProtection_mock.h"

#include "osInit.h"

#include "utCfg.h"

TEST(osInit, executionFlow)
{
	MemoryProtection_TestFixture memoryProtectionMock;
	MemoryManager_TestFixture memoryManagerMock;
	CoreSync_TestFixture coreSyncMock;
	CILcore_TestFixture CILcoreMock;
	Core_TestFixture coreMock;
	Os_TestFixture osMock;
	OsBoot_TestFixture osBootMock;

	EXPECT_CALL(*osMock._OsMock, os_getOsVar()).Times(1).WillOnce(Return((CosmOS_OsVariableType*)NULL));
	EXPECT_CALL(*CILcoreMock._CILcoreMock, CILcore_setCoreVar((CosmOS_OsVariableType*)NULL)).Times(1);
	EXPECT_CALL(*coreMock._CoreMock, core_getCoreVar()).Times(1).WillOnce(Return(&CoresVar[0]));
	EXPECT_CALL(*memoryProtectionMock._MemoryProtectionMock, memoryProtection_init(310 ,300 ,210 ,200,400,500)).Times(1);
	EXPECT_CALL(*osBootMock._OsBootMock, osBoot_bootValidate()).Times(1);
	EXPECT_CALL(*memoryManagerMock._MemoryManagerMock, memoryManager_stackInit(&CoresVar[0])).Times(1);
	EXPECT_CALL(*memoryManagerMock._MemoryManagerMock, memoryManager_heapInit(&CoresVar[0])).Times(1);
	//EXPECT_CALL(*coreSyncMock._CoreSyncMock, coreSync_getBarrier(&CoresVar[0], OS_INIT_ID)).Times(1);

	osInit_init(0);
}
