#ifndef __MEMORYPROTECTION_MOCK_H__
#define __MEMORYPROTECTION_MOCK_H__

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
#include "memoryProtection.h"

using namespace ::testing;
using ::testing::Return;

class MemoryProtection_MOCK
{
   public:
    MemoryProtection_MOCK()
    {}
    ~MemoryProtection_MOCK()
    {}

    MOCK_METHOD(
        void,
        memoryProtection_init,
        ( AddressType codeMemoryHighAddress,
          AddressType codeMemoryLowAddress,
          AddressType stackMemoryHighAddress,
          AddressType stackMemoryLowAddress,
          AddressType unprotectedMemoryLowAddress,
          AddressType unprotectedMemoryHighAddress ) );
};

class MemoryProtection_TestFixture : public ::testing::Test
{
   public:
    MemoryProtection_TestFixture()
    {
        _MemoryProtectionMock.reset(
            new ::testing::NiceMock<MemoryProtection_MOCK>() );
    }
    ~MemoryProtection_TestFixture()
    {
        _MemoryProtectionMock.reset();
    }

    static std::unique_ptr<MemoryProtection_MOCK> _MemoryProtectionMock;

   protected:
    virtual void
    SetUp()
    {}
    virtual void
    TestBody()
    {}
    virtual void
    TearDown()
    {}
};

#endif
