/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file os.h
*********************************************************************************
<!--                        os Module Group Definition                        -->
*********************************************************************************
** @defgroup os_module os
** @brief os Module
** @details lorem
*********************************************************************************
<!--                         os Unit Group Definition                         -->
*********************************************************************************
** @defgroup os_unit os Unit
** @ingroup os_module
** @brief os Unit
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
<!--                      os Unit Global Group Definition                     -->
*********************************************************************************
** @defgroup Global_os Global
** @ingroup os_unit
** @brief os globals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __OS_H__
#define __OS_H__
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
#include "cosmosTypes.h"
#include "memoryMapping.h"
#include "sysDefs.h"

/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_os_h Macros
  * @ingroup Global_os
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_os_h
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
  * @defgroup Variables_os_h Variables
  * @ingroup Global_os
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_os_h
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
  * @defgroup Apis_os_h API's
  * @ingroup Global_os
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_os_h Getters
  * @ingroup Apis_os_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn os_getOsCfg(void)
  *
  * @brief Get operating system configuration type. This function can be
  * called from the unprivileged context directly.
  *
  * @param[in]  none
  *
  * @return CosmOS_OsConfigurationType *
********************************************************************************/
__OS_FUNC_SECTION CosmOS_OsConfigurationType *
os_getOsCfg( void );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn os_kernelPanicInternal( BitWidthType id )
  *
  * @brief OS kernel panic function. This is operating system internal funtion
  * only and cannot be called from the unprivileged context directly. DEMO
  *
  * @param[in]  BitWidthType id
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void
os_kernelPanicInternal( BitWidthType id );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn os_kernelPanic(void)
  *
  * @brief OS kernel panic function. DEMO
  *
  * @param[in]  none
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void
os_kernelPanic( void );
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_os_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_os_h Setters
  * @ingroup Apis_os_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_os_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_os_h General
  * @ingroup Apis_os_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn os_start(BitWidthType entityId)
  *
  * @brief Start of the operating system. This function is provided as a CosmOS
  * API system call mapped with the routes and cannot be called from the
  * unprivileged context directly. DEMO
  *
  * @param[in]  entityId is used during the system call dispatching
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void
os_start( BitWidthType entityId );
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_os_h
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
  * @addtogroup Getters_os_h Getters
  * @ingroup Apis_os_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn os_getOsCores(CosmOS_OsConfigurationType * os)
  *
  * @brief Get os cores pointer.
  *
  * @param[in]  os configuration pointer
  *
  * @return CosmOS_CoreConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_CoreConfigurationType *
os_getOsCores( CosmOS_OsConfigurationType * os )
{
    return (CosmOS_CoreConfigurationType *)( os->cores );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn os_getCore(CosmOS_OsConfigurationType * os, BitWidthType coreId)
  *
  * @brief Get os core pointer.
  *
  * @param[in]  os configuration pointer
  * @param[in]  coreId specifies the core from array of configured cores
  *
  * @return CosmOS_CoreConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_CoreConfigurationType *
os_getCore( CosmOS_OsConfigurationType * os, BitWidthType coreId )
{
    return (CosmOS_CoreConfigurationType *)( &( os->cores[coreId] ) );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn os_getOsNumberOfCores(CosmOS_OsConfigurationType * os)
  *
  * @brief Get os numberOfCores.
  *
  * @param[in]  os configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
os_getOsNumberOfCores( CosmOS_OsConfigurationType * os )
{
    return ( os->numberOfCores );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn os_getOsBuffers(CosmOS_OsConfigurationType * os)
  *
  * @brief Get os buffers pointer.
  *
  * @param[in]  os configuration pointer
  *
  * @return CosmOS_BufferConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BufferConfigurationType *
os_getOsBuffers( CosmOS_OsConfigurationType * os )
{
    return (CosmOS_BufferConfigurationType *)( os->buffers );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn os_getOsNumberOfBuffers(CosmOS_OsConfigurationType * os)
  *
  * @brief Get os numberOfBuffers.
  *
  * @param[in]  os configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
os_getOsNumberOfBuffers( CosmOS_OsConfigurationType * os )
{
    return ( os->numberOfBuffers );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn os_getOsRoutes(CosmOS_OsConfigurationType * os)
  *
  * @brief Get os route pointer.
  *
  * @param[in]  os configuration pointer
  *
  * @return CosmOS_RoutesConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_RoutesConfigurationType *
os_getOsRoutes( CosmOS_OsConfigurationType * os )
{
    return (CosmOS_RoutesConfigurationType *)( os->route );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn os_getOsNumberOfSpinlocks(CosmOS_OsConfigurationType * os)
  *
  * @brief Get os numberOfSpinlocks.
  *
  * @param[in]  os configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
os_getOsNumberOfSpinlocks( CosmOS_OsConfigurationType * os )
{
    return ( os->numberOfSpinlocks );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn os_getOsBufferCfgs(CosmOS_OsConfigurationType * os)
  *
  * @brief Get os bufferCfgs pointer.
  *
  * @param[in]  os configuration pointer
  *
  * @return CosmOS_BufferConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BufferConfigurationType *
os_getOsBufferCfgs( CosmOS_OsConfigurationType * os )
{
    return (CosmOS_BufferConfigurationType *)( os->bufferCfgs );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn os_getOsBufferCfg(CosmOS_OsConfigurationType * os,BitWidthType bufferId)
  *
  * @brief Get os buffer pointer.
  *
  * @param[in]  os configuration pointer
  * @param[in]  bufferId specifies the buffer from array of configured buffers
  *
  * @return CosmOS_BufferConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BufferConfigurationType *
os_getOsBufferCfg( CosmOS_OsConfigurationType * os, BitWidthType bufferId )
{
    return (CosmOS_BufferConfigurationType *)( &( os->bufferCfgs[bufferId] ) );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn os_getOsbufferDoubleCfgs(CosmOS_OsConfigurationType * os)
  *
  * @brief Get os bufferDoubleCfgs pointer.
  *
  * @param[in]  os configuration pointer
  *
  * @return CosmOS_BufferDoubleConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BufferDoubleConfigurationType *
os_getOsbufferDoubleCfgs( CosmOS_OsConfigurationType * os )
{
    return (CosmOS_BufferDoubleConfigurationType *)( os->bufferDoubleCfgs );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn os_getOsBufferDoubleCfg(CosmOS_OsConfigurationType * os,
  * BitWidthType bufferDoubleId)
  *
  * @brief Get os bufferDouble pointer.
  *
  * @param[in]  os configuration pointer
  * @param[in]  bufferDoubleId specifies the bufferDouble from array of
  * configured buffersDouble
  *
  * @return CosmOS_BufferDoubleConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BufferDoubleConfigurationType *
os_getOsBufferDoubleCfg(
    CosmOS_OsConfigurationType * os,
    BitWidthType bufferDoubleId )
{
    return (CosmOS_BufferDoubleConfigurationType *)( &(
        os->bufferDoubleCfgs[bufferDoubleId] ) );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn os_getOsSpinlockVars(CosmOS_OsConfigurationType * os)
  *
  * @brief Get os spinlockVars pointer.
  *
  * @param[in]  os configuration pointer
  *
  * @return CosmOS_SpinlockVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_SpinlockVariableType *
os_getOsSpinlockVars( CosmOS_OsConfigurationType * os )
{
    return ( os->spinlockVars );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn os_getOsSpinlockVar(CosmOS_OsConfigurationType * os,
  * BitWidthType spinlockId)
  *
  * @brief Get os spinlock pointer.
  *
  * @param[in]  os configuration pointer
  * @param[in]  spinlockId specifies the spinlock from array of configured
  * spinlocks
  *
  * @return CosmOS_SpinlockVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_SpinlockVariableType *
os_getOsSpinlockVar( CosmOS_OsConfigurationType * os, BitWidthType spinlockId )
{
    return ( &( os->spinlockVars[spinlockId] ) );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn os_getOsEventCfg(CosmOS_OsConfigurationType * os)
  *
  * @brief Get os osEventCfg pointer.
  *
  * @param[in]  os configuration pointer
  *
  * @return CosmOS_OsEventConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_OsEventConfigurationType *
os_getOsEventCfg( CosmOS_OsConfigurationType * os )
{
    return (CosmOS_OsEventConfigurationType *)( os->osEventCfg );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn os_getOsChannelsCfg(CosmOS_OsConfigurationType * os)
  *
  * @brief Get channels pointer.
  *
  * @param[in]  os configuration pointer
  *
  * @return CosmOS_ChannelConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_ChannelConfigurationType *
os_getOsChannelsCfg( CosmOS_OsConfigurationType * os )
{
    return (CosmOS_ChannelConfigurationType *)( os->channels );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn os_getOsChannelCfg( CosmOS_OsConfigurationType * os,
  * BitWidthType channelId )
  *
  * @brief Get channel pointer.
  *
  * @param[in]  os configuration pointer
  * @param[in]  channelId specifies the channel from array of configured
  * channels
  *
  * @return CosmOS_ChannelConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_ChannelConfigurationType *
os_getOsChannelCfg( CosmOS_OsConfigurationType * os, BitWidthType channelId )
{
    return (CosmOS_ChannelConfigurationType *)( &( os->channels[channelId] ) );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn os_getOsNumberOfChannels(CosmOS_OsConfigurationType * os)
  *
  * @brief Get numberOfChannels.
  *
  * @param[in]  os configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
os_getOsNumberOfChannels( CosmOS_OsConfigurationType * os )
{
    return ( BitWidthType )( os->numberOfChannels );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn os_getOsSemaphoreVars(CosmOS_OsConfigurationType * os)
  *
  * @brief Get os semaphoreVars pointer.
  *
  * @param[in]  os configuration pointer
  *
  * @return CosmOS_SemaphoreVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_SemaphoreVariableType *
os_getOsSemaphoreVars( CosmOS_OsConfigurationType * os )
{
    return ( os->semaphoreVars );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn os_getOsSemaphoreVar(CosmOS_OsConfigurationType * os,
  * BitWidthType semaphoreId)
  *
  * @brief Get os semaphore pointer.
  *
  * @param[in]  os configuration pointer
  * @param[in]  semaphoreId specifies the semaphore from array of configured
  * semaphores
  *
  * @return CosmOS_SemaphoreVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_SemaphoreVariableType *
os_getOsSemaphoreVar( CosmOS_OsConfigurationType * os, BitWidthType semaphoreId )
{
    return ( &( os->semaphoreVars[semaphoreId] ) );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn os_getOsNumberOfSemaphores(CosmOS_OsConfigurationType * os)
  *
  * @brief Get os numberOfSemaphores.
  *
  * @param[in]  os configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
os_getOsNumberOfSemaphores( CosmOS_OsConfigurationType * os )
{
    return ( os->numberOfSemaphores );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn os_getOsInterruptCfgs(CosmOS_OsConfigurationType * os)
  *
  * @brief Get os interrupts pointer.
  *
  * @param[in]  os configuration pointer
  *
  * @return CosmOS_InterruptConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_InterruptConfigurationType *
os_getOsInterruptCfgs( CosmOS_OsConfigurationType * os )
{
    return (CosmOS_InterruptConfigurationType *)( os->interrupts );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn os_getOsInterruptCfg(CosmOS_OsConfigurationType * os,
  * BitWidthType interruptId)
  *
  * @brief Get os semaphore pointer.
  *
  * @param[in]  os configuration pointer
  * @param[in]  interruptId specifies the semaphore from array of configured
  * semaphores
  *
  * @return CosmOS_InterruptConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_InterruptConfigurationType *
os_getOsInterruptCfg( CosmOS_OsConfigurationType * os, BitWidthType interruptId )
{
    return (
        CosmOS_InterruptConfigurationType *)( &( os->interrupts[interruptId] ) );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn os_getOsNumberOfInterrupts(CosmOS_OsConfigurationType * os)
  *
  * @brief Get os numberOfInterrupts.
  *
  * @param[in]  os configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
os_getOsNumberOfInterrupts( CosmOS_OsConfigurationType * os )
{
    return ( os->numberOfInterrupts );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn os_getOsDummy(CosmOS_OsConfigurationType * os)
  *
  * @brief Get os dummy.
  *
  * @param[in]  os configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
os_getOsDummy( CosmOS_OsConfigurationType * os )
{
    return ( os->var->dummy );
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_os_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_os_h Setters
  * @ingroup Apis_os_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn os_setOsDummy( CosmOS_OsConfigurationType * os,
  * BitWidthType dummyParam )
  *
  * @brief Set os dummy.
  *
  * @param[in]  os configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE void
os_setOsDummy( CosmOS_OsConfigurationType * os, BitWidthType dummyParam )
{
    os->var->dummy = dummyParam;
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_os_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_os_h General
  * @ingroup Apis_os_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_os_h
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
