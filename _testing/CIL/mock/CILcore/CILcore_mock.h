#ifndef __CILCORE_MOCK_H__
#define __CILCORE_MOCK_H__

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
#include "CILcore.h"

using namespace ::testing;
using ::testing::Return;

class CILcore_MOCK
{
   public:
    CILcore_MOCK()
    {}
    ~CILcore_MOCK()
    {}

    MOCK_METHOD( void, CILcore_setCoreCfg, ( CosmOS_OsVariableType * osVar ) );
    MOCK_METHOD( (CosmOS_CoreVariableType *), CILcore_getCoreCfg, () );
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
