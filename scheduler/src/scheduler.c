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
#include "CILinterrupt.h"
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
  * CosmOS_SchedulerConfigurationType * schedulerCfg,
  * CosmOS_SchedulableConfigurationType ** schedulableCfg,
  * StackPointerType * stackPointerRetVal,
  * BitWidthType * timerTicks,
  * BitWidthType * scheduleTableIterator,
  * BitWidthType scheduleTableElementsNum )
  *
  * @brief Classic scheduling core function. DEMO
  *
  * @param[in]  CosmOS_SchedulerConfigurationType * schedulerCfg
  * @param[in]  CosmOS_SchedulableConfigurationType * schedulableCfg
  * @param[in]  StackPointerType * stackPointerRetVal
  * @param[in]  BitWidthType * timerTicks
  * @param[in]  BitWidthType * scheduleTableIterator
  * @param[in]  BitWidthType scheduleTableElementsNum
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
scheduler_classicSchedulingCore(
    CosmOS_SchedulerConfigurationType * schedulerCfg,
    CosmOS_SchedulableConfigurationType ** schedulableCfg,
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
  * CosmOS_SchedulerConfigurationType * schedulerCfg,
  * CosmOS_SchedulableConfigurationType ** schedulableCfg,
  * StackPointerType * stackPointerRetVal,
  * BitWidthType * timerTicks,
  * BitWidthType * scheduleTableIterator,
  * BitWidthType scheduleTableElementsNum )
  *
  * @details The implementation contains obtaining task variable from the
  * schedule table based on the schedule table iterator argument. The task
  * variable is then used in function task_getTaskSchedulable to get the
  * schedulable variable. Then the stack is initialized for the schedulable
  * variable by calling stackInit_schedulableStackInit. The schedule table
  * iterator is then incremented by one and modulo operation is done by schedule
  * table elements number to keep the iterator in the range of schedule table
  * array. The schedule table iterator is then stored back to the scheduler
  * variable by calling function scheduler_setSchedulerScheduleTableIterator.
  * In the end the timer ticks are set to the task wcet that is obtained by
  * calling task_getTaskWcet function.
********************************************************************************/
__STATIC_FORCEINLINE void
scheduler_classicSchedulingCore(
    CosmOS_SchedulerConfigurationType * schedulerCfg,
    CosmOS_SchedulableConfigurationType ** schedulableCfg,
    StackPointerType * stackPointerRetVal,
    BitWidthType * timerTicks,
    BitWidthType * scheduleTableIterator,
    BitWidthType scheduleTableElementsNum )
{
    BitWidthType wcet;

    CosmOS_TaskConfigurationType * taskCfg;

    taskCfg = scheduler_getSchedulerScheduleTableTaskVar(
        schedulerCfg, *scheduleTableIterator );

    *schedulableCfg = task_getTaskSchedulable( taskCfg );
    *stackPointerRetVal = stackInit_schedulableStackInit( *schedulableCfg );

    *scheduleTableIterator =
        ( ( ( *scheduleTableIterator ) + 1 ) % scheduleTableElementsNum );
    scheduler_setSchedulerScheduleTableIterator(
        schedulerCfg, *scheduleTableIterator );

    wcet = task_getTaskWcet( taskCfg );
    *timerTicks = wcet;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn  scheduler_updateAlarms(
  * CosmOS_CoreConfigurationType * core,
  * BitWidthType priorTickStep)
  *
  * @details The implementation contains obtaining of the alarms number used
  * inside the for loop that iterates over all alarm possible identifiers and
  * get based on them alarm variable by calling scheduler_getAlarmCfg function.
  * Then the alarm variable is used in the alarm_getAlarmState function to get
  * alarm state.
  * The alarm state is used in the if condition that checks if the alarm
  * state is ALARM_STATE_ENUM__ACTIVATED which means the alarm internal timer
  * needs to be updated, otherwise the alarm is ignored. The alarm is updated in
  * the sequence where its tick count is obtained by function
  * alarm_getAlarmTickCount and compared in the if condition to the prior tick
  * step. If the prior tick step is bigger or equal to the tick count it means
  * that alarm expires as the decrementing prior tick step would lead to zero or
  * negative alarms timer value, therefore the alarm_expire function is called.
  * Otherwise the tick count is decremented by the prior tick step and stored
  * back to the alarm variable by calling alarm_setAlarmTickCount function.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
scheduler_updateAlarms(
    CosmOS_CoreConfigurationType * core,
    BitWidthType priorTickStep )
{
    BitWidthType numberOfAlarms, tickCount;

    CosmOS_AlarmStateType alarmState;

    CosmOS_AlarmConfigurationType * alarmCfg;

    numberOfAlarms = core_getCoreNumberOfAlarms( core );
    for ( BitWidthType iterator = 0; iterator < numberOfAlarms; iterator++ )
    {
        alarmCfg = scheduler_getAlarmCfg(
            (CosmOS_SchedulerConfigurationType *)core->scheduler, iterator );
        alarmState = alarm_getAlarmState( alarmCfg );

        if ( alarmState IS_EQUAL_TO ALARM_STATE_ENUM__ACTIVATED )
        {
            tickCount = alarm_getAlarmTickCount( alarmCfg );

            if ( tickCount <= priorTickStep )
            {
                alarm_expire( alarmCfg );
            }
            else
            {
                tickCount -= priorTickStep;
                alarm_setAlarmTickCount( alarmCfg, tickCount );
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
  * CosmOS_SchedulerConfigurationType * schedulerCfg,
  * CosmOS_SchedulableConfigurationType ** schedulableCfg,
  * StackPointerType * stackPointerRetVal,
  * BitWidthType * timerTicks)
  *
  * @details The implementation contains obtaining of the thread list elements
  * number by calling scheduler_getSchedulerThreadListElementsNum function. Then
  * the for loop is implemented that iterates over all possible thread
  * identifiers and uses them for obtaining thread variable by calling function
  * scheduler_getSchedulerThreadListThreadVar. From the thread variable is the
  * schedulable variable extracted by calling thread_getThreadSchedulable
  * function and the schedulable state is obtained by calling function
  * schedulable_getState. Then the if condition is implemented that checks if
  * the schedulable state is equal to the SCHEDULABLE_STATE_ENUM__READY and if
  * yes the for loop breaks, otherwise continues till it finds thread in ready
  * state for execution. The thread list is priority sorted and has to contain
  * as the lowest priority thread the idle thread. The found schedulable
  * variable from the for loop is then used in the function
  * schedulable_getStackPointer to get its stack pointer and the preempt tick is
  * obtained by calling function scheduler_getSchedulerPreemptTick and passed
  * to the timer ticks.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
scheduler_performanceScheduling(
    CosmOS_SchedulerConfigurationType * schedulerCfg,
    CosmOS_SchedulableConfigurationType ** schedulableCfg,
    StackPointerType * stackPointerRetVal,
    BitWidthType * timerTicks )
{
    BitWidthType preemptTick, threadListElementsNum;

    CosmOS_SchedulableStateType schedulableState;

    CosmOS_ThreadConfigurationType * threadCfg;
    CosmOS_SchedulableConfigurationType * currentSchedulableCfg = NULL;

    threadListElementsNum =
        scheduler_getSchedulerThreadListElementsNum( schedulerCfg );

    for ( BitWidthType iterator = 0; iterator < threadListElementsNum;
          iterator++ )
    {
        threadCfg =
            scheduler_getSchedulerThreadListThreadVar( schedulerCfg, iterator );
        currentSchedulableCfg = thread_getThreadSchedulable( threadCfg );
        schedulableState = schedulable_getState( currentSchedulableCfg );

        if ( schedulableState IS_EQUAL_TO SCHEDULABLE_STATE_ENUM__READY )
        {
            break;
        }
    }

    *schedulableCfg = currentSchedulableCfg;
    *stackPointerRetVal = schedulable_getStackPointer( *schedulableCfg );

    preemptTick = scheduler_getSchedulerPreemptTick( schedulerCfg );
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
  * CosmOS_SchedulerConfigurationType * schedulerCfg,
  * CosmOS_SchedulableConfigurationType * schedulableCfg,
  * StackPointerType * stackPointerRetVal,
  * BitWidthType * timerTicks,
  * BitWidthType startTick,
  * BitWidthType currentTick)
  *
  * @details The implementation contains obtaining of the idle task variable by
  * calling scheduler_getSchedulerIdleTask function and schedulable is
  * extracted out of the idle task variable by calling task_getTaskSchedulable
  * function. Then the stack is initialized for the schedulable variable by
  * calling stackInit_schedulableStackInit. Next the if condition is implemented
  * to check if the current tick is bigger than next start tick in the schedule
  * table, if yes then it means that the ticks from the last to first task in
  * schedule table have to be obtained by calling function
  * scheduler_getSchedulerLastToFirstTaskTicks, otherwise we can subtract
  * current tick from the start tick variable and get the timer ticks.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
scheduler_classicScheduling(
    CosmOS_SchedulerConfigurationType * schedulerCfg,
    CosmOS_SchedulableConfigurationType ** schedulableCfg,
    StackPointerType * stackPointerRetVal,
    BitWidthType * timerTicks,
    BitWidthType startTick,
    BitWidthType currentTick )
{
    CosmOS_TaskConfigurationType * taskCfg;

    taskCfg = scheduler_getSchedulerIdleTask( schedulerCfg );

    *schedulableCfg = task_getTaskSchedulable( taskCfg );
    *stackPointerRetVal = stackInit_schedulableStackInit( *schedulableCfg );

    if ( startTick < currentTick )
    {
        *timerTicks = scheduler_getSchedulerLastToFirstTaskTicks( schedulerCfg );
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
  * @fn  scheduler_timerISRCallback( void )
  *
  * @details The implementation contains obtaining of the core configuration by
  * calling function core_getCoreCfg. The core configuration is then used to get
  * the scheduler variable for the current core. After this point the reschedule
  * state of the scheduler is checked in the if condition. If the reschedule
  * trigger is equal to the RESCHEDULE_TRIGGER_STATE_ENUM__TIMER the scheduling
  * algorithm was not finished in the required time (preempt tick) and an error
  * reaction is triggered. Otherwise the scheduler state is checked in the
  * if condition. If the scheduler state is equal to the
  * SCHEDULER_STATE_ENUM__TASK_EXECUTED_IN_WCET_CHECK, the schedulableState is
  * obtained from the schedulable in execution for the current core
  * configuration and check if it is equal to SCHEDULABLE_STATE_ENUM__EXECUTED.
  * If not an error reaction is triggered. Otherwise the reschedule trigger
  * state is set to RESCHEDULE_TRIGGER_STATE_ENUM__TIMER, timer is set to the
  * preempt period and timer offset is saved to by calling function
  * CILsysTimer_setTicksSaveOffset and scheduler state is set to the
  * SCHEDULER_STATE_ENUM__WAITING_FOR_START_TIME. After this point the scheduling
  * algorithm is triggered by calling CILinterrupt_contextSwitchRoutineTrigger
  * function.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
scheduler_timerISRCallback( void )
{
    CosmOS_CoreConfigurationType * coreCfg;
    CosmOS_SchedulerConfigurationType * schedulerCfg;

    coreCfg = core_getCoreCfg();
    schedulerCfg = core_getCoreScheduler( coreCfg );

    if ( schedulerCfg->var->rescheduleTriggerState IS_NOT_EQUAL_TO
             RESCHEDULE_TRIGGER_STATE_ENUM__TIMER )
    {
        if ( schedulerCfg->var->schedulerState IS_EQUAL_TO
                 SCHEDULER_STATE_ENUM__TASK_EXECUTED_IN_WCET_CHECK )
        {
            CosmOS_SchedulableStateType schedulableState;

            schedulableState =
                schedulable_getState( (CosmOS_SchedulableConfigurationType *)
                                          coreCfg->var->schedulableInExecution );

            if ( schedulableState IS_NOT_EQUAL_TO
                     SCHEDULABLE_STATE_ENUM__EXECUTED )
            {
                /* TODO: ERROR REACTION EXCEEDING WCET */
            }
        }

        schedulerCfg->var->rescheduleTriggerState =
            RESCHEDULE_TRIGGER_STATE_ENUM__TIMER;

        /* Set to unblock reschedule */
        schedulerCfg->var->schedulerState =
            SCHEDULER_STATE_ENUM__WAITING_FOR_START_TIME;

        /* Give scheduling algorithm preempt tick to finish the reschedule */
        CILsysTimer_setTicksSaveOffset(
            schedulerCfg->preemptTick,
            schedulerCfg->timerTickCount,
            &schedulerCfg->var->timerOffset );

        CILinterrupt_contextSwitchRoutineTrigger();
    }
    else
    {
        coreCfg->var->osState = coreCfg->var->osState; /* TODO: BREAKPOINT */
        /* TODO: ERROR REACTION RESCHEDULE WAS NOT FINISHED IN PREEMPT TICK */
    }
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn scheduler_start(void)
  *
  * @details The implementation contains obtaining of the core configuration by
  * calling the core_getCoreCfg function. Then the scheduler variable in
  * is obtained by the core_getCoreScheduler and the hyper tick, current tick
  * maximum timer tick, timer tick count, schedule table iterator and schedule
  * table elements number are obtained by calling functions
  * scheduler_getSchedulerHyperTick, scheduler_getSchedulerCurrentTick,
  * scheduler_getSchedulerMaxTimerTick, scheduler_getSchedulerTimerTickCount,
  * scheduler_getSchedulerScheduleTableIterator and
  * scheduler_getSchedulerScheduleTableElementsNum. If the schedule table
  * elements number is non-zero value the startick is obtained by calling
  * function scheduler_getSchedulerScheduleTableStartTick. Subsequent if
  * condition checks if the schedule table elements number is non-zero value and
  * if the starttick is equal to the current tick, in this case zero. If
  * condition is true the scheduler_classicSchedulingCore function is called and
  * scheduler state is set to the
  * SCHEDULER_STATE_ENUM__TASK_EXECUTED_IN_WCET_CHECK.
  * If no the functions as macros switchScheduler_performanceScheduling and
  * switchScheduler_classicScheduling are called depends on the
  * SCHEDULER_PERFORMANCE_SCHEDULING macro state (configured via switches).
  * and scheduler state is set to SCHEDULER_STATE_ENUM__WAITING_FOR_START_TIME.
  * The schedulable stack pointer is then set by calling function
  * schedulable_setStackPointer and also schedulable variable is set to the
  * current context by calling function core_setSchedulableIntoCurrentContext
  * and also scheduler state is set by calling scheduler_setSchedulerState
  * function. If condition is implemented to check if the timer ticks that need
  * to be set are more than maximum timer ticks, and if yes than the timer ticks
  * are reduced to the maximum timer ticks. Current tick is then incremented by
  * the timer ticks value modulo hyper tick to not exceed the hyper tick. THe
  * prior tick step is then set by calling scheduler_setSchedulerPriorTickStep
  * function and the current tick by calling scheduler_setSchedulerCurrentTick.
  * The function as macro switchMemoryProtection_setMemoryProtection is called
  * based on the MEMORY_PROTECTION macro state. The operating system state for
  * the current core configuration is set to
  * RESCHEDULE_TRIGGER_STATE_ENUM__SYSTEM
  * by calling core_setCoreOsState function. The scheduler reschedule state is
  * set to RESCHEDULE_TRIGGER_STATE_ENUM__SYSTEM by calling function
  * scheduler_setSchedulerRescheduleTriggerState - this is done only in this
  * place to force system timer overwrite this state when occurs. Then the
  * synchronization barrier function coreSync_getBarrier is called to get in sync
  * with all cores.
  * In the end the system timer is started CILsysTimer_startTimer and the
  * CILstack_setStackPointer called to switch to the schedulable stack.
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

    CosmOS_CoreConfigurationType * coreCfg;
    CosmOS_SchedulerConfigurationType * schedulerCfg;
    CosmOS_SchedulableConfigurationType * schedulableCfg;

    coreCfg = core_getCoreCfg();
    schedulerCfg = core_getCoreScheduler( coreCfg );
    hyperTick = scheduler_getSchedulerHyperTick( schedulerCfg );
    currentTick = scheduler_getSchedulerCurrentTick( schedulerCfg );
    maxTimerTick = scheduler_getSchedulerMaxTimerTick( schedulerCfg );
    timerTickCount = scheduler_getSchedulerTimerTickCount( schedulerCfg );
    scheduleTableIterator =
        scheduler_getSchedulerScheduleTableIterator( schedulerCfg );
    scheduleTableElementsNum =
        scheduler_getSchedulerScheduleTableElementsNum( schedulerCfg );

    startTick = 0;
    if ( scheduleTableElementsNum )
    {
        cosmosAssert( scheduleTableIterator < scheduleTableElementsNum );

        startTick = scheduler_getSchedulerScheduleTableStartTick(
            schedulerCfg, scheduleTableIterator );
    }

    if ( scheduleTableElementsNum AND( startTick IS_EQUAL_TO currentTick ) )
    {
        scheduler_classicSchedulingCore(
            schedulerCfg,
            &schedulableCfg,
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
            schedulerCfg, &schedulableCfg, &stackPointerRetVal, &timerTicks );
        /* SCHEDULER_PERFORMANCE_SCHEDULING IS_EQUAL_TO OFF */
        switchScheduler_classicScheduling(
            schedulerCfg,
            &schedulableCfg,
            &stackPointerRetVal,
            &timerTicks,
            startTick,
            currentTick );

        schedulerState = SCHEDULER_STATE_ENUM__WAITING_FOR_START_TIME;
    }

    schedulable_setStackPointer( schedulableCfg, stackPointerRetVal );
    core_setSchedulableIntoCurrentContext( coreCfg, schedulableCfg );

    scheduler_setSchedulerState( schedulerCfg, schedulerState );

    if ( maxTimerTick < timerTicks )
    {
        timerTicks = maxTimerTick;
    }

    currentTick = ( currentTick + timerTicks ) % hyperTick;
    scheduler_setSchedulerPriorTickStep( schedulerCfg, timerTicks );
    scheduler_setSchedulerCurrentTick( schedulerCfg, currentTick );

    switchMemoryProtection_setMemoryProtection( coreCfg, schedulableCfg );

    core_setCoreOsState( coreCfg, OS_STATE_ENUM__STARTED );

    scheduler_setSchedulerRescheduleTriggerState(
        schedulerCfg, RESCHEDULE_TRIGGER_STATE_ENUM__SYSTEM );

    coreSync_getBarrier( coreCfg, OS_START_ID );

    CILsysTimer_startTimer( timerTicks, timerTickCount );

    CILstack_setStackPointer( stackPointerRetVal );
};
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn scheduler_scheduleNextInstance(StackPointerType stackPointer)
  *
  * @details The implementation contains obtaining of the core configuration by
  * calling the core_getCoreCfg function. Then the scheduler variable in
  * is obtained by the core_getCoreScheduler and the prior schedulable and
  * reschedule trigger state are obtained by calling functions
  * core_getCoreSchedulableInExecution and
  * scheduler_getSchedulerRescheduleTriggerState. Then the switch statement
  * is implemented and contains two states RESCHEDULE_TRIGGER_STATE_ENUM__TIMER
  * and RESCHEDULE_TRIGGER_STATE_ENUM__SYSTEM. The timer reschedule state means
  * that the trigger for the scheduler algorithm execution was timer interrupt.
  * In this case the hyper tick, scheduler state, current tick
  * maximum timer tick, prior tick step, timer tick count, prior schedulable
  * instance type, schedule table iterator, schedule
  * table elements number and start tick are obtained by calling functions
  * scheduler_getSchedulerHyperTick, scheduler_getSchedulerCurrentTick,
  * scheduler_getSchedulerMaxTimerTick, scheduler_getSchedulerTimerTickCount,
  * scheduler_getSchedulerScheduleTableIterator,
  * scheduler_getSchedulerScheduleTableElementsNum and
  * scheduler_getSchedulerScheduleTableStartTick. Then the if condition is
  * implemented to check if the prior schedulable instance type is
  * SCHEDULABLE_INSTANCE_ENUM__THREAD and if yes the stack pointer is stored
  * by calling switchScheduler_schedulable_setStackPointer function based on
  * the SCHEDULER_PERFORMANCE_SCHEDULING macro state. This is needed just for
  * the threads, because the tasks stack is always reused. Next the function as
  * macro switchScheduler_updateAlarms is called based also on the
  * SCHEDULER_PERFORMANCE_SCHEDULING macro state to update all alarms - only
  * if there is performance scheduling active otherwise there are no alarms.
  * Subsequent if condition checks if the schedule table elements number is
  * non-zero value and if the starttick is equal to the current tick, in this
  * case zero. If condition is true the scheduler_classicSchedulingCore function
  * is called and scheduler state is set to the
  * SCHEDULER_STATE_ENUM__TASK_EXECUTED_IN_WCET_CHECK.
  * If no the functions as macros switchScheduler_performanceScheduling and
  * switchScheduler_classicScheduling are called depends on the
  * SCHEDULER_PERFORMANCE_SCHEDULING macro state (configured via switches).
  * and scheduler state is set to SCHEDULER_STATE_ENUM__WAITING_FOR_START_TIME.
  * The schedulable stack pointer is then set by calling function
  * schedulable_setStackPointer and also schedulable variable is set to the
  * current context by calling function core_setSchedulableIntoCurrentContext
  * and also scheduler state is set by calling scheduler_setSchedulerState
  * function. If condition is implemented to check if the timer ticks that need
  * to be set are more than maximum timer ticks, and if yes than the timer ticks
  * are reduced to the maximum timer ticks. Current tick is then incremented by
  * the timer ticks value modulo hyper tick to not exceed the hyper tick. THe
  * prior tick step is then set by calling scheduler_setSchedulerPriorTickStep
  * function and the current tick by calling scheduler_setSchedulerCurrentTick.
  * The function as macro switchMemoryProtection_setMemoryProtection is called
  * based on the MEMORY_PROTECTION macro state. The operating system state for
  * the current core configuration is set to RESCHEDULE_TRIGGER_STATE_ENUM__SYSTEM
  * by calling core_setCoreOsState function. The scheduler  reschedule state is
  * set to RESCHEDULE_TRIGGER_STATE_ENUM__SYSTEM by calling function
  * scheduler_setSchedulerRescheduleTriggerState. Then the system timer is set
  * by calling CILsysTimer_setTicks.
  * The system reschedule state means that the trigger for the scheduler
  * algorithm execution was system even such as mutex or putting thread to the
  * sleep state. In this case there is no need to check the start time for
  * another critical task as the system timer has not yet occurred and therefore
  * the prior schedulable instance type has to be in this case
  * SCHEDULABLE_INSTANCE_ENUM__THREAD. Then the stack pointer must be stored by
  * calling schedulable_setStackPointer function. After this point the function
  * scheduler_performanceScheduling is called to schedule next thread for the
  * execution that is then set as schedulable in current context by calling
  * core_setSchedulableIntoCurrentContext function. The function as macro
  * switchMemoryProtection_setMemoryProtection is called based on the
  * MEMORY_PROTECTION macro state.
  * Finally the stackPointerRetVal is returned from the function, that contains
  * the next schedulable stack pointer.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION StackPointerType
scheduler_scheduleNextInstance( StackPointerType stackPointer )
{
    BitWidthType currentTick, hyperTick, startTick, timerTicks, maxTimerTick,
        priorTickStep, timerTickCount, scheduleTableIterator,
        scheduleTableElementsNum, timerOffset;

    StackPointerType stackPointerRetVal;

    CosmOS_SchedulerStateType schedulerState;
    CosmOS_RescheduleTriggerStateType rescheduleTriggerState;
    CosmOS_SchedulableInstanceType priorSchedulableInstanceType;

    CosmOS_CoreConfigurationType * coreCfg;
    CosmOS_SchedulerConfigurationType * schedulerCfg;
    CosmOS_SchedulableConfigurationType * schedulableCfg;
    CosmOS_SchedulableConfigurationType * priorSchedulableCfg;

    coreCfg = core_getCoreCfg();
    schedulerCfg = core_getCoreScheduler( coreCfg );
    priorSchedulableCfg = core_getCoreSchedulableInExecution( coreCfg );
    rescheduleTriggerState =
        scheduler_getSchedulerRescheduleTriggerState( schedulerCfg );

    switch ( rescheduleTriggerState )
    {
        case RESCHEDULE_TRIGGER_STATE_ENUM__TIMER:
        {
            hyperTick = scheduler_getSchedulerHyperTick( schedulerCfg );
            schedulerState = scheduler_getSchedulerState( schedulerCfg );
            currentTick = scheduler_getSchedulerCurrentTick( schedulerCfg );
            maxTimerTick = scheduler_getSchedulerMaxTimerTick( schedulerCfg );
            priorTickStep = scheduler_getSchedulerPriorTickStep( schedulerCfg );
            timerTickCount =
                scheduler_getSchedulerTimerTickCount( schedulerCfg );
            priorSchedulableInstanceType =
                schedulable_getInstanceType( priorSchedulableCfg );
            scheduleTableIterator =
                scheduler_getSchedulerScheduleTableIterator( schedulerCfg );
            scheduleTableElementsNum =
                scheduler_getSchedulerScheduleTableElementsNum( schedulerCfg );
            startTick = scheduler_getSchedulerScheduleTableStartTick(
                schedulerCfg, scheduleTableIterator );
            timerOffset = scheduler_getSchedulerTimerOffset( schedulerCfg );

            if ( priorSchedulableInstanceType IS_EQUAL_TO
                     SCHEDULABLE_INSTANCE_ENUM__THREAD )
            {
                /* SCHEDULER_PERFORMANCE_SCHEDULING IS_EQUAL_TO ON */
                switchScheduler_schedulable_setStackPointer(
                    priorSchedulableCfg, stackPointer );
            }

            /* SCHEDULER_PERFORMANCE_SCHEDULING IS_EQUAL_TO ON */
            switchScheduler_updateAlarms( coreCfg, priorTickStep );

            if ( scheduleTableElementsNum AND startTick IS_EQUAL_TO currentTick )
            {
                scheduler_classicSchedulingCore(
                    schedulerCfg,
                    &schedulableCfg,
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
                    schedulerCfg,
                    &schedulableCfg,
                    &stackPointerRetVal,
                    &timerTicks );
                /* SCHEDULER_PERFORMANCE_SCHEDULING IS_EQUAL_TO OFF */
                switchScheduler_classicScheduling(
                    schedulerCfg,
                    &schedulableCfg,
                    &stackPointerRetVal,
                    &timerTicks,
                    startTick,
                    currentTick );

                schedulerState = SCHEDULER_STATE_ENUM__WAITING_FOR_START_TIME;
            }

            schedulable_setStackPointer( schedulableCfg, stackPointerRetVal );
            core_setSchedulableIntoCurrentContext( coreCfg, schedulableCfg );

            scheduler_setSchedulerState( schedulerCfg, schedulerState );

            if ( maxTimerTick < timerTicks )
            {
                timerTicks = maxTimerTick;
            }

            currentTick = ( ( currentTick + timerTicks ) % hyperTick );
            scheduler_setSchedulerPriorTickStep( schedulerCfg, timerTicks );
            scheduler_setSchedulerCurrentTick( schedulerCfg, currentTick );

            switchMemoryProtection_setMemoryProtection(
                coreCfg, schedulableCfg );

            CILsysTimer_setTicks( timerTicks, timerTickCount, timerOffset );
            break;
        }
        case RESCHEDULE_TRIGGER_STATE_ENUM__SYSTEM:
        {
            schedulable_setStackPointer( priorSchedulableCfg, stackPointer );

            scheduler_performanceScheduling(
                schedulerCfg,
                &schedulableCfg,
                &stackPointerRetVal,
                &timerTicks );

            schedulable_setStackPointer( schedulableCfg, stackPointerRetVal );
            core_setSchedulableIntoCurrentContext( coreCfg, schedulableCfg );

            switchMemoryProtection_setMemoryProtection(
                coreCfg, schedulableCfg );

            break;
        }
    }

    return stackPointerRetVal;
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
