/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file mutex.h
*********************************************************************************
<!--                       mutex Module Group Definition                      -->
*********************************************************************************
** @defgroup mutex_module mutex
** @brief mutex Module
** @details lorem
*********************************************************************************
<!--                        mutex Unit Group Definition                       -->
*********************************************************************************
** @defgroup mutex_unit mutex Unit
** @ingroup mutex_module
** @brief mutex Unit
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
<!--                   mutex Unit Global Group Definition                     -->
*********************************************************************************
** @defgroup Global_mutex Global
** @ingroup mutex_unit
** @brief mutex globals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __MUTEX_H__
#define __MUTEX_H__
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
  * @defgroup Macros_mutex_h Macros
  * @ingroup Global_mutex
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_mutex_h
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
  * @defgroup Variables_mutex_h Variables
  * @ingroup Global_mutex
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_mutex_h
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
  * @defgroup Apis_mutex_h API's
  * @ingroup Global_mutex
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_mutex_h Getters
  * @ingroup Apis_mutex_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn mutex_getMutexInternal(BitWidthType entityId,
  * CosmOS_MutexVariableType * mutexVar)
  *
  * @brief Get mutex internal. This function cannot be called
  * from the unprivileged context directly. DEMO
  *
  * @param[in]  entityId is used during the system call dispatching
  * @param[in]  mutexVar pointer to the mutex variable
  *
  * @return CosmOS_MutexStateType
********************************************************************************/
__OS_FUNC_SECTION CosmOS_MutexStateType
mutex_getMutexInternal(
    BitWidthType entityId,
    CosmOS_MutexVariableType * mutexVar );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn mutex_getMutex(CosmOS_MutexVariableType * mutexVar)
  *
  * @brief Get mutex. DEMO
  *
  * @param[in]  mutexVar pointer to the mutex variable
  *
  * @return CosmOS_MutexStateType
********************************************************************************/
__OS_FUNC_SECTION CosmOS_MutexStateType
mutex_getMutex( CosmOS_MutexVariableType * mutexVar );
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_mutex_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_mutex_h Setters
  * @ingroup Apis_mutex_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_mutex_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_mutex_h General
  * @ingroup Apis_mutex_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn mutex_tryMutexInternal(BitWidthType entityId,
  * CosmOS_MutexVariableType * mutexVar)
  *
  * @brief Try to get mutex internal. This function cannot be called
  * from the unprivileged context directly. DEMO
  *
  * @param[in]  entityId is used during the system call dispatching
  * @param[in]  mutexVar pointer to the mutex variable
  *
  * @return CosmOS_MutexStateType
********************************************************************************/
__OS_FUNC_SECTION CosmOS_MutexStateType
mutex_tryMutexInternal(
    BitWidthType entityId,
    CosmOS_MutexVariableType * mutexVar );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn mutex_releaseMutexInternal(BitWidthType entityId,
  * CosmOS_MutexVariableType * mutexVar)
  *
  * @brief Release mutex internal. This function cannot be called
  * from the unprivileged context directly. DEMO
  *
  * @param[in]  entityId is used during the system call dispatching
  * @param[in]  mutexVar pointer to the mutex variable
  *
  * @return CosmOS_MutexStateType
********************************************************************************/
__OS_FUNC_SECTION CosmOS_MutexStateType
mutex_releaseMutexInternal(
    BitWidthType entityId,
    CosmOS_MutexVariableType * mutexVar );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn mutex_tryMutex(CosmOS_MutexVariableType * mutexVar)
  *
  * @brief Try to get mutex. DEMO
  *
  * @param[in]  mutexVar pointer to the mutex variable
  *
  * @return CosmOS_MutexStateType
********************************************************************************/
__OS_FUNC_SECTION CosmOS_MutexStateType
mutex_tryMutex( CosmOS_MutexVariableType * mutexVar );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn mutex_releaseMutex(CosmOS_MutexVariableType * mutexVar)
  *
  * @brief Release mutex. DEMO
  *
  * @param[in]  mutexVar pointer to the mutex variable
  *
  * @return CosmOS_MutexStateType
********************************************************************************/
__OS_FUNC_SECTION CosmOS_MutexStateType
mutex_releaseMutex( CosmOS_MutexVariableType * mutexVar );
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_mutex_h
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
  * @addtogroup Getters_mutex_h Getters
  * @ingroup Apis_mutex_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_mutex_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn mutex_getMutexValue(CosmOS_MutexVariableType * mutexVar)
  *
  * @brief Get mutex value.
  *
  * @param[in]  mutexVar pointer to the mutex variable
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
mutex_getMutexValue( CosmOS_MutexVariableType * mutexVar )
{
    return ( mutexVar->mutex );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn mutex_getMutexSchedulableOwner(CosmOS_MutexVariableType * mutexVar)
  *
  * @brief Get mutex schedulableOwner.
  *
  * @param[in]  mutexVar pointer to the mutex variable
  *
  * @return CosmOS_SchedulableVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_SchedulableVariableType *
mutex_getMutexSchedulableOwner( CosmOS_MutexVariableType * mutexVar )
{
    return (CosmOS_SchedulableVariableType *)( mutexVar->schedulableOwner );
}
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_mutex_h Setters
  * @ingroup Apis_mutex_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn mutex_setMutexValue(CosmOS_MutexVariableType * mutexVar,
  * BitWidthType mutexParam)
  *
  * @brief Set mutex value.
  *
  * @param[out]  mutexVar pointer to the mutex variable
  * @param[in]  CosmOS_MutexStateType mutexParam
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
mutex_setMutexValue(
    CosmOS_MutexVariableType * mutexVar,
    BitWidthType mutexParam )
{
    mutexVar->mutex = mutexParam;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn mutex_setMutexSchedulableOwner(CosmOS_MutexVariableType * mutex,
  * BitWidthType mutexParam)
  *
  * @brief Set mutex schedulableOwner.
  *
  * @param[out]  mutexVar pointer to the mutex variable
  * @param[in]  CosmOS_SchedulableVariableType * schedulableOwnerParam
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
mutex_setMutexSchedulableOwner(
    CosmOS_MutexVariableType * mutexVar,
    CosmOS_SchedulableVariableType * schedulableOwnerParam )
{
    mutexVar->schedulableOwner = schedulableOwnerParam;
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_mutex_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_mutex_h General
  * @ingroup Apis_mutex_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn mutex_willCauseDeadlock(CosmOS_CoreVariableType * coreVar,
  * CosmOS_MutexVariableType * mutexVar)
  *
  * @brief Check if the mutex will ends up in deadlock. DEMO
  *
  * @param[in]  coreVar pointer
  * @param[in]  mutexVar pointer to the mutex variable
  *
  * @return CosmOS_BufferStateType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BooleanType
mutex_willCauseDeadlock(
    CosmOS_CoreVariableType * coreVar,
    CosmOS_MutexVariableType * mutexVar )
{
    return ( (mutexVar->mutex IS_EQUAL_TO MUTEX_STATE_ENUM__OCCUPIED)AND(
               coreVar->schedulableInExecution IS_EQUAL_TO
                   mutexVar->schedulableOwner ) )
               ? True
               : False;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn mutex_ownsSchedulableMutex(CosmOS_CoreVariableType * coreVar,
  * CosmOS_MutexVariableType * mutexVar)
  *
  * @brief Check if the schedulable in execution owns the current mutex.
  *
  * @param[in]  coreVar pointer
  * @param[in]  mutexVar pointer to the mutex variable
  *
  * @return CosmOS_BufferStateType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BooleanType
mutex_ownsSchedulableMutex(
    CosmOS_CoreVariableType * coreVar,
    CosmOS_MutexVariableType * mutexVar )
{
    return ( coreVar->schedulableInExecution IS_EQUAL_TO
                 mutexVar->schedulableOwner )
               ? True
               : False;
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_mutex_h
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
