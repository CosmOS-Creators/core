/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file permission.c
*********************************************************************************
<!--                  permission Unit Local Group Definition                 -->
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
#include "permissionCfg.h"
#include "core.h"
#include "cosmosAssert.h"
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
  * @}  
  * Macros_permission  
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
  * @}  
  * Variables_permission  
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
  * @}       
  * Getters_permission_c
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
  * @}    
  * Setters_permission_c   
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
  * *************************************************************************//**
  * @fn permission_tryTaskAccess(CosmOS_PermissionsConfigurationType * permission, CosmOS_TaskVariableType * task)
  * 
  * @brief Try if task has permitted access.
  * 
  * @param[in]  CosmOS_PermissionsConfigurationType * permission
  * @param[in]  CosmOS_TaskVariableType * task
  * 
  * @return CosmOS_AccessStateType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_AccessStateType permission_tryTaskAccess(CosmOS_PermissionsConfigurationType * permission, CosmOS_TaskVariableType * task)
{
    cosmosAssert( IS_NOT( permission[task->cfg->coreId].bitLocksTasks[TaskIdToBitLock[task->cfg->id]] & \
              permission[task->cfg->coreId].bitLocksTasksInverted[TaskIdToBitLock[task->cfg->id]] ) );

    return ((( permission[task->cfg->coreId].bitLocksTasks[TaskIdToBitLock[task->cfg->id]] >> task->cfg->id ) & BITLOCK_MASK ) ? \
            ACCESS_STATE_ENUM__ALLOWED : ACCESS_STATE_ENUM__DENIED );
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_permission_c  
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
  * @fn permission_tryAccess(CosmOS_PermissionsConfigurationType * permission,CosmOS_CoreVariableType * coreVar)
  * 
  * @brief Try access of current running instance DEMO CODE.
  * 
  * @param[in]  CosmOS_PermissionsConfigurationType * permission
  * @param[in]  CosmOS_CoreVariableType * coreVar
  * 
  * @return CosmOS_AccessStateType
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION CosmOS_AccessStateType permission_tryAccess(CosmOS_PermissionsConfigurationType * permission,CosmOS_CoreVariableType * coreVar)
{
    CosmOS_AccessStateType accessState;

    CosmOS_TaskVariableType * taskVar;

    taskVar = core_getCoreTaskInCurrentContext( coreVar );
    accessState = permission_tryTaskAccess( permission, taskVar );

    return accessState;
}
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/
/********************************************************************************
**                        Function Definitions | Stop                          **
********************************************************************************/
/********************************************************************************
**                           END OF THE SOURCE FILE                            **
********************************************************************************/
