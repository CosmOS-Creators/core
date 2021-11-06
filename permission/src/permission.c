/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file permission.c
*********************************************************************************
<!--                  permission Unit Local Group Definition                  -->
*********************************************************************************
** @defgroup Local_permission Local
** @ingroup permission_unit
** @brief permission locals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "permission.h"
#include "core.h"
#include "cosmosAssert.h"
#include "permissionCfg.h"

/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_permission Macros
  * @ingroup Local_permission
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_permission
********************************************************************************/
#define BITLOCK_MASK (BitWidthType)0x1
/********************************************************************************
**                          Macro Definitions | Stop                           **
********************************************************************************/
/********************************************************************************
**                              Variables | Start                              **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Variables_permission Variables
  * @ingroup Local_permission
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_permission
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
  * @defgroup Apis_permission_c API's
  * @ingroup Local_permission
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_permission_c Getters
  * @ingroup Apis_permission_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_permission_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_permission_c Setters
  * @ingroup Apis_permission_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_permission_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_permission_c General
  * @ingroup Apis_permission_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn permission_trySchedulableAccess(
  * CosmOS_PermissionsConfigurationType * permission,
  * CosmOS_SchedulableConfigurationType * schedulableCfg)
  *
  * @brief Try if schedulable has access.
  *
  * @param[in]  permission pointer to the permission configuration type
  * @param[in]  schedulableCfg configuration pointer
  *
  * @return CosmOS_AccessStateType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_AccessStateType
permission_trySchedulableAccess(
    CosmOS_PermissionsConfigurationType * permission,
    CosmOS_SchedulableConfigurationType * schedulableCfg );
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_permission_c
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
  * @fn permission_trySchedulableAccess(
  * CosmOS_PermissionsConfigurationType * permission,
  * CosmOS_SchedulableConfigurationType * schedulableCfg)
  *
  * @details The implementation contains cosmosAssert call with the comparing of
  * bitlock and bitlock inverted value.
  * After this the bitlock element from bitlock array is extracted by the unique
  * schedulable id and the specific bit shifted by the unique schedulable id.
  * If the bit is 0 function returns ACCESS_STATE_ENUM__DENIED if 1
  * ACCESS_STATE_ENUM__ALLOWED.
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_AccessStateType
permission_trySchedulableAccess(
    CosmOS_PermissionsConfigurationType * permission,
    CosmOS_SchedulableConfigurationType * schedulableCfg )
{
    cosmosAssert( IS_NOT(
        permission->bitLocksTasks[SchedulableIdToBitLock[schedulableCfg->id]] &
        permission->bitLocksTasksInverted
            [SchedulableIdToBitLock[schedulableCfg->id]] ) );

    return (
        ( ( permission
                ->bitLocksTasks[SchedulableIdToBitLock[schedulableCfg->id]] >>
            schedulableCfg->id ) &
          BITLOCK_MASK )
            ? ACCESS_STATE_ENUM__ALLOWED
            : ACCESS_STATE_ENUM__DENIED );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn permission_tryAccess(CosmOS_PermissionsConfigurationType * permission,
  * CosmOS_CoreConfigurationType * core)
  *
  * @details The implementation contains obtaining the schedulable variable in
  * execution by calling core_getCoreSchedulableInExecution function and then
  * using the schedulable variable with the permission configuration structure
  * in the permission_trySchedulableAccess function call that returns the
  * accessState and is returned from the function.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_AccessStateType
permission_tryAccess(
    CosmOS_PermissionsConfigurationType * permission,
    CosmOS_CoreConfigurationType * core )
{
    CosmOS_AccessStateType accessState;

    CosmOS_SchedulableConfigurationType * schedulableCfg;

    schedulableCfg = core_getCoreSchedulableInExecution( core );
    accessState = permission_trySchedulableAccess( permission, schedulableCfg );

    return accessState;
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
