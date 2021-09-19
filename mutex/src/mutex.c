/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file mutex.c
*********************************************************************************
<!--                     mutex Unit Local Group Definition                   -->
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
#include "core.h"
#include "mutex.h"
#include "program.h"
#include "cosmosAssert.h"
#include "cosmosApiPrivate.h"
#include "memoryProtection.h"

/* CIL interfaces */
#include "CILcore.h"
#include "CILmutex.h"
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
  * @defgroup Macros_mutex Macros
  * @ingroup Local_mutex
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Macros_mutex
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
  * @}
  * Variables_mutex
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
  * @}
  * Getters_mutex_c
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
  * @}
  * Setters_mutex_c
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
  * @}
  * General_mutex_c
********************************************************************************/
/********************************************************************************
**                         Function Prototypes | Stop                          **
********************************************************************************/
/********************************************************************************
**                        Function Definitions | Start                         **
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn mutex_getMutexPrivileged(BitWidthType entityId, CosmOS_MutexVariableType * mutexVar)
  *
  * @brief Get mutex privileged DEMO CODE.
  *
  *	@param[in]	BitWidthType entityId
  * @param[in]  CosmOS_MutexVariableType * mutexVar
  *
  * @return CosmOS_MutexStateType
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION CosmOS_MutexStateType mutex_getMutexPrivileged(BitWidthType entityId, CosmOS_MutexVariableType * mutexVar)
{
	CosmOS_MutexStateType mutexState;

	CosmOS_CoreVariableType * coreVar;
	CosmOS_ThreadVariableType * threadVar;


	coreVar = CILcore_getCoreVar();

	mutexState = CILmutex_tryMutex(&(mutexVar->mutex));
	if ( mutexState IS_EQUAL_TO MUTEX_STATE_ENUM__SUCCESSFULLY_LOCKED )
	{
		mutexVar->schedulableOwner = coreVar->schedulableInExecution;
		__SUPRESS_UNUSED_VAR(threadVar);
	}
	else
	{
		threadVar = program_getProgramThread(coreVar->programInExecution,coreVar->schedulableInExecution->cfg->instanceId);
		threadVar->blockingMutexVar = mutexVar;
		coreVar->schedulableInExecution->state = SCHEDULABLE_STATE_ENUM__BLOCKED;
		CILinterrupt_contextSwitchRoutineTrigger();
	}

	__SUPRESS_UNUSED_VAR(entityId);
	return mutexState;
}
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn mutex_tryMutexPrivileged(BitWidthType entityId, CosmOS_MutexVariableType * mutexVar)
  *
  * @brief Get mutex privileged DEMO CODE.
  *
  *	@param[in]	BitWidthType entityId
  * @param[in]  CosmOS_MutexVariableType * mutexVar
  *
  * @return CosmOS_MutexStateType
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION CosmOS_MutexStateType mutex_tryMutexPrivileged(BitWidthType entityId, CosmOS_MutexVariableType * mutexVar)
{
	CosmOS_MutexStateType mutexState;

	CosmOS_CoreVariableType * coreVar;


	coreVar = CILcore_getCoreVar();

	mutexState = CILmutex_tryMutex(&(mutexVar->mutex));
	if ( mutexState IS_EQUAL_TO MUTEX_STATE_ENUM__SUCCESSFULLY_LOCKED )
	{
		mutexVar->schedulableOwner = coreVar->schedulableInExecution;
	}

	__SUPRESS_UNUSED_VAR(entityId);
	return mutexState;
}
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn mutex_releaseMutexPrivileged(BitWidthType entityId, CosmOS_MutexVariableType * mutexVar)
  *
  * @brief Release mutex privileged DEMO CODE.
  *
  *	@param[in]	BitWidthType entityId
  * @param[in]  CosmOS_MutexVariableType * mutexVar
  *
  * @return CosmOS_MutexStateType
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION CosmOS_MutexStateType mutex_releaseMutexPrivileged(BitWidthType entityId, CosmOS_MutexVariableType * mutexVar)
{
	CosmOS_BooleanType higherPriorityThreadBlocked;
	CosmOS_MutexStateType mutexState;

	CosmOS_CoreVariableType * coreVar;
	CosmOS_ThreadVariableType * threadVar;

	coreVar = CILcore_getCoreVar();

	mutexState = CILmutex_releaseMutex(&(mutexVar->mutex));

	higherPriorityThreadBlocked = False;
	for (BitWidthType iterator = 0; iterator < coreVar->programInExecution->cfg->numberOfThreads; iterator++)
	{
		if (coreVar->programInExecution->threadVars[iterator].blockingMutexVar IS_EQUAL_TO mutexVar)
		{
			coreVar->programInExecution->threadVars[iterator].schedulable->state = SCHEDULABLE_STATE_ENUM__READY;
			coreVar->programInExecution->threadVars[iterator].blockingMutexVar = NULL;

			threadVar = program_getProgramThread(coreVar->programInExecution,coreVar->schedulableInExecution->cfg->instanceId);
			if ( coreVar->programInExecution->threadVars[iterator].cfg->priority > threadVar->cfg->priority )
			{
				higherPriorityThreadBlocked = True;
			}
		}
	}

	if (higherPriorityThreadBlocked)
	{
		CILinterrupt_contextSwitchRoutineTrigger();
	}

	__SUPRESS_UNUSED_VAR(entityId);
	return mutexState;
}
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn mutex_getMutex(CosmOS_MutexVariableType * mutexVar)
  *
  * @brief Get mutex DEMO CODE.
  *
  * @param[in]  CosmOS_MutexVariableType * mutexVar
  *
  * @return CosmOS_MutexStateType
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION CosmOS_MutexStateType mutex_getMutex(CosmOS_MutexVariableType * mutexVar)
{
	CosmOS_BooleanType isMutexInProtectedMemory;
	CosmOS_BooleanType willCauseDeadlock;
	CosmOS_MutexStateType mutexState;

	CosmOS_CoreVariableType * coreVar;


	coreVar = CILcore_getCoreVar();

	isMutexInProtectedMemory = memoryProtection_isMemoryRegionProtected(coreVar, (void *)mutexVar, sizeof(mutexVar));

	if ( IS_NOT(isMutexInProtectedMemory) )
	{
		if (coreVar->schedulableInExecution->cfg->instanceType IS_EQUAL_TO SCHEDULABLE_INSTANCE_ENUM__THREAD )
		{
			willCauseDeadlock = mutex_willCauseDeadlock(coreVar, mutexVar);
			if( willCauseDeadlock )
			{
				mutexState = MUTEX_STATE_ENUM__DEADLOCK_WARNING;
			}
			else
			{
				do
				{
					mutexState = cosmosApiPrivate_mutex_getMutexPrivileged(mutexVar);
				} while ( mutexState IS_NOT_EQUAL_TO MUTEX_STATE_ENUM__SUCCESSFULLY_LOCKED );

			}
		}
		else
		{
			mutexState = MUTEX_STATE_ENUM__ERROR_ONLY_THREADS_CAN_MUTEX;
		}
	}
	else
	{
		mutexState = MUTEX_STATE_ENUM__ERROR_INVALID_MUTEX_ADDRESS;
	}

	return mutexState;
}
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn mutex_tryMutex(CosmOS_MutexVariableType * mutexVar)
  *
  * @brief Try to get mutex DEMO CODE
  * .
  * @param[in]  CosmOS_MutexVariableType * mutexVar
  *
  * @return CosmOS_MutexStateType
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION CosmOS_MutexStateType mutex_tryMutex(CosmOS_MutexVariableType * mutexVar)
{
	CosmOS_BooleanType isMutexInProtectedMemory;
	CosmOS_MutexStateType mutexState;

	CosmOS_CoreVariableType * coreVar;


	coreVar = CILcore_getCoreVar();

	isMutexInProtectedMemory = memoryProtection_isMemoryRegionProtected(coreVar, (void *)mutexVar, sizeof(mutexVar));

	if ( IS_NOT(isMutexInProtectedMemory) )
	{
		if (coreVar->schedulableInExecution->cfg->instanceType IS_EQUAL_TO SCHEDULABLE_INSTANCE_ENUM__THREAD )
		{
			mutexState = cosmosApiPrivate_mutex_tryMutexPrivileged(mutexVar);
		}
		else
		{
			mutexState = MUTEX_STATE_ENUM__ERROR_ONLY_THREADS_CAN_MUTEX;
		}
	}
	else
	{
		mutexState = MUTEX_STATE_ENUM__ERROR_INVALID_MUTEX_ADDRESS;
	}

	return mutexState;
}
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn mutex_releaseMutex(CosmOS_MutexVariableType * mutexVar)
  *
  * @brief Release mutex DEMO CODE.
  *
  * @param[in]  CosmOS_MutexVariableType * mutexVar
  *
  * @return CosmOS_MutexStateType
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION CosmOS_MutexStateType mutex_releaseMutex(CosmOS_MutexVariableType * mutexVar)
{
	CosmOS_BooleanType ownsSchedulableMutex,
						isMutexInProtectedMemory;
	CosmOS_MutexStateType mutexState;

	CosmOS_CoreVariableType * coreVar;


	coreVar = CILcore_getCoreVar();

	isMutexInProtectedMemory = memoryProtection_isMemoryRegionProtected(coreVar, (void *)mutexVar, sizeof(mutexVar));

	if ( IS_NOT(isMutexInProtectedMemory) )
	{
		if (coreVar->schedulableInExecution->cfg->instanceType IS_EQUAL_TO SCHEDULABLE_INSTANCE_ENUM__THREAD )
		{
			ownsSchedulableMutex = mutex_ownsSchedulableMutex(coreVar, mutexVar);
			if ( mutexVar->mutex IS_EQUAL_TO MUTEX_STATE_ENUM__OCCUPIED )
			{
				if ( ownsSchedulableMutex )
				{
					mutexState = cosmosApiPrivate_mutex_releaseMutexPrivileged(mutexVar);
				}
				else
				{
					mutexState = MUTEX_STATE_ENUM__ERROR_SCHEDULABLE_IS_NOT_OWNER;
				}
			}
			else
			{
				mutexState = MUTEX_STATE_ENUM__ERROR_NOT_IN_OCCUPIED_STATE;
			}
		}
		else
		{
			mutexState = MUTEX_STATE_ENUM__ERROR_ONLY_THREADS_CAN_MUTEX;
		}
	}
	else
	{
		mutexState = MUTEX_STATE_ENUM__ERROR_INVALID_MUTEX_ADDRESS;
	}

	return mutexState;
}
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/
/********************************************************************************
**                        Function Definitions | Stop                          **
********************************************************************************/
/********************************************************************************
**                           END OF THE SOURCE FILE                            **
********************************************************************************/
