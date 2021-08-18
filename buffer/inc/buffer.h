/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file buffer.h
*********************************************************************************
<!--                      buffer Module Group Definition                      -->
*********************************************************************************
** @defgroup buffer_module buffer
** @brief buffer Module
** @details lorem
*********************************************************************************
<!--                       buffer Unit Group Definition                       -->
*********************************************************************************
** @defgroup buffer_unit buffer Unit
** @ingroup buffer_module
** @brief buffer Unit
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
<!--                    buffer Unit Global Group Definition                   -->
*********************************************************************************
** @defgroup Global_buffer Global
** @ingroup buffer_unit
** @brief buffer globals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __BUFFER_H__
#define __BUFFER_H__
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
#include "cosmosTypesStd.h"
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
  * @defgroup Macros_buffer_h Macros
  * @ingroup Global_buffer
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Macros_buffer_h
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
  * @defgroup Variables_buffer_h Variables
  * @ingroup Global_buffer
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Variables_buffer_h
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
  * @defgroup Apis_buffer_h API's
  * @ingroup Global_buffer
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_buffer_h Getters
  * @ingroup Apis_buffer_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Getters_buffer_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_buffer_h Setters
  * @ingroup Apis_buffer_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Setters_buffer_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_buffer_h General
  * @ingroup Apis_buffer_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn buffer_readArray(BitWidthType id, void * buffer, BitWidthType num)
  *
  * @brief Reading array from the buffer DEMO CODE.
  *
  * @param[in]  BitWidthType id
  * @param[in]  void * buffer
  * @param[in]  BitWidthType size
  *
  * @return CosmOS_BufferStateType
********************************************************************************/
__OS_FUNC_SECTION CosmOS_BufferStateType buffer_readArray(BitWidthType id, void * buffer, BitWidthType size);

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn buffer_writeArray(BitWidthType id, void * buffer, BitWidthType num)
  *
  * @brief Writing array into the buffer DEMO CODE.
  *
  * @param[in]  BitWidthType id
  * @param[in]  void * buffer
  * @param[in]  BitWidthType size
  *
  * @return CosmOS_BufferStateType
********************************************************************************/
__OS_FUNC_SECTION CosmOS_BufferStateType buffer_writeArray(BitWidthType id, void * buffer, BitWidthType size);
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_buffer_h
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
  * @addtogroup Getters_buffer_h Getters
  * @ingroup Apis_buffer_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn buffer_getBuffer(CosmOS_BufferVariableType * bufferVar)
  *
  * @brief Get buffer pointer.
  *
  * @param[in]  CosmOS_BufferVariableType * bufferVar
  *
  * @return unsigned char *
********************************************************************************/
__STATIC_FORCEINLINE unsigned char * buffer_getBuffer(CosmOS_BufferVariableType * bufferVar)
{
    return (unsigned char *)(bufferVar->cfg->buffer);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn buffer_getBufferId(CosmOS_BufferVariableType * bufferVar)
  *
  * @brief Get buffer id.
  *
  * @param[in]  CosmOS_BufferVariableType * bufferVar
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType buffer_getBufferId(CosmOS_BufferVariableType * bufferVar)
{
    return (bufferVar->cfg->id);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn buffer_getBufferSize(CosmOS_BufferVariableType * bufferVar)
  *
  * @brief Get buffer size.
  *
  * @param[in]  CosmOS_BufferVariableType * bufferVar
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType buffer_getBufferSize(CosmOS_BufferVariableType * bufferVar)
{
    return (bufferVar->cfg->size);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn buffer_isBufferInterCore(CosmOS_BufferVariableType * bufferVar)
  *
  * @brief Is buffer inter core.
  *
  * @param[in]  CosmOS_BufferVariableType * bufferVar
  *
  * @return CosmOS_BooleanType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BooleanType buffer_isBufferInterCore(CosmOS_BufferVariableType * bufferVar)
{
    return (bufferVar->cfg->isInterCore);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn buffer_getBufferSpinlockId(CosmOS_BufferVariableType * bufferVar)
  *
  * @brief Get buffer spinlockId.
  *
  * @param[in]  CosmOS_BufferVariableType * bufferVar
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType buffer_getBufferSpinlockId(CosmOS_BufferVariableType * bufferVar)
{
    return (bufferVar->cfg->spinlockId);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn buffer_getBufferReadPermission(CosmOS_BufferVariableType * bufferVar)
  *
  * @brief Get buffer readPermission.
  *
  * @param[in]  CosmOS_BufferVariableType * bufferVar
  *
  * @return CosmOS_PermissionsConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_PermissionsConfigurationType * buffer_getBufferReadPermission(CosmOS_BufferVariableType * bufferVar)
{
    return (CosmOS_PermissionsConfigurationType *)(bufferVar->cfg->readPermission);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn buffer_getBufferWritePermission(CosmOS_BufferVariableType * bufferVar)
  *
  * @brief Get buffer writePermission.
  *
  * @param[in]  CosmOS_BufferVariableType * bufferVar
  *
  * @return CosmOS_PermissionsConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_PermissionsConfigurationType * buffer_getBufferWritePermission(CosmOS_BufferVariableType * bufferVar)
{
    return (CosmOS_PermissionsConfigurationType *)(bufferVar->cfg->writePermission);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn buffer_getBufferHead(CosmOS_BufferVariableType * bufferVar)
  *
  * @brief Get buffer head.
  *
  * @param[in]  CosmOS_BufferVariableType * bufferVar
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType buffer_getBufferHead(CosmOS_BufferVariableType * bufferVar)
{
    return (bufferVar->head);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn buffer_getBufferTail(CosmOS_BufferVariableType * bufferVar)
  *
  * @brief Get buffer tail.
  *
  * @param[in]  CosmOS_BufferVariableType * bufferVar
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType buffer_getBufferTail(CosmOS_BufferVariableType * bufferVar)
{
    return (bufferVar->tail);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn buffer_getBufferFullCells(CosmOS_BufferVariableType * bufferVar)
  *
  * @brief Get buffer fullCells.
  *
  * @param[in]  CosmOS_BufferVariableType * bufferVar
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType buffer_getBufferFullCells(CosmOS_BufferVariableType * bufferVar)
{
    return (bufferVar->fullCells);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn buffer_getFullCellsNum(BitWidthType id, void * bufferVar, BitWidthType num)
  *
  * @brief Get full bufferVar cells DEMO CODE.
  *
  * @param[in]  CosmOS_BufferVariableType * bufferVar
  *
  * @return CosmOS_BufferStateType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType buffer_getFullCellsNum(CosmOS_BufferVariableType * bufferVar)
{
    return (bufferVar->fullCells);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn buffer_getEmptyCellsNum(CosmOS_BufferVariableType * bufferVar)
  *
  * @brief Get empty bufferVar cells DEMO CODE.
  *
  * @param[in]  CosmOS_BufferVariableType * bufferVar
  *
  * @return CosmOS_BufferStateType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType buffer_getEmptyCellsNum(CosmOS_BufferVariableType * bufferVar)
{
    return ((bufferVar->cfg->size) - (bufferVar->fullCells));
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Getters_buffer_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_buffer_h Setters
  * @ingroup Apis_buffer_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn buffer_setBufferHead(CosmOS_BufferVariableType * bufferVar, BitWidthType tailParam)
  *
  * @brief Set buffer head.
  *
  * @param[in]  CosmOS_BufferVariableType * bufferVar
  * @param[in]  BitWidthType headParam
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void buffer_setBufferHead(CosmOS_BufferVariableType * bufferVar, BitWidthType headParam)
{
    bufferVar->head = headParam;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn buffer_setBufferTail(CosmOS_BufferVariableType * bufferVar, BitWidthType tailParam)
  *
  * @brief Set buffer tail.
  *
  * @param[in]  CosmOS_BufferVariableType * bufferVar
  * @param[in]  BitWidthType tailParam
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void buffer_setBufferTail(CosmOS_BufferVariableType * bufferVar, BitWidthType tailParam)
{
    bufferVar->tail = tailParam;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn buffer_setBufferfullCells(CosmOS_BufferVariableType * bufferVar, BitWidthType fullCellsParam)
  *
  * @brief Set buffer fullCells.
  *
  * @param[in]  CosmOS_BufferVariableType * bufferVar
  * @param[in]  BitWidthType fullCellsParam
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void buffer_setBufferfullCells(CosmOS_BufferVariableType * bufferVar, BitWidthType fullCellsParam)
{
    bufferVar->fullCells = fullCellsParam;
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Setters_buffer_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_buffer_h General
  * @ingroup Apis_buffer_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn buffer_isEmpty(CosmOS_BufferVariableType * bufferVar)
  *
  * @brief Returning if the buffer is empty or ok.
  *
  * @param[in]  CosmOS_BufferVariableType * bufferVar
  *
  * @return CosmOS_BufferStateType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BufferStateType buffer_isEmpty(CosmOS_BufferVariableType * bufferVar)
{
    return (IS_NOT(bufferVar->fullCells) ? BUFFER_STATE_ENUM__EMPTY : BUFFER_STATE_ENUM__OK);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn buffer_isFull(CosmOS_BufferVariableType * bufferVar)
  *
  * @brief Returning if the buffer is full or ok.
  *
  * @param[in]  CosmOS_BufferVariableType * bufferVar
  *
  * @return CosmOS_BufferStateType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BufferStateType buffer_isFull(CosmOS_BufferVariableType * bufferVar)
{
    return (IS_NOT((bufferVar->cfg->size) ^ (bufferVar->fullCells)) ? \
    BUFFER_STATE_ENUM__FULL : BUFFER_STATE_ENUM__OK);
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_buffer_h
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
