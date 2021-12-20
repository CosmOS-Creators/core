#ifndef __CILCOREMOCK_H__
#define __CILCOREMOCK_H__

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
#include "sysCalls.h"

using namespace ::testing;
using ::testing::Return;

class SysCalls_MOCK
{
   public:
    SysCalls_MOCK()
    {}
    ~SysCalls_MOCK()
    {}

    MOCK_METHOD(
        void,
        sysCalls_bitWidthType_ret_void,
        ( BitWidthType identifier ) );
};

class SysCalls_TestFixture : public ::testing::Test
{
   public:
    SysCalls_TestFixture()
    {
        _SysCallsMock.reset( new ::testing::NiceMock<SysCalls_MOCK>() );
    }
    ~SysCalls_TestFixture()
    {
        _SysCallsMock.reset();
    }

    static std::unique_ptr<SysCalls_MOCK> _SysCallsMock;

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
