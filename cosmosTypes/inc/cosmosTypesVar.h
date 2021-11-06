/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file cosmosTypesVar.h
*********************************************************************************
<!--                   cosmosTypesVar Unit Group Definition                   -->
*********************************************************************************
** @defgroup cosmosTypesVar_unit cosmosTypesVar Unit
** @ingroup cosmosTypes_module
** @brief cosmosTypesVar Unit
** @details lorem
*********************************************************************************
<!--                           Version Information                            -->
*********************************************************************************
** @version 1.0.0
** @date 1.8.2020
** @author https://github.com/PavolKostolansky
*********************************************************************************
<!--                          Warnings and License                            -->
*********************************************************************************
** @warning Modifying code can lead to unexpected behaviour of the whole system
** @copyright MIT License
*********************************************************************************
<!--              cosmosTypesVar Unit Global Group Definition                 -->
*********************************************************************************
** @defgroup Global_cosmosTypesVar Global
** @ingroup cosmosTypesVar_unit
** @brief cosmosTypesVar globals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __COSMOSTYPESVAR_H__
#define __COSMOSTYPESVAR_H__
/********************************************************************************
**                         START OF C++ SUPPORT SECTION                        **
********************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "cosmosTypesCfg.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_cosmosTypesVar_h Macros
  * @ingroup Global_cosmosTypesVar
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_cosmosTypesVar_h
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Stop                           **
********************************************************************************/
/********************************************************************************
**                              Typedefs | Start                               **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Typedefs_cosmosTypesVarCfg_h Typedefs
  * @ingroup Global_cosmosTypesVar
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_ProgramVariableType struct type
********************************************************************************/
typedef struct
{
    const CosmOS_ProgramConfigurationType * const cfg;
    const CosmOS_TaskConfigurationType * const taskCfgs;
    const CosmOS_ThreadConfigurationType * const threadCfgs;
    BitWidthType numberOfMallocVars;

} CosmOS_ProgramVariableType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_SchedulerVariableType struct type
********************************************************************************/
typedef struct
{
    const CosmOS_SchedulerConfigurationType * const cfg;
    BitWidthType currentTick;
    BitWidthType priorTickStep;
    BitWidthType scheduleTableIterator;
    BitWidthType threadListIterator;
    CosmOS_SchedulerStateType schedulerState;
    BitWidthType nextSyncTick;
    CosmOS_BooleanType syncInitState;
    CosmOS_RescheduleTriggerStateType rescheduleTriggerState;

} CosmOS_SchedulerVariableType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_SysJobsGroupVariableType struct type
********************************************************************************/
typedef struct
{
    const CosmOS_SysJobsConfigurationType * const cfg;
    BitWidthType currentTick;

} CosmOS_SysJobsVariableType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_AlarmVariableType struct type
********************************************************************************/
typedef struct
{
    const CosmOS_AlarmConfigurationType * const cfg;
    CosmOS_AlarmStateType state;
    BitWidthType tickCount;

} CosmOS_AlarmVariableType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_SpinlockVariableType struct type
********************************************************************************/
typedef struct
{
    BitWidthType spinlock;
    const CosmOS_SchedulableConfigurationType * schedulableOwner;

} CosmOS_SpinlockVariableType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_CoreVariableType struct type
********************************************************************************/
typedef struct
{
    const CosmOS_CoreConfigurationType * const cfg;
    const CosmOS_SchedulableConfigurationType * schedulableInExecution;
    CosmOS_ProgramVariableType * programInExecution;
    CosmOS_ProgramVariableType * const programVars;
    CosmOS_SchedulerVariableType * const schedulerVar;
    CosmOS_BarrierVariableType * const barrierVars;
    CosmOS_OsStateType osState;
    CosmOS_SysJobsVariableType * const sysJobs;
    CosmOS_AlarmVariableType * const alarmVars;

} CosmOS_CoreVariableType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_OsVariableType struct type
********************************************************************************/
typedef struct
{
    const CosmOS_OsConfigurationType * const cfg;
    CosmOS_CoreVariableType * const coreVars;
    const CosmOS_BufferConfigurationType * const bufferCfgs;
    const CosmOS_BufferDoubleConfigurationType * const bufferDoubleCfgs;
    CosmOS_SpinlockVariableType * const spinlockVars;

} CosmOS_OsVariableType;
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Typedefs_cosmosTypesVar_h
********************************************************************************/
/********************************************************************************
**                              Typedefs | Stop                                **
********************************************************************************/
#ifdef __cplusplus
}
#endif
/********************************************************************************
**                         END OF C++ SUPPORT SECTION                          **
********************************************************************************/
#endif
/********************************************************************************
**                           END OF THE HEADER FILE                            **
********************************************************************************/
