/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file semaphore.c
*********************************************************************************
<!--                   semaphore Unit Local Group Definition                   -->
*********************************************************************************
** @defgroup Local_semaphore Local
** @ingroup semaphore_unit
** @brief semaphore locals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "semaphore.h"
#include "core.h"
#include "cosmosApiInternal.h"
#include "cosmosAssert.h"
#include "os.h"
#include "osEvent.h"
#include "program.h"
#include "supportStdio.h"

/* CIL interfaces */
#include "CILcore.h"
#include "CILinterrupt.h"
#include "CILsemaphore.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_semaphore Macros
  * @ingroup Local_semaphore
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_semaphore
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
  * @defgroup Variables_semaphore Variables
  * @ingroup Local_semaphore
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_semaphore
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
  * @defgroup Apis_semaphore_c API's
  * @ingroup Local_semaphore
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_semaphore_c Getters
  * @ingroup Apis_semaphore_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_semaphore_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_semaphore_c Setters
  * @ingroup Apis_semaphore_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_semaphore_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_semaphore_c General
  * @ingroup Apis_semaphore_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_semaphore_c
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
  * @fn semaphore_getSemaphoreInternal(BitWidthType entityId,
  * CosmOS_SemaphoreVariableType * semaphoreVar)
  *
  * @details The implementation contains obtaining of the core configuration by
  * calling the CILcore_getCoreCfg function. Then the function
  * CILsemaphore_trySemaphore is called and the returned semaphoreState is used
  * in the if condition where in case of
  * SEMAPHORE_STATE_ENUM__SUCCESSFULLY_LOCKED the schedulableOwner in the
  * semaphore variable is set to the schedulable in execution obtained from the
  * core variable.
  * If the semaphore was not successfully locked the thread variable is
  * obtained by calling the program_getProgramThread function and its
  * blocking semaphore variable is set to the semaphoreVar.
  * The state of the schedulable is set to the SCHEDULABLE_STATE_ENUM__BLOCKED
  * and context switch routine is triggered by calling
  * CILinterrupt_contextSwitchRoutineTrigger. In the end the semaphoreState is
  * returned.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_SemaphoreStateType
semaphore_getSemaphoreInternal(
    BitWidthType id,
    CosmOS_SemaphoreVariableType * semaphoreVar,
    BitWidthType semaphoreId )
{
    CosmOS_SemaphoreStateType semaphoreState;

    CosmOS_CoreConfigurationType * coreCfg;
    CosmOS_ThreadConfigurationType * threadCfg;

    coreCfg = CILcore_getCoreCfg();

    semaphoreState = CILsemaphore_trySemaphore(
        &( semaphoreVar->semaphore ),
        semaphoreId,
        ( (CosmOS_SchedulableConfigurationType *)
              coreCfg->var->schedulableInExecution )
            ->id );

    if ( semaphoreState IS_EQUAL_TO SEMAPHORE_STATE_ENUM__SUCCESSFULLY_LOCKED )
    {
        semaphoreVar->schedulableOwner = coreCfg->var->schedulableInExecution;
        __SUPRESS_UNUSED_VAR( threadCfg );
    }
    else
    {
        threadCfg = program_getProgramThread(
            (CosmOS_ProgramConfigurationType *)coreCfg->var->programInExecution,
            ( (CosmOS_SchedulableConfigurationType *)
                  coreCfg->var->schedulableInExecution )
                ->instanceId );
        threadCfg->var->blockingSemaphoreVar = semaphoreVar;
        ( (CosmOS_SchedulableConfigurationType *)
              coreCfg->var->schedulableInExecution )
            ->var->state = SCHEDULABLE_STATE_ENUM__BLOCKED;
        CILinterrupt_contextSwitchRoutineTrigger();
    }

    __SUPRESS_UNUSED_VAR( id );
    return semaphoreState;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn semaphore_trySemaphoreInternal(
  * BitWidthType id,
  * CosmOS_SemaphoreVariableType * semaphoreVar,
  * BitWidthType semaphoreId )
  *
  * @details The implementation contains obtaining of the core configuration by
  * calling function CILcore_getCoreCfg. Then the function
  * CILsemaphore_trySemaphore is called to try to get semaphore and result is
  * then returned as semaphore state. The if condition is implemented to check
  * if the result from CILsemaphore_trySemaphore is equal to the
  * SEMAPHORE_STATE_ENUM__SUCCESSFULLY_LOCKED and if yes the schedulable owner
  * member in semaphore variable is set to the schedulable in execution.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_SemaphoreStateType
semaphore_trySemaphoreInternal(
    BitWidthType id,
    CosmOS_SemaphoreVariableType * semaphoreVar,
    BitWidthType semaphoreId )
{
    CosmOS_SemaphoreStateType semaphoreState;

    CosmOS_CoreConfigurationType * coreCfg;

    coreCfg = CILcore_getCoreCfg();

    semaphoreState = CILsemaphore_trySemaphore(
        &( semaphoreVar->semaphore ),
        semaphoreId,
        ( (CosmOS_SchedulableConfigurationType *)
              coreCfg->var->schedulableInExecution )
            ->id );

    if ( semaphoreState IS_EQUAL_TO SEMAPHORE_STATE_ENUM__SUCCESSFULLY_LOCKED )
    {
        semaphoreVar->schedulableOwner = coreCfg->var->schedulableInExecution;
    }

    __SUPRESS_UNUSED_VAR( id );
    return semaphoreState;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn semaphore_releaseSemaphoreInternal(
  * BitWidthType id,
  * CosmOS_SemaphoreVariableType * semaphoreVar,
  * BitWidthType semaphoreId )
  *
  * @details The implementation contains obtaining of the core configuration by
  * calling the CILcore_getCoreCfg function. Then the function
  * CILsemaphore_releaseSemaphore is called. As the semaphore is now released it
  * is needed to notice all threads that were waiting for this specific
  * semaphore. As the semaphore can be used for synchronizing threads between
  * the different programs (inter-program) the for loops are implemented which
  * iterate over the all configurated cores in the system and threads in their
  * programs and if the thread variable blockingSemaphoreVar is equal to the
  * semaphoreVar its schedulable state is set to the
  * SCHEDULABLE_STATE_ENUM__READY and thread blockingSemaphoreVar is set to the
  * NULL pointer. If the core id of current core is equal to the core iterator
  * for loop variable, we check if threads which were blocked do not have higher
  * priority than the running thread that releases the semaphore, if yes the
  * local boolean variable higherPriorityThreadBlocked is set to True and it is
  * checked in the end if we have to trigger the reschedule on the current core.
  * If the blocked threads are bound to the different core we set the event
  * handle core variable with the coreId related to this core. After iterating
  * over all threads in the system we call the function osEvent_triggerEvent
  * if atleastOneCoreHandleEvent local variable is True with the
  * OS_EVENT_RESCHEDULE event and core handle array we configured before.
  * Then assertion is called to check if the os event state is
  * OS_EVENT_STATE_ENUM__OK. In the end the if condition is implemented that
  * checks if there is higherPriorityThreadBlocked on the current core and if
  * yes the CILinterrupt_contextSwitchRoutineTrigger function is called.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_SemaphoreStateType
semaphore_releaseSemaphoreInternal(
    BitWidthType id,
    CosmOS_SemaphoreVariableType * semaphoreVar,
    BitWidthType semaphoreId )
{
    BitWidthType coreId;

    CosmOS_BooleanType higherPriorityThreadBlocked, atleastOneCoreHandleEvent;

    CosmOS_OsEventStateType osEventState;
    CosmOS_SemaphoreStateType semaphoreState;

    CosmOS_CoreConfigurationType * coreCfg;
    CosmOS_ProgramConfigurationType * programCfg;
    CosmOS_ThreadConfigurationType * threadCfg;
    CosmOS_OsConfigurationType * osCfg;

    osCfg = os_getOsCfg();
    coreCfg = CILcore_getCoreCfg();
    coreId = core_getCoreId( coreCfg );

    semaphoreState = CILsemaphore_releaseSemaphore(
        &( semaphoreVar->semaphore ),
        semaphoreId,
        ( (CosmOS_SchedulableConfigurationType *)
              coreCfg->var->schedulableInExecution )
            ->id );

    higherPriorityThreadBlocked = False;
    atleastOneCoreHandleEvent = False;
    CosmOS_BooleanType osEventHandleCore[osCfg->numberOfCores];

    for ( BitWidthType coreIterator = 0; coreIterator < osCfg->numberOfCores;
          coreIterator++ )
    {
        osEventHandleCore[coreIterator] = False;
        coreCfg = os_getCore( osCfg, coreIterator );

        for ( BitWidthType programIterator = 0;
              programIterator < coreCfg->numberOfPrograms;
              programIterator++ )
        {
            programCfg = core_getCoreProgramCfg( coreCfg, programIterator );

            for ( BitWidthType threadIterator = 0;
                  threadIterator < programCfg->numberOfThreads;
                  threadIterator++ )

                if ( programCfg->threadCfgs[threadIterator]
                         .var->blockingSemaphoreVar IS_EQUAL_TO semaphoreVar )
                {
                    programCfg->threadCfgs[threadIterator]
                        .schedulable->var->state = SCHEDULABLE_STATE_ENUM__READY;

                    programCfg->threadCfgs[threadIterator]
                        .var->blockingSemaphoreVar = NULL;

                    if ( coreId IS_EQUAL_TO coreIterator )
                    {
                        threadCfg = program_getProgramThread(
                            (CosmOS_ProgramConfigurationType *)
                                coreCfg->var->programInExecution,
                            ( (CosmOS_SchedulableConfigurationType *)
                                  coreCfg->var->schedulableInExecution )
                                ->instanceId );

                        if ( programCfg->threadCfgs[threadIterator].priority >
                             threadCfg->priority )
                        {
                            higherPriorityThreadBlocked = True;
                        }
                    }
                    else
                    {
                        osEventHandleCore[coreIterator] = True;
                        atleastOneCoreHandleEvent = True;
                    }
                }
        }
    }

    if ( atleastOneCoreHandleEvent )
    {
        osEventState = osEvent_triggerEvent(
            OS_EVENT_RESCHEDULE, osEventHandleCore, NULL, 0 );

        cosmosAssert( osEventState IS_EQUAL_TO OS_EVENT_STATE_ENUM__OK );
    }

    if ( higherPriorityThreadBlocked )
    {
        CILinterrupt_contextSwitchRoutineTrigger();
    }

    __SUPRESS_UNUSED_VAR( id );
    return semaphoreState;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn semaphore_getSemaphore(BitWidthType semaphoreId)
  *
  * @details The implementation contains obtaining of the operating system and
  * core configuration by calling functions os_getOsCfg and CILcore_getCoreCfg.
  * Then the operating system configuration in function
  * os_getOsNumberOfSemaphores to get number of semaphores.
  * The input element id argument is then checked
  * againts the number of semaphore, if it is greater than number of semaphores
  * SEMAPHORE_STATE_ENUM__ERROR_INVALID_ID is returned.
  * Semaphore variable is then obtained based on the id argument by the function
  * os_getOsSemaphoreVar.
  * Nested if condition then subsequently checks if the schedulable in execution
  * which means the semaphore release requesting schedulable is a thread type
  * SCHEDULABLE_INSTANCE_ENUM__THREAD. If not the semaphoreState is returned with
  * the value SEMAPHORE_STATE_ENUM__ERROR_ONLY_THREADS_CAN_USE_SEMAPHORE.
  * The function semaphore_willCauseDeadlock is called to
  * check if the semaphore would cause eventually deadlock, if yes the semaphore
  * state SEMAPHORE_STATE_ENUM__ERROR_DEADLOCK is returned. Otherwise the
  * function cosmosApiInternal_semaphore_getSemaphoreInternal is called if the
  * core is in the privileged mode or semaphore_getSemaphoreInternal is called
  * to get semaphore and result is then returned as semaphore state.
  * The schedulable owner member in semaphore variable is set to the schedulable
  * in execution.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_SemaphoreStateType
semaphore_getSemaphore( BitWidthType semaphoreId )
{
    BitWidthType numberOfSemaphores;

    CosmOS_BooleanType willCauseDeadlock;
    CosmOS_SemaphoreStateType semaphoreState;

    CosmOS_OsConfigurationType * osCfg;
    CosmOS_CoreConfigurationType * coreCfg;
    CosmOS_SemaphoreVariableType * semaphoreVar;

    osCfg = os_getOsCfg();
    coreCfg = CILcore_getCoreCfg();

    numberOfSemaphores = os_getOsNumberOfSemaphores( osCfg );

    if ( semaphoreId < numberOfSemaphores )
    {
        semaphoreVar = os_getOsSemaphoreVar( osCfg, semaphoreId );

        if ( ( (CosmOS_SchedulableConfigurationType *)
                   coreCfg->var->schedulableInExecution )
                 ->instanceType IS_EQUAL_TO SCHEDULABLE_INSTANCE_ENUM__THREAD )
        {
            willCauseDeadlock =
                semaphore_willCauseDeadlock( coreCfg, semaphoreVar );
            if ( willCauseDeadlock )
            {
                semaphoreState = SEMAPHORE_STATE_ENUM__ERROR_DEADLOCK;
            }
            else
            {
                do
                {
                    semaphoreState =
                        cosmosApiInternal_semaphore_getSemaphoreInternal(
                            semaphoreVar, semaphoreId );
                } while ( semaphoreState IS_NOT_EQUAL_TO
                              SEMAPHORE_STATE_ENUM__SUCCESSFULLY_LOCKED );
            }
        }
        else
        {
            semaphoreState =
                SEMAPHORE_STATE_ENUM__ERROR_ONLY_THREADS_CAN_USE_SEMAPHORE;
        }
    }
    else
    {
        semaphoreState = SEMAPHORE_STATE_ENUM__ERROR_INVALID_ID;
    }

    return semaphoreState;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn semaphore_trySemaphore(BitWidthType semaphoreId)
  *
  * @details The implementation contains obtaining of the operating system and
  * core configuration by calling functions os_getOsCfg and CILcore_getCoreCfg.
  * Then the operating system configuration in function
  * os_getOsNumberOfSemaphores to get number of semaphores.
  * The input element id argument is then checked
  * againts the number of semaphore, if it is greater than number of semaphores
  * SEMAPHORE_STATE_ENUM__ERROR_INVALID_ID is returned. Semaphore
  * variable is then obtained based on the id argument by the function
  * os_getOsSemaphoreVar.
  * Next if condition then subsequently checks if the schedulable in execution
  * which means the semaphore release requesting schedulable is a thread type
  * SCHEDULABLE_INSTANCE_ENUM__THREAD. If not the semaphoreState is returned with
  * the value SEMAPHORE_STATE_ENUM__ERROR_ONLY_THREADS_CAN_USE_SEMAPHORE.
  * Then the function cosmosApiInternal_semaphore_trySemaphoreInternal is called
  * if the core is in the privileged mode or semaphore_trySemaphoreInternal is
  * called try to get semaphore and result is then returned as semaphore state.
  * The if condition is implemented to check if the result from
  * cosmosApiInternal_semaphore_trySemaphoreInternal is equal to the
  * SEMAPHORE_STATE_ENUM__SUCCESSFULLY_LOCKED and if yes  the schedulable owner
  * member in semaphore variable is set to the schedulable in execution.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_SemaphoreStateType
semaphore_trySemaphore( BitWidthType semaphoreId )
{
    BitWidthType numberOfSemaphores;

    CosmOS_SemaphoreStateType semaphoreState;

    CosmOS_OsConfigurationType * osCfg;
    CosmOS_CoreConfigurationType * coreCfg;
    CosmOS_SemaphoreVariableType * semaphoreVar;

    osCfg = os_getOsCfg();
    coreCfg = CILcore_getCoreCfg();

    numberOfSemaphores = os_getOsNumberOfSemaphores( osCfg );

    if ( semaphoreId < numberOfSemaphores )
    {
        semaphoreVar = os_getOsSemaphoreVar( osCfg, semaphoreId );

        if ( ( (CosmOS_SchedulableConfigurationType *)
                   coreCfg->var->schedulableInExecution )
                 ->instanceType IS_EQUAL_TO SCHEDULABLE_INSTANCE_ENUM__THREAD )
        {
            semaphoreState = cosmosApiInternal_semaphore_trySemaphoreInternal(
                semaphoreVar, semaphoreId );
        }
        else
        {
            semaphoreState =
                SEMAPHORE_STATE_ENUM__ERROR_ONLY_THREADS_CAN_USE_SEMAPHORE;
        }
    }
    else
    {
        semaphoreState = SEMAPHORE_STATE_ENUM__ERROR_INVALID_ID;
    }

    return semaphoreState;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn semaphore_releaseSemaphore(BitWidthType id)
  *
  * @details The implementation contains obtaining of the operating system and
  * core configuration by calling functions os_getOsCfg and CILcore_getCoreCfg.
  * Then the operating system configuration in function
  * os_getOsNumberOfSemaphores to get number of semaphores.
  * The input element id argument is then checked
  * againts the number of semaphore, if it is greater than number of semaphores
  * SEMAPHORE_STATE_ENUM__ERROR_INVALID_ID is returned. Semaphore
  * variable is then obtained based on the id argument by the function
  * os_getOsSemaphoreVar.
  * Next if condition then subsequently checks if the schedulable in execution
  * which means the semaphore release requesting schedulable is a thread type
  * SCHEDULABLE_INSTANCE_ENUM__THREAD. If not the semaphoreState is returned with
  * the value SEMAPHORE_STATE_ENUM__ERROR_ONLY_THREADS_CAN_USE_SEMAPHORE.
  * The the boolean is obtained by calling function
  * semaphore_ownsSchedulableSemaphore to know if the requesting schedulable owns
  * the semaphore which means if the schedulable locked the semaphore before.
  * The semaphore member of the semaphore variable structure is compared in the
  * implemented if condition that checks if the semaphore is equal to the state
  * SEMAPHORE_STATE_ENUM__OCCUPIED otherwise the semaphore state is returned with
  * the value SEMAPHORE_STATE_ENUM__ERROR_NOT_IN_OCCUPIED_STATE. Another nested
  * if condition is implemented to check the obtained boolean variable that
  * stores value if the requesting schedulable owns the semaphore. If yes the
  * cosmosApiInternal_semaphore_releaseSemaphoreInternal function is called if
  * the core is in the privileged mode or semaphore_releaseSemaphoreInternal is
  * called and the result is returned as semaphore state. Otherwise the semaphore
  * state is SEMAPHORE_STATE_ENUM__ERROR_SCHEDULABLE_IS_NOT_OWNER.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_SemaphoreStateType
semaphore_releaseSemaphore( BitWidthType semaphoreId )
{
    BitWidthType numberOfSemaphores;

    CosmOS_BooleanType ownsSchedulableSemaphore;

    CosmOS_SemaphoreStateType semaphoreState;

    CosmOS_OsConfigurationType * osCfg;
    CosmOS_CoreConfigurationType * coreCfg;
    CosmOS_SemaphoreVariableType * semaphoreVar;

    osCfg = os_getOsCfg();
    coreCfg = CILcore_getCoreCfg();

    numberOfSemaphores = os_getOsNumberOfSemaphores( osCfg );

    if ( semaphoreId < numberOfSemaphores )
    {
        semaphoreVar = os_getOsSemaphoreVar( osCfg, semaphoreId );

        if ( ( (CosmOS_SchedulableConfigurationType *)
                   coreCfg->var->schedulableInExecution )
                 ->instanceType IS_EQUAL_TO SCHEDULABLE_INSTANCE_ENUM__THREAD )
        {
            ownsSchedulableSemaphore =
                semaphore_ownsSchedulableSemaphore( coreCfg, semaphoreVar );

            if ( semaphoreVar->semaphore IS_EQUAL_TO
                     SEMAPHORE_STATE_ENUM__OCCUPIED )
            {
                if ( ownsSchedulableSemaphore )
                {
                    semaphoreState =
                        cosmosApiInternal_semaphore_releaseSemaphoreInternal(
                            semaphoreVar, semaphoreId );
                }
                else
                {
                    semaphoreState =
                        SEMAPHORE_STATE_ENUM__ERROR_SCHEDULABLE_IS_NOT_OWNER;
                }
            }
            else
            {
                semaphoreState =
                    SEMAPHORE_STATE_ENUM__ERROR_NOT_IN_OCCUPIED_STATE;
            }
        }
        else
        {
            semaphoreState =
                SEMAPHORE_STATE_ENUM__ERROR_ONLY_THREADS_CAN_USE_SEMAPHORE;
        }
    }
    else
    {
        semaphoreState = SEMAPHORE_STATE_ENUM__ERROR_INVALID_ID;
    }

    return semaphoreState;
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
