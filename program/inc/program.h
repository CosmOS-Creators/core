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
#include "sysDefs.h"
#include "cosmosTypes.h"
#include "memoryMapping.h"
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
  * @}
  * Macros_program_h
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
  * @}
  * Variables_program_h
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
  * @}
  * Getters_program_h
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
  * @}
  * Setters_program_h
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
  * @}
  * General_program_h
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
  * *************************************************************************//**
  * @fn program_getProgramCoreId(CosmOS_ProgramVariableType * program)
  *
  * @brief Get program coreId.
  *
  * @param[in]  CosmOS_ProgramVariableType * program
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType program_getProgramCoreId(CosmOS_ProgramVariableType * program)
{
    return (program->cfg->coreId);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn program_getProgramNumberOfTasks(CosmOS_ProgramVariableType * program)
  *
  * @brief Get program numberOfTasks.
  *
  * @param[in]  CosmOS_ProgramVariableType * program
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType program_getProgramNumberOfTasks(CosmOS_ProgramVariableType * program)
{
    return (program->cfg->numberOfTasks);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn program_getProgramNumberOfThreads(CosmOS_ProgramVariableType * program)
  *
  * @brief Get program numberOfThreads.
  *
  * @param[in]  CosmOS_ProgramVariableType * program
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType program_getProgramNumberOfThreads(CosmOS_ProgramVariableType * program)
{
    return (program->cfg->numberOfThreads);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn program_getProgramMemorySize(CosmOS_ProgramVariableType * program)
  *
  * @brief Get program programMemorySize.
  *
  * @param[in]  CosmOS_ProgramVariableType * program
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType program_getProgramMemorySize(CosmOS_ProgramVariableType * program)
{
    return (program->cfg->programMemorySize);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn program_getProgramMemoryLowAddress(CosmOS_ProgramVariableType * program)
  *
  * @brief Get program programMemoryLowAddress.
  *
  * @param[in]  CosmOS_ProgramVariableType * program
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType program_getProgramMemoryLowAddress(CosmOS_ProgramVariableType * program)
{
    return (program->cfg->programMemoryLowAddress);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn program_getProgramMemoryHighAddress(CosmOS_ProgramVariableType * program)
  *
  * @brief Get program programMemoryHighAddress.
  *
  * @param[in]  CosmOS_ProgramVariableType * program
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType program_getProgramMemoryHighAddress(CosmOS_ProgramVariableType * program)
{
    return (program->cfg->programMemoryHighAddress);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn program_getHeap(CosmOS_ProgramVariableType * program)
  *
  * @brief Get program heap pointer.
  *
  * @param[in]  CosmOS_ProgramVariableType * program
  *
  * @return CosmOS_HeapConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_HeapConfigurationType * program_getHeap(CosmOS_ProgramVariableType * program)
{
    return (CosmOS_HeapConfigurationType *)(program->cfg->heap);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn program_getProgramHeapMutex(CosmOS_ProgramVariableType * program)
  *
  * @brief Get program programHeapMutex.
  *
  * @param[in]  CosmOS_ProgramVariableType * program
  *
  * @return CosmOS_MutexVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_MutexVariableType * program_getProgramHeapMutex(CosmOS_ProgramVariableType * program)
{
    return (CosmOS_MutexVariableType *)(program->cfg->heapMutex);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn program_getProgramTasks(CosmOS_ProgramVariableType * program)
  *
  * @brief Get program taskVars.
  *
  * @param[in]  CosmOS_ProgramVariableType * program
  *
  * @return CosmOS_TaskVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_TaskVariableType * program_getProgramTasks(CosmOS_ProgramVariableType * program)
{
    return (program->taskVars);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn program_getProgramTask(CosmOS_ProgramVariableType * program, BitWidthType taskIterator)
  *
  * @brief Get program taskVars element pointer.
  *
  * @param[in]  CosmOS_ProgramVariableType * program
  * @param[in]  BitWidthType taskIterator
  *
  * @return CosmOS_TaskVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_TaskVariableType * program_getProgramTask(CosmOS_ProgramVariableType * program, BitWidthType taskIterator)
{
    return (&(program->taskVars[taskIterator]));
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn program_getProgramThreads(CosmOS_ProgramVariableType * program)
  *
  * @brief Get program threadVars.
  *
  * @param[in]  CosmOS_ProgramVariableType * program
  *
  * @return CosmOS_ThreadVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_ThreadVariableType * program_getProgramThreads(CosmOS_ProgramVariableType * program)
{
    return (program->threadVars);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn program_getProgramThread(CosmOS_ProgramVariableType * program, BitWidthType threadIterator)
  *
  * @brief Get program threadVars element pointer.
  *
  * @param[in]  CosmOS_ProgramVariableType * program
  * @param[in]  BitWidthType threadIterator
  *
  * @return CosmOS_ThreadVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_ThreadVariableType * program_getProgramThread(CosmOS_ProgramVariableType * program, BitWidthType threadIterator)
{
    return (&(program->threadVars[threadIterator]));
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn program_getProgramNumberOfMallocVars(CosmOS_ProgramVariableType * program)
  *
  * @brief Get program numberOfMallocVars.
  *
  * @param[in]  CosmOS_ProgramVariableType * program
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType program_getProgramNumberOfMallocVars(CosmOS_ProgramVariableType * program)
{
    return (program->numberOfMallocVars);
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Getters_program_h
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
  * *************************************************************************//**
  * @fn program_setProgramNumberOfMallocVars(CosmOS_ProgramVariableType * program, BitWidthType numberOfMallocVarsParam)
  *
  * @brief Set program numberOfMallocVars.
  *
  * @param[in]  CosmOS_ProgramVariableType * program
  * @param[in]  BitWidthType numberOfMallocVarsParam
	*
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void program_setProgramNumberOfMallocVars(CosmOS_ProgramVariableType * program, BitWidthType numberOfMallocVarsParam)
{
    program->numberOfMallocVars = numberOfMallocVarsParam;
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Setters_program_h
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
  * @}
  * General_program_h
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
