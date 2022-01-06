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
  * @details The implementation contains obtaining of the operating system
  * configuration structure and also core configuration structure by calling
  * functions os_getOsCfg and CILcore_getCoreCfg. Operating system configuration
  * structure is then used to get event configuration by calling function
  * os_getOsEventCfg. Os event configuration structure is used to get the event
  * data pool by calling function osEvent_getOsEventDataPool. The interrupt event
  * is then extracted from the os event data pool. To check if the interrupt id
  * stored in the os event data pool is correct we get the number of interrupts
  * by calling the os_getOsNumberOfInterrupts function and check it in the
  * assertion. Then the interrupt configuration is obtained by calling the
  * function os_getOsInterruptCfg and used to get the interrupt handler thread
  * which is then set to SCHEDULABLE_STATE_ENUM__READY. Then we obtain the
  * number of requests by calling function interrupt_getInterruptNumberOfRequests
  * and check with assertion it is non-zero value, because atleast one request
  * had to be created before this function is called. Then we decrement number
  * of requests by one, as the one request will be handled and set it to the
  * interrupt structure by calling interrupt_setInterruptNumberOfRequests
  * function. We need to get also the current running thread on the
  * core obtained by calling the function program_getProgramThread. If condition
  * is implemented to check if the running thread priority is less than the
  * interrupt handler thread priority, if yes the reschedule algorithm is
  * triggered by calling function CILinterrupt_contextSwitchRoutineTrigger.
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
  * @details The implementation contains obtaining core configuration structure
  * by calling function CILcore_getCoreCfg. The interruptCfg argument is used to
  * get the handler thread and number of requests by calling functions
  * interrupt_getInterruptHandlerThread, interrupt_getInterruptNumberOfRequests.
  * If the number of reuests is non-zero value we decrement it by one and set it
  * to the interrupt structure back by calling function
  * interrupt_setInterruptNumberOfRequests. If there is no interrupt request to
  * handle we set the handler thread to the waiting for interrupt state and
  * trigger reschedule algorithm on the current core by calling function
  * CILinterrupt_contextSwitchRoutineTrigger.
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
  * @details The implementation contains obtaining of the operating system
  * configuration structure and also core configuration structure by calling
  * functions os_getOsCfg and CILcore_getCoreCfg. Operating system configuration
  * structure is then used to get number of the interrupts by calling function
  * os_getOsNumberOfInterrupts. Currently the interrupts support only threads
  * and therefore in the if condition is checked if the running schedulable is
  * thread type, otherwise
  * INTERRUPT_STATE_ENUM__ERROR_ONLY_THREADS_CAN_USE_INTERRUPT
  * is returned from the function. The next point is check of the interruptId
  * function argument, if the interruptId is less than numberOfInterrupts it
  * means that user tries to use interrupt in the range of configured interrupts,
  * otherwise INTERRUPT_STATE_ENUM__ERROR_INVALID_INTERRUPT_ID is returned from
  * the function. Then the interrupt configuration structure is obtained by
  * calling os_getOsInterruptCfg function and used to get handler thread which
  * is used in the subsequent if condition to check if the currently running
  * thread (caller of the function) is the same as the handler thread. If not
  * the INTERRUPT_STATE_ENUM__ERROR_ACCESSED_BY_WRONG_THREAD is returned from
  * the function. Otherwise we check if the core is in privileged mode by calling
  * function CILcore_isInPrivilegedMode, if yes the
  * INTERRUPT_STATE_ENUM__ERROR_CAN_BE_CALLED_ONLY_FROM_UNPRIVILEGED is returned
  * from the function. Otherwise the cosmosApiInternal_interrupt_handleInternal
  * function is called and the INTERRUPT_STATE_ENUM__OK is returned from the
  * function.
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
  * @details The implementation contains obtaining of the operating system
  * configuration structure and also core configuration structure by calling
  * functions os_getOsCfg and CILcore_getCoreCfg.Operating system configuration
  * structure is then used to get number of the interrupts by calling function
  * os_getOsNumberOfInterrupts.  The next point is check of the interruptId
  * function argument, if the interruptId is less than numberOfInterrupts it
  * means that user tries to use interrupt in the range of configured interrupts.
  * After this point we can obtain the interrupt configuration by calling the
  * function os_getOsInterruptCfg with the interrupt identifier parameter.
  * The interrupt configuration is then used to get handler thread and number
  * of requests by calling functions interrupt_getInterruptNumberOfRequests and
  * interrupt_getInterruptHandlerThread. Subsequently the assertion is
  * implemented to check if we can increment number of request value or it will
  * overflow. If we are able to increment it we then store the value back to
  * the interrupt structure by calling interrupt_setInterruptNumberOfRequests
  * function. In the next if condition we check if the handler thread is running
  * on the current core, if yes we can decrement the number of request, set
  * the handler thread to SCHEDULABLE_STATE_ENUM__READY and trigger the
  * reschedule algorithm for the current core by calling the function
  * CILinterrupt_contextSwitchRoutineTrigger. Otherwise we have
  * to send os event. First of all we have to configure the array of event
  * handling cores, in our case we just set true the element in that array that
  * belongs to the core where the handler thread is running and leave all other
  * elements set to false. The data transferred by the os event contains just
  * CosmOS_InterruptEventType structure with the interrupt id set to the current
  * interrupt id. After this point the osEvent_triggerEvent is called with the
  * OS_EVENT_INTERRUPT_SIGNALIZETHREAD parameter and assertion is called to check
  * if the os event state is OS_EVENT_STATE_ENUM__OK.
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
