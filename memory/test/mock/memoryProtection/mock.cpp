#include <gmock/gmock.h>

#include "memoryProtection_mock.h"

#include "memoryProtection.h"

// instantiate mocked lib
std::unique_ptr<MemoryProtection_MOCK> MemoryProtection_TestFixture::_MemoryProtectionMock;

// fake lib functions
void memoryProtection_init(AddressType codeMemoryHighAddress,AddressType codeMemoryLowAddress,
			AddressType stackMemoryHighAddress,AddressType stackMemoryLowAddress,
			AddressType unprotectedMemoryLowAddress, AddressType unprotectedMemoryHighAddress)
{
	MemoryProtection_TestFixture::_MemoryProtectionMock->memoryProtection_init(codeMemoryHighAddress,codeMemoryLowAddress,
										stackMemoryHighAddress,stackMemoryLowAddress,
										unprotectedMemoryLowAddress,unprotectedMemoryHighAddress);
}
