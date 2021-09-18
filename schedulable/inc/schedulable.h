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
#include "sysDefs.h"
#include "cosmosTypesStd.h"
#include "memoryMapping.h"
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
  * @}
  * Macros_schedulable_h
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
  * @}
  * Variables_schedulable_h
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
  * @}
  * Getters_schedulable_h
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
  * *************************************************************************//**
  * @fn schedulable_setExecutionStateToFinished(BitWidthType entityId)
  *
  * @brief Set schedulable execution state to finished DEMO CODE.
  *
  * @param[in]  BitWidthType entityId
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void schedulable_setExecutionStateToFinished(BitWidthType entityId);
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Setters_schedulable_h
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
  * @}
  * General_schedulable_h
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
  * *************************************************************************//**
  * @fn schedulable_getStack(CosmOS_SchedulableVariableType * schedulable)
  *
  * @brief Get schedulable stack pointer.
  *
  * @param[in]  CosmOS_SchedulableVariableType * schedulable
  *
  * @return CosmOS_StackConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_StackConfigurationType * schedulable_getStack(CosmOS_SchedulableVariableType * schedulable)
{
    return (CosmOS_StackConfigurationType *)(schedulable->cfg->stack);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn schedulable_getInstanceType(CosmOS_SchedulableVariableType * schedulable)
  *
  * @brief Get schedulable instanceType.
  *
  * @param[in]  CosmOS_SchedulableVariableType * schedulable
  *
  * @return CosmOS_SchedulableInstanceType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_SchedulableInstanceType schedulable_getInstanceType(CosmOS_SchedulableVariableType * schedulable)
{
    return (schedulable->cfg->instanceType);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn schedulable_getHandler(CosmOS_SchedulableVariableType * schedulable)
  *
  * @brief Get schedulable handler.
  *
  * @param[in]  CosmOS_SchedulableVariableType * schedulable
  *
  * @return CosmOS_GenericVoidType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_GenericVoidType schedulable_getHandler(CosmOS_SchedulableVariableType * schedulable)
{
    return (schedulable->cfg->handler);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn schedulable_getFp(CosmOS_SchedulableVariableType * schedulable)
  *
  * @brief Get schedulable fb.
  *
  * @param[in]  CosmOS_SchedulableVariableType * schedulable
  *
  * @return CosmOS_BooleanType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BooleanType schedulable_getFp(CosmOS_SchedulableVariableType * schedulable)
{
    return (schedulable->cfg->fp);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn schedulable_getId(CosmOS_SchedulableVariableType * schedulable)
  *
  * @brief Get schedulable id.
  *
  * @param[in]  CosmOS_SchedulableVariableType * schedulable
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType schedulable_getId(CosmOS_SchedulableVariableType * schedulable)
{
    return (schedulable->cfg->id);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn schedulable_getInstanceId(CosmOS_SchedulableVariableType * schedulable)
  *
  * @brief Get schedulable instanceId.
  *
  * @param[in]  CosmOS_SchedulableVariableType * schedulable
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType schedulable_getInstanceId(CosmOS_SchedulableVariableType * schedulable)
{
    return (schedulable->cfg->instanceId);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn schedulable_getProgramId(CosmOS_SchedulableVariableType * schedulable)
  *
  * @brief Get schedulable programId.
  *
  * @param[in]  CosmOS_SchedulableVariableType * schedulable
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType schedulable_getProgramId(CosmOS_SchedulableVariableType * schedulable)
{
    return (schedulable->cfg->programId);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn schedulable_getCoreId(CosmOS_SchedulableVariableType * schedulable)
  *
  * @brief Get schedulable coreId.
  *
  * @param[in]  CosmOS_SchedulableVariableType * schedulable
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType schedulable_getCoreId(CosmOS_SchedulableVariableType * schedulable)
{
    return (schedulable->cfg->coreId);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn schedulable_getAlarmId(CosmOS_SchedulableVariableType * schedulable)
  *
  * @brief Get schedulable alarmId.
  *
  * @param[in]  CosmOS_SchedulableVariableType * schedulable
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType schedulable_getAlarmId(CosmOS_SchedulableVariableType * schedulable)
{
    return (schedulable->cfg->alarmId);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn schedulable_getState(CosmOS_SchedulableVariableType * schedulable)
  *
  * @brief Get schedulable state.
  *
  * @param[in]  CosmOS_SchedulableVariableType * schedulable
  *
  * @return CosmOS_SchedulableStateType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_SchedulableStateType schedulable_getState(CosmOS_SchedulableVariableType * schedulable)
{
    return (schedulable->state);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn schedulable_getStackPointer(CosmOS_SchedulableVariableType * schedulable)
  *
  * @brief Get schedulable stackPointer.
  *
  * @param[in]  CosmOS_SchedulableVariableType * schedulable
  *
  * @return StackPointerType
********************************************************************************/
__STATIC_FORCEINLINE StackPointerType schedulable_getStackPointer(CosmOS_SchedulableVariableType * schedulable)
{
    return (schedulable->stackPointer);
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Getters_schedulable_h
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
  * *************************************************************************//**
  * @fn schedulable_setState(CosmOS_SchedulableVariableType * schedulable,CosmOS_SchedulableStateType stateParam)
  *
  * @brief Set schedulable state.
  *
  * @param[in]  CosmOS_SchedulableVariableType * schedulable
  * @param[in]  CosmOS_SchedulableStateType stateParam
  *
  * @return CosmOS_SchedulableStateType
********************************************************************************/
__STATIC_FORCEINLINE void schedulable_setState(CosmOS_SchedulableVariableType * schedulable, CosmOS_SchedulableStateType stateParam)
{
    schedulable->state = stateParam;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn schedulable_setStackPointer(CosmOS_SchedulableVariableType * schedulable, StackPointerType stackPointerParam)
  *
  * @brief Set schedulable stackPointer.
  *
  * @param[in]  CosmOS_SchedulableVariableType * schedulable
  * @param[in]  StackPointerType stackPointerParam
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void schedulable_setStackPointer(CosmOS_SchedulableVariableType * schedulable, StackPointerType stackPointerParam)
{
    schedulable->stackPointer = stackPointerParam;
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Setters_schedulable_h
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
  * @}
  * General_schedulable_h
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
