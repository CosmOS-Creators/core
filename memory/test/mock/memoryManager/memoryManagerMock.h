#ifndef __MEMORYMANAGERMOCK_H__
#define __MEMORYMANAGERMOCK_H__

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
#include "memoryManager.h"

using namespace ::testing;
using ::testing::Return;

class MemoryManager_MOCK
{
   public:
    MemoryManager_MOCK()
    {}
    ~MemoryManager_MOCK()
    {}

    MOCK_METHOD(
        void,
        memoryManager_heapInit,
        ( CosmOS_CoreConfigurationType * coreCfg ) );
    MOCK_METHOD(
        void,
        memoryManager_stackInit,
        ( CosmOS_CoreConfigurationType * coreCfg ) );
};

class MemoryManager_TestFixture : public ::testing::Test
{
   public:
    MemoryManager_TestFixture()
    {
        _MemoryManagerMock.reset(
            new ::testing::NiceMock<MemoryManager_MOCK>() );
    }
    ~MemoryManager_TestFixture()
    {
        _MemoryManagerMock.reset();
    }

    static std::unique_ptr<MemoryManager_MOCK> _MemoryManagerMock;

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
