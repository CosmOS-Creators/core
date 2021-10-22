/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file schedulerSync.c
*********************************************************************************
<!--                schedulerSync Unit Local Group Definition                 -->
*********************************************************************************
** @defgroup Local_schedulerSync Local
** @ingroup schedulerSync_unit
** @brief schedulerSync locals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "schedulerSync.h"
#include "coreSync.h"
#include "scheduler.h"

/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_schedulerSync Macros
  * @ingroup Local_schedulerSync
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Macros_schedulerSync
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
  * @defgroup Variables_schedulerSync Variables
  * @ingroup Local_schedulerSync
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Variables_schedulerSync
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
  * @defgroup Apis_schedulerSync_c API's
  * @ingroup Local_schedulerSync
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_schedulerSync_c Getters
  * @ingroup Apis_schedulerSync_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Getters_schedulerSync_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_schedulerSync_c Setters
  * @ingroup Apis_schedulerSync_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Setters_schedulerSync_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_schedulerSync_c General
  * @ingroup Apis_schedulerSync_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_schedulerSync_c
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
  * @fn schedulerSync_sync(CosmOS_SchedulerVariableType * schedulerVar,
  * CosmOS_CoreVariableType * coreVar,
  * BitWidthType currentTick,
  * BitWidthType hyperTick)
  *
  * @brief Algorithm for synchronization during runtime DEMO CODE.
  *
  * @param[in] CosmOS_SchedulerVariableType * schedulerVar
  * @param[in] CosmOS_CoreVariableType * coreVar
  * @param[in] BitWidthType currentTick
  * @param[in] BitWidthType hyperTick
  *
  * @return CosmOS_SchedulerSyncStateType
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_SchedulerSyncStateType
schedulerSync_sync(
    CosmOS_SchedulerVariableType * schedulerVar,
    CosmOS_CoreVariableType * coreVar,
    BitWidthType currentTick,
    BitWidthType hyperTick )
{
    CosmOS_BooleanType syncInitState;

    CosmOS_SchedulerSyncStateType schedulerState =
        SCHEDULER_SYNC_STATE_ENUM__NOT_IN_SYNC;

    syncInitState = scheduler_getSchedulerSyncInitState( schedulerVar );

    if ( __COSMOS_UNLIKELY( syncInitState IS_EQUAL_TO False ) )
    {
        BitWidthType firstSyncTaskStartTick;

        firstSyncTaskStartTick =
            scheduler_getSchedulerFirstSyncTaskStartTick( schedulerVar );

        if ( firstSyncTaskStartTick IS_EQUAL_TO currentTick )
        {
            BitWidthType syncTicks, nextTick;

            syncTicks = scheduler_getSchedulerSyncTicks( schedulerVar );

            nextTick = ( currentTick + syncTicks ) % hyperTick;
            scheduler_setSchedulerNextSyncTick( schedulerVar, nextTick );

            scheduler_setSchedulerSyncInitState( schedulerVar, True );

            schedulerState = SCHEDULER_SYNC_STATE_ENUM__IN_SYNC;
        }
    }
    else
    {
        BitWidthType nextTick;

        nextTick = scheduler_getSchedulerNextSyncTick( schedulerVar );

        if ( __COSMOS_UNLIKELY( nextTick IS_EQUAL_TO currentTick ) )
        {
            BitWidthType syncTicks;

            syncTicks = scheduler_getSchedulerSyncTicks( schedulerVar );

            nextTick = ( currentTick + syncTicks ) % hyperTick;
            scheduler_setSchedulerNextSyncTick( schedulerVar, nextTick );

            schedulerState = SCHEDULER_SYNC_STATE_ENUM__IN_SYNC;
        }
    }

    if ( schedulerState IS_EQUAL_TO SCHEDULER_SYNC_STATE_ENUM__IN_SYNC )
    {
        coreSync_getBarrier( coreVar, SCHEDULERS_SYNC_ID );
        coreSync_reactivateBarrier( coreVar, SCHEDULERS_SYNC_ID );
    }

    return schedulerState;
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
