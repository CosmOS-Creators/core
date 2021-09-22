#include <gtest/gtest.h>

#include "CILcore_mock.h"

#include "core.h"

#include "utCfg.h"

TEST(core_getCoreVar, executionFlow)
{
	CosmOS_CoreVariableType * coreVar;

	CILcore_TestFixture CILcoreMock;

	EXPECT_CALL(*CILcoreMock._CILcoreMock, CILcore_getCoreVar()).Times(1).WillOnce(Return(&CoresVar[0]));;

	coreVar = core_getCoreVar();

	ASSERT_EQ(coreVar, &CoresVar[0]);
}
