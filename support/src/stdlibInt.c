/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file stdlibInt.c
*********************************************************************************
<!--                  stdlibInt Unit Local Group Definition                   -->
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
#include "stdlibInt.h"
#include "core.h"
#include "cosmosAssert.h"
#include "heap.h"
#include "mutex.h"
#include "program.h"

/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_stdlibInt_c Macros
  * @ingroup Local_stdlibInt
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_stdlibInt_c
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
  * @defgroup Variables_stdlibInt_c Variables
  * @ingroup Local_stdlibInt
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_stdlibInt_c
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
  * @defgroup Apis_stdlibInt_c API's
  * @ingroup Local_stdlibInt
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_stdlibInt_c Getters
  * @ingroup Apis_stdlibInt_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_stdlibInt_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_stdlibInt_c Setters
  * @ingroup Apis_stdlibInt_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_stdlibInt_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_stdlibInt_c General
  * @ingroup Apis_stdlibInt_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn malloc_varAlloc( AddressType nextAvailableAddress,
  * AddressType priorMallocAddress,
  * AddressType nextMallocAddress,
  * BitWidthType size )
  *
  * @brief Malloc support function.
  *
  * @param[in]  nextAvailableAddress
  * @param[in]  priorMallocAddress
  * @param[in]  nextMallocAddress
  * @param[in]  size
  *
  * @return CosmOS_MallocVariableType *
********************************************************************************/
static CosmOS_MallocVariableType *
malloc_varAlloc(
    AddressType nextAvailableAddress,
    AddressType priorMallocAddress,
    AddressType nextMallocAddress,
    BitWidthType size );
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_stdlibInt_c
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
  * @fn malloc_varAlloc(AddressType nextAvailableAddress,
  * AddressType priorMallocAddress,
  * AddressType nextMallocAddress,
  * BitWidthType size )
  *
  * @details The implementation contains creation of the new pointer of malloc
  * variable type based on the next available address argument. The members of
  * the malloc variable are then set based on the arguments and size is aligned
  * to the BitWidthType (size contains aligned size of the malloc variable and
  * then aligned size of the allocated memory)
********************************************************************************/
static CosmOS_MallocVariableType *
malloc_varAlloc(
    AddressType nextAvailableAddress,
    AddressType priorMallocAddress,
    AddressType nextMallocAddress,
    BitWidthType size )
{
    CosmOS_MallocVariableType * newMallocVar =
        (CosmOS_MallocVariableType *)nextAvailableAddress;

    newMallocVar->prior = (CosmOS_MallocVariableType *)priorMallocAddress;
    newMallocVar->next = (CosmOS_MallocVariableType *)nextMallocAddress;
    newMallocVar->size =
        ( (BitWidthType)ALIGN(
              sizeof( CosmOS_MallocVariableType ), sizeof( BitWidthType ) ) +
          (BitWidthType)ALIGN( size, sizeof( BitWidthType ) ) );

    return newMallocVar;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn malloc_internal( size_t size )
  *
  * @details The implementation contains obtaining of the core variable by
  * calling function core_getCoreVar. The return address is set to NULL in the
  * case no suitable memory chunk will be found (to return NULL pointer).
  * Schedulable in execution type is then checked in the implemented if
  * condition if it is equal to the SCHEDULABLE_INSTANCE_ENUM__THREAD, if yes
  * the program variable in execution is obtained by calling function
  * core_getCoreProgramInExecution and used to get the heap configuration
  * structure by calling program_getHeap function. Then the heap configuration
  * structure is used in the functions heap_getHeapLowAddress and
  * heap_getHeapHighAddress to get the heap low and high adresses. The
  * pre-initialization before the do-while loop is needed therefore allocated
  * boolean variable is preset to the False and currentMallocVar pointer is set
  * to the heap low address. Because the heap allocation can be requested from
  * multiple threads within one program the mutual exclusion is needed and
  * mutex_getMutex function is called with the program specific mutex variable.
  * After this point the do-while loop is implemented iterating over the linked
  * list of the mutex variables till the currentMallocVar next member is not
  * null pointer or till the allocated boolean is not true. Inside the do-while
  * loop is if condition that checks if the currentMallocVar next member is not
  * NULL - nextAvailableAddress is as the currentMallocVar plus its size member
  * and checked in the nested if condition if the required size argument is
  * smaller than currentMallocVar next member address minus the
  * nextAvailableAddress variable. If no the currentMallocVar is set to the
  * currentMallocVar next member. If yes the new malloc variable is allocated
  * by calling malloc_varAlloc helper function and the result is then used to
  * linked it between the currentMallocVar and the next malloc variable. Then
  * to the returnAddress is stored the newly allocated address with the respect
  * to the aligned malloc variable offset and allocated boolean variable is set
  * to True.
  * If the currentMallocVar next member is was NULL, it means that its the end
  * of the linked list. The nextAvailableAddress is then calculated as the
  * currentMallocVar plus its size member and checked in the nested if condition
  * if the required size argument is smaller than heap high address minus the
  * nextAvailableAddress variable. If yes the new malloc variable is allocated
  * by calling malloc_varAlloc helper function and the result is then used to
  * linked it to the currentMallocVar. Then to the returnAddress is stored the
  * newly allocated address with the respect to the aligned malloc variable
  * offset and allocated boolean variable is set to True.
  * In the end the mutex for the specific program is released and the address
  * returned.
********************************************************************************/
void *
malloc_internal( size_t size )
{
    AddressType heapLowAddress, heapHighAddress, nextAvailableAddress,
        returnAddress;
    CosmOS_BooleanType allocated;

    CosmOS_MutexStateType mutexState;

    CosmOS_CoreConfigurationType * coreCfg;
    CosmOS_ProgramConfigurationType * programCfg;
    CosmOS_HeapConfigurationType * heapCfg;
    CosmOS_MallocVariableType *currentMallocVar, *newMallocVar;

    coreCfg = core_getCoreVar();
    returnAddress = (AddressType)NULL;

    if ( ( (CosmOS_SchedulableConfigurationType *)
               coreCfg->var->schedulableInExecution )
             ->instanceType IS_EQUAL_TO SCHEDULABLE_INSTANCE_ENUM__THREAD )
    {
        programCfg = core_getCoreProgramInExecution( coreCfg );

        heapCfg = program_getHeap( programCfg );

        heapLowAddress = heap_getHeapLowAddress( heapCfg );
        heapHighAddress = heap_getHeapHighAddress( heapCfg );

        allocated = False;
        currentMallocVar = (CosmOS_MallocVariableType *)heapLowAddress;

        mutexState = mutex_getMutex( programCfg->heapMutex );

        /*TODO: this assertion cannot be here cause it will in the
        future disable ISRs - so only os can call it in privileged context */
        cosmosAssert(
            mutexState IS_EQUAL_TO MUTEX_STATE_ENUM__SUCCESSFULLY_LOCKED );

        do
        {
            if ( currentMallocVar->next IS_NOT_EQUAL_TO NULL )
            {
                nextAvailableAddress = (AddressType)currentMallocVar +
                                       (AddressType)currentMallocVar->size;
                if ( size < ( (AddressType)currentMallocVar->next -
                              nextAvailableAddress ) )
                {
                    newMallocVar = malloc_varAlloc(
                        nextAvailableAddress,
                        (AddressType)currentMallocVar,
                        (AddressType)currentMallocVar->next,
                        size );

                    ( (CosmOS_MallocVariableType *)currentMallocVar->next )
                        ->prior = newMallocVar;
                    currentMallocVar->next = newMallocVar;

                    returnAddress = (AddressType)newMallocVar +
                                    (AddressType)ALIGN(
                                        sizeof( CosmOS_MallocVariableType ),
                                        sizeof( BitWidthType ) );
                    allocated = True;
                }
                else
                {
                    currentMallocVar = currentMallocVar->next;
                }
            }
            else
            {
                nextAvailableAddress = (AddressType)currentMallocVar +
                                       (AddressType)currentMallocVar->size;
                if ( size < ( heapHighAddress - nextAvailableAddress ) )
                {
                    newMallocVar = malloc_varAlloc(
                        nextAvailableAddress,
                        (AddressType)currentMallocVar,
                        (AddressType)NULL,
                        size );

                    currentMallocVar->next = newMallocVar;

                    returnAddress = (AddressType)newMallocVar +
                                    (AddressType)ALIGN(
                                        sizeof( CosmOS_MallocVariableType ),
                                        sizeof( BitWidthType ) );
                    allocated = True;
                }
            }
        } while ( currentMallocVar->next AND IS_NOT( allocated ) );

        mutexState = mutex_releaseMutex( programCfg->heapMutex );

        /*TODO: this assertion cannot be here cause it will in the
        future disable ISRs - so only os can call it in privileged context */
        cosmosAssert( mutexState IS_EQUAL_TO MUTEX_STATE_ENUM__RELEASED );
    }

    return (void *)returnAddress;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn free_internal( void* ptr )
  *
  * @details The implementation contains obtaining of the mallocVarToFree by
  * subtracting the aligned size of the malloc variable type from the ptr
  * argument. Then the core variable is obtained by calling function
  * core_getCoreVar.
  * Schedulable in execution type is then checked in the implemented if
  * condition if it is equal to the SCHEDULABLE_INSTANCE_ENUM__THREAD, if yes
  * the program variable in execution is obtained by calling function
  * core_getCoreProgramInExecution. Because the heap allocation can be requested
  * from multiple threads within one program the mutual exclusion is needed and
  * mutex_getMutex function is called with the program specific mutex variable.
  * Then the malloc variable to free is unlinked from the list and the mutex for
  * the specific program is released.
********************************************************************************/
void
free_internal( void * ptr )
{
    CosmOS_MutexStateType mutexState;

    CosmOS_CoreConfigurationType * coreCfg;
    CosmOS_ProgramConfigurationType * programCfg;

    CosmOS_MallocVariableType * mallocVarToFree =
        (CosmOS_MallocVariableType *)( (AddressType)ptr - ALIGN( sizeof( CosmOS_MallocVariableType ), sizeof( BitWidthType ) ) );

    coreCfg = core_getCoreVar();
    if ( ( (CosmOS_SchedulableConfigurationType *)
               coreCfg->var->schedulableInExecution )
             ->instanceType IS_EQUAL_TO SCHEDULABLE_INSTANCE_ENUM__THREAD )
    {
        //TODO: check if the pointer is one of the allocated heap variables
        programCfg = core_getCoreProgramInExecution( coreCfg );

        mutexState = mutex_getMutex( programCfg->heapMutex );

        /*TODO: this assertion cannot be here cause it will in the
        future disable ISRs - so only os can call it in privileged context */
        cosmosAssert(
            mutexState IS_EQUAL_TO MUTEX_STATE_ENUM__SUCCESSFULLY_LOCKED );

        if ( mallocVarToFree->prior )
        {
            ( (CosmOS_MallocVariableType *)mallocVarToFree->prior )->next =
                mallocVarToFree->next ? mallocVarToFree->next : NULL;
        }

        if ( mallocVarToFree->next )
        {
            ( (CosmOS_MallocVariableType *)mallocVarToFree->next )->prior =
                mallocVarToFree->prior ? mallocVarToFree->prior : NULL;
        }

        mutexState = mutex_releaseMutex( programCfg->heapMutex );

        /*TODO: this assertion cannot be here cause it will in the
        future disable ISRs - so only os can call it in privileged context */
        cosmosAssert( mutexState IS_EQUAL_TO MUTEX_STATE_ENUM__RELEASED );
    }
}
/********************************************************************************
**                        Function Definitions | Stop                          **
********************************************************************************/
/********************************************************************************
**                           END OF THE SOURCE FILE                            **
********************************************************************************/
