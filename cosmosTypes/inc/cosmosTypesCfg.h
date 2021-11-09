/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file cosmosTypesCfg.h
*********************************************************************************
<!--                   cosmosTypesCfg Unit Group Definition                   -->
*********************************************************************************
** @defgroup cosmosTypesCfg_unit cosmosTypesCfg Unit
** @ingroup cosmosTypes_module
** @brief cosmosTypesCfg Unit
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
<!--                cosmosTypesCfg Unit Global Group Definition               -->
*********************************************************************************
** @defgroup Global_cosmosTypesCfg Global
** @ingroup cosmosTypesCfg_unit
** @brief cosmosTypesCfg globals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __COSMOSTYPESCFG_H__
#define __COSMOSTYPESCFG_H__
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
#include "cosmosTypesVar.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_cosmosTypesCfg_h Macros
  * @ingroup Global_cosmosTypesCfg
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_cosmosTypesCfg_h
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Stop                           **
********************************************************************************/
/********************************************************************************
**                              Typedefs | Start                               **
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_BufferVariableType struct type
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Typedefs_cosmosTypesCfgCfg_h Typedefs
  * @ingroup Global_cosmosTypesCfg
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_ProgramSectionConfigurationType struct type
********************************************************************************/
typedef struct
{
    unsigned char * const startAddress;
    unsigned char * const endAddress;
    unsigned char * const flashAddress;

} CosmOS_ProgramSectionConfigurationType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_BootSectionConfigurationType struct type
********************************************************************************/
typedef struct
{
    const CosmOS_ProgramSectionConfigurationType * const programSections;
    const BitWidthType programSectionsNumber;

} CosmOS_BootSectionConfigurationType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_PermissionsConfigurationType struct type
********************************************************************************/
typedef struct
{
    const BitWidthType * const bitLocksSchedulables;
    const BitWidthType * const bitLocksSchedulablesInverted;

} CosmOS_PermissionsConfigurationType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_BufferConfigurationType struct type
********************************************************************************/
typedef struct
{
    const CosmOS_GenericVoidType * const routeFunc;
    const BitWidthType * const routeIdToFunc;
    const BitWidthType * const routeIdToEntity;

} CosmOS_RoutesConfigurationType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_BufferConfigurationType struct type
********************************************************************************/
typedef struct
{
    CosmOS_BufferVariableType * const var;
    unsigned char * const buffer;
    const BitWidthType id;
    const BitWidthType size;
    const CosmOS_PermissionsConfigurationType * const readPermission;
    const CosmOS_PermissionsConfigurationType * const writePermission;
    const CosmOS_BooleanType isInterCore;
    const BitWidthType spinlockId;

} CosmOS_BufferConfigurationType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_BufferDoublePairConfigurationType struct type
********************************************************************************/
typedef struct
{
    const CosmOS_BufferConfigurationType * const buffer;

} CosmOS_BufferDoublePairConfigurationType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_BufferDoubleConfigurationType struct type
********************************************************************************/
typedef struct
{
    CosmOS_BufferDoubleVariableType * const var;
    const CosmOS_BufferDoublePairConfigurationType * const bufferPair;

} CosmOS_BufferDoubleConfigurationType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_StackConfigurationType struct type
********************************************************************************/
typedef struct
{
    const BitWidthType stackSize;
    const AddressType stackLowAddress;
    const AddressType stackHighAddress;

} CosmOS_StackConfigurationType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_HeapConfigurationType struct type
********************************************************************************/
typedef struct
{
    const BitWidthType heapSize;
    const AddressType heapLowAddress;
    const AddressType heapHighAddress;

} CosmOS_HeapConfigurationType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_SchedulableConfigurationType struct type
********************************************************************************/
typedef struct
{
    CosmOS_SchedulableVariableType * const var;
    const CosmOS_StackConfigurationType * const stack;
    const CosmOS_SchedulableInstanceType instanceType;
    const CosmOS_GenericVoidType handler;
    const CosmOS_BooleanType fp;
    const BitWidthType id;
    const BitWidthType instanceId;
    const BitWidthType programId;
    const BitWidthType coreId;
    const BitWidthType alarmId;
    const AddressType peripheralAccessLowAddress;
    const AddressType peripheralAccessHighAddress;
    const BitWidthType peripheralAccessSize;

} CosmOS_SchedulableConfigurationType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_TaskConfigurationType struct type
********************************************************************************/
typedef struct
{
    CosmOS_TaskVariableType * const var;
    const CosmOS_SchedulableConfigurationType * const schedulable;
    const BitWidthType wcet;

} CosmOS_TaskConfigurationType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_ThreadConfigurationType struct type
********************************************************************************/
typedef struct
{
    CosmOS_ThreadVariableType * const var;
    const CosmOS_SchedulableConfigurationType * const schedulable;
    const BitWidthType priority;

} CosmOS_ThreadConfigurationType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_ProgramConfigurationType struct type
********************************************************************************/
typedef struct
{
    CosmOS_ProgramVariableType * const var;
    const BitWidthType coreId;
    const BitWidthType numberOfTasks;
    const BitWidthType numberOfThreads;
    const BitWidthType programMemorySize;
    const AddressType programMemoryLowAddress;
    const AddressType programMemoryHighAddress;
    const CosmOS_HeapConfigurationType * const heap;
    const CosmOS_TaskConfigurationType * const taskCfgs;
    const CosmOS_ThreadConfigurationType * const threadCfgs;
    CosmOS_MutexVariableType * const heapMutex;

} CosmOS_ProgramConfigurationType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_ScheduleTableConfigurationType struct type
********************************************************************************/
typedef struct
{
    const BitWidthType startTick;
    const CosmOS_TaskConfigurationType * const taskCfg;

} CosmOS_ScheduleTableConfigurationType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_ThreadListConfigurationType struct type
********************************************************************************/
typedef struct
{
    const CosmOS_ThreadConfigurationType * const threadCfg;

} CosmOS_ThreadListConfigurationType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_AlarmConfigurationType struct type
********************************************************************************/
typedef struct
{
    CosmOS_AlarmVariableType * const var;
    const CosmOS_SchedulableConfigurationType * const schedulableCfg;

} CosmOS_AlarmConfigurationType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_SchedulerConfigurationType struct type
********************************************************************************/
typedef struct
{
    CosmOS_SchedulerVariableType * const var;
    const CosmOS_ScheduleTableConfigurationType * const scheduleTable;
    const CosmOS_ThreadListConfigurationType * const threadList;
    const BitWidthType hyperTick;
    const BitWidthType preemptTick;
    const BitWidthType scheduleTableElementsNum;
    const BitWidthType threadListElementsNum;
    const BitWidthType lastToFirstTaskTicks;
    const BitWidthType syncTicks;
    const BitWidthType firstSyncTaskStartTick;
    const BitWidthType maxTimerTick;
    const BitWidthType timerTickCount;
    const CosmOS_TaskConfigurationType * const idleTask;
    const CosmOS_AlarmConfigurationType * const alarmCfgs;

} CosmOS_SchedulerConfigurationType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_SysJobsGroupConfigurationType struct type
********************************************************************************/
typedef struct
{
    const CosmOS_GenericVoidType * const handlers;
    const BitWidthType numOfHandlers;
    const BitWidthType tickMultiplicator;

} CosmOS_SysJobsGroupConfigurationType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_SysJobsGroupConfigurationType struct type
********************************************************************************/
typedef struct
{
    CosmOS_SysJobsVariableType * const var;
    const CosmOS_SysJobsGroupConfigurationType * const groups;
    const BitWidthType numOfGroups;
    const BitWidthType hyperTick;

} CosmOS_SysJobsConfigurationType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_CoreConfigurationType struct type
********************************************************************************/
typedef struct
{
    CosmOS_CoreVariableType * const var;
    const CosmOS_ProgramConfigurationType * const programs;
    const BitWidthType numberOfPrograms;
    const CosmOS_SchedulerConfigurationType * const scheduler;
    const BitWidthType coreId;
    const CosmOS_GenericVoidType kernelPanicHook;
    const AddressType stackMemoryLowAddress;
    const AddressType stackMemoryHighAddress;
    const AddressType codeMemoryLowAddress;
    const AddressType codeMemoryHighAddress;
    const AddressType unprotectedMemoryLowAddress;
    const AddressType unprotectedMemoryHighAddress;
    const BitWidthType msToTicks;
    const BitWidthType numberOfAlarms;
    const CosmOS_ProgramConfigurationType * const programCfgs;
    const CosmOS_SchedulerConfigurationType * const schedulerCfg;
    CosmOS_BarrierVariableType * const barrierVars;
    const CosmOS_SysJobsConfigurationType * const sysJobsCfg;

} CosmOS_CoreConfigurationType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_OsConfigurationType struct type
********************************************************************************/
typedef struct
{
    CosmOS_OsVariableType * const var;
    const CosmOS_CoreConfigurationType * const cores;
    const BitWidthType numberOfCores;
    const CosmOS_BufferConfigurationType * const buffers;
    const BitWidthType numberOfBuffers;
    const CosmOS_RoutesConfigurationType * const route;
    const BitWidthType numberOfSpinlocks;
    const CosmOS_CoreConfigurationType * const coreCfgs;
    const CosmOS_BufferConfigurationType * const bufferCfgs;
    const CosmOS_BufferDoubleConfigurationType * const bufferDoubleCfgs;
    CosmOS_SpinlockVariableType * const spinlockVars;

} CosmOS_OsConfigurationType;
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Typedefs_cosmosTypesCfg_h
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
