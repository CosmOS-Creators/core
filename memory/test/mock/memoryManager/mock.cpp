#include <gmock/gmock.h>
#include "memoryManager.h"
#include "memoryManager_mock.h"

std::unique_ptr<MemoryManager_MOCK>
    MemoryManager_TestFixture::_MemoryManagerMock;

void
memoryManager_heapInit( CosmOS_CoreConfigurationType * coreCfg )
{
    MemoryManager_TestFixture::_MemoryManagerMock->memoryManager_heapInit(
        coreCfg );
}

void
memoryManager_stackInit( CosmOS_CoreConfigurationType * coreCfg )
{
    MemoryManager_TestFixture::_MemoryManagerMock->memoryManager_stackInit(
        coreCfg );
}
