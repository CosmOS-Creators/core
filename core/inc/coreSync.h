/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file coreSync.h
*********************************************************************************
<!--                      coreSync Unit Group Definition                      -->
*********************************************************************************
** @defgroup coreSync_unit coreSync Unit
** @ingroup core_module
** @brief coreSync Unit
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
<!--                  coreSync Unit Global Group Definition                   -->
*********************************************************************************
** @defgroup Global_coreSync Global
** @ingroup coreSync_unit
** @brief coreSync globals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __CORESYNC_H__
#define __CORESYNC_H__
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
  * @defgroup Macros_coreSync_h Macros
  * @ingroup Global_coreSync
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Macros_coreSync_h
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
  * @defgroup Variables_coreSync_h Variables
  * @ingroup Global_coreSync
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Variables_coreSync_h
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
  * @defgroup Apis_coreSync_h API's
  * @ingroup Global_coreSync
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_coreSync_h Getters
  * @ingroup Apis_coreSync_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn coreSync_getBarrier(CosmOS_CoreVariableType * coreVar,
  * BitWidthType barrierId)
  *
  * @brief Set barrier with specific id for core X.
  *
  * @param[in]  CosmOS_CoreVariableType * coreVar
  * @param[in]  BitWidthType barrierId
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void
coreSync_getBarrier( CosmOS_CoreVariableType * coreVar, BitWidthType barrierId );
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Getters_coreSync_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_coreSync_h Setters
  * @ingroup Apis_coreSync_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Setters_coreSync_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_coreSync_h General
  * @ingroup Apis_coreSync_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn coreSync_reactivateBarrier(CosmOS_CoreVariableType * coreVar,
  * BitWidthType barrierId)
  *
  * @brief Reactivate barrier with specific barrierId for coreVar.
  *
  * @param[in]  CosmOS_CoreVariableType * coreVar
  * @param[in]  BitWidthType barrierId
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void
coreSync_reactivateBarrier(
    CosmOS_CoreVariableType * coreVar,
    BitWidthType barrierId );
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_coreSync_h
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
  * @addtogroup Getters_coreSync_h Getters
  * @ingroup Apis_coreSync_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn coreSync_getBarrierState(CosmOS_CoreVariableType * core)
  *
  * @brief Get barrierState.
  *
  * @param[in]  CosmOS_BarrierVariableType * barrier
  *
  * @return CosmOS_BarrierStateType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BarrierStateType
coreSync_getBarrierState( CosmOS_BarrierVariableType * barrier )
{
    return ( barrier->barrierState );
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Getters_coreSync_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_coreSync_h Setters
  * @ingroup Apis_coreSync_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn coreSync_setBarrierState(CosmOS_BarrierVariableType * barrier,
  * CosmOS_BarrierStateType barrierStateParam)
  *
  * @brief Set barrierState.
  *
  * @param[in]  CosmOS_BarrierVariableType * barrier
  * @param[in]  CosmOS_BarrierStateType barrierStateParam
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
coreSync_setBarrierState(
    CosmOS_BarrierVariableType * barrier,
    CosmOS_BarrierStateType barrierStateParam )
{
    barrier->barrierState = barrierStateParam;
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Setters_coreSync_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_coreSync_h General
  * @ingroup Apis_coreSync_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_coreSync_h
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
