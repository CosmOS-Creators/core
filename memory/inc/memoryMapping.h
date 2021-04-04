/********************************************************************************
**                                                                             **
**                       GENERATED FILE BY COSMOS CustomBox                    **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file memoryMapping.h
*********************************************************************************	
<!--                   memoryMapping Unit Group Definition                    -->
********************************************************************************* 
** @defgroup memoryMapping_unit memoryMapping Unit 
** @ingroup memory_module        
** @brief memoryMapping Unit 
** @details lorem                               
*********************************************************************************	
<!--                           Version Information                            -->
*********************************************************************************
** @version 1.0.0
** @date 2021-04-04
** @author Generated by CosmOS CustomBox 
*********************************************************************************	
<!--                          Warnings and License                            -->
*********************************************************************************
** @warning Modifying code can lead to unexpected behaviour of the whole system
** @copyright MIT License
*********************************************************************************
<!--                memoryMapping Unit Global Group Definition                -->
*********************************************************************************
** @defgroup Global_memoryMapping Global
** @ingroup memoryMapping_unit 
** @brief memoryMapping globals
** @details lorem  
********************************************************************************/
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __MEMORYMAPPING_H__
#define __MEMORYMAPPING_H__
/********************************************************************************
**                         START OF C++ SUPPORT SECTION                        **
********************************************************************************/
#ifdef __cplusplus
 extern "C" {
#endif
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_memoryMapping_h Macros
  * @ingroup Global_memoryMapping  
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  __OS_FUNC_SECTION
********************************************************************************/
#if     defined ( __GNUC__ )
    #define __OS_FUNC_SECTION       __attribute__((section(".os_funcs")))
    #define __OS_FUNC_SECTION_START 
    #define __OS_FUNC_SECTION_STOP
#elif   defined ( __CC_ARM )
    #define __OS_FUNC_SECTION
    #define __OS_FUNC_SECTION_START 
    #define __OS_FUNC_SECTION_STOP
#else
    #error "Your compiler is currently not supported by CosmOS!"
#endif

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  __OS_FUNC_SECTION
********************************************************************************/
#if     defined ( __GNUC__ )
    #define __OS_CONST_SECTION        __attribute__((section(".os_consts")))
    #define __OS_CONST_SECTION_START 
    #define __OS_CONST_SECTION_STOP
#elif   defined ( __CC_ARM )
    #define __OS_CONST_SECTION
    #define __OS_CONST_SECTION_START 
    #define __OS_CONST_SECTION_STOP
#else
    #error "Your compiler is currently not supported by CosmOS!"
#endif

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  __OS_VAR_SECTION
********************************************************************************/
#if     defined ( __GNUC__ )
    #define __OS_VAR_SECTION        __attribute__((section(".os_vars")))
    #define __OS_VAR_SECTION_START 
    #define __OS_VAR_SECTION_STOP
#elif   defined ( __CC_ARM )
    #define __OS_VAR_SECTION
    #define __OS_VAR_SECTION_START 
    #define __OS_VAR_SECTION_STOP
#else
    #error "Your compiler is currently not supported by CosmOS!"
#endif

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  __UNMAPPED_SECTION
********************************************************************************/
#if     defined ( __GNUC__ )
    #define __UNMAPPED_SECTION        __attribute__((section(".unmapped")))
    #define __UNMAPPED_SECTION_START 
    #define __UNMAPPED_SECTION_STOP
#elif   defined ( __CC_ARM )
    #define __UNMAPPED__SECTION
    #define __UNMAPPED__SECTION_START 
    #define __UNMAPPED__SECTION_STOP
#else
    #error "Your compiler is currently not supported by CosmOS!"
#endif

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  __DEFAULT_CM7_SECTION
********************************************************************************/
#if     defined ( __GNUC__ )
    #define __DEFAULT_CM7_INIT_SECTION        __attribute__((section(".default_CM7_init")))
    #define __DEFAULT_CM7_INIT_SECTION_START 
    #define __DEFAULT_CM7_INIT_SECTION_STOP
#elif   defined ( __CC_ARM )
    #define __DEFAULT_CM7_INIT_SECTION
    #define __DEFAULT_CM7_INIT_SECTION_START 
    #define __DEFAULT_CM7_INIT_SECTION_STOP
#else
    #error "Your compiler is currently not supported by CosmOS!"
#endif

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  __BLINKING_LED_CM7_SECTION
********************************************************************************/
#if     defined ( __GNUC__ )
    #define __BLINKING_LED_CM7_INIT_SECTION        __attribute__((section(".blinking_led_CM7_init")))
    #define __BLINKING_LED_CM7_INIT_SECTION_START 
    #define __BLINKING_LED_CM7_INIT_SECTION_STOP
#elif   defined ( __CC_ARM )
    #define __BLINKING_LED_CM7_INIT_SECTION
    #define __BLINKING_LED_CM7_INIT_SECTION_START 
    #define __BLINKING_LED_CM7_INIT_SECTION_STOP
#else
    #error "Your compiler is currently not supported by CosmOS!"
#endif

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  __DEFAULT_CM4_SECTION
********************************************************************************/
#if     defined ( __GNUC__ )
    #define __DEFAULT_CM4_INIT_SECTION        __attribute__((section(".default_CM4_init")))
    #define __DEFAULT_CM4_INIT_SECTION_START 
    #define __DEFAULT_CM4_INIT_SECTION_STOP
#elif   defined ( __CC_ARM )
    #define __DEFAULT_CM4_INIT_SECTION
    #define __DEFAULT_CM4_INIT_SECTION_START 
    #define __DEFAULT_CM4_INIT_SECTION_STOP
#else
    #error "Your compiler is currently not supported by CosmOS!"
#endif

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  __BLINKING_LED_CM4_SECTION
********************************************************************************/
#if     defined ( __GNUC__ )
    #define __BLINKING_LED_CM4_INIT_SECTION        __attribute__((section(".blinking_led_CM4_init")))
    #define __BLINKING_LED_CM4_INIT_SECTION_START 
    #define __BLINKING_LED_CM4_INIT_SECTION_STOP
#elif   defined ( __CC_ARM )
    #define __BLINKING_LED_CM4_INIT_SECTION
    #define __BLINKING_LED_CM4_INIT_SECTION_START 
    #define __BLINKING_LED_CM4_INIT_SECTION_STOP
#else
    #error "Your compiler is currently not supported by CosmOS!"
#endif

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  __DEFAULT_CM7_SECTION
********************************************************************************/
#if     defined ( __GNUC__ )
    #define __DEFAULT_CM7_NOINIT_SECTION        __attribute__((section(".default_CM7_noInit")))
    #define __DEFAULT_CM7_NOINIT_SECTION_START 
    #define __DEFAULT_CM7_NOINIT_SECTION_STOP
#elif   defined ( __CC_ARM )
    #define __DEFAULT_CM7_NOINIT_SECTION
    #define __DEFAULT_CM7_NOINIT_SECTION_START 
    #define __DEFAULT_CM7_NOINIT_SECTION_STOP
#else
    #error "Your compiler is currently not supported by CosmOS!"
#endif

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  __BLINKING_LED_CM7_SECTION
********************************************************************************/
#if     defined ( __GNUC__ )
    #define __BLINKING_LED_CM7_NOINIT_SECTION        __attribute__((section(".blinking_led_CM7_noInit")))
    #define __BLINKING_LED_CM7_NOINIT_SECTION_START 
    #define __BLINKING_LED_CM7_NOINIT_SECTION_STOP
#elif   defined ( __CC_ARM )
    #define __BLINKING_LED_CM7_NOINIT_SECTION
    #define __BLINKING_LED_CM7_NOINIT_SECTION_START 
    #define __BLINKING_LED_CM7_NOINIT_SECTION_STOP
#else
    #error "Your compiler is currently not supported by CosmOS!"
#endif

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  __DEFAULT_CM4_SECTION
********************************************************************************/
#if     defined ( __GNUC__ )
    #define __DEFAULT_CM4_NOINIT_SECTION        __attribute__((section(".default_CM4_noInit")))
    #define __DEFAULT_CM4_NOINIT_SECTION_START 
    #define __DEFAULT_CM4_NOINIT_SECTION_STOP
#elif   defined ( __CC_ARM )
    #define __DEFAULT_CM4_NOINIT_SECTION
    #define __DEFAULT_CM4_NOINIT_SECTION_START 
    #define __DEFAULT_CM4_NOINIT_SECTION_STOP
#else
    #error "Your compiler is currently not supported by CosmOS!"
#endif

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  __BLINKING_LED_CM4_SECTION
********************************************************************************/
#if     defined ( __GNUC__ )
    #define __BLINKING_LED_CM4_NOINIT_SECTION        __attribute__((section(".blinking_led_CM4_noInit")))
    #define __BLINKING_LED_CM4_NOINIT_SECTION_START 
    #define __BLINKING_LED_CM4_NOINIT_SECTION_STOP
#elif   defined ( __CC_ARM )
    #define __BLINKING_LED_CM4_NOINIT_SECTION
    #define __BLINKING_LED_CM4_NOINIT_SECTION_START 
    #define __BLINKING_LED_CM4_NOINIT_SECTION_STOP
#else
    #error "Your compiler is currently not supported by CosmOS!"
#endif
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Macros_memoryMapping_h  
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
  * @defgroup Variables_memoryMapping_h Variables  
  * @ingroup Global_memoryMapping  
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Variables_memoryMapping_h  
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
  * @defgroup Apis_memoryMapping_h API's 
  * @ingroup Global_memoryMapping
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_memoryMapping_h Getters  
  * @ingroup Apis_memoryMapping_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}       
  * Getters_memoryMapping_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_memoryMapping_h Setters  
  * @ingroup Apis_memoryMapping_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}    
  * Setters_memoryMapping_h   
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_memoryMapping_h General  
  * @ingroup Apis_memoryMapping_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_memoryMapping_h  
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
  * @addtogroup Getters_memoryMapping_h Getters  
  * @ingroup Apis_memoryMapping_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}       
  * Getters_memoryMapping_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_memoryMapping_h Setters  
  * @ingroup Apis_memoryMapping_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}    
  * Setters_memoryMapping_h   
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_memoryMapping_h General  
  * @ingroup Apis_memoryMapping_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_memoryMapping_h  
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