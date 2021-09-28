/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file memoryProtection.c
*********************************************************************************
<!--              memoryProtection Unit Local Group Definition                -->
*********************************************************************************
** @defgroup Local_memoryProtection Local
** @ingroup memoryProtection_unit
** @brief memoryProtection locals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "core.h"
#include "stack.h"
#include "schedulable.h"
#include "program.h"
#include "memoryProtection.h"

/* CIL interfaces */
#include "CILmemoryProtection.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_memoryProtection_c Macros
  * @ingroup Local_memoryProtection
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Macros_memoryProtection_c
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
  * @defgroup Variables_memoryProtection_c Variables
  * @ingroup Local_memoryProtection
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Variables_memoryProtection_c
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
  * @defgroup Apis_memoryProtection_c API's
  * @ingroup Local_memoryProtection
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_memoryProtection_c Getters
  * @ingroup Apis_memoryProtection_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Getters_memoryProtection_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_memoryProtection_c Setters
  * @ingroup Apis_memoryProtection_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Setters_memoryProtection_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_memoryProtection_c General
  * @ingroup Apis_memoryProtection_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_memoryProtection_c
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
  * @fn memoryProtection_init(AddressType codeMemoryHighAddress,
  *							AddressType codeMemoryLowAddress,
  *							AddressType stackMemoryHighAddress,
  *							AddressType stackMemoryLowAddress,
  *							AddressType unprotectedMemoryLowAddress,
  *							AddressType unprotectedMemoryHighAddress)
  * @brief Init memory protection DEMO CODE.
  *
  * @param[in]  AddressType codeMemoryHighAddress
  * @param[in]  AddressType codeMemoryLowAddress
  * @param[in]  AddressType stackMemoryHighAddress
  * @param[in]  AddressType unprotectedMemoryLowAddress
  * @param[in]  AddressType unprotectedMemoryHighAddress
	*
  * @return none
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION void memoryProtection_init(AddressType codeMemoryHighAddress,\
												AddressType codeMemoryLowAddress,\
												AddressType stackMemoryHighAddress,\
												AddressType stackMemoryLowAddress,\
												AddressType unprotectedMemoryLowAddress,\
												AddressType unprotectedMemoryHighAddress)
{
    CILmemoryProtection_init(codeMemoryHighAddress,codeMemoryLowAddress,
							stackMemoryHighAddress,stackMemoryLowAddress,
							unprotectedMemoryLowAddress,unprotectedMemoryHighAddress);
}
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn memoryProtection_setStackOverflowProtection(CosmOS_StackConfigurationType * stack)
  *
  * @brief Set stack overflow protection.
  *
  * @param[in]  CosmOS_StackConfigurationType * stack
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void memoryProtection_setStackOverflowProtection(CosmOS_StackConfigurationType * stack)
{
    AddressType lowAddress,
                highAddress;

    lowAddress = stack_getStackLowAddress( stack );
    highAddress = stack_getStackHighAddress( stack );

    CILmemoryProtection_setStackOverflowProtection( lowAddress, highAddress );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn memoryProtection_setProgramMemoryProtection(CosmOS_ProgramVariableType * program)
  *
  * @brief Set program memory protection.
  *
  * @param[in]  CosmOS_ProgramVariableType * program
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void memoryProtection_setProgramMemoryProtection(CosmOS_ProgramVariableType * program)
{
    BitWidthType size;

    AddressType lowAddress,
                highAddress;

    size = program_getProgramMemorySize( program );
    lowAddress = program_getProgramMemoryLowAddress( program );
    highAddress = program_getProgramMemoryHighAddress( program );

    if ( size )
    {
        CILmemoryProtection_setProgramMemoryProtection( lowAddress, highAddress );
    }
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn memoryProtection_setSchedulablePeripheralProtection(CosmOS_SchedulableVariableType * schedulable)
  *
  * @brief Set schedulable peripheral protection.
  *
  * @param[in]  CosmOS_SchedulableVariableType * schedulable
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void memoryProtection_setSchedulablePeripheralProtection(CosmOS_SchedulableVariableType * schedulable)
{
    BitWidthType size;

    AddressType lowAddress,
                highAddress;

    size = schedulable_getPeripheralAccessSize( schedulable );
    lowAddress = schedulable_getPeripheralAccessLowAddress( schedulable );
    highAddress = schedulable_getPeripheralAccessHighAddress( schedulable );

    if ( size )
    {
        CILmemoryProtection_setSchedulablePeripheralProtection( lowAddress, highAddress );
    }
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn memoryProtection_setMemoryProtection(CosmOS_CoreVariableType * core,CosmOS_SchedulableVariableType  * schedulable)
  *
  * @brief Set memory protection for current execution context.
  *
  * @param[in]  CosmOS_CoreVariableType * core
  * @param[in]  CosmOS_SchedulableConfigurationType  * schedulable
  *
  * @return none
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION void memoryProtection_setMemoryProtection(CosmOS_CoreVariableType * core,CosmOS_SchedulableVariableType  * schedulable)
{
    BitWidthType programId;

    CosmOS_StackConfigurationType * stack;
    CosmOS_ProgramVariableType * programVar;


    programId = schedulable_getProgramId( schedulable );
    programVar = core_getCoreProgramVar( core, programId );

    stack = schedulable_getStack( schedulable );

    memoryProtection_setStackOverflowProtection( stack );
    memoryProtection_setProgramMemoryProtection( programVar );
	memoryProtection_setSchedulablePeripheralProtection( schedulable );
}
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn memoryProtection_isMemoryRegionProtected(CosmOS_CoreVariableType * core, void  * regionLowAddressPointer, BitWidthType size)
  *
  * @brief Check if specific memory region is protected against changes for the current execution context.
  *
  * @param[in]  CosmOS_CoreVariableType * core
  * @param[in]  void * regionLowAddressPointer
  * @param[in]  BitWidthType size
  *
  * @return CosmOS_BooleanType
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION CosmOS_BooleanType memoryProtection_isMemoryRegionProtected(CosmOS_CoreVariableType * core, void * regionLowAddressPointer, BitWidthType size)
{
    AddressType stackLowAddress,
                stackHighAddress,
				programLowAddress,
				programHighAddress,
				regionLowAddress,
				regionHighAddress;

	CosmOS_BooleanType isMemoryRegionProtected = True;

    CosmOS_StackConfigurationType * stack;
    CosmOS_ProgramVariableType * programVar;
	CosmOS_SchedulableVariableType * schedulable;

	regionLowAddress = (AddressType)regionLowAddressPointer;

    programVar = core_getCoreProgramInExecution( core );
	schedulable = core_getCoreSchedulableInExecution( core );
    stack = schedulable_getStack( schedulable );

	stackLowAddress = stack_getStackLowAddress( stack );
    stackHighAddress = stack_getStackHighAddress( stack );

    programLowAddress = program_getProgramMemoryLowAddress( programVar );
    programHighAddress = program_getProgramMemoryHighAddress( programVar );

	regionHighAddress = regionLowAddress + (AddressType)size;

	if (((regionHighAddress < stackHighAddress) && (regionLowAddress > stackLowAddress)) || \
		((regionHighAddress < programHighAddress) && (regionLowAddress > programLowAddress)))
	{
		isMemoryRegionProtected = False;
	}

	return isMemoryRegionProtected;
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
