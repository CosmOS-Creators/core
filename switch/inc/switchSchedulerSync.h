/********************************************************************************
**                                                                             **
**                       GENERATED FILE BY CosmOS CustomBox                    **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file switchSchedulerSync.h                                      	 		
*********************************************************************************	
<!--               switchSchedulerSync Unit Group Definition                -->
********************************************************************************* 
** @defgroup switchSchedulerSync_unit switchSchedulerSync Unit 
** @ingroup switch_module        
** @brief switchSchedulerSync Unit 
** @details lorem                               
*********************************************************************************	
<!--                           Version Information                            -->
*********************************************************************************
** @version 1.0.0
** @date 2021-06-03
** @author Generated by CosmOS CustomBox   
*********************************************************************************	
<!--                          Warnings and License                            -->
*********************************************************************************
** @warning Modifying code can lead to unexpected behaviour of the whole system
** @copyright MIT License       	
*********************************************************************************
<!--             switchSchedulerSync Unit Global Group Definition           -->
*********************************************************************************	
** @defgroup Global_switchSchedulerSync Global
** @ingroup switchSchedulerSync_unit 
** @brief switchSchedulerSync globals
** @details lorem 
********************************************************************************/ 
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __SWITCHESSCHEDULERSYNC_H__
#define __SWITCHESSCHEDULERSYNC_H__
/********************************************************************************
**                         START OF C++ SUPPORT SECTION                        **
********************************************************************************/
#ifdef __cplusplus
 extern "C" {
#endif
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "schedulerSync.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_switchSchedulerSync_h Macros
  * @ingroup Global_switchSchedulerSync  
  * @{    
********************************************************************************/
#define SCHEDULER_SYNC OFF
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Macros_switchSchedulerSync_h  
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
  * @defgroup Variables_switchSchedulerSync_h Variables  
  * @ingroup Global_switchSchedulerSync  
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Variables_switchSchedulerSync_h  
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
  * @defgroup Apis_switchSchedulerSync_h API's 
  * @ingroup Global_switchSchedulerSync
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_switchSchedulerSync_h Getters  
  * @ingroup Apis_switchSchedulerSync_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}       
  * Getters_switchSchedulerSync_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_switchSchedulerSync_h Setters  
  * @ingroup Apis_switchSchedulerSync_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}    
  * Setters_switchSchedulerSync_h   
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_switchSchedulerSync_h General  
  * @ingroup Apis_switchSchedulerSync_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_switchSchedulerSync_h  
********************************************************************************/
/********************************************************************************
**                         Function Prototypes | Stop                          **
********************************************************************************/
/********************************************************************************
**                        Function Definitions | Start                         **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_switchSchedulerSync_h Getters  
  * @ingroup Apis_switchSchedulerSync_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}       
  * Getters_switchSchedulerSync_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_switchSchedulerSync_h Setters  
  * @ingroup Apis_switchSchedulerSync_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}    
  * Setters_switchSchedulerSync_h   
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_switchSchedulerSync_h General  
  * @ingroup Apis_switchSchedulerSync_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn switchSchedulerSync_sync(CosmOS_CoreVariableType * coreVar,BitWidthType currentTick,BitWidthType currentTick)
  * 
  * @brief Algorithm for synchronization during runtime.
  * 
  * @param[in] CosmOS_CoreVariableType * coreVar
  * @param[in] BitWidthType currentTick
  * @param[in] BitWidthType syncPeriod
  * 
  * @return BitWidthType
********************************************************************************/
#if ( SCHEDULER_SYNC IS_EQUAL_TO ON )
    #define switchSchedulerSync_sync(schedulerVar, coreVar, currentTick, hyperTick) schedulerSync_sync(schedulerVar, coreVar, currentTick, hyperTick)
#else
    #define switchSchedulerSync_sync(schedulerVar, coreVar, currentTick, hyperTick) SCHEDULER_SYNC_STATE_ENUM__NOT_IN_SYNC
#endif
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_switchSchedulerSync_h  
********************************************************************************/
/********************************************************************************
**                        Function Definitions | Stop                          **
********************************************************************************/
#ifdef __cplusplus
}
#endif
/********************************************************************************
**                         END OF C++ SUPPORT SECTION                          **
********************************************************************************/
#endif
/********************************************************************************
**                           END OF THE HEADER FILE                            **
********************************************************************************/