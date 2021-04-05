/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file sysJobsCfg.c
*********************************************************************************
<!--                   sysJobsCfg Unit Local Group Definition                 -->
*********************************************************************************	
** @defgroup Local_sysJobsCfg Local
** @ingroup sysJobsCfg_unit 
** @brief sysJobsCfg locals
** @details lorem 
********************************************************************************/ 
/********************************************************************************  
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "sysJobsCfg.h"

/* CIL interfaces */
#include "CIL_uart.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_sysJobsCfg Macros
  * @ingroup Local_sysJobsCfg
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Macros_sysJobsCfg  
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
  * @defgroup Variables_sysJobsCfg Variables  
  * @ingroup Local_sysJobsCfg
  * @{    
********************************************************************************/
/* @cond S */
__SEC_START(__OS_CONST_SECTION_START)
/* @endcond*/
const CosmOS_GenericVoidType SysJobsHandlersGroup0Core0Const[SYSJOBS_HANDLERS_GROUP_0_CORE_0_NUM] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
    (CosmOS_GenericVoidType)CIL_uart_sysJob,
};
const CosmOS_GenericVoidType SysJobsHandlersGroup0Core1Const[SYSJOBS_HANDLERS_GROUP_0_CORE_1_NUM] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
    (CosmOS_GenericVoidType)CIL_uart_sysJob,
};
const CosmOS_SysJobsGroupConfigurationType SysJobsGroupsCore0ConstCfg[SYSJOBS_GROUPS_CORE_0_NUM] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
    {
        SysJobsHandlersGroup0Core0Const,                /* const CosmOS_GenericVoidType * const handlers    */
        SYSJOBS_HANDLERS_GROUP_0_CORE_0_NUM,            /* const BitWidthType numOfHandlers                 */
        SYSJOBS_GROUP_0_CORE_0_TICK_MULTIPLICATOR,      /* const BitWidthType tickMultiplicator             */
    },
};
const CosmOS_SysJobsGroupConfigurationType SysJobsGroupsCore1ConstCfg[SYSJOBS_GROUPS_CORE_1_NUM] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
    {
        SysJobsHandlersGroup0Core1Const,                /* const CosmOS_GenericVoidType * const handlers    */
        SYSJOBS_HANDLERS_GROUP_0_CORE_1_NUM,            /* const BitWidthType numOfHandlers                 */
        SYSJOBS_GROUP_0_CORE_1_TICK_MULTIPLICATOR,      /* const BitWidthType tickMultiplicator             */
    },
};
const CosmOS_SysJobsConfigurationType SysJobsConstCfg[CORE_NUM] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
    {
        SysJobsGroupsCore0ConstCfg,                   /* const CosmOS_SysJobsGroupConfigurationType * const groups    */
        SYSJOBS_GROUPS_CORE_0_NUM,                    /* const BitWidthType numOfGroups                               */
        SYSJOBS_CORE_0_MAX_TICK_MULTIPLICATOR         /* const BitWidthType maxTickMultiplicator                      */
    },
{
        SysJobsGroupsCore1ConstCfg,                   /* const CosmOS_SysJobsGroupConfigurationType * const groups    */
        SYSJOBS_GROUPS_CORE_1_NUM,                    /* const BitWidthType numOfGroups                               */
        SYSJOBS_CORE_1_MAX_TICK_MULTIPLICATOR         /* const BitWidthType maxTickMultiplicator                      */
    },
};
/* @cond S */
__SEC_STOP(__OS_CONST_SECTION_STOP)
/* @endcond*/

/* @cond S */
__SEC_START(__OS_VAR_SECTION_START)
/* @endcond*/
CosmOS_SysJobsVariableType SysJobsVar[CORE_NUM] __OS_VAR_SECTION 
IS_INITIALIZED_TO 
{
    {
        &SysJobsConstCfg[CORE_0_ID],    /* const CosmOS_SysJobsConfigurationType * const cfg  */
        0,                              /* BitWidthType currentTick                           */
    },
{
        &SysJobsConstCfg[CORE_1_ID],    /* const CosmOS_SysJobsConfigurationType * const cfg  */
        0,                              /* BitWidthType currentTick                           */
    },
};
/* @cond S */
__SEC_STOP(__OS_VAR_SECTION_STOP)
/* @endcond*/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Variables_sysJobsCfg  
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
  * @defgroup Apis_sysJobsCfg_c API's  
  * @ingroup Local_sysJobsCfg
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_sysJobsCfg_c Getters  
  * @ingroup Apis_sysJobsCfg_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}       
  * Getters_sysJobsCfg_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_sysJobsCfg_c Setters  
  * @ingroup Apis_sysJobsCfg_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}    
  * Setters_sysJobsCfg_c   
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_sysJobsCfg_c General  
  * @ingroup Apis_sysJobsCfg_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_sysJobsCfg_c  
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