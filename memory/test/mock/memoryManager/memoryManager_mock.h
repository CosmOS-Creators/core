#ifndef __MEMORYMANAGER_MOCK_H__
#define __MEMORYMANAGER_MOCK_H__

#include <memory>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "memoryManager.h"

using namespace ::testing;
using ::testing::Return;

class MemoryManager_MOCK{
public:
		MemoryManager_MOCK(){}
    ~MemoryManager_MOCK(){}

    // mock methods
    MOCK_METHOD(void,memoryManager_heapInit, ());
};

class MemoryManager_TestFixture: public ::testing::Test{
public:
    MemoryManager_TestFixture(){
        _MemoryManagerMock.reset(new ::testing::NiceMock<MemoryManager_MOCK>());
    }
    ~MemoryManager_TestFixture(){
        _MemoryManagerMock.reset();
    }

    // pointer for accessing mocked library
    static std::unique_ptr<MemoryManager_MOCK> _MemoryManagerMock;

protected:
    virtual void SetUp(){}
		virtual void TestBody(){}
    virtual void TearDown(){}
};


#endif
