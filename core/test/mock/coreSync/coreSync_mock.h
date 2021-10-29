#ifndef __CORESYNC_MOCK_H__
#define __CORESYNC_MOCK_H__

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
#include "coreSync.h"

using namespace ::testing;
using ::testing::Return;

class CoreSync_MOCK
{
   public:
    CoreSync_MOCK()
    {}
    ~CoreSync_MOCK()
    {}

    MOCK_METHOD(
        void,
        coreSync_getBarrier,
        ( CosmOS_CoreVariableType * coreVar, BitWidthType barrierId ) );
};

class CoreSync_TestFixture : public ::testing::Test
{
   public:
    CoreSync_TestFixture()
    {
        _CoreSyncMock.reset( new ::testing::NiceMock<CoreSync_MOCK>() );
    }
    ~CoreSync_TestFixture()
    {
        _CoreSyncMock.reset();
    }

    static std::unique_ptr<CoreSync_MOCK> _CoreSyncMock;

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
