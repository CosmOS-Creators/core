/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file mutex.c
*********************************************************************************
<!--                     mutex Unit Local Group Definition                    -->
*********************************************************************************
** @defgroup Local_mutex Local
** @ingroup mutex_unit
** @brief mutex locals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "mutex.h"
#include "core.h"
#include "cosmosApiInternal.h"
#include "cosmosAssert.h"
#include "memoryProtection.h"
#include "program.h"

/* CIL interfaces */
#include "CILcore.h"
#include "CILinterrupt.h"
#include "CILmutex.h"

/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_mutex Macros
  * @ingroup Local_mutex
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_mutex
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
  * @defgroup Variables_mutex Variables
  * @ingroup Local_mutex
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_mutex
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
  * @defgroup Apis_mutex_c API's
  * @ingroup Local_mutex
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_mutex_c Getters
  * @ingroup Apis_mutex_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_mutex_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_mutex_c Setters
  * @ingroup Apis_mutex_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_mutex_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_mutex_c General
  * @ingroup Apis_mutex_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_mutex_c
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
  * @fn mutex_getMutexInternal(BitWidthType entityId,
  * CosmOS_MutexVariableType * mutexVar)
  *
  * @details The implementation contains obtaining of the core configuration by
  * calling the CILcore_getCoreCfg function. Then the function CILmutex_tryMutex
  * is called and the returned mutexState is used in the if condition where in
  * case of MUTEX_STATE_ENUM__SUCCESSFULLY_LOCKED the schedulableOwner in the
  * mutex variable is set to the schedulable in execution obtained from the core
  * variable. If the mutex was not successfully locked the thread variable is
  * obtained by calling the program_getProgramThread function and its
  * blocking mutex variable is set to the mutexVar. The state of the schedulable
  * is set to the SCHEDULABLE_STATE_ENUM__BLOCKED and context switch routine is
  * triggered by calling CILinterrupt_contextSwitchRoutineTrigger. In the end
  * the mutexState is returned.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_MutexStateType
mutex_getMutexInternal(
    BitWidthType entityId,
    CosmOS_MutexVariableType * mutexVar )
{
    CosmOS_MutexStateType mutexState;

    CosmOS_CoreConfigurationType * coreCfg;
    CosmOS_ThreadConfigurationType * threadCfg;

    coreCfg = CILcore_getCoreCfg();

    mutexState = CILmutex_tryMutex( &( mutexVar->mutex ) );
    if ( mutexState IS_EQUAL_TO MUTEX_STATE_ENUM__SUCCESSFULLY_LOCKED )
    {
        mutexVar->schedulableOwner = coreCfg->var->schedulableInExecution;
        __SUPRESS_UNUSED_VAR( threadCfg );
    }
    else
    {
        threadCfg = program_getProgramThread(
            (CosmOS_ProgramConfigurationType *)coreCfg->var->programInExecution,
            ( (CosmOS_SchedulableConfigurationType *)
                  coreCfg->var->schedulableInExecution )
                ->instanceId );
        threadCfg->var->blockingMutexVar = mutexVar;
        ( (CosmOS_SchedulableConfigurationType *)
              coreCfg->var->schedulableInExecution )
            ->var->state = SCHEDULABLE_STATE_ENUM__BLOCKED;
        CILinterrupt_contextSwitchRoutineTrigger();
    }

    __SUPRESS_UNUSED_VAR( entityId );
    return mutexState;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn mutex_tryMutexInternal(BitWidthType entityId,
  * CosmOS_MutexVariableType * mutexVar)
  *
  * @details The implementation contains obtaining of the core configuration by
  * calling the CILcore_getCoreCfg function. Then the function CILmutex_tryMutex
  * is called and the returned mutexState is used in the if condition where in
  * case of MUTEX_STATE_ENUM__SUCCESSFULLY_LOCKED the schedulableOwner in the
  * mutex variable is set to the schedulable in execution obtained from the core
  * variable. In the end the mutexState is returned.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_MutexStateType
mutex_tryMutexInternal(
    BitWidthType entityId,
    CosmOS_MutexVariableType * mutexVar )
{
    CosmOS_MutexStateType mutexState;

    CosmOS_CoreConfigurationType * coreCfg;

    coreCfg = CILcore_getCoreCfg();

    mutexState = CILmutex_tryMutex( &( mutexVar->mutex ) );
    if ( mutexState IS_EQUAL_TO MUTEX_STATE_ENUM__SUCCESSFULLY_LOCKED )
    {
        mutexVar->schedulableOwner = coreCfg->var->schedulableInExecution;
    }

    __SUPRESS_UNUSED_VAR( entityId );
    return mutexState;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn mutex_releaseMutexInternal(BitWidthType entityId,
  * CosmOS_MutexVariableType * mutexVar)
  *
  * @details The implementation contains obtaining of the core configuration by
  * calling the CILcore_getCoreCfg function. Then the function
  * CILmutex_releaseMutex is called. As the mutex is now released it is needed
  * to notice all threads that were waiting for this specific mutex. As the
  * mutex can be used only for the threads within the one program the for loop
  * is implemented that iterates over all threads in the current program and if
  * the thread variable blockingMutexVar is equal to the mutexVar its
  * schedulable state is set to the SCHEDULABLE_STATE_ENUM__READY, the thread
  * blockingMutexVar is set to the NULL pointer and the
  * priority of the thread in current context is obtained by getting the thread
  * variable in the first place by function program_getProgramThread and then
  * comparing this to the thread variable that was blocked by the mutexVar. If
  * the blocked thread priority is higher the flag higherPriorityThreadBlocked
  * is set to True and the CILinterrupt_contextSwitchRoutineTrigger is called
  * in the end to trigger scheduler algorithm to unblock higher priority thread.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_MutexStateType
mutex_releaseMutexInternal(
    BitWidthType entityId,
    CosmOS_MutexVariableType * mutexVar )
{
    CosmOS_BooleanType higherPriorityThreadBlocked;
    CosmOS_MutexStateType mutexState;

    CosmOS_CoreConfigurationType * coreCfg;
    CosmOS_ThreadConfigurationType * threadCfg;

    coreCfg = CILcore_getCoreCfg();

    mutexState = CILmutex_releaseMutex( &( mutexVar->mutex ) );

    higherPriorityThreadBlocked = False;
    for ( BitWidthType iterator = 0;
          iterator <
          ( (CosmOS_ProgramConfigurationType *)coreCfg->var->programInExecution )
              ->numberOfThreads;
          iterator++ )
    {
        if ( ( (CosmOS_ProgramConfigurationType *)
                   coreCfg->var->programInExecution )
                 ->threadCfgs[iterator]
                 .var->blockingMutexVar IS_EQUAL_TO mutexVar )
        {
            ( (CosmOS_ProgramConfigurationType *)
                  coreCfg->var->programInExecution )
                ->threadCfgs[iterator]
                .schedulable->var->state = SCHEDULABLE_STATE_ENUM__READY;
            ( (CosmOS_ProgramConfigurationType *)
                  coreCfg->var->programInExecution )
                ->threadCfgs[iterator]
                .var->blockingMutexVar = NULL;

            threadCfg = program_getProgramThread(
                (CosmOS_ProgramConfigurationType *)
                    coreCfg->var->programInExecution,
                ( (CosmOS_SchedulableConfigurationType *)
                      coreCfg->var->schedulableInExecution )
                    ->instanceId );
            if ( ( (CosmOS_ProgramConfigurationType *)
                       coreCfg->var->programInExecution )
                     ->threadCfgs[iterator]
                     .priority > threadCfg->priority )
            {
                higherPriorityThreadBlocked = True;
            }
        }
    }

    if ( higherPriorityThreadBlocked )
    {
        CILinterrupt_contextSwitchRoutineTrigger();
    }

    __SUPRESS_UNUSED_VAR( entityId );
    return mutexState;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn mutex_getMutex(CosmOS_MutexVariableType * mutexVar)
  *
  * @details The implementation contains obtaining of the core configuration by
  * calling the CILcore_getCoreCfg function. Then the mutex variable address is
  * checked if its not in the memory protected region by calling the function
  * memoryProtection_isMemoryRegionProtected. If the address of mutex variable
  * is protected mutexState with MUTEX_STATE_ENUM__ERROR_INVALID_MUTEX_ADDRESS
  * value is returned.
  * Nested if condition then subsequently checks if the schedulable in execution
  * which means the mutex release requesting schedulable is a thread type
  * SCHEDULABLE_INSTANCE_ENUM__THREAD. If not the mutexState is returned with
  * the value MUTEX_STATE_ENUM__ERROR_ONLY_THREADS_CAN_USE_MUTEX.
  * After this point another condition is needed to check if the schedulable in
  * execution will not cause the deadlock by calling mutex_willCauseDeadlock
  * function. If yes the mutexState is returned with the value
  * MUTEX_STATE_ENUM__ERROR_DEADLOCK. If not the do while loop is implemented
  * with calling the cosmosApiInternal_mutex_getMutexInternal till the returned
  * value is not MUTEX_STATE_ENUM__SUCCESSFULLY_LOCKED.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_MutexStateType
mutex_getMutex( CosmOS_MutexVariableType * mutexVar )
{
    CosmOS_BooleanType isMutexInProtectedMemory;
    CosmOS_BooleanType willCauseDeadlock;
    CosmOS_MutexStateType mutexState;

    CosmOS_CoreConfigurationType * coreCfg;

    coreCfg = CILcore_getCoreCfg();

    isMutexInProtectedMemory = memoryProtection_isMemoryRegionProtected(
        coreCfg, (void *)mutexVar, sizeof( mutexVar ) );

    if ( IS_NOT( isMutexInProtectedMemory ) )
    {
        if ( ( (CosmOS_SchedulableConfigurationType *)
                   coreCfg->var->schedulableInExecution )
                 ->instanceType IS_EQUAL_TO SCHEDULABLE_INSTANCE_ENUM__THREAD )
        {
            willCauseDeadlock = mutex_willCauseDeadlock( coreCfg, mutexVar );
            if ( willCauseDeadlock )
            {
                mutexState = MUTEX_STATE_ENUM__ERROR_DEADLOCK;
            }
            else
            {
                do
                {
                    mutexState =
                        cosmosApiInternal_mutex_getMutexInternal( mutexVar );
                } while ( mutexState IS_NOT_EQUAL_TO
                              MUTEX_STATE_ENUM__SUCCESSFULLY_LOCKED );
            }
        }
        else
        {
            mutexState = MUTEX_STATE_ENUM__ERROR_ONLY_THREADS_CAN_USE_MUTEX;
        }
    }
    else
    {
        mutexState = MUTEX_STATE_ENUM__ERROR_INVALID_MUTEX_ADDRESS;
    }

    return mutexState;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn mutex_tryMutex(CosmOS_MutexVariableType * mutexVar)
  *
  * @details The implementation contains obtaining of the core configuration by
  * calling the CILcore_getCoreCfg function. Then the mutex variable address is
  * checked if its not in the memory protected region by calling the function
  * memoryProtection_isMemoryRegionProtected. If the address of mutex variable
  * is protected mutexState with MUTEX_STATE_ENUM__ERROR_INVALID_MUTEX_ADDRESS
  * value is returned.
  * Nested if condition then subsequently checks if the schedulable in execution
  * which means the mutex release requesting schedulable is a thread type
  * SCHEDULABLE_INSTANCE_ENUM__THREAD. If not the mutexState is returned with
  * the value MUTEX_STATE_ENUM__ERROR_ONLY_THREADS_CAN_USE_MUTEX. If yes then is
  * possible to try to lock the mutex by calling CosmOS API function
  * cosmosApiInternal_mutex_tryMutexInternal.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_MutexStateType
mutex_tryMutex( CosmOS_MutexVariableType * mutexVar )
{
    CosmOS_BooleanType isMutexInProtectedMemory;
    CosmOS_MutexStateType mutexState;

    CosmOS_CoreConfigurationType * coreCfg;

    coreCfg = CILcore_getCoreCfg();

    isMutexInProtectedMemory = memoryProtection_isMemoryRegionProtected(
        coreCfg, (void *)mutexVar, sizeof( mutexVar ) );

    if ( IS_NOT( isMutexInProtectedMemory ) )
    {
        if ( ( (CosmOS_SchedulableConfigurationType *)
                   coreCfg->var->schedulableInExecution )
                 ->instanceType IS_EQUAL_TO SCHEDULABLE_INSTANCE_ENUM__THREAD )
        {
            mutexState = cosmosApiInternal_mutex_tryMutexInternal( mutexVar );
        }
        else
        {
            mutexState = MUTEX_STATE_ENUM__ERROR_ONLY_THREADS_CAN_USE_MUTEX;
        }
    }
    else
    {
        mutexState = MUTEX_STATE_ENUM__ERROR_INVALID_MUTEX_ADDRESS;
    }

    return mutexState;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn mutex_releaseMutex(CosmOS_MutexVariableType * mutexVar)
  *
  * @details The implementation contains obtaining of the core configuration by
  * calling the CILcore_getCoreCfg function. Then the mutex variable address is
  * checked if its not in the memory protected region by calling the function
  * memoryProtection_isMemoryRegionProtected. If the address of mutex variable
  * is protected mutexState with MUTEX_STATE_ENUM__ERROR_INVALID_MUTEX_ADDRESS
  * value is returned.
  * Nested if condition then subsequently checks if the schedulable in execution
  * which means the mutex release requesting schedulable is a thread type
  * SCHEDULABLE_INSTANCE_ENUM__THREAD. If not the mutexState is returned with
  * the value MUTEX_STATE_ENUM__ERROR_ONLY_THREADS_CAN_USE_MUTEX.
  * After this point another condition is needed to check if the schedulable in
  * execution owns the mutex variable by calling mutex_ownsSchedulableMutex
  * function. If not the mutexState is returned with
  * the value MUTEX_STATE_ENUM__ERROR_SCHEDULABLE_IS_NOT_OWNER.
  * The last if condition checks if the mutex variable value is equal to
  * MUTEX_STATE_ENUM__OCCUPIED which means that the mutex is locked, if not the
  * mutexState is returned with MUTEX_STATE_ENUM__ERROR_NOT_IN_OCCUPIED_STATE.
  * If yes then the mutex can be released by calling CosmOS API function
  * cosmosApiInternal_mutex_releaseMutexInternal.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_MutexStateType
mutex_releaseMutex( CosmOS_MutexVariableType * mutexVar )
{
    CosmOS_BooleanType ownsSchedulableMutex, isMutexInProtectedMemory;
    CosmOS_MutexStateType mutexState;

    CosmOS_CoreConfigurationType * coreCfg;

    coreCfg = CILcore_getCoreCfg();

    isMutexInProtectedMemory = memoryProtection_isMemoryRegionProtected(
        coreCfg, (void *)mutexVar, sizeof( mutexVar ) );

    if ( IS_NOT( isMutexInProtectedMemory ) )
    {
        if ( ( (CosmOS_SchedulableConfigurationType *)
                   coreCfg->var->schedulableInExecution )
                 ->instanceType IS_EQUAL_TO SCHEDULABLE_INSTANCE_ENUM__THREAD )
        {
            ownsSchedulableMutex =
                mutex_ownsSchedulableMutex( coreCfg, mutexVar );
            if ( mutexVar->mutex IS_EQUAL_TO MUTEX_STATE_ENUM__OCCUPIED )
            {
                if ( ownsSchedulableMutex )
                {
                    mutexState =
                        cosmosApiInternal_mutex_releaseMutexInternal( mutexVar );
                }
                else
                {
                    mutexState =
                        MUTEX_STATE_ENUM__ERROR_SCHEDULABLE_IS_NOT_OWNER;
                }
            }
            else
            {
                mutexState = MUTEX_STATE_ENUM__ERROR_NOT_IN_OCCUPIED_STATE;
            }
        }
        else
        {
            mutexState = MUTEX_STATE_ENUM__ERROR_ONLY_THREADS_CAN_USE_MUTEX;
        }
    }
    else
    {
        mutexState = MUTEX_STATE_ENUM__ERROR_INVALID_MUTEX_ADDRESS;
    }

    return mutexState;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/
/********************************************************************************
**                        Function Definitions | Stop                          **
********************************************************************************/
/********************************************************************************
**                           END OF THE SOURCE FILE                            **
********************************************************************************/
