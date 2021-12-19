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
#include "cosmosTypesStd.h"
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
  * @brief CosmOS_MallocVariableType
********************************************************************************/
typedef struct
{
    void * prior;
    void * next;
    BitWidthType size;

} CosmOS_MallocVariableType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_MutexVariableType struct type
********************************************************************************/
typedef struct
{
    BitWidthType mutex;
    const CosmOS_SchedulableConfigurationType * schedulableOwner;

} CosmOS_MutexVariableType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_SemaphoreVariableType struct type
********************************************************************************/
typedef struct
{
    BitWidthType semaphore;
    const CosmOS_SchedulableConfigurationType * schedulableOwner;

} CosmOS_SemaphoreVariableType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_TaskVariableType struct type
********************************************************************************/
typedef struct
{
    CosmOS_BarrierStateType barrierState;

} CosmOS_BarrierVariableType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_BufferVariableType struct type
********************************************************************************/
typedef struct
{
    BitWidthType head;
    BitWidthType tail;
    BitWidthType fullCells;

} CosmOS_BufferVariableType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_BufferDoubleVariableType struct type
********************************************************************************/
typedef struct
{
    BitWidthType activeKernelBufferId;
    BitWidthType activeUserBufferId;

} CosmOS_BufferDoubleVariableType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_SchedulableVariableType struct type
********************************************************************************/
typedef struct
{
    CosmOS_SchedulableStateType state;
    StackPointerType stackPointer;

} CosmOS_SchedulableVariableType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_TaskVariableType struct type
********************************************************************************/
typedef struct
{
    BitWidthType dummy;

} CosmOS_TaskVariableType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_ThreadVariableType struct type
********************************************************************************/
typedef struct
{
    CosmOS_MutexVariableType * blockingMutexVar;
    CosmOS_SemaphoreVariableType * blockingSemaphoreVar;

} CosmOS_ThreadVariableType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_ProgramVariableType struct type
********************************************************************************/
typedef struct
{
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
    CosmOS_RescheduleTriggerStateType rescheduleTriggerState;
    BitWidthType currentTick;
    BitWidthType priorTickStep;
    BitWidthType scheduleTableIterator;
    BitWidthType threadListIterator;
    CosmOS_SchedulerStateType schedulerState;
    BitWidthType nextSyncTick;
    CosmOS_BooleanType syncInitState;
    BitWidthType timerOffset;

} CosmOS_SchedulerVariableType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_SysJobsGroupVariableType struct type
********************************************************************************/
typedef struct
{
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
    const CosmOS_SchedulableConfigurationType * schedulableInExecution;
    const CosmOS_ProgramConfigurationType * programInExecution;
    CosmOS_OsStateType osState;

} CosmOS_CoreVariableType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_OsEventVariableType struct type
********************************************************************************/
typedef struct
{
    BitWidthType event;

} CosmOS_OsEventVariableType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_ChannelVariableType struct type
********************************************************************************/
typedef struct
{
    CosmOS_BooleanType initialized;
    CosmOS_ChannelPoolStateType sendPoolState;
    BitWidthType sendPoolPayloadLength;
    const CosmOS_SchedulableConfigurationType * sendPoolSchedulableOwner;
    CosmOS_BooleanType senderWaitingForResponse;
    CosmOS_ChannelPoolStateType replyPoolState;
    BitWidthType replyPoolPayloadLength;

} CosmOS_ChannelVariableType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_OsVariableType struct type
********************************************************************************/
typedef struct
{
    BitWidthType dummy;

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
