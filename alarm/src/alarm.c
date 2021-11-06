/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file alarm.c
*********************************************************************************
<!--                     alarm Unit Local Group Definition                    -->
*********************************************************************************
** @defgroup Local_alarm Local
** @ingroup alarm_unit
** @brief alarm locals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
#include "alarm.h"
#include "schedulable.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_alarm_c Macros
  * @ingroup Local_alarm
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_alarm_c
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
  * @defgroup Variables_alarm_c Variables
  * @ingroup Local_alarm
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_alarm_c
********************************************************************************/
/********************************************************************************
**                              Variables | Stop                               **
********************************************************************************/
/********************************************************************************
**                         Function Prototypes | Start                         **
********************************************************************************/
/********************************************************************************
* DOXYGEN DEF GROUP                                                            **
* ***************************************************************************//**
* @defgroup Apis_alarm_c API's
* @ingroup Local_alarm
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_alarm_c Getters
  * @ingroup Apis_alarm_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_alarm_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_alarm_c Setters
  * @ingroup Apis_alarm_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_alarm_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_alarm_c General
  * @ingroup Apis_alarm_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn alarm_expire(CosmOS_AlarmConfigurationType *alarm)
  *
  * @details The implementation contains call to alarm_getAlarmSchedulable to get
  * alarm linked thread and set it again with calling schedulable_setState
  * function with argument SCHEDULABLE_STATE_ENUM__READY, then the alarm is
  * disabled with calling alarm_setAlarmState with argument
  * ALARM_STATE_ENUM__DISABLED (alarm is no longer updated in scheduler) and
  * finally alarm internal timer is reset to 0 with calling function
  * alarm_setAlarmTickCount
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
alarm_expire( CosmOS_AlarmConfigurationType * alarm )
{
    CosmOS_SchedulableConfigurationType * schedulableCfg;

    schedulableCfg = alarm_getAlarmSchedulable( alarm );

    schedulable_setState( schedulableCfg, SCHEDULABLE_STATE_ENUM__READY );
    alarm_setAlarmState( alarm, ALARM_STATE_ENUM__DISABLED );
    alarm_setAlarmTickCount( alarm, 0 );
};
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_alarm_c
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
