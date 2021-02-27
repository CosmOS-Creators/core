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
#include "stackInit.h"
#include "CosmOSAssert.h"
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
    BitWidthType currentTick,
                 hyperTick,
                 startTick,
                 timerTicks,
                 stackPointerRetVal,
                 scheduleTableIterator,
                 scheduleTableElementsNum;

    CosmOS_SchedulerSyncStateType schedulersSyncState;

    CosmOS_StackVariableType * stack;
    CosmOS_CoreVariableType * coreVar;
    CosmOS_SchedulerVariableType * schedulerVar;
    

    coreVar = core_getCoreVar();

    schedulerVar = core_getCoreSchedulerVar( coreVar );

    scheduleTableIterator = scheduler_getSchedulerScheduleTableIterator( schedulerVar );
    scheduleTableElementsNum = scheduler_getSchedulerScheduleTableElementsNum( schedulerVar );

    CosmOSAssert( scheduleTableIterator < scheduleTableElementsNum );

    startTick = scheduler_getSchedulerScheduleTableStartTick( schedulerVar, scheduleTableIterator );
    hyperTick = scheduler_getSchedulerHyperTick( schedulerVar );
    currentTick = scheduler_getSchedulerCurrentTick( schedulerVar );
    
    if ( __COSMOS_UNLIKELY( startTick IS_EQUAL_TO currentTick ) )
    {   
        BitWidthType wcet;
        
        CosmOS_TaskVariableType * taskVar;

        taskVar = scheduler_getSchedulerScheduleTableTaskVar( schedulerVar, scheduleTableIterator );
        stackPointerRetVal = stackInit_taskStackInit( taskVar );

        task_setTaskStackPointer( taskVar, stackPointerRetVal );
        core_setTaskIntoCurrentContext( coreVar, taskVar );

        stack = task_getTaskStackVar( taskVar );

        scheduleTableIterator = ( ( scheduleTableIterator + 1 ) % scheduleTableElementsNum );
        scheduler_setSchedulerScheduleTableIterator( schedulerVar, scheduleTableIterator );

        wcet = task_getTaskWcet( taskVar );
        timerTicks = wcet;
    }
    else
    {

    }

    schedulersSyncState = switchSchedulerSync_sync( coreVar, currentTick, 10 );

    currentTick = ( ( currentTick + timerTicks ) % hyperTick ); 
    scheduler_setSchedulerCurrentTick( schedulerVar, currentTick );

    switchMemoryProtection_setStackOverflowProtection( stack );

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
    BitWidthType currentTick,
                 hyperTick,
                 startTick,
                 timerTicks,
                 stackPointerRetVal,
                 scheduleTableIterator,
                 scheduleTableElementsNum;

    CosmOS_StackVariableType * stack;
    CosmOS_CoreVariableType * coreVar;
    CosmOS_SchedulerVariableType * schedulerVar;


    coreVar = core_getCoreVar();

    schedulerVar = core_getCoreSchedulerVar( coreVar );
    scheduleTableIterator = scheduler_getSchedulerScheduleTableIterator( schedulerVar );
    scheduleTableElementsNum = scheduler_getSchedulerScheduleTableElementsNum( schedulerVar );

    CosmOSAssert( scheduleTableIterator < scheduleTableElementsNum );

    startTick = scheduler_getSchedulerScheduleTableStartTick( schedulerVar, scheduleTableIterator );
    hyperTick = scheduler_getSchedulerHyperTick( schedulerVar );
    currentTick = scheduler_getSchedulerCurrentTick( schedulerVar );
    
    if ( __COSMOS_UNLIKELY(startTick IS_EQUAL_TO currentTick) )
    {   
        BitWidthType wcet;

        CosmOS_TaskVariableType * taskVar;

        taskVar = scheduler_getSchedulerScheduleTableTaskVar( schedulerVar, scheduleTableIterator );
        stackPointerRetVal = stackInit_taskStackInit( taskVar );

        task_setTaskStackPointer( taskVar, stackPointerRetVal );
        core_setTaskIntoCurrentContext( coreVar, taskVar );

        stack = task_getTaskStackVar( taskVar );

        scheduleTableIterator = ( ( scheduleTableIterator + 1 ) % scheduleTableElementsNum );
        scheduler_setSchedulerScheduleTableIterator( schedulerVar, scheduleTableIterator );

        wcet = task_getTaskWcet( taskVar );
        timerTicks = wcet;
    }
    else
    {

    }

    currentTick = ( currentTick + timerTicks ) % hyperTick;
    scheduler_setSchedulerCurrentTick( schedulerVar, currentTick );

    switchMemoryProtection_setStackOverflowProtection( stack );

    coreSync_getBarrier( coreVar, OS_START_ID );

    CIL_sysTimer_setTicks( timerTicks, SCHEDULER_SYNC_STATE_ENUM__NOT_IN_SYNC );

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
