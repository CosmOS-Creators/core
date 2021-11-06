/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file program.h
*********************************************************************************
<!--                      program Module Group Definition                     -->
*********************************************************************************
** @defgroup program_module program
** @brief program Module
** @details lorem
*********************************************************************************
<!--                       program Unit Group Definition                      -->
*********************************************************************************
** @defgroup program_unit program Unit
** @ingroup program_module
** @brief program Unit
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
<!--                    program Unit Global Group Definition                  -->
*********************************************************************************
** @defgroup Global_program Global
** @ingroup program_unit
** @brief program globals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __PROGRAM_H__
#define __PROGRAM_H__
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
  * @defgroup Macros_program_h Macros
  * @ingroup Global_program
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_program_h
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
  * @defgroup Variables_program_h Variables
  * @ingroup Global_program
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_program_h
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
  * @defgroup Apis_program_h API's
  * @ingroup Global_program
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_program_h Getters
  * @ingroup Apis_program_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_program_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_program_h Setters
  * @ingroup Apis_program_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_program_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_program_h General
  * @ingroup Apis_program_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_program_h
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
  * @addtogroup Getters_program_h Getters
  * @ingroup Apis_program_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn program_getProgramCoreId(CosmOS_ProgramVariableType * program)
  *
  * @brief Get program coreId.
  *
  * @param[in]  program pointer to the program variable
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
program_getProgramCoreId( CosmOS_ProgramVariableType * program )
{
    return ( program->cfg->coreId );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn program_getProgramNumberOfTasks(CosmOS_ProgramVariableType * program)
  *
  * @brief Get program numberOfTasks.
  *
  * @param[in]  program pointer to the program variable
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
program_getProgramNumberOfTasks( CosmOS_ProgramVariableType * program )
{
    return ( program->cfg->numberOfTasks );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn program_getProgramNumberOfThreads(CosmOS_ProgramVariableType * program)
  *
  * @brief Get program numberOfThreads.
  *
  * @param[in]  program pointer to the program variable
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
program_getProgramNumberOfThreads( CosmOS_ProgramVariableType * program )
{
    return ( program->cfg->numberOfThreads );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn program_getProgramMemorySize(CosmOS_ProgramVariableType * program)
  *
  * @brief Get program programMemorySize.
  *
  * @param[in]  program pointer to the program variable
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
program_getProgramMemorySize( CosmOS_ProgramVariableType * program )
{
    return ( program->cfg->programMemorySize );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn program_getProgramMemoryLowAddress(CosmOS_ProgramVariableType * program)
  *
  * @brief Get program programMemoryLowAddress.
  *
  * @param[in]  program pointer to the program variable
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
program_getProgramMemoryLowAddress( CosmOS_ProgramVariableType * program )
{
    return ( program->cfg->programMemoryLowAddress );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn program_getProgramMemoryHighAddress(CosmOS_ProgramVariableType * program)
  *
  * @brief Get program programMemoryHighAddress.
  *
  * @param[in]  program pointer to the program variable
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
program_getProgramMemoryHighAddress( CosmOS_ProgramVariableType * program )
{
    return ( program->cfg->programMemoryHighAddress );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn program_getHeap(CosmOS_ProgramVariableType * program)
  *
  * @brief Get program heap pointer.
  *
  * @param[in]  program pointer to the program variable
  *
  * @return CosmOS_HeapConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_HeapConfigurationType *
program_getHeap( CosmOS_ProgramVariableType * program )
{
    return (CosmOS_HeapConfigurationType *)( program->cfg->heap );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn program_getProgramHeapMutex(CosmOS_ProgramVariableType * program)
  *
  * @brief Get program programHeapMutex.
  *
  * @param[in]  program pointer to the program variable
  *
  * @return CosmOS_MutexVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_MutexVariableType *
program_getProgramHeapMutex( CosmOS_ProgramVariableType * program )
{
    return (CosmOS_MutexVariableType *)( program->cfg->heapMutex );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn program_getProgramTasks(CosmOS_ProgramVariableType * program)
  *
  * @brief Get program taskCfgs.
  *
  * @param[in]  program pointer to the program variable
  *
  * @return CosmOS_TaskConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_TaskConfigurationType *
program_getProgramTasks( CosmOS_ProgramVariableType * program )
{
    return (CosmOS_TaskConfigurationType *)( program->taskCfgs );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn program_getProgramTask(CosmOS_ProgramVariableType * program,
  * BitWidthType taskIterator)
  *
  * @brief Get program taskCfgs element pointer.
  *
  * @param[in]  program pointer to the program variable
  * @param[in]  BitWidthType taskIterator
  *
  * @return CosmOS_TaskConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_TaskConfigurationType *
program_getProgramTask(
    CosmOS_ProgramVariableType * program,
    BitWidthType taskIterator )
{
    return (CosmOS_TaskConfigurationType *)( &( program->taskCfgs[taskIterator] ) );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn program_getProgramThreads(CosmOS_ProgramVariableType * program)
  *
  * @brief Get program threadCfgs.
  *
  * @param[in]  program pointer to the program variable
  *
  * @return CosmOS_ThreadConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_ThreadConfigurationType *
program_getProgramThreads( CosmOS_ProgramVariableType * program )
{
    return (CosmOS_ThreadConfigurationType *)( program->threadCfgs );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn program_getProgramThread(CosmOS_ProgramVariableType * program,
  * BitWidthType threadIterator)
  *
  * @brief Get program threadCfgs element pointer.
  *
  * @param[in]  program pointer to the program variable
  * @param[in]  BitWidthType threadIterator
  *
  * @return CosmOS_ThreadConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_ThreadConfigurationType *
program_getProgramThread(
    CosmOS_ProgramVariableType * program,
    BitWidthType threadIterator )
{
    return (CosmOS_ThreadConfigurationType *)( &( program->threadCfgs[threadIterator] ) );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn program_getProgramNumberOfMallocVars(
  * CosmOS_ProgramVariableType * program)
  *
  * @brief Get program numberOfMallocVars.
  *
  * @param[in]  program pointer to the program variable
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
program_getProgramNumberOfMallocVars( CosmOS_ProgramVariableType * program )
{
    return ( program->numberOfMallocVars );
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_program_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_program_h Setters
  * @ingroup Apis_program_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn program_setProgramNumberOfMallocVars(
  * CosmOS_ProgramVariableType * program,
  * BitWidthType numberOfMallocVarsParam)
  *
  * @brief Set program numberOfMallocVars. This function cannot be called
  * from the unprivileged context directly.
  *
  * @param[out]  program pointer to the program variable
  * @param[in]  numberOfMallocVarsParam number of malloc variables to set
  * for current program
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
program_setProgramNumberOfMallocVars(
    CosmOS_ProgramVariableType * program,
    BitWidthType numberOfMallocVarsParam )
{
    program->numberOfMallocVars = numberOfMallocVarsParam;
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_program_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_program_h General
  * @ingroup Apis_program_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_program_h
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
