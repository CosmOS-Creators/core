/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file stackInit.c
*********************************************************************************
<!--                  stackInit Unit Local Group Definition                   -->
*********************************************************************************	
** @defgroup Local_stackInit Local
** @ingroup stackInit_unit 
** @brief stackInit locals
** @details lorem 
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "stackInit.h"
#include "stack.h"
#include "core.h"
#include "program.h"
#include "task.h"
#include "thread.h"
#include "schedulable.h"

/* CIL interfaces */
#include "CIL_stack.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_stackInit_c Macros
  * @ingroup Local_stackInit
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Macros_stackInit_c  
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
  * @defgroup Variables_stackInit_c Variables  
  * @ingroup Local_stackInit
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Variables_stackInit_c  
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
  * @defgroup Apis_stackInit_c API's  
  * @ingroup Local_stackInit
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_stackInit_c Getters  
  * @ingroup Apis_stackInit_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}       
  * Getters_stackInit_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_stackInit_c Setters  
  * @ingroup Apis_stackInit_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}    
  * Setters_stackInit_c   
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_stackInit_c General  
  * @ingroup Apis_stackInit_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_stackInit_c  
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
  * @fn stackInit_schedulableStackInit(CosmOS_SchedulableVariableType  * schedulable)
  * 
  * @brief Schedulable stack initialization.
  * 
  * @param[in]  CosmOS_SchedulableVariableType  * schedulable
  * 
  * @return StackPointerType
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION StackPointerType stackInit_schedulableStackInit(CosmOS_SchedulableVariableType  * schedulable)
{
    AddressType stackLowAddress,
                stackHighAddress;

    CosmOS_HandlerType handler;
    StackPointerType stackPointer;

    CosmOS_StackConfigurationType * stack;


    stack = schedulable_getStack( schedulable );
    handler = schedulable_getHandler( schedulable );

    stackLowAddress = stack_getStackLowAddress( stack );
    stackHighAddress = stack_getStackHighAddress( stack );

    stackPointer = CIL_stack_stackInit( stackLowAddress, stackHighAddress, (BitWidthType)handler );

    return stackPointer;
}
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn stackInit_init(CosmOS_CoreVariableType * coreVar)
  * 
  * @brief Stack intialization for all thread schedulables.
  * 
  * @param[in] CosmOS_CoreVariableType * coreVar
  * 
  * @return none
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION void stackInit_init(CosmOS_CoreVariableType * coreVar)
{
    BitWidthType  numberOfThreads,
                  numberOfPrograms,
                  stackPointerRetVal;

    CosmOS_ThreadVariableType * threadVar;
    CosmOS_ProgramVariableType * programVar;

    numberOfPrograms = core_getCoreNumberOfPrograms( coreVar );

    for ( BitWidthType programIterator = 0; programIterator < numberOfPrograms; programIterator++ )
    {
        programVar = core_getCoreProgramVar( coreVar, programIterator );
        numberOfThreads = program_getProgramNumberOfThreads( programVar );

        for( BitWidthType threadIterator = 0; threadIterator < numberOfThreads; threadIterator++ )
        {   
            CosmOS_SchedulableVariableType * schedulableVar;


            threadVar = program_getProgramThread( programVar, threadIterator );
            schedulableVar = thread_getThreadSchedulable( threadVar );

            stackPointerRetVal = stackInit_schedulableStackInit( schedulableVar );
            schedulable_setStackPointer( schedulableVar, stackPointerRetVal );
        }
    }
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
