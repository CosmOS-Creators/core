#include <gmock/gmock.h>
#include "memoryManager.h"
#include "memoryManager_mock.h"

std::unique_ptr<MemoryManager_MOCK>
    MemoryManager_TestFixture::_MemoryManagerMock;

void
memoryManager_heapInit( CosmOS_CoreVariableType * coreVar )
{
    MemoryManager_TestFixture::_MemoryManagerMock->memoryManager_heapInit(
        coreVar );
}

void
memoryManager_stackInit( CosmOS_CoreVariableType * coreVar )
{
    MemoryManager_TestFixture::_MemoryManagerMock->memoryManager_stackInit(
        coreVar );
}
