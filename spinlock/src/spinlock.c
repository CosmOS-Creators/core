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
#include "cosmosAssert.h"
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
  * @}
  * Macros_spinlock
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
  * @}
  * Variables_spinlock
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
  * @}
  * Getters_spinlock_c
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
  * @}
  * Setters_spinlock_c
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
  * @}
  * General_spinlock_c
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
  * @fn spinlock_getSpinlock(BitWidthType id)
  *
  * @brief Get spinlock DEMO CODE.
  *
  * @param[in]  BitWidthType id
  *
  * @return CosmOS_SpinlockStateType
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_SpinlockStateType
spinlock_getSpinlock( BitWidthType id )
{
    BitWidthType numberOfSpinlocks;

    CosmOS_BooleanType willCauseDeadlock;
    CosmOS_SpinlockStateType spinlockState;

    CosmOS_OsVariableType * osVar;
    CosmOS_CoreVariableType * coreVar;
    CosmOS_SpinlockVariableType * spinlockVar;

    osVar = os_getOsVar();
    coreVar = CILcore_getCoreVar();

    numberOfSpinlocks = os_getOsNumberOfSpinlocks( osVar );

    cosmosAssert( id < numberOfSpinlocks );

    spinlockVar = os_getOsSpinlockVar( osVar, id );

    willCauseDeadlock = spinlock_willCauseDeadlock( coreVar, spinlockVar );

    if ( willCauseDeadlock )
    {
        spinlockState = SPINLOCK_STATE_ENUM__DEADLOCK_WARNING;
    }
    else
    {
        spinlockState = CILspinlock_getSpinlock(
            &( spinlockVar->spinlock ),
            id,
            coreVar->schedulableInExecution->cfg->id );
        spinlockVar->schedulableOwner = coreVar->schedulableInExecution;
    }

    return spinlockState;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn spinlock_trySpinlock(BitWidthType id)
  *
  * @brief Try to get spinlock DEMO CODE.
  *
  * @param[in]  BitWidthType id
  *
  * @return CosmOS_SpinlockStateType
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_SpinlockStateType
spinlock_trySpinlock( BitWidthType id )
{
    BitWidthType numberOfSpinlocks;

    CosmOS_SpinlockStateType spinlockState;

    CosmOS_OsVariableType * osVar;
    CosmOS_CoreVariableType * coreVar;
    CosmOS_SpinlockVariableType * spinlockVar;

    osVar = os_getOsVar();
    coreVar = CILcore_getCoreVar();

    numberOfSpinlocks = os_getOsNumberOfSpinlocks( osVar );

    cosmosAssert( id < numberOfSpinlocks );
    spinlockVar = os_getOsSpinlockVar( osVar, id );

    spinlockState = CILspinlock_trySpinlock(
        &( spinlockVar->spinlock ),
        id,
        coreVar->schedulableInExecution->cfg->id );

    if ( spinlockState IS_EQUAL_TO SPINLOCK_STATE_ENUM__SUCCESSFULLY_LOCKED )
    {
        spinlockVar->schedulableOwner = coreVar->schedulableInExecution;
    }

    return spinlockState;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn spinlock_releaseSpinlock(BitWidthType id)
  *
  * @brief Release spinlock DEMO CODE.
  *
  * @param[in]  BitWidthType id
  *
  * @return CosmOS_SpinlockStateType
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_SpinlockStateType
spinlock_releaseSpinlock( BitWidthType id )
{
    BitWidthType numberOfSpinlocks;

    CosmOS_BooleanType ownsSchedulableSpinlock;

    CosmOS_SpinlockStateType spinlockState;

    CosmOS_OsVariableType * osVar;
    CosmOS_CoreVariableType * coreVar;
    CosmOS_SpinlockVariableType * spinlockVar;

    osVar = os_getOsVar();
    coreVar = CILcore_getCoreVar();

    numberOfSpinlocks = os_getOsNumberOfSpinlocks( osVar );

    cosmosAssert( id < numberOfSpinlocks );
    spinlockVar = os_getOsSpinlockVar( osVar, id );

    ownsSchedulableSpinlock =
        spinlock_ownsSchedulableSpinlock( coreVar, spinlockVar );

    if ( spinlockVar->spinlock IS_EQUAL_TO SPINLOCK_STATE_ENUM__OCCUPIED )
    {
        if ( ownsSchedulableSpinlock )
        {
            spinlockState = CILspinlock_releaseSpinlock(
                &( spinlockVar->spinlock ),
                id,
                coreVar->schedulableInExecution->cfg->id );
        }
        else
        {
            spinlockState = SPINLOCK_STATE_ENUM__ERROR_SCHEDULABLE_IS_NOT_OWNER;
        }
    }
    else
    {
        spinlockState = SPINLOCK_STATE_ENUM__ERROR_NOT_IN_OCCUPIED_STATE;
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
