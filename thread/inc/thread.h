/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file thread.h
*********************************************************************************
<!--                      thread Module Group Definition                      -->
*********************************************************************************  
** @defgroup thread_module thread
** @brief thread Module
** @details lorem   	 		
*********************************************************************************	
<!--                       thread Unit Group Definition                       -->
********************************************************************************* 
** @defgroup thread_unit thread Unit 
** @ingroup thread_module        
** @brief thread Unit 
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
<!--                    thread Unit Global Group Definition                   -->
*********************************************************************************
** @defgroup Global_thread Global
** @ingroup thread_unit 
** @brief thread globals
** @details lorem  
********************************************************************************/
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __THREAD_H__
#define __THREAD_H__
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
  * @defgroup Macros_thread_h Macros
  * @ingroup Global_thread  
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Macros_thread_h  
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
  * @defgroup Variables_thread_h Variables  
  * @ingroup Global_thread  
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Variables_thread_h  
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
  * @defgroup Apis_thread_h API's 
  * @ingroup Global_thread
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_thread_h Getters  
  * @ingroup Apis_thread_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}       
  * Getters_thread_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_thread_h Setters  
  * @ingroup Apis_thread_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}    
  * Setters_thread_h   
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_thread_h General  
  * @ingroup Apis_thread_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_thread_h  
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
  * @addtogroup Getters_thread_h Getters  
  * @ingroup Apis_thread_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn thread_getThreadStack(CosmOS_ThreadVariableType * thread) 
  * 
  * @brief Get thread stack pointer.
  * 
  * @param[in]  CosmOS_ThreadVariableType * thread
  * 
  * @return CosmOS_StackConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_StackConfigurationType * thread_getThreadStack(CosmOS_ThreadVariableType * thread)
{
    return (CosmOS_StackConfigurationType *)(thread->cfg->stack);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn thread_getThreadHandler(CosmOS_ThreadVariableType * thread) 
  * 
  * @brief Get thread handler.
  * 
  * @param[in]  CosmOS_ThreadVariableType * thread
  * 
  * @return CosmOS_HandlerType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_HandlerType thread_getThreadHandler(CosmOS_ThreadVariableType * thread)
{
    return (thread->cfg->handler);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn thread_getThreadId(CosmOS_ThreadVariableType * thread) 
  * 
  * @brief Get thread id.
  * 
  * @param[in]  CosmOS_ThreadVariableType * thread
  * 
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType thread_getThreadId(CosmOS_ThreadVariableType * thread)
{
    return (thread->cfg->id);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn thread_getThreadProgramId(CosmOS_ThreadVariableType * thread) 
  * 
  * @brief Get thread programId.
  * 
  * @param[in]  CosmOS_ThreadVariableType * thread
  * 
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType thread_getThreadProgramId(CosmOS_ThreadVariableType * thread)
{
    return (thread->cfg->programId);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn thread_getThreadCoreId(CosmOS_ThreadVariableType * thread) 
  * 
  * @brief Get thread coreId.
  * 
  * @param[in]  CosmOS_ThreadVariableType * thread
  * 
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType thread_getThreadCoreId(CosmOS_ThreadVariableType * thread)
{
    return (thread->cfg->coreId);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn thread_getThreadStackVar(CosmOS_ThreadVariableType * thread) 
  * 
  * @brief Get thread stackVar pointer.
  * 
  * @param[in]  CosmOS_ThreadVariableType * thread
  * 
  * @return CosmOS_StackVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_StackVariableType * thread_getThreadStackVar(CosmOS_ThreadVariableType * thread)
{
    return (thread->stackVar);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn thread_getThreadStackPointer(CosmOS_ThreadVariableType * thread) 
  * 
  * @brief Get thread stackPointer.
  * 
  * @param[in]  CosmOS_ThreadVariableType * thread
  * 
  * @return StackPointerType
********************************************************************************/
__STATIC_FORCEINLINE StackPointerType thread_getThreadStackPointer(CosmOS_ThreadVariableType * thread)
{
    return (thread->stackPointer);
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}       
  * Getters_thread_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_thread_h Setters  
  * @ingroup Apis_thread_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn thread_setThreadStackPointer(CosmOS_ThreadVariableType * thread, StackPointerType stackPointerParam) 
  * 
  * @brief Set thread stackPointer.
  * 
  * @param[in]  CosmOS_ThreadVariableType * thread
  * @param[in]  StackPointerType stackPointerParam
  * 
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void thread_setThreadStackPointer(CosmOS_ThreadVariableType * thread, StackPointerType stackPointerParam)
{
    thread->stackPointer = stackPointerParam;
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}    
  * Setters_thread_h   
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_thread_h General  
  * @ingroup Apis_thread_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_thread_h  
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