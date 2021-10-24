/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file memoryManager.c
*********************************************************************************
<!--                memoryManager Unit Local Group Definition                 -->
*********************************************************************************
** @defgroup Local_memoryManager Local
** @ingroup memoryManager_unit
** @brief memoryManager locals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "memoryManager.h"
#include "core.h"
#include "program.h"
#include "schedulable.h"
#include "stackInit.h"
#include "thread.h"

/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_memoryManager_c Macros
  * @ingroup Local_memoryManager
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_memoryManager_c
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
  * @defgroup Variables_memoryManager_c Variables
  * @ingroup Local_memoryManager
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_memoryManager_c
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
  * @defgroup Apis_memoryManager_c API's
  * @ingroup Local_memoryManager
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_memoryManager_c Getters
  * @ingroup Apis_memoryManager_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_memoryManager_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_memoryManager_c Setters
  * @ingroup Apis_memoryManager_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_memoryManager_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_memoryManager_c General
  * @ingroup Apis_memoryManager_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_memoryManager_c
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
  * @fn memoryManager_stackInit(CosmOS_CoreVariableType * coreVar)
  *
  * @brief Stack intialization for all thread schedulables.
  *
  * @param[in] CosmOS_CoreVariableType * coreVar
  *
  * @return none
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
memoryManager_stackInit( CosmOS_CoreVariableType * coreVar )
{
    BitWidthType numberOfThreads, numberOfPrograms, stackPointerRetVal;

    CosmOS_ThreadVariableType * threadVar;
    CosmOS_ProgramVariableType * programVar;

    numberOfPrograms = core_getCoreNumberOfPrograms( coreVar );

    for ( BitWidthType programIterator = 0; programIterator < numberOfPrograms;
          programIterator++ )
    {
        programVar = core_getCoreProgramVar( coreVar, programIterator );
        numberOfThreads = program_getProgramNumberOfThreads( programVar );

        for ( BitWidthType threadIterator = 0; threadIterator < numberOfThreads;
              threadIterator++ )
        {
            CosmOS_SchedulableVariableType * schedulableVar;

            threadVar = program_getProgramThread( programVar, threadIterator );
            schedulableVar = thread_getThreadSchedulable( threadVar );

            stackPointerRetVal =
                stackInit_schedulableStackInit( schedulableVar );
            schedulable_setStackPointer( schedulableVar, stackPointerRetVal );
        }
    }
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn memoryManager_heapInit(void)
  *
  * @brief Heap init function DEMO implementation.
  *
  * @param[in] CosmOS_CoreVariableType * coreVar
  *
  * @return none
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
memoryManager_heapInit( CosmOS_CoreVariableType * coreVar )
{
    BitWidthType numberOfPrograms;

    CosmOS_ProgramVariableType * programVars;
    CosmOS_MallocVariableType * currentMallocVar;

    programVars = core_getCoreProgramVars( coreVar );
    numberOfPrograms = core_getCoreNumberOfPrograms( coreVar );

    for ( BitWidthType i = 0; i < numberOfPrograms; i++ )
    {
        if ( programVars[i].cfg->heap->heapSize )
        {
            currentMallocVar = (CosmOS_MallocVariableType *)programVars[i]
                                   .cfg->heap->heapLowAddress;

            currentMallocVar->prior = NULL;
            currentMallocVar->next = NULL;
            currentMallocVar->size = (BitWidthType)ALIGN(
                sizeof( CosmOS_MallocVariableType ), sizeof( BitWidthType ) );
        }
    }
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
