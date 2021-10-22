/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file bufferDouble.h
*********************************************************************************
<!--                   bufferDouble Module Group Definition                   -->
*********************************************************************************
** @defgroup bufferDouble_module bufferDouble
** @brief bufferDouble Module
** @details lorem
*********************************************************************************
<!--                    bufferDouble Unit Group Definition                    -->
*********************************************************************************
** @defgroup bufferDouble_unit bufferDouble Unit
** @ingroup bufferDouble_module
** @brief bufferDouble Unit
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
<!--                bufferDouble Unit Global Group Definition                 -->
*********************************************************************************
** @defgroup Global_bufferDouble Global
** @ingroup bufferDouble_unit
** @brief bufferDouble globals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __BUFFERDOUBLE_H__
#define __BUFFERDOUBLE_H__
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
  * @defgroup Macros_bufferDouble_h Macros
  * @ingroup Global_bufferDouble
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Macros_bufferDouble_h
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
  * @defgroup Variables_bufferDouble_h Variables
  * @ingroup Global_bufferDouble
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Variables_bufferDouble_h
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
  * @defgroup Apis_bufferDouble_h API's
  * @ingroup Global_bufferDouble
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_bufferDouble_h Getters
  * @ingroup Apis_bufferDouble_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Getters_bufferDouble_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_bufferDouble_h Setters
  * @ingroup Apis_bufferDouble_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Setters_bufferDouble_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_bufferDouble_h General
  * @ingroup Apis_bufferDouble_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn bufferDouble_readArray(BitWidthType id, void * buffer,
  * BitWidthType size,
  * CosmOS_BufferDoubleAccessType access)
  *
  * @brief Reading array from the bufferDouble DEMO CODE.
  *
  * @param[in]  BitWidthType id
  * @param[in]  void * buffer
  * @param[in]  BitWidthType size
  * @param[in]  CosmOS_BufferDoubleAccessType access
  *
  * @return CosmOS_BufferStateType
********************************************************************************/
__OS_FUNC_SECTION CosmOS_BufferStateType
bufferDouble_readArray(
    BitWidthType id,
    void * buffer,
    BitWidthType size,
    CosmOS_BufferDoubleAccessType access );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn bufferDouble_writeArray(BitWidthType id, void * buffer,
  * BitWidthType size,
  * CosmOS_BufferDoubleAccessType access)
  *
  * @brief Writing array into the bufferDouble DEMO CODE.
  *
  * @param[in]  BitWidthType id
  * @param[in]  void * buffer
  * @param[in]  BitWidthType size
  * @param[in]  CosmOS_BufferDoubleAccessType access
  *
  * @return CosmOS_BufferStateType
********************************************************************************/
__OS_FUNC_SECTION CosmOS_BufferStateType
bufferDouble_writeArray(
    BitWidthType id,
    void * buffer,
    BitWidthType size,
    CosmOS_BufferDoubleAccessType access );
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_bufferDouble_h
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
  * @addtogroup Getters_bufferDouble_h Getters
  * @ingroup Apis_bufferDouble_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn bufferDouble_getBufferDoublePair(
  * CosmOS_BufferDoubleVariableType * bufferDoubleVar)
  *
  * @brief Get bufferDouble pair.
  *
  * @param[in]  CosmOS_BufferDoubleVariableType * bufferDoubleVar
  *
  * @return CosmOS_BufferDoublePairConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BufferDoublePairConfigurationType *
bufferDouble_getBufferDoublePair(
    CosmOS_BufferDoubleVariableType * bufferDoubleVar )
{
    return (CosmOS_BufferDoublePairConfigurationType *)( bufferDoubleVar->cfg
                                                             ->bufferPair );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn bufferDouble_getBufferDoubleKernelBufferId(
  * CosmOS_BufferDoubleVariableType * bufferDoubleVar)
  *
  * @brief Get bufferDouble kernelBufferId.
  *
  * @param[in]  CosmOS_BufferDoubleVariableType * bufferDoubleVar
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
bufferDouble_getBufferDoubleKernelBufferId(
    CosmOS_BufferDoubleVariableType * bufferDoubleVar )
{
    return ( bufferDoubleVar->activeKernelBufferId );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn bufferDouble_getBufferDoubleUserBufferId(
  * CosmOS_BufferDoubleVariableType * bufferDoubleVar)
  *
  * @brief Get bufferDouble userBufferId.
  *
  * @param[in]  CosmOS_BufferDoubleVariableType * bufferDoubleVar
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
bufferDouble_getBufferDoubleUserBufferId(
    CosmOS_BufferDoubleVariableType * bufferDoubleVar )
{
    return ( bufferDoubleVar->activeUserBufferId );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn bufferDouble_getBufferDoubleKernelBuffer(
  * CosmOS_BufferDoubleVariableType * bufferDoubleVar)
  *
  * @brief Get bufferDouble kernelBuffer.
  *
  * @param[in]  CosmOS_BufferDoubleVariableType * bufferDoubleVar
  *
  * @return CosmOS_BufferVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BufferVariableType *
bufferDouble_getBufferDoubleKernelBuffer(
    CosmOS_BufferDoubleVariableType * bufferDoubleVar )
{
    return (CosmOS_BufferVariableType *)( &(
        bufferDoubleVar->cfg
            ->bufferPair[bufferDoubleVar->activeKernelBufferId] ) );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn bufferDouble_getBufferDoubleUserBuffer(
  * CosmOS_BufferDoubleVariableType * bufferDoubleVar)
  *
  * @brief Get bufferDouble userBuffer.
  *
  * @param[in]  CosmOS_BufferDoubleVariableType * bufferDoubleVar
  *
  * @return CosmOS_BufferVariableType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BufferVariableType *
bufferDouble_getBufferDoubleUserBuffer(
    CosmOS_BufferDoubleVariableType * bufferDoubleVar )
{
    return (CosmOS_BufferVariableType *)( &(
        bufferDoubleVar->cfg
            ->bufferPair[bufferDoubleVar->activeUserBufferId] ) );
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Getters_bufferDouble_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_bufferDouble_h Setters
  * @ingroup Apis_bufferDouble_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn bufferDouble_setBufferDoubleKernelBuffer(
  * CosmOS_BufferDoubleVariableType * bufferDoubleVar,
  * BitWidthType activeKernelBufferIdParam)
  *
  * @brief Set bufferDouble activeKernelBufferId.
  *
  * @param[in]  CosmOS_BufferDoubleVariableType * bufferDoubleVar
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
bufferDouble_setBufferDoubleKernelBuffer(
    CosmOS_BufferDoubleVariableType * bufferDoubleVar,
    BitWidthType activeKernelBufferIdParam )
{
    bufferDoubleVar->activeKernelBufferId = activeKernelBufferIdParam;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn bufferDouble_setBufferDoubleUserBuffer(
  * CosmOS_BufferDoubleVariableType * bufferDoubleVar,
  * BitWidthType activeUserBufferIdParam)
  *
  * @brief Set bufferDouble activeUserBufferId.
  *
  * @param[in]  CosmOS_BufferDoubleVariableType * bufferDoubleVar
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
bufferDouble_setBufferDoubleUserBuffer(
    CosmOS_BufferDoubleVariableType * bufferDoubleVar,
    BitWidthType activeUserBufferIdParam )
{
    bufferDoubleVar->activeUserBufferId = activeUserBufferIdParam;
}

/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Setters_bufferDouble_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_bufferDouble_h General
  * @ingroup Apis_bufferDouble_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn bufferDouble_isUserAndKernelBufferSame(
  * CosmOS_BufferDoubleVariableType * bufferDoubleVar)
  *
  * @brief Does user and kernel use the same buffer.
  *
  * @param[in]  CosmOS_BufferDoubleVariableType * bufferDoubleVar
  *
  * @return CosmOS_BooleanType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BooleanType
bufferDouble_isUserAndKernelBufferSame(
    CosmOS_BufferDoubleVariableType * bufferDoubleVar )
{
    return (
        bufferDoubleVar->activeKernelBufferId IS_EQUAL_TO
                bufferDoubleVar->activeUserBufferId
            ? True
            : False );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn bufferDouble_switchUserAndKernelBuffer(
  * CosmOS_BufferDoubleVariableType * bufferDoubleVar)
  *
  * @brief Does user and kernel use the same buffer.
  *
  * @param[in]  CosmOS_BufferDoubleVariableType * bufferDoubleVar
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
bufferDouble_switchUserAndKernelBuffer(
    CosmOS_BufferDoubleVariableType * bufferDoubleVar )
{
    BitWidthType kernelTempId;

    kernelTempId = bufferDoubleVar->activeKernelBufferId;
    bufferDoubleVar->activeKernelBufferId = bufferDoubleVar->activeUserBufferId;
    bufferDoubleVar->activeUserBufferId = kernelTempId;
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_bufferDouble_h
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
