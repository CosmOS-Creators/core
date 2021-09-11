/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file stdlib.c
*********************************************************************************
<!--               	    stdlib Unit Local Group Definition                    -->
*********************************************************************************
** @defgroup Local_stdlib Local
** @ingroup stdlib_unit
** @brief stdlib locals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "sysCalls.h"
#include "spinlock.h"
#include "program.h"
#include "stdlib.h"
#include "core.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
* DOXYGEN START GROUP                                                          **
* ***************************************************************************//**
* @defgroup Macros_stdlib_c Macros
* @ingroup Local_stdlib
* @{
********************************************************************************/
/********************************************************************************
* DOXYGEN STOP GROUP                                                           **
* ***************************************************************************//**
* @}
* Macros_stdlib_c
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
* @defgroup Variables_stdlib_c Variables
* @ingroup Local_stdlib
* @{
********************************************************************************/
/********************************************************************************
* DOXYGEN STOP GROUP                                                           **
* ***************************************************************************//**
* @}
* Variables_stdlib_c
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
* @defgroup Apis_stdlib_c API's
* @ingroup Local_stdlib
********************************************************************************/
/********************************************************************************
* DOXYGEN START GROUP                                                          **
* ***************************************************************************//**
* @addtogroup Getters_stdlib_c Getters
* @ingroup Apis_stdlib_c
* @{
********************************************************************************/
/********************************************************************************
* DOXYGEN STOP GROUP                                                           **
* ***************************************************************************//**
* @}
* Getters_stdlib_c
********************************************************************************/
/********************************************************************************
* DOXYGEN START GROUP                                                          **
* ***************************************************************************//**
* @addtogroup Setters_stdlib_c Setters
* @ingroup Apis_stdlib_c
* @{
********************************************************************************/
/********************************************************************************
* DOXYGEN STOP GROUP                                                           **
* ***************************************************************************//**
* @}
* Setters_stdlib_c
********************************************************************************/
/********************************************************************************
* DOXYGEN START GROUP                                                          **
* ***************************************************************************//**
* @addtogroup General_stdlib_c General
* @ingroup Apis_stdlib_c
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
* General_stdlib_c
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
	newMallocVar->size = (ALIGN(sizeof(CosmOS_MallocVariableType),sizeof(AddressType)) + \
							(AddressType)ALIGN(size,sizeof(AddressType)));

	return newMallocVar;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn malloc( size_t size )
  *
  * @brief Stdlib malloc function implementation redesigned for CosmOS DEMO.
  *
  * @param[in]  size_t size
  *
  * @return void *
********************************************************************************/
void *malloc(size_t size)
{
	BitWidthType getSpinlockRouteId,
					releaseSpinlockRouteId;
	AddressType heapLowAddress,
				heapHighAddress,
				nextAvailableAddress,
				returnAddress;
	CosmOS_BooleanType allocated,
						lastItem;

	CosmOS_SpinlockStateType spinlockState;

	CosmOS_CoreVariableType *coreVar;
	CosmOS_ProgramVariableType *programVar;
	CosmOS_MallocVariableType *currentMallocVar,
								*newMallocVar;


	coreVar = core_getCoreVar();

	programVar = core_getCoreProgramInExecution(coreVar);

	heapLowAddress = program_getProgramHeapLowAddress(programVar);
	heapHighAddress = program_getProgramHeapHighAddress(programVar);

	getSpinlockRouteId = program_getProgramHeapGetSpinlockRouteId(programVar);
	releaseSpinlockRouteId = program_getProgramHeapReleaseSpinlockRouteId(programVar);

	allocated = False;
	lastItem = False;
	currentMallocVar = (CosmOS_MallocVariableType *)heapLowAddress;
	returnAddress = (AddressType)NULL;

	spinlockState = (CosmOS_SpinlockStateType)sysCalls_bitWidthType_ret_bitWidthType(getSpinlockRouteId);

	while (IS_NOT(lastItem) __OR IS_NOT(allocated))
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
								(AddressType)ALIGN(sizeof(CosmOS_MallocVariableType), sizeof(AddressType));
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
								(AddressType)ALIGN(sizeof(CosmOS_MallocVariableType), sizeof(AddressType));
				allocated = True;
			}
			lastItem = True;
		}
	}

	spinlockState = (CosmOS_SpinlockStateType)sysCalls_bitWidthType_ret_bitWidthType(releaseSpinlockRouteId);

	__SUPRESS_UNUSED_VAR(spinlockState);

	return (void *)returnAddress;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn free( void* ptr )
  *
  * @brief Stdlib free function implementation redesigned for CosmOS DEMO.
  *
  * @param[in]  void * ptr
  *
  * @return none
********************************************************************************/
void free(void *ptr)
{
	BitWidthType getSpinlockRouteId,
					releaseSpinlockRouteId;
	CosmOS_SpinlockStateType spinlockState;

	CosmOS_CoreVariableType *coreVar;
	CosmOS_ProgramVariableType *programVar;

	CosmOS_MallocVariableType *mallocVarToFree =
	(CosmOS_MallocVariableType *)((AddressType)ptr - ALIGN(sizeof(CosmOS_MallocVariableType), sizeof(AddressType)));


	coreVar = core_getCoreVar();

	programVar = core_getCoreProgramInExecution(coreVar);

	getSpinlockRouteId = program_getProgramHeapGetSpinlockRouteId(programVar);
	releaseSpinlockRouteId = program_getProgramHeapReleaseSpinlockRouteId(programVar);

	spinlockState = (CosmOS_SpinlockStateType)sysCalls_bitWidthType_ret_bitWidthType(getSpinlockRouteId);

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

	spinlockState = (CosmOS_SpinlockStateType)sysCalls_bitWidthType_ret_bitWidthType(releaseSpinlockRouteId);

	__SUPRESS_UNUSED_VAR(spinlockState);
}
/********************************************************************************
**                        Function Definitions | Stop                          **
********************************************************************************/
/********************************************************************************
**                           END OF THE SOURCE FILE                            **
********************************************************************************/
