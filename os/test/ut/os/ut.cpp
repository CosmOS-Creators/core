#include <gtest/gtest.h>
#include <future>

#include "scheduler_mock.h"
#include "core_mock.h"

#include "os.h"

#include "utCfg.h"

#include <future>
#define TEST_TIMEOUT_BEGIN std::promise<bool> promisedFinished; \
 auto futureResult = promisedFinished.get_future(); \
 std::thread([](std::promise<bool>& finished) {
#define TEST_TIMEOUT_FAIL_END(X) finished.set_value(true); \
 } , std::ref(promisedFinished)).detach(); \
EXPECT_TRUE(futureResult.wait_for(std::chrono::milliseconds(X))!= \
 std::future_status::timeout);
#define TEST_TIMEOUT_SUCCESS_END(X) finished.set_value(true); \
 }, std::ref(promisedFinished)).detach(); \
EXPECT_FALSE(futureResult.wait_for(std::chrono::milliseconds(X))!= \
 std::future_status::timeout);

TEST(os_start, executionFlow)
{
	Scheduler_TestFixture schedulerMock;

	EXPECT_CALL(*schedulerMock._SchedulerMock, scheduler_start()).Times(1);

	os_start(0);
}

TEST(os_getOsVar, returnValue)
{
	CosmOS_OsVariableType * osVarRet;

	osVarRet = os_getOsVar();

	ASSERT_EQ(osVarRet, &OsVar);
}

TEST(os_kernelPanic, executionFlow)
{
	Core_TestFixture coreMock;
	UtCfg_TestFixture utCfgMock;

	EXPECT_CALL(*coreMock._CoreMock, core_getCoreVar()).Times(1).WillOnce(Return(&CoresVar[0]));
	EXPECT_CALL(*utCfgMock._UtCfgMock, dummyKernelPanic_core0()).Times(1);

	TEST_TIMEOUT_BEGIN
	os_kernelPanic();
	TEST_TIMEOUT_SUCCESS_END(1000)
}
