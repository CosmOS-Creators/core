/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file scheduler.h
*********************************************************************************
<!--                     scheduler Module Group Definition                    -->
*********************************************************************************
** @defgroup scheduler_module scheduler
** @brief scheduler Module
** @details lorem
*********************************************************************************
<!--                      scheduler Unit Group Definition                     -->
*********************************************************************************
** @defgroup scheduler_unit scheduler Unit
** @ingroup scheduler_module
** @brief scheduler Unit
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
<!--                   scheduler Unit Global Group Definition                 -->
*********************************************************************************
** @defgroup Global_scheduler Global
** @ingroup scheduler_unit
** @brief scheduler globals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __SCHEDULER_H__
#define __SCHEDULER_H__
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
#include "sysDefs.h"
#include "memoryMapping.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_scheduler_h Macros
  * @ingroup Global_scheduler
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Macros_scheduler_h
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
  * @defgroup Variables_scheduler_h Variables
  * @ingroup Global_scheduler
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Variables_scheduler_h
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
  * @defgroup Apis_scheduler_h API's
  * @ingroup Global_scheduler
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_scheduler_h Getters
  * @ingroup Apis_scheduler_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Getters_scheduler_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_scheduler_h Setters
  * @ingroup Apis_scheduler_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Setters_scheduler_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_scheduler_h General
  * @ingroup Apis_scheduler_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn  scheduler_updateAlarms(CosmOS_CoreVariableType * coreVar, BitWidthType priorTickStep)
  *
  * @brief Update alarms DEMO.
  *
  * @param[in]  CosmOS_CoreVariableType * coreVar
  * @param[in]  BitWidthType priorTickStep
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void scheduler_updateAlarms(CosmOS_CoreVariableType *coreVar, BitWidthType priorTickStep);

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn  scheduler_performanceScheduling(CosmOS_SchedulerVariableType * schedulerVar, CosmOS_SchedulableVariableType ** schedulableVar,\
  * StackPointerType * stackPointerRetVal,BitWidthType * timerTicks)
  *
  * @brief Performance scheduling function. DEMO
  *
  * @param[in]  CosmOS_SchedulerVariableType * schedulerVar
  * @param[in]  CosmOS_SchedulableVariableType * schedulableVar
  * @param[in]  StackPointerType * stackPointerRetVal
  * @param[in]  BitWidthType * timerTicks
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void scheduler_performanceScheduling(CosmOS_SchedulerVariableType * schedulerVar, CosmOS_SchedulableVariableType ** schedulableVar,\
StackPointerType * stackPointerRetVal,BitWidthType * timerTicks);

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn  scheduler_classicScheduling(CosmOS_SchedulerVariableType * schedulerVar, CosmOS_SchedulableVariableType * schedulableVar,StackPointerType * stackPointerRetVal,
  * BitWidthType * timerTicks, BitWidthType startTick, BitWidthType currentTick)
  *
  * @brief Classic scheduling function. DEMO
  *
  * @param[in]  CosmOS_SchedulerVariableType * schedulerVar
  * @param[in]  CosmOS_SchedulableVariableType * schedulableVar
  * @param[in]  StackPointerType * stackPointerRetVal
  * @param[in]  BitWidthType * timerTicks
  * @param[in]  BitWidthType startTick
  * @param[in]  BitWidthType currentTick
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void scheduler_classicScheduling(CosmOS_SchedulerVariableType * schedulerVar, CosmOS_SchedulableVariableType ** schedulableVar,\
StackPointerType * stackPointerRetVal,BitWidthType * timerTicks, BitWidthType startTick, BitWidthType currentTick);

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_scheduleNextInstance(StackPointerType stackPointer)
  *
  * @brief Algorithm for scheduling next schedulable DEMO CODE.
  *
  * @param[in]  StackPointerType stackPointer
  *
  * @return BitWidthType
********************************************************************************/
__OS_FUNC_SECTION StackPointerType scheduler_scheduleNextInstance(StackPointerType stackPointer);

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_start(void)
  *
  * @brief Start of scheduler, pick the starting task and execute it DEMO CODE.
  *
  * @param[in]  none
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void scheduler_start(void);
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_scheduler_h
********************************************************************************/
/********************************************************************************
**                         Function Prototypes | Stop                          **
********************************************************************************/
/********************************************************************************
**                        Function Definitions | Start                         **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_scheduler_h Getters
  * @ingroup Apis_scheduler_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_getSchedulerScheduleTable(CosmOS_SchedulerVariableType * scheduler)
  *
  * @brief Get scheduler scheduleTable pointer.
  *
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  *
  * @return CosmOS_ScheduleTableConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_ScheduleTableConfigurationType * scheduler_getSchedulerScheduleTable(CosmOS_SchedulerVariableType * scheduler)
{
    return (CosmOS_ScheduleTableConfigurationType *)(scheduler->cfg->scheduleTable);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_getSchedulerHyperTick(CosmOS_SchedulerVariableType * scheduler)
  *
  * @brief Get scheduler hyperTick.
  *
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType scheduler_getSchedulerHyperTick(CosmOS_SchedulerVariableType * scheduler)
{
    return (scheduler->cfg->hyperTick);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_getSchedulerPreemptTick(CosmOS_SchedulerVariableType * scheduler)
  *
  * @brief Get scheduler preemptTick.
  *
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType scheduler_getSchedulerPreemptTick(CosmOS_SchedulerVariableType * scheduler)
{
    return (scheduler->cfg->preemptTick);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_getSchedulerScheduleTableElementsNum(CosmOS_SchedulerVariableType * scheduler)
  *
  * @brief Get scheduler scheduleTableElementsNum.
  *
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType scheduler_getSchedulerScheduleTableElementsNum(CosmOS_SchedulerVariableType * scheduler)
{
    return (scheduler->cfg->scheduleTableElementsNum);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_getSchedulerThreadListElementsNum(CosmOS_SchedulerVariableType * scheduler)
  *
  * @brief Get scheduler threadListElementsNum.
  *
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType scheduler_getSchedulerThreadListElementsNum(CosmOS_SchedulerVariableType * scheduler)
{
    return (scheduler->cfg->threadListElementsNum);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_getSchedulerLastToFirstTaskTicks(CosmOS_SchedulerVariableType * scheduler)
  *
  * @brief Get scheduler lastToFirstTaskTicks.
  *
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType scheduler_getSchedulerLastToFirstTaskTicks(CosmOS_SchedulerVariableType * scheduler)
{
    return (scheduler->cfg->lastToFirstTaskTicks);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_getSchedulerSyncTicks(CosmOS_SchedulerVariableType * scheduler)
  *
  * @brief Get scheduler syncTicks.
  *
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType scheduler_getSchedulerSyncTicks(CosmOS_SchedulerVariableType * scheduler)
{
    return (scheduler->cfg->syncTicks);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_getSchedulerFirstSyncTaskStartTick(CosmOS_SchedulerVariableType * scheduler)
  *
  * @brief Get scheduler firstSyncTaskStartTick.
  *
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType scheduler_getSchedulerFirstSyncTaskStartTick(CosmOS_SchedulerVariableType * scheduler)
{
    return (scheduler->cfg->firstSyncTaskStartTick);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_getSchedulerMaxTimerTick(CosmOS_SchedulerVariableType * scheduler)
  *
  * @brief Get scheduler maxTimerTick.
  *
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType scheduler_getSchedulerMaxTimerTick(CosmOS_SchedulerVariableType * scheduler)
{
    return (scheduler->cfg->maxTimerTick);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_getSchedulerTimerTickCount(CosmOS_SchedulerVariableType * scheduler)
  *
  * @brief Get scheduler timerTickCount.
  *
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType scheduler_getSchedulerTimerTickCount(CosmOS_SchedulerVariableType * scheduler)
{
    return (scheduler->cfg->timerTickCount);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_getSchedulerIdleTaskVar(CosmOS_SchedulerVariableType * scheduler)
  *
  * @brief Get scheduler idleTaskVar.
  *
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  *
  * @return CosmOS_TaskVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_TaskVariableType * scheduler_getSchedulerIdleTaskVar(CosmOS_SchedulerVariableType * scheduler)
{
    return (CosmOS_TaskVariableType *)(scheduler->cfg->idleTaskVar);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_getSchedulerCurrentTick(CosmOS_SchedulerVariableType * scheduler)
  *
  * @brief Get scheduler currentTick.
  *
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType scheduler_getSchedulerCurrentTick(CosmOS_SchedulerVariableType * scheduler)
{
    return (scheduler->currentTick);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_getSchedulerPriorTickStep(CosmOS_SchedulerVariableType * scheduler)
  *
  * @brief Get scheduler priorTickStep.
  *
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType scheduler_getSchedulerPriorTickStep(CosmOS_SchedulerVariableType * scheduler)
{
    return (scheduler->priorTickStep);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_getSchedulerScheduleTableIterator(CosmOS_SchedulerVariableType * scheduler)
  *
  * @brief Get scheduler scheduleTableIterator.
  *
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType scheduler_getSchedulerScheduleTableIterator(CosmOS_SchedulerVariableType * scheduler)
{
    return (scheduler->scheduleTableIterator);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_getSchedulerThreadListIterator(CosmOS_SchedulerVariableType * scheduler)
  *
  * @brief Get scheduler threadListIterator.
  *
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType scheduler_getSchedulerThreadListIterator(CosmOS_SchedulerVariableType * scheduler)
{
    return (scheduler->threadListIterator);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_getSchedulerState(CosmOS_SchedulerVariableType * scheduler)
  *
  * @brief Get scheduler schedulerState.
  *
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  *
  * @return CosmOS_SchedulerStateType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType scheduler_getSchedulerState(CosmOS_SchedulerVariableType * scheduler)
{
    return (scheduler->schedulerState);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_getSchedulerNextSyncTick(CosmOS_SchedulerVariableType * scheduler)
  *
  * @brief Get scheduler nextSyncTick.
  *
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType scheduler_getSchedulerNextSyncTick(CosmOS_SchedulerVariableType * scheduler)
{
    return (scheduler->nextSyncTick);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_getSchedulerSyncInitState(CosmOS_SchedulerVariableType * scheduler)
  *
  * @brief Get scheduler syncInitState.
  *
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  *
  * @return CosmOS_BooleanType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BooleanType scheduler_getSchedulerSyncInitState(CosmOS_SchedulerVariableType * scheduler)
{
    return (scheduler->syncInitState);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_getSchedulerRescheduleTriggerState(CosmOS_SchedulerVariableType * scheduler)
  *
  * @brief Get scheduler rescheduleTriggerState.
  *
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  *
  * @return CosmOS_RescheduleTriggerStateType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_RescheduleTriggerStateType scheduler_getSchedulerRescheduleTriggerState(CosmOS_SchedulerVariableType * scheduler)
{
    return (scheduler->rescheduleTriggerState);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_getSchedulerScheduleTableStartTick(CosmOS_SchedulerVariableType * scheduler, BitWidthType scheduleTableIterator)
  *
  * @brief Get scheduler scheduleTable element startTick.
  *
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  * @param[in]  BitWidthType scheduleTableIterator
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType scheduler_getSchedulerScheduleTableStartTick(CosmOS_SchedulerVariableType * scheduler, BitWidthType scheduleTableIterator)
{
    return (scheduler->cfg->scheduleTable[scheduleTableIterator].startTick);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_getSchedulerScheduleTableTaskVar(CosmOS_SchedulerVariableType * scheduler, BitWidthType scheduleTableIterator)
  *
  * @brief Get scheduler scheduleTable element taskVar.
  *
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  * @param[in]  BitWidthType scheduleTableIterator
  *
  * @return CosmOS_TaskVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_TaskVariableType * scheduler_getSchedulerScheduleTableTaskVar(CosmOS_SchedulerVariableType * scheduler, BitWidthType scheduleTableIterator)
{
    return (CosmOS_TaskVariableType *)(scheduler->cfg->scheduleTable[scheduleTableIterator].taskVar);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_getSchedulerThreadListThreadVar(CosmOS_SchedulerVariableType * scheduler, BitWidthType threadListIterator)
  *
  * @brief Get scheduler threadList element threadVar.
  *
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  * @param[in]  BitWidthType threadListIterator
  *
  * @return CosmOS_ThreadVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_ThreadVariableType * scheduler_getSchedulerThreadListThreadVar(CosmOS_SchedulerVariableType * scheduler, BitWidthType threadListIterator)
{
    return (CosmOS_ThreadVariableType *)(scheduler->cfg->threadList[threadListIterator].threadVar);
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Getters_scheduler_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_scheduler_h Setters
  * @ingroup Apis_scheduler_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_setSchedulerCurrentTick(CosmOS_SchedulerVariableType * scheduler, BitWidthType currentTickParam)
  *
  * @brief Set scheduler currentTick.
  *
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  * @param[in]  BitWidthType currentTickParam
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void scheduler_setSchedulerCurrentTick(CosmOS_SchedulerVariableType * scheduler, BitWidthType currentTickParam)
{
    scheduler->currentTick = currentTickParam;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_setSchedulerPriorTickStep(CosmOS_SchedulerVariableType * scheduler, BitWidthType priorTickStepParam)
  *
  * @brief Set scheduler priorTickStep.
  *
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  * @param[in]  BitWidthType priorTickStepParam
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void scheduler_setSchedulerPriorTickStep(CosmOS_SchedulerVariableType * scheduler, BitWidthType priorTickStepParam)
{
    scheduler->priorTickStep = priorTickStepParam;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_setSchedulerScheduleTableIterator(CosmOS_SchedulerVariableType * scheduler, BitWidthType scheduleTableIteratorParam)
  *
  * @brief Set scheduler scheduleTableIterator.
  *
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  * @param[in]  BitWidthType scheduleTableIteratorParam
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void scheduler_setSchedulerScheduleTableIterator(CosmOS_SchedulerVariableType * scheduler, BitWidthType scheduleTableIteratorParam)
{
    scheduler->scheduleTableIterator = scheduleTableIteratorParam;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_setSchedulerThreadListIterator(CosmOS_SchedulerVariableType * scheduler, BitWidthType scheduleTableIteratorParam)
  *
  * @brief Set scheduler threadListIterator.
  *
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  * @param[in]  BitWidthType threadListIteratorParam
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void scheduler_setSchedulerThreadListIterator(CosmOS_SchedulerVariableType * scheduler, BitWidthType threadListIteratorParam)
{
    scheduler->threadListIterator = threadListIteratorParam;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_setSchedulerState(CosmOS_SchedulerVariableType * scheduler, CosmOS_SchedulerStateType schedulerStateParam)
  *
  * @brief Set scheduler schedulerState.
  *
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  * @param[in]  CosmOS_SchedulerStateType schedulerStateParam
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void scheduler_setSchedulerState(CosmOS_SchedulerVariableType * scheduler, CosmOS_SchedulerStateType schedulerStateParam)
{
    scheduler->schedulerState = schedulerStateParam;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_setSchedulerNextSyncTick(CosmOS_SchedulerVariableType * scheduler)
  *
  * @brief Set scheduler nextSyncTick.
  *
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  * @param[in]  BitWidthType paramNextSyncTick
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void scheduler_setSchedulerNextSyncTick(CosmOS_SchedulerVariableType * scheduler, BitWidthType paramNextSyncTick)
{
    scheduler->nextSyncTick = paramNextSyncTick;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_setSchedulerSyncInitState(CosmOS_SchedulerVariableType * scheduler)
  *
  * @brief Set scheduler syncInitState.
  *
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  * @param[in]  CosmOS_BooleanType paramSyncInitState
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void scheduler_setSchedulerSyncInitState(CosmOS_SchedulerVariableType * scheduler, CosmOS_BooleanType paramSyncInitState)
{
    scheduler->syncInitState = paramSyncInitState;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_setSchedulerRescheduleTriggerState(CosmOS_SchedulerVariableType * scheduler)
  *
  * @brief Set scheduler rescheduleTriggerState.
  *
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  * @param[in]  CosmOS_RescheduleTriggerStateType paramRescheduleTriggerState
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void scheduler_setSchedulerRescheduleTriggerState(CosmOS_SchedulerVariableType * scheduler, CosmOS_RescheduleTriggerStateType paramRescheduleTriggerState)
{
    scheduler->rescheduleTriggerState = paramRescheduleTriggerState;
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Setters_scheduler_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_scheduler_h General
  * @ingroup Apis_scheduler_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_scheduler_h
********************************************************************************/
/********************************************************************************
**                        Function Definitions | Stop                          **
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
