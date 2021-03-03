/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file CosmOSTypesCfg.h                                      
*********************************************************************************	
<!--                     CosmOSTypesCfg Unit Group Definition                    -->
********************************************************************************* 
** @defgroup CosmOSTypesCfg_unit CosmOSTypesCfg Unit 
** @ingroup CosmOSTypes_module        
** @brief CosmOSTypesCfg Unit 
** @details lorem                               
*********************************************************************************	
<!--                           Version Information                            -->
*********************************************************************************
** @version 1.0.0
** @date 1.8.2020
** @author https://github.com/PavolKostolansky   
*********************************************************************************	
<!--                          Warnings and License                            -->
*********************************************************************************
** @warning Modifying code can lead to unexpected behaviour of the whole system
** @copyright MIT License       	
*********************************************************************************
<!--                CosmOSTypesCfg Unit Global Group Definition                  -->
*********************************************************************************	
** @defgroup Global_CosmOSTypesCfg Global
** @ingroup CosmOSTypesCfg_unit 
** @brief CosmOSTypesCfg globals
** @details lorem 
********************************************************************************/ 
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __COSMOSTYPESCFG_H__
#define __COSMOSTYPESCFG_H__
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
#include "CosmOSTypesBase.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_CosmOSTypesCfg_h Macros
  * @ingroup Global_CosmOSTypesCfg  
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Macros_CosmOSTypesCfg_h  
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Stop                           **
********************************************************************************/
/********************************************************************************
**                              Typedefs | Start                               **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Typedefs_CosmOSTypesCfgCfg_h Typedefs
  * @ingroup Global_CosmOSTypesCfg  
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_PermissionsConfigurationType struct type
********************************************************************************/
typedef struct
{
    const BitWidthType * const bitLocksTasks;
    const BitWidthType * const bitLocksTasksInversed;

} CosmOS_PermissionsConfigurationType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_BufferConfigurationType struct type
********************************************************************************/
typedef struct
{
    const CosmOS_GenericVoidType * const routeFunc;
    const BitWidthType * const routeIdToFunc;
    const BitWidthType * const routeIdToEntity;

} CosmOS_RoutesConfigurationType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_BufferConfigurationType struct type
********************************************************************************/
typedef struct
{
    unsigned char * const buffer;
    const BitWidthType size;
    const CosmOS_PermissionsConfigurationType * const readPermission;
    const CosmOS_PermissionsConfigurationType * const writePermission;

} CosmOS_BufferConfigurationType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_StackConfigurationType struct type
********************************************************************************/
typedef struct
{
    const BitWidthType stackSize;
    const AddressType stackLowAddress;
    const AddressType stackHighAddress;
    
} CosmOS_StackConfigurationType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_TaskConfigurationType struct type
********************************************************************************/
typedef struct
{
    const CosmOS_StackConfigurationType * const stack;
    const CosmOS_HandlerType handler;
    const BitWidthType id;
    const BitWidthType wcet;
    const BitWidthType programId;
    const BitWidthType coreId;
    
} CosmOS_TaskConfigurationType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_ProgramConfigurationType struct type
********************************************************************************/
typedef struct            
{               
    const CosmOS_TaskConfigurationType * const tasks;
    const BitWidthType coreId;
    const BitWidthType numberOfTasks;
    
} CosmOS_ProgramConfigurationType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_ScheduleTableConfigurationType struct type
********************************************************************************/
typedef struct
{
    const BitWidthType startTick;
    void * const taskVar;

} CosmOS_ScheduleTableConfigurationType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_SchedulerConfigurationType struct type
********************************************************************************/
typedef struct
{
    const CosmOS_ScheduleTableConfigurationType * const scheduleTable;
    const BitWidthType hyperTick;
    const BitWidthType scheduleTableElementsNum;
    const BitWidthType lastToFirstTaskTicks;

} CosmOS_SchedulerConfigurationType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_CoreConfigurationType struct type
********************************************************************************/
typedef struct
{
    const CosmOS_ProgramConfigurationType * const programs;
    const BitWidthType numberOfPrograms;
    const CosmOS_SchedulerConfigurationType * const scheduler;

} CosmOS_CoreConfigurationType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_OsConfigurationType struct type
********************************************************************************/
typedef struct
{
    const CosmOS_CoreConfigurationType * const cores;
    const BitWidthType numberOfCores;
    const CosmOS_BufferConfigurationType * const buffers;
    const BitWidthType numberOfBuffers;
    const CosmOS_RoutesConfigurationType * const route;
    
} CosmOS_OsConfigurationType;
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Typedefs_CosmOSTypesCfg_h  
********************************************************************************/
/********************************************************************************
**                              Typedefs | Stop                                **
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