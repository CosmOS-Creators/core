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
#include "cosmosTypes.h"
#include "memoryMapping.h"
#include "sysDefs.h"

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
  * @} */
/*  Macros_scheduler_h
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
  * @} */
/*  Variables_scheduler_h
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
  * @} */
/*  Getters_scheduler_h
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
  * @} */
/*  Setters_scheduler_h
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
  * ****************************************************************************/
/**
  * @fn  scheduler_updateAlarms(CosmOS_CoreConfigurationType * core,
  * BitWidthType priorTickStep)
  *
  * @brief Update alarms. This function cannot
  * be called from the unprivileged context directly.
  *
  * @param[in]  core configuration pointer
  * @param[in]  priorTickStep prior tick step of the scheduler
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void
scheduler_updateAlarms(
    CosmOS_CoreConfigurationType * core,
    BitWidthType priorTickStep );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn  scheduler_performanceScheduling(
  * CosmOS_SchedulerConfigurationType * schedulerVar,
  * CosmOS_SchedulableConfigurationType ** schedulableCfg,
  * StackPointerType * stackPointerRetVal,
  * BitWidthType * timerTicks)
  *
  * @brief Performance scheduling function. This function cannot
  * be called from the unprivileged context directly. DEMO
  *
  * @param[in]  scheduler configuration pointerVar
  * @param[in]  schedulableCfg pointer
  * @param[in]  stackPointerRetVal stack pointer of the current schedulable
  * @param[in]  timerTicks timer ticks to set, usually preempt period
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void
scheduler_performanceScheduling(
    CosmOS_SchedulerConfigurationType * schedulerVar,
    CosmOS_SchedulableConfigurationType ** schedulableCfg,
    StackPointerType * stackPointerRetVal,
    BitWidthType * timerTicks );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn  scheduler_classicScheduling(
  * CosmOS_SchedulerConfigurationType * schedulerVar,
  * CosmOS_SchedulableConfigurationType * schedulableCfg,
  * StackPointerType * stackPointerRetVal,
  * BitWidthType * timerTicks,
  * BitWidthType startTick,
  * BitWidthType currentTick)
  *
  * @brief Classic scheduling function. This function cannot
  * be called from the unprivileged context directly. DEMO
  *
  * @param[in]  scheduler configuration pointerVar
  * @param[in]  schedulableCfg pointer
  * @param[in]  stackPointerRetVal stack pointer of the current schedulable
  * @param[in]  timerTicks timer ticks to set, in this case wcet of task
  * @param[in]  startTick startTick of the next task
  * @param[in]  currentTick current tick of the scheduler
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void
scheduler_classicScheduling(
    CosmOS_SchedulerConfigurationType * schedulerVar,
    CosmOS_SchedulableConfigurationType ** schedulableCfg,
    StackPointerType * stackPointerRetVal,
    BitWidthType * timerTicks,
    BitWidthType startTick,
    BitWidthType currentTick );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn scheduler_timerISRCallback(void)
  *
  * @brief System timer callback function. This function cannot
  * be called from the unprivileged context directly. DEMO
  *
  * @param[in]  none
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void
scheduler_timerISRCallback( void );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn scheduler_start(void)
  *
  * @brief Start of scheduler. This function cannot
  * be called from the unprivileged context directly. DEMO
  *
  * @param[in]  none
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void
scheduler_start( void );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn scheduler_scheduleNextInstance(StackPointerType stackPointer)
  *
  * @brief Algorithm for scheduling next schedulable.This function cannot
  * be called from the unprivileged context directly. DEMO
  *
  * @param[in]  stackPointer stack pointer of the current schedulable
  *
  * @return BitWidthType
********************************************************************************/
__OS_FUNC_SECTION StackPointerType
scheduler_scheduleNextInstance( StackPointerType stackPointer );
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_scheduler_h
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
  * ****************************************************************************/
/**
  * @fn scheduler_getSchedulerScheduleTable(
  * CosmOS_SchedulerConfigurationType * scheduler)
  *
  * @brief Get scheduler scheduleTable pointer.
  *
  * @param[in]  scheduler configuration pointer
  *
  * @return CosmOS_ScheduleTableConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_ScheduleTableConfigurationType *
scheduler_getSchedulerScheduleTable(
    CosmOS_SchedulerConfigurationType * scheduler )
{
    return (CosmOS_ScheduleTableConfigurationType *)( scheduler->scheduleTable );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn scheduler_getSchedulerHyperTick(
  * CosmOS_SchedulerConfigurationType * scheduler)
  *
  * @brief Get scheduler hyperTick.
  *
  * @param[in]  scheduler configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
scheduler_getSchedulerHyperTick( CosmOS_SchedulerConfigurationType * scheduler )
{
    return ( scheduler->hyperTick );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn scheduler_getSchedulerPreemptTick(
  * CosmOS_SchedulerConfigurationType * scheduler)
  *
  * @brief Get scheduler preemptTick.
  *
  * @param[in]  scheduler configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
scheduler_getSchedulerPreemptTick(
    CosmOS_SchedulerConfigurationType * scheduler )
{
    return ( scheduler->preemptTick );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn scheduler_getSchedulerScheduleTableElementsNum(
  * CosmOS_SchedulerConfigurationType * scheduler)
  *
  * @brief Get scheduler scheduleTableElementsNum.
  *
  * @param[in]  scheduler configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
scheduler_getSchedulerScheduleTableElementsNum(
    CosmOS_SchedulerConfigurationType * scheduler )
{
    return ( scheduler->scheduleTableElementsNum );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn scheduler_getSchedulerThreadListElementsNum(
  * CosmOS_SchedulerConfigurationType * scheduler)
  *
  * @brief Get scheduler threadListElementsNum.
  *
  * @param[in]  scheduler configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
scheduler_getSchedulerThreadListElementsNum(
    CosmOS_SchedulerConfigurationType * scheduler )
{
    return ( scheduler->threadListElementsNum );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn scheduler_getSchedulerLastToFirstTaskTicks(
  * CosmOS_SchedulerConfigurationType * scheduler)
  *
  * @brief Get scheduler lastToFirstTaskTicks.
  *
  * @param[in]  scheduler configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
scheduler_getSchedulerLastToFirstTaskTicks(
    CosmOS_SchedulerConfigurationType * scheduler )
{
    return ( scheduler->lastToFirstTaskTicks );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn scheduler_getSchedulerSyncTicks(
  * CosmOS_SchedulerConfigurationType * scheduler)
  *
  * @brief Get scheduler syncTicks.
  *
  * @param[in]  scheduler configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
scheduler_getSchedulerSyncTicks( CosmOS_SchedulerConfigurationType * scheduler )
{
    return ( scheduler->syncTicks );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn scheduler_getSchedulerFirstSyncTaskStartTick(
  * CosmOS_SchedulerConfigurationType * scheduler)
  *
  * @brief Get scheduler firstSyncTaskStartTick.
  *
  * @param[in]  scheduler configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
scheduler_getSchedulerFirstSyncTaskStartTick(
    CosmOS_SchedulerConfigurationType * scheduler )
{
    return ( scheduler->firstSyncTaskStartTick );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn scheduler_getSchedulerMaxTimerTick(
  * CosmOS_SchedulerConfigurationType * scheduler)
  *
  * @brief Get scheduler maxTimerTick.
  *
  * @param[in]  scheduler configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
scheduler_getSchedulerMaxTimerTick(
    CosmOS_SchedulerConfigurationType * scheduler )
{
    return ( scheduler->maxTimerTick );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn scheduler_getSchedulerTimerTickCount(
  * CosmOS_SchedulerConfigurationType * scheduler)
  *
  * @brief Get scheduler timerTickCount.
  *
  * @param[in]  scheduler configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
scheduler_getSchedulerTimerTickCount(
    CosmOS_SchedulerConfigurationType * scheduler )
{
    return ( scheduler->timerTickCount );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn scheduler_getSchedulerIdleTask(
  * CosmOS_SchedulerConfigurationType * scheduler)
  *
  * @brief Get scheduler idleTask.
  *
  * @param[in]  scheduler configuration pointer
  *
  * @return CosmOS_TaskConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_TaskConfigurationType *
scheduler_getSchedulerIdleTask( CosmOS_SchedulerConfigurationType * scheduler )
{
    return (CosmOS_TaskConfigurationType *)( scheduler->idleTask );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn scheduler_getAlarmCfgs(CosmOS_SchedulerConfigurationType * scheduler)
  *
  * @brief Get scheduler alarmCfgs.
  *
  * @param[in]  scheduler configuration pointer
  *
  * @return CosmOS_AlarmConfigurationType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_AlarmConfigurationType *
scheduler_getAlarmCfgs( CosmOS_SchedulerConfigurationType * scheduler )
{
    return (CosmOS_AlarmConfigurationType *)( scheduler->alarmCfgs );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn scheduler_getAlarmCfg(CosmOS_SchedulerConfigurationType * scheduler,
  * BitWidthType * barrierId)
  *
  * @brief Get alarmCfg element pointer.
  *
  * @param[in]  scheduler configuration pointer
  * @param[in]  alarmId required alarm id
  *
  * @return CosmOS_AlarmConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_AlarmConfigurationType *
scheduler_getAlarmCfg( CosmOS_SchedulerConfigurationType * scheduler, BitWidthType alarmId )
{
    return (CosmOS_AlarmConfigurationType *)( &( scheduler->alarmCfgs[alarmId] ) );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn scheduler_getSchedulerCurrentTick(
  * CosmOS_SchedulerConfigurationType * scheduler)
  *
  * @brief Get scheduler currentTick.
  *
  * @param[in]  scheduler configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
scheduler_getSchedulerCurrentTick(
    CosmOS_SchedulerConfigurationType * scheduler )
{
    return ( scheduler->var->currentTick );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn scheduler_getSchedulerPriorTickStep(
  * CosmOS_SchedulerConfigurationType * scheduler)
  *
  * @brief Get scheduler priorTickStep.
  *
  * @param[in]  scheduler configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
scheduler_getSchedulerPriorTickStep(
    CosmOS_SchedulerConfigurationType * scheduler )
{
    return ( scheduler->var->priorTickStep );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn scheduler_getSchedulerScheduleTableIterator(
  * CosmOS_SchedulerConfigurationType * scheduler)
  *
  * @brief Get scheduler scheduleTableIterator.
  *
  * @param[in]  scheduler configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
scheduler_getSchedulerScheduleTableIterator(
    CosmOS_SchedulerConfigurationType * scheduler )
{
    return ( scheduler->var->scheduleTableIterator );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn scheduler_getSchedulerThreadListIterator(
  * CosmOS_SchedulerConfigurationType * scheduler)
  *
  * @brief Get scheduler threadListIterator.
  *
  * @param[in]  scheduler configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
scheduler_getSchedulerThreadListIterator(
    CosmOS_SchedulerConfigurationType * scheduler )
{
    return ( scheduler->var->threadListIterator );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn scheduler_getSchedulerState(CosmOS_SchedulerConfigurationType * scheduler)
  *
  * @brief Get scheduler schedulerState.
  *
  * @param[in]  scheduler configuration pointer
  *
  * @return CosmOS_SchedulerStateType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
scheduler_getSchedulerState( CosmOS_SchedulerConfigurationType * scheduler )
{
    return ( scheduler->var->schedulerState );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn scheduler_getSchedulerNextSyncTick(
  * CosmOS_SchedulerConfigurationType * scheduler)
  *
  * @brief Get scheduler nextSyncTick.
  *
  * @param[in]  scheduler configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
scheduler_getSchedulerNextSyncTick(
    CosmOS_SchedulerConfigurationType * scheduler )
{
    return ( scheduler->var->nextSyncTick );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn scheduler_getSchedulerSyncInitState(
  * CosmOS_SchedulerConfigurationType * scheduler)
  *
  * @brief Get scheduler syncInitState.
  *
  * @param[in]  scheduler configuration pointer
  *
  * @return CosmOS_BooleanType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BooleanType
scheduler_getSchedulerSyncInitState(
    CosmOS_SchedulerConfigurationType * scheduler )
{
    return ( scheduler->var->syncInitState );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn scheduler_getSchedulerRescheduleTriggerState(
  * CosmOS_SchedulerConfigurationType * scheduler)
  *
  * @brief Get scheduler rescheduleTriggerState.
  *
  * @param[in]  scheduler configuration pointer
  *
  * @return CosmOS_RescheduleTriggerStateType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_RescheduleTriggerStateType
scheduler_getSchedulerRescheduleTriggerState(
    CosmOS_SchedulerConfigurationType * scheduler )
{
    return ( scheduler->var->rescheduleTriggerState );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn scheduler_getSchedulerScheduleTableStartTick(
  * CosmOS_SchedulerConfigurationType * scheduler,
  * BitWidthType scheduleTableIterator)
  *
  * @brief Get scheduler scheduleTable element startTick.
  *
  * @param[in]  scheduler configuration pointer
  * @param[in]  scheduleTableIterator iterator pointing to specific task variable
  * in the schedule table
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
scheduler_getSchedulerScheduleTableStartTick(
    CosmOS_SchedulerConfigurationType * scheduler,
    BitWidthType scheduleTableIterator )
{
    return ( scheduler->scheduleTable[scheduleTableIterator].startTick );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn scheduler_getSchedulerScheduleTableTaskVar(
  * CosmOS_SchedulerConfigurationType * scheduler,
  * BitWidthType scheduleTableIterator)
  *
  * @brief Get scheduler scheduleTable element taskVar.
  *
  * @param[in]  scheduler configuration pointer
  * @param[in]  scheduleTableIterator iterator pointing to specific task variable
  * in the schedule table
  *
  * @return CosmOS_TaskConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_TaskConfigurationType *
scheduler_getSchedulerScheduleTableTaskVar(
    CosmOS_SchedulerConfigurationType * scheduler,
    BitWidthType scheduleTableIterator )
{
    return (CosmOS_TaskConfigurationType *)( scheduler
                                                 ->scheduleTable
                                                     [scheduleTableIterator]
                                                 .taskCfg );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn scheduler_getSchedulerThreadListThreadVar(
  * CosmOS_SchedulerConfigurationType * scheduler,
  * BitWidthType threadListIterator)
  *
  * @brief Get scheduler threadList element threadVar.
  *
  * @param[in]  scheduler configuration pointer
  * @param[in]  threadListIterator iterator pointing to specific thread
  * configuration in the thread list
  *
  * @return CosmOS_ThreadConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_ThreadConfigurationType *
scheduler_getSchedulerThreadListThreadVar(
    CosmOS_SchedulerConfigurationType * scheduler,
    BitWidthType threadListIterator )
{
    return (
        CosmOS_ThreadConfigurationType *)( scheduler
                                               ->threadList[threadListIterator]
                                               .threadCfg );
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_scheduler_h
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
  * ****************************************************************************/
/**
  * @fn scheduler_setSchedulerCurrentTick(
  * CosmOS_SchedulerConfigurationType * scheduler,
  * BitWidthType currentTickParam)
  *
  * @brief Set scheduler currentTick. This function cannot
  * be called from the unprivileged context directly.
  *
  * @param[out]  scheduler configuration pointer
  * @param[in]  currentTickParam current tick to be set
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
scheduler_setSchedulerCurrentTick(
    CosmOS_SchedulerConfigurationType * scheduler,
    BitWidthType currentTickParam )
{
    scheduler->var->currentTick = currentTickParam;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn scheduler_setSchedulerPriorTickStep(
  * CosmOS_SchedulerConfigurationType * scheduler,
  * BitWidthType priorTickStepParam)
  *
  * @brief Set scheduler priorTickStep. This function cannot
  * be called from the unprivileged context directly.
  *
  * @param[out]  scheduler configuration pointer
  * @param[in]  priorTickStepParam prior tick step to be set
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
scheduler_setSchedulerPriorTickStep(
    CosmOS_SchedulerConfigurationType * scheduler,
    BitWidthType priorTickStepParam )
{
    scheduler->var->priorTickStep = priorTickStepParam;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn scheduler_setSchedulerScheduleTableIterator(
  * CosmOS_SchedulerConfigurationType * scheduler,
  * BitWidthType scheduleTableIteratorParam)
  *
  * @brief Set scheduler scheduleTableIterator. This function cannot
  * be called from the unprivileged context directly.
  *
  * @param[out]  scheduler configuration pointer
  * @param[in]  scheduleTableIteratorParam schedule table iterator to be set
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
scheduler_setSchedulerScheduleTableIterator(
    CosmOS_SchedulerConfigurationType * scheduler,
    BitWidthType scheduleTableIteratorParam )
{
    scheduler->var->scheduleTableIterator = scheduleTableIteratorParam;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn scheduler_setSchedulerThreadListIterator(
  * CosmOS_SchedulerConfigurationType * scheduler,
  * BitWidthType scheduleTableIteratorParam)
  *
  * @brief Set scheduler threadListIterator. This function cannot
  * be called from the unprivileged context directly.
  *
  * @param[out]  scheduler configuration pointer
  * @param[in]  threadListIteratorParam thread list iterator to be set
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
scheduler_setSchedulerThreadListIterator(
    CosmOS_SchedulerConfigurationType * scheduler,
    BitWidthType threadListIteratorParam )
{
    scheduler->var->threadListIterator = threadListIteratorParam;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn scheduler_setSchedulerState(
  * CosmOS_SchedulerConfigurationType * scheduler,
  * CosmOS_SchedulerStateType schedulerStateParam)
  *
  * @brief Set scheduler schedulerState. This function cannot
  * be called from the unprivileged context directly.
  *
  * @param[out]  scheduler configuration pointer
  * @param[in]  schedulerStateParam state of the scheduler to be set
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
scheduler_setSchedulerState(
    CosmOS_SchedulerConfigurationType * scheduler,
    CosmOS_SchedulerStateType schedulerStateParam )
{
    scheduler->var->schedulerState = schedulerStateParam;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn scheduler_setSchedulerNextSyncTick(
  * CosmOS_SchedulerConfigurationType * scheduler)
  *
  * @brief Set scheduler nextSyncTick. This function cannot
  * be called from the unprivileged context directly.
  *
  * @param[out]  scheduler configuration pointer
  * @param[in]  paramNextSyncTick next sync tick to be set
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
scheduler_setSchedulerNextSyncTick(
    CosmOS_SchedulerConfigurationType * scheduler,
    BitWidthType paramNextSyncTick )
{
    scheduler->var->nextSyncTick = paramNextSyncTick;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn scheduler_setSchedulerSyncInitState(
  * CosmOS_SchedulerConfigurationType * scheduler)
  *
  * @brief Set scheduler syncInitState. This function cannot
  * be called from the unprivileged context directly.
  *
  * @param[out]  scheduler configuration pointer
  * @param[in]  paramSyncInitState sync init state to be set
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
scheduler_setSchedulerSyncInitState(
    CosmOS_SchedulerConfigurationType * scheduler,
    CosmOS_BooleanType paramSyncInitState )
{
    scheduler->var->syncInitState = paramSyncInitState;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn scheduler_setSchedulerRescheduleTriggerState(
  * CosmOS_SchedulerConfigurationType * scheduler)
  *
  * @brief Set scheduler rescheduleTriggerState. This function cannot
  * be called from the unprivileged context directly.
  *
  * @param[out]  scheduler configuration pointer
  * @param[in]  paramRescheduleTriggerState reschedule trigger state to be set
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
scheduler_setSchedulerRescheduleTriggerState(
    CosmOS_SchedulerConfigurationType * scheduler,
    CosmOS_RescheduleTriggerStateType paramRescheduleTriggerState )
{
    scheduler->var->rescheduleTriggerState = paramRescheduleTriggerState;
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_scheduler_h
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
  * @} */
/*  General_scheduler_h
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
