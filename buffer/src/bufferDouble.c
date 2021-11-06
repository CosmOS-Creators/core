/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file bufferDouble.c
*********************************************************************************
<!--                 bufferDouble Unit Local Group Definition                 -->
*********************************************************************************
** @defgroup Local_bufferDouble Local
** @ingroup bufferDouble_unit
** @brief bufferDouble locals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "bufferDouble.h"
#include "buffer.h"
#include "os.h"

/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_bufferDouble Macros
  * @ingroup Local_bufferDouble
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_bufferDouble
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
  * @defgroup Variables_bufferDouble Variables
  * @ingroup Local_bufferDouble
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_bufferDouble
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
  * @defgroup Apis_bufferDouble_c API's
  * @ingroup Local_bufferDouble
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_bufferDouble_c Getters
  * @ingroup Apis_bufferDouble_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_bufferDouble_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_bufferDouble_c Setters
  * @ingroup Apis_bufferDouble_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_bufferDouble_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_bufferDouble_c General
  * @ingroup Apis_bufferDouble_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_bufferDouble_c
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
  * @fn bufferDouble_readArray(BitWidthType id, void * buffer,
  * BitWidthType size, CosmOS_BufferDoubleAccessType access)
  *
  * @details The implementation contains obtaining of the operating system
  * generated variable structure by os_getOsVar function that stores all system
  * double buffers in it.
  * Then the double buffer variable is obtained by the function
  * os_getOsBufferDoubleCfg based on the id argument which is mapped with the
  * routes to the proper entity, in this case one of the system double buffers.
  * After this point the buffer variable is obtained based on the access type
  * either BUFFER_DOUBLE_ACCESS_ENUM__USER or BUFFER_DOUBLE_ACCESS_ENUM__KERNEL.
  * with functions bufferDouble_getBufferDoubleUserBuffer or
  * bufferDouble_getBufferDoubleKernelBuffer. In the case of wrong access type
  * the BUFFER_STATE_ENUM__ERROR_ACCESS_DENIED is returned as bufferState.
  * From the buffer variable the buffer id is extracted by calling
  * buffer_getBufferId function and then the function buffer_readArray to read
  * specific number of bytes from the buffer.
  * Finally the bufferState is returned.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_BufferStateType
bufferDouble_readArray(
    BitWidthType id,
    void * buffer,
    BitWidthType size,
    CosmOS_BufferDoubleAccessType access )
{
    BitWidthType bufferId;

    CosmOS_BufferStateType bufferState;

    CosmOS_OsVariableType * osVar;
    CosmOS_BufferConfigurationType * bufferCfg;
    CosmOS_BufferDoubleConfigurationType * bufferDoubleCfg;

    osVar = os_getOsVar();

    bufferDoubleCfg = os_getOsBufferDoubleCfg( osVar, id );

    switch ( access )
    {
        case BUFFER_DOUBLE_ACCESS_ENUM__USER:
        {
            bufferCfg =
                bufferDouble_getBufferDoubleUserBuffer( bufferDoubleCfg );
            bufferId = buffer_getBufferId( bufferCfg );
            bufferState = buffer_readArray( bufferId, buffer, size );
            break;
        }

        case BUFFER_DOUBLE_ACCESS_ENUM__KERNEL:
        {
            bufferCfg =
                bufferDouble_getBufferDoubleKernelBuffer( bufferDoubleCfg );
            bufferId = buffer_getBufferId( bufferCfg );
            bufferState = buffer_readArray( bufferId, buffer, size );
            break;
        }

        default:
        {
            bufferState = BUFFER_STATE_ENUM__ERROR_ACCESS_DENIED;
            break;
        }
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
  * @fn bufferDouble_writeArray(BitWidthType id, void * buffer,
  * BitWidthType size, CosmOS_BufferDoubleAccessType access)
  *
  * @details The implementation contains obtaining of the operating system
  * generated variable structure by os_getOsVar function that stores all system
  * double buffers in it.
  * Then the double buffer variable is obtained by the function
  * os_getOsBufferDoubleCfg based on the id argument which is mapped with the
  * routes to the proper entity, in this case one of the system double buffers.
  * After this point the buffer variable is obtained based on the access type
  * either BUFFER_DOUBLE_ACCESS_ENUM__USER or BUFFER_DOUBLE_ACCESS_ENUM__KERNEL.
  * with functions bufferDouble_getBufferDoubleUserBuffer or
  * bufferDouble_getBufferDoubleKernelBuffer. In the case of wrong access type
  * the BUFFER_STATE_ENUM__ERROR_ACCESS_DENIED is returned as bufferState.
  * From the buffer variable the buffer id is extracted by calling
  * buffer_getBufferId function and then the function buffer_writeArray to write
  * specific number of bytes to the buffer.
  * Finally the bufferState is returned.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_BufferStateType
bufferDouble_writeArray(
    BitWidthType id,
    void * buffer,
    BitWidthType size,
    CosmOS_BufferDoubleAccessType access )
{
    BitWidthType bufferId;

    CosmOS_BufferStateType bufferState;

    CosmOS_OsVariableType * osVar;
    CosmOS_BufferConfigurationType * bufferCfg;
    CosmOS_BufferDoubleConfigurationType * bufferDoubleCfg;

    osVar = os_getOsVar();

    bufferDoubleCfg = os_getOsBufferDoubleCfg( osVar, id );

    switch ( access )
    {
        case BUFFER_DOUBLE_ACCESS_ENUM__USER:
        {
            bufferCfg =
                bufferDouble_getBufferDoubleUserBuffer( bufferDoubleCfg );
            bufferId = buffer_getBufferId( bufferCfg );
            bufferState = buffer_writeArray( bufferId, buffer, size );
            break;
        }

        case BUFFER_DOUBLE_ACCESS_ENUM__KERNEL:
        {
            bufferCfg =
                bufferDouble_getBufferDoubleKernelBuffer( bufferDoubleCfg );
            bufferId = buffer_getBufferId( bufferCfg );
            bufferState = buffer_writeArray( bufferId, buffer, size );
            break;
        }

        default:
        {
            bufferState = BUFFER_STATE_ENUM__ERROR_ACCESS_DENIED;
            break;
        }
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
