/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file CILstdTypes.h                                      
*********************************************************************************	
<!--                     CILstdTypes Unit Group Definition                    -->
********************************************************************************* 
** @defgroup CILstdTypes_unit CILstdTypes Unit 
** @ingroup CILmodule        
** @brief CILstdTypes Unit 
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
<!--                 CILstdTypes Unit Global Group Definition                 -->
*********************************************************************************	
** @defgroup Global_CILstdTypes Global
** @ingroup CILstdTypes_unit 
** @brief CILstdTypes globals
** @details lorem 
********************************************************************************/ 
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __CILSTDTYPES_H__
#define __CILSTDTYPES_H__
/********************************************************************************
**                         START OF C++ SUPPORT SECTION                        **
********************************************************************************/
#ifdef __cplusplus
 extern "C" {
#endif
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CIL interfaces */
#include "CILbaseTypes.h"
#include "CILmacros.h"
#include "cosmosTypesMacros.h" 

/* CMSIS interfaces */
#include "cmsis_gcc.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_CILstdTypes_h Macros
  * @ingroup Global_CILstdTypes  
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Macros_CILstdTypes_h  
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
  * @defgroup Typedefs_CILstdTypesCfg_h Typedefs
  * @ingroup Global_CILstdTypes  
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  StackPointerType AddressType type
********************************************************************************/
typedef AddressType StackPointerType;

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  CosmOS_StackType struct type
********************************************************************************/
typedef struct
{
    volatile BitWidthType R4;
    volatile BitWidthType R5;
    volatile BitWidthType R6;
    volatile BitWidthType R7;
    volatile BitWidthType R8;
    volatile BitWidthType R10;
    volatile BitWidthType R11;
    volatile BitWidthType R14;
    volatile BitWidthType R0;
    volatile BitWidthType R1;
    volatile BitWidthType R2;
    volatile BitWidthType R3;
    volatile BitWidthType R12;
    volatile BitWidthType LR;
    volatile BitWidthType PC;
    volatile BitWidthType XPSR;

} CosmOS_StackType;
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Typedefs_CILstdTypes_h  
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