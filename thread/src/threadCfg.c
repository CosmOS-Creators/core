/********************************************************************************
**                                                                             **
**                       GENERATED FILE BY CosmOS CustomBox                    **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file threadCfg.c       	
*********************************************************************************
<!--                  threadCfg Unit Local Group Definition                   -->
*********************************************************************************	
** @defgroup Local_threadCfg Local
** @ingroup threadCfg_unit 
** @brief threadCfg locals
** @details lorem 
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "threadCfg.h"
#include "stackCfg.h"

/* THIS INCLUDE IS PART OF DEMO CODE FOR TESTING PURPOSES */
#include "stm32h7xx_hal.h"
#include "CosmOSApi.h"
/* THIS INCLUDE IS PART OF DEMO CODE FOR TESTING PURPOSES */
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_threadCfg_c Macros
  * @ingroup Local_threadCfg
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Macros_threadCfg_c  
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
  * @defgroup Variables_threadCfg_c Variables
  * @ingroup Local_threadCfg
  * @{    
********************************************************************************/
/* @cond S */
__SEC_START(__OS_CONST_SECTION_START)
/* @endcond*/
const CosmOS_ThreadConfigurationType ThreadsProgram0Core0CfgConst[THREAD_PROGRAM_0_CORE_0_NUM] __OS_CONST_SECTION
IS_INITIALIZED_TO 
{
{                                                                     /* ThreadsProgram0Core0CfgConst[THREAD_0_PROGRAM_0_CORE_0_ID]   */
        &ThreadsStacksCfgConst[STACK_THREAD_0_PROGRAM_0_CORE_0_ID],       /* const CosmOS_StackConfigurationType * stack                     */
        Thread_0_Core_0_Handler,                                          /* const CosmOS_HandlerType handler                                */
        THREAD_0_PROGRAM_0_CORE_0_ID,                                     /* const BitWidthType id                                        */
        PROGRAM_0_CORE_0_ID,                                              /* const BitWidthType programId                                 */ 
        CORE_0_ID,                                                        /* const BitWidthType coreId                                    */
    },


};

const CosmOS_ThreadConfigurationType ThreadsProgram0Core1CfgConst[THREAD_PROGRAM_0_CORE_1_NUM] __OS_CONST_SECTION
IS_INITIALIZED_TO 
{
{                                                                     /* ThreadsProgram0Core1CfgConst[THREAD_0_PROGRAM_0_CORE_1_ID]   */
        &ThreadsStacksCfgConst[STACK_THREAD_0_PROGRAM_0_CORE_1_ID],       /* const CosmOS_StackConfigurationType * stack                     */
        Thread_0_Core_1_Handler,                                          /* const CosmOS_HandlerType handler                                */
        THREAD_0_PROGRAM_0_CORE_1_ID,                                     /* const BitWidthType id                                        */
        PROGRAM_0_CORE_1_ID,                                              /* const BitWidthType programId                                 */ 
        CORE_1_ID,                                                        /* const BitWidthType coreId                                    */
    },


};


/* @cond S */
__SEC_STOP(__OS_CONST_SECTION_STOP)
/* @endcond*/

/* @cond S */
__SEC_START(__OS_VAR_SECTION_START)
/* @endcond*/
CosmOS_ThreadVariableType ThreadsProgram0Core0Var[THREAD_PROGRAM_0_CORE_0_NUM] __OS_VAR_SECTION 
IS_INITIALIZED_TO 
{
{                                                                     /* ThreadsProgram0Core0Var[THREAD_0_PROGRAM_0_CORE_0_ID]        */
        &ThreadsProgram0Core0CfgConst[THREAD_0_PROGRAM_0_CORE_0_ID],      /* const CosmOS_ThreadConfigurationType * cfg                      */
        &ThreadsStacksVar[STACK_THREAD_0_PROGRAM_0_CORE_0_ID],            /* CosmOS_StackVariableType * stackVar                             */
        STACK_THREAD_0_PROGRAM_0_CORE_0_HIGH_ADDRESS,                     /* StackPointerType stackPointer                                */          
    },


};

CosmOS_ThreadVariableType ThreadsProgram0Core1Var[THREAD_PROGRAM_0_CORE_1_NUM] __OS_VAR_SECTION 
IS_INITIALIZED_TO 
{
{                                                                     /* ThreadsProgram0Core0Var[THREAD_0_PROGRAM_0_CORE_1_ID]        */
        &ThreadsProgram0Core1CfgConst[THREAD_0_PROGRAM_0_CORE_1_ID],      /* const CosmOS_ThreadConfigurationType * cfg                      */
        &ThreadsStacksVar[STACK_THREAD_0_PROGRAM_0_CORE_1_ID],            /* CosmOS_StackVariableType * stackVar                             */
        STACK_THREAD_0_PROGRAM_0_CORE_1_HIGH_ADDRESS,                     /* StackPointerType stackPointer                                */          
    },


};


/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Variables_threadCfg_c  
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
  * @defgroup Apis_threadCfg_c API's  
  * @ingroup Local_threadCfg
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_threadCfg_c Getters  
  * @ingroup Apis_threadCfg_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}       
  * Getters_threadCfg_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_threadCfg_c Setters  
  * @ingroup Apis_threadCfg_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}    
  * Setters_threadCfg_c   
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_threadCfg_c General  
  * @ingroup Apis_threadCfg_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_threadCfg_c  
********************************************************************************/
/********************************************************************************
**                         Function Prototypes | Stop                          **
********************************************************************************/
/********************************************************************************
**                        Function Definitions | Start                         **
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn Thread_0_Core_0_Handler(void)
  * 
  * @brief Thread 0. Core 0, should be placed in application layer, (DEMO CODE its here for the testing purposes).
  * 
  * @param[in]  none
  * 
  * @return none
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION void Thread_0_Core_0_Handler(void)
{
    while(1)
    {
        for( BitWidthType i = 0; i < 10000000; i++ ){
          
        }
        
        togglePin(GPIOE, GPIO_PIN_1);
    }
}
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn Thread_0_Core_1_Handler(void)
  * 
  * @brief Thread 0. Core 1, should be placed in application layer, (DEMO CODE its here for the testing purposes).
  * 
  * @param[in]  none
  * 
  * @return none
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION void Thread_0_Core_1_Handler(void)
{
    while(1)
    {

    }
}
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/
/********************************************************************************
**                        Function Definitions | Stop                          **
********************************************************************************/
/********************************************************************************
**                           END OF THE SOURCE FILE                            **
********************************************************************************/