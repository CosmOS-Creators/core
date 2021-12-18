/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file osEvent.h
*********************************************************************************
<!--                       osEvent Unit Group Definition                      -->
*********************************************************************************
** @defgroup osEvent_unit osEvent Unit
** @ingroup os_module
** @brief osEvent Unit
** @details lorem
*********************************************************************************
<!--                           Version Information                            -->
*********************************************************************************
** @version 1.0.0
** @date 1.8.2020
** @author https://github.com/PavolKostolansky
*********************************************************************************
<!--                          Warnings and License                            -->
*********************************************************************************
** @warning Modifying code can lead to unexpected behaviour of the whole system
** @copyright MIT License
*********************************************************************************
<!--                   osEvent Unit Global Group Definition                   -->
*********************************************************************************
** @defgroup Global_osEvent Global
** @ingroup osEvent_unit
** @brief osEvent globals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __OSEVENT_H__
#define __OSEVENT_H__
/********************************************************************************
**                         START OF C++ SUPPORT SECTION                        **
********************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "cosmosTypes.h"
#include "memoryMapping.h"
#include "sysDefs.h"

/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_osEvent_h Macros
  * @ingroup Global_osEvent
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_osEvent_h
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
  * @defgroup Variables_osEvent_h Variables
  * @ingroup Global_osEvent
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_osEvent_h
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
  * @defgroup Apis_osEvent_h API's
  * @ingroup Global_osEvent
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_osEvent_h Getters
  * @ingroup Apis_osEvent_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_osEvent_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_osEvent_h Setters
  * @ingroup Apis_osEvent_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_osEvent_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_osEvent_h General
  * @ingroup Apis_osEvent_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osEvent_triggerEventInternal(
  * BitWidthType id,
  * CosmOS_BooleanType * handleCores,
  * BitWidthType event )
  *
  * @brief OS trigger event internal function. This function cannot be called
  * from the unprivileged context directly.
  *
  * @param[in]  id is used during the system call dispatching
  * @param[in]  handleCores pointer to the array with all handleCores booleans
  * @param[in]  event required event to trigger
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void
osEvent_triggerEventInternal(
    BitWidthType id,
    CosmOS_BooleanType * handleCores,
    BitWidthType event );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osEvent_triggerEvent(
  * BitWidthType event,
  * CosmOS_BooleanType * handleCores,
  * AddressType * data,
  * BitWidthType size )
  *
  * @brief OS event trigger function.
  *
  * @param[in]  event required event to trigger
  * @param[in]  handleCores pointer to the array with all handleCores booleans
  * @param[in]  data pointer to the data passed to the event
  * @param[in]  size of the data to copy
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION CosmOS_OsEventStateType
osEvent_triggerEvent(
    BitWidthType event,
    CosmOS_BooleanType * handleCores,
    AddressType * data,
    BitWidthType size );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osEvent_dispatchEvent( void )
  *
  * @brief OS dispatch event function.
  *
  * @param[in]  none
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void
osEvent_dispatchEvent( void );
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_osEvent_h
********************************************************************************/
/********************************************************************************
**                         Function Prototypes | Stop                          **
********************************************************************************/
/********************************************************************************
**                        Function Definitions | Start                         **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_osEvent_h Getters
  * @ingroup Apis_osEvent_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osEvent_getOsEventHandleCores(CosmOS_OsEventConfigurationType * osEvent)
  *
  * @brief Get handleCores pointer.
  *
  * @param[in]  osEvent configuration pointer
  *
  * @return CosmOS_BooleanType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BooleanType *
osEvent_getOsEventHandleCores( CosmOS_OsEventConfigurationType * osEvent )
{
    return (CosmOS_BooleanType *)( osEvent->handleCores );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osEvent_getOsEventHandleCore(CosmOS_OsEventConfigurationType * osEvent
  * BitWidthType coreId)
  *
  * @brief Get handleCore boolean.
  *
  * @param[in]  osEvent configuration pointer
  * @param[in]  coreId id of the core
  *
  * @return CosmOS_BooleanType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BooleanType
osEvent_getOsEventHandleCore(
    CosmOS_OsEventConfigurationType * osEvent,
    BitWidthType coreId )
{
    return ( CosmOS_BooleanType )( osEvent->handleCores[coreId] );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osEvent_getOsEventSpinlockId(CosmOS_OsEventConfigurationType * osEvent)
  *
  * @brief Get spinlockId.
  *
  * @param[in]  osEvent configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
osEvent_getOsEventSpinlockId( CosmOS_OsEventConfigurationType * osEvent )
{
    return ( BitWidthType )( osEvent->spinlockId );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osEvent_getOsEventFuncs(CosmOS_OsEventConfigurationType * osEvent)
  *
  * @brief Get eventFuncs.
  *
  * @param[in]  osEvent configuration pointer
  *
  * @return CosmOS_GenericVoidType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_GenericVoidType *
osEvent_getOsEventFuncs( CosmOS_OsEventConfigurationType * osEvent )
{
    return (CosmOS_GenericVoidType *)( osEvent->eventFuncs );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osEvent_getOsEventFunc(CosmOS_OsEventConfigurationType * osEvent)
  *
  * @brief Get eventFunc based on event.
  *
  * @param[in]  osEvent configuration pointer
  * @param[in]  event identifier of the event pointing to the correct function
  *
  * @return CosmOS_GenericVoidType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_GenericVoidType
osEvent_getOsEventFunc(
    CosmOS_OsEventConfigurationType * osEvent,
    BitWidthType event )
{
    return ( CosmOS_GenericVoidType )( osEvent->eventFuncs[event] );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osEvent_getOsEventNumberOfEventFuncs(CosmOS_OsEventConfigurationType *
  * osEvent)
  *
  * @brief Get numberOfEventFuncs.
  *
  * @param[in]  osEvent configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
osEvent_getOsEventNumberOfEventFuncs( CosmOS_OsEventConfigurationType * osEvent )
{
    return ( BitWidthType )( osEvent->numberOfEventFuncs );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osEvent_getOsEvent(CosmOS_OsEventConfigurationType * osEvent)
  *
  * @brief Get event.
  *
  * @param[in]  osEvent configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
osEvent_getOsEvent( CosmOS_OsEventConfigurationType * osEvent )
{
    return ( BitWidthType )( osEvent->var->event );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osEvent_getOsEventDataPool(CosmOS_OsEventConfigurationType * osEvent)
  *
  * @brief Get dataPool pointer.
  *
  * @param[in]  osEvent configuration pointer
  *
  * @return AddressType *
********************************************************************************/
__STATIC_FORCEINLINE AddressType *
osEvent_getOsEventDataPool( CosmOS_OsEventConfigurationType * osEvent )
{
    return (AddressType *)( osEvent->dataPool );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osEvent_getOsEventDataPoolSize(CosmOS_OsEventConfigurationType * osEvent)
  *
  * @brief Get dataPoolSize.
  *
  * @param[in]  osEvent configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
osEvent_getOsEventDataPoolSize( CosmOS_OsEventConfigurationType * osEvent )
{
    return ( BitWidthType )( osEvent->dataPoolSize );
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_osEvent_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_osEvent_h Setters
  * @ingroup Apis_osEvent_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osEvent_setOsEventHandleCore(CosmOS_OsEventConfigurationType * osEvent
  * BitWidthType coreId)
  *
  * @brief Set handleCore boolean.
  *
  * @param[in]  osEvent configuration pointer
  * @param[in]  coreId id of the core
  * @param[in]  paramHandleCore core should handle event boolean
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
osEvent_setOsEventHandleCore(
    CosmOS_OsEventConfigurationType * osEvent,
    BitWidthType coreId,
    CosmOS_BooleanType paramHandleCore )
{
    osEvent->handleCores[coreId] = paramHandleCore;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osEvent_setOsEvent(CosmOS_OsEventConfigurationType * osEvent)
  *
  * @brief Set event.
  *
  * @param[out]  osEvent configuration pointer
  * @param[in]  paramEvent event
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
osEvent_setOsEvent(
    CosmOS_OsEventConfigurationType * osEvent,
    BitWidthType paramEvent )
{
    osEvent->var->event = paramEvent;
}

/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_osEvent_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_osEvent_h General
  * @ingroup Apis_osEvent_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_osEvent_h
********************************************************************************/
/********************************************************************************
**                        Function Definitions | Stop                          **
********************************************************************************/
#ifdef __cplusplus
}
#endif
/********************************************************************************
**                         END OF C++ SUPPORT SECTION                          **
********************************************************************************/
#endif
/********************************************************************************
**                           END OF THE HEADER FILE                            **
********************************************************************************/
