/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file core.c
*********************************************************************************
<!--                     core Unit Local Group Definition                     -->
*********************************************************************************
** @defgroup Local_core Local
** @ingroup core_unit
** @brief core locals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "core.h"
#include "schedulable.h"

/* CIL interfaces */
#include "CILcore.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_core Macros
  * @ingroup Local_core
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_core
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
  * @defgroup Variables_core Variables
  * @ingroup Local_core
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_core
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
  * @defgroup Apis_core_c API's
  * @ingroup Local_core
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_core_c Getters
  * @ingroup Apis_core_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_core_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_core_c Setters
  * @ingroup Apis_core_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_core_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_core_c General
  * @ingroup Apis_core_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_core_c
********************************************************************************/
/********************************************************************************
**                         Function Prototypes | Stop                          **
********************************************************************************/
/********************************************************************************
**                        Function Definitions | Start                         **
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_getCoreVar( void )
  *
  * @details The implementation contains obtaining of the core variable by
  * calling the CILcore_getCoreVar function and returning the result.
  *
  * @see TEST_CORE_GETCOREVAR_EXECUTIONFLOW
  * @see TEST_CORE_GETCOREVAR_RETURNVALUE
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_CoreVariableType *
core_getCoreVar( void )
{
    CosmOS_CoreVariableType * coreVar;

    coreVar = CILcore_getCoreVar();

    return coreVar;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn core_setSchedulableIntoCurrentContext(CosmOS_CoreVariableType * coreVar,
  * CosmOS_SchedulableConfigurationType * schedulableCfg)
  *
  * @details The implementation contains obtaining of the program id from the
  * schedulable variable by schedulable_getProgramId function. Then the program
  * variable is obtained from all configured programs under the current core
  * by function core_getCoreProgramVar. Then is the program from schedulable that
  * has to be set into the current context set as program in execution by
  * calling function core_setCoreProgramInExecution and also the schedulable by
  * calling function core_setCoreSchedulableInExecution.
  * For the check of the prior schedulable in execution state is the prior
  * schedulable obtained by calling function core_getCoreSchedulableInExecution
  * and then the state of it by calling schedulable_getState function. If the
  * prior schedulable is not NULL and if the state of the
  * priorSchedulableCfg is SCHEDULABLE_STATE_ENUM__RUNNING the prior schedulable
  * state is set to SCHEDULABLE_STATE_ENUM__READY. Then also state of the
  * schedulable that has to be set into the current context is set by function
  * schedulable_setState to the SCHEDULABLE_STATE_ENUM__RUNNING.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
core_setSchedulableIntoCurrentContext(
    CosmOS_CoreVariableType * coreVar,
    CosmOS_SchedulableConfigurationType * schedulableCfg )
{
    BitWidthType programId;

    CosmOS_SchedulableStateType priorschedulableState;

    CosmOS_ProgramVariableType * programVar;
    CosmOS_SchedulableConfigurationType * priorSchedulableCfg;

    programId = schedulable_getProgramId( schedulableCfg );
    programVar = core_getCoreProgramVar( coreVar, programId );

    core_setCoreProgramInExecution( coreVar, programVar );
    core_setCoreSchedulableInExecution( coreVar, schedulableCfg );
    schedulable_setState( schedulableCfg, SCHEDULABLE_STATE_ENUM__RUNNING );

    priorSchedulableCfg = core_getCoreSchedulableInExecution( coreVar );
    if ( priorSchedulableCfg )
    {
        priorschedulableState = schedulable_getState( priorSchedulableCfg );

        if ( priorschedulableState IS_EQUAL_TO SCHEDULABLE_STATE_ENUM__RUNNING )
        {
            schedulable_setState(
                priorSchedulableCfg, SCHEDULABLE_STATE_ENUM__READY );
        }
    }
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/
/********************************************************************************
**                        Function Definitions | Stop                          **
********************************************************************************/
/********************************************************************************
**                           END OF THE SOURCE FILE                            **
********************************************************************************/
