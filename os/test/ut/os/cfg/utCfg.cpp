/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file utCfg.cpp
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
#include "utCfg.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_os_ut_c Macros
  * @ingroup Test_os
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_os_ut_c
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Stop                           **
********************************************************************************/
/********************************************************************************
**                              Variables | Start                              **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Variables_os_ut_c Variables
  * @ingroup Test_os
  * @{
********************************************************************************/
std::unique_ptr<UtCfg_MOCK> UtCfg_TestFixture::_UtCfgMock;

CosmOS_CoreVariableType CoresVar[CORE_NUM] IS_INITIALIZED_TO{
    {
        (CosmOS_SchedulableConfigurationType *)NULL,
        (CosmOS_ProgramConfigurationType *)NULL,
        OS_STATE_ENUM__NOT_INITIALIZED,
    },
    {
        (CosmOS_SchedulableConfigurationType *)NULL,
        (CosmOS_ProgramConfigurationType *)NULL,
        OS_STATE_ENUM__NOT_INITIALIZED,
    },
};

CosmOS_CoreConfigurationType CoresCfgConst[CORE_NUM] IS_INITIALIZED_TO{
    {
        &CoresVar[CORE_0_ID],
        (CosmOS_ProgramConfigurationType *)NULL,
        2,
        (CosmOS_SchedulerConfigurationType *)NULL,
        0,
        dummyKernelPanic_core0,
        200,
        210,
        300,
        310,
        400,
        500,
        10,
        11,
        (CosmOS_ProgramConfigurationType *)NULL,
        (CosmOS_SchedulerConfigurationType *)NULL,
        (CosmOS_BarrierVariableType *)NULL,
        (CosmOS_SysJobsConfigurationType *)NULL,
    },
    {
        &CoresVar[CORE_1_ID],
        (CosmOS_ProgramConfigurationType *)NULL,
        2,
        (CosmOS_SchedulerConfigurationType *)NULL,
        1,
        (CosmOS_GenericVoidType)NULL,
        200,
        210,
        300,
        310,
        400,
        500,
        10,
        11,
        (CosmOS_ProgramConfigurationType *)NULL,
        (CosmOS_SchedulerConfigurationType *)NULL,
        (CosmOS_BarrierVariableType *)NULL,
        (CosmOS_SysJobsConfigurationType *)NULL,
    },
};

CosmOS_OsVariableType OsVar IS_INITIALIZED_TO{
    0,
};

CosmOS_OsConfigurationType OsCfg IS_INITIALIZED_TO{
    &OsVar,
    (CosmOS_CoreConfigurationType *)NULL,
    2,
    (CosmOS_BufferConfigurationType *)NULL,
    2,
    (CosmOS_RoutesConfigurationType *)NULL,
    2,
    (CosmOS_BufferConfigurationType *)NULL,
    (CosmOS_BufferDoubleConfigurationType *)NULL,
    (CosmOS_SpinlockVariableType *)NULL,
    (CosmOS_OsEventConfigurationType *)NULL,
    (CosmOS_ChannelConfigurationType *)NULL,
    0,
    (CosmOS_SemaphoreVariableType *)NULL,
    0,
};
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_os_ut_c
********************************************************************************/
/********************************************************************************
**                              Variables | Stop                               **
********************************************************************************/
/********************************************************************************
**                           Test Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup functions_os_ut_c Functions
  * @ingroup Test_os
  * @{
********************************************************************************/
void
dummyKernelPanic_core0()
{
    UtCfg_TestFixture::_UtCfgMock->dummyKernelPanic_core0();
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  functions_os_ut_c
********************************************************************************/
/********************************************************************************
**                           Test Definitions | Stop                           **
********************************************************************************/
/********************************************************************************
**                           END OF THE SOURCE FILE                            **
********************************************************************************/
