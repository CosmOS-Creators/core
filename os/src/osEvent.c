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
  * CosmOS_OsEventStateType event )
  *
  * @details The implementation contains
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
osEvent_triggerEventInternal(
    BitWidthType id,
    CosmOS_BooleanType * handleCores,
    AddressType * data,
    CosmOS_OsEventStateType event )
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

    for ( BitWidthType coreId = 0; coreId < numberOfCores; coreId++ )
    {
        if ( currentCoreId IS_EQUAL_TO coreId )
        {
            osEvent_setOsEventHandleCore( eventCfg, coreId, False );
        }
        else
        {
            osEvent_setOsEventHandleCore(
                eventCfg, coreId, handleCores[coreId] );
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
  * CosmOS_OsEventStateType event,
  * CosmOS_BooleanType * handleCores,
  * AddressType * data )
  *
  * @details The implementation contains
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
osEvent_triggerEvent(
    CosmOS_OsEventStateType event,
    CosmOS_BooleanType * handleCores,
    AddressType * data )
{
    BitWidthType spinlockId, coreId, numberOfCores;

    CosmOS_BooleanType coreInPrivilegedMode, eventNotHandled;
    CosmOS_SpinlockStateType spinlockState;

    CosmOS_OsConfigurationType * osCfg;
    CosmOS_OsEventConfigurationType * eventCfg;

    osCfg = os_getOsCfg();

    numberOfCores = os_getOsNumberOfCores( osCfg );
    eventCfg = os_getOsEventCfg( osCfg );

    spinlockId = osEvent_getOsEventSpinlockId( eventCfg );

    do
    {
        coreId = 0;
        do
        {
            eventNotHandled = osEvent_getOsEventHandleCore( eventCfg, coreId );
            if ( IS_NOT( eventNotHandled ) )
            {
                coreId++;
            }
        } while ( coreId < numberOfCores );

        spinlockState = spinlock_trySpinlock( spinlockId );

    } while (
        spinlockState IS_NOT_EQUAL_TO SPINLOCK_STATE_ENUM__SUCCESSFULLY_LOCKED );

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

    cosmosAssert( spinlockState IS_EQUAL_TO SPINLOCK_STATE_ENUM__RELEASED );
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
  * @details The implementation contains
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
osEvent_dispatchEvent( void )
{
    BitWidthType coreId;

    CosmOS_OsEventStateType event;

    CosmOS_BooleanType handleEvent;

    CosmOS_OsConfigurationType * osCfg;
    CosmOS_CoreConfigurationType * coreCfg;
    CosmOS_OsEventConfigurationType * eventCfg;

    osCfg = os_getOsCfg();
    coreCfg = core_getCoreCfg();

    eventCfg = os_getOsEventCfg( osCfg );

    coreId = core_getCoreId( coreCfg );

    handleEvent = osEvent_getOsEventHandleCore( eventCfg, coreId );

    if ( handleEvent )
    {
        event = osEvent_getOsEvent( eventCfg );

        switch ( event )
        {
            case OS_EVENT_STATE_ENUM__TEST_EVENT:
            {
                coreId = coreId;
                break;
            }
            default:
            {
                break;
            }
        }

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
