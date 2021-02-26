/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file CosmOSTypesMacros.h                                      
*********************************************************************************	
<!--                   CosmOSTypesMacros Unit Group Definition                   -->
********************************************************************************* 
** @defgroup CosmOSTypesMacros_unit CosmOSTypesMacros Unit 
** @ingroup CosmOSTypes_module        
** @brief CosmOSTypesMacros Unit 
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
<!--               CosmOSTypesMacros Unit Global Group Definition                -->
*********************************************************************************	
** @defgroup Global_CosmOSTypesMacros Global
** @ingroup CosmOSTypesMacros_unit 
** @brief CosmOSTypesMacros globals
** @details lorem 
********************************************************************************/ 
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __TICTYPESMACROS_H__
#define __TICTYPESMACROS_H__
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
  * @defgroup Macros_CosmOSTypesMacros_h Macros
  * @ingroup Global_CosmOSTypesMacros  
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  EMPTY defines empty space
********************************************************************************/
#define EMPTY

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  ON defines activated instance with 1
********************************************************************************/
#define ON 1

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  OFF defines deactivated instance with 0
********************************************************************************/
#define OFF 0

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  IS_INITIALIZED_TO redefines equals sign
********************************************************************************/
#define IS_INITIALIZED_TO =

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  AND redefines and sign
********************************************************************************/
#define AND &&

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  IS_EQUAL_TO avoid assigning values in statements
********************************************************************************/
#define IS_EQUAL_TO ==

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  IS_NOT_EQUAL_TO
********************************************************************************/
#define IS_NOT_EQUAL_TO !=

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  IS_NOT more readable expresion than !
********************************************************************************/
#define IS_NOT(expr)  !(expr)

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  __STATIC_FORCEINLINE
********************************************************************************/
#if     defined ( __GNUC__ )
    #ifndef __STATIC_FORCEINLINE
        #define __STATIC_FORCEINLINE __attribute__((always_inline)) static inline
    #endif
#elif   defined ( __CC_ARM )
    #ifndef __STATIC_FORCEINLINE 
        #define __STATIC_FORCEINLINE __attribute__((always_inline)) static inline
    #endif 
#else
    #error "Your compiler is currently not supported by CosmOS!"
#endif

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  __NAKED
********************************************************************************/
#if     defined ( __GNUC__ )
    #ifndef __NAKED
        #define __NAKED __attribute__((naked))
    #endif
#elif   defined ( __CC_ARM )
    #ifndef __NAKED 
        #define __NAKED __attribute__((naked))
    #endif 
#else
    #error "Your compiler is currently not supported by CosmOS!"
#endif

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  __FORCEINLINE
********************************************************************************/
#if     defined ( __GNUC__ )
    #ifndef __FORCEINLINE
        #define __FORCEINLINE __attribute__((always_inline)) inline
    #endif
#elif   defined ( __CC_ARM )
    #ifndef __FORCEINLINE 
        #define __FORCEINLINE __attribute__((always_inline)) inline
    #endif 
#else
    #error "Your compiler is currently not supported by CosmOS!"
#endif

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  __SUPRESS_UNUSED_VAR used to supress compilator warnings
********************************************************************************/
#if     defined ( __GNUC__ )
    #define __SUPRESS_UNUSED_VAR(dummy) (void)(dummy)
#elif   defined ( __CC_ARM )
    #define __SUPRESS_UNUSED_VAR(dummy)
#else
    #error "Your compiler is currently not supported by CosmOS!"
#endif

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  NULL pointer macro
********************************************************************************/
#if     defined ( __GNUC__ )
    #ifndef NULL
        #define NULL ((void *)0)
    #endif
#elif   defined ( __CC_ARM )
    #ifndef NULL
        #define NULL ((void *)0)
    #endif
#else
    #error "Your compiler is currently not supported by CosmOS!"
#endif

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  __COSMOS_LIKELY pointer macro
********************************************************************************/
#if     defined ( __GNUC__ )
    #define __COSMOS_LIKELY(expr)      __builtin_expect(!!(expr),1)
#elif   defined ( __CC_ARM )
    #define __COSMOS_LIKELY(expr)      (expr)
#else
    #error "Your compiler is currently not supported by CosmOS!"
#endif

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  __COSMOS_UNLIKELY pointer macro
********************************************************************************/
#if     defined ( __GNUC__ )
    #define __COSMOS_UNLIKELY(expr)    __builtin_expect(!!(expr),0)
#elif   defined ( __CC_ARM )
    #define __COSMOS_UNLIKELY(expr)      (expr)
#else
    #error "Your compiler is currently not supported by CosmOS!"
#endif

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  __FUNC_START
********************************************************************************/
#if     defined ( __GNUC__ )
    #define __SEC_START( pragma ) \
    pragma

#elif   defined ( __CC_ARM )
    #define __SEC_START( pragma ) \
    pragma
#else
    #error "Your compiler is currently not supported by CosmOS!"
#endif

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  __FUNC_STOP
********************************************************************************/
#if     defined ( __GNUC__ )
    #define __SEC_STOP( pragma ) \
    pragma 
#elif   defined ( __CC_ARM )
    #define __SEC_STOP( pragma ) \
    pragma
#else
    #error "Your compiler is currently not supported by CosmOS!"
#endif
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Macros_CosmOSTypesMacros_h  
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Stop                           **
********************************************************************************/
/********************************************************************************
**                              Typedefs | Start                               **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Typedefs_CosmOSTypesMacrosCfg_h Typedefs
  * @ingroup Global_CosmOSTypesMacros  
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Typedefs_CosmOSTypesMacros_h  
********************************************************************************/
/********************************************************************************
**                              Typedefs | Stop                                **
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