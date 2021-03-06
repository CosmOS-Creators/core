/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file thread.h
*********************************************************************************
<!--                      thread Module Group Definition                      -->
*********************************************************************************
** @defgroup thread_module thread
** @brief thread Module
** @details lorem
*********************************************************************************
<!--                       thread Unit Group Definition                       -->
*********************************************************************************
** @defgroup thread_unit thread Unit
** @ingroup thread_module
** @brief thread Unit
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
<!--                    thread Unit Global Group Definition                   -->
*********************************************************************************
** @defgroup Global_thread Global
** @ingroup thread_unit
** @brief thread globals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __THREAD_H__
#define __THREAD_H__
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
  * @defgroup Macros_thread_h Macros
  * @ingroup Global_thread
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_thread_h
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
  * @defgroup Variables_thread_h Variables
  * @ingroup Global_thread
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_thread_h
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
  * @defgroup Apis_thread_h API's
  * @ingroup Global_thread
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_thread_h Getters
  * @ingroup Apis_thread_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_thread_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_thread_h Setters
  * @ingroup Apis_thread_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_thread_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_thread_h General
  * @ingroup Apis_thread_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn thread_sleepMsInternal(BitWidthType entityId,
  * CosmOS_CoreConfigurationType * core,
  * BitWidthType tickCount)
  *
  * @brief Set thread to sleep internal for x milliseconds. This function cannot
  * be called from the unprivileged context directly. DEMO
  *
  * @param[in]  entityId is used during the system call dispatching
  * @param[in]  core configuration pointer
  * @param[in]  tickCount number of ticks to put thread into sleep for
  *
  * @return CosmOS_SleepStateType
********************************************************************************/
__OS_FUNC_SECTION CosmOS_SleepStateType
thread_sleepMsInternal(
    BitWidthType entityId,
    CosmOS_CoreConfigurationType * core,
    BitWidthType tickCount );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn thread_sleepMs(BitWidthType delayMs)
  *
  * @brief Set thread to sleep for x milliseconds. DEMO
  *
  * @param[in]  delayMs number of milliseconds to put thread into sleep for
  *
  * @return CosmOS_SleepStateType
********************************************************************************/
__OS_FUNC_SECTION CosmOS_SleepStateType
thread_sleepMs( BitWidthType delayMs );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn thread_sleep(BitWidthType delay)
  *
  * @brief Set thread to sleep for x seconds.
  *
  * @param[in]  delay number of seconds to put thread into sleep for
  *
  * @return CosmOS_SleepStateType
********************************************************************************/
#define thread_sleep( delay ) thread_sleepMs( delay * 1000 )
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_thread_h
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
  * @addtogroup Getters_thread_h Getters
  * @ingroup Apis_thread_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn thread_getThreadPriority(CosmOS_ThreadConfigurationType *thread)
  *
  * @brief Get thread priority.
  *
  * @param[in] thread configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
thread_getThreadPriority( CosmOS_ThreadConfigurationType * thread )
{
    return ( thread->priority );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn thread_getThreadSchedulable(CosmOS_ThreadConfigurationType *thread)
  *
  * @brief Get thread schedulable.
  *
  * @param[in] thread configuration pointer
  *
  * @return CosmOS_SchedulableConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_SchedulableConfigurationType *
thread_getThreadSchedulable( CosmOS_ThreadConfigurationType * thread )
{
    return (CosmOS_SchedulableConfigurationType *)( thread->schedulable );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn thread_getThreadBlockingMutexVar(CosmOS_ThreadConfigurationType *thread)
  *
  * @brief Get thread blockingMutexVar.
  *
  * @param[in] thread configuration pointer
  *
  * @return CosmOS_MutexVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_MutexVariableType *
thread_getThreadBlockingMutexVar( CosmOS_ThreadConfigurationType * thread )
{
    return (CosmOS_MutexVariableType *)( thread->var->blockingMutexVar );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn thread_getThreadBlockingSemaphoreVar(CosmOS_ThreadConfigurationType
  * *thread)
  *
  * @brief Get thread blockingSemaphoreVar.
  *
  * @param[in] thread configuration pointer
  *
  * @return CosmOS_SemaphoreVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_SemaphoreVariableType *
thread_getThreadBlockingSemaphoreVar( CosmOS_ThreadConfigurationType * thread )
{
    return (CosmOS_SemaphoreVariableType *)( thread->var->blockingSemaphoreVar );
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_thread_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_thread_h Setters
  * @ingroup Apis_thread_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn thread_setThreadBlockingMutexVar(CosmOS_ThreadConfigurationType *thread)
  *
  * @brief Set thread blockingMutexVar. This function cannot
  * be called from the unprivileged context directly.
  *
  * @param[in] thread configuration pointer
  * @param[in]  mutexParam pointer to the mutex variable
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
thread_setThreadBlockingMutexVar(
    CosmOS_ThreadConfigurationType * thread,
    CosmOS_MutexVariableType * mutexParam )
{
    thread->var->blockingMutexVar = mutexParam;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn thread_setThreadBlockingSemaphoreVar(CosmOS_ThreadConfigurationType
  * *thread)
  *
  * @brief Set thread blockingSemaphoreVar. This function cannot
  * be called from the unprivileged context directly.
  *
  * @param[in] thread configuration pointer
  * @param[in]  semaphoreParam pointer to the semaphore variable
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
thread_setThreadBlockingSemaphoreVar(
    CosmOS_ThreadConfigurationType * thread,
    CosmOS_SemaphoreVariableType * semaphoreParam )
{
    thread->var->blockingSemaphoreVar = semaphoreParam;
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_thread_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_thread_h General
  * @ingroup Apis_thread_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_thread_h
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
