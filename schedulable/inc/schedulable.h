/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file schedulable.h
*********************************************************************************
<!--                   schedulable Module Group Definition                    -->
*********************************************************************************
** @defgroup schedulable_module schedulable
** @brief schedulable Module
** @details lorem
*********************************************************************************
<!--                     schedulable Unit Group Definition                    -->
*********************************************************************************
** @defgroup schedulable_unit schedulable Unit
** @ingroup schedulable_module
** @brief schedulable Unit
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
<!--                schedulable Unit Global Group Definition                  -->
*********************************************************************************
** @defgroup Global_schedulable Global
** @ingroup schedulable_unit
** @brief schedulable globals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __SCHEDULABLE_H__
#define __SCHEDULABLE_H__
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
  * @defgroup Macros_schedulable_h Macros
  * @ingroup Global_schedulable
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_schedulable_h
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
  * @defgroup Variables_schedulable_h Variables
  * @ingroup Global_schedulable
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_schedulable_h
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
  * @defgroup Apis_schedulable_h API's
  * @ingroup Global_schedulable
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_schedulable_h Getters
  * @ingroup Apis_schedulable_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_schedulable_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_schedulable_h Setters
  * @ingroup Apis_schedulable_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn schedulable_setExecutionStateToFinished(BitWidthType entityId)
  *
  * @brief Set schedulable execution state to finished. This function cannot
  * be called from the unprivileged context directly. DEMO
  *
  * @param[in]  entityId is used during the system call dispatching
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void
schedulable_setExecutionStateToFinished( BitWidthType entityId );
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_schedulable_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_schedulable_h General
  * @ingroup Apis_schedulable_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_schedulable_h
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
  * @addtogroup Getters_schedulable_h Getters
  * @ingroup Apis_schedulable_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn schedulable_getStack(CosmOS_SchedulableConfigurationType * schedulable)
  *
  * @brief Get schedulable stack pointer.
  *
  * @param[in] schedulable configuration pointer
  *
  * @return CosmOS_StackConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_StackConfigurationType *
schedulable_getStack( CosmOS_SchedulableConfigurationType * schedulable )
{
    return (CosmOS_StackConfigurationType *)( schedulable->stack );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn schedulable_getInstanceType(
  * CosmOS_SchedulableConfigurationType * schedulable)
  *
  * @brief Get schedulable instanceType.
  *
  * @param[in] schedulable configuration pointer
  *
  * @return CosmOS_SchedulableInstanceType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_SchedulableInstanceType
schedulable_getInstanceType( CosmOS_SchedulableConfigurationType * schedulable )
{
    return ( schedulable->instanceType );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn schedulable_getHandler(CosmOS_SchedulableConfigurationType * schedulable)
  *
  * @brief Get schedulable handler.
  *
  * @param[in] schedulable configuration pointer
  *
  * @return CosmOS_GenericVoidType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_GenericVoidType
schedulable_getHandler( CosmOS_SchedulableConfigurationType * schedulable )
{
    return ( schedulable->handler );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn schedulable_getFp(CosmOS_SchedulableConfigurationType * schedulable)
  *
  * @brief Get schedulable fb.
  *
  * @param[in] schedulable configuration pointer
  *
  * @return CosmOS_BooleanType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BooleanType
schedulable_getFp( CosmOS_SchedulableConfigurationType * schedulable )
{
    return ( schedulable->fp );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn schedulable_getId(CosmOS_SchedulableConfigurationType * schedulable)
  *
  * @brief Get schedulable id.
  *
  * @param[in] schedulable configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
schedulable_getId( CosmOS_SchedulableConfigurationType * schedulable )
{
    return ( schedulable->id );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn schedulable_getInstanceId(
  * CosmOS_SchedulableConfigurationType * schedulable)
  *
  * @brief Get schedulable instanceId.
  *
  * @param[in] schedulable configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
schedulable_getInstanceId( CosmOS_SchedulableConfigurationType * schedulable )
{
    return ( schedulable->instanceId );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn schedulable_getProgramId(
  * CosmOS_SchedulableConfigurationType * schedulable)
  *
  * @brief Get schedulable programId.
  *
  * @param[in] schedulable configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
schedulable_getProgramId( CosmOS_SchedulableConfigurationType * schedulable )
{
    return ( schedulable->programId );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn schedulable_getCoreId(CosmOS_SchedulableConfigurationType * schedulable)
  *
  * @brief Get schedulable coreId.
  *
  * @param[in] schedulable configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
schedulable_getCoreId( CosmOS_SchedulableConfigurationType * schedulable )
{
    return ( schedulable->coreId );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn schedulable_getAlarmId(CosmOS_SchedulableConfigurationType * schedulable)
  *
  * @brief Get schedulable alarmId.
  *
  * @param[in] schedulable configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
schedulable_getAlarmId( CosmOS_SchedulableConfigurationType * schedulable )
{
    return ( schedulable->alarmId );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn schedulable_getPeripheralAccessLowAddress(
  * CosmOS_SchedulableConfigurationType * schedulable)
  *
  * @brief Get schedulable peripheralAccessLowAddress.
  *
  * @param[in] schedulable configuration pointer
  *
  * @return AddressType
********************************************************************************/
__STATIC_FORCEINLINE AddressType
schedulable_getPeripheralAccessLowAddress(
    CosmOS_SchedulableConfigurationType * schedulable )
{
    return ( schedulable->peripheralAccessLowAddress );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn schedulable_getPeripheralAccessHighAddress(
  * CosmOS_SchedulableConfigurationType * schedulable)
  *
  * @brief Get schedulable peripheralAccessHighAddress.
  *
  * @param[in] schedulable configuration pointer
  *
  * @return AddressType
********************************************************************************/
__STATIC_FORCEINLINE AddressType
schedulable_getPeripheralAccessHighAddress(
    CosmOS_SchedulableConfigurationType * schedulable )
{
    return ( schedulable->peripheralAccessHighAddress );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn schedulable_getPeripheralAccessSize(
  * CosmOS_SchedulableConfigurationType * schedulable)
  *
  * @brief Get schedulable peripheralAccessSize.
  *
  * @param[in] schedulable configuration pointer
  *
  * @return AddressType
********************************************************************************/
__STATIC_FORCEINLINE AddressType
schedulable_getPeripheralAccessSize(
    CosmOS_SchedulableConfigurationType * schedulable )
{
    return ( schedulable->peripheralAccessSize );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn schedulable_getState(CosmOS_SchedulableConfigurationType * schedulable)
  *
  * @brief Get schedulable state.
  *
  * @param[in] schedulable configuration pointer
  *
  * @return CosmOS_SchedulableStateType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_SchedulableStateType
schedulable_getState( CosmOS_SchedulableConfigurationType * schedulable )
{
    return ( schedulable->var->state );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn schedulable_getStackPointer(
  * CosmOS_SchedulableConfigurationType * schedulable)
  *
  * @brief Get schedulable stackPointer.
  *
  * @param[in] schedulable configuration pointer
  *
  * @return StackPointerType
********************************************************************************/
__STATIC_FORCEINLINE StackPointerType
schedulable_getStackPointer( CosmOS_SchedulableConfigurationType * schedulable )
{
    return ( schedulable->var->stackPointer );
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_schedulable_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_schedulable_h Setters
  * @ingroup Apis_schedulable_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn schedulable_setState(CosmOS_SchedulableConfigurationType * schedulable,
  * CosmOS_SchedulableStateType stateParam)
  *
  * @brief Set schedulable state. This function cannot
  * be called from the unprivileged context directly.
  *
  * @param[out] schedulable configuration pointer
  * @param[in]  stateParam state of the schedulable configuration to be set
  *
  * @return CosmOS_SchedulableStateType
********************************************************************************/
__STATIC_FORCEINLINE void
schedulable_setState(
    CosmOS_SchedulableConfigurationType * schedulable,
    CosmOS_SchedulableStateType stateParam )
{
    schedulable->var->state = stateParam;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn schedulable_setStackPointer(
  * CosmOS_SchedulableConfigurationType * schedulable,
  * StackPointerType stackPointerParam)
  *
  * @brief Set schedulable stackPointer. This function cannot
  * be called from the unprivileged context directly.
  *
  * @param[out] schedulable configuration pointer
  * @param[in]  stackPointerParam stack pointer of the schedulable configuration
  * to be set
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
schedulable_setStackPointer(
    CosmOS_SchedulableConfigurationType * schedulable,
    StackPointerType stackPointerParam )
{
    schedulable->var->stackPointer = stackPointerParam;
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_schedulable_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_schedulable_h General
  * @ingroup Apis_schedulable_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_schedulable_h
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
