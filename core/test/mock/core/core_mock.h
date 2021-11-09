#ifndef __CORE_MOCK_H__
#define __CORE_MOCK_H__

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
#include "core.h"

using namespace ::testing;
using ::testing::Return;

class Core_MOCK
{
   public:
    Core_MOCK()
    {}
    ~Core_MOCK()
    {}

    MOCK_METHOD( (CosmOS_CoreConfigurationType *), core_getCoreCfg, () );
};

class Core_TestFixture : public ::testing::Test
{
   public:
    Core_TestFixture()
    {
        _CoreMock.reset( new ::testing::NiceMock<Core_MOCK>() );
    }
    ~Core_TestFixture()
    {
        _CoreMock.reset();
    }

    static std::unique_ptr<Core_MOCK> _CoreMock;

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
