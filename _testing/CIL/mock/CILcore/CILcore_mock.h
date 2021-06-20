#ifndef __CILCORE_MOCK_H__
#define __CILCORE_MOCK_H__

#include <memory>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "CILcore.h"

using namespace ::testing;
using ::testing::Return;

class CILcore_MOCK{
public:
		CILcore_MOCK(){}
    ~CILcore_MOCK(){}

    MOCK_METHOD(void, CILcore_setCoreVar, (CosmOS_OsVariableType * osVar));
};

class CILcore_TestFixture: public ::testing::Test{
public:
    CILcore_TestFixture(){
        _CILcoreMock.reset(new ::testing::NiceMock<CILcore_MOCK>());
    }
    ~CILcore_TestFixture(){
        _CILcoreMock.reset();
    }

    // pointer for accessing mocked library
    static std::unique_ptr<CILcore_MOCK> _CILcoreMock;

protected:
    virtual void SetUp(){}
		virtual void TestBody(){}
    virtual void TearDown(){}
};

#endif
