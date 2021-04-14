/********************************************************************************
**                                                                             **
**                       GENERATED FILE BY CosmOS CustomBox                    **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file osCfg.c
*********************************************************************************
<!--                    osCfg Unit Local Group Definition                     -->
*********************************************************************************	
** @defgroup Local_osCfg Local
** @ingroup osCfg_unit 
** @brief osCfg locals
** @details lorem 
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "osCfg.h"
#include "coreCfg.h"
#include "bufferCfg.h"
#include "bufferDoubleCfg.h"
#include "routeCfg.h"
#include "sysJobsCfg.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_osCfg_c Macros
  * @ingroup Local_osCfg
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Macros_osCfg_c  
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
  * @defgroup Variables_osCfg_c Variables  
  * @ingroup Local_osCfg
  * @{    
********************************************************************************/
/* @cond S */
__SEC_START(__OS_CONST_SECTION_START)
/* @endcond*/
const CosmOS_OsConfigurationType OsCfg __OS_CONST_SECTION
IS_INITIALIZED_TO
{                       /* osCfg                                        */
    CoresCfgConst,      /* const CosmOS_CoreConfigurationType * cores      */
    CORE_NUM,           /* const BitWidthType numberOfCores             */
    BuffersCfgConst,    /* const CosmOS_BufferConfigurationType * buffers  */
    BUFFER_NUM,         /* const BitWidthType numberOfBuffers           */
    &RoutesConstCfg,    /* const CosmOS_RoutesConfigurationType route     */
};
/* @cond S */
__SEC_STOP(__OS_CONST_SECTION_STOP)
/* @endcond*/

/* @cond S */
__SEC_START(__OS_VAR_SECTION_START)
/* @endcond*/
CosmOS_OsVariableType OsVar __OS_VAR_SECTION
IS_INITIALIZED_TO
{                       /* osVar                                                      */
    &OsCfg,             /* const CosmOS_OsConfigurationType * cfg                     */
    CoresVar,           /* CosmOS_CoreVariableType * coreVars                         */   
    BuffersVar,         /* CosmOS_BufferVariableType * bufferVars                     */
    BuffersDoubleVar,   /* CosmOS_BufferDoubleVariableType * const bufferDoubleVars   */
};
/* @cond S */
__SEC_STOP(__OS_VAR_SECTION_STOP)
/* @endcond*/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Variables_osCfg_c  
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
  * @defgroup Apis_osCfg_c API's  
  * @ingroup Local_osCfg
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_osCfg_c Getters  
  * @ingroup Apis_osCfg_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}       
  * Getters_osCfg_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_osCfg_c Setters  
  * @ingroup Apis_osCfg_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}    
  * Setters_osCfg_c   
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_osCfg_c General  
  * @ingroup Apis_osCfg_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_osCfg_c  
********************************************************************************/
/********************************************************************************
**                         Function Prototypes | Stop                          **
********************************************************************************/
/********************************************************************************
**                        Function Definitions | Start                         **
********************************************************************************/
/********************************************************************************
**                        Function Definitions | Stop                          **
********************************************************************************/
/********************************************************************************
**                           END OF THE SOURCE FILE                            **
********************************************************************************/
