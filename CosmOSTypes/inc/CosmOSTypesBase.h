/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file CosmOSTypesBase.h                                      
*********************************************************************************	
<!--                    CosmOSTypesBase Unit Group Definition                    -->
********************************************************************************* 
** @defgroup CosmOSTypesBase_unit CosmOSTypesBase Unit 
** @ingroup CosmOSTypes_module        
** @brief CosmOSTypesBase Unit 
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
<!--               CosmOSTypesBase Unit Global Group Definition                  -->
*********************************************************************************	
** @defgroup Global_CosmOSTypesBase Global
** @ingroup CosmOSTypesBase_unit 
** @brief CosmOSTypesBase globals
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
#include "CIL_stdTypes.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_CosmOSTypesBase_h Macros
  * @ingroup Global_CosmOSTypesBase  
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Macros_CosmOSTypesBase_h  
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
  * @defgroup Typedefs_CosmOSTypesBaseCfg_h Typedefs
  * @ingroup Global_CosmOSTypesBase  
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
  * @brief  CosmOS_BarrierStateType enum
********************************************************************************/
typedef enum {

    TASK_STATE_ENUM__ACTIVATED       = 0x00,
    TASK_STATE_ENUM__DEACTIVATED     = SECURE_NUMBER,
    TASK_STATE_ENUM__FORCE           = FORCE_ENUM,

} CosmOS_TaskStateType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_BarrierStateType enum
********************************************************************************/
typedef enum {

    TASK_EXECUTION_STATE_ENUM__RUNNING    = 0x00,
    TASK_EXECUTION_STATE_ENUM__EXECUTED   = SECURE_NUMBER,
    TASK_EXECUTION_STATE_ENUM__FORCE      = FORCE_ENUM,

} CosmOS_TaskExecutionStateType;
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Typedefs_CosmOSTypesBase_h  
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