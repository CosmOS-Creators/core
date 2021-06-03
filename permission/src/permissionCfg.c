/********************************************************************************
**                                                                             **
**                       GENERATED FILE BY CosmOS CustomBox                    **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file permissionCfg.c
*********************************************************************************
<!--                permissionCfg Unit Local Group Definition                -->
*********************************************************************************	
** @defgroup Local_permissionCfg Local
** @ingroup permissionCfg_unit 
** @brief permissionCfg locals
** @details lorem 
********************************************************************************/ 
/********************************************************************************  
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "permissionCfg.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_permissionCfg Macros
  * @ingroup Local_permissionCfg
  * @{    
********************************************************************************/
#define BITLOCK_ID_PLACEMENT_8BIT(id)   id,id,id,id,id,id,id,id,

#define BITLOCK_ID_PLACEMENT_16BIT(id)  id,id,id,id,id,id,id,id, \
                                        id,id,id,id,id,id,id,id,

#define BITLOCK_ID_PLACEMENT_32BIT(id)  id,id,id,id,id,id,id,id, \
                                        id,id,id,id,id,id,id,id, \
                                        id,id,id,id,id,id,id,id, \
                                        id,id,id,id,id,id,id,id,

#define BITLOCK_ID_PLACEMENT_64BIT(id)  id,id,id,id,id,id,id,id, \
                                        id,id,id,id,id,id,id,id, \
                                        id,id,id,id,id,id,id,id, \
                                        id,id,id,id,id,id,id,id, \
                                        id,id,id,id,id,id,id,id, \
                                        id,id,id,id,id,id,id,id, \
                                        id,id,id,id,id,id,id,id, \
                                        id,id,id,id,id,id,id,id,
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Macros_permissionCfg  
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
  * @defgroup Variables_permissionCfg Variables  
  * @ingroup Local_permissionCfg
  * @{    
********************************************************************************/
/* @cond S */
__SEC_START(__OS_CONST_SECTION_START)
/* @endcond*/
const unsigned char SchedulableIdToBitLock[((MAX_SCHEDULABLES_ON_ONE_CORE/(sizeof(BitWidthType)*8)) + 1)*(sizeof(BitWidthType)*8)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		BITLOCK_ID_PLACEMENT_32BIT(0)
};

const BitWidthType BitLockBuffer0SchedulablesCore0ReadCfgConst[((TASK_NUM_CORE_0/(sizeof(BitWidthType)*8)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		0b00000000000000000000000000000000,
};
const BitWidthType BitLockBuffer0SchedulablesCore1ReadCfgConst[((TASK_NUM_CORE_1/(sizeof(BitWidthType)*8)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		0b00000000000000000000000001010000,
};
const BitWidthType BitLockBuffer1SchedulablesCore0ReadCfgConst[((TASK_NUM_CORE_0/(sizeof(BitWidthType)*8)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		0b00000000000000000000000000000000,
};
const BitWidthType BitLockBuffer1SchedulablesCore1ReadCfgConst[((TASK_NUM_CORE_1/(sizeof(BitWidthType)*8)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		0b00000000000000000000000001010000,
};

const BitWidthType BitLockBuffer0SchedulablesCore0WriteCfgConst[((TASK_NUM_CORE_0/(sizeof(BitWidthType)*8)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		0b00000000000000000000000000000101,
};
const BitWidthType BitLockBuffer0SchedulablesCore1WriteCfgConst[((TASK_NUM_CORE_1/(sizeof(BitWidthType)*8)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		0b00000000000000000000000000000000,
};
const BitWidthType BitLockBuffer1SchedulablesCore0WriteCfgConst[((TASK_NUM_CORE_0/(sizeof(BitWidthType)*8)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		0b00000000000000000000000000000101,
};
const BitWidthType BitLockBuffer1SchedulablesCore1WriteCfgConst[((TASK_NUM_CORE_1/(sizeof(BitWidthType)*8)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		0b00000000000000000000000000000000,
};

const BitWidthType BitLockBuffer0SchedulablesCore0ReadCfgInvertedConst[((TASK_NUM_CORE_0/(sizeof(BitWidthType)*8)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		0b11111111111111111111111111111111,
};
const BitWidthType BitLockBuffer0SchedulablesCore1ReadCfgInvertedConst[((TASK_NUM_CORE_1/(sizeof(BitWidthType)*8)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		0b11111111111111111111111110101111,
};
const BitWidthType BitLockBuffer1SchedulablesCore0ReadCfgInvertedConst[((TASK_NUM_CORE_0/(sizeof(BitWidthType)*8)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		0b11111111111111111111111111111111,
};
const BitWidthType BitLockBuffer1SchedulablesCore1ReadCfgInvertedConst[((TASK_NUM_CORE_1/(sizeof(BitWidthType)*8)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		0b11111111111111111111111110101111,
};

const BitWidthType BitLockBuffer0SchedulablesCore0WriteCfgInvertedConst[((TASK_NUM_CORE_0/(sizeof(BitWidthType)*8)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		0b11111111111111111111111111111010,
};
const BitWidthType BitLockBuffer0SchedulablesCore1WriteCfgInvertedConst[((TASK_NUM_CORE_1/(sizeof(BitWidthType)*8)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		0b11111111111111111111111111111111,
};
const BitWidthType BitLockBuffer1SchedulablesCore0WriteCfgInvertedConst[((TASK_NUM_CORE_0/(sizeof(BitWidthType)*8)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		0b11111111111111111111111111111010,
};
const BitWidthType BitLockBuffer1SchedulablesCore1WriteCfgInvertedConst[((TASK_NUM_CORE_1/(sizeof(BitWidthType)*8)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		0b11111111111111111111111111111111,
};

const CosmOS_PermissionsConfigurationType PermissionsBuffer0ReadCfgConst[CORE_NUM] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		{   /* CORE_0_ID */
        BitLockBuffer0SchedulablesCore0ReadCfgConst,
        BitLockBuffer0SchedulablesCore0ReadCfgInvertedConst,
    },
		{   /* CORE_1_ID */
        BitLockBuffer0SchedulablesCore1ReadCfgConst,
        BitLockBuffer0SchedulablesCore1ReadCfgInvertedConst,
    },
};
const CosmOS_PermissionsConfigurationType PermissionsBuffer1ReadCfgConst[CORE_NUM] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		{   /* CORE_0_ID */
        BitLockBuffer1SchedulablesCore0ReadCfgConst,
        BitLockBuffer1SchedulablesCore0ReadCfgInvertedConst,
    },
		{   /* CORE_1_ID */
        BitLockBuffer1SchedulablesCore1ReadCfgConst,
        BitLockBuffer1SchedulablesCore1ReadCfgInvertedConst,
    },
};

const CosmOS_PermissionsConfigurationType PermissionsBuffer0WriteCfgConst[CORE_NUM] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		{   /* CORE_0_ID */
        BitLockBuffer0SchedulablesCore0WriteCfgConst,
        BitLockBuffer0SchedulablesCore0WriteCfgInvertedConst,
    },
		{   /* CORE_1_ID */
        BitLockBuffer0SchedulablesCore1WriteCfgConst,
        BitLockBuffer0SchedulablesCore1WriteCfgInvertedConst,
    },
};
const CosmOS_PermissionsConfigurationType PermissionsBuffer1WriteCfgConst[CORE_NUM] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		{   /* CORE_0_ID */
        BitLockBuffer1SchedulablesCore0WriteCfgConst,
        BitLockBuffer1SchedulablesCore0WriteCfgInvertedConst,
    },
		{   /* CORE_1_ID */
        BitLockBuffer1SchedulablesCore1WriteCfgConst,
        BitLockBuffer1SchedulablesCore1WriteCfgInvertedConst,
    },
};
/* @cond S */
__SEC_STOP(__OS_CONST_SECTION_STOP)
/* @endcond*/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Variables_permissionCfg  
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
  * @defgroup Apis_permissionCfg_c API's  
  * @ingroup Local_permissionCfg
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_permissionCfg_c Getters  
  * @ingroup Apis_permissionCfg_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}       
  * Getters_permissionCfg_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_permissionCfg_c Setters  
  * @ingroup Apis_permissionCfg_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}    
  * Setters_permissionCfg_c   
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_permissionCfg_c General  
  * @ingroup Apis_permissionCfg_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_permissionCfg_c  
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