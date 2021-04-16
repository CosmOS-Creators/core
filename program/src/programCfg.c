/********************************************************************************
**                                                                             **
**                       GENERATED FILE BY COSMOS CustomBox                    **
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
#include "threadCfg.h"
#include "taskCfg.h"
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
		{
        CORE_0_ID,                                      /* const BitWidthType coreId                            */
        TASK_PROGRAM_0_CORE_0_NUM,                      /* const BitWidthType numberOfTasks                     */
        THREAD_PROGRAM_0_CORE_0_NUM,                      /* const BitWidthType numberOfThreads                     */
        PROGRAM_0_CORE_0_SIZE,                      /* const BitWidthType programMemorySize                     */
        PROGRAM_0_CORE_0_LOW_ADDRESS,                      /* const AddressType programMemoryLowAddress                     */
        PROGRAM_0_CORE_0_HIGH_ADDRESS,                      /* const AddressType programMemoryHighAddress                     */
    },
		{
        CORE_0_ID,                                      /* const BitWidthType coreId                            */
        TASK_PROGRAM_1_CORE_0_NUM,                      /* const BitWidthType numberOfTasks                     */
        THREAD_PROGRAM_1_CORE_0_NUM,                      /* const BitWidthType numberOfThreads                     */
        PROGRAM_1_CORE_0_SIZE,                      /* const BitWidthType programMemorySize                     */
        PROGRAM_1_CORE_0_LOW_ADDRESS,                      /* const AddressType programMemoryLowAddress                     */
        PROGRAM_1_CORE_0_HIGH_ADDRESS,                      /* const AddressType programMemoryHighAddress                     */
    },
};
const CosmOS_ProgramConfigurationType ProgramsCore1CfgConst[PROGRAM_CORE_1_NUM] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		{
        CORE_1_ID,                                      /* const BitWidthType coreId                            */
        TASK_PROGRAM_0_CORE_1_NUM,                      /* const BitWidthType numberOfTasks                     */
        THREAD_PROGRAM_0_CORE_1_NUM,                      /* const BitWidthType numberOfThreads                     */
        PROGRAM_0_CORE_1_SIZE,                      /* const BitWidthType programMemorySize                     */
        PROGRAM_0_CORE_1_LOW_ADDRESS,                      /* const AddressType programMemoryLowAddress                     */
        PROGRAM_0_CORE_1_HIGH_ADDRESS,                      /* const AddressType programMemoryHighAddress                     */
    },
		{
        CORE_1_ID,                                      /* const BitWidthType coreId                            */
        TASK_PROGRAM_1_CORE_1_NUM,                      /* const BitWidthType numberOfTasks                     */
        THREAD_PROGRAM_1_CORE_1_NUM,                      /* const BitWidthType numberOfThreads                     */
        PROGRAM_1_CORE_1_SIZE,                      /* const BitWidthType programMemorySize                     */
        PROGRAM_1_CORE_1_LOW_ADDRESS,                      /* const AddressType programMemoryLowAddress                     */
        PROGRAM_1_CORE_1_HIGH_ADDRESS,                      /* const AddressType programMemoryHighAddress                     */
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
		{
        &ProgramsCore0CfgConst[PROGRAM_0_CORE_0_ID],    /* const CosmOS_ProgramConfigurationType * cfg                       */
        TasksProgram0Core0Var,                          /* CosmOS_TaskVariableType * taskVars                                */
        ThreadsProgram0Core0Var,                          /* CosmOS_ThreadVariableType * threadVars                                */
    },
		{
        &ProgramsCore0CfgConst[PROGRAM_1_CORE_0_ID],    /* const CosmOS_ProgramConfigurationType * cfg                       */
        TasksProgram1Core0Var,                          /* CosmOS_TaskVariableType * taskVars                                */
        ThreadsProgram1Core0Var,                          /* CosmOS_ThreadVariableType * threadVars                                */
    },
};
CosmOS_ProgramVariableType ProgramsCore1Var[PROGRAM_CORE_1_NUM] __OS_VAR_SECTION
IS_INITIALIZED_TO
{
		{
        &ProgramsCore1CfgConst[PROGRAM_0_CORE_1_ID],    /* const CosmOS_ProgramConfigurationType * cfg                       */
        TasksProgram0Core1Var,                          /* CosmOS_TaskVariableType * taskVars                                */
        ThreadsProgram0Core1Var,                          /* CosmOS_ThreadVariableType * threadVars                                */
    },
		{
        &ProgramsCore1CfgConst[PROGRAM_1_CORE_1_ID],    /* const CosmOS_ProgramConfigurationType * cfg                       */
        TasksProgram1Core1Var,                          /* CosmOS_TaskVariableType * taskVars                                */
        ThreadsProgram1Core1Var,                          /* CosmOS_ThreadVariableType * threadVars                                */
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