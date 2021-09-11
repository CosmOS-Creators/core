#ifndef __OSBOOT_MOCK_H__
#define __OSBOOT_MOCK_H__

#include <memory>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "osBoot.h"

using namespace ::testing;
using ::testing::Return;

class OsBoot_MOCK{
public:
		OsBoot_MOCK(){}
    ~OsBoot_MOCK(){}

    MOCK_METHOD(void, osBoot_bootValidate, ());
};

class OsBoot_TestFixture: public ::testing::Test{
public:
    OsBoot_TestFixture(){
        _OsBootMock.reset(new ::testing::NiceMock<OsBoot_MOCK>());
    }
    ~OsBoot_TestFixture(){
        _OsBootMock.reset();
    }

    // pointer for accessing mocked library
    static std::unique_ptr<OsBoot_MOCK> _OsBootMock;

protected:
    virtual void SetUp(){}
		virtual void TestBody(){}
    virtual void TearDown(){}
};

#endif