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

const CosmOS_CoreConfigurationType CoresCfgConst[CORE_NUM] IS_INITIALIZED_TO{
    {
        (CosmOS_ProgramConfigurationType *)
            NULL,
        2,
        (CosmOS_SchedulerConfigurationType *)
            NULL,
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
    },
    {
        (CosmOS_ProgramConfigurationType *)
            NULL,
        2,
        (CosmOS_SchedulerConfigurationType *)
            NULL,
        1,
        (CosmOS_GenericVoidType)
            NULL,
        200,
        210,
        300,
        310,
        400,
        500,
        10,
        11,
    },
};

CosmOS_CoreVariableType CoresVar[CORE_NUM] IS_INITIALIZED_TO{
    {
        &CoresCfgConst
            [CORE_0_ID],
        (CosmOS_SchedulableVariableType *)
            NULL,
        (CosmOS_ProgramVariableType *)
            NULL,
        (CosmOS_ProgramVariableType *)
            NULL,
        (CosmOS_SchedulerVariableType *)
            NULL,
        (CosmOS_BarrierVariableType *)
            NULL,
        OS_STATE_ENUM__NOT_INITIALIZED,
        (CosmOS_SysJobsVariableType *)
            NULL,
    },
    {
        &CoresCfgConst
            [CORE_1_ID],
        (CosmOS_SchedulableVariableType *)
            NULL,
        (CosmOS_ProgramVariableType *)
            NULL,
        (CosmOS_ProgramVariableType *)
            NULL,
        (CosmOS_SchedulerVariableType *)
            NULL,
        (CosmOS_BarrierVariableType *)
            NULL,
        OS_STATE_ENUM__NOT_INITIALIZED,
        (CosmOS_SysJobsVariableType *)
            NULL,
    },
};

const CosmOS_OsConfigurationType OsCfg IS_INITIALIZED_TO{
    (CosmOS_CoreConfigurationType *)
        NULL,
    2,
    (CosmOS_BufferConfigurationType *)
        NULL,
    2,
    (CosmOS_RoutesConfigurationType *)
        NULL,
    2,
};

CosmOS_OsVariableType OsVar IS_INITIALIZED_TO{
    &OsCfg,
    (CosmOS_CoreVariableType *)
        NULL,
    (CosmOS_BufferVariableType *)
        NULL,
    (CosmOS_BufferDoubleVariableType *)
        NULL,
    (CosmOS_SpinlockVariableType *)
        NULL,
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
