#include <gmock/gmock.h>

#include "memoryProtection_mock.h"

#include "memoryProtection.h"

// instantiate mocked lib
std::unique_ptr<MemoryProtection_MOCK> MemoryProtection_TestFixture::_MemoryProtectionMock;

// fake lib functions
void memoryProtection_init()
{
    MemoryProtection_TestFixture::_MemoryProtectionMock->memoryProtection_init();
}
