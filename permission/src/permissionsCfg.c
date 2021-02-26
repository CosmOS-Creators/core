/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file permissionsCfg.c
*********************************************************************************
<!--                permissionsCfg Unit Local Group Definition                -->
*********************************************************************************	
** @defgroup Local_permissionsCfg Local
** @ingroup permissionsCfg_unit 
** @brief permissionsCfg locals
** @details lorem 
********************************************************************************/ 
/********************************************************************************  
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "permissionsCfg.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_permissionsCfg Macros
  * @ingroup Local_permissionsCfg
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Macros_permissionsCfg  
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
  * @defgroup Variables_permissionsCfg Variables  
  * @ingroup Local_permissionsCfg
  * @{    
********************************************************************************/
/* @cond S */
__SEC_START(__OS_CONST_SECTION_START)
/* @endcond*/
const BitWidthType BitLockBuffer0TasksCore0ReadCfgConst[((TASK_NUM_CORE_0/sizeof(BitWidthType)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
    0b00000000000000000000000000000001,
};

const BitWidthType BitLockBuffer0TasksCore1ReadCfgConst[((TASK_NUM_CORE_1/sizeof(BitWidthType)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
    0b00000000000000000000000000000000,
};

const BitWidthType BitLockBuffer0TasksCore0WriteCfgConst[((TASK_NUM_CORE_0/sizeof(BitWidthType)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
    0b00000000000000000000000000000000,
};

const BitWidthType BitLockBuffer0TasksCore1WriteCfgConst[((TASK_NUM_CORE_1/sizeof(BitWidthType)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
    0b00000000000000000000000000000001,
};

const BitWidthType BitLockBuffer0ThreadsCore0ReadCfgConst[((THREAD_NUM_CORE_0/sizeof(BitWidthType)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
    0b00000000000000000000000000000000,
};

const BitWidthType BitLockBuffer0ThreadsCore1ReadCfgConst[((THREAD_NUM_CORE_1/sizeof(BitWidthType)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
    0b00000000000000000000000000000000,
};

const BitWidthType BitLockBuffer0ThreadsCore0WriteCfgConst[((THREAD_NUM_CORE_0/sizeof(BitWidthType)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
    0b00000000000000000000000000000000,
};

const BitWidthType BitLockBuffer0ThreadsCore1WriteCfgConst[((THREAD_NUM_CORE_1/sizeof(BitWidthType)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
    0b00000000000000000000000000000000,
};

const BitWidthType BitLockBuffer0TasksCore0ReadCfgInversedConst[((TASK_NUM_CORE_0/sizeof(BitWidthType)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
    0b11111111111111111111111111111110,
};

const BitWidthType BitLockBuffer0TasksCore1ReadCfgInversedConst[((TASK_NUM_CORE_1/sizeof(BitWidthType)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
    0b11111111111111111111111111111111,
};

const BitWidthType BitLockBuffer0TasksCore0WriteCfgInversedConst[((TASK_NUM_CORE_0/sizeof(BitWidthType)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
    0b11111111111111111111111111111111,
};

const BitWidthType BitLockBuffer0TasksCore1WriteCfgInversedConst[((TASK_NUM_CORE_1/sizeof(BitWidthType)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
    0b11111111111111111111111111111110,
};

const BitWidthType BitLockBuffer0ThreadsCore0ReadCfgInversedConst[((THREAD_NUM_CORE_0/sizeof(BitWidthType)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
    0b11111111111111111111111111111111,
};

const BitWidthType BitLockBuffer0ThreadsCore1ReadCfgInversedConst[((THREAD_NUM_CORE_1/sizeof(BitWidthType)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
    0b11111111111111111111111111111111,
};

const BitWidthType BitLockBuffer0ThreadsCore0WriteCfgInversedConst[((THREAD_NUM_CORE_0/sizeof(BitWidthType)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
    0b11111111111111111111111111111111,
};

const BitWidthType BitLockBuffer0ThreadsCore1WriteCfgInversedConst[((THREAD_NUM_CORE_1/sizeof(BitWidthType)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
    0b11111111111111111111111111111111,
};

const CosmOS_PermissionsConfigurationType PermissionsBuffer0ReadCfgConst[CORE_NUM] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
    {   /* CORE_0_ID */
        BitLockBuffer0TasksCore0ReadCfgConst,
        BitLockBuffer0ThreadsCore0ReadCfgConst,
        BitLockBuffer0TasksCore0ReadCfgInversedConst,
        BitLockBuffer0ThreadsCore0ReadCfgInversedConst,
    },
    {   /* CORE_1_ID */
        BitLockBuffer0TasksCore1ReadCfgConst,
        BitLockBuffer0ThreadsCore1ReadCfgConst,
        BitLockBuffer0TasksCore1ReadCfgInversedConst,
        BitLockBuffer0ThreadsCore1ReadCfgInversedConst,
    },
};

const CosmOS_PermissionsConfigurationType PermissionsBuffer0WriteCfgConst[CORE_NUM] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
    {   /* CORE_0_ID */
        BitLockBuffer0TasksCore0WriteCfgConst,
        BitLockBuffer0ThreadsCore0WriteCfgConst,
        BitLockBuffer0TasksCore0WriteCfgInversedConst,
        BitLockBuffer0ThreadsCore0WriteCfgInversedConst,
    },
    {   /* CORE_1_ID */
        BitLockBuffer0TasksCore1WriteCfgConst,
        BitLockBuffer0ThreadsCore1WriteCfgConst,
        BitLockBuffer0TasksCore1WriteCfgInversedConst,
        BitLockBuffer0ThreadsCore1WriteCfgInversedConst,            
    },
};
/* @cond S */
__SEC_STOP(__OS_CONST_SECTION_STOP)
/* @endcond*/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Variables_permissionsCfg  
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
  * @defgroup Apis_permissionsCfg_c API's  
  * @ingroup Local_permissionsCfg
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_permissionsCfg_c Getters  
  * @ingroup Apis_permissionsCfg_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}       
  * Getters_permissionsCfg_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_permissionsCfg_c Setters  
  * @ingroup Apis_permissionsCfg_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}    
  * Setters_permissionsCfg_c   
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_permissionsCfg_c General  
  * @ingroup Apis_permissionsCfg_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_permissionsCfg_c  
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
