/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file semaphore.h
*********************************************************************************
<!--                    semaphore Module Group Definition                     -->
*********************************************************************************
** @defgroup semaphore_module semaphore
** @brief semaphore Module
** @details lorem
*********************************************************************************
<!--                     semaphore Unit Group Definition                      -->
*********************************************************************************
** @defgroup semaphore_unit semaphore Unit
** @ingroup semaphore_module
** @brief semaphore Unit
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
<!--                  semaphore Unit Global Group Definition                  -->
*********************************************************************************
** @defgroup Global_semaphore Global
** @ingroup semaphore_unit
** @brief semaphore globals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __SEMAPHORE_H__
#define __SEMAPHORE_H__
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
  * @defgroup Macros_semaphore_h Macros
  * @ingroup Global_semaphore
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_semaphore_h
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
  * @defgroup Variables_semaphore_h Variables
  * @ingroup Global_semaphore
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_semaphore_h
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
  * @defgroup Apis_semaphore_h API's
  * @ingroup Global_semaphore
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_semaphore_h Getters
  * @ingroup Apis_semaphore_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn semaphore_getSemaphore(BitWidthType semaphoreId)
  *
  * @brief Get semaphore. DEMO
  *
  * @param[in]  semaphoreId semaphore identifier
  *
  * @return CosmOS_SemaphoreStateType
********************************************************************************/
__OS_FUNC_SECTION CosmOS_SemaphoreStateType
semaphore_getSemaphore( BitWidthType semaphoreId );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn semaphore_getSemaphoreInternal(BitWidthType id,
  * CosmOS_SemaphoreVariableType * semaphoreVar,
  * BitWidthType semaphoreId );
  *
  * @brief Get to get semaphore internal. This function cannot be called
  * from the unprivileged context directly. DEMO
  *
  * @param[in]  id is used during the system call dispatching
  * @param[in]  semaphoreVar variable structure pointer
  * @param[in]  semaphoreId semaphore identifier
  *
  * @return CosmOS_SemaphoreStateType
********************************************************************************/
__OS_FUNC_SECTION CosmOS_SemaphoreStateType
semaphore_getSemaphoreInternal(
    BitWidthType id,
    CosmOS_SemaphoreVariableType * semaphoreVar,
    BitWidthType semaphoreId );
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_semaphore_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_semaphore_h Setters
  * @ingroup Apis_semaphore_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_semaphore_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_semaphore_h General
  * @ingroup Apis_semaphore_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn semaphore_trySemaphoreInternal(BitWidthType id,
  * CosmOS_SemaphoreVariableType * semaphoreVar,
  * BitWidthType semaphoreId );
  *
  * @brief Try to get semaphore internal. This function cannot be called
  * from the unprivileged context directly. DEMO
  *
  * @param[in]  id is used during the system call dispatching
  * @param[in]  semaphoreVar variable structure pointer
  * @param[in]  semaphoreId semaphore identifier
  *
  * @return CosmOS_SemaphoreStateType
********************************************************************************/
__OS_FUNC_SECTION CosmOS_SemaphoreStateType
semaphore_trySemaphoreInternal(
    BitWidthType id,
    CosmOS_SemaphoreVariableType * semaphoreVar,
    BitWidthType semaphoreId );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn semaphore_releaseSemaphoreInternal(BitWidthType id,
  * CosmOS_SemaphoreVariableType * semaphoreVar,
  * BitWidthType semaphoreId );
  *
  * @brief Release to get semaphore internal. This function cannot be called
  * from the unprivileged context directly. DEMO
  *
  * @param[in]  id is used during the system call dispatching
  * @param[in]  semaphoreVar variable structure pointer
  * @param[in]  semaphoreId semaphore identifier
  *
  * @return CosmOS_SemaphoreStateType
********************************************************************************/
__OS_FUNC_SECTION CosmOS_SemaphoreStateType
semaphore_releaseSemaphoreInternal(
    BitWidthType id,
    CosmOS_SemaphoreVariableType * semaphoreVar,
    BitWidthType semaphoreId );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn semaphore_trySemaphore(BitWidthType semaphoreId)
  *
  * @brief Try to get semaphore. DEMO
  *
  * @param[in]  semaphoreId semaphore identifier
  *
  * @return CosmOS_SemaphoreStateType
********************************************************************************/
__OS_FUNC_SECTION CosmOS_SemaphoreStateType
semaphore_trySemaphore( BitWidthType semaphoreId );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn semaphore_releaseSemaphore(BitWidthType semaphoreId)
  *
  * @brief Release semaphore. DEMO
  *
  * @param[in]  semaphoreId semaphore identifier
  *
  * @return CosmOS_SemaphoreStateType
********************************************************************************/
__OS_FUNC_SECTION CosmOS_SemaphoreStateType
semaphore_releaseSemaphore( BitWidthType semaphoreId );
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_semaphore_h
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
  * @addtogroup Getters_semaphore_h Getters
  * @ingroup Apis_semaphore_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_semaphore_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn semaphore_getSemaphoreValue(CosmOS_SemaphoreVariableType * semaphoreVar)
  *
  * @brief Get semaphore value.
  *
  * @param[in]  semaphoreVar pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
semaphore_getSemaphoreValue( CosmOS_SemaphoreVariableType * semaphoreVar )
{
    return ( semaphoreVar->semaphore );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn semaphore_getSemaphoreSchedulableOwner(
  * CosmOS_SemaphoreVariableType * semaphoreVar)
  *
  * @brief Get semaphore schedulableOwner.
  *
  * @param[in]  semaphoreVar pointer
  *
  * @return CosmOS_SchedulableConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_SchedulableConfigurationType *
semaphore_getSemaphoreSchedulableOwner(
    CosmOS_SemaphoreVariableType * semaphoreVar )
{
    return (
        CosmOS_SchedulableConfigurationType *)( semaphoreVar->schedulableOwner );
}
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_semaphore_h Setters
  * @ingroup Apis_semaphore_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn semaphore_setSemaphoreValue(CosmOS_SemaphoreVariableType * semaphoreVar,
  * BitWidthType semaphoreParam)
  *
  * @brief Set semaphore value. This function cannot
  * be called from the unprivileged context directly.
  *
  * @param[out]  semaphoreVar pointer
  * @param[in]  semaphoreParam value to be set to the semaphore variable
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
semaphore_setSemaphoreValue(
    CosmOS_SemaphoreVariableType * semaphoreVar,
    BitWidthType semaphoreParam )
{
    semaphoreVar->semaphore = semaphoreParam;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn semaphore_setSemaphoreSchedulableOwner(
  * CosmOS_SemaphoreVariableType * semaphore,
  * CosmOS_SchedulableConfigurationType * schedulableOwnerParam)
  *
  * @brief Set semaphore schedulableOwner. This function cannot
  * be called from the unprivileged context directly.
  *
  * @param[out]  semaphoreVar pointer
  * @param[in]  schedulableOwnerParam pointer to the schedulable that owns
  * current semaphore
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
semaphore_setSemaphoreSchedulableOwner(
    CosmOS_SemaphoreVariableType * semaphoreVar,
    CosmOS_SchedulableConfigurationType * schedulableOwnerParam )
{
    semaphoreVar->schedulableOwner = schedulableOwnerParam;
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_semaphore_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_semaphore_h General
  * @ingroup Apis_semaphore_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn semaphore_willCauseDeadlock(CosmOS_CoreConfigurationType * core,
  * CosmOS_SemaphoreVariableType * semaphoreVar)
  *
  * @brief Check if the semaphore will ends up in deadlock. DEMO
  *
  * @param[in]  core configuration pointer
  * @param[in]  semaphoreVar pointer
  *
  * @return CosmOS_BufferStateType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BooleanType
semaphore_willCauseDeadlock(
    CosmOS_CoreConfigurationType * core,
    CosmOS_SemaphoreVariableType * semaphoreVar )
{
    return ( (semaphoreVar->semaphore IS_EQUAL_TO SEMAPHORE_STATE_ENUM__OCCUPIED)
                 AND( core->var->schedulableInExecution IS_EQUAL_TO
                          semaphoreVar->schedulableOwner ) )
               ? True
               : False;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn semaphore_ownsSchedulableSemaphore(CosmOS_CoreConfigurationType * core,
  * CosmOS_SemaphoreVariableType * semaphoreVar)
  *
  * @brief Check if the schedulable in execution owns the current semaphore.
  *
  * @param[in]  core configuration pointer
  * @param[in]  semaphoreVar pointer
  *
  * @return CosmOS_BufferStateType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BooleanType
semaphore_ownsSchedulableSemaphore(
    CosmOS_CoreConfigurationType * core,
    CosmOS_SemaphoreVariableType * semaphoreVar )
{
    return ( core->var->schedulableInExecution IS_EQUAL_TO
                 semaphoreVar->schedulableOwner )
               ? True
               : False;
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_semaphore_h
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
