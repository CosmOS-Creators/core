/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file task.h
*********************************************************************************
<!--                       task Module Group Definition                       -->
*********************************************************************************  
** @defgroup task_module task
** @brief task Module
** @details lorem   	 		
*********************************************************************************	
<!--                        task Unit Group Definition                        -->
********************************************************************************* 
** @defgroup task_unit task Unit 
** @ingroup task_module        
** @brief task Unit 
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
<!--                      task Unit Global Group Definition                   -->
*********************************************************************************
** @defgroup Global_task Global
** @ingroup task_unit 
** @brief task globals
** @details lorem  
********************************************************************************/
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __TASK_H__
#define __TASK_H__
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
#include "CosmOSTypesStd.h"
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
  * @defgroup Macros_task_h Macros
  * @ingroup Global_task  
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Macros_task_h  
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
  * @defgroup Variables_task_h Variables  
  * @ingroup Global_task  
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Variables_task_h  
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
  * @defgroup Apis_task_h API's 
  * @ingroup Global_task
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_task_h Getters  
  * @ingroup Apis_task_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}       
  * Getters_task_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_task_h Setters  
  * @ingroup Apis_task_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn task_setExecutionStateToFinished(void) 
  * 
  * @brief Set task execution state to finished DEMO CODE.
  * 
  * @param[in]  none
  * 
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void task_setExecutionStateToFinished(void);
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}    
  * Setters_task_h   
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_task_h General  
  * @ingroup Apis_task_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_task_h  
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
  * @addtogroup Getters_task_h Getters  
  * @ingroup Apis_task_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn task_getTaskStack(CosmOS_TaskVariableType *task) 
  * 
  * @brief Get task stack pointer.
  * 
  * @param[in]  CosmOS_TaskVariableType * task
  * 
  * @return CosmOS_StackConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_StackConfigurationType * task_getTaskStack(CosmOS_TaskVariableType * task)
{
    return (CosmOS_StackConfigurationType *)(task->cfg->stack);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn task_getTaskHandler(CosmOS_TaskVariableType *task) 
  * 
  * @brief Get task handler.
  * 
  * @param[in]  CosmOS_TaskVariableType * task
  * 
  * @return CosmOS_HandlerType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_HandlerType task_getTaskHandler(CosmOS_TaskVariableType * task)
{
    return (task->cfg->handler);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn task_getTaskId(CosmOS_TaskVariableType *task) 
  * 
  * @brief Get task id.
  * 
  * @param[in]  CosmOS_TaskVariableType * task
  * 
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType task_getTaskId(CosmOS_TaskVariableType * task)
{
    return (task->cfg->id);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn task_getTaskWcet(CosmOS_TaskVariableType *task) 
  * 
  * @brief Get task wcet.
  * 
  * @param[in]  CosmOS_TaskVariableType * task
  * 
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType task_getTaskWcet(CosmOS_TaskVariableType * task)
{
    return (task->cfg->wcet);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn task_getTaskProgramId(CosmOS_TaskVariableType *task) 
  * 
  * @brief Get task programId.
  * 
  * @param[in]  CosmOS_TaskVariableType * task
  * 
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType task_getTaskProgramId(CosmOS_TaskVariableType * task)
{
    return (task->cfg->programId);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn task_getTaskCoreId(CosmOS_TaskVariableType *task) 
  * 
  * @brief Get task coreId.
  * 
  * @param[in]  CosmOS_TaskVariableType * task
  * 
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType task_getTaskCoreId(CosmOS_TaskVariableType * task)
{
    return (task->cfg->coreId);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn task_getTaskStackVar(CosmOS_TaskVariableType *task) 
  * 
  * @brief Get task stackVar pointer.
  * 
  * @param[in]  CosmOS_TaskVariableType * task
  * 
  * @return CosmOS_StackVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_StackVariableType * task_getTaskStackVar(CosmOS_TaskVariableType * task)
{
    return (task->stackVar);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn task_getTaskStackPointer(CosmOS_TaskVariableType * task) 
  * 
  * @brief Get task stackPointer.
  * 
  * @param[in]  CosmOS_TaskVariableType * task
  * 
  * @return StackPointerType
********************************************************************************/
__STATIC_FORCEINLINE StackPointerType task_getTaskStackPointer(CosmOS_TaskVariableType * task)
{
    return (task->stackPointer);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn task_getTaskState(CosmOS_TaskVariableType * task) 
  * 
  * @brief Get task taskState.
  * 
  * @param[in]  CosmOS_TaskVariableType * task
  * 
  * @return CosmOS_TaskStateType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_TaskStateType task_getTaskState(CosmOS_TaskVariableType * task)
{
    return (task->taskState);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn task_getTaskExecutionState(CosmOS_TaskVariableType * task) 
  * 
  * @brief Get task executionState.
  * 
  * @param[in]  CosmOS_TaskVariableType * task
  * 
  * @return CosmOS_TaskExecutionStateType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_TaskExecutionStateType task_getTaskExecutionState(CosmOS_TaskVariableType * task)
{
    return (task->executionState);
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}       
  * Getters_task_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_task_h Setters  
  * @ingroup Apis_task_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn task_setTaskStackPointer(CosmOS_TaskVariableType * task, StackPointerType stackPointerParam) 
  * 
  * @brief Set task stackPointer.
  * 
  * @param[in]  CosmOS_TaskVariableType * task
  * @param[in]  StackPointerType stackPointerParam
  * 
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void task_setTaskStackPointer(CosmOS_TaskVariableType * task, StackPointerType stackPointerParam)
{
    task->stackPointer = stackPointerParam;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn task_setTaskState(CosmOS_TaskVariableType * task, CosmOS_TaskStateType taskStateParam) 
  * 
  * @brief Set task taskState.
  * 
  * @param[in]  CosmOS_TaskVariableType * task
  * @param[in]  CosmOS_TaskStateType taskStateParam
  * 
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void task_setTaskState(CosmOS_TaskVariableType * task, CosmOS_TaskStateType taskStateParam)
{
    task->taskState = taskStateParam;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn task_setTaskExecutionState(CosmOS_TaskVariableType * task, CosmOS_TaskExecutionStateType executionStateParam) 
  * 
  * @brief Set task executionState.
  * 
  * @param[in]  CosmOS_TaskVariableType * task
  * @param[in]  CosmOS_TaskExecutionStateType executionStateParam
  * 
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void task_setTaskExecutionState(CosmOS_TaskVariableType * task, CosmOS_TaskExecutionStateType executionStateParam)
{
    task->executionState = executionStateParam;
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}    
  * Setters_task_h   
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_task_h General  
  * @ingroup Apis_task_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_task_h  
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