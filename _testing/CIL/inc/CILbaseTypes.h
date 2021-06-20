/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file CILbaseTypes.h                                      
*********************************************************************************	
<!--                    CILbaseTypes Unit Group Definition                    -->
********************************************************************************* 
** @defgroup CILbaseTypes_unit CILbaseTypes Unit 
** @ingroup CILmodule        
** @brief CILbaseTypes Unit 
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
<!--                  CILbaseTypes Unit Global Group Definition               -->
*********************************************************************************	
** @defgroup Global_CILbaseTypes Global
** @ingroup CILbaseTypes_unit 
** @brief CILbaseTypes globals
** @details lorem 
********************************************************************************/ 
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __CILBASETYPES_H__
#define __CILBASETYPES_H__
/********************************************************************************
**                         START OF C++ SUPPORT SECTION                        **
********************************************************************************/
#ifdef __cplusplus
 extern "C" {
#endif
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* STANDARD interfaces */
#include <stdint.h>
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_CILbaseTypes_h Macros
  * @ingroup Global_CILbaseTypes  
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Macros_CILbaseTypes_h  
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
  * @defgroup Typedefs_CILbaseTypesCfg_h Typedefs
  * @ingroup Global_CILbaseTypes  
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  BitWidthType based on processor register bit width type, please define
  * your processor registers bit width type with ARCH_NBIT
********************************************************************************/
#ifdef ARCH_8BIT
    typedef unsigned char         BitWidthType;
    #define FORCE_ENUM            0xFF
    #define SECURE_NUMBER       0xAA
#elif ARCH_16BIT
    typedef unsigned short        BitWidthType;
    #define FORCE_ENUM            0xFFFF
    #define SECURE_NUMBER       0xAAAA
#elif ARCH_32BIT
    typedef unsigned int          BitWidthType;
    #define FORCE_ENUM            0xFFFFFFFF
    #define SECURE_NUMBER       0xAAAAAAAA
#elif ARCH_64BIT
    typedef unsigned long long    BitWidthType;
    #define FORCE_ENUM            0xFFFFFFFFFFFFFFFF
    #define SECURE_NUMBER       0xAAAAAAAAAAAAAAAA
#else
    #error "Please specify the BitWidth for your microprocessor! (ARCH_NBIT) => N = 8,16,32,64"
#endif

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  AddressType based on addressable memory with ADDR_NBIT
********************************************************************************/
#ifdef ADDR_8BIT
    typedef unsigned char         AddressType;
#elif ADDR_16BIT
    typedef unsigned short        AddressType;
#elif ADDR_32BIT
    typedef unsigned int          AddressType;
#elif ADDR_64BIT
    typedef unsigned long long    AddressType;
#else
    #error "Please specify the AddressType for your microprocessor! (ADDR_NBIT) => N = 8,16,32,64"
#endif
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Typedefs_CILbaseTypes_h  
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