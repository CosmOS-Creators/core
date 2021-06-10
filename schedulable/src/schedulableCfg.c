/********************************************************************************
**                                                                             **
**                       GENERATED FILE BY COSMOS CustomBox                    **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file schedulableCfg.c
*********************************************************************************
<!--                schedulableCfg Unit Local Group Definition                -->
*********************************************************************************	
** @defgroup Local_schedulableCfg Local
** @ingroup schedulableCfg_unit 
** @brief schedulableCfg locals
** @details lorem 
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "schedulableCfg.h"
#include "sysCalls.h"
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
  * @defgroup Macros_schedulableCfg_c Macros
  * @ingroup Local_schedulableCfg
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Macros_schedulableCfg_c  
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
  * @defgroup Variables_schedulableCfg_c Variables  
  * @ingroup Local_schedulableCfg
  * @{    
********************************************************************************/
/* @cond S */
__SEC_START(__OS_CONST_SECTION_START)
/* @endcond*/
const CosmOS_SchedulableConfigurationType TasksSchedulablesCfgConst[TASK_NUM] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		{
        &TasksStacksCfgConst[STACK_TASK_0_PROGRAM_0_CORE_0_ID],       /* const CosmOS_StackConfigurationType * stack                 */
        SCHEDULABLE_INSTANCE_ENUM__TASK,                              /* const CosmOS_SchedulableInstanceType instance                        */
        wrapped_Idle_CM7,                                        /* const CosmOS_HandlerType handler                            */
        False,                                                        /* const CosmOS_BooleanType fp                                          */
        SCHEDULABLE_0_UNIQUE_ID,                                          /* const BitWidthType id                                         */
        TASK_0_PROGRAM_0_CORE_0_ID,                                   /* const BitWidthType instanceId                                                */
        PROGRAM_0_CORE_0_ID,                                          /* const BitWidthType programId                                         */
        CORE_0_ID,                                                    /* const BitWidthType coreId                                            */
    },
		{
        &TasksStacksCfgConst[STACK_TASK_1_PROGRAM_0_CORE_0_ID],       /* const CosmOS_StackConfigurationType * stack                 */
        SCHEDULABLE_INSTANCE_ENUM__TASK,                              /* const CosmOS_SchedulableInstanceType instance                        */
        wrapped_sysJobs_CM7,                                        /* const CosmOS_HandlerType handler                            */
        False,                                                        /* const CosmOS_BooleanType fp                                          */
        SCHEDULABLE_1_UNIQUE_ID,                                          /* const BitWidthType id                                         */
        TASK_1_PROGRAM_0_CORE_0_ID,                                   /* const BitWidthType instanceId                                                */
        PROGRAM_0_CORE_0_ID,                                          /* const BitWidthType programId                                         */
        CORE_0_ID,                                                    /* const BitWidthType coreId                                            */
    },
		{
        &TasksStacksCfgConst[STACK_TASK_0_PROGRAM_1_CORE_0_ID],       /* const CosmOS_StackConfigurationType * stack                 */
        SCHEDULABLE_INSTANCE_ENUM__TASK,                              /* const CosmOS_SchedulableInstanceType instance                        */
        wrapped_Task_0_Core_0_Handler,                                        /* const CosmOS_HandlerType handler                            */
        False,                                                        /* const CosmOS_BooleanType fp                                          */
        SCHEDULABLE_3_UNIQUE_ID,                                          /* const BitWidthType id                                         */
        TASK_0_PROGRAM_1_CORE_0_ID,                                   /* const BitWidthType instanceId                                                */
        PROGRAM_1_CORE_0_ID,                                          /* const BitWidthType programId                                         */
        CORE_0_ID,                                                    /* const BitWidthType coreId                                            */
    },
		{
        &TasksStacksCfgConst[STACK_TASK_0_PROGRAM_0_CORE_1_ID],       /* const CosmOS_StackConfigurationType * stack                 */
        SCHEDULABLE_INSTANCE_ENUM__TASK,                              /* const CosmOS_SchedulableInstanceType instance                        */
        wrapped_Idle_CM4,                                        /* const CosmOS_HandlerType handler                            */
        False,                                                        /* const CosmOS_BooleanType fp                                          */
        SCHEDULABLE_4_UNIQUE_ID,                                          /* const BitWidthType id                                         */
        TASK_0_PROGRAM_0_CORE_1_ID,                                   /* const BitWidthType instanceId                                                */
        PROGRAM_0_CORE_1_ID,                                          /* const BitWidthType programId                                         */
        CORE_1_ID,                                                    /* const BitWidthType coreId                                            */
    },
		{
        &TasksStacksCfgConst[STACK_TASK_1_PROGRAM_0_CORE_1_ID],       /* const CosmOS_StackConfigurationType * stack                 */
        SCHEDULABLE_INSTANCE_ENUM__TASK,                              /* const CosmOS_SchedulableInstanceType instance                        */
        wrapped_sysJobs_CM4,                                        /* const CosmOS_HandlerType handler                            */
        False,                                                        /* const CosmOS_BooleanType fp                                          */
        SCHEDULABLE_5_UNIQUE_ID,                                          /* const BitWidthType id                                         */
        TASK_1_PROGRAM_0_CORE_1_ID,                                   /* const BitWidthType instanceId                                                */
        PROGRAM_0_CORE_1_ID,                                          /* const BitWidthType programId                                         */
        CORE_1_ID,                                                    /* const BitWidthType coreId                                            */
    },
		{
        &TasksStacksCfgConst[STACK_TASK_0_PROGRAM_1_CORE_1_ID],       /* const CosmOS_StackConfigurationType * stack                 */
        SCHEDULABLE_INSTANCE_ENUM__TASK,                              /* const CosmOS_SchedulableInstanceType instance                        */
        wrapped_Task_0_Core_1_Handler,                                        /* const CosmOS_HandlerType handler                            */
        False,                                                        /* const CosmOS_BooleanType fp                                          */
        SCHEDULABLE_7_UNIQUE_ID,                                          /* const BitWidthType id                                         */
        TASK_0_PROGRAM_1_CORE_1_ID,                                   /* const BitWidthType instanceId                                                */
        PROGRAM_1_CORE_1_ID,                                          /* const BitWidthType programId                                         */
        CORE_1_ID,                                                    /* const BitWidthType coreId                                            */
    },
};

const CosmOS_SchedulableConfigurationType ThreadsSchedulablesCfgConst[THREAD_NUM] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		{
        &ThreadsStacksCfgConst[STACK_THREAD_0_PROGRAM_0_CORE_0_ID],       /* const CosmOS_StackConfigurationType * stack                              */
        SCHEDULABLE_INSTANCE_ENUM__THREAD,                                /* const CosmOS_SchedulableInstanceType instance                            */
        wrapped_IdleThread_CM7,                                        /* const CosmOS_HandlerType handler                            */
        True,                                                             /* const CosmOS_BooleanType fp                                              */
        SCHEDULABLE_2_UNIQUE_ID,                                          /* const BitWidthType id                                         */
        THREAD_0_PROGRAM_0_CORE_0_ID,                                     /* const BitWidthType instanceId                                                    */
        PROGRAM_0_CORE_0_ID,                                              /* const BitWidthType programId                                             */
        CORE_0_ID,                                                        /* const BitWidthType coreId                                                */
    },
		{
        &ThreadsStacksCfgConst[STACK_THREAD_0_PROGRAM_0_CORE_1_ID],       /* const CosmOS_StackConfigurationType * stack                              */
        SCHEDULABLE_INSTANCE_ENUM__THREAD,                                /* const CosmOS_SchedulableInstanceType instance                            */
        wrapped_IdleThread_CM4,                                        /* const CosmOS_HandlerType handler                            */
        False,                                                             /* const CosmOS_BooleanType fp                                              */
        SCHEDULABLE_6_UNIQUE_ID,                                          /* const BitWidthType id                                         */
        THREAD_0_PROGRAM_0_CORE_1_ID,                                     /* const BitWidthType instanceId                                                    */
        PROGRAM_0_CORE_1_ID,                                              /* const BitWidthType programId                                             */
        CORE_1_ID,                                                        /* const BitWidthType coreId                                                */
    },
};
/* @cond S */
__SEC_STOP(__OS_CONST_SECTION_STOP)
/* @endcond*/

/* @cond S */
__SEC_START(__OS_VAR_SECTION_START)
/* @endcond*/
CosmOS_SchedulableVariableType TasksSchedulablesVar[TASK_NUM] __OS_VAR_SECTION
IS_INITIALIZED_TO
{
		{
        &TasksSchedulablesCfgConst[SCHEDULABLE_TASK_0_PROGRAM_0_CORE_0_ID],       /* const CosmOS_SchedulableConfigurationType * const cfg                              */
        SCHEDULABLE_INSTANCE_ENUM__READY,                              /* CosmOS_SchedulableStateType state                        */
        STACK_TASK_0_PROGRAM_0_CORE_0_HIGH_ADDRESS,                                        /* StackPointerType stackPointer                            */
    },
		{
        &TasksSchedulablesCfgConst[SCHEDULABLE_TASK_1_PROGRAM_0_CORE_0_ID],       /* const CosmOS_SchedulableConfigurationType * const cfg                              */
        SCHEDULABLE_INSTANCE_ENUM__READY,                              /* CosmOS_SchedulableStateType state                        */
        STACK_TASK_1_PROGRAM_0_CORE_0_HIGH_ADDRESS,                                        /* StackPointerType stackPointer                            */
    },
		{
        &TasksSchedulablesCfgConst[SCHEDULABLE_TASK_0_PROGRAM_1_CORE_0_ID],       /* const CosmOS_SchedulableConfigurationType * const cfg                              */
        SCHEDULABLE_INSTANCE_ENUM__READY,                              /* CosmOS_SchedulableStateType state                        */
        STACK_TASK_0_PROGRAM_1_CORE_0_HIGH_ADDRESS,                                        /* StackPointerType stackPointer                            */
    },
		{
        &TasksSchedulablesCfgConst[SCHEDULABLE_TASK_0_PROGRAM_0_CORE_1_ID],       /* const CosmOS_SchedulableConfigurationType * const cfg                              */
        SCHEDULABLE_INSTANCE_ENUM__READY,                              /* CosmOS_SchedulableStateType state                        */
        STACK_TASK_0_PROGRAM_0_CORE_1_HIGH_ADDRESS,                                        /* StackPointerType stackPointer                            */
    },
		{
        &TasksSchedulablesCfgConst[SCHEDULABLE_TASK_1_PROGRAM_0_CORE_1_ID],       /* const CosmOS_SchedulableConfigurationType * const cfg                              */
        SCHEDULABLE_INSTANCE_ENUM__READY,                              /* CosmOS_SchedulableStateType state                        */
        STACK_TASK_1_PROGRAM_0_CORE_1_HIGH_ADDRESS,                                        /* StackPointerType stackPointer                            */
    },
		{
        &TasksSchedulablesCfgConst[SCHEDULABLE_TASK_0_PROGRAM_1_CORE_1_ID],       /* const CosmOS_SchedulableConfigurationType * const cfg                              */
        SCHEDULABLE_INSTANCE_ENUM__READY,                              /* CosmOS_SchedulableStateType state                        */
        STACK_TASK_0_PROGRAM_1_CORE_1_HIGH_ADDRESS,                                        /* StackPointerType stackPointer                            */
    },
};

CosmOS_SchedulableVariableType ThreadsSchedulablesVar[THREAD_NUM] __OS_VAR_SECTION
IS_INITIALIZED_TO
{
		{
        &ThreadsSchedulablesCfgConst[SCHEDULABLE_THREAD_0_PROGRAM_0_CORE_0_ID],       /* const CosmOS_SchedulableConfigurationType * const cfg                              */
        SCHEDULABLE_INSTANCE_ENUM__READY,                                /* CosmOS_SchedulableStateType state                            */
        STACK_THREAD_0_PROGRAM_0_CORE_0_HIGH_ADDRESS,                                        /* StackPointerType stackPointer                            */
    },
		{
        &ThreadsSchedulablesCfgConst[SCHEDULABLE_THREAD_0_PROGRAM_0_CORE_1_ID],       /* const CosmOS_SchedulableConfigurationType * const cfg                              */
        SCHEDULABLE_INSTANCE_ENUM__READY,                                /* CosmOS_SchedulableStateType state                            */
        STACK_THREAD_0_PROGRAM_0_CORE_1_HIGH_ADDRESS,                                        /* StackPointerType stackPointer                            */
    },
};
/* @cond S */
__SEC_STOP(__OS_VAR_SECTION_STOP)
/* @endcond*/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Variables_schedulableCfg_c  
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
  * @defgroup Apis_schedulableCfg_c API's  
  * @ingroup Local_schedulableCfg
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_schedulableCfg_c Getters  
  * @ingroup Apis_schedulableCfg_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}       
  * Getters_schedulableCfg_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_schedulableCfg_c Setters  
  * @ingroup Apis_schedulableCfg_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}    
  * Setters_schedulableCfg_c   
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_schedulableCfg_c General  
  * @ingroup Apis_schedulableCfg_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_schedulableCfg_c  
********************************************************************************/
/********************************************************************************
**                         Function Prototypes | Stop                          **
********************************************************************************/
/********************************************************************************
**                        Function Definitions | Start                         **
********************************************************************************/

void wrapped_Idle_CM7(void)
{
    Idle_CM7();
    for(;;);
};
void wrapped_sysJobs_CM7(void)
{
    sysCalls_os(SYSCALL_SYSJOBS_DISPATCHER);
    sysCalls_os(SYSCALL_SCHEDULABLE_SETEXECUTIONSTATETOFINISHED);
    for(;;);
};
void wrapped_Task_0_Core_0_Handler(void)
{
    Task_0_Core_0_Handler();
    sysCalls_os(SYSCALL_SCHEDULABLE_SETEXECUTIONSTATETOFINISHED);
    for(;;);
};
void wrapped_Idle_CM4(void)
{
    Idle_CM4();
    for(;;);
};
void wrapped_sysJobs_CM4(void)
{
    sysCalls_os(SYSCALL_SYSJOBS_DISPATCHER);
    sysCalls_os(SYSCALL_SCHEDULABLE_SETEXECUTIONSTATETOFINISHED);
    for(;;);
};
void wrapped_Task_0_Core_1_Handler(void)
{
    Task_0_Core_1_Handler();
    sysCalls_os(SYSCALL_SCHEDULABLE_SETEXECUTIONSTATETOFINISHED);
    for(;;);
};
void wrapped_IdleThread_CM7(void)
{
    while ( 1 )
    {
        IdleThread_CM7();
    }
};
void wrapped_IdleThread_CM4(void)
{
    while ( 1 )
    {
        IdleThread_CM4();
    }
};
/********************************************************************************
**                        Function Definitions | Stop                          **
********************************************************************************/
/********************************************************************************
**                           END OF THE SOURCE FILE                            **
********************************************************************************/