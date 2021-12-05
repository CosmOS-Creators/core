/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file osEvent.c
*********************************************************************************
<!--                    osEvent Unit Local Group Definition                   -->
*********************************************************************************
** @defgroup Local_osEvent Local
** @ingroup osEvent_unit
** @brief osEvent locals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "osEvent.h"
#include "core.h"
#include "cosmosApiInternal.h"
#include "cosmosAssert.h"
#include "os.h"
#include "spinlock.h"

/* CIL interfaces */
#include "CILcore.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_osEvent_c Macros
  * @ingroup Local_osEvent
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_osEvent_c
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
  * @defgroup Variables_osEvent_c Variables
  * @ingroup Local_osEvent
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_osEvent_c
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
  * @defgroup Apis_osEvent_c API's
  * @ingroup Local_osEvent
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_osEvent_c Getters
  * @ingroup Apis_osEvent_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_osEvent_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_osEvent_c Setters
  * @ingroup Apis_osEvent_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_osEvent_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_osEvent_c General
  * @ingroup Apis_osEvent_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_osEvent_c
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
  * @fn osEvent_triggerEventInternal(
  * BitWidthType id,
  * CosmOS_BooleanType * handleCores,
  * AddressType * data,
  * BitWidthType event )
  *
  * @details The implementation contains obtaining of operating system
  * configuration structure used to get number of cores and event configuration
  * structure by calling functions os_getOsNumberOfCores and os_getOsEventCfg.
  * CILcore_getCoreId call returns then id of the current core. Then os event
  * and the data pointer are set in the event variable by calling functions
  * osEvent_setOsEvent and osEvent_setOsEventData. After this point the for
  * loop is implemented that iterates over all cores, to set cores which handle
  * this event except the current core - it remains False, by calling function
  * osEvent_setOsEventHandleCore. In the end other cores are signalized by
  * calling CILcore_triggerEvent function.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
osEvent_triggerEventInternal(
    BitWidthType id,
    CosmOS_BooleanType * handleCores,
    AddressType * data,
    BitWidthType event )
{
    BitWidthType numberOfCores, currentCoreId;

    CosmOS_OsConfigurationType * osCfg;
    CosmOS_OsEventConfigurationType * eventCfg;

    osCfg = os_getOsCfg();

    numberOfCores = os_getOsNumberOfCores( osCfg );
    eventCfg = os_getOsEventCfg( osCfg );

    currentCoreId = CILcore_getCoreId();

    osEvent_setOsEvent( eventCfg, event );

    osEvent_setOsEventData( eventCfg, data );

    for ( BitWidthType coreIt = 0; coreIt < numberOfCores; coreIt++ )
    {
        if ( currentCoreId IS_EQUAL_TO coreIt )
        {
            osEvent_setOsEventHandleCore( eventCfg, coreIt, False );
        }
        else
        {
            osEvent_setOsEventHandleCore(
                eventCfg, coreIt, handleCores[coreIt] );
        }
    }

    CILcore_triggerEvent();
};
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osEvent_triggerEvent(
  * BitWidthType event,
  * CosmOS_BooleanType * handleCores,
  * AddressType * data )
  *
  * @details The implementation contains obtaining of operating system
  * configuration structure used to get number of cores and event configuration
  * structure by calling functions os_getOsNumberOfCores and os_getOsEventCfg.
  * CILcore_getCoreId call returns then id of the current core. Next the number
  * of event handler functions is obtained by calling function
  * osEvent_getOsEventNumberOfEventFuncs. If the event number is less than
  * numberOfEventFuncs the OS_EVENT_STATE_ENUM__ERROR_INVALID_EVENT is returned
  * from the function. Otherwise a for loop is implemented that iterates over all
  * cores except the current core to check if there is atleast one core that
  * should handle this event, otherwise the function returns value
  * OS_EVENT_STATE_ENUM__ERROR_ATLEAST_ONE_CORE_MUST_HANDLE_EVENT.
  * If there is atleast one core except the current one that should handle this
  * event the function osEvent_getOsEventSpinlockId gets the spinlockId of the
  * event spinlock used in the function spinlock_getSpinlock. Assertion is then
  * implemented to check if the spinlock was obtained correctly as the function
  * cannot work properly without it. Then a do-while loop is implemented to check
  * if there is any unhandled event, if yes we wait in this loop till the event
  * will be handled and proceed afterwards. Next the CILcore_isInPrivilegedMode
  * function is called to check if the core is in privileged mode, and call
  * osEvent_triggerEventInternal internal function which sets system internal
  * event variable as systemCall or a normal function call. After this point the
  * spinlock can be again unlocked by calling function spinlock_releaseSpinlock
  * and assertion is implemented to check if the spinlock was released. In the
  * end the return value is set to OS_EVENT_STATE_ENUM__OK and returned from the
  * function.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_OsEventStateType
osEvent_triggerEvent(
    BitWidthType event,
    CosmOS_BooleanType * handleCores,
    AddressType * data )
{
    BitWidthType spinlockId, coreId, numberOfCores, numberOfEventFuncs,
        currentCoreId;

    CosmOS_BooleanType coreInPrivilegedMode, eventNotHandled,
        handleAtleastOneCore;
    CosmOS_SpinlockStateType spinlockState;

    CosmOS_OsEventStateType returnValue;

    CosmOS_OsConfigurationType * osCfg;
    CosmOS_CoreConfigurationType * coreCfg;
    CosmOS_OsEventConfigurationType * eventCfg;

    osCfg = os_getOsCfg();

    numberOfCores = os_getOsNumberOfCores( osCfg );
    eventCfg = os_getOsEventCfg( osCfg );

    osCfg = os_getOsCfg();
    coreCfg = CILcore_getCoreCfg();

    currentCoreId = core_getCoreId( coreCfg );

    numberOfEventFuncs = osEvent_getOsEventNumberOfEventFuncs( eventCfg );

    if ( event < numberOfEventFuncs )
    {
        handleAtleastOneCore = False;
        for ( BitWidthType coreIt = 0; coreIt < numberOfCores; coreIt++ )
        {
            if ( currentCoreId IS_NOT_EQUAL_TO coreIt )
            {
                if ( handleCores[coreIt] )
                {
                    handleAtleastOneCore = True;
                }
            }
        }

        if ( handleAtleastOneCore )
        {
            spinlockId = osEvent_getOsEventSpinlockId( eventCfg );

            spinlockState = spinlock_getSpinlock( spinlockId );

            cosmosAssert( spinlockState IS_EQUAL_TO
                              SPINLOCK_STATE_ENUM__SUCCESSFULLY_LOCKED );

            coreId = 0;
            do
            {
                eventNotHandled =
                    osEvent_getOsEventHandleCore( eventCfg, coreId );
                if ( IS_NOT( eventNotHandled ) )
                {
                    coreId++;
                }
            } while ( coreId < numberOfCores );

            coreInPrivilegedMode = CILcore_isInPrivilegedMode();

            if ( coreInPrivilegedMode )
            {
                osEvent_triggerEventInternal( 0, handleCores, data, event );
            }
            else
            {
                cosmosApiInternal_osEvent_triggerEventInternal(
                    handleCores, data, event );
            }

            spinlockState = spinlock_releaseSpinlock( spinlockId );

            cosmosAssert(
                spinlockState IS_EQUAL_TO SPINLOCK_STATE_ENUM__RELEASED );

            returnValue = OS_EVENT_STATE_ENUM__OK;
        }
        else
        {
            returnValue =
                OS_EVENT_STATE_ENUM__ERROR_ATLEAST_ONE_CORE_MUST_HANDLE_EVENT;
        }
    }
    else
    {
        returnValue = OS_EVENT_STATE_ENUM__ERROR_INVALID_EVENT;
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
  * @fn osEvent_dispatchEvent( void )
  *
  * @details The implementation contains obtaining of operating system
  * configuration structure used to get event configuration structure by calling
  * function os_getOsEventCfg. CILcore_getCoreId call returns then id of the
  * current core used as parameter in the function osEvent_getOsEventHandleCore
  * to check if the current core should handle the event, if yes the function
  * osEvent_getOsEvent is called to get the event number and then the number of
  * event handler function is obtained by calling the function
  * osEvent_getOsEventNumberOfEventFuncs. Assertion checks if the event number
  * is less than number of event handler functions (as these are mapped together)
  * and event handler is then obtained by osEvent_getOsEventFunc. Another
  * assertion checks if the handles is not null pointer and event handler is
  * called right afterwards. Then the function osEvent_setOsEventHandleCore is
  * called to set handleCore variable for this core to handled (False).
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
osEvent_dispatchEvent( void )
{
    BitWidthType event, coreId, numberOfEventFuncs;

    CosmOS_BooleanType handleEvent;

    CosmOS_OsConfigurationType * osCfg;
    CosmOS_OsEventConfigurationType * eventCfg;

    CosmOS_GenericVoidType eventHandler;

    osCfg = os_getOsCfg();

    eventCfg = os_getOsEventCfg( osCfg );

    coreId = CILcore_getCoreId();

    handleEvent = osEvent_getOsEventHandleCore( eventCfg, coreId );

    if ( handleEvent )
    {
        event = osEvent_getOsEvent( eventCfg );

        numberOfEventFuncs = osEvent_getOsEventNumberOfEventFuncs( eventCfg );
        cosmosAssert( event < numberOfEventFuncs );

        eventHandler = osEvent_getOsEventFunc( eventCfg, event );
        cosmosAssert( eventHandler );

        eventHandler();
        osEvent_setOsEventHandleCore( eventCfg, coreId, False );
    }
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
