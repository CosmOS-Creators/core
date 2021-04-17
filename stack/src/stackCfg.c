/********************************************************************************
**                                                                             **
**                       GENERATED FILE BY COSMOS CustomBox                    **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file stackCfg.c
*********************************************************************************
<!--                   stackCfg Unit Local Group Definition                   -->
*********************************************************************************	
** @defgroup Local_stackCfg Local
** @ingroup stackCfg_unit 
** @brief stackCfg locals
** @details lorem 
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
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
  * @defgroup Macros_stackCfg_c Macros
  * @ingroup Local_stackCfg
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Macros_stackCfg_c  
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
  * @defgroup Variables_stackCfg_c Variables  
  * @ingroup Local_stackCfg
  * @{    
********************************************************************************/
/* @cond S */
__SEC_START(__OS_CONST_SECTION_START)
/* @endcond*/
const CosmOS_StackConfigurationType KernelsStacksCfgConst[KERNEL_NUM] __OS_CONST_SECTION 
IS_INITIALIZED_TO
{
		{                                                     /* KernelsStacksCfgConst[STACK_KERNEL_0_CORE_0_ID]            */
        STACK_KERNEL_0_CORE_0_SIZE,                       /* const BitWidthType stackSize                               */
        STACK_KERNEL_0_CORE_0_LOW_ADDRESS,                /* const AddressType stackLowAddress                          */   
        STACK_KERNEL_0_CORE_0_HIGH_ADDRESS,               /* const AddressType stackHighAddress                         */  
    },   
		{                                                     /* KernelsStacksCfgConst[STACK_KERNEL_0_CORE_1_ID]            */
        STACK_KERNEL_0_CORE_1_SIZE,                       /* const BitWidthType stackSize                               */
        STACK_KERNEL_0_CORE_1_LOW_ADDRESS,                /* const AddressType stackLowAddress                          */   
        STACK_KERNEL_0_CORE_1_HIGH_ADDRESS,               /* const AddressType stackHighAddress                         */  
    },   
};

const CosmOS_StackConfigurationType TasksStacksCfgConst[TASK_NUM] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		{                                                     /* TasksStacksCfgConst[STACK_TASK_0_PROGRAM_0_CORE_0_ID]      */
        STACK_TASK_0_PROGRAM_0_CORE_0_SIZE,               /* const BitWidthType stackSize                               */
        STACK_TASK_0_PROGRAM_0_CORE_0_LOW_ADDRESS,        /* const AddressType stackLowAddress                          */
        STACK_TASK_0_PROGRAM_0_CORE_0_HIGH_ADDRESS,       /* const AddressType stackHighAddress                         */
    },
		{                                                     /* TasksStacksCfgConst[STACK_TASK_1_PROGRAM_0_CORE_0_ID]      */
        STACK_TASK_1_PROGRAM_0_CORE_0_SIZE,               /* const BitWidthType stackSize                               */
        STACK_TASK_1_PROGRAM_0_CORE_0_LOW_ADDRESS,        /* const AddressType stackLowAddress                          */
        STACK_TASK_1_PROGRAM_0_CORE_0_HIGH_ADDRESS,       /* const AddressType stackHighAddress                         */
    },
		{                                                     /* TasksStacksCfgConst[STACK_TASK_0_PROGRAM_1_CORE_0_ID]      */
        STACK_TASK_0_PROGRAM_1_CORE_0_SIZE,               /* const BitWidthType stackSize                               */
        STACK_TASK_0_PROGRAM_1_CORE_0_LOW_ADDRESS,        /* const AddressType stackLowAddress                          */
        STACK_TASK_0_PROGRAM_1_CORE_0_HIGH_ADDRESS,       /* const AddressType stackHighAddress                         */
    },
		{                                                     /* TasksStacksCfgConst[STACK_TASK_0_PROGRAM_0_CORE_1_ID]      */
        STACK_TASK_0_PROGRAM_0_CORE_1_SIZE,               /* const BitWidthType stackSize                               */
        STACK_TASK_0_PROGRAM_0_CORE_1_LOW_ADDRESS,        /* const AddressType stackLowAddress                          */
        STACK_TASK_0_PROGRAM_0_CORE_1_HIGH_ADDRESS,       /* const AddressType stackHighAddress                         */
    },
		{                                                     /* TasksStacksCfgConst[STACK_TASK_1_PROGRAM_0_CORE_1_ID]      */
        STACK_TASK_1_PROGRAM_0_CORE_1_SIZE,               /* const BitWidthType stackSize                               */
        STACK_TASK_1_PROGRAM_0_CORE_1_LOW_ADDRESS,        /* const AddressType stackLowAddress                          */
        STACK_TASK_1_PROGRAM_0_CORE_1_HIGH_ADDRESS,       /* const AddressType stackHighAddress                         */
    },
		{                                                     /* TasksStacksCfgConst[STACK_TASK_0_PROGRAM_1_CORE_1_ID]      */
        STACK_TASK_0_PROGRAM_1_CORE_1_SIZE,               /* const BitWidthType stackSize                               */
        STACK_TASK_0_PROGRAM_1_CORE_1_LOW_ADDRESS,        /* const AddressType stackLowAddress                          */
        STACK_TASK_0_PROGRAM_1_CORE_1_HIGH_ADDRESS,       /* const AddressType stackHighAddress                         */
    },
};

const CosmOS_StackConfigurationType ThreadsStacksCfgConst[THREAD_NUM] __OS_CONST_SECTION 
IS_INITIALIZED_TO
{
		{                                                     /* ThreadsStacksCfgConst[STACK_THREAD_0_PROGRAM_0_CORE_0_ID]  */
        STACK_THREAD_0_PROGRAM_0_CORE_0_SIZE,             /* const BitWidthType stackSize                               */
        STACK_THREAD_0_PROGRAM_0_CORE_0_LOW_ADDRESS,      /* const AddressType stackLowAddress                          */
        STACK_THREAD_0_PROGRAM_0_CORE_0_HIGH_ADDRESS,     /* const AddressType stackHighAddress                         */
    },
		{                                                     /* ThreadsStacksCfgConst[STACK_THREAD_0_PROGRAM_0_CORE_1_ID]  */
        STACK_THREAD_0_PROGRAM_0_CORE_1_SIZE,             /* const BitWidthType stackSize                               */
        STACK_THREAD_0_PROGRAM_0_CORE_1_LOW_ADDRESS,      /* const AddressType stackLowAddress                          */
        STACK_THREAD_0_PROGRAM_0_CORE_1_HIGH_ADDRESS,     /* const AddressType stackHighAddress                         */
    },
};
/* @cond S */
__SEC_STOP(__OS_CONST_SECTION_STOP)
/* @endcond*/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Variables_stackCfg_c  
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
  * @defgroup Apis_stackCfg_c API's  
  * @ingroup Local_stackCfg
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_stackCfg_c Getters  
  * @ingroup Apis_stackCfg_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}       
  * Getters_stackCfg_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_stackCfg_c Setters  
  * @ingroup Apis_stackCfg_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}    
  * Setters_stackCfg_c   
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_stackCfg_c General  
  * @ingroup Apis_stackCfg_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_stackCfg_c  
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
