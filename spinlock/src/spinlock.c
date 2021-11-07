/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file spinlock.c
*********************************************************************************
<!--                   spinlock Unit Local Group Definition                   -->
*********************************************************************************
** @defgroup Local_spinlock Local
** @ingroup spinlock_unit
** @brief spinlock locals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "spinlock.h"
#include "core.h"
#include "cosmosApiInternal.h"
#include "os.h"

/* CIL interfaces */
#include "CILcore.h"
#include "CILspinlock.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_spinlock Macros
  * @ingroup Local_spinlock
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_spinlock
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
  * @defgroup Variables_spinlock Variables
  * @ingroup Local_spinlock
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_spinlock
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
  * @defgroup Apis_spinlock_c API's
  * @ingroup Local_spinlock
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_spinlock_c Getters
  * @ingroup Apis_spinlock_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_spinlock_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_spinlock_c Setters
  * @ingroup Apis_spinlock_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_spinlock_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_spinlock_c General
  * @ingroup Apis_spinlock_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_spinlock_c
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
  * @fn spinlock_getSpinlockInternal(
  * BitWidthType id,
  * CosmOS_SpinlockVariableType * spinlockVar,
  * BitWidthType spinlockId )
  *
  * @details The implementation contains obtaining of the operating system and
  * core variable by calling functions os_getOsCfg and core_getCoreVar.
  * Then the operating system variable in function os_getOsNumberOfSpinlocks
  * to get number of spinlocks. The input element spinlockId argument is then checked
  * againts the number of spinlock in if condition.
  * Spinlock variable is then obtained based on the id argument by the function
  * os_getOsSpinlockVar. The function spinlock_willCauseDeadlock is called to
  * check if the spinlock would cause eventually deadlock, if yes the spinlock
  * state SPINLOCK_STATE_ENUM__DEADLOCK_WARNING is returned. Otherwise the
  * function CILspinlock_getSpinlock is called to get spinlock and result is
  * then returned as spinlock state. The schedulable owner member in spinlock
  * variable is set to the schedulable in execution.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_SpinlockStateType
spinlock_getSpinlockInternal(
    BitWidthType id,
    CosmOS_SpinlockVariableType * spinlockVar,
    BitWidthType spinlockId )
{
    CosmOS_SpinlockStateType spinlockState;

    CosmOS_CoreConfigurationType * coreCfg;

    coreCfg = CILcore_getCoreCfg();

    spinlockState = CILspinlock_getSpinlock(
        &( spinlockVar->spinlock ),
        spinlockId,
        ( (CosmOS_SchedulableConfigurationType *)
              coreCfg->var->schedulableInExecution )
            ->id );
    spinlockVar->schedulableOwner = coreCfg->var->schedulableInExecution;

    __SUPRESS_UNUSED_VAR( id );
    return spinlockState;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn spinlock_trySpinlockInternal(
  * BitWidthType id,
  * CosmOS_SpinlockVariableType * spinlockVar,
  * BitWidthType spinlockId )
  *
  * @details The implementation contains obtaining of the operating system and
  * core variable by calling functions os_getOsCfg and core_getCoreVar.
  * Then the operating system variable in function os_getOsNumberOfSpinlocks
  * to get number of spinlocks. The input element id argument is then checked
  * againts the number of spinlock in assertion function cosmosAssert. Spinlock
  * variable is then obtained based on the id argument by the function
  * os_getOsSpinlockVar. Then the function CILspinlock_trySpinlock is called to
  * try to get spinlock and result is then returned as spinlock state. The if
  * condition is implemented to check if the result from CILspinlock_trySpinlock
  * is equal to the SPINLOCK_STATE_ENUM__SUCCESSFULLY_LOCKED and if yes  the
  * schedulable owner member in spinlock variable is set to the schedulable in
  * execution.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_SpinlockStateType
spinlock_trySpinlockInternal(
    BitWidthType id,
    CosmOS_SpinlockVariableType * spinlockVar,
    BitWidthType spinlockId )
{
    CosmOS_SpinlockStateType spinlockState;

    CosmOS_CoreConfigurationType * coreCfg;

    coreCfg = CILcore_getCoreCfg();

    spinlockState = CILspinlock_trySpinlock(
        &( spinlockVar->spinlock ),
        id,
        ( (CosmOS_SchedulableConfigurationType *)
              coreCfg->var->schedulableInExecution )
            ->id );

    if ( spinlockState IS_EQUAL_TO SPINLOCK_STATE_ENUM__SUCCESSFULLY_LOCKED )
    {
        spinlockVar->schedulableOwner = coreCfg->var->schedulableInExecution;
    }

    __SUPRESS_UNUSED_VAR( id );
    return spinlockState;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn spinlock_releaseSpinlockInternal(
  * BitWidthType id,
  * CosmOS_SpinlockVariableType * spinlockVar,
  * BitWidthType spinlockId )
  *
  * @details The implementation contains obtaining of the operating system and
  * core variable by calling functions os_getOsCfg and core_getCoreVar.
  * Then the operating system variable in function os_getOsNumberOfSpinlocks
  * to get number of spinlocks. The input element id argument is then checked
  * againts the number of spinlock in assertion function cosmosAssert. Spinlock
  * variable is then obtained based on the id argument by the function
  * os_getOsSpinlockVar. The the boolean is obtained by calling function
  * spinlock_ownsSchedulableSpinlock to know if the requesting schedulable owns
  * the spinlock which means if the schedulable locked the spinlock before.
  * The spinlock member of the spinlock variable structure is compared in the
  * implemented if condition that checks if the spinlock is equal to the state
  * SPINLOCK_STATE_ENUM__OCCUPIED otherwise the spinlock state is returned with
  * the value SPINLOCK_STATE_ENUM__ERROR_NOT_IN_OCCUPIED_STATE. Another nested
  * if condition is implemented to check the obtained boolean variable that
  * stores value if the requesting schedulable owns the spinlock. If yes the
  * CILspinlock_releaseSpinlock function is called and the result is returned
  * as spinlock state.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_SpinlockStateType
spinlock_releaseSpinlockInternal(
    BitWidthType id,
    CosmOS_SpinlockVariableType * spinlockVar,
    BitWidthType spinlockId )
{
    CosmOS_SpinlockStateType spinlockState;

    CosmOS_CoreConfigurationType * coreCfg;

    coreCfg = CILcore_getCoreCfg();

    spinlockState = CILspinlock_releaseSpinlock(
        &( spinlockVar->spinlock ),
        spinlockId,
        ( (CosmOS_SchedulableConfigurationType *)
              coreCfg->var->schedulableInExecution )
            ->id );

    __SUPRESS_UNUSED_VAR( id );
    return spinlockState;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn spinlock_getSpinlock(BitWidthType spinlockId)
  *
  * @details The implementation contains obtaining of the operating system and
  * core variable by calling functions os_getOsCfg and core_getCoreVar.
  * Then the operating system variable in function os_getOsNumberOfSpinlocks
  * to get number of spinlocks. The input element spinlockId argument is then checked
  * againts the number of spinlock in assertion function cosmosAssert. Spinlock
  * variable is then obtained based on the id argument by the function
  * os_getOsSpinlockVar. The function spinlock_willCauseDeadlock is called to
  * check if the spinlock would cause eventually deadlock, if yes the spinlock
  * state SPINLOCK_STATE_ENUM__DEADLOCK_WARNING is returned. Otherwise the
  * function CILspinlock_getSpinlock is called to get spinlock and result is
  * then returned as spinlock state. The schedulable owner member in spinlock
  * variable is set to the schedulable in execution.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_SpinlockStateType
spinlock_getSpinlock( BitWidthType spinlockId )
{
    BitWidthType numberOfSpinlocks;

    CosmOS_BooleanType willCauseDeadlock;
    CosmOS_SpinlockStateType spinlockState;

    CosmOS_OsConfigurationType * osCfg;
    CosmOS_CoreConfigurationType * coreCfg;
    CosmOS_SpinlockVariableType * spinlockVar;

    osCfg = os_getOsCfg();
    coreCfg = CILcore_getCoreCfg();

    numberOfSpinlocks = os_getOsNumberOfSpinlocks( osCfg );

    if ( spinlockId < numberOfSpinlocks )
    {
        spinlockVar = os_getOsSpinlockVar( osCfg, spinlockId );

        willCauseDeadlock = spinlock_willCauseDeadlock( coreCfg, spinlockVar );

        if ( IS_NOT( willCauseDeadlock ) )
        {
            spinlockState = cosmosApiInternal_spinlock_getSpinlockInternal(
                spinlockVar, spinlockId );
        }
        else
        {
            spinlockState = SPINLOCK_STATE_ENUM__DEADLOCK_WARNING;
        }
    }
    else
    {
        spinlockState = SPINLOCK_STATE_ENUM__ERROR_INVALID_ID;
    }

    return spinlockState;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn spinlock_trySpinlock(BitWidthType spinlockId)
  *
  * @details The implementation contains obtaining of the operating system and
  * core variable by calling functions os_getOsCfg and core_getCoreVar.
  * Then the operating system variable in function os_getOsNumberOfSpinlocks
  * to get number of spinlocks. The input element id argument is then checked
  * againts the number of spinlock in assertion function cosmosAssert. Spinlock
  * variable is then obtained based on the id argument by the function
  * os_getOsSpinlockVar. Then the function CILspinlock_trySpinlock is called to
  * try to get spinlock and result is then returned as spinlock state. The if
  * condition is implemented to check if the result from CILspinlock_trySpinlock
  * is equal to the SPINLOCK_STATE_ENUM__SUCCESSFULLY_LOCKED and if yes  the
  * schedulable owner member in spinlock variable is set to the schedulable in
  * execution.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_SpinlockStateType
spinlock_trySpinlock( BitWidthType spinlockId )
{
    BitWidthType numberOfSpinlocks;

    CosmOS_SpinlockStateType spinlockState;

    CosmOS_OsConfigurationType * osCfg;
    CosmOS_SpinlockVariableType * spinlockVar;

    osCfg = os_getOsCfg();

    numberOfSpinlocks = os_getOsNumberOfSpinlocks( osCfg );

    if ( spinlockId < numberOfSpinlocks )
    {
        spinlockVar = os_getOsSpinlockVar( osCfg, spinlockId );

        spinlockState = cosmosApiInternal_spinlock_trySpinlockInternal(
            spinlockVar, spinlockId );
    }
    else
    {
        spinlockState = SPINLOCK_STATE_ENUM__ERROR_INVALID_ID;
    }

    return spinlockState;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn spinlock_releaseSpinlock(BitWidthType id)
  *
  * @details The implementation contains obtaining of the operating system and
  * core variable by calling functions os_getOsCfg and core_getCoreVar.
  * Then the operating system variable in function os_getOsNumberOfSpinlocks
  * to get number of spinlocks. The input element id argument is then checked
  * againts the number of spinlock in assertion function cosmosAssert. Spinlock
  * variable is then obtained based on the id argument by the function
  * os_getOsSpinlockVar. The the boolean is obtained by calling function
  * spinlock_ownsSchedulableSpinlock to know if the requesting schedulable owns
  * the spinlock which means if the schedulable locked the spinlock before.
  * The spinlock member of the spinlock variable structure is compared in the
  * implemented if condition that checks if the spinlock is equal to the state
  * SPINLOCK_STATE_ENUM__OCCUPIED otherwise the spinlock state is returned with
  * the value SPINLOCK_STATE_ENUM__ERROR_NOT_IN_OCCUPIED_STATE. Another nested
  * if condition is implemented to check the obtained boolean variable that
  * stores value if the requesting schedulable owns the spinlock. If yes the
  * CILspinlock_releaseSpinlock function is called and the result is returned
  * as spinlock state. Otherwise the spinlock state is returned with the value
  * SPINLOCK_STATE_ENUM__ERROR_SCHEDULABLE_IS_NOT_OWNER.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_SpinlockStateType
spinlock_releaseSpinlock( BitWidthType spinlockId )
{
    BitWidthType numberOfSpinlocks;

    CosmOS_BooleanType ownsSchedulableSpinlock;

    CosmOS_SpinlockStateType spinlockState;

    CosmOS_OsConfigurationType * osCfg;
    CosmOS_CoreConfigurationType * coreCfg;
    CosmOS_SpinlockVariableType * spinlockVar;

    osCfg = os_getOsCfg();
    coreCfg = CILcore_getCoreCfg();

    numberOfSpinlocks = os_getOsNumberOfSpinlocks( osCfg );

    if ( spinlockId < numberOfSpinlocks )
    {
        spinlockVar = os_getOsSpinlockVar( osCfg, spinlockId );

        ownsSchedulableSpinlock =
            spinlock_ownsSchedulableSpinlock( coreCfg, spinlockVar );

        if ( spinlockVar->spinlock IS_EQUAL_TO SPINLOCK_STATE_ENUM__OCCUPIED )
        {
            if ( ownsSchedulableSpinlock )
            {
                spinlockState =
                    cosmosApiInternal_spinlock_releaseSpinlockInternal(
                        spinlockVar, spinlockId );
            }
            else
            {
                spinlockState =
                    SPINLOCK_STATE_ENUM__ERROR_SCHEDULABLE_IS_NOT_OWNER;
            }
        }
        else
        {
            spinlockState = SPINLOCK_STATE_ENUM__ERROR_NOT_IN_OCCUPIED_STATE;
        }
    }
    else
    {
        spinlockState = SPINLOCK_STATE_ENUM__ERROR_INVALID_ID;
    }

    return spinlockState;
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
