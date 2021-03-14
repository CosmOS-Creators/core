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
const BitWidthType TaskIdToBitLock[MAX_TASKS_ON_ONE_CORE*sizeof(BitWidthType)*8] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		BITLOCK_ID_PLACEMENT_32BIT(0)
		BITLOCK_ID_PLACEMENT_32BIT(1)
};

const BitWidthType BitLockBuffer0TasksCore0ReadCfgConst[((TASK_NUM_CORE_0/sizeof(BitWidthType)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		0b00000000000000000000000000000000,
};
const BitWidthType BitLockBuffer0TasksCore1ReadCfgConst[((TASK_NUM_CORE_1/sizeof(BitWidthType)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		0b00000000000000000000000000000001,
};
const BitWidthType BitLockBuffer1TasksCore0ReadCfgConst[((TASK_NUM_CORE_0/sizeof(BitWidthType)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		0b00000000000000000000000000000000,
};
const BitWidthType BitLockBuffer1TasksCore1ReadCfgConst[((TASK_NUM_CORE_1/sizeof(BitWidthType)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		0b00000000000000000000000000000001,
};

const BitWidthType BitLockBuffer0TasksCore0WriteCfgConst[((TASK_NUM_CORE_0/sizeof(BitWidthType)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		0b00000000000000000000000000000001,
};
const BitWidthType BitLockBuffer0TasksCore1WriteCfgConst[((TASK_NUM_CORE_1/sizeof(BitWidthType)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		0b00000000000000000000000000000000,
};
const BitWidthType BitLockBuffer1TasksCore0WriteCfgConst[((TASK_NUM_CORE_0/sizeof(BitWidthType)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		0b00000000000000000000000000000001,
};
const BitWidthType BitLockBuffer1TasksCore1WriteCfgConst[((TASK_NUM_CORE_1/sizeof(BitWidthType)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		0b00000000000000000000000000000000,
};

const BitWidthType BitLockBuffer0TasksCore0ReadCfgInvertedConst[((TASK_NUM_CORE_0/sizeof(BitWidthType)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		0b11111111111111111111111111111111,
};
const BitWidthType BitLockBuffer0TasksCore1ReadCfgInvertedConst[((TASK_NUM_CORE_1/sizeof(BitWidthType)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		0b11111111111111111111111111111110,
};
const BitWidthType BitLockBuffer1TasksCore0ReadCfgInvertedConst[((TASK_NUM_CORE_0/sizeof(BitWidthType)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		0b11111111111111111111111111111111,
};
const BitWidthType BitLockBuffer1TasksCore1ReadCfgInvertedConst[((TASK_NUM_CORE_1/sizeof(BitWidthType)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		0b11111111111111111111111111111110,
};

const BitWidthType BitLockBuffer0TasksCore0WriteCfgInvertedConst[((TASK_NUM_CORE_0/sizeof(BitWidthType)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		0b11111111111111111111111111111110,
};
const BitWidthType BitLockBuffer0TasksCore1WriteCfgInvertedConst[((TASK_NUM_CORE_1/sizeof(BitWidthType)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		0b11111111111111111111111111111111,
};
const BitWidthType BitLockBuffer1TasksCore0WriteCfgInvertedConst[((TASK_NUM_CORE_0/sizeof(BitWidthType)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		0b11111111111111111111111111111110,
};
const BitWidthType BitLockBuffer1TasksCore1WriteCfgInvertedConst[((TASK_NUM_CORE_1/sizeof(BitWidthType)) + 1)] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		0b11111111111111111111111111111111,
};

const CosmOS_PermissionsConfigurationType PermissionsBuffer0ReadCfgConst[CORE_NUM] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		{   /* CORE_0_ID */
        BitLockBuffer0TasksCore0ReadCfgConst,
        BitLockBuffer0TasksCore0ReadCfgInvertedConst,
    },
		{   /* CORE_1_ID */
        BitLockBuffer0TasksCore1ReadCfgConst,
        BitLockBuffer0TasksCore1ReadCfgInvertedConst,
    },
};
const CosmOS_PermissionsConfigurationType PermissionsBuffer1ReadCfgConst[CORE_NUM] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		{   /* CORE_0_ID */
        BitLockBuffer1TasksCore0ReadCfgConst,
        BitLockBuffer1TasksCore0ReadCfgInvertedConst,
    },
		{   /* CORE_1_ID */
        BitLockBuffer1TasksCore1ReadCfgConst,
        BitLockBuffer1TasksCore1ReadCfgInvertedConst,
    },
};

const CosmOS_PermissionsConfigurationType PermissionsBuffer0WriteCfgConst[CORE_NUM] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		{   /* CORE_0_ID */
        BitLockBuffer0TasksCore0WriteCfgConst,
        BitLockBuffer0TasksCore0WriteCfgInvertedConst,
    },
		{   /* CORE_1_ID */
        BitLockBuffer0TasksCore1WriteCfgConst,
        BitLockBuffer0TasksCore1WriteCfgInvertedConst,
    },
};
const CosmOS_PermissionsConfigurationType PermissionsBuffer1WriteCfgConst[CORE_NUM] __OS_CONST_SECTION
IS_INITIALIZED_TO
{
		{   /* CORE_0_ID */
        BitLockBuffer1TasksCore0WriteCfgConst,
        BitLockBuffer1TasksCore0WriteCfgInvertedConst,
    },
		{   /* CORE_1_ID */
        BitLockBuffer1TasksCore1WriteCfgConst,
        BitLockBuffer1TasksCore1WriteCfgInvertedConst,
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