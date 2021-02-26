/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file CosmOSTypesVar.h                                      
*********************************************************************************	
<!--                     CosmOSTypesVar Unit Group Definition                    -->
********************************************************************************* 
** @defgroup CosmOSTypesVar_unit CosmOSTypesVar Unit 
** @ingroup CosmOSTypes_module        
** @brief CosmOSTypesVar Unit 
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
<!--                CosmOSTypesVar Unit Global Group Definition                  -->
*********************************************************************************	
** @defgroup Global_CosmOSTypesVar Global
** @ingroup CosmOSTypesVar_unit 
** @brief CosmOSTypesVar globals
** @details lorem 
********************************************************************************/ 
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __TICTYPESVAR_H__
#define __TICTYPESVAR_H__
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
#include "CosmOSTypesCfg.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_CosmOSTypesVar_h Macros
  * @ingroup Global_CosmOSTypesVar  
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Macros_CosmOSTypesVar_h  
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Stop                           **
********************************************************************************/
/********************************************************************************
**                              Typedefs | Start                               **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Typedefs_CosmOSTypesVarCfg_h Typedefs
  * @ingroup Global_CosmOSTypesVar  
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_TaskVariableType struct type
********************************************************************************/
typedef struct
{
    CosmOS_BarrierStateType barrierState;
    
} CosmOS_BarrierVariableType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_BufferVariableType struct type
********************************************************************************/
typedef struct
{
    const CosmOS_BufferConfigurationType * const cfg;
    BitWidthType head;
    BitWidthType tail;
    BitWidthType fullCells;

} CosmOS_BufferVariableType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_TaskVariableType struct type
********************************************************************************/
typedef struct
{
    const CosmOS_StackConfigurationType * const cfg;
    
} CosmOS_StackVariableType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_TaskVariableType struct type
********************************************************************************/
typedef struct
{
    const CosmOS_TaskConfigurationType * const cfg;
    CosmOS_StackVariableType * const stackVar;
    StackPointerType stackPointer;
    
} CosmOS_TaskVariableType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_ThreadVariableType struct type
********************************************************************************/
typedef struct
{
    const CosmOS_ThreadConfigurationType * const cfg;
    CosmOS_StackVariableType * const stackVar;
    StackPointerType stackPointer;
    
} CosmOS_ThreadVariableType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_ProgramVariableType struct type
********************************************************************************/
typedef struct
{
    const CosmOS_ProgramConfigurationType * const cfg;
    CosmOS_ThreadVariableType * threadInCurrentContext;
    CosmOS_TaskVariableType * taskInCurrentContext;
    CosmOS_RunningInstanceType runningInstance;
    CosmOS_ThreadVariableType * const threadVars;
    CosmOS_TaskVariableType * const taskVars;

} CosmOS_ProgramVariableType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_ScheduleTableVariableType struct type
********************************************************************************/
typedef struct
{
    CosmOS_TaskVariableType * const task;

} CosmOS_ScheduleTableVariableType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_ScheduleTableVariableType struct type
********************************************************************************/
typedef struct
{
    CosmOS_ThreadVariableType * const thread;

} CosmOS_SchedulerThreadListVariableType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_SchedulerVariableType struct type
********************************************************************************/
typedef struct
{
    const CosmOS_SchedulerConfigurationType * const cfg;
    BitWidthType currentTick;
    BitWidthType scheduleTableIterator;
    CosmOS_ScheduleTableVariableType * const scheduleTableVar;
    CosmOS_SchedulerThreadListVariableType * const threadListVar;
    BitWidthType threadListIterator;

} CosmOS_SchedulerVariableType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_CoreVariableType struct type
********************************************************************************/
typedef struct
{
    const CosmOS_CoreConfigurationType * const cfg;
    CosmOS_ProgramVariableType * programInCurrentContext;
    CosmOS_ProgramVariableType * const programVars;
    CosmOS_SchedulerVariableType * const schedulerVar;
    CosmOS_BarrierVariableType * const barrierVars;

} CosmOS_CoreVariableType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_OsVariableType struct type
********************************************************************************/
typedef struct
{
    const CosmOS_OsConfigurationType * const cfg;
    CosmOS_CoreVariableType * const coreVars;
    CosmOS_BufferVariableType * const bufferVars;
    
} CosmOS_OsVariableType;
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Typedefs_CosmOSTypesVar_h  
********************************************************************************/
/********************************************************************************
**                              Typedefs | Stop                                **
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