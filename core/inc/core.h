/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file core.h
*********************************************************************************
<!--                       core Module Group Definition                       -->
*********************************************************************************
** @defgroup core_module core
** @brief core Module
** @details lorem
*********************************************************************************
<!--                        core Unit Group Definition                        -->
*********************************************************************************
** @defgroup core_unit Core Unit
** @ingroup core_module
** @brief core Unit
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
<!--                     core Unit Global Group Definition                    -->
*********************************************************************************
** @defgroup Global_core Global
** @ingroup core_unit
** @brief core globals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __CORE_H__
#define __CORE_H__
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
  * @defgroup Macros_core_h Macros
  * @ingroup Global_core
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_core_h
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
  * @defgroup Variables_core_h Variables
  * @ingroup Global_core
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_core_h
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
  * @defgroup Apis_core_h API's
  * @ingroup Global_core
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_core_h Getters
  * @ingroup Apis_core_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_core_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_core_h Setters
  * @ingroup Apis_core_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getCoreVar( void )
  *
  * @brief Get current core variable. This function can be called
  * from the unprivileged context directly.
  *
  * @param[in]  none
  *
  * @return CosmOS_CoreVariableType *
********************************************************************************/
__OS_FUNC_SECTION CosmOS_CoreVariableType *
core_getCoreVar( void );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_setSchedulableIntoCurrentContext(CosmOS_CoreVariableType * coreVar,
  * CosmOS_TaskVariableType * taskVar)
  *
  * @brief Set program and schedulable into the current context. This function
  * cannot be called from the unprivileged context directly.
  *
  * @param[out]  core variable pointerVar
  * @param[in]  schedulableVar variable pointer
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void
core_setSchedulableIntoCurrentContext(
    CosmOS_CoreVariableType * coreVar,
    CosmOS_SchedulableVariableType * schedulableVar );
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_core_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_core_h General
  * @ingroup Apis_core_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_core_h
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
  * @addtogroup Getters_core_h Getters
  * @ingroup Apis_core_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getCorePrograms(CosmOS_CoreVariableType * core)
  *
  * @brief Get core programs pointer.
  *
  * @param[in]  core variable pointer
  *
  * @return CosmOS_ProgramConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_ProgramConfigurationType *
core_getCorePrograms( CosmOS_CoreVariableType * core )
{
    return (CosmOS_ProgramConfigurationType *)( core->cfg->programs );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getCoreNumberOfPrograms(CosmOS_CoreVariableType * core)
  *
  * @brief Get core numberOfPrograms.
  *
  * @param[in]  core variable pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
core_getCoreNumberOfPrograms( CosmOS_CoreVariableType * core )
{
    return ( core->cfg->numberOfPrograms );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getCoreScheduler(CosmOS_CoreVariableType * core)
  *
  * @brief Get core scheduler pointer.
  *
  * @param[in]  core variable pointer
  *
  * @return CosmOS_SchedulerConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_SchedulerConfigurationType *
core_getCoreScheduler( CosmOS_CoreVariableType * core )
{
    return (CosmOS_SchedulerConfigurationType *)( core->cfg->scheduler );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getCoreId(CosmOS_CoreVariableType * core)
  *
  * @brief Get coreId.
  *
  * @param[in]  core variable pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
core_getCoreId( CosmOS_CoreVariableType * core )
{
    return ( core->cfg->coreId );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getKernelPanicHook(CosmOS_CoreVariableType * coreVar)
  *
  * @brief Get core kernelPanicHook.
  *
  * @param[in]  core variable pointerVar
  *
  * @return CosmOS_GenericVoidType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_GenericVoidType
core_getKernelPanicHook( CosmOS_CoreVariableType * coreVar )
{
    return ( CosmOS_GenericVoidType )( coreVar->cfg->kernelPanicHook );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getStackMemoryLowAddress(CosmOS_CoreVariableType * core)
  *
  * @brief Get stackMemoryLowAddress.
  *
  * @param[in]  core variable pointer
  *
  * @return AddressType
********************************************************************************/
__STATIC_FORCEINLINE AddressType
core_getStackMemoryLowAddress( CosmOS_CoreVariableType * core )
{
    return ( core->cfg->stackMemoryLowAddress );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getStackMemoryHighAddress(CosmOS_CoreVariableType * core)
  *
  * @brief Get stackMemoryHighAddress.
  *
  * @param[in]  core variable pointer
  *
  * @return AddressType
********************************************************************************/
__STATIC_FORCEINLINE AddressType
core_getStackMemoryHighAddress( CosmOS_CoreVariableType * core )
{
    return ( core->cfg->stackMemoryHighAddress );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getCodeMemoryLowAddress(CosmOS_CoreVariableType * core)
  *
  * @brief Get codeMemoryLowAddress.
  *
  * @param[in]  core variable pointer
  *
  * @return AddressType
********************************************************************************/
__STATIC_FORCEINLINE AddressType
core_getCodeMemoryLowAddress( CosmOS_CoreVariableType * core )
{
    return ( core->cfg->codeMemoryLowAddress );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getCodeMemoryHighAddress(CosmOS_CoreVariableType * core)
  *
  * @brief Get codeMemoryHighAddress.
  *
  * @param[in]  core variable pointer
  *
  * @return AddressType
********************************************************************************/
__STATIC_FORCEINLINE AddressType
core_getCodeMemoryHighAddress( CosmOS_CoreVariableType * core )
{
    return ( core->cfg->codeMemoryHighAddress );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getUnprotectedMemoryLowAddress(CosmOS_CoreVariableType * core)
  *
  * @brief Get unprotectedMemoryLowAddress.
  *
  * @param[in]  core variable pointer
  *
  * @return AddressType
********************************************************************************/
__STATIC_FORCEINLINE AddressType
core_getUnprotectedMemoryLowAddress( CosmOS_CoreVariableType * core )
{
    return ( core->cfg->unprotectedMemoryLowAddress );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getUnprotectedMemoryHighAddress(CosmOS_CoreVariableType * core)
  *
  * @brief Get unprotectedMemoryHighAddress.
  *
  * @param[in]  core variable pointer
  *
  * @return AddressType
********************************************************************************/
__STATIC_FORCEINLINE AddressType
core_getUnprotectedMemoryHighAddress( CosmOS_CoreVariableType * core )
{
    return ( core->cfg->unprotectedMemoryHighAddress );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getMsToTicks(CosmOS_CoreVariableType * core)
  *
  * @brief Get msToTicks.
  *
  * @param[in]  core variable pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
core_getMsToTicks( CosmOS_CoreVariableType * core )
{
    return ( core->cfg->msToTicks );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getCoreNumberOfAlarms(CosmOS_CoreVariableType * core)
  *
  * @brief Get core numberOfAlarms.
  *
  * @param[in]  core variable pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
core_getCoreNumberOfAlarms( CosmOS_CoreVariableType * core )
{
    return ( core->cfg->numberOfAlarms );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getCoreSchedulableInExecution(CosmOS_CoreVariableType * core)
  *
  * @brief Get core schedulableInExecution pointer.
  *
  * @param[in]  core variable pointer
  *
  * @return CosmOS_SchedulableVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_SchedulableVariableType *
core_getCoreSchedulableInExecution( CosmOS_CoreVariableType * core )
{
    return ( core->schedulableInExecution );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getCoreProgramInExecution(CosmOS_CoreVariableType * core)
  *
  * @brief Get core programInExecution pointer.
  *
  * @param[in]  core variable pointer
  *
  * @return CosmOS_ProgramVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_ProgramVariableType *
core_getCoreProgramInExecution( CosmOS_CoreVariableType * core )
{
    return ( core->programInExecution );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getCoreProgramVars(CosmOS_CoreVariableType * core)
  *
  * @brief Get core programVars.
  *
  * @param[in]  core variable pointer
  *
  * @return CosmOS_ProgramVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_ProgramVariableType *
core_getCoreProgramVars( CosmOS_CoreVariableType * core )
{
    return ( core->programVars );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getCoreProgramVar(CosmOS_CoreVariableType * core,
  * BitWidthType programIterator)
  *
  * @brief Get core programVar element pointer.
  *
  * @param[in]  core variable pointer
  * @param[in]  programIterator required program id
  *
  * @return CosmOS_ProgramVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_ProgramVariableType *
core_getCoreProgramVar(
    CosmOS_CoreVariableType * core,
    BitWidthType programIterator )
{
    return ( &( core->programVars[programIterator] ) );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getCoreSchedulerVar(CosmOS_CoreVariableType * core)
  *
  * @brief Get core scheduler pointer.
  *
  * @param[in]  core variable pointer
  *
  * @return CosmOS_SchedulerVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_SchedulerVariableType *
core_getCoreSchedulerVar( CosmOS_CoreVariableType * core )
{
    return ( core->schedulerVar );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getCoreBarrierVars(CosmOS_CoreVariableType * core)
  *
  * @brief Get core barrierVars pointer.
  *
  * @param[in]  core variable pointer
  *
  * @return CosmOS_BarrierVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BarrierVariableType *
core_getCoreBarrierVars( CosmOS_CoreVariableType * core )
{
    return ( core->barrierVars );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getBarrierVar(CosmOS_CoreVariableType * core,
  * BitWidthType * barrierId)
  *
  * @brief Get barrierVars element pointer.
  *
  * @param[in]  core variable pointer
  * @param[in]  barrierId required barrier id
  *
  * @return CosmOS_BarrierVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BarrierVariableType *
core_getBarrierVar( CosmOS_CoreVariableType * core, BitWidthType barrierId )
{
    return ( &( core->barrierVars[barrierId] ) );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getCoreOsState(CosmOS_CoreVariableType * core)
  *
  * @brief Get core osState.
  *
  * @param[in]  core variable pointer
  *
  * @return CosmOS_OsStateType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_OsStateType
core_getCoreOsState( CosmOS_CoreVariableType * core )
{
    return ( core->osState );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getCoreSysJobs(CosmOS_CoreVariableType * core)
  *
  * @brief Get core sysJobs.
  *
  * @param[in]  core variable pointer
  *
  * @return CosmOS_SysJobsVariableType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_SysJobsVariableType *
core_getCoreSysJobs( CosmOS_CoreVariableType * core )
{
    return ( core->sysJobs );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getCoreAlarmVars(CosmOS_CoreVariableType * core)
  *
  * @brief Get core alarmVars.
  *
  * @param[in]  core variable pointer
  *
  * @return CosmOS_AlarmVariableType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_AlarmVariableType *
core_getCoreAlarmVars( CosmOS_CoreVariableType * core )
{
    return ( core->alarmVars );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getAlarmVar(CosmOS_CoreVariableType * core,
  * BitWidthType * barrierId)
  *
  * @brief Get alarmVars element pointer.
  *
  * @param[in]  core variable pointer
  * @param[in]  alarmId required alarm id
  *
  * @return CosmOS_AlarmVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_AlarmVariableType *
core_getAlarmVar( CosmOS_CoreVariableType * core, BitWidthType alarmId )
{
    return ( &( core->alarmVars[alarmId] ) );
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_core_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_core_h Setters
  * @ingroup Apis_core_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_setCoreProgramInExecution(CosmOS_CoreVariableType * core,
  * CosmOS_ProgramVariableType * programInExecutionParam)
  *
  * @brief Set core programInExecution pointer. This function cannot be called
  * from the unprivileged context directly.
  *
  * @param[out]  core variable pointer
  * @param[in]  programInExecutionParam variable pointer
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
core_setCoreProgramInExecution(
    CosmOS_CoreVariableType * core,
    CosmOS_ProgramVariableType * programInExecutionParam )
{
    core->programInExecution = programInExecutionParam;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_setCoreSchedulableInExecution(CosmOS_CoreVariableType * core,
  * CosmOS_SchedulableVariableType * schedulableInExecutionParam)
  *
  * @brief Set core schedulableInExecution pointer. This function cannot be
  * called from the unprivileged context directly.
  *
  * @param[out]  core variable pointer
  * @param[in]  schedulableInExecutionParam variable pointer
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
core_setCoreSchedulableInExecution(
    CosmOS_CoreVariableType * core,
    CosmOS_SchedulableVariableType * schedulableInExecutionParam )
{
    core->schedulableInExecution = schedulableInExecutionParam;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_setCoreOsState(CosmOS_CoreVariableType * core)
  *
  * @brief Set core osState. This function cannot be called
  * from the unprivileged context directly.
  *
  * @param[out]  core variable pointer
  * @param[in]  osStateParam state of the operating system
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
core_setCoreOsState(
    CosmOS_CoreVariableType * core,
    CosmOS_OsStateType osStateParam )
{
    core->osState = osStateParam;
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_core_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_core_h General
  * @ingroup Apis_core_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_core_h
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
