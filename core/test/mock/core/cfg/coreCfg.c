/********************************************************************************
**                                                                             **
**                       GENERATED FILE BY CosmOS CustomBox                    **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file coreCfg.c
*********************************************************************************
<!--                   coreCfg Unit Local Group Definition                    -->
*********************************************************************************
** @defgroup Local_coreCfg Local
** @ingroup coreCfg_unit
** @brief coreCfg locals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "coreCfg.h"
#include "coreSyncCfg.h"
#include "programCfg.h"
#include "sysJobsCfg.h"
#include "schedulerCfg.h"
#include "userKernelPanicHook_CM7.h"
#include "userKernelPanicHook_CM4.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_coreCfg_c Macros
  * @ingroup Local_coreCfg
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Macros_coreCfg_c
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
  * @defgroup Variables_coreCfg_c Variables
  * @ingroup Local_coreCfg
  * @{
********************************************************************************/
/* @cond S */
__SEC_START(__OS_CONSTS_SECTION_START)
/* @endcond*/
const CosmOS_CoreConfigurationType CoresCfgConst[CORE_NUM] __OS_CONSTS_SECTION
IS_INITIALIZED_TO
{
		{                                               /* CoresCfgConst[CORE_0_ID]                         */
        ProgramsCore0CfgConst,                      /* const CosmOS_ProgramConfigurationType * programs    */
        PROGRAM_CORE_0_NUM,                         /* const BitWidthType numberOfPrograms              */
        &SchedulersCfgConst[SCHEDULER_CORE_0_ID],   /* CosmOS_SchedulerConfigurationType * scheduler       */
		CORE_0_ID,		 /* const BitWidthType coreId       */
		userKernelPanicHook_CM7,		/* const CosmOS_GenericVoidType kernelPanicHook   */
		CORE_0_STACK_MEMORY_LOW_ADDRESS,		/* const AddressType stackMemoryLowAddress   */
		CORE_0_STACK_MEMORY_HIGH_ADDRESS,		/* const AddressType stackMemoryHighAddress   */
		CORE_0_CODE_MEMORY_LOW_ADDRESS,		/* const AddressType codeMemoryLowAddress   */
		CORE_0_CODE_MEMORY_HIGH_ADDRESS,		/* const AddressType codeMemoryHighAddress   */
    },
		{                                               /* CoresCfgConst[CORE_1_ID]                         */
        ProgramsCore1CfgConst,                      /* const CosmOS_ProgramConfigurationType * programs    */
        PROGRAM_CORE_1_NUM,                         /* const BitWidthType numberOfPrograms              */
        &SchedulersCfgConst[SCHEDULER_CORE_1_ID],   /* CosmOS_SchedulerConfigurationType * scheduler       */
		CORE_1_ID,		 /* const BitWidthType coreId       */
		userKernelPanicHook_CM4,		/* const CosmOS_GenericVoidType kernelPanicHook   */
		CORE_1_STACK_MEMORY_LOW_ADDRESS,		/* const AddressType stackMemoryLowAddress   */
		CORE_1_STACK_MEMORY_HIGH_ADDRESS,		/* const AddressType stackMemoryHighAddress   */
		CORE_1_CODE_MEMORY_LOW_ADDRESS,		/* const AddressType codeMemoryLowAddress   */
		CORE_1_CODE_MEMORY_HIGH_ADDRESS,		/* const AddressType codeMemoryHighAddress   */
    },
};
/* @cond S */
__SEC_STOP(__OS_CONSTS_SECTION_STOP)
/* @endcond*/

/* @cond S */
__SEC_START(__OS_VARS_SECTION_START)
/* @endcond*/
CosmOS_CoreVariableType CoresVar[CORE_NUM] __OS_VARS_SECTION
IS_INITIALIZED_TO
{
		{                                               /* CoresVar[CORE_0_ID]                                  */
        &CoresCfgConst[CORE_0_ID],                  /* const CosmOS_CoreConfigurationType *cfg                 */
        NULL,                                       /* CosmOS_SchedulableVariableType * schedulableInExecution    */
        NULL,                                       /* CosmOS_ProgramVariableType * programInCurrentContext       */
        ProgramsCore0Var,                           /* CosmOS_ProgramVariableType * programVars                */
        &SchedulersVar[SCHEDULER_CORE_0_ID],        /* CosmOS_SchedulerVariableType * scheduler                */
        BarriersCore0Var,                           /* CosmOS_BarrierVariableType * barrierVars                */
        OS_STATE_ENUM__NOT_INITIALIZED,                 /* CosmOS_OsState osState                                  */
        &SysJobsVar[CORE_0_ID],                 /* CosmOS_SysJobsVariableType * const sysJobs               */
    },
		{                                               /* CoresVar[CORE_1_ID]                                  */
        &CoresCfgConst[CORE_1_ID],                  /* const CosmOS_CoreConfigurationType *cfg                 */
        NULL,                                       /* CosmOS_SchedulableVariableType * schedulableInExecution    */
        NULL,                                       /* CosmOS_ProgramVariableType * programInCurrentContext       */
        ProgramsCore1Var,                           /* CosmOS_ProgramVariableType * programVars                */
        &SchedulersVar[SCHEDULER_CORE_1_ID],        /* CosmOS_SchedulerVariableType * scheduler                */
        BarriersCore1Var,                           /* CosmOS_BarrierVariableType * barrierVars                */
        OS_STATE_ENUM__NOT_INITIALIZED,                 /* CosmOS_OsState osState                                  */
        &SysJobsVar[CORE_1_ID],                 /* CosmOS_SysJobsVariableType * const sysJobs               */
    },
};
/* @cond S */
__SEC_STOP(__OS_VARS_SECTION_STOP)
/* @endcond*/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Variables_coreCfg_c
********************************************************************************/
/********************************************************************************
**                              Variables | Stop                               **
********************************************************************************/
/********************************************************************************
**                         Function Prototypes | Start                         **
********************************************************************************/
/********************************************************************************
  * DOXYGEN DEF GROUP                                                          **
  * *************************************************************************//**
  * @defgroup Apis_coreCfg_c API's
  * @ingroup Local_coreCfg
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_coreCfg_c Getters
  * @ingroup Apis_coreCfg_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Getters_coreCfg_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_coreCfg_c Setters
  * @ingroup Apis_coreCfg_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Setters_coreCfg_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_coreCfg_c General
  * @ingroup Apis_coreCfg_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_coreCfg_c
********************************************************************************/
/********************************************************************************
**                         Function Prototypes | Stop                          **
********************************************************************************/
/********************************************************************************
**                        Function Definitions | Start                         **
********************************************************************************/
/********************************************************************************
**                        Function Definitions | Stop                          **
********************************************************************************/
/********************************************************************************
**                           END OF THE SOURCE FILE                            **
********************************************************************************/