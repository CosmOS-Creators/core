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
  * @fn memoryManager_stackInit(CosmOS_CoreConfigurationType * core)
  *
  * @details The implementation contains obtaining of the number of programs
  * by calling core_getCoreNumberOfPrograms function with current core variable.
  * Then the for loop is implemented to iterate over all configured programs.
  * In the for loop is implemented the core_getCoreProgramCfg call to get
  * current program variable and subsequently call to the function
  * program_getProgramNumberOfThreads to get number of threads configured
  * under specific program. Then the nested for loop is implemented that
  * iterates over all threads under the specific program variable and
  * first of all obtains thread variable by calling program_getProgramThread
  * then is this thread variable used to get schedulable variable by calling
  * function thread_getThreadSchedulable because it is needed as an argument
  * for the stack initialization function stackInit_schedulableStackInit that
  * is called subsequently. After this point the stack pointer is stored to the
  * schedulable structure by calling schedulable_setStackPointer.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
memoryManager_stackInit( CosmOS_CoreConfigurationType * core )
{
    BitWidthType numberOfThreads, numberOfPrograms, stackPointerRetVal;

    CosmOS_ThreadConfigurationType * threadCfg;
    CosmOS_ProgramConfigurationType * programCfg;

    numberOfPrograms = core_getCoreNumberOfPrograms( core );

    for ( BitWidthType programIterator = 0; programIterator < numberOfPrograms;
          programIterator++ )
    {
        programCfg = core_getCoreProgramCfg( core, programIterator );
        numberOfThreads = program_getProgramNumberOfThreads( programCfg );

        for ( BitWidthType threadIterator = 0; threadIterator < numberOfThreads;
              threadIterator++ )
        {
            CosmOS_SchedulableConfigurationType * schedulableCfg;

            threadCfg = program_getProgramThread( programCfg, threadIterator );
            schedulableCfg = thread_getThreadSchedulable( threadCfg );

            stackPointerRetVal =
                stackInit_schedulableStackInit( schedulableCfg );
            schedulable_setStackPointer( schedulableCfg, stackPointerRetVal );
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
  * @fn memoryManager_heapInit(CosmOS_CoreConfigurationType * core)
  *
  * @details The implementation contains obtaining of the program variables by
  * callling the core_getCoreProgramCfgs function and the number of programs
  * by calling core_getCoreNumberOfPrograms function with current core variable.
  * Then the for loop is implemented to iterate over all configured programs.
  * In the for loop is implemented if condition to check if the heap size is
  * non-zero value. Then the malloc variable is placed to the low address of the
  * current program heap as initialization before the heap will be used.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
memoryManager_heapInit( CosmOS_CoreConfigurationType * core )
{
    BitWidthType numberOfPrograms;

    CosmOS_ProgramConfigurationType * programCfgs;
    CosmOS_MallocVariableType * currentMallocVar;

    programCfgs = core_getCoreProgramCfgs( core );
    numberOfPrograms = core_getCoreNumberOfPrograms( core );

    for ( BitWidthType i = 0; i < numberOfPrograms; i++ )
    {
        if ( programCfgs[i].heap->heapSize )
        {
            currentMallocVar =
                (CosmOS_MallocVariableType *)programCfgs[i].heap->heapLowAddress;

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
