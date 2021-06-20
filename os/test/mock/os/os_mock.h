#ifndef __OS_MOCK_H__
#define __OS_MOCK_H__

#include <memory>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "os.h"

using namespace ::testing;
using ::testing::Return;

class Os_MOCK{
public:
		Os_MOCK(){}
    ~Os_MOCK(){}

    MOCK_METHOD(CosmOS_OsVariableType*, os_getOsVar, ());
};

class Os_TestFixture: public ::testing::Test{
public:
    Os_TestFixture(){
        _OsMock.reset(new ::testing::NiceMock<Os_MOCK>());
    }
    ~Os_TestFixture(){
        _OsMock.reset();
    }

    // pointer for accessing mocked library
    static std::unique_ptr<Os_MOCK> _OsMock;

protected:
    virtual void SetUp(){}
		virtual void TestBody(){}
    virtual void TearDown(){}
};

#endif
