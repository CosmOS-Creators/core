/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file scheduler.h
*********************************************************************************
<!--                     scheduler Module Group Definition                    -->
*********************************************************************************  
** @defgroup scheduler_module scheduler
** @brief scheduler Module
** @details lorem   	 		
*********************************************************************************	
<!--                      scheduler Unit Group Definition                     -->
********************************************************************************* 
** @defgroup scheduler_unit scheduler Unit 
** @ingroup scheduler_module        
** @brief scheduler Unit 
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
<!--                   scheduler Unit Global Group Definition                 -->
*********************************************************************************
** @defgroup Global_scheduler Global
** @ingroup scheduler_unit 
** @brief scheduler globals
** @details lorem  
********************************************************************************/
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __SCHEDULER_H__
#define __SCHEDULER_H__
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
#include "CosmOSTypesStd.h"
#include "sysDefs.h"
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
  * @defgroup Macros_scheduler_h Macros
  * @ingroup Global_scheduler  
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Macros_scheduler_h  
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
  * @defgroup Variables_scheduler_h Variables  
  * @ingroup Global_scheduler  
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Variables_scheduler_h  
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
  * @defgroup Apis_scheduler_h API's 
  * @ingroup Global_scheduler
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_scheduler_h Getters  
  * @ingroup Apis_scheduler_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}       
  * Getters_scheduler_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_scheduler_h Setters  
  * @ingroup Apis_scheduler_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}    
  * Setters_scheduler_h   
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_scheduler_h General  
  * @ingroup Apis_scheduler_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_scheduleNextInstance(void) 
  * 
  * @brief Algorithm for scheduling next task/thread DEMO CODE.
  * 
  * @param[in]  BitWidthType stackPointer
  * 
  * @return BitWidthType
********************************************************************************/
__OS_FUNC_SECTION BitWidthType scheduler_scheduleNextInstance(BitWidthType stackPointer);

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_start(void) 
  * 
  * @brief Start of scheduler, pick the starting task/thread and execute it DEMO CODE.
  * 
  * @param[in]  none
  * 
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void scheduler_start(void);
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_scheduler_h  
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
  * @addtogroup Getters_scheduler_h Getters  
  * @ingroup Apis_scheduler_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_getSchedulerScheduleTable(CosmOS_SchedulerVariableType * scheduler) 
  * 
  * @brief Get scheduler scheduleTable pointer.
  * 
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  * 
  * @return CosmOS_ScheduleTableConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_ScheduleTableConfigurationType * scheduler_getSchedulerScheduleTable(CosmOS_SchedulerVariableType * scheduler)
{
    return (CosmOS_ScheduleTableConfigurationType *)(scheduler->cfg->scheduleTable);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_getSchedulerHyperTick(CosmOS_SchedulerVariableType * scheduler) 
  * 
  * @brief Get scheduler hyperTick.
  * 
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  * 
  * @return BitWidthType 
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType scheduler_getSchedulerHyperTick(CosmOS_SchedulerVariableType * scheduler)
{
    return (scheduler->cfg->hyperTick);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_getSchedulerPreemptTick(CosmOS_SchedulerVariableType * scheduler) 
  * 
  * @brief Get scheduler preemptTick.
  * 
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  * 
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType scheduler_getSchedulerPreemptTick(CosmOS_SchedulerVariableType * scheduler)
{
    return (scheduler->cfg->preemptTick);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_getSchedulerScheduleTableElementsNum(CosmOS_SchedulerVariableType * scheduler) 
  * 
  * @brief Get scheduler scheduleTableElementsNum.
  * 
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  * 
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType scheduler_getSchedulerScheduleTableElementsNum(CosmOS_SchedulerVariableType * scheduler)
{
    return (scheduler->cfg->scheduleTableElementsNum);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_getSchedulerThreadListElementsNum(CosmOS_SchedulerVariableType * scheduler) 
  * 
  * @brief Get scheduler threadListElementsNum.
  * 
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  * 
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType scheduler_getSchedulerThreadListElementsNum(CosmOS_SchedulerVariableType * scheduler)
{
    return (scheduler->cfg->threadListElementsNum);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_getSchedulerCurrentTick(CosmOS_SchedulerVariableType * scheduler) 
  * 
  * @brief Get scheduler currentTick.
  * 
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  * 
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType scheduler_getSchedulerCurrentTick(CosmOS_SchedulerVariableType * scheduler)
{
    return (scheduler->currentTick);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_getSchedulerScheduleTableIterator(CosmOS_SchedulerVariableType * scheduler) 
  * 
  * @brief Get scheduler scheduleTableIterator.
  * 
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  * 
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType scheduler_getSchedulerScheduleTableIterator(CosmOS_SchedulerVariableType * scheduler)
{
    return (scheduler->scheduleTableIterator);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_getSchedulerScheduleTableVar(CosmOS_SchedulerVariableType * scheduler) 
  * 
  * @brief Get scheduler scheduleTable pointer.
  * 
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  * 
  * @return CosmOS_ScheduleTableVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_ScheduleTableVariableType * scheduler_getSchedulerScheduleTableVar(CosmOS_SchedulerVariableType * scheduler)
{
    return (scheduler->scheduleTableVar);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_getSchedulerScheduleTableTaskVar(CosmOS_SchedulerVariableType * scheduler, BitWidthType scheduleTableIterator) 
  * 
  * @brief Get scheduler scheduleTable element task pointer.
  * 
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  * @param[in]  BitWidthType scheduleTableIterator
  * 
  * @return CosmOS_TaskVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_TaskVariableType * scheduler_getSchedulerScheduleTableTaskVar(CosmOS_SchedulerVariableType * scheduler, BitWidthType scheduleTableIterator)
{
    return (scheduler->scheduleTableVar[scheduleTableIterator].task);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_getSchedulerScheduleTableStartTick(CosmOS_SchedulerVariableType * scheduler, BitWidthType scheduleTableIterator) 
  * 
  * @brief Get scheduler scheduleTable element startTick.
  * 
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  * @param[in]  BitWidthType scheduleTableIterator
  * 
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType scheduler_getSchedulerScheduleTableStartTick(CosmOS_SchedulerVariableType * scheduler, BitWidthType scheduleTableIterator)
{
    return (scheduler->cfg->scheduleTable[scheduleTableIterator].startTick);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_getSchedulerThreadList(CosmOS_SchedulerVariableType * scheduler) 
  * 
  * @brief Get scheduler threadList pointer.
  * 
  * @param[in] CosmOS_SchedulerVariableType * scheduler
  * 
  * @return CosmOS_SchedulerThreadListVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_SchedulerThreadListVariableType * scheduler_getSchedulerThreadList(CosmOS_SchedulerVariableType * scheduler)
{
    return (scheduler->threadListVar);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_getSchedulerScheduleTableStartTime(CosmOS_SchedulerVariableType * scheduler, BitWidthType threadListIterator) 
  * 
  * @brief Get scheduler threadList element thread pointer.
  * 
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  * @param[in]  BitWidthType threadListIterator
  * 
  * @return CosmOS_ThreadVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_ThreadVariableType * scheduler_getSchedulerThreadListThreadVar(CosmOS_SchedulerVariableType * scheduler, BitWidthType threadListIterator)
{
    return (scheduler->threadListVar[threadListIterator].thread);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_getSchedulerThreadListIterator(CosmOS_SchedulerVariableType * scheduler) 
  * 
  * @brief Get scheduler threadListIterator.
  * 
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  * 
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType scheduler_getSchedulerThreadListIterator(CosmOS_SchedulerVariableType * scheduler)
{
    return (scheduler->threadListIterator);
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}       
  * Getters_scheduler_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_scheduler_h Setters  
  * @ingroup Apis_scheduler_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_setSchedulerCurrentTick(CosmOS_SchedulerVariableType * scheduler, BitWidthType currentTickParam) 
  * 
  * @brief Set scheduler currentTick.
  * 
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  * @param[in]  BitWidthType currentTickParam
  * 
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void scheduler_setSchedulerCurrentTick(CosmOS_SchedulerVariableType * scheduler, BitWidthType currentTickParam)
{
    scheduler->currentTick = currentTickParam;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_setSchedulerScheduleTableIterator(CosmOS_SchedulerVariableType * scheduler, BitWidthType currentTimeParam) 
  * 
  * @brief Set scheduler scheduleTableIterator.
  * 
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  * @param[in]  BitWidthType scheduleTableIteratorParam
  * 
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void scheduler_setSchedulerScheduleTableIterator(CosmOS_SchedulerVariableType * scheduler, BitWidthType scheduleTableIteratorParam)
{
    scheduler->scheduleTableIterator = scheduleTableIteratorParam;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn scheduler_setSchedulerThreadListIterator(CosmOS_SchedulerVariableType * scheduler, BitWidthType threadListIteratorParam) 
  * 
  * @brief Set scheduler threadListIterator.
  * 
  * @param[in]  CosmOS_SchedulerVariableType * scheduler
  * @param[in]  BitWidthType threadListIteratorParam
  * 
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void scheduler_setSchedulerThreadListIterator(CosmOS_SchedulerVariableType * scheduler, BitWidthType threadListIteratorParam)
{
    scheduler->threadListIterator = threadListIteratorParam;
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}    
  * Setters_scheduler_h   
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_scheduler_h General  
  * @ingroup Apis_scheduler_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_scheduler_h  
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