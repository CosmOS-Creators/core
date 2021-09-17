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
  * @brief  CosmOS_GenericVoidType void pointer type
********************************************************************************/
typedef void (*CosmOS_GenericVoidType)(void);

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_Generic_bitWidthType_ret_void type
********************************************************************************/
typedef void (*CosmOS_Generic_bitWidthType_ret_void)(BitWidthType);

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_Generic_bitWidthType_ret_bitWidthType type
********************************************************************************/
typedef BitWidthType (*CosmOS_Generic_bitWidthType_ret_bitWidthType)(BitWidthType);

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_Generic_bitWidthType_bitWidthType_ret_bitWidthType type
********************************************************************************/
typedef BitWidthType (*CosmOS_Generic_bitWidthType_bitWidthType_ret_bitWidthType)(BitWidthType,BitWidthType);

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_Generic_bitWidthType_voidPtr_bitWidthType_ret_bitWidthType type
********************************************************************************/
typedef BitWidthType (*CosmOS_Generic_bitWidthType_voidPtr_bitWidthType_ret_bitWidthType)(BitWidthType,void *,BitWidthType);

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_BooleanType enum
********************************************************************************/
typedef enum { False = 0x00, True = 0x01} CosmOS_BooleanType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_AccessStateType enum
********************************************************************************/
typedef enum {

	ACCESS_STATE_ENUM__ALLOWED      = 0x00,
	ACCESS_STATE_ENUM__DENIED       = SECURE_NUMBER,

} CosmOS_AccessStateType;

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
	BUFFER_STATE_ENUM__ERROR_SPINLOCK_NOT_OBTAINED,
	BUFFER_STATE_ENUM__ERROR_INPUT_ARRAY_IS_PROTECTED,
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

} CosmOS_SchedulableInstanceType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_SchedulableStateType enum
********************************************************************************/
typedef enum {

	SCHEDULABLE_STATE_ENUM__READY,
	SCHEDULABLE_STATE_ENUM__RUNNING,
	SCHEDULABLE_STATE_ENUM__EXECUTED,
	SCHEDULABLE_STATE_ENUM__BLOCKED,
	SCHEDULABLE_STATE_ENUM__SLEEP,

} CosmOS_SchedulableStateType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_SchedulerSyncStateType enum
********************************************************************************/
typedef enum {

	SCHEDULER_SYNC_STATE_ENUM__NOT_IN_SYNC  = 0x00,
	SCHEDULER_SYNC_STATE_ENUM__IN_SYNC      = SECURE_NUMBER,

} CosmOS_SchedulerSyncStateType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_BarrierStateType enum
********************************************************************************/
typedef enum {

	BARRIER_STATE_ENUM__ACTIVATED  = 0x00,
	BARRIER_STATE_ENUM__REACHED    = SECURE_NUMBER,

} CosmOS_BarrierStateType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_BarrierStateType enum
********************************************************************************/
typedef enum {

	ALARM_STATE_ENUM__ACTIVATED  = 0x00,
	ALARM_STATE_ENUM__DISABLED   = SECURE_NUMBER,

} CosmOS_AlarmStateType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_OsStateType enum
********************************************************************************/
typedef enum {

	OS_STATE_ENUM__NOT_INITIALIZED,
	OS_STATE_ENUM__INITIALIZED,
	OS_STATE_ENUM__STARTED,
	OS_STATE_ENUM__ERROR_HOOK,

} CosmOS_OsStateType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_SchedulerStateType enum
********************************************************************************/
typedef enum {

	SCHEDULER_STATE_ENUM__NOT_STARTED 					= FORCE_ENUM,
	SCHEDULER_STATE_ENUM__TASK_EXECUTED_IN_WCET_CHECK	= 0x00,
	SCHEDULER_STATE_ENUM__WAITING_FOR_START_TIME 		= 0x01,

} CosmOS_SchedulerStateType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_RescheduleTriggerStateType enum
********************************************************************************/
typedef enum {

	RESCHEDULE_TRIGGER_STATE_ENUM__TIMER	= FORCE_ENUM,
	RESCHEDULE_TRIGGER_STATE_ENUM__SYSTEM 	= 0x00,

} CosmOS_RescheduleTriggerStateType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_SpinlockStateType enum
********************************************************************************/
typedef enum {

	SPINLOCK_STATE_ENUM__DEADLOCK_WARNING 			= 0xFF,
	SPINLOCK_STATE_ENUM__RELEASED 					= 0x00,
	SPINLOCK_STATE_ENUM__OCCUPIED 					= 0x01,
	SPINLOCK_STATE_ENUM__SUCCESSFULLY_LOCKED		= 0x02,
	SPINLOCK_STATE_ENUM__SCHEDULABLE_IS_NOT_OWNER 	= 0x02,
	SPINLOCK_STATE_ENUM__FORCE      				= FORCE_ENUM,

} CosmOS_SpinlockStateType;
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
