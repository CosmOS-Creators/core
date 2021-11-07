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
  * @defgroup Macros_buffer_h Macros
  * @ingroup Global_buffer
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_buffer_h
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
  * @} */
/*  Variables_buffer_h
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
  * @} */
/*  Getters_buffer_h
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
  * @} */
/*  Setters_buffer_h
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
  * ****************************************************************************/
/**
  * @fn buffer_readArrayInternal(
  * BitWidthType id,
  * void * buffer,
  * CosmOS_BufferConfigurationType * systemBufferCfg,
  * BitWidthType size );
  *
  * @brief Reading array from the buffer. DEMO
  *
  * @param[in]  id buffer identifier
  * @param[in]  buffer pointer to the user buffer array
  * @param[out]  systemBufferCfg configuration pointer
  * @param[in]  size of the bytes to read
  *
  * @return CosmOS_BufferStateType
********************************************************************************/
__OS_FUNC_SECTION CosmOS_BufferStateType
buffer_readArrayInternal(
    BitWidthType id,
    void * buffer,
    CosmOS_BufferConfigurationType * systemBufferCfg,
    BitWidthType size );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn buffer_writeArrayInternal(
  * BitWidthType id,
  * void * buffer,
  * CosmOS_BufferConfigurationType * systemBufferCfg,
  * BitWidthType size );
  *
  * @brief Writing array from the buffer. DEMO
  *
  * @param[in]  id buffer identifier
  * @param[in]  buffer pointer to the user buffer array
  * @param[out]  systemBufferCfg configuration pointer
  * @param[in]  size of the bytes to write
  *
  * @return CosmOS_BufferStateType
********************************************************************************/
__OS_FUNC_SECTION CosmOS_BufferStateType
buffer_writeArrayInternal(
    BitWidthType id,
    void * buffer,
    CosmOS_BufferConfigurationType * systemBufferCfg,
    BitWidthType size );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn buffer_readArray(BitWidthType bufferId, void * buffer, BitWidthType size)
  *
  * @brief Reading array from the buffer. DEMO
  *
  * @param[in]  bufferId buffer identifier
  * @param[out]  buffer pointer to the user buffer array
  * @param[in]  size of the bytes to read
  *
  * @return CosmOS_BufferStateType
********************************************************************************/
__OS_FUNC_SECTION CosmOS_BufferStateType
buffer_readArray( BitWidthType bufferId, void * buffer, BitWidthType size );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn buffer_writeArray(BitWidthType bufferId, void * buffer, BitWidthType size)
  *
  * @brief Writing array into the buffer. DEMO
  *
  * @param[in]  bufferId buffer identifier
  * @param[in]  buffer pointer to the user buffer array
  * @param[in]  size of the bytes to write
  *
  * @return CosmOS_BufferStateType
********************************************************************************/
__OS_FUNC_SECTION CosmOS_BufferStateType
buffer_writeArray( BitWidthType bufferId, void * buffer, BitWidthType size );
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_buffer_h
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
  * ****************************************************************************/
/**
  * @fn buffer_getBuffer(CosmOS_BufferConfigurationType * bufferCfg)
  *
  * @brief Get buffer pointer.
  *
  * @param[in]  bufferCfg configuration pointer
  *
  * @return unsigned char *
********************************************************************************/
__STATIC_FORCEINLINE unsigned char *
buffer_getBuffer( CosmOS_BufferConfigurationType * bufferCfg )
{
    return (unsigned char *)( bufferCfg->buffer );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn buffer_getBufferId(CosmOS_BufferConfigurationType * bufferCfg)
  *
  * @brief Get buffer id.
  *
  * @param[in]  bufferCfg configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
buffer_getBufferId( CosmOS_BufferConfigurationType * bufferCfg )
{
    return ( bufferCfg->id );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn buffer_getBufferSize(CosmOS_BufferConfigurationType * bufferCfg)
  *
  * @brief Get buffer size.
  *
  * @param[in]  bufferCfg configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
buffer_getBufferSize( CosmOS_BufferConfigurationType * bufferCfg )
{
    return ( bufferCfg->size );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn buffer_isBufferInterCore(CosmOS_BufferConfigurationType * bufferCfg)
  *
  * @brief Is buffer inter core.
  *
  * @param[in]  bufferCfg configuration pointer
  *
  * @return CosmOS_BooleanType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BooleanType
buffer_isBufferInterCore( CosmOS_BufferConfigurationType * bufferCfg )
{
    return ( bufferCfg->isInterCore );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn buffer_getBufferSpinlockId(CosmOS_BufferConfigurationType * bufferCfg)
  *
  * @brief Get buffer spinlockId.
  *
  * @param[in]  bufferCfg configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
buffer_getBufferSpinlockId( CosmOS_BufferConfigurationType * bufferCfg )
{
    return ( bufferCfg->spinlockId );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn buffer_getBufferReadPermission(CosmOS_BufferConfigurationType *
  * bufferCfg)
  *
  * @brief Get buffer readPermission.
  *
  * @param[in]  bufferCfg configuration pointer
  *
  * @return CosmOS_PermissionsConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_PermissionsConfigurationType *
buffer_getBufferReadPermission( CosmOS_BufferConfigurationType * bufferCfg )
{
    return (CosmOS_PermissionsConfigurationType *)( bufferCfg->readPermission );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn buffer_getBufferWritePermission(CosmOS_BufferConfigurationType *
  * bufferCfg)
  *
  * @brief Get buffer writePermission.
  *
  * @param[in]  bufferCfg configuration pointer
  *
  * @return CosmOS_PermissionsConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_PermissionsConfigurationType *
buffer_getBufferWritePermission( CosmOS_BufferConfigurationType * bufferCfg )
{
    return (CosmOS_PermissionsConfigurationType *)( bufferCfg->writePermission );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn buffer_getBufferHead(CosmOS_BufferConfigurationType * bufferCfg)
  *
  * @brief Get buffer head.
  *
  * @param[in]  bufferCfg configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
buffer_getBufferHead( CosmOS_BufferConfigurationType * bufferCfg )
{
    return ( bufferCfg->var->head );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn buffer_getBufferTail(CosmOS_BufferConfigurationType * bufferCfg)
  *
  * @brief Get buffer tail.
  *
  * @param[in]  bufferCfg configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
buffer_getBufferTail( CosmOS_BufferConfigurationType * bufferCfg )
{
    return ( bufferCfg->var->tail );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn buffer_getFullCellsNum(BitWidthType id, void * bufferCfg,
  * BitWidthType num)
  *
  * @brief Get full bufferCfg cells DEMO CODE.
  *
  * @param[in]  bufferCfg configuration pointer
  *
  * @return CosmOS_BufferStateType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
buffer_getFullCellsNum( CosmOS_BufferConfigurationType * bufferCfg )
{
    return ( bufferCfg->var->fullCells );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn buffer_getEmptyCellsNum(CosmOS_BufferConfigurationType * bufferCfg)
  *
  * @brief Get empty bufferCfg cells DEMO CODE.
  *
  * @param[in]  bufferCfg configuration pointer
  *
  * @return CosmOS_BufferStateType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
buffer_getEmptyCellsNum( CosmOS_BufferConfigurationType * bufferCfg )
{
    return ( ( bufferCfg->size ) - ( bufferCfg->var->fullCells ) );
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_buffer_h
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
  * ****************************************************************************/
/**
  * @fn buffer_setBufferHead(CosmOS_BufferConfigurationType * bufferCfg,
  * BitWidthType tailParam)
  *
  * @brief Set buffer head. This function cannot be called
  * from the unprivileged context directly.
  *
  * @param[out]  bufferCfg configuration pointer
  * @param[in]  headParam head of the buffer
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
buffer_setBufferHead(
    CosmOS_BufferConfigurationType * bufferCfg,
    BitWidthType headParam )
{
    bufferCfg->var->head = headParam;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn buffer_setBufferTail(CosmOS_BufferConfigurationType * bufferCfg,
  * BitWidthType tailParam)
  *
  * @brief Set buffer tail. This function cannot be called
  * from the unprivileged context directly.
  *
  * @param[out]  bufferCfg configuration pointer
  * @param[in]  tailParam tail of the buffer
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
buffer_setBufferTail(
    CosmOS_BufferConfigurationType * bufferCfg,
    BitWidthType tailParam )
{
    bufferCfg->var->tail = tailParam;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn buffer_setBufferfullCells(CosmOS_BufferConfigurationType * bufferCfg,
  * BitWidthType fullCellsParam)
  *
  * @brief Set buffer fullCells. This function cannot be called
  * from the unprivileged context directly.
  *
  * @param[out]  bufferCfg configuration pointer
  * @param[in]  fullCellsParam full cells
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
buffer_setBufferfullCells(
    CosmOS_BufferConfigurationType * bufferCfg,
    BitWidthType fullCellsParam )
{
    bufferCfg->var->fullCells = fullCellsParam;
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_buffer_h
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
  * ****************************************************************************/
/**
  * @fn buffer_isEmpty(CosmOS_BufferConfigurationType * bufferCfg)
  *
  * @brief Returning if the buffer is empty or ok.
  *
  * @param[in]  bufferCfg configuration pointer
  *
  * @return CosmOS_BufferStateType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BufferStateType
buffer_isEmpty( CosmOS_BufferConfigurationType * bufferCfg )
{
    return (
        IS_NOT( bufferCfg->var->fullCells ) ? BUFFER_STATE_ENUM__EMPTY
                                            : BUFFER_STATE_ENUM__OK );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn buffer_isFull(CosmOS_BufferConfigurationType * bufferCfg)
  *
  * @brief Returning if the buffer is full or ok.
  *
  * @param[in]  bufferCfg configuration pointer
  *
  * @return CosmOS_BufferStateType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BufferStateType
buffer_isFull( CosmOS_BufferConfigurationType * bufferCfg )
{
    return (
        IS_NOT( ( bufferCfg->size ) ^ ( bufferCfg->var->fullCells ) )
            ? BUFFER_STATE_ENUM__FULL
            : BUFFER_STATE_ENUM__OK );
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_buffer_h
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
