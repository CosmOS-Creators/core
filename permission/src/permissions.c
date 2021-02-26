/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file permissions.c
*********************************************************************************
<!--                  permissions Unit Local Group Definition                 -->
*********************************************************************************	
** @defgroup Local_permissions Local
** @ingroup permissions_unit 
** @brief permissions locals
** @details lorem 
********************************************************************************/ 
/********************************************************************************  
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "permissions.h"
#include "core.h"
#include "CosmOSAssert.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_permissions Macros
  * @ingroup Local_permissions
  * @{    
********************************************************************************/
#define BITLOCK_MASK (BitWidthType)0x1

#define BITLOCK_ID_PLACEMENT_8BIT(id)   id,id,id,id,id,id,id,id,

#define BITLOCK_ID_PLACEMENT_16BIT(id)  id,id,id,id,id,id,id,id, \
                                        id,id,id,id,id,id,id,id,

#define BITLOCK_ID_PLACEMENT_32BIT(id)  id,id,id,id,id,id,id,id, \
                                        id,id,id,id,id,id,id,id, \
                                        id,id,id,id,id,id,id,id, \
                                        id,id,id,id,id,id,id,id,

#define BITLOCK_ID_PLACEMENT_64BIT(id)  id,id,id,id,id,id,id,id, \
                                        id,id,id,id,id,id,id,id, \
                                        id,id,id,id,id,id,id,id, \
                                        id,id,id,id,id,id,id,id, \
                                        id,id,id,id,id,id,id,id, \
                                        id,id,id,id,id,id,id,id, \
                                        id,id,id,id,id,id,id,id, \
                                        id,id,id,id,id,id,id,id,
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Macros_permissions  
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
  * @defgroup Variables_permissions Variables  
  * @ingroup Local_permissions
  * @{    
********************************************************************************/
/* @cond S */
__SEC_START(__OS_CONST_SECTION_START)
/* @endcond*/
const BitWidthType TaskIdToBitLock[TASK_NUM*sizeof(BitWidthType)*8] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
    BITLOCK_ID_PLACEMENT_32BIT(0)
    BITLOCK_ID_PLACEMENT_32BIT(1)
};

const BitWidthType ThreadIdToBitLock[THREAD_NUM*sizeof(BitWidthType)*8] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
    BITLOCK_ID_PLACEMENT_32BIT(0)
    BITLOCK_ID_PLACEMENT_32BIT(1)
};
/* @cond S */
__SEC_STOP(__OS_CONST_SECTION_STOP)
/* @endcond*/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Variables_permissions  
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
  * @defgroup Apis_permissions_c API's  
  * @ingroup Local_permissions
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_permissions_c Getters  
  * @ingroup Apis_permissions_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}       
  * Getters_permissions_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_permissions_c Setters  
  * @ingroup Apis_permissions_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}    
  * Setters_permissions_c   
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_permissions_c General  
  * @ingroup Apis_permissions_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn permissions_tryTaskAccess(CosmOS_PermissionsConfigurationType * permission, CosmOS_TaskVariableType * task)
  * 
  * @brief Try if task has permitted access.
  * 
  * @param[in]  CosmOS_PermissionsConfigurationType * permission
  * @param[in]  CosmOS_TaskVariableType * task
  * 
  * @return CosmOS_AccessStateType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_AccessStateType permissions_tryTaskAccess(CosmOS_PermissionsConfigurationType * permission, CosmOS_TaskVariableType * task)
{
    CosmOSAssert( IS_NOT( permission[task->cfg->coreId].bitLocksTasks[TaskIdToBitLock[task->cfg->id]] & \
              permission[task->cfg->coreId].bitLocksTasksInversed[TaskIdToBitLock[task->cfg->id]] ) );
    return ((( permission[task->cfg->coreId].bitLocksTasks[TaskIdToBitLock[task->cfg->id]] >> task->cfg->id ) & BITLOCK_MASK ) ? \
            ACCESS_STATE_ENUM__ALLOWED : ACCESS_STATE_ENUM__DENIED );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn permissions_tryThreadAccess(CosmOS_PermissionsConfigurationType * permission, CosmOS_ThreadVariableType * thread)
  * 
  * @brief Try if thread has permitted access.
  * 
  * @param[in]  CosmOS_PermissionsConfigurationType * permission
  * @param[in]  CosmOS_ThreadVariableType * thread
  * 
  * @return CosmOS_AccessStateType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_AccessStateType permissions_tryThreadAccess(CosmOS_PermissionsConfigurationType * permission, CosmOS_ThreadVariableType * thread)
{
    CosmOSAssert( IS_NOT( permission[thread->cfg->coreId].bitLocksThreads[ThreadIdToBitLock[thread->cfg->id]] & \
              permission[thread->cfg->coreId].bitLocksThreadsInversed[ThreadIdToBitLock[thread->cfg->id]] ) );
    return ((( permission[thread->cfg->coreId].bitLocksThreads[ThreadIdToBitLock[thread->cfg->id]] >> thread->cfg->id ) & BITLOCK_MASK ) ? \
            ACCESS_STATE_ENUM__ALLOWED : ACCESS_STATE_ENUM__DENIED );
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_permissions_c  
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
  * @fn permissions_tryAccess(CosmOS_PermissionsConfigurationType * permission,CosmOS_CoreVariableType * coreVar)
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
__OS_FUNC_SECTION CosmOS_AccessStateType permissions_tryAccess(CosmOS_PermissionsConfigurationType * permission,CosmOS_CoreVariableType * coreVar)
{
    CosmOS_AccessStateType accessState;
    CosmOS_RunningInstanceType runningInstance;

    CosmOS_TaskVariableType * taskVar;
    CosmOS_ThreadVariableType * threadVar;


    runningInstance = core_getCoreRunningInstance( coreVar );

    switch ( runningInstance )
    {
        case RUNNING_INSTANCE_ENUM__TASK :
        {
            taskVar = core_getCoreTaskInCurrentContext( coreVar );
            accessState = permissions_tryTaskAccess( permission, taskVar );
            break;
        }
        case RUNNING_INSTANCE_ENUM__THREAD :
        {
            threadVar = core_getCoreThreadInCurrentContext( coreVar );
            accessState = permissions_tryThreadAccess( permission, threadVar );
            break;
        }
        default :
        {
            /* Kernel Panic */
            accessState = ACCESS_STATE_ENUM__DENIED;
            break;
        }
    }

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
