/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file os.c
*********************************************************************************
<!--                      os Unit Local Group Definition                      -->
*********************************************************************************
** @defgroup Local_os Local
** @ingroup os_unit
** @brief os locals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "os.h"
#include "core.h"
#include "osCfg.h"
#include "scheduler.h"

/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_os Macros
  * @ingroup Local_os
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_os
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
  * @defgroup Variables_os Variables
  * @ingroup Local_os
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_os
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
  * @defgroup Apis_os_c API's
  * @ingroup Local_os
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_os_c Getters
  * @ingroup Apis_os_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_os_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_os_c Setters
  * @ingroup Apis_os_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_os_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_os_c General
  * @ingroup Apis_os_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_os_c
********************************************************************************/
/********************************************************************************
**                         Function Prototypes | Stop                          **
********************************************************************************/
/********************************************************************************
**                        Function Definitions | Start                         **
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn os_start(BitWidthType entityId)
  *
  * @details The implementation contains scheduler_start function call that does
  * not return.
  *
  * @see TEST_OS_START_EXECUTIONFLOW
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
os_start( BitWidthType entityId )
{
    scheduler_start();

    __SUPRESS_UNUSED_VAR( entityId );
};
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn os_getOsCfg(void)
  *
  * @details The implementation contains return of the generated operating
  * system configuration structure.
  *
  * @see TEST_OS_GETOSVAR_RETURNVALUE
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_OsConfigurationType *
os_getOsCfg( void )
{
    return (CosmOS_OsConfigurationType *)&OsCfg;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn os_kernelPanic(void)
  *
  * @details The implementation contains call to the kernel panic hook
  * configured by the user.
  *
  * @see TEST_OS_KERNELPANIC_EXECUTIONFLOW
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
os_kernelPanic( void )
{
    CosmOS_CoreConfigurationType * coreCfg;

    coreCfg = core_getCoreCfg();
    coreCfg->kernelPanicHook();

    for ( ;; )
        ;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn os_write8( BitWidthType entityId, uint8_t * address, uint8_t value )
  *
  * @details The implementation contains write operation of the value to the
  * specific address.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
os_write8( BitWidthType entityId, uint8_t * address, uint8_t value )
{
    /* TODO: some mechanism to check if the user has permission to write to
    this specific memory, alignment check */
    *address = value;
    __SUPRESS_UNUSED_VAR( entityId );
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn os_write16( BitWidthType entityId, uint16_t * address, uint16_t value )
  *
  * @details The implementation contains write operation of the value to the
  * specific address.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
os_write16( BitWidthType entityId, uint16_t * address, uint16_t value )
{
    /* TODO: some mechanism to check if the user has permission to write to
    this specific memory, alignment check */
    *address = value;
    __SUPRESS_UNUSED_VAR( entityId );
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn os_write32( BitWidthType entityId, uint32_t * address, uint32_t value )
  *
  * @details The implementation contains write operation of the value to the
  * specific address.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
os_write32( BitWidthType entityId, uint32_t * address, uint32_t value )
{
    /* TODO: some mechanism to check if the user has permission to write to
    this specific memory, alignment check */
    *address = value;
    __SUPRESS_UNUSED_VAR( entityId );
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/
/********************************************************************************
**                        Function Definitions | Stop                          **
********************************************************************************/
/********************************************************************************
**                           END OF THE SOURCE FILE                            **
********************************************************************************/
