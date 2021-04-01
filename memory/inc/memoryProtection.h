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
#include "sysDefs.h"
#include "CosmOSTypesStd.h"
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
  * @defgroup Macros_memoryProtection_h Macros
  * @ingroup Global_memoryProtection  
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Macros_memoryProtection_h  
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
  * @}  
  * Variables_memoryProtection_h  
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
  * @}       
  * Getters_memoryProtection_h
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
  * *************************************************************************//**
  * @fn memoryProtection_init(CosmOS_StackVariableType * stack)
  * 
  * @brief Set stack overflow protection.
  * 
  * @param[in]  none
  * 
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void memoryProtection_init();

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn memoryProtection_setStackOverflowProtection(CosmOS_StackVariableType * stack)
  * 
  * @brief Set stack overflow protection.
  * 
  * @param[in]  CosmOS_StackVariableType * stack
  * 
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void memoryProtection_setStackOverflowProtection(CosmOS_StackVariableType * stack);

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn memoryProtection_setProgramMemoryProtection(CosmOS_ProgramVariableType * program)
  * 
  * @brief Set program memory protection.
  * 
  * @param[in]  CosmOS_ProgramVariableType * program
  * 
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void memoryProtection_setProgramMemoryProtection(CosmOS_ProgramVariableType * program);

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn memoryProtection_setMemoryProtection(CosmOS_TaskVariableType * task)
  * 
  * @brief Set memory protection for current execution context.
  * 
  * @param[in]  CosmOS_CoreVariableType * core
  * @param[in]  CosmOS_TaskVariableType * task
  * 
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void memoryProtection_setMemoryProtection(CosmOS_CoreVariableType * core,CosmOS_TaskVariableType * task);
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}    
  * Setters_memoryProtection_h   
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
  * @}
  * General_memoryProtection_h  
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
  * @}       
  * Getters_memoryProtection_h
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
  * @}    
  * Setters_memoryProtection_h   
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
  * @}
  * General_memoryProtection_h  
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