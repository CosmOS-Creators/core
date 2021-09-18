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
#include "scheduler.h"
#include "core.h"
#include "osCfg.h"
#include "os.h"
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
  * @}
  * Macros_os
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
  * @}
  * Variables_os
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
  * @}
  * Getters_os_c
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
  * @}
  * Setters_os_c
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
  * @}
  * General_os_c
********************************************************************************/
/********************************************************************************
**                         Function Prototypes | Stop                          **
********************************************************************************/
/********************************************************************************
**                        Function Definitions | Start                         **
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn os_start(BitWidthType entityId)
  *
  * @brief Start operating system. DEMO / NO RETURN FUNC
  *
  * @param[in]  BitWidthType entityId
  *
  * @return none
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION void os_start(BitWidthType entityId)
{
    scheduler_start();

	__SUPRESS_UNUSED_VAR(entityId);
};
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn os_getOsVar(void)
  *
  * @brief Get osVar.
  *
  * @param[in]  none
  *
  * @return CosmOS_OsVariableType *
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION CosmOS_OsVariableType * os_getOsVar(void)
{
    return &OsVar;
}
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn os_kernelPanic(void)
  *
  * @brief OS kernel panic function DEMO.
  *
  * @param[in]  none
  *
  * @return none
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION void os_kernelPanic(void)
{
	CosmOS_CoreVariableType * coreVar;


	coreVar = core_getCoreVar();
    coreVar->cfg->kernelPanicHook();

	for(;;);
}
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn os_write8(void)
  *
  * @brief OS write to protected memory 8bit variable DEMO.
  *
  * @param[in]  BitWidthType entityId
  * @param[in]  uint8_t *address
  * @param[in]  uint8_t value
  *
  * @return none
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION void os_write8(BitWidthType entityId,uint8_t *address,uint8_t value)
{
	//TODO: memoryProtection_isMemoryRegionProtected check
	*address = value;
	__SUPRESS_UNUSED_VAR(entityId);
}
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn os_write16(void)
  *
  * @brief OS write to protected memory 16bit variable DEMO.
  *
  * @param[in]  BitWidthType entityId
  * @param[in]  uint16_t *address
  * @param[in]  uint16_t value
  *
  * @return none
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION void os_write16(BitWidthType entityId,uint16_t *address,uint16_t value)
{
	//TODO: memoryProtection_isMemoryRegionProtected check
	*address = value;
	__SUPRESS_UNUSED_VAR(entityId);
}
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn os_write32(void)
  *
  * @brief OS write to protected memory 32bit variable DEMO.
  *
  * @param[in]  BitWidthType entityId
  * @param[in]  uint32_t *address
  * @param[in]  uint32_t value
  *
  * @return none
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION void os_write32(BitWidthType entityId,uint32_t *address,uint32_t value)
{
	//TODO: memoryProtection_isMemoryRegionProtected check
	*address = value;
	__SUPRESS_UNUSED_VAR(entityId);
}
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/
/********************************************************************************
**                        Function Definitions | Stop                          **
********************************************************************************/
/********************************************************************************
**                           END OF THE SOURCE FILE                            **
********************************************************************************/
