/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file scheduler.c
*********************************************************************************
<!--                   scheduler Unit Local Group Definition                  -->
*********************************************************************************
** @defgroup Local_scheduler Local
** @ingroup scheduler_unit
** @brief scheduler locals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "scheduler.h"
#include "alarm.h"
#include "core.h"
#include "coreSync.h"
#include "cosmosAssert.h"
#include "os.h"
#include "program.h"
#include "schedulable.h"
#include "stackInit.h"
#include "switchMemoryProtection.h"
#include "switchScheduler.h"
#include "switchSchedulerSync.h"
#include "task.h"
#include "thread.h"

/* CIL interfaces */
#include "CILcore.h"
#include "CILstack.h"
#include "CILsysTimer.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_scheduler Macros
  * @ingroup Local_scheduler
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_scheduler
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
  * @defgroup Variables_scheduler Variables
  * @ingroup Local_scheduler
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_scheduler
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
  * @defgroup Apis_scheduler_c API's
  * @ingroup Local_scheduler
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_scheduler_c Getters
  * @ingroup Apis_scheduler_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_scheduler_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_scheduler_c Setters
  * @ingroup Apis_scheduler_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_scheduler_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_scheduler_c General
  * @ingroup Apis_scheduler_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn  scheduler_classicSchedulingCore(
  * CosmOS_SchedulerVariableType * schedulerVar,
  * CosmOS_SchedulableVariableType ** schedulableVar,
  * StackPointerType * stackPointerRetVal,
  * BitWidthType * timerTicks,
  * BitWidthType * scheduleTableIterator)
  *
  * @brief Classic scheduling core function. DEMO
  *
  * @param[in]  CosmOS_SchedulerVariableType * schedulerVar
  * @param[in]  CosmOS_SchedulableVariableType * schedulableVar
  * @param[in]  StackPointerType * stackPointerRetVal
  * @param[in]  BitWidthType * timerTicks
  * @param[in]  BitWidthType * scheduleTableIterator
  * @param[in]  BitWidthType scheduleTableElementsNum
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
scheduler_classicSchedulingCore(
    CosmOS_SchedulerVariableType * schedulerVar,
    CosmOS_SchedulableVariableType ** schedulableVar,
    StackPointerType * stackPointerRetVal,
    BitWidthType * timerTicks,
    BitWidthType * scheduleTableIterator,
    BitWidthType scheduleTableElementsNum );
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_scheduler_c
********************************************************************************/
/********************************************************************************
**                         Function Prototypes | Stop                          **
********************************************************************************/
/********************************************************************************
**                        Function Definitions | Start                         **
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn  scheduler_classicSchedulingCore(
  * CosmOS_SchedulerVariableType * schedulerVar,
  * CosmOS_SchedulableVariableType ** schedulableVar,
  * StackPointerType * stackPointerRetVal,
  * BitWidthType * timerTicks,
  * BitWidthType * scheduleTableIterator)
  *
  * @brief Classic scheduling core function. DEMO
  *
  * @param[in]  CosmOS_SchedulerVariableType * schedulerVar
  * @param[in]  CosmOS_SchedulableVariableType * schedulableVar
  * @param[in]  StackPointerType * stackPointerRetVal
  * @param[in]  BitWidthType * timerTicks
  * @param[in]  BitWidthType * scheduleTableIterator
  * @param[in]  BitWidthType scheduleTableElementsNum
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
scheduler_classicSchedulingCore(
    CosmOS_SchedulerVariableType * schedulerVar,
    CosmOS_SchedulableVariableType ** schedulableVar,
    StackPointerType * stackPointerRetVal,
    BitWidthType * timerTicks,
    BitWidthType * scheduleTableIterator,
    BitWidthType scheduleTableElementsNum )
{
    BitWidthType wcet;

    CosmOS_TaskVariableType * taskVar;

    taskVar = scheduler_getSchedulerScheduleTableTaskVar(
        schedulerVar, *scheduleTableIterator );

    *schedulableVar = task_getTaskSchedulable( taskVar );
    *stackPointerRetVal = stackInit_schedulableStackInit( *schedulableVar );

    schedulable_setState( *schedulableVar, SCHEDULABLE_STATE_ENUM__RUNNING );

    *scheduleTableIterator =
        ( ( ( *scheduleTableIterator ) + 1 ) % scheduleTableElementsNum );
    scheduler_setSchedulerScheduleTableIterator(
        schedulerVar, *scheduleTableIterator );

    wcet = task_getTaskWcet( taskVar );
    *timerTicks = wcet;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn  scheduler_updateAlarms(
  * CosmOS_CoreVariableType * coreVar,
  * BitWidthType priorTickStep)
  *
  * @brief Update alarms DEMO.
  *
  * @param[in]  CosmOS_CoreVariableType * coreVar
  * @param[in]  BitWidthType priorTickStep
  *
  * @return none
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
scheduler_updateAlarms(
    CosmOS_CoreVariableType * coreVar,
    BitWidthType priorTickStep )
{
    BitWidthType numberOfAlarms, tickCount;

    CosmOS_AlarmStateType alarmState;

    CosmOS_AlarmVariableType * alarmVar;

    numberOfAlarms = core_getCoreNumberOfAlarms( coreVar );
    for ( BitWidthType iterator = 0; iterator < numberOfAlarms; iterator++ )
    {
        alarmVar = core_getAlarmVar( coreVar, iterator );
        alarmState = alarm_getAlarmState( alarmVar );

        if ( alarmState IS_EQUAL_TO ALARM_STATE_ENUM__ACTIVATED )
        {
            tickCount = alarm_getAlarmTickCount( alarmVar );

            if ( tickCount <= priorTickStep )
            {
                alarm_expire( alarmVar );
            }
            else
            {
                tickCount -= priorTickStep;
                alarm_setAlarmTickCount( alarmVar, tickCount );
            }
        }
    }
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn  scheduler_performanceScheduling(
  * CosmOS_SchedulerVariableType * schedulerVar,
  * CosmOS_SchedulableVariableType ** schedulableVar,
  * StackPointerType * stackPointerRetVal,
  * BitWidthType * timerTicks)
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
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
scheduler_performanceScheduling(
    CosmOS_SchedulerVariableType * schedulerVar,
    CosmOS_SchedulableVariableType ** schedulableVar,
    StackPointerType * stackPointerRetVal,
    BitWidthType * timerTicks )
{
    BitWidthType preemptTick, threadListElementsNum;

    CosmOS_SchedulableStateType schedulableState;

    CosmOS_ThreadVariableType * threadVar;
    CosmOS_SchedulableVariableType * currentSchedulableVar;

    threadListElementsNum =
        scheduler_getSchedulerThreadListElementsNum( schedulerVar );

    for ( BitWidthType iterator = 0; iterator < threadListElementsNum;
          iterator++ )
    {
        threadVar =
            scheduler_getSchedulerThreadListThreadVar( schedulerVar, iterator );
        currentSchedulableVar = thread_getThreadSchedulable( threadVar );
        schedulableState = schedulable_getState( currentSchedulableVar );

        if ( schedulableState IS_EQUAL_TO SCHEDULABLE_STATE_ENUM__READY )
        {
            break;
        }
    }

    *schedulableVar = currentSchedulableVar;
    *stackPointerRetVal = schedulable_getStackPointer( *schedulableVar );

    preemptTick = scheduler_getSchedulerPreemptTick( schedulerVar );
    *timerTicks = preemptTick;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn  scheduler_classicScheduling(
  * CosmOS_SchedulerVariableType * schedulerVar,
  * CosmOS_SchedulableVariableType * schedulableVar,
  * StackPointerType * stackPointerRetVal,
  * BitWidthType * timerTicks,
  * BitWidthType startTick,
  * BitWidthType currentTick)
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
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
scheduler_classicScheduling(
    CosmOS_SchedulerVariableType * schedulerVar,
    CosmOS_SchedulableVariableType ** schedulableVar,
    StackPointerType * stackPointerRetVal,
    BitWidthType * timerTicks,
    BitWidthType startTick,
    BitWidthType currentTick )
{
    CosmOS_TaskVariableType * taskVar;

    taskVar = scheduler_getSchedulerIdleTaskVar( schedulerVar );

    *schedulableVar = task_getTaskSchedulable( taskVar );
    *stackPointerRetVal = stackInit_schedulableStackInit( *schedulableVar );

    if ( startTick < currentTick )
    {
        *timerTicks = scheduler_getSchedulerLastToFirstTaskTicks( schedulerVar );
    }
    else
    {
        *timerTicks = startTick - currentTick;
    }
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn scheduler_scheduleNextInstance(StackPointerType stackPointer)
  *
  * @brief Algorithm for scheduling next schedulable DEMO CODE.
  *
  * @param[in]  StackPointerType stackPointer
  *
  * @return BitWidthType
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION StackPointerType
scheduler_scheduleNextInstance( StackPointerType stackPointer )
{
    BitWidthType currentTick, hyperTick, startTick, timerTicks, maxTimerTick,
        priorTickStep, timerTickCount, scheduleTableIterator,
        scheduleTableElementsNum;

    StackPointerType stackPointerRetVal;

    CosmOS_SchedulerStateType schedulerState;
    CosmOS_RescheduleTriggerStateType rescheduleTriggerState;
    CosmOS_SchedulableInstanceType priorSchedulableInstanceType;

    CosmOS_CoreVariableType * coreVar;
    CosmOS_SchedulerVariableType * schedulerVar;
    CosmOS_SchedulableVariableType * schedulableVar;
    CosmOS_SchedulableVariableType * priorSchedulableVar;

    coreVar = core_getCoreVar();
    schedulerVar = core_getCoreSchedulerVar( coreVar );
    priorSchedulableVar = core_getCoreSchedulableInExecution( coreVar );
    rescheduleTriggerState =
        scheduler_getSchedulerRescheduleTriggerState( schedulerVar );

    switch ( rescheduleTriggerState )
    {
        case RESCHEDULE_TRIGGER_STATE_ENUM__TIMER:
        {
            hyperTick = scheduler_getSchedulerHyperTick( schedulerVar );
            schedulerState = scheduler_getSchedulerState( schedulerVar );
            currentTick = scheduler_getSchedulerCurrentTick( schedulerVar );
            maxTimerTick = scheduler_getSchedulerMaxTimerTick( schedulerVar );
            priorTickStep = scheduler_getSchedulerPriorTickStep( schedulerVar );
            timerTickCount =
                scheduler_getSchedulerTimerTickCount( schedulerVar );
            priorSchedulableInstanceType =
                schedulable_getInstanceType( priorSchedulableVar );
            scheduleTableIterator =
                scheduler_getSchedulerScheduleTableIterator( schedulerVar );
            scheduleTableElementsNum =
                scheduler_getSchedulerScheduleTableElementsNum( schedulerVar );
            startTick = scheduler_getSchedulerScheduleTableStartTick(
                schedulerVar, scheduleTableIterator );

            /*TODO: this should be moved to the sysTick interrupt
            with higher priority to have faster response - without else,
             that should stay here */
            if ( schedulerState IS_EQUAL_TO
                     SCHEDULER_STATE_ENUM__TASK_EXECUTED_IN_WCET_CHECK )
            {
                CosmOS_SchedulableStateType schedulableState;

                schedulableState = schedulable_getState( priorSchedulableVar );

                if ( schedulableState IS_NOT_EQUAL_TO
                         SCHEDULABLE_STATE_ENUM__EXECUTED )
                {
                    /* reaction */
                }
            }

            if ( priorSchedulableInstanceType IS_EQUAL_TO
                     SCHEDULABLE_INSTANCE_ENUM__THREAD )
            {
                /* SCHEDULER_PERFORMANCE_SCHEDULING IS_EQUAL_TO ON */
                switchScheduler_schedulable_setStackPointer(
                    priorSchedulableVar, stackPointer );
            }

            /* SCHEDULER_PERFORMANCE_SCHEDULING IS_EQUAL_TO ON */
            switchScheduler_updateAlarms( coreVar, priorTickStep );

            if ( scheduleTableElementsNum AND startTick IS_EQUAL_TO currentTick )
            {
                scheduler_classicSchedulingCore(
                    schedulerVar,
                    &schedulableVar,
                    &stackPointerRetVal,
                    &timerTicks,
                    &scheduleTableIterator,
                    scheduleTableElementsNum );

                schedulerState =
                    SCHEDULER_STATE_ENUM__TASK_EXECUTED_IN_WCET_CHECK;
            }
            else
            {
                /* SCHEDULER_PERFORMANCE_SCHEDULING IS_EQUAL_TO ON */
                switchScheduler_performanceScheduling(
                    schedulerVar,
                    &schedulableVar,
                    &stackPointerRetVal,
                    &timerTicks );
                /* SCHEDULER_PERFORMANCE_SCHEDULING IS_EQUAL_TO OFF */
                switchScheduler_classicScheduling(
                    schedulerVar,
                    &schedulableVar,
                    &stackPointerRetVal,
                    &timerTicks,
                    startTick,
                    currentTick );

                schedulerState = SCHEDULER_STATE_ENUM__WAITING_FOR_START_TIME;
            }

            schedulable_setStackPointer( schedulableVar, stackPointerRetVal );
            core_setSchedulableIntoCurrentContext( coreVar, schedulableVar );

            scheduler_setSchedulerState( schedulerVar, schedulerState );

            if ( maxTimerTick < timerTicks )
            {
                timerTicks = maxTimerTick;
            }

            currentTick = ( ( currentTick + timerTicks ) % hyperTick );
            scheduler_setSchedulerPriorTickStep( schedulerVar, timerTicks );
            scheduler_setSchedulerCurrentTick( schedulerVar, currentTick );

            switchMemoryProtection_setMemoryProtection(
                coreVar, schedulableVar );

            CILsysTimer_setTicks( timerTicks, timerTickCount );
            break;
        }
        case RESCHEDULE_TRIGGER_STATE_ENUM__SYSTEM:
        {
            /* SCHEDULER_PERFORMANCE_SCHEDULING IS_EQUAL_TO ON */
            switchScheduler_schedulable_setStackPointer(
                priorSchedulableVar, stackPointer );
            /* SCHEDULER_PERFORMANCE_SCHEDULING IS_EQUAL_TO ON */
            switchScheduler_performanceScheduling(
                schedulerVar,
                &schedulableVar,
                &stackPointerRetVal,
                &timerTicks );

            schedulable_setStackPointer( schedulableVar, stackPointerRetVal );
            core_setSchedulableIntoCurrentContext( coreVar, schedulableVar );

            switchMemoryProtection_setMemoryProtection(
                coreVar, schedulableVar );

            break;
        }
    }

    scheduler_setSchedulerRescheduleTriggerState(
        schedulerVar, RESCHEDULE_TRIGGER_STATE_ENUM__SYSTEM );
    return stackPointerRetVal;
};
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn scheduler_start(void)
  *
  * @brief Start of scheduler, pick the starting task and execute it DEMO CODE.
  *
  * @param[in]  none
  *
  * @return none
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
scheduler_start( void )
{
    BitWidthType hyperTick, startTick, timerTicks, currentTick, maxTimerTick,
        timerTickCount, stackPointerRetVal, scheduleTableIterator,
        scheduleTableElementsNum;

    CosmOS_SchedulerStateType schedulerState;

    CosmOS_CoreVariableType * coreVar;
    CosmOS_SchedulerVariableType * schedulerVar;
    CosmOS_SchedulableVariableType * schedulableVar;

    coreVar = core_getCoreVar();
    schedulerVar = core_getCoreSchedulerVar( coreVar );
    hyperTick = scheduler_getSchedulerHyperTick( schedulerVar );
    currentTick = scheduler_getSchedulerCurrentTick( schedulerVar );
    maxTimerTick = scheduler_getSchedulerMaxTimerTick( schedulerVar );
    timerTickCount = scheduler_getSchedulerTimerTickCount( schedulerVar );
    scheduleTableIterator =
        scheduler_getSchedulerScheduleTableIterator( schedulerVar );
    scheduleTableElementsNum =
        scheduler_getSchedulerScheduleTableElementsNum( schedulerVar );

    if ( scheduleTableElementsNum )
    {
        cosmosAssert( scheduleTableIterator < scheduleTableElementsNum );

        startTick = scheduler_getSchedulerScheduleTableStartTick(
            schedulerVar, scheduleTableIterator );
    }

    if ( scheduleTableElementsNum AND( startTick IS_EQUAL_TO currentTick ) )
    {
        scheduler_classicSchedulingCore(
            schedulerVar,
            &schedulableVar,
            &stackPointerRetVal,
            &timerTicks,
            &scheduleTableIterator,
            scheduleTableElementsNum );

        schedulerState = SCHEDULER_STATE_ENUM__TASK_EXECUTED_IN_WCET_CHECK;
    }
    else
    {
        /* SCHEDULER_PERFORMANCE_SCHEDULING IS_EQUAL_TO ON */
        switchScheduler_performanceScheduling(
            schedulerVar, &schedulableVar, &stackPointerRetVal, &timerTicks );
        /* SCHEDULER_PERFORMANCE_SCHEDULING IS_EQUAL_TO OFF */
        switchScheduler_classicScheduling(
            schedulerVar,
            &schedulableVar,
            &stackPointerRetVal,
            &timerTicks,
            startTick,
            currentTick );

        schedulerState = SCHEDULER_STATE_ENUM__WAITING_FOR_START_TIME;
    }

    schedulable_setStackPointer( schedulableVar, stackPointerRetVal );
    core_setSchedulableIntoCurrentContext( coreVar, schedulableVar );

    scheduler_setSchedulerState( schedulerVar, schedulerState );

    if ( maxTimerTick < timerTicks )
    {
        timerTicks = maxTimerTick;
    }

    currentTick = ( currentTick + timerTicks ) % hyperTick;
    scheduler_setSchedulerPriorTickStep( schedulerVar, timerTicks );
    scheduler_setSchedulerCurrentTick( schedulerVar, currentTick );

    switchMemoryProtection_setMemoryProtection( coreVar, schedulableVar );

    core_setCoreOsState( coreVar, OS_STATE_ENUM__STARTED );

    scheduler_setSchedulerRescheduleTriggerState(
        schedulerVar, RESCHEDULE_TRIGGER_STATE_ENUM__SYSTEM );

    CILsysTimer_startTimer( timerTicks, timerTickCount );

    CILstack_setStackPointer( stackPointerRetVal );
};
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/
/********************************************************************************
**                        Function Definitions | Stop                          **
********************************************************************************/
/********************************************************************************
**                           END OF THE SOURCE FILE                            **
********************************************************************************/
