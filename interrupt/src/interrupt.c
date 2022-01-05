/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file interrupt.c
*********************************************************************************
<!--                  interrupt Unit Local Group Definition                   -->
*********************************************************************************
** @defgroup Local_interrupt Local
** @ingroup interrupt_unit
** @brief interrupt locals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "interrupt.h"
#include "core.h"
#include "cosmosApiInternal.h"
#include "cosmosAssert.h"
#include "os.h"
#include "osEvent.h"
#include "program.h"

/* CIL interfaces */
#include "CILcore.h"
#include "CILinterrupt.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_interrupt_c Macros
  * @ingroup Local_interrupt
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_interrupt_c
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
  * @defgroup Variables_interrupt_c Variables
  * @ingroup Local_interrupt
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_interrupt_c
********************************************************************************/
/********************************************************************************
**                              Variables | Stop                               **
********************************************************************************/
/********************************************************************************
**                         Function Prototypes | Start                         **
********************************************************************************/
/********************************************************************************
* DOXYGEN DEF GROUP                                                            **
* ***************************************************************************//**
* @defgroup Apis_interrupt_c API's
* @ingroup Local_interrupt
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_interrupt_c Getters
  * @ingroup Apis_interrupt_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_interrupt_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_interrupt_c Setters
  * @ingroup Apis_interrupt_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_interrupt_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_interrupt_c General
  * @ingroup Apis_interrupt_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_interrupt_c
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
  * @fn interrupt_handleInternal(
  * BitWidthType id,
  * CosmOS_InterruptConfigurationType * interruptCfg )
  *
  * @details The implementation contains
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
interrupt_signalizeThread( void )
{
    BitWidthType numberOfInterrupts, numberOfRequests;

    CosmOS_ThreadConfigurationType * handlerThread;
    CosmOS_ThreadConfigurationType * currentThreadCfg;
    CosmOS_CoreConfigurationType * coreCfg;
    CosmOS_OsConfigurationType * osCfg;
    CosmOS_OsEventConfigurationType * eventCfg;
    CosmOS_InterruptConfigurationType * interruptCfg;

    osCfg = os_getOsCfg();

    coreCfg = CILcore_getCoreCfg();

    eventCfg = os_getOsEventCfg( osCfg );

    CosmOS_InterruptEventType * interruptEvent =
        (CosmOS_InterruptEventType *)osEvent_getOsEventDataPool( eventCfg );

    numberOfInterrupts = os_getOsNumberOfInterrupts( osCfg );

    cosmosAssert( interruptEvent->interruptId < numberOfInterrupts );

    interruptCfg = os_getOsInterruptCfg( osCfg, interruptEvent->interruptId );

    handlerThread = interrupt_getInterruptHandlerThread( interruptCfg );

    cosmosAssert(
        handlerThread->schedulable->coreId IS_EQUAL_TO coreCfg->coreId );

    handlerThread->schedulable->var->state = SCHEDULABLE_STATE_ENUM__READY;

    numberOfRequests = interrupt_getInterruptNumberOfRequests( interruptCfg );

    cosmosAssert( numberOfRequests );

    numberOfRequests--;

    interrupt_setInterruptNumberOfRequests( interruptCfg, numberOfRequests );

    currentThreadCfg = program_getProgramThread(
        (CosmOS_ProgramConfigurationType *)coreCfg->var->programInExecution,
        ( (CosmOS_SchedulableConfigurationType *)
              coreCfg->var->schedulableInExecution )
            ->instanceId );

    if ( handlerThread->priority > currentThreadCfg->priority )
    {
        CILinterrupt_contextSwitchRoutineTrigger();
    }
};
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn interrupt_handleInternal(
  * BitWidthType id,
  * CosmOS_InterruptConfigurationType * interruptCfg )
  *
  * @details The implementation contains
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
interrupt_handleInternal(
    BitWidthType id,
    CosmOS_InterruptConfigurationType * interruptCfg )
{
    BitWidthType numberOfRequests;
    CosmOS_ThreadConfigurationType * handlerThread;
    CosmOS_CoreConfigurationType * coreCfg;

    coreCfg = CILcore_getCoreCfg();

    handlerThread = interrupt_getInterruptHandlerThread( interruptCfg );

    cosmosAssert( handlerThread->schedulable IS_EQUAL_TO
                      coreCfg->var->schedulableInExecution );

    numberOfRequests = interrupt_getInterruptNumberOfRequests( interruptCfg );

    if ( numberOfRequests )
    {
        numberOfRequests--;
        interrupt_setInterruptNumberOfRequests( interruptCfg, numberOfRequests );
    }
    else
    {
        handlerThread->schedulable->var->state =
            SCHEDULABLE_STATE_ENUM__WAITING_FOR_INTERRUPT;
        CILinterrupt_contextSwitchRoutineTrigger();
    }

    __SUPRESS_UNUSED_VAR( coreCfg );
};
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn interrupt_handle(
  * BitWidthType interruptId)
  *
  * @details The implementation contains
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_InterruptStateType
interrupt_handle( BitWidthType interruptId )
{
    BitWidthType numberOfInterrupts;

    CosmOS_BooleanType coreInPrivilegedMode;

    CosmOS_InterruptStateType returnValue;

    CosmOS_OsConfigurationType * osCfg;
    CosmOS_CoreConfigurationType * coreCfg;

    osCfg = os_getOsCfg();

    coreCfg = CILcore_getCoreCfg();

    numberOfInterrupts = os_getOsNumberOfInterrupts( osCfg );

    if ( ( (CosmOS_SchedulableConfigurationType *)
               coreCfg->var->schedulableInExecution )
             ->instanceType IS_EQUAL_TO SCHEDULABLE_INSTANCE_ENUM__THREAD )
    {
        if ( interruptId < numberOfInterrupts )
        {
            CosmOS_InterruptConfigurationType * interruptCfg;
            CosmOS_ThreadConfigurationType * handlerThread;

            interruptCfg = os_getOsInterruptCfg( osCfg, interruptId );

            handlerThread = interrupt_getInterruptHandlerThread( interruptCfg );

            if ( handlerThread->schedulable IS_EQUAL_TO
                     coreCfg->var->schedulableInExecution )
            {
                coreInPrivilegedMode = CILcore_isInPrivilegedMode();

                if ( IS_NOT( coreInPrivilegedMode ) )
                {
                    cosmosApiInternal_interrupt_handleInternal( interruptCfg );
                    returnValue = INTERRUPT_STATE_ENUM__OK;
                }
                else
                {
                    returnValue =
                        INTERRUPT_STATE_ENUM__ERROR_CAN_BE_CALLED_ONLY_FROM_UNPRIVILEGED;
                }
            }
            else
            {
                returnValue =
                    INTERRUPT_STATE_ENUM__ERROR_ACCESSED_BY_WRONG_THREAD;
            }
        }
        else
        {
            returnValue = INTERRUPT_STATE_ENUM__ERROR_INVALID_INTERRUPT_ID;
        }
    }
    else
    {
        returnValue = INTERRUPT_STATE_ENUM__ERROR_ONLY_THREADS_CAN_USE_INTERRUPT;
    }

    return returnValue;
};
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn interrupt_handleInternal(
  * BitWidthType id,
  * CosmOS_InterruptConfigurationType * interruptCfg )
  *
  * @details The implementation contains
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
interrupt_trigger( BitWidthType interruptId )
{
    BitWidthType numberOfInterrupts, numberOfRequests;

    CosmOS_ThreadConfigurationType * handlerThread;
    CosmOS_CoreConfigurationType * coreCfg;
    CosmOS_OsConfigurationType * osCfg;
    CosmOS_InterruptConfigurationType * interruptCfg;

    osCfg = os_getOsCfg();

    coreCfg = CILcore_getCoreCfg();

    numberOfInterrupts = os_getOsNumberOfInterrupts( osCfg );

    cosmosAssert( numberOfInterrupts > interruptId );

    interruptCfg = os_getOsInterruptCfg( osCfg, interruptId );
    numberOfRequests = interrupt_getInterruptNumberOfRequests( interruptCfg );

    cosmosAssert( IS_NOT( __ADD_OVERFLOW(
        numberOfRequests, (BitWidthType)1, &numberOfRequests ) ) );

    interrupt_setInterruptNumberOfRequests( interruptCfg, numberOfRequests );

    handlerThread = interrupt_getInterruptHandlerThread( interruptCfg );

    if ( handlerThread->schedulable->coreId IS_EQUAL_TO coreCfg->coreId )
    {
        numberOfRequests--;

        interrupt_setInterruptNumberOfRequests( interruptCfg, numberOfRequests );

        handlerThread->schedulable->var->state = SCHEDULABLE_STATE_ENUM__READY;

        CILinterrupt_contextSwitchRoutineTrigger();
    }
    else
    {
        CosmOS_InterruptEventType interruptEvent;
        CosmOS_OsEventStateType osEventState;

        CosmOS_BooleanType osEventHandleCore[osCfg->numberOfCores];

        for ( BitWidthType coreIt = 0; coreIt < osCfg->numberOfCores; coreIt++ )
        {
            if ( handlerThread->schedulable->coreId IS_EQUAL_TO coreIt )
            {
                osEventHandleCore[coreIt] = True;
            }
            else
            {
                osEventHandleCore[coreIt] = False;
            }
        }

        interruptEvent.interruptId = interruptCfg->interruptId;

        osEventState = osEvent_triggerEvent(
            OS_EVENT_INTERRUPT_SIGNALIZETHREAD,
            osEventHandleCore,
            (AddressType *)&interruptEvent,
            sizeof( interruptEvent ) );

        cosmosAssert( osEventState IS_EQUAL_TO OS_EVENT_STATE_ENUM__OK );
    }

    __SUPRESS_UNUSED_VAR( coreCfg );
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
