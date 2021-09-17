/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file schedulable.c
*********************************************************************************
<!--                 schedulable Unit Local Group Definition                  -->
*********************************************************************************
** @defgroup Local_schedulable Local
** @ingroup schedulable_unit
** @brief schedulable locals
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
#include "scheduler.h"
#include "alarm.h"
#include "core.h"

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
  * @defgroup Macros_schedulable Macros
  * @ingroup Local_schedulable
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Macros_schedulable
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
  * @defgroup Variables_schedulable Variables
  * @ingroup Local_schedulable
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Variables_schedulable
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
  * @defgroup Apis_schedulable_c API's
  * @ingroup Local_schedulable
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_schedulable_c Getters
  * @ingroup Apis_schedulable_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Getters_schedulable_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_schedulable_c Setters
  * @ingroup Apis_schedulable_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Setters_schedulable_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_schedulable_c General
  * @ingroup Apis_schedulable_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_schedulable_c
********************************************************************************/
/********************************************************************************
**                         Function Prototypes | Stop                          **
********************************************************************************/
/********************************************************************************
**                        Function Definitions | Start                         **
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn schedulable_sleepMs(BitWidthType entityId, BitWidthType delayMs)
  *
  * @brief Set schedulable to sleep for x ms DEMO CODE.
  *
  * @param[in]  BitWidthType entityId
  * @param[in]  BitWidthType delayMs
  *
  * @return none
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION void schedulable_sleepMs(BitWidthType entityId, BitWidthType delayMs)
{
	BitWidthType alarmId,
					msToTicks,
					tickCount;

	CosmOS_SchedulableInstanceType schedulableInstanceType;

	CosmOS_AlarmVariableType * alarmVar;
	CosmOS_CoreVariableType * coreVar;
    CosmOS_SchedulableVariableType * schedulableVar;


	coreVar = core_getCoreVar();

	msToTicks = core_getMsToTicks(coreVar);

	schedulableVar = core_getCoreSchedulableInExecution(coreVar);
	schedulableInstanceType = schedulable_getInstanceType(schedulableVar);

	if (schedulableInstanceType IS_EQUAL_TO SCHEDULABLE_INSTANCE_ENUM__THREAD)
	{
		alarmId = schedulable_getAlarmId(schedulableVar);
		alarmVar = core_getAlarmVar(coreVar, alarmId);
		//overflow needs to be checked for this multiplication and return err if overflows
		tickCount = delayMs * msToTicks;

		schedulable_setState(schedulableVar, SCHEDULABLE_STATE_ENUM__SLEEP);
		alarm_setAlarmTickCount(alarmVar,tickCount);
		alarm_setAlarmState(alarmVar,ALARM_STATE_ENUM__ACTIVATED);

		CILinterrupt_contextSwitchRoutineTrigger();
	}
	else
	{
		//error critical tasks cannot be preempted
	}

	__SUPRESS_UNUSED_VAR(entityId);
};
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn schedulable_setExecutionStateToFinished(BitWidthType entityId)
  *
  * @brief Set schedulable execution state to finished DEMO CODE.
  *
  * @param[in]  BitWidthType entityId
  *
  * @return none
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION void schedulable_setExecutionStateToFinished(BitWidthType entityId)
{
    CosmOS_CoreVariableType * coreVar;
    CosmOS_SchedulableVariableType * schedulableVar;


    coreVar = core_getCoreVar();

    schedulableVar = core_getCoreSchedulableInExecution( coreVar );

    schedulable_setState( schedulableVar, SCHEDULABLE_STATE_ENUM__EXECUTED );

	__SUPRESS_UNUSED_VAR(entityId);
};
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/
/********************************************************************************
**                        Function Definitions | Stop                          **
********************************************************************************/
/********************************************************************************
**                           END OF THE SOURCE FILE                            **
********************************************************************************/
