/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file sysJobs.h
*********************************************************************************
<!--                      sysJobs Module Group Definition                     -->
*********************************************************************************
** @defgroup sysJobs_module sysJobs
** @brief sysJobs Module
** @details lorem
*********************************************************************************
<!--                       sysJobs Unit Group Definition                      -->
*********************************************************************************
** @defgroup sysJobs_unit sysJobs Unit
** @ingroup sysJobs_module
** @brief sysJobs Unit
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
<!--                    sysJobs Unit Global Group Definition                  -->
*********************************************************************************
** @defgroup Global_sysJobs Global
** @ingroup sysJobs_unit
** @brief sysJobs globals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __SYSJOBS_H__
#define __SYSJOBS_H__
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
#include "sysDefs.h"
#include "cosmosTypesStd.h"
#include "memoryMapping.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_sysJobs_h Macros
  * @ingroup Global_sysJobs
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Macros_sysJobs_h
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
  * @defgroup Variables_sysJobs_h Variables
  * @ingroup Global_sysJobs
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Variables_sysJobs_h
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
  * @defgroup Apis_sysJobs_h API's
  * @ingroup Global_sysJobs
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_sysJobs_h Getters
  * @ingroup Apis_sysJobs_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Getters_sysJobs_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_sysJobs_h Setters
  * @ingroup Apis_sysJobs_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Setters_sysJobs_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_sysJobs_h General
  * @ingroup Apis_sysJobs_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn sysJobs_dispatcher(BitWidthType entityId)
  *
  * @brief System jobs dispatcher DEMO FUNCTION.
  *
  * @param[in]  BitWidthType entityId
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void sysJobs_dispatcher(BitWidthType entityId);
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_sysJobs_h
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
  * @addtogroup Getters_sysJobs_h Getters
  * @ingroup Apis_sysJobs_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn sysJobs_getSysJobsGroups(CosmOS_SysJobsVariableType * sysJobs)
  *
  * @brief Get sysJobs groups.
  *
  * @param[in]  CosmOS_SysJobsVariableType * sysJobs
  *
  * @return CosmOS_SysJobsGroupConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_SysJobsGroupConfigurationType * sysJobs_getSysJobsGroups(CosmOS_SysJobsVariableType * sysJobs)
{
    return (CosmOS_SysJobsGroupConfigurationType *)(sysJobs->cfg->groups);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn sysJobs_getSysJobsNumOfGroups(CosmOS_SysJobsVariableType * sysJobs)
  *
  * @brief Get sysJobs numOfGroups.
  *
  * @param[in]  CosmOS_SysJobsVariableType * sysJobs
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType sysJobs_getSysJobsNumOfGroups(CosmOS_SysJobsVariableType * sysJobs)
{
    return (sysJobs->cfg->numOfGroups);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn sysJobs_getSysJobsHyperTick(CosmOS_SysJobsVariableType * sysJobs)
  *
  * @brief Get sysJobs hyperTick.
  *
  * @param[in]  CosmOS_SysJobsVariableType * sysJobs
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType sysJobs_getSysJobsHyperTick(CosmOS_SysJobsVariableType * sysJobs)
{
    return (sysJobs->cfg->hyperTick);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn sysJobs_getSysJobsCurrentTick(CosmOS_SysJobsVariableType * sysJobs)
  *
  * @brief Get sysJobs currentTick.
  *
  * @param[in]  CosmOS_SysJobsVariableType * sysJobs
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType sysJobs_getSysJobsCurrentTick(CosmOS_SysJobsVariableType * sysJobs)
{
    return (sysJobs->currentTick);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn sysJobs_getSysJobsGroupHandlers(CosmOS_SysJobsVariableType * sysJobs, BitWidthType groupId)
  *
  * @brief Get sysJobs group handlers.
  *
  * @param[in]  CosmOS_SysJobsVariableType * sysJobs
  * @param[in]  BitWidthType groupId
  *
  * @return CosmOS_GenericVoidType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_GenericVoidType * sysJobs_getSysJobsGroupHandlers(CosmOS_SysJobsVariableType * sysJobs, BitWidthType groupId)
{
    return (CosmOS_GenericVoidType *)(sysJobs->cfg->groups[groupId].handlers);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn sysJobs_getSysJobsGroupNumOfHandlers(CosmOS_SysJobsVariableType * sysJobs, BitWidthType groupId)
  *
  * @brief Get sysJobs group numOfHandlers.
  *
  * @param[in]  CosmOS_SysJobsVariableType * sysJobs
  * @param[in]  BitWidthType groupId
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType sysJobs_getSysJobsGroupNumOfHandlers(CosmOS_SysJobsVariableType * sysJobs, BitWidthType groupId)
{
    return (sysJobs->cfg->groups[groupId].numOfHandlers);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn sysJobs_getSysJobsGroupTickMultiplicator(CosmOS_SysJobsVariableType * sysJobs, BitWidthType groupId)
  *
  * @brief Get sysJobs group tickMultiplicator.
  *
  * @param[in]  CosmOS_SysJobsVariableType * sysJobs
  * @param[in]  BitWidthType groupId
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType sysJobs_getSysJobsGroupTickMultiplicator(CosmOS_SysJobsVariableType * sysJobs, BitWidthType groupId)
{
    return (sysJobs->cfg->groups[groupId].tickMultiplicator);
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Getters_sysJobs_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_sysJobs_h Setters
  * @ingroup Apis_sysJobs_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn sysJobs_setSysJobsCurrentTick(CosmOS_SysJobsVariableType * sysJobs, BitWidthType currentTickParam)
  *
  * @brief Set sysJobs currentTick.
  *
  * @param[in]  CosmOS_SysJobsVariableType * sysJobs
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void sysJobs_setSysJobsCurrentTick(CosmOS_SysJobsVariableType * sysJobs, BitWidthType currentTickParam)
{
    sysJobs->currentTick = currentTickParam;
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Setters_sysJobs_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_sysJobs_h General
  * @ingroup Apis_sysJobs_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_sysJobs_h
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
