/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file alarm.h
*********************************************************************************
<!--                       alarm Module Group Definition                      -->
*********************************************************************************
** @defgroup alarm_module alarm
** @brief alarm Module
** @details lorem
*********************************************************************************
<!--                        alarm Unit Group Definition                       -->
*********************************************************************************
** @defgroup alarm_unit alarm Unit
** @ingroup alarm_module
** @brief alarm Unit
** @details lorem
*********************************************************************************
<!--                           Version Information                            -->
*********************************************************************************
** @version 1.0.0
** @date 18.08.2021
** @author https://github.com/pavolkostolansky
*********************************************************************************
<!--                          Warnings and License                            -->
*********************************************************************************
** @warning Modifying code can lead to unexpected behaviour of the whole system
** @copyright MIT License
*********************************************************************************
<!--                   alarm Unit Global Group Definition                     -->
*********************************************************************************
** @defgroup Global_alarm Global
** @ingroup alarm_unit
** @brief alarm globals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __ALARM_H__
#define __ALARM_H__
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
#include "cosmosTypes.h"
#include "memoryMapping.h"
#include "sysDefs.h"

/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_alarm_h Macros
  * @ingroup Global_alarm
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_alarm_h
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
  * @defgroup Variables_alarm_h Variables
  * @ingroup Global_alarm
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_alarm_h
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
  * @defgroup Apis_alarm_h API's
  * @ingroup Global_alarm
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_alarm_h Getters
  * @ingroup Apis_alarm_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_alarm_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_alarm_h Setters
  * @ingroup Apis_alarm_h
  * @{
********************************************************************************/

/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_alarm_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_alarm_h General
  * @ingroup Apis_alarm_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn alarm_expire(CosmOS_AlarmConfigurationType * alarm)
  *
  * @brief Alarm expire function needs to be called when the internal timer
  * expire. This function cannot be called from the unprivileged context
  * directly. DEMO
  *
  * @param[in]  alarm configuration pointer
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void
alarm_expire( CosmOS_AlarmConfigurationType * alarm );
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_alarm_h
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
  * @addtogroup Getters_alarm_h Getters
  * @ingroup Apis_alarm_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn alarm_getAlarmSchedulable(CosmOS_AlarmConfigurationType * alarm)
  *
  * @brief Get alarm schedulable pointer.
  *
  * @param[in]  alarm configuration pointer
  *
  * @return CosmOS_SchedulableConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_SchedulableConfigurationType *
alarm_getAlarmSchedulable( CosmOS_AlarmConfigurationType * alarm )
{
    return (CosmOS_SchedulableConfigurationType *)( alarm->schedulableCfg );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn alarm_getAlarmState(CosmOS_AlarmConfigurationType * alarm)
  *
  * @brief Get alarm state.
  *
  * @param[in]  alarm configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
alarm_getAlarmState( CosmOS_AlarmConfigurationType * alarm )
{
    return ( alarm->var->state );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn alarm_getAlarmTickCount(CosmOS_AlarmConfigurationType * alarm)
  *
  * @brief Get alarm tickCount.
  *
  * @param[in]  alarm configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
alarm_getAlarmTickCount( CosmOS_AlarmConfigurationType * alarm )
{
    return ( alarm->var->tickCount );
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_alarm_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_alarm_h Setters
  * @ingroup Apis_alarm_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn alarm_setAlarmState(CosmOS_AlarmConfigurationType * alarm,
  * CosmOS_AlarmStateType stateParam)
  *
  * @brief Set alarm state. This function cannot be called
  * from the unprivileged context directly.
  *
  * @param[out]  alarm configuration pointer
  * @param[in]  stateParam state of the alarm
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
alarm_setAlarmState(
    CosmOS_AlarmConfigurationType * alarm,
    CosmOS_AlarmStateType stateParam )
{
    alarm->var->state = stateParam;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn alarm_setAlarmTickCount(CosmOS_AlarmConfigurationType * alarm,
  * BitWidthType tickCountParam)
  *
  * @brief Set alarm tickCount. This function cannot be called
  * from the unprivileged context directly.
  *
  * @param[out]  alarm configuration pointer
  * @param[in]  tickCountParam number of ticks to load internal timer
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
alarm_setAlarmTickCount(
    CosmOS_AlarmConfigurationType * alarm,
    BitWidthType tickCountParam )
{
    alarm->var->tickCount = tickCountParam;
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_alarm_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_alarm_h General
  * @ingroup Apis_alarm_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_alarm_h
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
