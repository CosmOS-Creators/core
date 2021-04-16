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
#include "program.h"
#include "schedulable.h"
#include "stackInit.h"
#include "cosmosAssert.h"
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
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_classicScheduling(CosmOS_BufferVariableType * bufferVar, unsigned char * data)
  * 
  * @brief Pull data from the buffer DEMO CODE.
  * 
  * @param[in]  CosmOS_BufferVariableType * bufferVar
  * @param[in]  unsigned char * data
  * 
  * @return CosmOS_BufferStateType
********************************************************************************/
__OS_FUNC_SECTION static CosmOS_BufferStateType scheduler_classicScheduling(CosmOS_BufferVariableType * buffer, unsigned char * data);

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_performanceScheduling(CosmOS_BufferVariableType * bufferVar, unsigned char * data)
  * 
  * @brief Pull data from the buffer DEMO CODE.
  * 
  * @param[in]  CosmOS_BufferVariableType * bufferVar
  * @param[in]  unsigned char * data
  * 
  * @return CosmOS_BufferStateType
********************************************************************************/
__OS_FUNC_SECTION static CosmOS_BufferStateType scheduler_performanceScheduling(CosmOS_BufferVariableType * buffer, unsigned char * data);
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
  * @fn scheduler_scheduleNextInstance(void) 
  * 
  * @brief Algorithm for scheduling next task DEMO CODE.
  * 
  * @param[in]  BitWidthType stackPointer
  * 
  * @return BitWidthType
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION BitWidthType scheduler_scheduleNextInstance(BitWidthType stackPointer)
{
    BitWidthType  currentTick,
                  hyperTick,
                  startTick,
                  timerTicks,
                  stackPointerRetVal,
                  scheduleTableIterator,
                  scheduleTableElementsNum,
                  scheduleTableIteratorPrior;

    CosmOS_SchedulerSyncStateType schedulersSyncState;
    CosmOS_SchedulerStateType schedulerState;

    CosmOS_CoreVariableType * coreVar;
    CosmOS_TaskVariableType * taskVar;
    CosmOS_SchedulerVariableType * schedulerVar;
    CosmOS_SchedulableVariableType * schedulableVar;


    coreVar = core_getCoreVar();

    schedulerVar = core_getCoreSchedulerVar( coreVar );
    schedulerState = scheduler_getSchedulerState( schedulerVar );

    scheduleTableIterator = scheduler_getSchedulerScheduleTableIterator( schedulerVar );
    scheduleTableIteratorPrior = scheduler_getSchedulerScheduleTableIteratorPrior( schedulerVar );
    scheduleTableElementsNum = scheduler_getSchedulerScheduleTableElementsNum( schedulerVar );

    cosmosAssert( scheduleTableIterator < scheduleTableElementsNum );

    startTick = scheduler_getSchedulerScheduleTableStartTick( schedulerVar, scheduleTableIterator );
    hyperTick = scheduler_getSchedulerHyperTick( schedulerVar );
    currentTick = scheduler_getSchedulerCurrentTick( schedulerVar );


    //this should be moved to the sysTick interrupt with higher priority to have faster response
    if ( schedulerState IS_EQUAL_TO SCHEDULER_STATE_ENUM__TASK_EXECUTED_IN_WCET_CHECK )
    {
        CosmOS_SchedulableStateType schedulableState;

        CosmOS_TaskVariableType * priorTaskVar;
        CosmOS_SchedulableVariableType * priorSchedulable;

        priorTaskVar = scheduler_getSchedulerScheduleTableTaskVar( schedulerVar, scheduleTableIteratorPrior );
        priorSchedulable = task_getTaskSchedulable( priorTaskVar );
        schedulableState = schedulable_getState( priorSchedulable );

        if ( schedulableState IS_NOT_EQUAL_TO SCHEDULABLE_INSTANCE_ENUM__EXECUTED )
        {
            /* reaction */
        }
    }

    if ( startTick IS_EQUAL_TO currentTick )
    {   
        BitWidthType wcet;

        taskVar = scheduler_getSchedulerScheduleTableTaskVar( schedulerVar, scheduleTableIterator );

        schedulableVar = task_getTaskSchedulable( taskVar );
        stackPointerRetVal = stackInit_schedulableStackInit( schedulableVar );

        schedulable_setState( schedulableVar, SCHEDULABLE_INSTANCE_ENUM__RUNNING );

        scheduler_setSchedulerScheduleTableIteratorPrior( schedulerVar, scheduleTableIterator );
        scheduleTableIterator = ( ( scheduleTableIterator + 1 ) % scheduleTableElementsNum );
        scheduler_setSchedulerScheduleTableIterator( schedulerVar, scheduleTableIterator );

        wcet = task_getTaskWcet( taskVar );
        timerTicks = wcet;

        schedulerState = SCHEDULER_STATE_ENUM__TASK_EXECUTED_IN_WCET_CHECK;
    }
    else
    {
        taskVar = scheduler_getSchedulerIdleTaskVar( schedulerVar );

        schedulableVar = task_getTaskSchedulable( taskVar );
        stackPointerRetVal = stackInit_schedulableStackInit( schedulableVar );

        if ( startTick < currentTick )
        {
            timerTicks = scheduler_getSchedulerLastToFirstTaskTicks( schedulerVar );
        }
        else
        {
            timerTicks = startTick - currentTick;
        }

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
    CosmOS_TaskVariableType * taskVar;
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

        taskVar = scheduler_getSchedulerScheduleTableTaskVar( schedulerVar, scheduleTableIterator );

        schedulableVar = task_getTaskSchedulable( taskVar );
        stackPointerRetVal = stackInit_schedulableStackInit( schedulableVar );

        schedulable_setState( schedulableVar, SCHEDULABLE_INSTANCE_ENUM__RUNNING );

        scheduler_setSchedulerScheduleTableIteratorPrior( schedulerVar, scheduleTableIterator );
        scheduleTableIterator = ( ( scheduleTableIterator + 1 ) % scheduleTableElementsNum );
        scheduler_setSchedulerScheduleTableIterator( schedulerVar, scheduleTableIterator );

        wcet = task_getTaskWcet( taskVar );
        timerTicks = wcet;

        schedulerState = SCHEDULER_STATE_ENUM__TASK_EXECUTED_IN_WCET_CHECK;
    }
    else
    {
        taskVar = scheduler_getSchedulerIdleTaskVar( schedulerVar );

        schedulableVar = task_getTaskSchedulable( taskVar );
        stackPointerRetVal = stackInit_schedulableStackInit( schedulableVar );

        timerTicks = startTick - currentTick;
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
