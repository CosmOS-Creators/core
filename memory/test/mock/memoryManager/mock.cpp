#include <gmock/gmock.h>

#include "memoryManager_mock.h"

#include "memoryManager.h"

// instantiate mocked lib
std::unique_ptr<MemoryManager_MOCK> MemoryManager_TestFixture::_MemoryManagerMock;

// fake lib functions
void memoryManager_heapInit(CosmOS_CoreVariableType * coreVar)
{
  MemoryManager_TestFixture::_MemoryManagerMock->memoryManager_heapInit(coreVar);
}

void memoryManager_stackInit(CosmOS_CoreVariableType * coreVar)
{
  MemoryManager_TestFixture::_MemoryManagerMock->memoryManager_stackInit(coreVar);
}
