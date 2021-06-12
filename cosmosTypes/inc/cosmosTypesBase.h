/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file cosmosTypesBase.h                                      
*********************************************************************************	
<!--                   cosmosTypesBase Unit Group Definition                  -->
********************************************************************************* 
** @defgroup cosmosTypesBase_unit cosmosTypesBase Unit 
** @ingroup cosmosTypes_module        
** @brief cosmosTypesBase Unit 
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
<!--               cosmosTypesBase Unit Global Group Definition               -->
*********************************************************************************	
** @defgroup Global_cosmosTypesBase Global
** @ingroup cosmosTypesBase_unit 
** @brief cosmosTypesBase globals
** @details lorem 
********************************************************************************/ 
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __COSMOSTYPESBASE_H__
#define __COSMOSTYPESBASE_H__
/********************************************************************************
**                         START OF C++ SUPPORT SECTION                        **
********************************************************************************/
#ifdef __cplusplus
 extern "C" {
#endif
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CIL interfaces */
#include "CILstdTypes.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_cosmosTypesBase_h Macros
  * @ingroup Global_cosmosTypesBase  
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Macros_cosmosTypesBase_h  
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
  * @defgroup Typedefs_cosmosTypesBaseCfg_h Typedefs
  * @ingroup Global_cosmosTypesBase  
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_HandlerType void pointer type
********************************************************************************/
typedef void (*CosmOS_HandlerType)(void);

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_GenericVoidType void pointer type
********************************************************************************/
typedef void (*CosmOS_GenericVoidType)(void);

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_GenericBitWidthRWType BitWidthType pointer RW type
********************************************************************************/
typedef BitWidthType (*CosmOS_GenericBitWidthRWType)(BitWidthType,void *,BitWidthType);

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_BooleanType enum
********************************************************************************/
typedef enum { False = 0x00, True = 0x01} CosmOS_BooleanType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_PermissionType enum
********************************************************************************/
typedef enum {

    ACCESS_STATE_ENUM__ALLOWED      = 0x00,
    ACCESS_STATE_ENUM__DENIED       = SECURE_NUMBER,
    ACCESS_STATE_ENUM__FORCE        = FORCE_ENUM,

} CosmOS_AccessStateType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_PermissionType enum
********************************************************************************/
typedef enum {

    PERMISSION_INSTANCE_ENUM__NONE,
    PERMISSION_INSTANCE_ENUM__ONLY_TASKS,     
    PERMISSION_INSTANCE_ENUM__ONLY_THREADS,
    PERMISSION_INSTANCE_ENUM__ALL_TASKS,
    PERMISSION_INSTANCE_ENUM__ALL_THREADS,
    PERMISSION_INSTANCE_ENUM__ALL,

} CosmOS_PermissionInstanceType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_BufferStateType enum
********************************************************************************/
typedef enum {

    BUFFER_STATE_ENUM__OK,
    BUFFER_STATE_ENUM__EMPTY,
    BUFFER_STATE_ENUM__FULL,
    BUFFER_STATE_ENUM__ERROR_ACCESS_DENIED,
    BUFFER_STATE_ENUM__ERROR_INPUT_IS_NULL_POINTER,
    BUFFER_STATE_ENUM__ERROR_SIZE_BIGGER_THAN_EMPTY_CELLS,
    BUFFER_STATE_ENUM__ERROR_SIZE_BIGGER_THAN_FULL_CELLS_NUM,
    
} CosmOS_BufferStateType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_BufferDoubleAccessType enum
********************************************************************************/
typedef enum {

    BUFFER_DOUBLE_ACCESS_ENUM__USER,
    BUFFER_DOUBLE_ACCESS_ENUM__KERNEL,
    
} CosmOS_BufferDoubleAccessType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_SchedulableInstanceType enum
********************************************************************************/
typedef enum {

    SCHEDULABLE_INSTANCE_ENUM__TASK    = 0x00,
    SCHEDULABLE_INSTANCE_ENUM__THREAD  = SECURE_NUMBER,
    SCHEDULABLE_INSTANCE_ENUM__FORCE   = FORCE_ENUM,
    
} CosmOS_SchedulableInstanceType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_SchedulableStateType enum
********************************************************************************/
typedef enum {

    SCHEDULABLE_INSTANCE_ENUM__READY,
    SCHEDULABLE_INSTANCE_ENUM__RUNNING,
    SCHEDULABLE_INSTANCE_ENUM__EXECUTED,
    SCHEDULABLE_INSTANCE_ENUM__BLOCKED,

} CosmOS_SchedulableStateType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_SchedulerSyncStateType enum
********************************************************************************/
typedef enum {

    SCHEDULER_SYNC_STATE_ENUM__NOT_IN_SYNC  = 0x00,
    SCHEDULER_SYNC_STATE_ENUM__IN_SYNC      = SECURE_NUMBER,
    SCHEDULER_SYNC_STATE_ENUM__FORCE        = FORCE_ENUM,

} CosmOS_SchedulerSyncStateType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_BarrierStateType enum
********************************************************************************/
typedef enum {

    BARRIER_STATE_ENUM__ACTIVATED  = 0x00,
    BARRIER_STATE_ENUM__REACHED    = SECURE_NUMBER,
    BARRIER_STATE_ENUM__FORCE      = FORCE_ENUM,

} CosmOS_BarrierStateType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_OsState enum
********************************************************************************/
typedef enum {

    OS_STATE_ENUM__NOT_STARTED,
    OS_STATE_ENUM__STARTED,
    OS_STATE_ENUM__ERROR_HOOK,

} CosmOS_OsState;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_SchedulerStateType enum
********************************************************************************/
typedef enum {

    SCHEDULER_STATE_ENUM__NOT_STARTED,
    SCHEDULER_STATE_ENUM__TASK_EXECUTED_IN_WCET_CHECK,
    SCHEDULER_STATE_ENUM__WAITING_FOR_START_TIME,

} CosmOS_SchedulerStateType;
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Typedefs_cosmosTypesBase_h  
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