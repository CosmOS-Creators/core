#ifndef __CORE_MOCK_H__
#define __CORE_MOCK_H__

#include <memory>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "core.h"

using namespace ::testing;
using ::testing::Return;

class Core_MOCK{
public:
		Core_MOCK(){}
    ~Core_MOCK(){}

    // mock methods
    MOCK_METHOD((CosmOS_CoreVariableType *), core_getCoreVar, ());
};

class Core_TestFixture: public ::testing::Test{
public:
    Core_TestFixture(){
        _CoreMock.reset(new ::testing::NiceMock<Core_MOCK>());
    }
    ~Core_TestFixture(){
        _CoreMock.reset();
    }

    // pointer for accessing mocked library
    static std::unique_ptr<Core_MOCK> _CoreMock;

protected:
    virtual void SetUp(){}
		virtual void TestBody(){}
    virtual void TearDown(){}
};


#endif
