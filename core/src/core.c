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
  * @}
  * Macros_core
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
  * @}
  * Variables_core
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
  * @}
  * Getters_core_c
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
  * @}
  * Setters_core_c
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
  * @}
  * General_core_c
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
  * @fn core_getCoreVar()
  *
  * @brief Get current core variable.
  *
  * @param[in]  none
  *
  * @return CosmOS_CoreVariableType *
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
  * *************************************************************************//**
  * @fn core_setSchedulableIntoCurrentContext(CosmOS_CoreVariableType * coreVar,
  * CosmOS_TaskVariableType * taskVar)
  *
  * @brief Set program and schedulable into the current context.
  *
  * @param[in]  CosmOS_CoreVariableType * coreVar
  * @param[in]  CosmOS_SchedulableVariableType * schedulableVar
  *
  * @return none
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
core_setSchedulableIntoCurrentContext(
    CosmOS_CoreVariableType * coreVar,
    CosmOS_SchedulableVariableType * schedulableVar )
{
    BitWidthType programId;

    CosmOS_SchedulableStateType priorSchedulableVarState;

    CosmOS_ProgramVariableType * programVar;
    CosmOS_SchedulableVariableType * priorSchedulableVar;

    programId = schedulable_getProgramId( schedulableVar );
    programVar = core_getCoreProgramVar( coreVar, programId );
    priorSchedulableVar = core_getCoreSchedulableInExecution( coreVar );
    priorSchedulableVarState = schedulable_getState( priorSchedulableVar );

    core_setCoreProgramInExecution( coreVar, programVar );
    core_setCoreSchedulableInExecution( coreVar, schedulableVar );

    if ( priorSchedulableVarState IS_EQUAL_TO SCHEDULABLE_STATE_ENUM__RUNNING )
    {
        schedulable_setState(
            priorSchedulableVar, SCHEDULABLE_STATE_ENUM__READY );
    }
    schedulable_setState( schedulableVar, SCHEDULABLE_STATE_ENUM__RUNNING );
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
