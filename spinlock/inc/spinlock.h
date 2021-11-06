/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file spinlock.h
*********************************************************************************
<!--                     spinlock Module Group Definition                     -->
*********************************************************************************
** @defgroup spinlock_module spinlock
** @brief spinlock Module
** @details lorem
*********************************************************************************
<!--                      spinlock Unit Group Definition                      -->
*********************************************************************************
** @defgroup spinlock_unit spinlock Unit
** @ingroup spinlock_module
** @brief spinlock Unit
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
<!--                   spinlock Unit Global Group Definition                  -->
*********************************************************************************
** @defgroup Global_spinlock Global
** @ingroup spinlock_unit
** @brief spinlock globals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __SPINLOCK_H__
#define __SPINLOCK_H__
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
  * @defgroup Macros_spinlock_h Macros
  * @ingroup Global_spinlock
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_spinlock_h
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
  * @defgroup Variables_spinlock_h Variables
  * @ingroup Global_spinlock
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_spinlock_h
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
  * @defgroup Apis_spinlock_h API's
  * @ingroup Global_spinlock
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_spinlock_h Getters
  * @ingroup Apis_spinlock_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn spinlock_getSpinlock(BitWidthType id)
  *
  * @brief Get spinlock. This function is provided
  * as a CosmOS API system call mapped with the routes and cannot be called from
  * the unprivileged context directly. DEMO
  *
  * @param[in]  id is used during the system call dispatching
  *
  * @return CosmOS_SpinlockStateType
********************************************************************************/
__OS_FUNC_SECTION CosmOS_SpinlockStateType
spinlock_getSpinlock( BitWidthType id );
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_spinlock_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_spinlock_h Setters
  * @ingroup Apis_spinlock_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_spinlock_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_spinlock_h General
  * @ingroup Apis_spinlock_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn spinlock_trySpinlock(BitWidthType id)
  *
  * @brief Try to get spinlock. This function is provided
  * as a CosmOS API system call mapped with the routes and cannot be called from
  * the unprivileged context directly. DEMO
  *
  * @param[in]  id is used during the system call dispatching
  *
  * @return CosmOS_SpinlockStateType
********************************************************************************/
__OS_FUNC_SECTION CosmOS_SpinlockStateType
spinlock_trySpinlock( BitWidthType id );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn spinlock_releaseSpinlock(BitWidthType id)
  *
  * @brief Release spinlock. This function is provided
  * as a CosmOS API system call mapped with the routes and cannot be called from
  * the unprivileged context directly. DEMO
  *
  * @param[in]  id is used during the system call dispatching
  *
  * @return CosmOS_SpinlockStateType
********************************************************************************/
__OS_FUNC_SECTION CosmOS_SpinlockStateType
spinlock_releaseSpinlock( BitWidthType id );
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_spinlock_h
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
  * @addtogroup Getters_spinlock_h Getters
  * @ingroup Apis_spinlock_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_spinlock_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn spinlock_getSpinlockValue(CosmOS_SpinlockVariableType * spinlockVar)
  *
  * @brief Get spinlock value.
  *
  * @param[in]  spinlockVar pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
spinlock_getSpinlockValue( CosmOS_SpinlockVariableType * spinlockVar )
{
    return ( spinlockVar->spinlock );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn spinlock_getSpinlockSchedulableOwner(
  * CosmOS_SpinlockVariableType * spinlockVar)
  *
  * @brief Get spinlock schedulableOwner.
  *
  * @param[in]  spinlockVar pointer
  *
  * @return CosmOS_SchedulableConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_SchedulableConfigurationType *
spinlock_getSpinlockSchedulableOwner( CosmOS_SpinlockVariableType * spinlockVar )
{
    return (
        CosmOS_SchedulableConfigurationType *)( spinlockVar->schedulableOwner );
}
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_spinlock_h Setters
  * @ingroup Apis_spinlock_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn spinlock_setSpinlockValue(CosmOS_SpinlockVariableType * spinlockVar,
  * BitWidthType spinlockParam)
  *
  * @brief Set spinlock value. This function cannot
  * be called from the unprivileged context directly.
  *
  * @param[out]  spinlockVar pointer
  * @param[in]  spinlockParam value to be set to the spinlock variable
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
spinlock_setSpinlockValue(
    CosmOS_SpinlockVariableType * spinlockVar,
    BitWidthType spinlockParam )
{
    spinlockVar->spinlock = spinlockParam;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn spinlock_setSpinlockSchedulableOwner(
  * CosmOS_SpinlockVariableType * spinlock,
  * CosmOS_SchedulableConfigurationType * schedulableOwnerParam)
  *
  * @brief Set spinlock schedulableOwner. This function cannot
  * be called from the unprivileged context directly.
  *
  * @param[out]  spinlockVar pointer
  * @param[in]  schedulableOwnerParam pointer to the schedulable that owns
  * current spinlock
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
spinlock_setSpinlockSchedulableOwner(
    CosmOS_SpinlockVariableType * spinlockVar,
    CosmOS_SchedulableConfigurationType * schedulableOwnerParam )
{
    spinlockVar->schedulableOwner = schedulableOwnerParam;
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_spinlock_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_spinlock_h General
  * @ingroup Apis_spinlock_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn spinlock_willCauseDeadlock(CosmOS_CoreConfigurationType * core,
  * CosmOS_SpinlockVariableType * spinlockVar)
  *
  * @brief Check if the spinlock will ends up in deadlock. DEMO
  *
  * @param[in]  core configuration pointer
  * @param[in]  spinlockVar pointer
  *
  * @return CosmOS_BufferStateType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BooleanType
spinlock_willCauseDeadlock(
    CosmOS_CoreConfigurationType * core,
    CosmOS_SpinlockVariableType * spinlockVar )
{
    return ( (spinlockVar->spinlock IS_EQUAL_TO SPINLOCK_STATE_ENUM__OCCUPIED)
                 AND( core->var->schedulableInExecution IS_EQUAL_TO
                          spinlockVar->schedulableOwner ) )
               ? True
               : False;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn spinlock_ownsSchedulableSpinlock(CosmOS_CoreConfigurationType * core,
  * CosmOS_SpinlockVariableType * spinlockVar)
  *
  * @brief Check if the schedulable in execution owns the current spinlock.
  *
  * @param[in]  core configuration pointer
  * @param[in]  spinlockVar pointer
  *
  * @return CosmOS_BufferStateType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BooleanType
spinlock_ownsSchedulableSpinlock(
    CosmOS_CoreConfigurationType * core,
    CosmOS_SpinlockVariableType * spinlockVar )
{
    return ( core->var->schedulableInExecution IS_EQUAL_TO
                 spinlockVar->schedulableOwner )
               ? True
               : False;
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_spinlock_h
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
