#include <gmock/gmock.h>
#include "scheduler.h"
#include "scheduler_mock.h"

std::unique_ptr<Scheduler_MOCK> Scheduler_TestFixture::_SchedulerMock;

void
scheduler_start()
{
    Scheduler_TestFixture::_SchedulerMock->scheduler_start();
}
