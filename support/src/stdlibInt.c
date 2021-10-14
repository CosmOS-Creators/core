/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file stdlibInt.c
*********************************************************************************
<!--               	  stdlibInt Unit Local Group Definition                   -->
*********************************************************************************
** @defgroup Local_stdlibInt Local
** @ingroup stdlibInt_unit
** @brief stdlibInt locals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "cosmosAssert.h"
#include "mutex.h"
#include "program.h"
#include "stdlibInt.h"
#include "core.h"
#include "heap.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
* DOXYGEN START GROUP                                                          **
* ***************************************************************************//**
* @defgroup Macros_stdlibInt_c Macros
* @ingroup Local_stdlibInt
* @{
********************************************************************************/
/********************************************************************************
* DOXYGEN STOP GROUP                                                           **
* ***************************************************************************//**
* @}
* Macros_stdlibInt_c
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Stop                           **
********************************************************************************/
/********************************************************************************
**                              Variables | Start                              **
********************************************************************************/
/********************************************************************************
* DOXYGEN START GROUP                                                          **
* ***************************************************************************//**
* @defgroup Variables_stdlibInt_c Variables
* @ingroup Local_stdlibInt
* @{
********************************************************************************/
/********************************************************************************
* DOXYGEN STOP GROUP                                                           **
* ***************************************************************************//**
* @}
* Variables_stdlibInt_c
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
* @defgroup Apis_stdlibInt_c API's
* @ingroup Local_stdlibInt
********************************************************************************/
/********************************************************************************
* DOXYGEN START GROUP                                                          **
* ***************************************************************************//**
* @addtogroup Getters_stdlibInt_c Getters
* @ingroup Apis_stdlibInt_c
* @{
********************************************************************************/
/********************************************************************************
* DOXYGEN STOP GROUP                                                           **
* ***************************************************************************//**
* @}
* Getters_stdlibInt_c
********************************************************************************/
/********************************************************************************
* DOXYGEN START GROUP                                                          **
* ***************************************************************************//**
* @addtogroup Setters_stdlibInt_c Setters
* @ingroup Apis_stdlibInt_c
* @{
********************************************************************************/
/********************************************************************************
* DOXYGEN STOP GROUP                                                           **
* ***************************************************************************//**
* @}
* Setters_stdlibInt_c
********************************************************************************/
/********************************************************************************
* DOXYGEN START GROUP                                                          **
* ***************************************************************************//**
* @addtogroup General_stdlibInt_c General
* @ingroup Apis_stdlibInt_c
* @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn malloc_varAlloc( AddressType nextAvailableAddress, AddressType priorMallocAddress,
  * 					 AddressType nextMallocAddress, BitWidthType size )
  *
  * @brief Malloc support function.
  *
  * @param[in]  AddressType nextAvailableAddress
  * @param[in]  AddressType priorMallocAddress
  * @param[in]  AddressType nextMallocAddress
  * @param[in]  BitWidthType size
  *
  * @return CosmOS_MallocVariableType *
********************************************************************************/
static CosmOS_MallocVariableType * malloc_varAlloc( AddressType nextAvailableAddress, AddressType priorMallocAddress,\
													AddressType nextMallocAddress, BitWidthType size );
/********************************************************************************
* DOXYGEN STOP GROUP                                                           **
* ***************************************************************************//**
* @}
* General_stdlibInt_c
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
  * @fn malloc_varAlloc( AddressType nextAvailableAddress, AddressType priorMallocAddress,
  * 					 AddressType nextMallocAddress, BitWidthType size )
  *
  * @brief Malloc support function for initializing malloc variable.
  *
  * @param[in]  AddressType nextAvailableAddress
  * @param[in]  AddressType priorMallocAddress
  * @param[in]  AddressType nextMallocAddress
  * @param[in]  BitWidthType size
  *
  * @return CosmOS_MallocVariableType *
********************************************************************************/
static CosmOS_MallocVariableType * malloc_varAlloc( AddressType nextAvailableAddress, AddressType priorMallocAddress,\
													AddressType nextMallocAddress, BitWidthType size )
{
	CosmOS_MallocVariableType * newMallocVar = (CosmOS_MallocVariableType *)nextAvailableAddress;

	newMallocVar->prior = (CosmOS_MallocVariableType *)priorMallocAddress;
	newMallocVar->next = (CosmOS_MallocVariableType *)nextMallocAddress;
	newMallocVar->size = ((BitWidthType)ALIGN(sizeof(CosmOS_MallocVariableType),sizeof(BitWidthType)) + \
							(BitWidthType)ALIGN(size,sizeof(BitWidthType)));

	return newMallocVar;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn malloc_internal( size_t size )
  *
  * @brief Stdlib malloc function implementation redesigned for CosmOS DEMO.
  *
  * @param[in]  size_t size
  *
  * @return void *
********************************************************************************/
void *malloc_internal(size_t size)
{
	AddressType heapLowAddress,
				heapHighAddress,
				nextAvailableAddress,
				returnAddress;
	CosmOS_BooleanType allocated;

	CosmOS_MutexStateType mutexState;

	CosmOS_CoreVariableType *coreVar;
	CosmOS_ProgramVariableType *programVar;
	CosmOS_HeapConfigurationType *heapCfg;
	CosmOS_MallocVariableType *currentMallocVar,
								*newMallocVar;


	coreVar = core_getCoreVar();
	returnAddress = (AddressType)NULL;

	if ( coreVar->schedulableInExecution->cfg->instanceType IS_EQUAL_TO SCHEDULABLE_INSTANCE_ENUM__THREAD )
	{

		programVar = core_getCoreProgramInExecution(coreVar);

		heapCfg = program_getHeap(programVar);

		heapLowAddress = heap_getHeapLowAddress(heapCfg);
		heapHighAddress = heap_getHeapHighAddress(heapCfg);

		allocated = False;
		currentMallocVar = (CosmOS_MallocVariableType *)heapLowAddress;

		mutexState = mutex_getMutex(programVar->cfg->heapMutex);

		//TODO: this assertion cannot be here cause it will in the future disable ISRs - so only os can call it in privileged context
		cosmosAssert(mutexState IS_EQUAL_TO MUTEX_STATE_ENUM__SUCCESSFULLY_LOCKED);

		do
		{
			if (currentMallocVar->next IS_NOT_EQUAL_TO NULL)
			{
				nextAvailableAddress = (AddressType)currentMallocVar + (AddressType)currentMallocVar->size;
				if (size < ((AddressType)currentMallocVar->next - nextAvailableAddress))
				{
					newMallocVar = malloc_varAlloc(nextAvailableAddress,
													(AddressType)currentMallocVar,
													(AddressType)currentMallocVar->next,
													size);

					((CosmOS_MallocVariableType *)currentMallocVar->next)->prior = newMallocVar;
					currentMallocVar->next = newMallocVar;

					returnAddress = (AddressType)newMallocVar +
									(AddressType)ALIGN(sizeof(CosmOS_MallocVariableType), sizeof(BitWidthType));
					allocated = True;
				}
				else
				{
					currentMallocVar = currentMallocVar->next;
				}
			}
			else
			{
				nextAvailableAddress = (AddressType)currentMallocVar + (AddressType)currentMallocVar->size;
				if (size < (heapHighAddress - nextAvailableAddress))
				{
					newMallocVar = malloc_varAlloc(nextAvailableAddress,
													(AddressType)currentMallocVar,
													(AddressType)NULL,
													size);

					currentMallocVar->next = newMallocVar;

					returnAddress = (AddressType)newMallocVar +
									(AddressType)ALIGN(sizeof(CosmOS_MallocVariableType), sizeof(BitWidthType));
					allocated = True;
				}
			}
		} while (currentMallocVar->next AND IS_NOT(allocated));

		mutexState = mutex_releaseMutex(programVar->cfg->heapMutex);

		//TODO: this assertion cannot be here cause it will in the future disable ISRs - so only os can call it in privileged context
		cosmosAssert(mutexState IS_EQUAL_TO MUTEX_STATE_ENUM__RELEASED);
	}

	return (void *)returnAddress;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn free_internal( void* ptr )
  *
  * @brief Stdlib free function implementation redesigned for CosmOS DEMO.
  *
  * @param[in]  void * ptr
  *
  * @return none
********************************************************************************/
void free_internal(void *ptr)
{
	CosmOS_MutexStateType mutexState;

	CosmOS_CoreVariableType *coreVar;
	CosmOS_ProgramVariableType *programVar;

	CosmOS_MallocVariableType *mallocVarToFree =
	(CosmOS_MallocVariableType *)((AddressType)ptr - ALIGN(sizeof(CosmOS_MallocVariableType), sizeof(BitWidthType)));


	coreVar = core_getCoreVar();
	if ( coreVar->schedulableInExecution->cfg->instanceType IS_EQUAL_TO SCHEDULABLE_INSTANCE_ENUM__THREAD )
	{
		//TODO: check if the pointer is one of the allocated heap variables
		programVar = core_getCoreProgramInExecution(coreVar);

		mutexState = mutex_getMutex(programVar->cfg->heapMutex);

		//TODO: this assertion cannot be here cause it will in the future disable ISRs - so only os can call it in privileged context
		cosmosAssert(mutexState IS_EQUAL_TO MUTEX_STATE_ENUM__SUCCESSFULLY_LOCKED);

		if (mallocVarToFree->prior)
		{
			((CosmOS_MallocVariableType *)mallocVarToFree->prior)->next =
				mallocVarToFree->next ? mallocVarToFree->next : NULL;
		}

		if (mallocVarToFree->next)
		{
			((CosmOS_MallocVariableType *)mallocVarToFree->next)->prior =
				mallocVarToFree->prior ? mallocVarToFree->prior : NULL;
		}

		mutexState = mutex_releaseMutex(programVar->cfg->heapMutex);

		//TODO: this assertion cannot be here cause it will in the future disable ISRs - so only os can call it in privileged context
		cosmosAssert(mutexState IS_EQUAL_TO MUTEX_STATE_ENUM__RELEASED);
	}
}
/********************************************************************************
**                        Function Definitions | Stop                          **
********************************************************************************/
/********************************************************************************
**                           END OF THE SOURCE FILE                            **
********************************************************************************/
