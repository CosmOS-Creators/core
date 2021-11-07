/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file buffer.c
*********************************************************************************
<!--                    buffer Unit Local Group Definition                    -->
*********************************************************************************
** @defgroup Local_buffer Local
** @ingroup buffer_unit
** @brief buffer locals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "buffer.h"
#include "core.h"
#include "cosmosApiInternal.h"
#include "memoryProtection.h"
#include "os.h"
#include "permission.h"
#include "route.h"
#include "spinlock.h"

/* CIL interfaces */
#include "CILcore.h"
#include "CILinterrupt.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_buffer Macros
  * @ingroup Local_buffer
  * @{
********************************************************************************/
#define SYCALL_BYTES_CHUNK 8
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_buffer
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
  * @defgroup Variables_buffer Variables
  * @ingroup Local_buffer
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_buffer
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
  * @defgroup Apis_buffer_c API's
  * @ingroup Local_buffer
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_buffer_c Getters
  * @ingroup Apis_buffer_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_buffer_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_buffer_c Setters
  * @ingroup Apis_buffer_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_buffer_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_buffer_c General
  * @ingroup Apis_buffer_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn buffer_pull(CosmOS_BufferConfigurationType * bufferCfg,
  * unsigned char * data)
  *
  * @brief Pull data from the buffer. This function cannot be called from the
  * unprivileged context directly. DEMO
  *
  * @param[in]  bufferCfg buffer configuration structure pointer
  * @param[out]  data data to pull from the buffer
  *
  * @return CosmOS_BufferStateType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BufferStateType
buffer_pull( CosmOS_BufferConfigurationType * bufferCfg, unsigned char * data );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn buffer_push(CosmOS_BufferConfigurationType * bufferCfg,
  * unsigned char data)
  *
  * @brief Push data to the buffer. This function cannot be called from the
  * unprivileged context directly. DEMO
  *
  * @param[in]  bufferCfg buffer configuration structure pointer
  * @param[in]  data data to push to the buffer
  *
  * @return CosmOS_BufferStateType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BufferStateType
buffer_push( CosmOS_BufferConfigurationType * bufferCfg, unsigned char data );
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_buffer_c
********************************************************************************/
/********************************************************************************
**                         Function Prototypes | Stop                          **
********************************************************************************/
/********************************************************************************
**                        Function Definitions | Start                         **
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn buffer_pull(CosmOS_BufferConfigurationType * bufferCfg,
  * unsigned char * data)
  *
  * @details The implementation contains obtaining of the buffer size by calling
  * function buffer_getBufferSize and obtaining buffer array pointer by calling
  * function buffer_getBuffer. To the data pointer argument is then written
  * one byte from the buffer tail and fullCells of the current bufferCfg are
  * decremented by one. Position of the tail is updated and buffer empty state
  * is obtained by the buffer_isEmpty function and returned.
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BufferStateType
buffer_pull( CosmOS_BufferConfigurationType * bufferCfg, unsigned char * data )
{
    BitWidthType bufferSize;

    CosmOS_BufferStateType bufferState;

    unsigned char * osBuffer;

    bufferSize = buffer_getBufferSize( bufferCfg );
    osBuffer = buffer_getBuffer( bufferCfg );

    *data = *( osBuffer + bufferCfg->var->tail );

    bufferCfg->var->fullCells--;
    bufferCfg->var->tail = ( ( bufferCfg->var->tail + 1 ) % bufferSize );

    bufferState = buffer_isEmpty( bufferCfg );

    return bufferState;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn buffer_push(CosmOS_BufferConfigurationType * bufferCfg,
  * unsigned char data)
  *
  * @details The implementation contains obtaining of the buffer size by calling
  * function buffer_getBufferSize and obtaining buffer array pointer by calling
  * function buffer_getBuffer. To the buffer array in the head position is
  * written the data byte argument and fullCells of the current bufferCfg are
  * incremented by one. Position of the head is updated and buffer full state
  * is obtained by the buffer_isFull function and returned.
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BufferStateType
buffer_push( CosmOS_BufferConfigurationType * bufferCfg, unsigned char data )
{
    BitWidthType bufferSize;

    CosmOS_BufferStateType bufferState;

    unsigned char * osBuffer;

    bufferSize = buffer_getBufferSize( bufferCfg );
    osBuffer = buffer_getBuffer( bufferCfg );

    *( osBuffer + bufferCfg->var->head ) = data;

    bufferCfg->var->fullCells++;
    bufferCfg->var->head = ( ( bufferCfg->var->head + 1 ) % bufferSize );

    bufferState = buffer_isFull( bufferCfg );

    return bufferState;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn buffer_push(CosmOS_BufferConfigurationType * bufferCfg,
  * unsigned char data)
  *
  * @details The implementation contains obtaining of the buffer size by calling
  * function buffer_getBufferSize and obtaining buffer array pointer by calling
  * function buffer_getBuffer. To the buffer array in the head position is
  * written the data byte argument and fullCells of the current bufferCfg are
  * incremented by one. Position of the head is updated and buffer full state
  * is obtained by the buffer_isFull function and returned.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_BufferStateType
buffer_readArrayInternal(
    BitWidthType id,
    void * buffer,
    CosmOS_BufferConfigurationType * systemBufferCfg,
    BitWidthType size )
{
    CosmOS_BufferStateType bufferState;

    BitWidthType userBufferIndex;

    unsigned char * userBuffer;

    userBuffer = buffer;
    userBufferIndex = 0;
    bufferState = BUFFER_STATE_ENUM__OK;
    while ( ( userBufferIndex < size ) )
    {
        bufferState =
            buffer_pull( systemBufferCfg, ( userBuffer + userBufferIndex ) );
        userBufferIndex++;
    }

    return bufferState;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn buffer_push(CosmOS_BufferConfigurationType * bufferCfg,
  * unsigned char data)
  *
  * @details The implementation contains obtaining of the buffer size by calling
  * function buffer_getBufferSize and obtaining buffer array pointer by calling
  * function buffer_getBuffer. To the buffer array in the head position is
  * written the data byte argument and fullCells of the current bufferCfg are
  * incremented by one. Position of the head is updated and buffer full state
  * is obtained by the buffer_isFull function and returned.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_BufferStateType
buffer_writeArrayInternal(
    BitWidthType id,
    void * buffer,
    CosmOS_BufferConfigurationType * systemBufferCfg,
    BitWidthType size )
{
    CosmOS_BufferStateType bufferState;

    BitWidthType userBufferIndex;

    unsigned char * userBuffer;

    userBuffer = buffer;
    userBufferIndex = 0;
    bufferState = BUFFER_STATE_ENUM__OK;
    while ( ( userBufferIndex < size ) )
    {
        bufferState =
            buffer_push( systemBufferCfg, *( userBuffer + userBufferIndex ) );
        userBufferIndex++;
    }

    return bufferState;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn buffer_readArray(BitWidthType id, void * buffer, BitWidthType size)
  *
  * @details The implementation contains obtaining of the operating system
  * generated variable structure by os_getOsCfg function that stores all system
  * buffers in it. Then the generated core variable structure is obtained byt
  * the function CILcore_getCoreCfg and used in the
  * memoryProtection_isMemoryRegionProtected function call to check if the
  * memory where the data from the buffer will be written is protected.
  * If yes the bufferState is returned with the value
  * BUFFER_STATE_ENUM__ERROR_INPUT_ARRAY_IS_PROTECTED. If not bufferCfg is
  * obtained by the function os_getOsBufferCfg based on the id argument which
  * is mapped with the routes to the proper entity, in this case one of the
  * system buffers. From the buffer variable are then extracted read permissions
  * by the function call buffer_getBufferReadPermission and passed to the
  * function permission_tryAccess that checks if the current schedulable has
  * read access to this system buffer and if not bufferState is returned with
  * the value BUFFER_STATE_ENUM__ERROR_ACCESS_DENIED. If yes the interrupts are
  * disable before reading from the buffer by calling the function
  * CILinterrupt_disableInterrupts. After this point the function has ensure the
  * exclusive access to the bufferCfg and therefore buffer_isBufferInterCore
  * function is called to know if the buffer is inter-core. If yes spinlock id
  * is obtained by the function buffer_getBufferSpinlockId and then the spinlock
  * is tried by the non-blocking function spinlock_trySpinlock. If the spinlock
  * cannot be obtained the interrupts are enabled again and the bufferState is
  * returned with the value BUFFER_STATE_ENUM__ERROR_SPINLOCK_NOT_OBTAINED. If
  * the spinlock was obtained the function buffer_getFullCellsNum is called to
  * get full cells number and check if the user required more bytes to read than
  * available. If yes then the interrupts are enabled again the bufferState is
  * returned with the value
  * BUFFER_STATE_ENUM__ERROR_SIZE_BIGGER_THAN_FULL_CELLS_NUM. If there is enough
  * bytes to read the buffer_pull function is called in the while loop till the
  * required number of data is read out of the buffer and then the interrupts
  * are enabled again the bufferState is returned with the last value returned
  * from the buffer_pull function.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_BufferStateType
buffer_readArray( BitWidthType bufferId, void * buffer, BitWidthType size )
{
    BitWidthType numberOfBuffers;
    CosmOS_BooleanType isMemoryRegionProtected;
    CosmOS_BufferStateType bufferState;

    CosmOS_OsConfigurationType * osCfg;
    CosmOS_CoreConfigurationType * coreCfg;

    osCfg = os_getOsCfg();
    coreCfg = CILcore_getCoreCfg();

    numberOfBuffers = os_getOsNumberOfBuffers( osCfg );

    if ( bufferId < numberOfBuffers )
    {
        isMemoryRegionProtected =
            memoryProtection_isMemoryRegionProtected( coreCfg, buffer, size );

        if ( IS_NOT( isMemoryRegionProtected ) )
        {
            CosmOS_AccessStateType accessState;

            CosmOS_BufferConfigurationType * bufferCfg;
            CosmOS_PermissionsConfigurationType * readPermission;

            bufferCfg = os_getOsBufferCfg( osCfg, bufferId );

            readPermission = buffer_getBufferReadPermission( bufferCfg );
            accessState = permission_tryAccess( readPermission, coreCfg );

            if ( accessState IS_EQUAL_TO ACCESS_STATE_ENUM__ALLOWED )
            {
                BitWidthType spinlockId, fullCellsNum;
                CosmOS_SpinlockStateType spinlockState;

                spinlockId = buffer_getBufferSpinlockId( bufferCfg );
                spinlockState = spinlock_trySpinlock( spinlockId );

                if ( spinlockState IS_EQUAL_TO
                         SPINLOCK_STATE_ENUM__SUCCESSFULLY_LOCKED )
                {
                    fullCellsNum = buffer_getFullCellsNum( bufferCfg );

                    if ( fullCellsNum >= size )
                    {
                        BitWidthType userBufferIndex;

                        unsigned char * userBuffer;

                        userBuffer = buffer;
                        userBufferIndex = 0;

                        bufferState = BUFFER_STATE_ENUM__OK;
                        while ( size )
                        {
                            if ( size >= SYCALL_BYTES_CHUNK )
                            {
                                bufferState =
                                    cosmosApiInternal_buffer_readArrayInternal(
                                        ( userBuffer + userBufferIndex ),
                                        bufferCfg,
                                        SYCALL_BYTES_CHUNK );
                                userBufferIndex += SYCALL_BYTES_CHUNK;
                                size -= SYCALL_BYTES_CHUNK;
                            }
                            else
                            {
                                bufferState =
                                    cosmosApiInternal_buffer_readArrayInternal(
                                        ( userBuffer + userBufferIndex ),
                                        bufferCfg,
                                        size );
                                size -= size;
                            }
                        }
                    }
                    else
                    {
                        bufferState =
                            BUFFER_STATE_ENUM__ERROR_SIZE_BIGGER_THAN_FULL_CELLS_NUM;
                    }
                    spinlockState = spinlock_releaseSpinlock( spinlockId );
                }
                else
                {
                    bufferState = BUFFER_STATE_ENUM__ERROR_SPINLOCK_NOT_OBTAINED;
                }
            }
            else
            {
                bufferState = BUFFER_STATE_ENUM__ERROR_ACCESS_DENIED;
            }
        }
        else
        {
            bufferState = BUFFER_STATE_ENUM__ERROR_INPUT_ARRAY_IS_PROTECTED;
        }
    }
    else
    {
        bufferState = BUFFER_STATE_ENUM__ERROR_INVALID_ID;
    }

    return bufferState;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn buffer_writeArray(BitWidthType bufferId, void * buffer, BitWidthType size)
  *
  * @details The implementation contains obtaining of the operating system
  * generated variable structure by os_getOsCfg function that stores all system
  * buffers in it. Then the generated core variable structure is obtained byt
  * the function CILcore_getCoreCfg and used in the
  * memoryProtection_isMemoryRegionProtected function call to check if the
  * memory where the data from the buffer will be read from is protected.
  * If yes the bufferState is returned with the value
  * BUFFER_STATE_ENUM__ERROR_INPUT_ARRAY_IS_PROTECTED. If not bufferCfg is
  * obtained by the function os_getOsBufferCfg based on the id argument which
  * is mapped with the routes to the proper entity, in this case one of the
  * system buffers. From the buffer variable are then extracted write
  * permissions by the function call buffer_getBufferReadPermission and passed
  * to the function permission_tryAccess that checks if the current schedulable
  * has write access to this system buffer and if not bufferState is returned
  * with the value BUFFER_STATE_ENUM__ERROR_ACCESS_DENIED. If yes the interrupts
  * are disable before writing to the buffer by calling the function
  * CILinterrupt_disableInterrupts. After this point the function has ensure the
  * exclusive access to the bufferCfg and therefore buffer_isBufferInterCore
  * function is called to know if the buffer is inter-core. If yes spinlock id
  * is obtained by the function buffer_getBufferSpinlockId and then the spinlock
  * is tried by the non-blocking function spinlock_trySpinlock. If the spinlock
  * cannot be obtained the interrupts are enabled again and the bufferState is
  * returned with the value BUFFER_STATE_ENUM__ERROR_SPINLOCK_NOT_OBTAINED. If
  * the spinlock was obtained the function buffer_getEmptyCellsNum is called to
  * get empty cells number and check if the user required more bytes to write
  * than empty cells available in the buffer. If yes then the interrupts are
  * enabled again the bufferState is returned with the value
  * BUFFER_STATE_ENUM__ERROR_SIZE_BIGGER_THAN_FULL_CELLS_NUM. If there is enough
  * bytes to write the buffer_push function is called in the while loop till the
  * required number of data is written to the buffer and then the interrupts
  * are enabled again the bufferState is returned with the last value returned
  * from the buffer_push function.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_BufferStateType
buffer_writeArray( BitWidthType bufferId, void * buffer, BitWidthType size )
{
    BitWidthType numberOfBuffers;
    CosmOS_BooleanType isMemoryRegionProtected;
    CosmOS_BufferStateType bufferState;

    CosmOS_OsConfigurationType * osCfg;
    CosmOS_CoreConfigurationType * coreCfg;

    osCfg = os_getOsCfg();
    coreCfg = CILcore_getCoreCfg();

    numberOfBuffers = os_getOsNumberOfBuffers( osCfg );

    if ( bufferId < numberOfBuffers )
    {
        isMemoryRegionProtected =
            memoryProtection_isMemoryRegionProtected( coreCfg, buffer, size );

        if ( IS_NOT( isMemoryRegionProtected ) )
        {
            CosmOS_AccessStateType accessState;

            CosmOS_BufferConfigurationType * bufferCfg;
            CosmOS_PermissionsConfigurationType * writePermission;

            bufferCfg = os_getOsBufferCfg( osCfg, bufferId );

            writePermission = buffer_getBufferWritePermission( bufferCfg );
            accessState = permission_tryAccess( writePermission, coreCfg );

            if ( accessState IS_EQUAL_TO ACCESS_STATE_ENUM__ALLOWED )
            {
                BitWidthType spinlockId, emptyCellsNum;
                CosmOS_SpinlockStateType spinlockState;

                spinlockId = buffer_getBufferSpinlockId( bufferCfg );
                spinlockState = spinlock_trySpinlock( spinlockId );

                if ( spinlockState IS_EQUAL_TO
                         SPINLOCK_STATE_ENUM__SUCCESSFULLY_LOCKED )
                {
                    emptyCellsNum = buffer_getEmptyCellsNum( bufferCfg );

                    if ( emptyCellsNum >= size )
                    {
                        BitWidthType userBufferIndex;

                        unsigned char * userBuffer;

                        userBuffer = buffer;
                        userBufferIndex = 0;

                        bufferState = BUFFER_STATE_ENUM__OK;
                        while ( size )
                        {
                            if ( size >= SYCALL_BYTES_CHUNK )
                            {
                                bufferState =
                                    cosmosApiInternal_buffer_writeArrayInternal(
                                        ( userBuffer + userBufferIndex ),
                                        bufferCfg,
                                        SYCALL_BYTES_CHUNK );
                                userBufferIndex += SYCALL_BYTES_CHUNK;
                                size -= SYCALL_BYTES_CHUNK;
                            }
                            else
                            {
                                bufferState =
                                    cosmosApiInternal_buffer_writeArrayInternal(
                                        ( userBuffer + userBufferIndex ),
                                        bufferCfg,
                                        size );
                                size -= size;
                            }
                        }
                    }
                    else
                    {
                        bufferState =
                            BUFFER_STATE_ENUM__ERROR_SIZE_BIGGER_THAN_EMPTY_CELLS;
                    }
                    spinlockState = spinlock_releaseSpinlock( spinlockId );
                }
                else
                {
                    bufferState = BUFFER_STATE_ENUM__ERROR_SPINLOCK_NOT_OBTAINED;
                }
            }
            else
            {
                bufferState = BUFFER_STATE_ENUM__ERROR_ACCESS_DENIED;
            }
        }
        else
        {
            bufferState = BUFFER_STATE_ENUM__ERROR_INPUT_ARRAY_IS_PROTECTED;
        }
    }
    else
    {
        bufferState = BUFFER_STATE_ENUM__ERROR_INVALID_ID;
    }

    return bufferState;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/
/********************************************************************************
**                        Function Definitions | Stop                          **
********************************************************************************/
/********************************************************************************
**                           END OF THE SOURCE FILE                            **
********************************************************************************/
