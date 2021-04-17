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
#include "core.h"
#include "coreSync.h"
#include "os.h"
#include "task.h"
#include "thread.h"
#include "program.h"
#include "schedulable.h"
#include "stackInit.h"
#include "cosmosAssert.h"
#include "switchScheduler.h"
#include "switchSchedulerSync.h"
#include "switchMemoryProtection.h"

/* CIL interfaces */
#include "CIL_core.h"
#include "CIL_stack.h"
#include "CIL_sysTimer.h"
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
  * @}  
  * Macros_scheduler  
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
  * @}  
  * Variables_scheduler  
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
  * @}       
  * Getters_scheduler_c
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
  * @}    
  * Setters_scheduler_c   
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_scheduler_c General  
  * @ingroup Apis_scheduler_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_scheduler_c  
********************************************************************************/
/********************************************************************************
**                         Function Prototypes | Stop                          **
********************************************************************************/
/********************************************************************************
**                        Function Definitions | Start                         **
********************************************************************************/
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
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION void scheduler_performanceScheduling(CosmOS_SchedulerVariableType * schedulerVar, CosmOS_SchedulableVariableType ** schedulableVar,\
StackPointerType * stackPointerRetVal,BitWidthType * timerTicks)
{
        BitWidthType preemptTick,
                     threadListIterator,
                     threadListElementsNum;

        CosmOS_ThreadVariableType * threadVar;

        threadListIterator = scheduler_getSchedulerThreadListIterator( schedulerVar );
        threadListElementsNum = scheduler_getSchedulerThreadListElementsNum( schedulerVar );

        cosmosAssert( threadListIterator < threadListElementsNum );

        threadVar = scheduler_getSchedulerThreadListThreadVar( schedulerVar, threadListIterator );

        *schedulableVar = thread_getThreadSchedulable( threadVar );
        *stackPointerRetVal = schedulable_getStackPointer( *schedulableVar );

        threadListIterator = ( ( threadListIterator + 1 ) % threadListElementsNum );
        scheduler_setSchedulerThreadListIterator( schedulerVar, threadListIterator );

        preemptTick = scheduler_getSchedulerPreemptTick( schedulerVar );
        *timerTicks = preemptTick;
}
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/

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
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION void scheduler_classicScheduling(CosmOS_SchedulerVariableType * schedulerVar, CosmOS_SchedulableVariableType ** schedulableVar,\
StackPointerType * stackPointerRetVal,BitWidthType * timerTicks, BitWidthType startTick, BitWidthType currentTick)
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
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/

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
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION StackPointerType scheduler_scheduleNextInstance(StackPointerType stackPointer)
{
    BitWidthType  currentTick,
                  hyperTick,
                  startTick,
                  timerTicks,
                  scheduleTableIterator,
                  scheduleTableElementsNum;

    StackPointerType stackPointerRetVal;

    CosmOS_SchedulerSyncStateType schedulersSyncState;
    CosmOS_SchedulerStateType schedulerState;

    CosmOS_CoreVariableType * coreVar;
    CosmOS_SchedulerVariableType * schedulerVar;
    CosmOS_SchedulableVariableType * schedulableVar;
    CosmOS_SchedulableVariableType * priorSchedulableVar;


    coreVar = core_getCoreVar();

    schedulerVar = core_getCoreSchedulerVar( coreVar );
    schedulerState = scheduler_getSchedulerState( schedulerVar );
    priorSchedulableVar = core_getCoreSchedulableInCurrentContext( coreVar );

    scheduleTableIterator = scheduler_getSchedulerScheduleTableIterator( schedulerVar );
    scheduleTableElementsNum = scheduler_getSchedulerScheduleTableElementsNum( schedulerVar );

    cosmosAssert( scheduleTableIterator < scheduleTableElementsNum );

    startTick = scheduler_getSchedulerScheduleTableStartTick( schedulerVar, scheduleTableIterator );
    hyperTick = scheduler_getSchedulerHyperTick( schedulerVar );
    currentTick = scheduler_getSchedulerCurrentTick( schedulerVar );

    //this should be moved to the sysTick interrupt with higher priority to have faster response
    if ( schedulerState IS_EQUAL_TO SCHEDULER_STATE_ENUM__TASK_EXECUTED_IN_WCET_CHECK )
    {
        CosmOS_SchedulableStateType schedulableState;

        schedulableState = schedulable_getState( priorSchedulableVar );

        if ( schedulableState IS_NOT_EQUAL_TO SCHEDULABLE_INSTANCE_ENUM__EXECUTED )
        {
            /* reaction */
        }
    }
    else
    {
        /* SCHEDULER_PERFORMANCE_SCHEDULING IS_EQUAL_TO ON */
        switchScheduler_setStackPointer( priorSchedulableVar, stackPointer );
    }

    if ( startTick IS_EQUAL_TO currentTick )
    {   
        BitWidthType wcet;

        CosmOS_TaskVariableType * taskVar;

        taskVar = scheduler_getSchedulerScheduleTableTaskVar( schedulerVar, scheduleTableIterator );

        schedulableVar = task_getTaskSchedulable( taskVar );
        stackPointerRetVal = stackInit_schedulableStackInit( schedulableVar );

        schedulable_setState( schedulableVar, SCHEDULABLE_INSTANCE_ENUM__RUNNING );

        scheduleTableIterator = ( ( scheduleTableIterator + 1 ) % scheduleTableElementsNum );
        scheduler_setSchedulerScheduleTableIterator( schedulerVar, scheduleTableIterator );

        wcet = task_getTaskWcet( taskVar );
        timerTicks = wcet;

        schedulerState = SCHEDULER_STATE_ENUM__TASK_EXECUTED_IN_WCET_CHECK;
    }
    else
    {
        /* SCHEDULER_PERFORMANCE_SCHEDULING IS_EQUAL_TO ON */
        switchScheduler_performanceScheduling(schedulerVar,&schedulableVar,&stackPointerRetVal,&timerTicks);
        /* SCHEDULER_PERFORMANCE_SCHEDULING IS_EQUAL_TO OFF */
        switchScheduler_classicScheduling(schedulerVar,&schedulableVar,&stackPointerRetVal,&timerTicks,startTick,currentTick);

        schedulerState = SCHEDULER_STATE_ENUM__WAITING_FOR_START_TIME;
    }

    schedulable_setStackPointer( schedulableVar, stackPointerRetVal );
    core_setSchedulableIntoCurrentContext( coreVar, schedulableVar );

    scheduler_setSchedulerState( schedulerVar, schedulerState );
    schedulersSyncState = switchSchedulerSync_sync( schedulerVar, coreVar, currentTick, hyperTick );

    currentTick = ( ( currentTick + timerTicks ) % hyperTick ); 
    scheduler_setSchedulerCurrentTick( schedulerVar, currentTick );

    switchMemoryProtection_setMemoryProtection( coreVar, schedulableVar );

    CIL_sysTimer_setTicks( timerTicks, schedulersSyncState );

    return stackPointerRetVal;
};
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/

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
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION void scheduler_start(void)
{
    BitWidthType  hyperTick,
                  startTick,
                  timerTicks,
                  currentTick,
                  stackPointerRetVal,
                  scheduleTableIterator,
                  scheduleTableElementsNum;

    CosmOS_SchedulerSyncStateType schedulersSyncState;
    CosmOS_SchedulerStateType schedulerState;

    CosmOS_CoreVariableType * coreVar;
    CosmOS_SchedulerVariableType * schedulerVar;
    CosmOS_SchedulableVariableType * schedulableVar;


    coreVar = core_getCoreVar();

    schedulerVar = core_getCoreSchedulerVar( coreVar );
    scheduleTableIterator = scheduler_getSchedulerScheduleTableIterator( schedulerVar );
    scheduleTableElementsNum = scheduler_getSchedulerScheduleTableElementsNum( schedulerVar );

    cosmosAssert( scheduleTableIterator < scheduleTableElementsNum );

    startTick = scheduler_getSchedulerScheduleTableStartTick( schedulerVar, scheduleTableIterator );
    hyperTick = scheduler_getSchedulerHyperTick( schedulerVar );
    currentTick = scheduler_getSchedulerCurrentTick( schedulerVar );
    
    if ( startTick IS_EQUAL_TO currentTick )
    {   
        BitWidthType wcet;

        CosmOS_TaskVariableType * taskVar;

        taskVar = scheduler_getSchedulerScheduleTableTaskVar( schedulerVar, scheduleTableIterator );

        schedulableVar = task_getTaskSchedulable( taskVar );
        stackPointerRetVal = stackInit_schedulableStackInit( schedulableVar );

        schedulable_setState( schedulableVar, SCHEDULABLE_INSTANCE_ENUM__RUNNING );

        scheduleTableIterator = ( ( scheduleTableIterator + 1 ) % scheduleTableElementsNum );
        scheduler_setSchedulerScheduleTableIterator( schedulerVar, scheduleTableIterator );

        wcet = task_getTaskWcet( taskVar );
        timerTicks = wcet;

        schedulerState = SCHEDULER_STATE_ENUM__TASK_EXECUTED_IN_WCET_CHECK;
    }
    else
    {
        /* SCHEDULER_PERFORMANCE_SCHEDULING IS_EQUAL_TO ON */
        switchScheduler_performanceScheduling(schedulerVar,&schedulableVar,&stackPointerRetVal,&timerTicks);
        /* SCHEDULER_PERFORMANCE_SCHEDULING IS_EQUAL_TO OFF */
        switchScheduler_classicScheduling(schedulerVar,&schedulableVar,&stackPointerRetVal,&timerTicks,startTick,currentTick);

        schedulerState = SCHEDULER_STATE_ENUM__WAITING_FOR_START_TIME;
    }

    schedulable_setStackPointer( schedulableVar, stackPointerRetVal );
    core_setSchedulableIntoCurrentContext( coreVar, schedulableVar );

    scheduler_setSchedulerState( schedulerVar, schedulerState );
    schedulersSyncState = switchSchedulerSync_sync( schedulerVar, coreVar, currentTick, hyperTick );

    currentTick = ( currentTick + timerTicks ) % hyperTick;
    scheduler_setSchedulerCurrentTick( schedulerVar, currentTick );

    switchMemoryProtection_setMemoryProtection( coreVar , schedulableVar );

    CIL_sysTimer_setTicks( timerTicks, schedulersSyncState );

    CIL_stack_setStackPointer( stackPointerRetVal );
};
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/
/********************************************************************************
**                        Function Definitions | Stop                          **
********************************************************************************/
/********************************************************************************
**                           END OF THE SOURCE FILE                            **
********************************************************************************/
