#include <gmock/gmock.h>
#include "memoryProtection.h"
#include "memoryProtection_mock.h"

std::unique_ptr<MemoryProtection_MOCK>
    MemoryProtection_TestFixture::_MemoryProtectionMock;

void
memoryProtection_init(
    AddressType codeMemoryHighAddress,
    AddressType codeMemoryLowAddress,
    AddressType stackMemoryHighAddress,
    AddressType stackMemoryLowAddress,
    AddressType unprotectedMemoryLowAddress,
    AddressType unprotectedMemoryHighAddress )
{
    MemoryProtection_TestFixture::_MemoryProtectionMock->memoryProtection_init(
        codeMemoryHighAddress,
        codeMemoryLowAddress,
        stackMemoryHighAddress,
        stackMemoryLowAddress,
        unprotectedMemoryLowAddress,
        unprotectedMemoryHighAddress );
}
