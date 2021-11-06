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
#include "memoryProtection.h"
#include "core.h"
#include "program.h"
#include "schedulable.h"
#include "stack.h"

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
  * @} */
/*  Macros_memoryProtection_c
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
  * @} */
/*  Variables_memoryProtection_c
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
  * @} */
/*  Getters_memoryProtection_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_memoryProtection_c Setters
  * @ingroup Apis_memoryProtection_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn memoryProtection_setStackOverflowProtection(
  * CosmOS_StackConfigurationType * stack)
  *
  * @brief Set stack overflow protection.
  *
  * @param[in]  stack pointer to the stack configuration type
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
memoryProtection_setStackOverflowProtection(
    CosmOS_StackConfigurationType * stack );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn memoryProtection_setProgramMemoryProtection(
  * CosmOS_ProgramConfigurationType * program)
  *
  * @brief Set program memory protection.
  *
  * @param[in]  program pointer to the program variable type
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
memoryProtection_setProgramMemoryProtection(
    CosmOS_ProgramConfigurationType * program );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn memoryProtection_setSchedulablePeripheralProtection(
  * CosmOS_SchedulableConfigurationType * schedulable)
  *
  * @brief Set schedulable peripheral protection.
  *
  * @param[in]  schedulable configuration pointer
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
memoryProtection_setSchedulablePeripheralProtection(
    CosmOS_SchedulableConfigurationType * schedulable );
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_memoryProtection_c
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
  * @} */
/*  General_memoryProtection_c
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
  * @fn memoryProtection_setStackOverflowProtection(
  * CosmOS_StackConfigurationType * stack)
  *
  * @details The implementation contains obtaining of the stack low and high
  * address for the current stack argument by calling functions
  * stack_getStackLowAddress and stack_getStackHighAddress. After this the
  * CILmemoryProtection_setStackOverflowProtection is called to set stack
  * overflow protection for the specified addresses.
********************************************************************************/
__STATIC_FORCEINLINE void
memoryProtection_setStackOverflowProtection(
    CosmOS_StackConfigurationType * stack )
{
    AddressType lowAddress, highAddress;

    lowAddress = stack_getStackLowAddress( stack );
    highAddress = stack_getStackHighAddress( stack );

    CILmemoryProtection_setStackOverflowProtection( lowAddress, highAddress );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn memoryProtection_setProgramMemoryProtection(
  * CosmOS_ProgramConfigurationType * program)
  *
  * @details The implementation contains obtaining of the program size, low and
  * high address for the current program variable argument by calling functions
  * program_getProgramMemorySize, program_getProgramMemoryLowAddress and
  * program_getProgramMemoryHighAddress. After this the if condition is
  * implemented to check if the program size is non-zero value and then the
  * CILmemoryProtection_setProgramMemoryProtection is called to set program
  * memory protection for the specified addresses.
********************************************************************************/
__STATIC_FORCEINLINE void
memoryProtection_setProgramMemoryProtection(
    CosmOS_ProgramConfigurationType * program )
{
    BitWidthType size;

    AddressType lowAddress, highAddress;

    size = program_getProgramMemorySize( program );
    lowAddress = program_getProgramMemoryLowAddress( program );
    highAddress = program_getProgramMemoryHighAddress( program );

    if ( size )
    {
        CILmemoryProtection_setProgramMemoryProtection(
            lowAddress, highAddress );
    }
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn memoryProtection_setSchedulablePeripheralProtection(
  * CosmOS_SchedulableConfigurationType * schedulable)
  *
  * @details The implementation contains obtaining of the schedulable peripheral
  * access region size, low and high address for the current schedulable variable
  * argument by calling functions schedulable_getPeripheralAccessSize,
  * schedulable_getPeripheralAccessLowAddress and
  * schedulable_getPeripheralAccessHighAddress. After this the if condition is
  * implemented to check if the schedulable peripheral access region size is
  * non-zero value and then the
  * CILmemoryProtection_setSchedulablePeripheralProtection is called to set
  * peripheral access region memory protection for the specified addresses.
********************************************************************************/
__STATIC_FORCEINLINE void
memoryProtection_setSchedulablePeripheralProtection(
    CosmOS_SchedulableConfigurationType * schedulable )
{
    BitWidthType size;

    AddressType lowAddress, highAddress;

    size = schedulable_getPeripheralAccessSize( schedulable );
    lowAddress = schedulable_getPeripheralAccessLowAddress( schedulable );
    highAddress = schedulable_getPeripheralAccessHighAddress( schedulable );

    if ( size )
    {
        CILmemoryProtection_setSchedulablePeripheralProtection(
            lowAddress, highAddress );
    }
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn memoryProtection_init(AddressType codeMemoryHighAddress,
  * AddressType codeMemoryLowAddress,
  * AddressType stackMemoryHighAddress,
  * AddressType stackMemoryLowAddress,
  * AddressType unprotectedMemoryLowAddress,
  * AddressType unprotectedMemoryHighAddress)
  *
  * @details The implementation contains CILmemoryProtection_init function call.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
memoryProtection_init(
    AddressType codeMemoryHighAddress,
    AddressType codeMemoryLowAddress,
    AddressType stackMemoryHighAddress,
    AddressType stackMemoryLowAddress,
    AddressType unprotectedMemoryLowAddress,
    AddressType unprotectedMemoryHighAddress )
{
    CILmemoryProtection_init(
        codeMemoryHighAddress,
        codeMemoryLowAddress,
        stackMemoryHighAddress,
        stackMemoryLowAddress,
        unprotectedMemoryLowAddress,
        unprotectedMemoryHighAddress );
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn memoryProtection_setMemoryProtection(CosmOS_CoreConfigurationType * core,
  * CosmOS_SchedulableConfigurationType * schedulable)
  *
  * @details The implementation contains obtaining of the program id and program
  * variable by calling schedulable_getProgramId and core_getCoreProgramCfg
  * functions. From the schedulable variable argument is also extracted its
  * stack configuration by calling schedulable_getStack. After this point
  * the memory protection is set for the stack, peripheral and program memory by
  * calling functions memoryProtection_setStackOverflowProtection,
  * memoryProtection_setProgramMemoryProtection and
  * memoryProtection_setSchedulablePeripheralProtection.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
memoryProtection_setMemoryProtection(
    CosmOS_CoreConfigurationType * core,
    CosmOS_SchedulableConfigurationType * schedulable )
{
    BitWidthType programId;

    CosmOS_StackConfigurationType * stack;
    CosmOS_ProgramConfigurationType * programVar;

    programId = schedulable_getProgramId( schedulable );
    programVar = core_getCoreProgramCfg( core, programId );

    stack = schedulable_getStack( schedulable );

    memoryProtection_setStackOverflowProtection( stack );
    memoryProtection_setProgramMemoryProtection( programVar );
    memoryProtection_setSchedulablePeripheralProtection( schedulable );
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn memoryProtection_isMemoryRegionProtected(
  * CosmOS_CoreConfigurationType * core,
  * void  * regionLowAddressPointer,
  * BitWidthType size)
  *
  * @details The implementation contains obtaining of the program
  * variable by calling core_getCoreProgramInExecution function and schedulable
  * variable by calling core_getCoreSchedulableInExecution that is then used
  * to get stack configuration from the stack by calling schedulable_getStack
  * function.
  * Subsequently the low and high addresses of the stack, peripheral access
  * region and program memory are obtained by calling functions
  * stack_getStackLowAddress, stack_getStackHighAddress,
  * schedulable_getPeripheralAccessLowAddress,
  * schedulable_getPeripheralAccessHighAddress,
  * program_getProgramMemoryLowAddress, program_getProgramMemoryHighAddress.
  * Then is the if condition implemented where is the region checked agains
  * all addresses and the isMemoryRegionProtected returned with the boolean
  * value.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_BooleanType
memoryProtection_isMemoryRegionProtected(
    CosmOS_CoreConfigurationType * core,
    AddressType * regionLowAddressPointer,
    BitWidthType size )
{
    AddressType stackLowAddress, stackHighAddress, programLowAddress,
        programHighAddress, regionLowAddress, regionHighAddress,
        peripheralLowAddress, peripheralHighAddress;

    CosmOS_BooleanType isMemoryRegionProtected = True;

    CosmOS_StackConfigurationType * stack;
    CosmOS_ProgramConfigurationType * programVar;
    CosmOS_SchedulableConfigurationType * schedulable;

    regionLowAddress = (AddressType)regionLowAddressPointer;

    programVar = core_getCoreProgramInExecution( core );
    schedulable = core_getCoreSchedulableInExecution( core );
    stack = schedulable_getStack( schedulable );

    stackLowAddress = stack_getStackLowAddress( stack );
    stackHighAddress = stack_getStackHighAddress( stack );

    peripheralLowAddress =
        schedulable_getPeripheralAccessLowAddress( schedulable );
    peripheralHighAddress =
        schedulable_getPeripheralAccessHighAddress( schedulable );

    programLowAddress = program_getProgramMemoryLowAddress( programVar );
    programHighAddress = program_getProgramMemoryHighAddress( programVar );

    regionHighAddress = regionLowAddress + (AddressType)size;

    if ( ( ( regionHighAddress < stackHighAddress ) &&
           ( regionLowAddress > stackLowAddress ) ) ||
         ( ( regionHighAddress < peripheralHighAddress ) &&
           ( regionLowAddress > peripheralLowAddress ) ) ||
         ( ( regionHighAddress < programHighAddress ) &&
           ( regionLowAddress > programLowAddress ) ) )
    {
        isMemoryRegionProtected = False;
    }

    return isMemoryRegionProtected;
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
