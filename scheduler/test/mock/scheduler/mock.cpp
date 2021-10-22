#include <gmock/gmock.h>
#include "scheduler.h"
#include "scheduler_mock.h"


// instantiate mocked lib
std::unique_ptr<Scheduler_MOCK> Scheduler_TestFixture::_SchedulerMock;

// fake lib functions
void scheduler_start()
{
    Scheduler_TestFixture::_SchedulerMock->scheduler_start();
}
