/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file cosmosTypesStd.h
*********************************************************************************
<!--                    cosmosTypesStd Unit Group Definition                  -->
*********************************************************************************
** @defgroup cosmosTypesStd_unit cosmosTypesStd Unit
** @ingroup cosmosTypes_module
** @brief cosmosTypesStd Unit
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
<!--                cosmosTypesStd Unit Global Group Definition               -->
*********************************************************************************
** @defgroup Global_cosmosTypesStd Global
** @ingroup cosmosTypesStd_unit
** @brief cosmosTypesStd globals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __COSMOSTYPESSTD_H__
#define __COSMOSTYPESSTD_H__
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
  * @defgroup Macros_cosmosTypesStd_h Macros
  * @ingroup Global_cosmosTypesStd
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_cosmosTypesStd_h
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
  * @defgroup Typedefs_cosmosTypesStdCfg_h Typedefs
  * @ingroup Global_cosmosTypesStd
  * @{
********************************************************************************/
typedef struct CosmOS_ChannelConfigurationType CosmOS_ChannelConfigurationType;
typedef struct CosmOS_SysJobsGroupConfigurationType
    CosmOS_SysJobsGroupConfigurationType;
typedef struct CosmOS_ProgramSectionConfigurationType
    CosmOS_ProgramSectionConfigurationType;
typedef struct CosmOS_BootSectionConfigurationType
    CosmOS_BootSectionConfigurationType;
typedef struct CosmOS_PermissionsConfigurationType
    CosmOS_PermissionsConfigurationType;
typedef struct CosmOS_RoutesConfigurationType CosmOS_RoutesConfigurationType;
typedef struct CosmOS_BufferConfigurationType CosmOS_BufferConfigurationType;
typedef struct CosmOS_BufferDoublePairConfigurationType
    CosmOS_BufferDoublePairConfigurationType;
typedef struct CosmOS_BufferDoubleConfigurationType
    CosmOS_BufferDoubleConfigurationType;
typedef struct CosmOS_StackConfigurationType CosmOS_StackConfigurationType;
typedef struct CosmOS_HeapConfigurationType CosmOS_HeapConfigurationType;
typedef struct CosmOS_SchedulableConfigurationType
    CosmOS_SchedulableConfigurationType;
typedef struct CosmOS_TaskConfigurationType CosmOS_TaskConfigurationType;
typedef struct CosmOS_ThreadConfigurationType CosmOS_ThreadConfigurationType;
typedef struct CosmOS_ProgramConfigurationType CosmOS_ProgramConfigurationType;
typedef struct CosmOS_ScheduleTableConfigurationType
    CosmOS_ScheduleTableConfigurationType;
typedef struct CosmOS_ThreadListConfigurationType
    CosmOS_ThreadListConfigurationType;
typedef struct CosmOS_AlarmConfigurationType CosmOS_AlarmConfigurationType;
typedef struct CosmOS_SchedulerConfigurationType
    CosmOS_SchedulerConfigurationType;
typedef struct CosmOS_SysJobsConfigurationType CosmOS_SysJobsConfigurationType;
typedef struct CosmOS_CoreConfigurationType CosmOS_CoreConfigurationType;
typedef struct CosmOS_OsEventConfigurationType CosmOS_OsEventConfigurationType;
typedef struct CosmOS_OsConfigurationType CosmOS_OsConfigurationType;
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_GenericVoidType void pointer type
********************************************************************************/
typedef void ( *CosmOS_GenericVoidType )( void );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_Generic_bitWidthType_ret_void type
********************************************************************************/
typedef void ( *CosmOS_Generic_bitWidthType_ret_void )( BitWidthType );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_Generic_bitWidthType_ret_bitWidthType type
********************************************************************************/
typedef BitWidthType ( *CosmOS_Generic_bitWidthType_ret_bitWidthType )(
    BitWidthType );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_Generic_bitWidthType_bitWidthType_ret_bitWidthType type
********************************************************************************/
typedef BitWidthType (
    *CosmOS_Generic_bitWidthType_bitWidthType_ret_bitWidthType )(
    BitWidthType,
    BitWidthType );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_Generic_bitWidthType_voidPtr_bitWidthType_ret_bitWidthType type
********************************************************************************/
typedef BitWidthType (
    *CosmOS_Generic_bitWidthType_voidPtr_bitWidthType_ret_bitWidthType )(
    BitWidthType,
    void *,
    BitWidthType );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_Generic_bitWidthType_voidPtr_bitWidthType_ret_bitWidthType type
********************************************************************************/
typedef BitWidthType ( *CosmOS_Generic_bitWidthType_voidPtr_ret_bitWidthType )(
    BitWidthType,
    void * );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief
  * CosmOS_Generic_bitWidthType_voidPtr_voidPtr_bitWidthType_ret_bitWidthType
  * type
********************************************************************************/
typedef BitWidthType (
    *CosmOS_Generic_bitWidthType_voidPtr_voidPtr_bitWidthType_ret_bitWidthType )(
    BitWidthType,
    void *,
    void *,
    BitWidthType );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief
  * CosmOS_Generic_bitWidthType_voidPtr_voidPtr_bitWidthType_ret_bitWidthType
  * type
********************************************************************************/
typedef BitWidthType (
    *CosmOS_Generic_bitWidthType_voidPtr_bitWidthType_bitWidthType_ret_bitWidthType )(
    BitWidthType,
    void *,
    BitWidthType,
    BitWidthType );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_BooleanType enum
********************************************************************************/
typedef enum
{
    False = 0x00,
    True = 0x01
} CosmOS_BooleanType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_OsVariableType struct type
********************************************************************************/
typedef struct
{
    BitWidthType channelId;

} CosmOS_ChannelEventType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_AccessStateType enum
********************************************************************************/
typedef enum
{

    ACCESS_STATE_ENUM__ALLOWED,
    ACCESS_STATE_ENUM__DENIED,

} CosmOS_AccessStateType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_BufferStateType enum
********************************************************************************/
typedef enum
{

    BUFFER_STATE_ENUM__OK = 0,
    BUFFER_STATE_ENUM__EMPTY = 1,
    BUFFER_STATE_ENUM__FULL = 2,
    BUFFER_STATE_ENUM__ERROR_INVALID_ID = -1,
    BUFFER_STATE_ENUM__ERROR_ACCESS_DENIED = -2,
    BUFFER_STATE_ENUM__ERROR_BUFFER_OCCUPIED = -3,
    BUFFER_STATE_ENUM__ERROR_INPUT_ARRAY_IS_PROTECTED = -4,
    BUFFER_STATE_ENUM__ERROR_SIZE_BIGGER_THAN_EMPTY_CELLS = -5,
    BUFFER_STATE_ENUM__ERROR_SIZE_BIGGER_THAN_FULL_CELLS_NUM = -6,

} CosmOS_BufferStateType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_BufferDoubleAccessType enum
********************************************************************************/
typedef enum
{

    BUFFER_DOUBLE_ACCESS_ENUM__USER,
    BUFFER_DOUBLE_ACCESS_ENUM__KERNEL,

} CosmOS_BufferDoubleAccessType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_ChannelPoolStateType enum
********************************************************************************/
typedef enum
{

    CHANNEL_POOL_STATE_ENUM__EMPTY,
    CHANNEL_POOL_STATE_ENUM__WAITING_TO_BE_PROCESSED,

} CosmOS_ChannelPoolStateType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_ChannelStateType enum
********************************************************************************/
typedef enum
{
    CHANNEL_STATE_ENUM__INITIALIZED = 0,
    CHANNEL_STATE_ENUM__RECEIVED = 1,
    CHANNEL_STATE_ENUM__NOT_RECEIVED = 2,
    CHANNEL_STATE_ENUM__REPLIED = 3,
    CHANNEL_STATE_ENUM__ERROR_INVALID_CHANNEL_ID = -1,
    CHANNEL_STATE_ENUM__ERROR_ACCESS_DENIED = -2,
    CHANNEL_STATE_ENUM__ERROR_CHANNEL_NOT_INITIALIZED = -3,
    CHANNEL_STATE_ENUM__ERROR_DATA_TO_SEND_BIGGER_THAN_POOL = -4,
    CHANNEL_STATE_ENUM__ERROR_DATA_TO_RECEIVE_BIGGER_THAN_POOL = -5,
    CHANNEL_STATE_ENUM__ERROR_ONLY_THREADS_CAN_USE_CHANNEL = -6,
    CHANNEL_STATE_ENUM__ERROR_CAN_BE_CALLED_ONLY_FROM_UNPRIVILEGED = -7,
    CHANNEL_STATE_ENUM__ERROR_CHANNEL_OCCUPIED = -8,
    CHANNEL_STATE_ENUM__ERROR_NO_REPLY_EXPECTED = -9,
    CHANNEL_STATE_ENUM__ERROR_CHANNEL_ALREADY_INITIALIZED = -10,

} CosmOS_ChannelStateType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_SchedulableInstanceType enum
********************************************************************************/
typedef enum
{

    SCHEDULABLE_INSTANCE_ENUM__TASK,
    SCHEDULABLE_INSTANCE_ENUM__THREAD,

} CosmOS_SchedulableInstanceType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_SchedulableStateType enum
********************************************************************************/
typedef enum
{

    SCHEDULABLE_STATE_ENUM__RUNNING,
    SCHEDULABLE_STATE_ENUM__EXECUTED,
    SCHEDULABLE_STATE_ENUM__BLOCKED,
    SCHEDULABLE_STATE_ENUM__SLEEP,
    SCHEDULABLE_STATE_ENUM__LISTENING,
    SCHEDULABLE_STATE_ENUM__WAITING_FOR_REPLY,
    SCHEDULABLE_STATE_ENUM__READY,

} CosmOS_SchedulableStateType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_SleepStateType enum
********************************************************************************/
typedef enum
{

    SLEEP_STATE_ENUM__OK = 0,
    SLEEP_STATE_ENUM__ERROR_ONLY_THREADS_CAN_SLEEP = -1,
    SLEEP_STATE_ENUM__ERROR_EXCEEDING_MAX = -2,
    SLEEP_STATE_ENUM__ERROR_MIN = -3,

} CosmOS_SleepStateType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_SchedulerSyncStateType enum
********************************************************************************/
typedef enum
{

    SCHEDULER_SYNC_STATE_ENUM__NOT_IN_SYNC,
    SCHEDULER_SYNC_STATE_ENUM__IN_SYNC,

} CosmOS_SchedulerSyncStateType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_BarrierStateType enum
********************************************************************************/
typedef enum
{

    BARRIER_STATE_ENUM__ACTIVATED,
    BARRIER_STATE_ENUM__REACHED,

} CosmOS_BarrierStateType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_BarrierStateType enum
********************************************************************************/
typedef enum
{

    ALARM_STATE_ENUM__DISABLED,
    ALARM_STATE_ENUM__ACTIVATED,

} CosmOS_AlarmStateType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_OsStateType enum
********************************************************************************/
typedef enum
{

    OS_STATE_ENUM__NOT_INITIALIZED,
    OS_STATE_ENUM__INITIALIZED,
    OS_STATE_ENUM__STARTED,
    OS_STATE_ENUM__ERROR_HOOK,

} CosmOS_OsStateType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_SchedulerStateType enum
********************************************************************************/
typedef enum
{

    SCHEDULER_STATE_ENUM__TASK_EXECUTED_IN_WCET_CHECK,
    SCHEDULER_STATE_ENUM__WAITING_FOR_START_TIME,
    SCHEDULER_STATE_ENUM__NOT_STARTED,

} CosmOS_SchedulerStateType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_RescheduleTriggerStateType enum
********************************************************************************/
typedef enum
{

    RESCHEDULE_TRIGGER_STATE_ENUM__SYSTEM,
    RESCHEDULE_TRIGGER_STATE_ENUM__TIMER,

} CosmOS_RescheduleTriggerStateType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_SpinlockStateType enum
********************************************************************************/
typedef enum
{

    SPINLOCK_STATE_ENUM__RELEASED = 0,
    SPINLOCK_STATE_ENUM__OCCUPIED = 1,
    SPINLOCK_STATE_ENUM__SUCCESSFULLY_LOCKED = 2,
    SPINLOCK_STATE_ENUM__ERROR_SCHEDULABLE_IS_NOT_OWNER = -3,
    SPINLOCK_STATE_ENUM__ERROR_NOT_IN_OCCUPIED_STATE = -4,
    SPINLOCK_STATE_ENUM__ERROR_INVALID_ID = -5,
    SPINLOCK_STATE_ENUM__ERROR_DEADLOCK = -6,

    SPINLOCK_STATE_ENUM__MAKE_ENUM_BITWIDTH_SIZE = FORCE_ENUM,

} CosmOS_SpinlockStateType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_SpinlockStateType enum
********************************************************************************/
typedef enum
{

    MUTEX_STATE_ENUM__RELEASED = 0,
    MUTEX_STATE_ENUM__OCCUPIED = 1,
    MUTEX_STATE_ENUM__SUCCESSFULLY_LOCKED = 2,
    MUTEX_STATE_ENUM__ERROR_SCHEDULABLE_IS_NOT_OWNER = -1,
    MUTEX_STATE_ENUM__ERROR_NOT_IN_OCCUPIED_STATE = -2,
    MUTEX_STATE_ENUM__ERROR_ONLY_THREADS_CAN_MUTEX = -3,
    MUTEX_STATE_ENUM__ERROR_INVALID_MUTEX_ADDRESS = -4,
    MUTEX_STATE_ENUM__ERROR_DEADLOCK = -5,

    MUTEX_STATE_ENUM__MAKE_ENUM_BITWIDTH_SIZE = FORCE_ENUM,

} CosmOS_MutexStateType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  CosmOS_OsEventStateType enum
********************************************************************************/
typedef enum
{
    OS_EVENT_STATE_ENUM__OK = 0,
    OS_EVENT_STATE_ENUM__ERROR_ATLEAST_ONE_CORE_MUST_HANDLE_EVENT = -1,
    OS_EVENT_STATE_ENUM__ERROR_INVALID_EVENT = -2,
    OS_EVENT_STATE_ENUM__ERROR_DATA_BIGGER_THAN_DATA_POOL_SIZE = -3,

} CosmOS_OsEventStateType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief  ForceEnums enum
********************************************************************************/
typedef enum
{
    MUTEX_FORCE = MUTEX_STATE_ENUM__MAKE_ENUM_BITWIDTH_SIZE,
    SPINLOCK_FORCE = SPINLOCK_STATE_ENUM__MAKE_ENUM_BITWIDTH_SIZE,

} ForceEnums;
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Typedefs_cosmosTypesStd_h
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
