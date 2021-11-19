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
  * @fn core_getCoreCfg( void )
  *
  * @brief Get current core configuration. This function can be called
  * from the unprivileged context directly.
  *
  * @param[in]  none
  *
  * @return CosmOS_CoreConfigurationType *
********************************************************************************/
__OS_FUNC_SECTION CosmOS_CoreConfigurationType *
core_getCoreCfg( void );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_setSchedulableIntoCurrentContext(
  * CosmOS_CoreConfigurationType * core,
  * CosmOS_SchedulableConfigurationType * schedulableCfg)
  *
  * @brief Set program and schedulable into the current context. This function
  * cannot be called from the unprivileged context directly.
  *
  * @param[out]  core configuration pointer
  * @param[in]  schedulableCfg configuration pointer
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void
core_setSchedulableIntoCurrentContext(
    CosmOS_CoreConfigurationType * core,
    CosmOS_SchedulableConfigurationType * schedulableCfg );
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
  * @fn core_getCorePrograms(CosmOS_CoreConfigurationType * core)
  *
  * @brief Get core programs pointer.
  *
  * @param[in]  core configuration pointer
  *
  * @return CosmOS_ProgramConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_ProgramConfigurationType *
core_getCorePrograms( CosmOS_CoreConfigurationType * core )
{
    return (CosmOS_ProgramConfigurationType *)( core->programs );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getCoreNumberOfPrograms(CosmOS_CoreConfigurationType * core)
  *
  * @brief Get core numberOfPrograms.
  *
  * @param[in]  core configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
core_getCoreNumberOfPrograms( CosmOS_CoreConfigurationType * core )
{
    return ( core->numberOfPrograms );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getCoreId(CosmOS_CoreConfigurationType * core)
  *
  * @brief Get coreId.
  *
  * @param[in]  core configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
core_getCoreId( CosmOS_CoreConfigurationType * core )
{
    return ( core->coreId );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getKernelPanicHook(CosmOS_CoreConfigurationType * coreVar)
  *
  * @brief Get core kernelPanicHook.
  *
  * @param[in]  core configuration pointerVar
  *
  * @return CosmOS_GenericVoidType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_GenericVoidType
core_getKernelPanicHook( CosmOS_CoreConfigurationType * coreVar )
{
    return ( CosmOS_GenericVoidType )( coreVar->kernelPanicHook );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getStackMemoryLowAddress(CosmOS_CoreConfigurationType * core)
  *
  * @brief Get stackMemoryLowAddress.
  *
  * @param[in]  core configuration pointer
  *
  * @return AddressType
********************************************************************************/
__STATIC_FORCEINLINE AddressType
core_getStackMemoryLowAddress( CosmOS_CoreConfigurationType * core )
{
    return ( core->stackMemoryLowAddress );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getStackMemoryHighAddress(CosmOS_CoreConfigurationType * core)
  *
  * @brief Get stackMemoryHighAddress.
  *
  * @param[in]  core configuration pointer
  *
  * @return AddressType
********************************************************************************/
__STATIC_FORCEINLINE AddressType
core_getStackMemoryHighAddress( CosmOS_CoreConfigurationType * core )
{
    return ( core->stackMemoryHighAddress );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getCodeMemoryLowAddress(CosmOS_CoreConfigurationType * core)
  *
  * @brief Get codeMemoryLowAddress.
  *
  * @param[in]  core configuration pointer
  *
  * @return AddressType
********************************************************************************/
__STATIC_FORCEINLINE AddressType
core_getCodeMemoryLowAddress( CosmOS_CoreConfigurationType * core )
{
    return ( core->codeMemoryLowAddress );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getCodeMemoryHighAddress(CosmOS_CoreConfigurationType * core)
  *
  * @brief Get codeMemoryHighAddress.
  *
  * @param[in]  core configuration pointer
  *
  * @return AddressType
********************************************************************************/
__STATIC_FORCEINLINE AddressType
core_getCodeMemoryHighAddress( CosmOS_CoreConfigurationType * core )
{
    return ( core->codeMemoryHighAddress );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getUnprotectedMemoryLowAddress(CosmOS_CoreConfigurationType * core)
  *
  * @brief Get unprotectedMemoryLowAddress.
  *
  * @param[in]  core configuration pointer
  *
  * @return AddressType
********************************************************************************/
__STATIC_FORCEINLINE AddressType
core_getUnprotectedMemoryLowAddress( CosmOS_CoreConfigurationType * core )
{
    return ( core->unprotectedMemoryLowAddress );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getUnprotectedMemoryHighAddress(CosmOS_CoreConfigurationType * core)
  *
  * @brief Get unprotectedMemoryHighAddress.
  *
  * @param[in]  core configuration pointer
  *
  * @return AddressType
********************************************************************************/
__STATIC_FORCEINLINE AddressType
core_getUnprotectedMemoryHighAddress( CosmOS_CoreConfigurationType * core )
{
    return ( core->unprotectedMemoryHighAddress );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getMsToTicks(CosmOS_CoreConfigurationType * core)
  *
  * @brief Get msToTicks.
  *
  * @param[in]  core configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
core_getMsToTicks( CosmOS_CoreConfigurationType * core )
{
    return ( core->msToTicks );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getCoreNumberOfAlarms(CosmOS_CoreConfigurationType * core)
  *
  * @brief Get core numberOfAlarms.
  *
  * @param[in]  core configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
core_getCoreNumberOfAlarms( CosmOS_CoreConfigurationType * core )
{
    return ( core->numberOfAlarms );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getCoreSchedulableInExecution(CosmOS_CoreConfigurationType * core)
  *
  * @brief Get core schedulableInExecution pointer.
  *
  * @param[in]  core configuration pointer
  *
  * @return CosmOS_SchedulableConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_SchedulableConfigurationType *
core_getCoreSchedulableInExecution( CosmOS_CoreConfigurationType * core )
{
    return (
        CosmOS_SchedulableConfigurationType *)( core->var
                                                    ->schedulableInExecution );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getCoreProgramInExecution(CosmOS_CoreConfigurationType * core)
  *
  * @brief Get core programInExecution pointer.
  *
  * @param[in]  core configuration pointer
  *
  * @return CosmOS_ProgramConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_ProgramConfigurationType *
core_getCoreProgramInExecution( CosmOS_CoreConfigurationType * core )
{
    return (CosmOS_ProgramConfigurationType *)( core->var->programInExecution );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getCoreProgramCfgs(CosmOS_CoreConfigurationType * core)
  *
  * @brief Get core programCfgs.
  *
  * @param[in]  core configuration pointer
  *
  * @return CosmOS_ProgramConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_ProgramConfigurationType *
core_getCoreProgramCfgs( CosmOS_CoreConfigurationType * core )
{
    return (CosmOS_ProgramConfigurationType *)( core->programCfgs );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getCoreProgramCfg(CosmOS_CoreConfigurationType * core,
  * BitWidthType programIterator)
  *
  * @brief Get core programVar element pointer.
  *
  * @param[in]  core configuration pointer
  * @param[in]  programIterator required program id
  *
  * @return CosmOS_ProgramConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_ProgramConfigurationType *
core_getCoreProgramCfg(
    CosmOS_CoreConfigurationType * core,
    BitWidthType programIterator )
{
    return (CosmOS_ProgramConfigurationType *)( &(
        core->programCfgs[programIterator] ) );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getCoreScheduler(CosmOS_CoreConfigurationType * core)
  *
  * @brief Get core scheduler pointer.
  *
  * @param[in]  core configuration pointer
  *
  * @return CosmOS_SchedulerConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_SchedulerConfigurationType *
core_getCoreScheduler( CosmOS_CoreConfigurationType * core )
{
    return (CosmOS_SchedulerConfigurationType *)( core->schedulerCfg );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getCoreBarrierVars(CosmOS_CoreConfigurationType * core)
  *
  * @brief Get core barrierVars pointer.
  *
  * @param[in]  core configuration pointer
  *
  * @return CosmOS_BarrierVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BarrierVariableType *
core_getCoreBarrierVars( CosmOS_CoreConfigurationType * core )
{
    return ( core->barrierVars );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getBarrierVar(CosmOS_CoreConfigurationType * core,
  * BitWidthType * barrierId)
  *
  * @brief Get barrierVars element pointer.
  *
  * @param[in]  core configuration pointer
  * @param[in]  barrierId required barrier id
  *
  * @return CosmOS_BarrierVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BarrierVariableType *
core_getBarrierVar( CosmOS_CoreConfigurationType * core, BitWidthType barrierId )
{
    return ( &( core->barrierVars[barrierId] ) );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getCoreOsState(CosmOS_CoreConfigurationType * core)
  *
  * @brief Get core osState.
  *
  * @param[in]  core configuration pointer
  *
  * @return CosmOS_OsStateType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_OsStateType
core_getCoreOsState( CosmOS_CoreConfigurationType * core )
{
    return ( core->var->osState );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getCoreSysJobs(CosmOS_CoreConfigurationType * core)
  *
  * @brief Get core sysJobs.
  *
  * @param[in]  core configuration pointer
  *
  * @return CosmOS_SysJobsConfigurationType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_SysJobsConfigurationType *
core_getCoreSysJobs( CosmOS_CoreConfigurationType * core )
{
    return (CosmOS_SysJobsConfigurationType *)( core->sysJobsCfg );
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
  * @fn core_setCoreProgramInExecution(CosmOS_CoreConfigurationType * core,
  * CosmOS_ProgramConfigurationType * programInExecutionParam)
  *
  * @brief Set core programInExecution pointer. This function cannot be called
  * from the unprivileged context directly.
  *
  * @param[out]  core configuration pointer
  * @param[in]  programInExecutionParam variable pointer
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
core_setCoreProgramInExecution(
    CosmOS_CoreConfigurationType * core,
    CosmOS_ProgramConfigurationType * programInExecutionParam )
{
    core->var->programInExecution = programInExecutionParam;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_setCoreSchedulableInExecution(CosmOS_CoreConfigurationType * core,
  * CosmOS_SchedulableConfigurationType * schedulableInExecutionParam)
  *
  * @brief Set core schedulableInExecution pointer. This function cannot be
  * called from the unprivileged context directly.
  *
  * @param[out]  core configuration pointer
  * @param[in]  schedulableInExecutionParam configuration pointer
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
core_setCoreSchedulableInExecution(
    CosmOS_CoreConfigurationType * core,
    CosmOS_SchedulableConfigurationType * schedulableInExecutionParam )
{
    core->var->schedulableInExecution = schedulableInExecutionParam;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_setCoreOsState(CosmOS_CoreConfigurationType * core)
  *
  * @brief Set core osState. This function cannot be called
  * from the unprivileged context directly.
  *
  * @param[out]  core configuration pointer
  * @param[in]  osStateParam state of the operating system
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
core_setCoreOsState(
    CosmOS_CoreConfigurationType * core,
    CosmOS_OsStateType osStateParam )
{
    core->var->osState = osStateParam;
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
