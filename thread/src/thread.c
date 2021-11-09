/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file thread.c
*********************************************************************************
<!--                    thread Unit Local Group Definition                    -->
*********************************************************************************
** @defgroup Local_thread Local
** @ingroup thread_unit
** @brief thread locals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "thread.h"
#include "alarm.h"
#include "core.h"
#include "cosmosApiInternal.h"
#include "schedulable.h"
#include "scheduler.h"

/* CIL interfaces */
#include "CILinterrupt.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_thread Macros
  * @ingroup Local_thread
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_thread
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
  * @defgroup Variables_thread Variables
  * @ingroup Local_thread
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_thread
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
  * @defgroup Apis_thread_c API's
  * @ingroup Local_thread
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_thread_c Getters
  * @ingroup Apis_thread_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_thread_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_thread_c Setters
  * @ingroup Apis_thread_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_thread_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_thread_c General
  * @ingroup Apis_thread_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn thread_sleepMsInternal(BitWidthType entityId,
  * CosmOS_CoreConfigurationType * core,
  * BitWidthType tickCount)
  *
  * @details The implementation contains obtaining of the schedulable variable
  * in execution is obtained by the core_getCoreSchedulableInExecution function.
  * From the schedulable variable is then extracted the alarm id by calling
  * schedulable_getAlarmId function, this id is then used to get alarm variable
  * by calling function scheduler_getAlarmCfg. After this point is schedulable
  * variable state set to the SCHEDULABLE_STATE_ENUM__SLEEP by calling function
  * schedulable_setState. Subsequently the alarm needs to be configured,
  * therefore the alarm_setAlarmTickCount function is called with tickCount
  * argument to set internal timer of the alarm and also alarm state is set to
  * ALARM_STATE_ENUM__ACTIVATED by calling function alarm_setAlarmState to let
  * the scheduler know that this alarm needs to be updated from now. Sleep state
  * is set to the SLEEP_STATE_ENUM__OK and after calling the function for
  * triggering scheduler algorithm CILinterrupt_contextSwitchRoutineTrigger is
  * returned from the function.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_SleepStateType
thread_sleepMsInternal(
    BitWidthType entityId,
    CosmOS_CoreConfigurationType * core,
    BitWidthType tickCount )
{
    BitWidthType alarmId;

    CosmOS_SleepStateType sleepStateReturn;

    CosmOS_AlarmConfigurationType * alarmCfg;
    CosmOS_SchedulableConfigurationType * schedulableCfg;

    schedulableCfg = core_getCoreSchedulableInExecution( core );

    alarmId = schedulable_getAlarmId( schedulableCfg );
    alarmCfg = scheduler_getAlarmCfg(
        (CosmOS_SchedulerConfigurationType *)core->scheduler, alarmId );

    schedulable_setState( schedulableCfg, SCHEDULABLE_STATE_ENUM__SLEEP );
    alarm_setAlarmTickCount( alarmCfg, tickCount );
    alarm_setAlarmState( alarmCfg, ALARM_STATE_ENUM__ACTIVATED );

    sleepStateReturn = SLEEP_STATE_ENUM__OK;

    CILinterrupt_contextSwitchRoutineTrigger();

    return sleepStateReturn;
    __SUPRESS_UNUSED_VAR( entityId );
};
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn thread_sleepMs(BitWidthType delayMs)
  *
  * @details The implementation contains if condition that checks if delayMs is
  * non-zero value otherwise it returns sleepStateReturn
  * SLEEP_STATE_ENUM__ERROR_MIN. Then the core configuration is obtained by
  * calling core_getCoreCfg function and then the msToTicks is obtained by
  * calling core_getMsToTicks with core configuration argument.
  * After this point is necessary to know if the schedulable variable obtained
  * by core_getCoreSchedulableInExecution function is
  * SCHEDULABLE_INSTANCE_ENUM__THREAD therefore the schedulable type is obtained
  * by calling schedulable_getInstanceType and then check in the if condition,
  * otherwise the sleepStateReturn is set to the
  * SLEEP_STATE_ENUM__ERROR_ONLY_THREADS_CAN_SLEEP and returned.
  * After this point the __MUL_OVERFLOW function as macro is called to check if
  * required tickCount wont overflow otherwise the sleepStateReturn is set to
  * SLEEP_STATE_ENUM__ERROR_EXCEEDING_MAX and returned. Additionally the
  * tickCount has to be incremented by 1 calling the __ADD_OVERFLOW function
  * and check in the if condition if overflow wont happen otherwise the
  * sleepStateReturn is set to SLEEP_STATE_ENUM__ERROR_EXCEEDING_MAX and
  * returned. If there is no overflow the CosmOS internal API
  * cosmosApiInternal_thread_sleepMsInternal is called.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_SleepStateType
thread_sleepMs( BitWidthType delayMs )
{
    BitWidthType msToTicks, tickCount;

    CosmOS_SleepStateType sleepStateReturn;
    CosmOS_SchedulableInstanceType schedulableInstanceType;

    CosmOS_CoreConfigurationType * core;
    CosmOS_SchedulableConfigurationType * schedulableCfg;

    if ( delayMs )
    {
        core = core_getCoreCfg();

        msToTicks = core_getMsToTicks( core );

        schedulableCfg = core_getCoreSchedulableInExecution( core );
        schedulableInstanceType = schedulable_getInstanceType( schedulableCfg );

        if ( schedulableInstanceType IS_EQUAL_TO
                 SCHEDULABLE_INSTANCE_ENUM__THREAD )
        {
            if ( IS_NOT( __MUL_OVERFLOW( delayMs, msToTicks, &tickCount ) ) )
            {
                if ( IS_NOT( __ADD_OVERFLOW(
                         tickCount, (BitWidthType)1, &tickCount ) ) )
                {
                    sleepStateReturn = cosmosApiInternal_thread_sleepMsInternal(
                        core, tickCount );
                }
                else
                {
                    sleepStateReturn = SLEEP_STATE_ENUM__ERROR_EXCEEDING_MAX;
                }
            }
            else
            {
                sleepStateReturn = SLEEP_STATE_ENUM__ERROR_EXCEEDING_MAX;
            }
        }
        else
        {
            sleepStateReturn = SLEEP_STATE_ENUM__ERROR_ONLY_THREADS_CAN_SLEEP;
        }
    }
    else
    {
        sleepStateReturn = SLEEP_STATE_ENUM__ERROR_MIN;
    }

    return sleepStateReturn;
};
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_thread_c
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
