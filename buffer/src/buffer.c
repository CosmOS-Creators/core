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
  * @fn buffer_pull(CosmOS_BufferVariableType * bufferVar, unsigned char * data)
  *
  * @brief Pull data from the buffer. This function cannot be called from the
  * unprivileged context directly. DEMO
  *
  * @param[in]  bufferVar buffer variable structure pointer
  * @param[out]  data data to pull from the buffer
  *
  * @return CosmOS_BufferStateType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BufferStateType
buffer_pull( CosmOS_BufferVariableType * buffer, unsigned char * data );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn buffer_push(CosmOS_BufferVariableType * bufferVar, unsigned char data)
  *
  * @brief Push data to the buffer. This function cannot be called from the
  * unprivileged context directly. DEMO
  *
  * @param[in]  bufferVar buffer variable structure pointer
  * @param[in]  data data to push to the buffer
  *
  * @return CosmOS_BufferStateType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BufferStateType
buffer_push( CosmOS_BufferVariableType * bufferVar, unsigned char data );
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
  * @fn buffer_pull(CosmOS_BufferVariableType * bufferVar, unsigned char * data)
  *
  * @details The implementation contains obtaining of the buffer size by calling
  * function buffer_getBufferSize and obtaining buffer array pointer by calling
  * function buffer_getBuffer. To the data pointer argument is then written
  * one byte from the buffer tail and fullCells of the current bufferVar are
  * decremented by one. Position of the tail is updated and buffer empty state
  * is obtained by the buffer_isEmpty function and returned.
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BufferStateType
buffer_pull( CosmOS_BufferVariableType * bufferVar, unsigned char * data )
{
    BitWidthType bufferSize;

    CosmOS_BufferStateType bufferState;

    unsigned char * osBuffer;

    bufferSize = buffer_getBufferSize( bufferVar );
    osBuffer = buffer_getBuffer( bufferVar );

    *data = *( osBuffer + bufferVar->tail );

    bufferVar->fullCells--;
    bufferVar->tail = ( ( bufferVar->tail + 1 ) % bufferSize );

    bufferState = buffer_isEmpty( bufferVar );

    return bufferState;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn buffer_push(CosmOS_BufferVariableType * bufferVar, unsigned char data)
  *
  * @details The implementation contains obtaining of the buffer size by calling
  * function buffer_getBufferSize and obtaining buffer array pointer by calling
  * function buffer_getBuffer. To the buffer array in the head position is
  * written the data byte argument and fullCells of the current bufferVar are
  * incremented by one. Position of the head is updated and buffer full state
  * is obtained by the buffer_isFull function and returned.
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BufferStateType
buffer_push( CosmOS_BufferVariableType * bufferVar, unsigned char data )
{
    BitWidthType bufferSize;

    CosmOS_BufferStateType bufferState;

    unsigned char * osBuffer;

    bufferSize = buffer_getBufferSize( bufferVar );
    osBuffer = buffer_getBuffer( bufferVar );

    *( osBuffer + bufferVar->head ) = data;

    bufferVar->fullCells++;
    bufferVar->head = ( ( bufferVar->head + 1 ) % bufferSize );

    bufferState = buffer_isFull( bufferVar );

    return bufferState;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn buffer_readArray(BitWidthType id, void * buffer, BitWidthType size)
  *
  * @details The implementation contains obtaining of the operating system
  * generated variable structure by os_getOsVar function that stores all system
  * buffers in it. Then the generated core variable structure is obtained byt
  * the function CILcore_getCoreVar and used in the
  * memoryProtection_isMemoryRegionProtected function call to check if the
  * memory where the data from the buffer will be written is protected.
  * If yes the bufferState is returned with the value
  * BUFFER_STATE_ENUM__ERROR_INPUT_ARRAY_IS_PROTECTED. If not bufferVar is
  * obtained by the function os_getOsBufferVar based on the id argument which
  * is mapped with the routes to the proper entity, in this case one of the
  * system buffers. From the buffer variable are then extracted read permissions
  * by the function call buffer_getBufferReadPermission and passed to the
  * function permission_tryAccess that checks if the current schedulable has
  * read access to this system buffer and if not bufferState is returned with
  * the value BUFFER_STATE_ENUM__ERROR_ACCESS_DENIED. If yes the interrupts are
  * disable before reading from the buffer by calling the function
  * CILinterrupt_disableInterrupts. After this point the function has ensure the
  * exclusive access to the bufferVar and therefore buffer_isBufferInterCore
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
buffer_readArray( BitWidthType id, void * buffer, BitWidthType size )
{
    CosmOS_BooleanType isMemoryRegionProtected;
    CosmOS_BufferStateType bufferState;

    CosmOS_OsVariableType * osVar;
    CosmOS_CoreVariableType * coreVar;

    osVar = os_getOsVar();
    coreVar = CILcore_getCoreVar();

    isMemoryRegionProtected =
        memoryProtection_isMemoryRegionProtected( coreVar, buffer, size );

    if ( isMemoryRegionProtected )
    {
        bufferState = BUFFER_STATE_ENUM__ERROR_INPUT_ARRAY_IS_PROTECTED;
    }
    else
    {
        CosmOS_AccessStateType accessState;

        CosmOS_BufferVariableType * bufferVar;
        CosmOS_PermissionsConfigurationType * readPermission;

        bufferVar = os_getOsBufferVar( osVar, id );

        readPermission = buffer_getBufferReadPermission( bufferVar );
        accessState = permission_tryAccess( readPermission, coreVar );

        if ( accessState IS_EQUAL_TO ACCESS_STATE_ENUM__DENIED )
        {
            bufferState = BUFFER_STATE_ENUM__ERROR_ACCESS_DENIED;
        }
        else
        {
            BitWidthType spinlockId, fullCellsNum;
            CosmOS_AccessStateType isBufferInterCore;
            CosmOS_SpinlockStateType spinlockState;

            CILinterrupt_disableInterrupts();

            isBufferInterCore = buffer_isBufferInterCore( bufferVar );

            if ( isBufferInterCore )
            {
                spinlockId = buffer_getBufferSpinlockId( bufferVar );
                spinlockState = spinlock_trySpinlock( spinlockId );
            }
            else
            {
                spinlockState = SPINLOCK_STATE_ENUM__SUCCESSFULLY_LOCKED;
            }

            if ( spinlockState IS_EQUAL_TO
                     SPINLOCK_STATE_ENUM__SUCCESSFULLY_LOCKED )
            {
                fullCellsNum = buffer_getFullCellsNum( bufferVar );

                if ( fullCellsNum >= size )
                {
                    BitWidthType userBufferIndex;

                    unsigned char * userBuffer;

                    userBuffer = buffer;
                    userBufferIndex = 0;

                    while ( ( userBufferIndex < size ) )
                    {
                        bufferState = buffer_pull(
                            bufferVar, ( userBuffer + userBufferIndex ) );
                        userBufferIndex++;
                    }
                }
                else
                {
                    bufferState =
                        BUFFER_STATE_ENUM__ERROR_SIZE_BIGGER_THAN_FULL_CELLS_NUM;
                }

                if ( isBufferInterCore )
                {
                    spinlockState = spinlock_releaseSpinlock( spinlockId );
                }
            }
            else
            {
                bufferState = BUFFER_STATE_ENUM__ERROR_SPINLOCK_NOT_OBTAINED;
            }

            CILinterrupt_enableInterrupts();
        }
    }

    /* MEMORY BARRIER HAS TO BE IMPLEMENTED */

    return bufferState;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn buffer_writeArray(BitWidthType id, void * buffer, BitWidthType size)
  *
  * @details The implementation contains obtaining of the operating system
  * generated variable structure by os_getOsVar function that stores all system
  * buffers in it. Then the generated core variable structure is obtained byt
  * the function CILcore_getCoreVar and used in the
  * memoryProtection_isMemoryRegionProtected function call to check if the
  * memory where the data from the buffer will be read from is protected.
  * If yes the bufferState is returned with the value
  * BUFFER_STATE_ENUM__ERROR_INPUT_ARRAY_IS_PROTECTED. If not bufferVar is
  * obtained by the function os_getOsBufferVar based on the id argument which
  * is mapped with the routes to the proper entity, in this case one of the
  * system buffers. From the buffer variable are then extracted write
  * permissions by the function call buffer_getBufferReadPermission and passed
  * to the function permission_tryAccess that checks if the current schedulable
  * has write access to this system buffer and if not bufferState is returned
  * with the value BUFFER_STATE_ENUM__ERROR_ACCESS_DENIED. If yes the interrupts
  * are disable before writing to the buffer by calling the function
  * CILinterrupt_disableInterrupts. After this point the function has ensure the
  * exclusive access to the bufferVar and therefore buffer_isBufferInterCore
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
buffer_writeArray( BitWidthType id, void * buffer, BitWidthType size )
{
    CosmOS_BooleanType isMemoryRegionProtected;
    CosmOS_BufferStateType bufferState;

    CosmOS_OsVariableType * osVar;
    CosmOS_CoreVariableType * coreVar;

    osVar = os_getOsVar();
    coreVar = CILcore_getCoreVar();

    isMemoryRegionProtected =
        memoryProtection_isMemoryRegionProtected( coreVar, buffer, size );

    if ( isMemoryRegionProtected )
    {
        bufferState = BUFFER_STATE_ENUM__ERROR_INPUT_ARRAY_IS_PROTECTED;
    }
    else
    {
        CosmOS_AccessStateType accessState;

        CosmOS_BufferVariableType * bufferVar;
        CosmOS_PermissionsConfigurationType * writePermission;

        bufferVar = os_getOsBufferVar( osVar, id );

        writePermission = buffer_getBufferWritePermission( bufferVar );
        accessState = permission_tryAccess( writePermission, coreVar );

        if ( accessState IS_EQUAL_TO ACCESS_STATE_ENUM__DENIED )
        {
            bufferState = BUFFER_STATE_ENUM__ERROR_ACCESS_DENIED;
        }
        else
        {
            BitWidthType spinlockId, emptyCellsNum;
            CosmOS_AccessStateType isBufferInterCore;
            CosmOS_SpinlockStateType spinlockState;

            CILinterrupt_disableInterrupts();

            isBufferInterCore = buffer_isBufferInterCore( bufferVar );

            if ( isBufferInterCore )
            {
                spinlockId = buffer_getBufferSpinlockId( bufferVar );
                spinlockState = spinlock_trySpinlock( spinlockId );
            }
            else
            {
                spinlockState = SPINLOCK_STATE_ENUM__SUCCESSFULLY_LOCKED;
            }

            if ( spinlockState IS_EQUAL_TO
                     SPINLOCK_STATE_ENUM__SUCCESSFULLY_LOCKED )
            {
                emptyCellsNum = buffer_getEmptyCellsNum( bufferVar );

                if ( emptyCellsNum >= size )
                {
                    BitWidthType userBufferIndex;

                    unsigned char * userBuffer;

                    userBuffer = buffer;
                    userBufferIndex = 0;

                    while ( ( userBufferIndex < size ) )
                    {
                        bufferState = buffer_push(
                            bufferVar, *( userBuffer + userBufferIndex ) );
                        userBufferIndex++;
                    }
                }
                else
                {
                    bufferState =
                        BUFFER_STATE_ENUM__ERROR_SIZE_BIGGER_THAN_EMPTY_CELLS;
                }

                if ( isBufferInterCore )
                {
                    spinlockState = spinlock_releaseSpinlock( spinlockId );
                }
            }
            else
            {
                bufferState = BUFFER_STATE_ENUM__ERROR_SPINLOCK_NOT_OBTAINED;
            }

            CILinterrupt_enableInterrupts();
        }
    }

    /* MEMORY BARRIER HAS TO BE IMPLEMENTED */

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
