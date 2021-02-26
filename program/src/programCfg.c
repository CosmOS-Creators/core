/********************************************************************************
**                                                                             **
**                       GENERATED FILE BY CosmOS CustomBox                    **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file programCfg.c
*********************************************************************************
<!--                  programCfg Unit Local Group Definition                  -->
*********************************************************************************	
** @defgroup Local_programCfg Local
** @ingroup programCfg_unit 
** @brief programCfg locals
** @details lorem 
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "programCfg.h"
#include "taskCfg.h"
#include "threadCfg.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_programCfg_c Macros
  * @ingroup Local_programCfg
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Macros_programCfg_c  
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
  * @defgroup Variables_programCfg_c Variables  
  * @ingroup Local_programCfg
  * @{    
********************************************************************************/
/* @cond S */
__SEC_START(__OS_CONST_SECTION_START)
/* @endcond*/
const CosmOS_ProgramConfigurationType ProgramsCore0CfgConst[PROGRAM_CORE_0_NUM] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
{                                                   /* ProgramsCore0CfgConst[PROGRAM_0_CORE_0_ID]           */
        TasksProgram0Core0CfgConst,                     /* const CosmOS_TaskConfigurationType * tasks              */
        ThreadsProgram0Core0CfgConst,                   /* const CosmOS_ThreadConfigurationType * threads          */
        CORE_0_ID,                                      /* const BitWidthType coreId                            */
        TASK_PROGRAM_0_CORE_0_NUM,                      /* const BitWidthType numberOfTasks                     */
        THREAD_PROGRAM_0_CORE_0_NUM,                    /* const BitWidthType numberOfThreads                   */                     
    },


};

const CosmOS_ProgramConfigurationType ProgramsCore1CfgConst[PROGRAM_CORE_1_NUM] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
{                                                   /* ProgramsCore1CfgConst[PROGRAM_0_CORE_1_ID]           */
        TasksProgram0Core1CfgConst,                     /* const CosmOS_TaskConfigurationType * tasks              */
        ThreadsProgram0Core1CfgConst,                   /* const CosmOS_ThreadConfigurationType * threads          */
        CORE_1_ID,                                      /* const BitWidthType coreId                            */
        TASK_PROGRAM_0_CORE_1_NUM,                      /* const BitWidthType numberOfTasks                     */
        THREAD_PROGRAM_0_CORE_1_NUM,                    /* const BitWidthType numberOfThreads                   */                     
    },


};


/* @cond S */
__SEC_STOP(__OS_CONST_SECTION_STOP)
/* @endcond*/

/* @cond S */
__SEC_START(__OS_VAR_SECTION_START)
/* @endcond*/
CosmOS_ProgramVariableType ProgramsCore0Var[PROGRAM_CORE_0_NUM] __OS_VAR_SECTION
IS_INITIALIZED_TO
{
{                                                   /* ProgramsCore0Var[PROGRAM_0_CORE_0_ID]                          */
        &ProgramsCore0CfgConst[PROGRAM_0_CORE_0_ID],    /* const CosmOS_ProgramConfigurationType * cfg                       */
        NULL,                                           /* CosmOS_ThreadVariableType * threadInCurrentContext                */ 
        NULL,                                           /* CosmOS_TaskVariableType * taskInCurrentContext                    */      
        RUNNING_INSTANCE_ENUM__NOTHING,                 /* CosmOS_RunningInstanceType runningInstance                        */      
        ThreadsProgram0Core0Var,                        /* CosmOS_ThreadVariableType * threadVars                            */                       
        TasksProgram0Core0Var,                          /* CosmOS_TaskVariableType * taskVars                                */                        
    },


};

CosmOS_ProgramVariableType ProgramsCore1Var[PROGRAM_CORE_1_NUM] __OS_VAR_SECTION
IS_INITIALIZED_TO
{
{                                                   /* ProgramsCore0Var[PROGRAM_0_CORE_1_ID]                          */
        &ProgramsCore1CfgConst[PROGRAM_0_CORE_1_ID],    /* const CosmOS_ProgramConfigurationType * cfg                       */
        NULL,                                           /* CosmOS_ThreadVariableType * threadInCurrentContext                */ 
        NULL,                                           /* CosmOS_TaskVariableType * taskInCurrentContext                    */      
        RUNNING_INSTANCE_ENUM__NOTHING,                 /* CosmOS_RunningInstanceType runningInstance                        */      
        ThreadsProgram0Core1Var,                        /* CosmOS_ThreadVariableType * threadVars                            */                       
        TasksProgram0Core1Var,                          /* CosmOS_TaskVariableType * taskVars                                */                        
    },


};


/* @cond S */
__SEC_STOP(__OS_VAR_SECTION_STOP)
/* @endcond*/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Variables_programCfg_c  
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
  * @defgroup Apis_programCfg_c API's  
  * @ingroup Local_programCfg
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_programCfg_c Getters  
  * @ingroup Apis_programCfg_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}       
  * Getters_programCfg_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_programCfg_c Setters  
  * @ingroup Apis_programCfg_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}    
  * Setters_programCfg_c   
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_programCfg_c General  
  * @ingroup Apis_programCfg_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_programCfg_c  
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