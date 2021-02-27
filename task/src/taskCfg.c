/********************************************************************************
**                                                                             **
**                       GENERATED FILE BY TiCOS CustomBox                     **
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
#include "stackCfg.h"
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
const TiC_TaskConfigurationType TasksProgram0Core0CfgConst[TASK_PROGRAM_0_CORE_0_NUM] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		{                                                                 /* TasksProgram0Core0CfgConst[TASK_0_PROGRAM_0_CORE_0_ID]   */
        &TasksStacksCfgConst[STACK_TASK_0_PROGRAM_0_CORE_0_ID],       /* const TiC_StackConfigurationType * stack                 */
        Task_0_Core_0_Handler,                                        /* const TiC_HandlerType handler                            */
        TASK_0_PROGRAM_0_CORE_0_ID,                                   /* const BitWidthType id                                    */
        TASK_0_PROGRAM_0_CORE_0_WCET,                                 /* const BitWidthType wcet                                  */
        PROGRAM_0_CORE_0_ID,                                          /* const BitWidthType programId                             */
        CORE_0_ID,                                                    /* const BitWidthType coreId                                */
    },
};
const TiC_TaskConfigurationType TasksProgram0Core1CfgConst[TASK_PROGRAM_0_CORE_1_NUM] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		{                                                                 /* TasksProgram0Core1CfgConst[TASK_0_PROGRAM_0_CORE_1_ID]   */
        &TasksStacksCfgConst[STACK_TASK_0_PROGRAM_0_CORE_1_ID],       /* const TiC_StackConfigurationType * stack                 */
        Task_0_Core_1_Handler,                                        /* const TiC_HandlerType handler                            */
        TASK_0_PROGRAM_0_CORE_1_ID,                                   /* const BitWidthType id                                    */
        TASK_0_PROGRAM_0_CORE_1_WCET,                                 /* const BitWidthType wcet                                  */
        PROGRAM_0_CORE_1_ID,                                          /* const BitWidthType programId                             */
        CORE_1_ID,                                                    /* const BitWidthType coreId                                */
    },
};
/* @cond S */
__SEC_STOP(__OS_CONST_SECTION_STOP)
/* @endcond*/

/* @cond S */
__SEC_START(__OS_VAR_SECTION_START)
/* @endcond*/
TiC_TaskVariableType TasksProgram0Core0Var[TASK_PROGRAM_0_CORE_0_NUM] __OS_VAR_SECTION
IS_INITIALIZED_TO 
{
		{                                                                 /* TasksProgram0Core0Var[TASK_0_PROGRAM_0_CORE_0_ID]        */
        &TasksProgram0Core0CfgConst[TASK_0_PROGRAM_0_CORE_0_ID],      /* const TiC_TaskConfigurationType * cfg                    */
        &TasksStacksVar[STACK_TASK_0_PROGRAM_0_CORE_0_ID],            /* TiC_StackVariableType * stackVar                         */
        STACK_TASK_0_PROGRAM_0_CORE_0_HIGH_ADDRESS,                   /* StackPointerType stackPointer                            */
    },
};
TiC_TaskVariableType TasksProgram0Core1Var[TASK_PROGRAM_0_CORE_1_NUM] __OS_VAR_SECTION
IS_INITIALIZED_TO 
{
		{                                                                 /* TasksProgram0Core1Var[TASK_0_PROGRAM_0_CORE_1_ID]        */
        &TasksProgram0Core1CfgConst[TASK_0_PROGRAM_0_CORE_1_ID],      /* const TiC_TaskConfigurationType * cfg                    */
        &TasksStacksVar[STACK_TASK_0_PROGRAM_0_CORE_1_ID],            /* TiC_StackVariableType * stackVar                         */
        STACK_TASK_0_PROGRAM_0_CORE_1_HIGH_ADDRESS,                   /* StackPointerType stackPointer                            */
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
