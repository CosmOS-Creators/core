#ifndef __STACK_MOCK_H__
#define __STACK_MOCK_H__

#include <memory>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "stack.h"

using namespace ::testing;
using ::testing::Return;

class Stack_MOCK{
public:
		Stack_MOCK(){}
    ~Stack_MOCK(){}

    // mock methods
    MOCK_METHOD(void, stackInit_init, (CosmOS_CoreVariableType * coreVar));
};

class Stack_TestFixture: public ::testing::Test{
public:
    Stack_TestFixture(){
        _StackMock.reset(new ::testing::NiceMock<Stack_MOCK>());
    }
    ~Stack_TestFixture(){
        _StackMock.reset();
    }

    // pointer for accessing mocked library
    static std::unique_ptr<Stack_MOCK> _StackMock;

protected:
    virtual void SetUp(){}
		virtual void TestBody(){}
    virtual void TearDown(){}
};


#endif
