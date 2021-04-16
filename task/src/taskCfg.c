/********************************************************************************
**                                                                             **
**                       GENERATED FILE BY COSMOS CustomBox                    **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file taskCfg.c
*********************************************************************************
<!--                   taskCfg Unit Local Group Definition                    -->
*********************************************************************************	
** @defgroup Local_taskCfg Local
** @ingroup taskCfg_unit 
** @brief taskCfg locals
** @details lorem 
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "taskCfg.h"
#include "schedulableCfg.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_taskCfg_c Macros
  * @ingroup Local_taskCfg
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Macros_taskCfg_c  
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
  * @defgroup Variables_taskCfg_c Variables  
  * @ingroup Local_taskCfg
  * @{    
********************************************************************************/
/* @cond S */
__SEC_START(__OS_CONST_SECTION_START)
/* @endcond*/
const CosmOS_TaskConfigurationType TasksProgram0Core0CfgConst[TASK_PROGRAM_0_CORE_0_NUM] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		{
        TASK_0_PROGRAM_0_CORE_0_WCET,                                 /* const BitWidthType wcet                                  */
    },
		{
        TASK_1_PROGRAM_0_CORE_0_WCET,                                 /* const BitWidthType wcet                                  */
    },
};
const CosmOS_TaskConfigurationType TasksProgram1Core0CfgConst[TASK_PROGRAM_1_CORE_0_NUM] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		{
        TASK_0_PROGRAM_1_CORE_0_WCET,                                 /* const BitWidthType wcet                                  */
    },
};
const CosmOS_TaskConfigurationType TasksProgram0Core1CfgConst[TASK_PROGRAM_0_CORE_1_NUM] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		{
        TASK_0_PROGRAM_0_CORE_1_WCET,                                 /* const BitWidthType wcet                                  */
    },
		{
        TASK_1_PROGRAM_0_CORE_1_WCET,                                 /* const BitWidthType wcet                                  */
    },
};
const CosmOS_TaskConfigurationType TasksProgram1Core1CfgConst[TASK_PROGRAM_1_CORE_1_NUM] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		{
        TASK_0_PROGRAM_1_CORE_1_WCET,                                 /* const BitWidthType wcet                                  */
    },
};
/* @cond S */
__SEC_STOP(__OS_CONST_SECTION_STOP)
/* @endcond*/

/* @cond S */
__SEC_START(__OS_VAR_SECTION_START)
/* @endcond*/
CosmOS_TaskVariableType TasksProgram0Core0Var[TASK_PROGRAM_0_CORE_0_NUM] __OS_VAR_SECTION
IS_INITIALIZED_TO 
{
		{
        &TasksProgram0Core0CfgConst[TASK_0_PROGRAM_0_CORE_0_ID],      /* const CosmOS_TaskConfigurationType * cfg                    */
        &TasksSchedulablesVar[SCHEDULABLE_TASK_0_PROGRAM_0_CORE_0_ID],            /* CosmOS_SchedulableVariableType * const schedulable                       */ 
    },
		{
        &TasksProgram0Core0CfgConst[TASK_1_PROGRAM_0_CORE_0_ID],      /* const CosmOS_TaskConfigurationType * cfg                    */
        &TasksSchedulablesVar[SCHEDULABLE_TASK_1_PROGRAM_0_CORE_0_ID],            /* CosmOS_SchedulableVariableType * const schedulable                       */ 
    },
};
CosmOS_TaskVariableType TasksProgram1Core0Var[TASK_PROGRAM_1_CORE_0_NUM] __OS_VAR_SECTION
IS_INITIALIZED_TO 
{
		{
        &TasksProgram1Core0CfgConst[TASK_0_PROGRAM_1_CORE_0_ID],      /* const CosmOS_TaskConfigurationType * cfg                    */
        &TasksSchedulablesVar[SCHEDULABLE_TASK_0_PROGRAM_1_CORE_0_ID],            /* CosmOS_SchedulableVariableType * const schedulable                       */ 
    },
};
CosmOS_TaskVariableType TasksProgram0Core1Var[TASK_PROGRAM_0_CORE_1_NUM] __OS_VAR_SECTION
IS_INITIALIZED_TO 
{
		{
        &TasksProgram0Core1CfgConst[TASK_0_PROGRAM_0_CORE_1_ID],      /* const CosmOS_TaskConfigurationType * cfg                    */
        &TasksSchedulablesVar[SCHEDULABLE_TASK_0_PROGRAM_0_CORE_1_ID],            /* CosmOS_SchedulableVariableType * const schedulable                       */ 
    },
		{
        &TasksProgram0Core1CfgConst[TASK_1_PROGRAM_0_CORE_1_ID],      /* const CosmOS_TaskConfigurationType * cfg                    */
        &TasksSchedulablesVar[SCHEDULABLE_TASK_1_PROGRAM_0_CORE_1_ID],            /* CosmOS_SchedulableVariableType * const schedulable                       */ 
    },
};
CosmOS_TaskVariableType TasksProgram1Core1Var[TASK_PROGRAM_1_CORE_1_NUM] __OS_VAR_SECTION
IS_INITIALIZED_TO 
{
		{
        &TasksProgram1Core1CfgConst[TASK_0_PROGRAM_1_CORE_1_ID],      /* const CosmOS_TaskConfigurationType * cfg                    */
        &TasksSchedulablesVar[SCHEDULABLE_TASK_0_PROGRAM_1_CORE_1_ID],            /* CosmOS_SchedulableVariableType * const schedulable                       */ 
    },
};
/* @cond S */
__SEC_STOP(__OS_VAR_SECTION_STOP)
/* @endcond*/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Variables_taskCfg_c  
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
  * @defgroup Apis_taskCfg_c API's  
  * @ingroup Local_taskCfg
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_taskCfg_c Getters  
  * @ingroup Apis_taskCfg_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}       
  * Getters_taskCfg_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_taskCfg_c Setters  
  * @ingroup Apis_taskCfg_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}    
  * Setters_taskCfg_c   
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_taskCfg_c General  
  * @ingroup Apis_taskCfg_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_taskCfg_c  
********************************************************************************/
/********************************************************************************
**                         Function Prototypes | Stop                          **
********************************************************************************/
/********************************************************************************
**                        Function Definitions | Start                         **
********************************************************************************/
/********************************************************************************
**                        Function Definitions | Stop                          **
********************************************************************************/
/********************************************************************************
**                           END OF THE SOURCE FILE                            **
********************************************************************************/
