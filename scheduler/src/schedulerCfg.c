/********************************************************************************
**                                                                             **
**                       GENERATED FILE BY CosmOS CustomBox                    **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file schedulerCfg.c
*********************************************************************************
<!--                 schedulerCfg Unit Local Group Definition                 -->
*********************************************************************************	
** @defgroup Local_schedulerCfg Local
** @ingroup schedulerCfg_unit 
** @brief schedulerCfg locals
** @details lorem 
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "schedulerCfg.h"
#include "schedulerScheduleTableCfg.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_schedulerCfg_c Macros
  * @ingroup Local_schedulerCfg
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Macros_schedulerCfg_c  
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
  * @defgroup Variables_schedulerCfg_c Variables  
  * @ingroup Local_schedulerCfg
  * @{    
********************************************************************************/
/* @cond S */
__SEC_START(__OS_CONST_SECTION_START)
/* @endcond*/
const CosmOS_SchedulerConfigurationType SchedulersCfgConst[SCHEDULER_NUM] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		{                                                   /* SchedulersCfgConst[SCHEDULER_CORE_0_ID]                         */
        ScheduleTableScheduler0CfgConst,                /* const CosmOS_ScheduleTableConfigurationType * scheduleTable     */
        HYPERTICK_SCHEDULER_0,                          /* const BitWidthType hyperTick                                    */
        SCHEDULETABLE_SCHEDULER_0_ELEMENT_NUM,          /* const BitWidthType scheduleTableElementsNum                     */
        LAST_TO_FIRST_TASK_TICK_SCHEDULER_0,            /* const BitWidthType lastToFirstTaskTicks                         */
    },
		{                                                   /* SchedulersCfgConst[SCHEDULER_CORE_1_ID]                         */
        ScheduleTableScheduler1CfgConst,                /* const CosmOS_ScheduleTableConfigurationType * scheduleTable     */
        HYPERTICK_SCHEDULER_1,                          /* const BitWidthType hyperTick                                    */
        SCHEDULETABLE_SCHEDULER_1_ELEMENT_NUM,          /* const BitWidthType scheduleTableElementsNum                     */
        LAST_TO_FIRST_TASK_TICK_SCHEDULER_1,            /* const BitWidthType lastToFirstTaskTicks                         */
    },
};
/* @cond S */
__SEC_STOP(__OS_CONST_SECTION_STOP)
/* @endcond*/

/* @cond S */
__SEC_START(__OS_VAR_SECTION_START)
/* @endcond*/
CosmOS_SchedulerVariableType SchedulersVar[SCHEDULER_NUM] __OS_VAR_SECTION 
IS_INITIALIZED_TO 
{
		{                                                   /* SchedulersCfgConst[SCHEDULER_CORE_0_ID]          */
        &SchedulersCfgConst[SCHEDULER_CORE_0_ID],       /* CosmOS_SchedulerConfigurationType * cfg    */
        0,                                              /* BitWidthType curentTick                    */
        0,                                              /* BitWidthType scheduleTableIterator         */
        0,                                              /* BitWidthType scheduleTableIteratorPrior    */
        SCHEDULER_STATE_ENUM__NOT_STARTED,              /* CosmOS_SchedulerStateType schedulerState         */
    },
		{                                                   /* SchedulersCfgConst[SCHEDULER_CORE_1_ID]          */
        &SchedulersCfgConst[SCHEDULER_CORE_1_ID],       /* CosmOS_SchedulerConfigurationType * cfg    */
        0,                                              /* BitWidthType curentTick                    */
        0,                                              /* BitWidthType scheduleTableIterator         */
        0,                                              /* BitWidthType scheduleTableIteratorPrior    */
        SCHEDULER_STATE_ENUM__NOT_STARTED,              /* CosmOS_SchedulerStateType schedulerState         */
    },
};
/* @cond S */
__SEC_STOP(__OS_VAR_SECTION_STOP)
/* @endcond*/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Variables_schedulerCfg_c  
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
  * @defgroup Apis_schedulerCfg_c API's  
  * @ingroup Local_schedulerCfg
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_schedulerCfg_c Getters  
  * @ingroup Apis_schedulerCfg_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}       
  * Getters_schedulerCfg_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_schedulerCfg_c Setters  
  * @ingroup Apis_schedulerCfg_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}    
  * Setters_schedulerCfg_c   
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_schedulerCfg_c General  
  * @ingroup Apis_schedulerCfg_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_schedulerCfg_c  
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