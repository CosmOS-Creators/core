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
#include "schedulable.h"
#include "alarm.h"
#include "cosmosApiInternal.h"
#include "core.h"
#include "thread.h"

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
  * @}
  * Macros_thread
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
  * @}
  * Variables_thread
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
  * @}
  * Getters_thread_c
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
  * @}
  * Setters_thread_c
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
  * *************************************************************************//**
  * @fn thread_sleepMsInternal(BitWidthType entityId, CosmOS_CoreVariableType * coreVar, BitWidthType tickCount)
  *
  * @brief Set thread to sleep internal for x milliseconds DEMO CODE.
  *
  * @param[in]  BitWidthType entityId
  * @param[in]  CosmOS_CoreVariableType * coreVar
  * @param[in]  BitWidthType tickCount
  *
  * @return CosmOS_SleepStateType
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION CosmOS_SleepStateType thread_sleepMsInternal(BitWidthType entityId, CosmOS_CoreVariableType * coreVar, BitWidthType tickCount)
{
	BitWidthType alarmId;

	CosmOS_SleepStateType sleepStateReturn;

	CosmOS_AlarmVariableType * alarmVar;
    CosmOS_SchedulableVariableType * schedulableVar;


	schedulableVar = core_getCoreSchedulableInExecution(coreVar);

	alarmId = schedulable_getAlarmId(schedulableVar);
	alarmVar = core_getAlarmVar(coreVar, alarmId);

	schedulable_setState(schedulableVar, SCHEDULABLE_STATE_ENUM__SLEEP);
	alarm_setAlarmTickCount(alarmVar,tickCount);
	alarm_setAlarmState(alarmVar,ALARM_STATE_ENUM__ACTIVATED);

	sleepStateReturn = SLEEP_STATE_ENUM__OK;

	CILinterrupt_contextSwitchRoutineTrigger();

	return sleepStateReturn;
	__SUPRESS_UNUSED_VAR(entityId);
};
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn thread_sleepMs(BitWidthType delayMs)
  *
  * @brief Set thread to sleep for x milliseconds DEMO CODE.
  *
  * @param[in]  BitWidthType delayMs
  *
  * @return CosmOS_SleepStateType
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION CosmOS_SleepStateType thread_sleepMs(BitWidthType delayMs)
{
	BitWidthType msToTicks,
					tickCount;

	CosmOS_SleepStateType sleepStateReturn;
	CosmOS_SchedulableInstanceType schedulableInstanceType;

	CosmOS_CoreVariableType * coreVar;
    CosmOS_SchedulableVariableType * schedulableVar;


	if ( delayMs )
	{
		coreVar = core_getCoreVar();

		msToTicks = core_getMsToTicks(coreVar);

		schedulableVar = core_getCoreSchedulableInExecution(coreVar);
		schedulableInstanceType = schedulable_getInstanceType(schedulableVar);

		if (schedulableInstanceType IS_EQUAL_TO SCHEDULABLE_INSTANCE_ENUM__THREAD)
		{
			if ( __MUL_OVERFLOW(delayMs,msToTicks,&tickCount) )
			{
				sleepStateReturn = SLEEP_STATE_ENUM__ERROR_EXCEEDING_MAX;
			}
			else
			{
				sleepStateReturn = cosmosApiInternal_thread_sleepMsInternal(coreVar, tickCount);
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
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_thread_c
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
