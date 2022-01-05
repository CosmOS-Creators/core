/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file interrupt.h
*********************************************************************************
<!--                     interrupt Module Group Definition                    -->
*********************************************************************************
** @defgroup interrupt_module interrupt
** @brief interrupt Module
** @details lorem
*********************************************************************************
<!--                      interrupt Unit Group Definition                     -->
*********************************************************************************
** @defgroup interrupt_unit interrupt Unit
** @ingroup interrupt_module
** @brief interrupt Unit
** @details lorem
*********************************************************************************
<!--                           Version Information                            -->
*********************************************************************************
** @version 1.0.0
** @date 18.08.2021
** @author https://github.com/pavolkostolansky
*********************************************************************************
<!--                          Warnings and License                            -->
*********************************************************************************
** @warning Modifying code can lead to unexpected behaviour of the whole system
** @copyright MIT License
*********************************************************************************
<!--                 interrupt Unit Global Group Definition                   -->
*********************************************************************************
** @defgroup Global_interrupt Global
** @ingroup interrupt_unit
** @brief interrupt globals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __INTERRUPT_H__
#define __INTERRUPT_H__
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

/* CIL interfaces */
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
  * @defgroup Macros_interrupt_h Macros
  * @ingroup Global_interrupt
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/* Macros_interrupt_h
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
  * @defgroup Variables_interrupt_h Variables
  * @ingroup Global_interrupt
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/* Variables_interrupt_h
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
* @defgroup Apis_interrupt_h API's
* @ingroup Global_interrupt
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_interrupt_h Getters
  * @ingroup Apis_interrupt_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/* Getters_interrupt_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_interrupt_h Setters
  * @ingroup Apis_interrupt_h
  * @{
********************************************************************************/

/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/* Setters_interrupt_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_interrupt_h General
  * @ingroup Apis_interrupt_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn interrupt_signalizeThread( void )
  *
  * @brief Interrupt signalize thread event handler. This function cannot be
  * called from the unprivileged context directly. DEMO
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void
interrupt_signalizeThread( void );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn interrupt_handleInternal(
  * BitWidthType id,
  * CosmOS_InterruptConfigurationType * interruptCfg)
  *
  * @brief Interrupt handle internal. This function cannot be called
  * from the unprivileged context directly. DEMO
  *
  * @param[in]  id is used during the system call dispatching
  * @param[in]  interruptCfg interrupt configuration pointer
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void
interrupt_handleInternal(
    BitWidthType id,
    CosmOS_InterruptConfigurationType * interruptCfg );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn interrupt_handle(BitWidthType interruptId)
  *
  * @brief Interrupt handle function. This function can be called from the
  * thread configured as the interrupt handler thread. DEMO
  *
  * @param[in]  interruptId is identifier of interrupt to handle
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION CosmOS_InterruptStateType
interrupt_handle( BitWidthType interruptId );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn interrupt_trigger(BitWidthType interruptId)
  *
  * @brief Interrupt trigger function. This function cannot be called
  * from the unprivileged context directly. This function is called from the
  * ISR to signalize handler thread. DEMO
  *
  * @param[in]  interruptId is identifier of interrupt to handle
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void
interrupt_trigger( BitWidthType interruptId );
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/* General_interrupt_h
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
  * @addtogroup Getters_interrupt_h Getters
  * @ingroup Apis_interrupt_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn interrupt_getInterruptId(CosmOS_InterruptConfigurationType * interrupt)
  *
  * @brief Get interrupt id.
  *
  * @param[in]  interrupt configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
interrupt_getInterruptId( CosmOS_InterruptConfigurationType * interrupt )
{
    return ( interrupt->interruptId );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn interrupt_getInterruptHandlerThread(CosmOS_InterruptConfigurationType
  * * interrupt)
  *
  * @brief Get interrupt handlerThread.
  *
  * @param[in]  interrupt configuration pointer
  *
  * @return CosmOS_ThreadConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_ThreadConfigurationType *
interrupt_getInterruptHandlerThread(
    CosmOS_InterruptConfigurationType * interrupt )
{
    return (CosmOS_ThreadConfigurationType *)( interrupt->handlerThread );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn interrupt_getInterruptNumberOfRequests(CosmOS_InterruptConfigurationType
  * * interrupt)
  *
  * @brief Get interrupt numberOfRequests.
  *
  * @param[in]  interrupt configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
interrupt_getInterruptNumberOfRequests(
    CosmOS_InterruptConfigurationType * interrupt )
{
    return ( interrupt->var->numberOfRequests );
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/* Getters_interrupt_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_interrupt_h Setters
  * @ingroup Apis_interrupt_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn interrupt_setInterruptNumberOfRequests(CosmOS_InterruptConfigurationType
  * * interrupt)
  *
  * @brief Set interrupt numberOfRequests.
  *
  * @param[in]  interrupt configuration pointer
  * @param[in]  numberOfRequestsParam number of requests for current interrupt
  * configuration
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
interrupt_setInterruptNumberOfRequests(
    CosmOS_InterruptConfigurationType * interrupt,
    BitWidthType numberOfRequestsParam )
{
    interrupt->var->numberOfRequests = numberOfRequestsParam;
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/* Setters_interrupt_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_interrupt_h General
  * @ingroup Apis_interrupt_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn interrupt_enableInterrupts(BitWidthType entityId)
  *
  * @brief Enable interrupts for the current core. This function is provided
  * as a CosmOS API system call mapped with the routes and cannot be called from
  * the unprivileged context directly. DEMO
  *
  * @param[in]  entityId is used during the system call dispatching
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
interrupt_enableInterrupts( BitWidthType entityId )
{
    CILinterrupt_enableInterrupts();

    __SUPRESS_UNUSED_VAR( entityId );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn interrupt_enableInterrupt( BitWidthType entityId, BitWidthType ISR )
  *
  * @brief Enable specific interrupt for the current core. This function is
  * provided as a CosmOS API system call mapped with the routes and cannot be
  * called from the unprivileged context directly. DEMO
  *
  * @param[in]  entityId is used during the system call dispatching
  * @param[in]  ISR id of the interrupt
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
interrupt_enableInterrupt( BitWidthType entityId, BitWidthType ISR )
{
    CILinterrupt_enableInterrupt( ISR );

    __SUPRESS_UNUSED_VAR( entityId );
    __SUPRESS_UNUSED_VAR( ISR );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn interrupt_disableInterrupts(BitWidthType entityId)
  *
  * @brief Disable interrupts for the current core. This function is provided
  * as a CosmOS API system call mapped with the routes and cannot be called from
  * the unprivileged context directly. DEMO
  *
  * @param[in]  entityId is used during the system call dispatching
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
interrupt_disableInterrupts( BitWidthType entityId )
{
    CILinterrupt_disableInterrupts();

    __SUPRESS_UNUSED_VAR( entityId );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn interrupt_disableInterrupt( BitWidthType entityId, BitWidthType ISR )
  *
  * @brief Disable specific interrupt for the current core. This function is
  * provided as a CosmOS API system call mapped with the routes and cannot be
  * called from the unprivileged context directly. DEMO
  *
  * @param[in]  entityId is used during the system call dispatching
  * @param[in]  ISR id of the interrupt
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
interrupt_disableInterrupt( BitWidthType entityId, BitWidthType ISR )
{
    CILinterrupt_disableInterrupt( ISR );

    __SUPRESS_UNUSED_VAR( entityId );
    __SUPRESS_UNUSED_VAR( ISR );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn interrupt_contextSwitchRoutineTrigger(BitWidthType entityId)
  *
  * @brief Context switch routine trigger. This function is provided
  * as a CosmOS API system call mapped with the routes and cannot be called from
  * the unprivileged context directly. DEMO
  *
  * @param[in]  entityId is used during the system call dispatching
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
interrupt_contextSwitchRoutineTrigger( BitWidthType entityId )
{
    CILinterrupt_contextSwitchRoutineTrigger();

    __SUPRESS_UNUSED_VAR( entityId );
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/* General_interrupt_h
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
