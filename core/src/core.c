/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file core.c
*********************************************************************************
<!--                     core Unit Local Group Definition                     -->
*********************************************************************************	
** @defgroup Local_core Local
** @ingroup core_unit 
** @brief core locals
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
#include "task.h"
#include "thread.h"
#include "program.h"
#include "core.h"
#include "CosmOSAssert.h"

/* TIL interfaces */
#include "TIL_core.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_core Macros
  * @ingroup Local_core
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Macros_core  
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
  * @defgroup Variables_core Variables  
  * @ingroup Local_core
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Variables_core  
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
  * @defgroup Apis_core_c API's  
  * @ingroup Local_core
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_core_c Getters  
  * @ingroup Apis_core_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}       
  * Getters_core_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_core_c Setters  
  * @ingroup Apis_core_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}    
  * Setters_core_c   
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_core_c General  
  * @ingroup Apis_core_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_core_c  
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
  * @fn core_getCoreVar()
  * 
  * @brief Get current core variable.
  * 
  * @param[in]  none
  * 
  * @return CosmOS_CoreVariableType *
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION CosmOS_CoreVariableType * core_getCoreVar(void)
{
    return TIL_core_getCoreVar();
}
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn core_setTaskIntoCurrentContext(CosmOS_CoreVariableType * coreVar, CosmOS_TaskVariableType * taskVar)
  * 
  * @brief Set core program into current context, set task into program current context.
  * 
  * @param[in]  CosmOS_CoreVariableType * coreVar
  * @param[in]  CosmOS_TaskVariableType * taskVar
  * 
  * @return none
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION void core_setTaskIntoCurrentContext(CosmOS_CoreVariableType * coreVar, CosmOS_TaskVariableType * taskVar)
{
    BitWidthType programId;

    CosmOS_ProgramVariableType * programVar;

    programId = task_getTaskProgramId( taskVar );
    programVar = core_getCoreProgramVar( coreVar, programId ); 

    program_setProgramTaskInCurrentContext( programVar, taskVar );
    program_setProgramRunningInstance( programVar, RUNNING_INSTANCE_ENUM__TASK );

    core_setCoreProgramInCurrentContext( coreVar, programVar );
}
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn core_setThreadIntoCurrentContext(CosmOS_CoreVariableType * coreVar, CosmOS_ThreadVariableType * threadVar)
  * 
  * @brief Set core program into current context, set task into program current context.
  * 
  * @param[in]  CosmOS_CoreVariableType * coreVar
  * @param[in]  CosmOS_ThreadVariableType * threadVar
  * 
  * @return none
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION void core_setThreadIntoCurrentContext(CosmOS_CoreVariableType * coreVar, CosmOS_ThreadVariableType * threadVar)
{
    BitWidthType programId;

    CosmOS_ProgramVariableType * programVar;

    programId = thread_getThreadProgramId( threadVar );
    programVar = core_getCoreProgramVar( coreVar, programId ); 

    program_setProgramThreadInCurrentContext( programVar, threadVar );
    program_setProgramRunningInstance( programVar, RUNNING_INSTANCE_ENUM__THREAD );

    core_setCoreProgramInCurrentContext( coreVar, programVar );
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
