#ifndef __SYSCALLSMOCK_H__
#define __SYSCALLSMOCK_H__

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
#include "sysCalls.h"

using namespace ::testing;
using ::testing::Return;

class CILcore_MOCK
{
   public:
    CILcore_MOCK()
    {}
    ~CILcore_MOCK()
    {}

    MOCK_METHOD(
        void,
        CILcore_setCoreCfg,
        ( CosmOS_OsConfigurationType * osCfg ) );
    MOCK_METHOD( (CosmOS_CoreConfigurationType *), CILcore_getCoreCfg, () );
    MOCK_METHOD( void, CILcore_systemReset, () );
    MOCK_METHOD( ( CosmOS_BooleanType ), CILcore_isInPrivilegedMode, () );
};

class CILcore_TestFixture : public ::testing::Test
{
   public:
    CILcore_TestFixture()
    {
        _CILcoreMock.reset( new ::testing::NiceMock<CILcore_MOCK>() );
    }
    ~CILcore_TestFixture()
    {
        _CILcoreMock.reset();
    }

    static std::unique_ptr<CILcore_MOCK> _CILcoreMock;

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
