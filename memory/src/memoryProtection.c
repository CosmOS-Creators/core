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
#include "task.h"
#include "stack.h"
#include "program.h"
#include "memoryProtection.h"

/* CIL interfaces */
#include "CIL_memoryProtection.h"
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
  * @fn memoryProtection_init(CosmOS_StackVariableType * stack)
  * 
  * @brief Set stack overflow protection.
  * 
  * @param[in]  none
  * 
  * @return none
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION void memoryProtection_init(void)
{
    CIL_memoryProtection_init();
}
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn memoryProtection_setStackOverflowProtection(CosmOS_StackVariableType * stack)
  * 
  * @brief Set stack overflow protection.
  * 
  * @param[in]  CosmOS_StackVariableType * stack
  * 
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void memoryProtection_setStackOverflowProtection(CosmOS_StackVariableType * stack)
{
    AddressType stackLowAddress,
                 stackHighAddress;

    stackLowAddress = stack_getStackLowAddress( stack );
    stackHighAddress = stack_getStackHighAddress( stack );

    CIL_memoryProtection_setStackOverflowProtection( stackLowAddress, stackHighAddress );
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
        CIL_memoryProtection_setProgramMemoryProtection( lowAddress, highAddress );
    }
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn memoryProtection_setMemoryProtection(CosmOS_CoreVariableType * core,CosmOS_TaskVariableType * task)
  * 
  * @brief Set memory protection for current execution context.
  * 
  * @param[in]  CosmOS_CoreVariableType * core
  * @param[in]  CosmOS_TaskVariableType * task
  * 
  * @return none
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION void memoryProtection_setMemoryProtection(CosmOS_CoreVariableType * core,CosmOS_TaskVariableType * task)
{
    BitWidthType programId;

    CosmOS_StackVariableType * stackVar;
    CosmOS_ProgramVariableType * programVar;

    programId = task_getTaskProgramId( task );
    programVar = core_getCoreProgramVar( core, programId ); 

    stackVar = task_getTaskStackVar( task );

    memoryProtection_setStackOverflowProtection( stackVar );
    memoryProtection_setProgramMemoryProtection( programVar );
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
