/********************************************************************************
**                                                                             **
**                       GENERATED FILE BY COSMOS CustomBox                    **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file sysDefsPrograms.h                                      	 		
*********************************************************************************
<!--                   sysDefsPrograms Unit Group Definition                  -->
********************************************************************************* 
** @defgroup sysDefsPrograms_unit sysDefsPrograms Unit 
** @ingroup sysDefs_module        
** @brief sysDefsPrograms Unit 
** @details lorem                               
*********************************************************************************	
<!--                           Version Information                            -->
*********************************************************************************
** @version 1.0.0
** @date 2021-04-05
** @author Generated by COSMOS CustomBox   
*********************************************************************************	
<!--                          Warnings and License                            -->
*********************************************************************************
** @warning Modifying code can lead to unexpected behaviour of the whole system
** @copyright MIT License       	
*********************************************************************************
<!--                sysDefsPrograms Unit Global Group Definition              -->
*********************************************************************************	
** @defgroup Global_sysDefsPrograms Global
** @ingroup sysDefsPrograms_unit 
** @brief sysDefsPrograms globals
** @details lorem 
********************************************************************************/ 
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __SYSDEFSPROGRAMS_H__
#define __SYSDEFSPROGRAMS_H__
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
#include "cosmosTypesStd.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_sysDefsPrograms_h Macros
  * @ingroup Global_sysDefsPrograms  
  * @{    
********************************************************************************/
#define PROGRAM_CORE_0_NUM      (BitWidthType)2    /* Number of configurated programs for core CM7 */
#define PROGRAM_CORE_1_NUM      (BitWidthType)2    /* Number of configurated programs for core CM4 */

#define PROGRAM_0_CORE_0_ID     (BitWidthType)0    /* Program default_CM7 identificator */

#define PROGRAM_0_CORE_0_SIZE    (BitWidthType)0    /* Program default_CM7 size */
#define PROGRAM_0_CORE_0_LOW_ADDRESS    (AddressType)0x0000    /* Program default_CM7 memoryLowAddress */
#define PROGRAM_0_CORE_0_HIGH_ADDRESS    (AddressType)0x0000    /* Program default_CM7 memoryHighAddress */ 

#define PROGRAM_1_CORE_0_ID     (BitWidthType)1    /* Program blinking_led_CM7 identificator */

#define PROGRAM_1_CORE_0_SIZE    (BitWidthType)1024    /* Program blinking_led_CM7 size */
#define PROGRAM_1_CORE_0_LOW_ADDRESS    (AddressType)0x20000800    /* Program blinking_led_CM7 memoryLowAddress */
#define PROGRAM_1_CORE_0_HIGH_ADDRESS    (AddressType)0x20000c00    /* Program blinking_led_CM7 memoryHighAddress */ 

#define PROGRAM_0_CORE_1_ID     (BitWidthType)0    /* Program default_CM4 identificator */

#define PROGRAM_0_CORE_1_SIZE    (BitWidthType)0    /* Program default_CM4 size */
#define PROGRAM_0_CORE_1_LOW_ADDRESS    (AddressType)0x0000    /* Program default_CM4 memoryLowAddress */
#define PROGRAM_0_CORE_1_HIGH_ADDRESS    (AddressType)0x0000    /* Program default_CM4 memoryHighAddress */ 

#define PROGRAM_1_CORE_1_ID     (BitWidthType)1    /* Program blinking_led_CM4 identificator */

#define PROGRAM_1_CORE_1_SIZE    (BitWidthType)1024    /* Program blinking_led_CM4 size */
#define PROGRAM_1_CORE_1_LOW_ADDRESS    (AddressType)0x10000400    /* Program blinking_led_CM4 memoryLowAddress */
#define PROGRAM_1_CORE_1_HIGH_ADDRESS    (AddressType)0x10000800    /* Program blinking_led_CM4 memoryHighAddress */ 
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Macros_sysDefsPrograms_h  
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
  * @defgroup Variables_sysDefsPrograms_h Variables  
  * @ingroup Global_sysDefsPrograms  
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Variables_sysDefsPrograms_h  
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
  * @defgroup Apis_sysDefsPrograms_h API's 
  * @ingroup Global_sysDefsPrograms
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_sysDefsPrograms_h Getters  
  * @ingroup Apis_sysDefsPrograms_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}       
  * Getters_sysDefsPrograms_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_sysDefsPrograms_h Setters  
  * @ingroup Apis_sysDefsPrograms_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}    
  * Setters_sysDefsPrograms_h   
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_sysDefsPrograms_h General  
  * @ingroup Apis_sysDefsPrograms_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_sysDefsPrograms_h  
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
  * @addtogroup Getters_sysDefsPrograms_h Getters  
  * @ingroup Apis_sysDefsPrograms_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}       
  * Getters_sysDefsPrograms_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_sysDefsPrograms_h Setters  
  * @ingroup Apis_sysDefsPrograms_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}    
  * Setters_sysDefsPrograms_h   
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_sysDefsPrograms_h General  
  * @ingroup Apis_sysDefsPrograms_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_sysDefsPrograms_h  
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