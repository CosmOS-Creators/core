/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file memoryProtection.h
*********************************************************************************
<!--                  memoryProtection Unit Group Definition                  -->
*********************************************************************************
** @defgroup memoryProtection_unit memoryProtection Unit
** @ingroup memory_module
** @brief memoryProtection Unit
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
<!--             memoryProtection Unit Global Group Definition                -->
*********************************************************************************
** @defgroup Global_memoryProtection Global
** @ingroup memoryProtection_unit
** @brief memoryProtection globals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __MEMORYPROTECTION_H__
#define __MEMORYPROTECTION_H__
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
  * @defgroup Macros_memoryProtection_h Macros
  * @ingroup Global_memoryProtection
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_memoryProtection_h
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
  * @defgroup Variables_memoryProtection_h Variables
  * @ingroup Global_memoryProtection
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_memoryProtection_h
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
  * @defgroup Apis_memoryProtection_h API's
  * @ingroup Global_memoryProtection
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_memoryProtection_h Getters
  * @ingroup Apis_memoryProtection_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_memoryProtection_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_memoryProtection_h Setters
  * @ingroup Apis_memoryProtection_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn memoryProtection_init(AddressType codeMemoryHighAddress,
  * AddressType codeMemoryLowAddress,
  * AddressType stackMemoryHighAddress,
  * AddressType stackMemoryLowAddress,
  * AddressType unprotectedMemoryLowAddress,
  * AddressType unprotectedMemoryHighAddress)
  *
  * @brief Memory protection initialization. DEMO
  *
  * @param[in]  codeMemoryHighAddress
  * @param[in]  codeMemoryLowAddress
  * @param[in]  stackMemoryHighAddress
  * @param[in]  unprotectedMemoryLowAddress
  * @param[in]  unprotectedMemoryHighAddress
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void
memoryProtection_init(
    AddressType codeMemoryHighAddress,
    AddressType codeMemoryLowAddress,
    AddressType stackMemoryHighAddress,
    AddressType stackMemoryLowAddress,
    AddressType unprotectedMemoryLowAddress,
    AddressType unprotectedMemoryHighAddress );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn memoryProtection_setMemoryProtection(CosmOS_CoreVariableType * core,
  * CosmOS_SchedulableConfigurationType  * schedulable)
  *
  * @brief Set memory protection for current execution context that means for
  * the schedulable stack, peripheral access and program memory. This function
  * cannot be called from the unprivileged context directly.
  *
  * @param[in]  core variable pointer
  * @param[in]  schedulable configuration pointer
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void
memoryProtection_setMemoryProtection(
    CosmOS_CoreVariableType * core,
    CosmOS_SchedulableConfigurationType * schedulable);

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn memoryProtection_isMemoryRegionProtected(
  * CosmOS_CoreVariableType * core,
  * void  * regionLowAddressPointer,
  * BitWidthType size)
  *
  * @brief Check if specific memory region is protected against changes
  * for the current execution context. This function cannot be called from
  * the unprivileged context directly. DEMO
  *
  * @param[in]  core variable pointer
  * @param[in]  regionLowAddressPointer pointer to the region
  * @param[in]  size of the region
  *
  * @return CosmOS_BooleanType
********************************************************************************/
__OS_FUNC_SECTION CosmOS_BooleanType
memoryProtection_isMemoryRegionProtected(
    CosmOS_CoreVariableType * core,
    AddressType * regionLowAddressPointer,
    BitWidthType size );
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_memoryProtection_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_memoryProtection_h General
  * @ingroup Apis_memoryProtection_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_memoryProtection_h
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
  * @addtogroup Getters_memoryProtection_h Getters
  * @ingroup Apis_memoryProtection_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_memoryProtection_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_memoryProtection_h Setters
  * @ingroup Apis_memoryProtection_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_memoryProtection_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_memoryProtection_h General
  * @ingroup Apis_memoryProtection_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_memoryProtection_h
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
