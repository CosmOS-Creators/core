#ifndef __SCHEDULER_MOCK_H__
#define __SCHEDULER_MOCK_H__

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
#include "scheduler.h"

using namespace ::testing;
using ::testing::Return;

class Scheduler_MOCK
{
   public:
    Scheduler_MOCK()
    {}
    ~Scheduler_MOCK()
    {}

    MOCK_METHOD( (void), scheduler_start, () );
};

class Scheduler_TestFixture : public ::testing::Test
{
   public:
    Scheduler_TestFixture()
    {
        _SchedulerMock.reset( new ::testing::NiceMock<Scheduler_MOCK>() );
    }
    ~Scheduler_TestFixture()
    {
        _SchedulerMock.reset();
    }

    static std::unique_ptr<Scheduler_MOCK> _SchedulerMock;

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
