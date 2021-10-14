#ifndef __UTCFG_H__
#define __UTCFG_H__

#include <memory>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

/* CORE interfaces */
#include "sysDefs.h"
#include "cosmosTypes.h"
#include "memoryMapping.h"

void dummyKernelPanic_core0(void);

extern const CosmOS_OsConfigurationType OsCfg;
extern CosmOS_OsVariableType OsVar;

extern const CosmOS_CoreConfigurationType CoresCfgConst[2];
extern CosmOS_CoreVariableType CoresVar[2];

using namespace ::testing;
using ::testing::Return;

class UtCfg_MOCK{
public:
		UtCfg_MOCK(){}
    ~UtCfg_MOCK(){}

    MOCK_METHOD((void), dummyKernelPanic_core0, ());
};

class UtCfg_TestFixture: public ::testing::Test{
public:
    UtCfg_TestFixture(){
        _UtCfgMock.reset(new ::testing::NiceMock<UtCfg_MOCK>());
    }
    ~UtCfg_TestFixture(){
        _UtCfgMock.reset();
    }

    // pointer for accessing mocked library
    static std::unique_ptr<UtCfg_MOCK> _UtCfgMock;

protected:
    virtual void SetUp(){}
		virtual void TestBody(){}
    virtual void TearDown(){}
};

#endif
