/********************************************************************************
**                                                                             **
**                       GENERATED FILE BY CosmOS CustomBox                    **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file coreSync.c
*********************************************************************************
<!--                  coreSync Unit Local Group Definition                    -->
*********************************************************************************	
** @defgroup Local_coreSync Local
** @ingroup coreSync_unit 
** @brief coreSync locals
** @details lorem 
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "coreSync.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_coreSync_c Macros
  * @ingroup Local_coreSync
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Macros_coreSync_c  
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
  * @defgroup Variables_coreSync_c Variables  
  * @ingroup Local_coreSync
  * @{    
********************************************************************************/
/* @cond S */
__SEC_START(__OS_VAR_SECTION_START)
/* @endcond*/
CosmOS_BarrierVariableType BarriersCore0Var[BARRIERS_NUM] __OS_VAR_SECTION
IS_INITIALIZED_TO
{
    {                 /* BarriersCore0Var[OS_INIT_ID]                     */
        BARRIER_STATE_ENUM__ACTIVATED,    /* CosmOS_BarrierStateType barrierState                */
    },
    {                 /* BarriersCore0Var[OS_START_ID]                    */
        BARRIER_STATE_ENUM__ACTIVATED,    /* CosmOS_BarrierStateType barrierState                */
    },
    {                 /* BarriersCore0Var[OS_STOP_ID]                     */
        BARRIER_STATE_ENUM__ACTIVATED,    /* CosmOS_BarrierStateType barrierState                */
    },
    {                 /* BarriersCore0Var[SCHEDULERS_SYNC_ID]                     */
        BARRIER_STATE_ENUM__ACTIVATED,    /* CosmOS_BarrierStateType barrierState                */
    },
};

CosmOS_BarrierVariableType BarriersCore1Var[BARRIERS_NUM] __OS_VAR_SECTION
IS_INITIALIZED_TO
{
    {                 /* BarriersCore0Var[OS_INIT_ID]                     */
        BARRIER_STATE_ENUM__ACTIVATED,    /* CosmOS_BarrierStateType barrierState                */
    },
    {                 /* BarriersCore0Var[OS_START_ID]                    */
        BARRIER_STATE_ENUM__ACTIVATED,    /* CosmOS_BarrierStateType barrierState                */
    },
    {                 /* BarriersCore0Var[OS_STOP_ID]                     */
        BARRIER_STATE_ENUM__ACTIVATED,    /* CosmOS_BarrierStateType barrierState                */
    },
    {                 /* BarriersCore0Var[SCHEDULERS_SYNC_ID]                     */
        BARRIER_STATE_ENUM__ACTIVATED,    /* CosmOS_BarrierStateType barrierState                */
    },
};
/* @cond S */
__SEC_STOP(__OS_VAR_SECTION_STOP)
/* @endcond*/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Variables_coreSync_c  
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
  * @defgroup Apis_coreSync_c API's  
  * @ingroup Local_coreSync
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_coreSync_c Getters  
  * @ingroup Apis_coreSync_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}       
  * Getters_coreSync_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_coreSync_c Setters  
  * @ingroup Apis_coreSync_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}    
  * Setters_coreSync_c   
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_coreSync_c General  
  * @ingroup Apis_coreSync_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_coreSync_c  
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
