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
  * AddressType * data,
  * CosmOS_OsEventStateType event )
  *
  * @brief OS trigger event internal function. This function cannot be called
  * from the unprivileged context directly.
  *
  * @param[in]  id is used during the system call dispatching
  * @param[in]  event required event to trigger
  * @param[in]  handleCores pointer to the array with all handleCores booleans
  * @param[in]  data pointer to the data passed to the event
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void
osEvent_triggerEventInternal(
    BitWidthType id,
    CosmOS_BooleanType * handleCores,
    AddressType * data,
    CosmOS_OsEventStateType event );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osEvent_triggerEvent(
  * CosmOS_OsEventStateType event,
  * CosmOS_BooleanType * handleCores,
  * AddressType * data )
  *
  * @brief OS event trigger function.
  *
  * @param[in]  event required event to trigger
  * @param[in]  handleCores pointer to the array with all handleCores booleans
  * @param[in]  data pointer to the data passed to the event
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void
osEvent_triggerEvent(
    CosmOS_OsEventStateType event,
    CosmOS_BooleanType * handleCores,
    AddressType * data );

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
  * @fn osEvent_getHandleCores(CosmOS_OsEventConfigurationType * osEvent)
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
  * @fn osEvent_getOsEvent(CosmOS_OsEventConfigurationType * osEvent)
  *
  * @brief Get event.
  *
  * @param[in]  osEvent configuration pointer
  *
  * @return CosmOS_OsEventStateType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_OsEventStateType
osEvent_getOsEvent( CosmOS_OsEventConfigurationType * osEvent )
{
    return ( CosmOS_OsEventStateType )( osEvent->var->event );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osEvent_getOsEventData(CosmOS_OsEventConfigurationType * osEvent)
  *
  * @brief Get data pointer.
  *
  * @param[in]  osEvent configuration pointer
  *
  * @return AddressType *
********************************************************************************/
__STATIC_FORCEINLINE AddressType *
osEvent_getOsEventData( CosmOS_OsEventConfigurationType * osEvent )
{
    return (AddressType *)( osEvent->var->data );
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
    CosmOS_OsEventStateType paramEvent )
{
    osEvent->var->event = paramEvent;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osEvent_setOsEventData(CosmOS_OsEventConfigurationType * osEvent)
  *
  * @brief Set data pointer.
  *
  * @param[out]  osEvent configuration pointer
  * @param[in]  paramData pointer
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
osEvent_setOsEventData(
    CosmOS_OsEventConfigurationType * osEvent,
    AddressType * paramData )
{
    osEvent->var->data = paramData;
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
