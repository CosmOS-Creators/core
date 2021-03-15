/********************************************************************************
**                                                                             **
**                       GENERATED FILE BY CosmOS CustomBox                    **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file sysDefsRoutes.h                                      	 		
*********************************************************************************	
<!--                    sysDefsRoutes Unit Group Definition                   -->
********************************************************************************* 
** @defgroup sysDefsRoutes_unit sysDefsRoutes Unit 
** @ingroup sysDefs_module        
** @brief sysDefsRoutes Unit 
** @details lorem                               
*********************************************************************************	
<!--                           Version Information                            -->
*********************************************************************************
** @version 1.0.0
** @date 1.8.2020
** @author Generated by CosmOS CustomBox   
*********************************************************************************	
<!--                          Warnings and License                            -->
*********************************************************************************
** @warning Modifying code can lead to unexpected behaviour of the whole system
** @copyright MIT License       	
*********************************************************************************
<!--                sysDefsRoutes Unit Global Group Definition                -->
*********************************************************************************	
** @defgroup Global_sysDefsRoutes Global
** @ingroup sysDefsRoutes_unit 
** @brief sysDefsRoutes globals
** @details lorem 
********************************************************************************/ 
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __SYSDEFSROUTES_H__
#define __SYSDEFSROUTES_H__
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
#include "CosmOSTypesStd.h"
#include "sysDefsBuffers.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_sysDefsRoutes_h Macros
  * @ingroup Global_sysDefsRoutes  
  * @{    
********************************************************************************/
#define ROUTES_NUM (BitWidthType)0x00000001          /* Number of route RW */

#define ROUTES_FUNC_NUM (BitWidthType)0x00000006          /* Number of route RW */


#define ROUTES_ID_TO_FUNC_NUM (BitWidthType)0x00000006     /* Number of route identificators */

#define READ_BUFFER (BitWidthType)0x00000000            /* Identificator pointing on function pointer in array (Routes) */
#define WRITE_BUFFER (BitWidthType)0x00000001           /* Identificator pointing on function pointer in array (Routes) */
#define GPIO_TOGGLE_PIN (BitWidthType)0x00000002        /* Identificator pointing on function pointer in array (Routes) */
#define OS_INIT (BitWidthType)0x00000003                /* Identificator pointing on function pointer in array (Routes) */
#define OS_START (BitWidthType)0x00000004               /* Identificator pointing on function pointer in array (Routes) */
#define OS_EXEC_FINISHED (BitWidthType)0x00000005       /* Identificator pointing on function pointer in array (Routes) */


#define READ_XCORE_1_TO_0_BUFFER_0 (BitWidthType)0x00000000   /* Identificator pointing on element in id array (RoutesIdToFuncConst) */
#define WRITE_XCORE_1_TO_0_BUFFER_0 (BitWidthType)0x00000001  /* Identificator pointing on element in id array (RoutesIdToFuncConst) */
#define TOGGLE_PIN (BitWidthType)0x00000002                   /* Identificator pointing on element in id array (RoutesIdToFuncConst) */
#define INIT_COSMOS  (BitWidthType)0x00000003                 /* Identificator pointing on element in id array (RoutesIdToFuncConst) */
#define START_COSMOS (BitWidthType)0x00000004                 /* Identificator pointing on element in id array (RoutesIdToFuncConst) */
#define EXEC_FINISHED (BitWidthType)0x00000005                /* Identificator pointing on element in id array (RoutesIdToFuncConst) */

#define ROUTES_ID_TO_ENTITY_NUM (BitWidthType)0x00000002     /* Number of route identificators */

#define BUFFER_XCORE_1_TO_0  BUFFER_0                      /* RoutesIdToEntityConst */
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Macros_sysDefsRoutes_h  
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
  * @defgroup Variables_sysDefsRoutes_h Variables  
  * @ingroup Global_sysDefsRoutes  
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Variables_sysDefsRoutes_h  
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
  * @defgroup Apis_sysDefsRoutes_h API's 
  * @ingroup Global_sysDefsRoutes
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_sysDefsRoutes_h Getters  
  * @ingroup Apis_sysDefsRoutes_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}       
  * Getters_sysDefsRoutes_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_sysDefsRoutes_h Setters  
  * @ingroup Apis_sysDefsRoutes_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}    
  * Setters_sysDefsRoutes_h   
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_sysDefsRoutes_h General  
  * @ingroup Apis_sysDefsRoutes_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_sysDefsRoutes_h  
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
  * @addtogroup Getters_sysDefsRoutes_h Getters  
  * @ingroup Apis_sysDefsRoutes_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}       
  * Getters_sysDefsRoutes_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_sysDefsRoutes_h Setters  
  * @ingroup Apis_sysDefsRoutes_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}    
  * Setters_sysDefsRoutes_h   
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_sysDefsRoutes_h General  
  * @ingroup Apis_sysDefsRoutes_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_sysDefsRoutes_h  
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