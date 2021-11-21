#ifndef __OSBOOTMOCK_H__
#define __OSBOOTMOCK_H__

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
#include "osBoot.h"

using namespace ::testing;
using ::testing::Return;

class OsBoot_MOCK
{
   public:
    OsBoot_MOCK()
    {}
    ~OsBoot_MOCK()
    {}

    MOCK_METHOD( void, osBoot_bootValidate, () );
};

class OsBoot_TestFixture : public ::testing::Test
{
   public:
    OsBoot_TestFixture()
    {
        _OsBootMock.reset( new ::testing::NiceMock<OsBoot_MOCK>() );
    }
    ~OsBoot_TestFixture()
    {
        _OsBootMock.reset();
    }

    static std::unique_ptr<OsBoot_MOCK> _OsBootMock;

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
