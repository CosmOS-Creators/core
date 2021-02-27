/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file core.h
*********************************************************************************
<!--                       core Module Group Definition                       -->
*********************************************************************************  
** @defgroup core_module core
** @brief core Module
** @details lorem   	 		
*********************************************************************************	
<!--                        core Unit Group Definition                        -->
********************************************************************************* 
** @defgroup core_unit Core Unit 
** @ingroup core_module        
** @brief core Unit 
** @details lorem                               
*********************************************************************************	
<!--                           Version Information                            -->
*********************************************************************************
** @version 1.0.0
** @date 1.8.2020
** @author https://github.com/PavolKostolansky   
*********************************************************************************	
<!--                          Warnings and License                            -->
*********************************************************************************
** @warning Modifying code can lead to unexpected behaviour of the whole system
** @copyright MIT License                                                                
*********************************************************************************
<!--                     core Unit Global Group Definition                    -->
*********************************************************************************
** @defgroup Global_core Global
** @ingroup core_unit 
** @brief core globals 
** @details lorem        
********************************************************************************/                                          
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __CORE_H__
#define __CORE_H__
/********************************************************************************
**                         START OF C++ SUPPORT SECTION                        **
********************************************************************************/
#ifdef __cplusplus
 extern "C" {
#endif
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "sysDefs.h"
#include "CosmOSTypesStd.h"
#include "memoryMapping.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_core_h Macros
  * @ingroup Global_core  
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Macros_core_h   
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
  * @defgroup Variables_core_h Variables 
  * @ingroup Global_core  
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Variables_core_h  
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
  * @defgroup Apis_core_h API's  
  * @ingroup Global_core
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_core_h Getters 
  * @ingroup Apis_core_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}       
  * Getters_core_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_core_h Setters  
  * @ingroup Apis_core_h                                            
  * @{                                                                           
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
__OS_FUNC_SECTION CosmOS_CoreVariableType * core_getCoreVar(void);

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn core_setTaskIntoCurrentContext(CosmOS_TaskVariableType * taskVar)
  * 
  * @brief Set core program into current context, set task into program current context.
  * 
  * @param[in]  CosmOS_TaskVariableType * taskVar
  * 
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void core_setTaskIntoCurrentContext(CosmOS_CoreVariableType * coreVar, CosmOS_TaskVariableType * taskVar);
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}    
  * Setters_core_h   
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_core_h General  
  * @ingroup Apis_core_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_core_h  
********************************************************************************/
/********************************************************************************
**                         Function Prototypes | Stop                          **
********************************************************************************/
/********************************************************************************
**                        Function Definitions | Start                         **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_core_h Getters 
  * @ingroup Apis_core_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn core_getCorePrograms(CosmOS_CoreVariableType * core) 
  * 
  * @brief Get core programs pointer.
  * 
  * @param[in]  CosmOS_CoreVariableType * core
  * 
  * @return CosmOS_ProgramConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_ProgramConfigurationType * core_getCorePrograms(CosmOS_CoreVariableType * core)
{
    return (CosmOS_ProgramConfigurationType *)(core->cfg->programs);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn core_getCoreNumberOfPrograms(CosmOS_CoreVariableType * core) 
  * 
  * @brief Get core numberOfPrograms.
  * 
  * @param[in]  CosmOS_CoreVariableType * core
  * 
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType core_getCoreNumberOfPrograms(CosmOS_CoreVariableType * core)
{
    return (core->cfg->numberOfPrograms);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn core_getCoreScheduler(CosmOS_CoreVariableType * core) 
  * 
  * @brief Get core scheduler pointer.
  * 
  * @param[in]  CosmOS_CoreVariableType * core
  * 
  * @return CosmOS_SchedulerConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_SchedulerConfigurationType * core_getCoreScheduler(CosmOS_CoreVariableType * core)
{
    return (CosmOS_SchedulerConfigurationType *)(core->cfg->scheduler);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn core_getCoreProgramInCurrentContext(CosmOS_CoreVariableType * core) 
  * 
  * @brief Get core programInCurrentContext pointer.
  * 
  * @param[in]  CosmOS_CoreVariableType * core
  * 
  * @return CosmOS_ProgramVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_ProgramVariableType * core_getCoreProgramInCurrentContext(CosmOS_CoreVariableType * core)
{
    return (core->programInCurrentContext);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn core_getCoreProgramVar(CosmOS_CoreVariableType * core, BitWidthType programIterator) 
  * 
  * @brief Get core programVars element pointer.
  * 
  * @param[in]  CosmOS_CoreVariableType * core
  * @param[in]  BitWidthType programIterator
  * 
  * @return CosmOS_ProgramVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_ProgramVariableType * core_getCoreProgramVar(CosmOS_CoreVariableType * core, BitWidthType programIterator)
{
    return (&(core->programVars[programIterator]));
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn core_getCoreSchedulerVar(CosmOS_CoreVariableType * core) 
  * 
  * @brief Get core scheduler pointer.
  * 
  * @param[in]  CosmOS_CoreVariableType * core
  * 
  * @return CosmOS_SchedulerVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_SchedulerVariableType * core_getCoreSchedulerVar(CosmOS_CoreVariableType * core)
{
    return (core->schedulerVar);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn core_getCoreBarrierVars(CosmOS_CoreVariableType * core) 
  * 
  * @brief Get core barrierVars pointer.
  * 
  * @param[in]  CosmOS_CoreVariableType * core
  * 
  * @return CosmOS_BarrierVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BarrierVariableType * core_getCoreBarrierVars(CosmOS_CoreVariableType * core)
{
    return (core->barrierVars);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn core_getBarrierVar(CosmOS_BarrierVariableType * barriers, BitWidthType * barrierId)
  * 
  * @brief Get barrierVars element pointer.
  * 
  * @param[in]  CosmOS_CoreVariableType * core
  * @param[in]  BitWidthType barrierId
  * 
  * @return CosmOS_BarrierVariableType * 
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BarrierVariableType * core_getBarrierVar(CosmOS_CoreVariableType * core, BitWidthType barrierId)
{
    return (&(core->barrierVars[barrierId]));
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn core_getCoreTaskInCurrentContext(CosmOS_CoreVariableType * core) 
  * 
  * @brief Get core programInCurrentContext taskInCurrentContext pointer.
  * 
  * @param[in]  CosmOS_CoreVariableType * core
  * 
  * @return CosmOS_TaskVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_TaskVariableType * core_getCoreTaskInCurrentContext(CosmOS_CoreVariableType * core)
{
    return (core->programInCurrentContext->taskInCurrentContext);
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}       
  * Getters_core_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_core_h Setters  
  * @ingroup Apis_core_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn core_setCoreProgramInCurrentContext(CosmOS_CoreVariableType * core, CosmOS_ProgramVariableType * programInCurrentContextParam) 
  * 
  * @brief Set core programInCurrentContext pointer.
  * 
  * @param[in]  CosmOS_CoreVariableType * core
  * @param[in]  CosmOS_ProgramVariableType * programInCurrentContextParam
  * 
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void core_setCoreProgramInCurrentContext(CosmOS_CoreVariableType * core, CosmOS_ProgramVariableType * programInCurrentContextParam)
{
    core->programInCurrentContext = programInCurrentContextParam;
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}    
  * Setters_core_h   
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_core_h General 
  * @ingroup Apis_core_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_core_h  
********************************************************************************/
/********************************************************************************
**                        Function Definitions | Stop                          **
********************************************************************************/
#ifdef __cplusplus
}
#endif
/********************************************************************************
**                         END OF C++ SUPPORT SECTION                          **
********************************************************************************/
#endif
/********************************************************************************
**                           END OF THE HEADER FILE                            **
********************************************************************************/
