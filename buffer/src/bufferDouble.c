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
#include "os.h"
#include "buffer.h"
#include "bufferDouble.h"
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
  * @}  
  * Macros_buffer  
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
  * @}  
  * Variables_buffer  
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
  * @}       
  * Getters_buffer_c
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
  * @}    
  * Setters_buffer_c   
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_buffer_c General  
  * @ingroup Apis_buffer_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_buffer_c  
********************************************************************************/
/********************************************************************************
**                         Function Prototypes | Stop                          **
********************************************************************************/
/********************************************************************************
**                        Function Definitions | Start                         **
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn bufferDouble_readArray(BitWidthType id, void * buffer, BitWidthType size, CosmOS_BufferDoubleAccessType access)cessType access)
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
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION CosmOS_BufferStateType bufferDouble_readArray(BitWidthType id, void * buffer, BitWidthType size, CosmOS_BufferDoubleAccessType access)
{
    BitWidthType bufferId;

    CosmOS_BufferStateType bufferState;

    CosmOS_OsVariableType * osVar;
    CosmOS_BufferVariableType * bufferVar;
    CosmOS_BufferDoubleVariableType * bufferDoubleVar;


    osVar = os_getOsVar();

    bufferDoubleVar = os_getOsBufferDoubleVar( osVar, id );

    switch ( access )
    {
        case BUFFER_DOUBLE_ACCESS_ENUM__USER :
        {
            bufferVar = bufferDouble_getBufferDoubleUserBuffer( bufferDoubleVar );
            break;
        }

        case BUFFER_DOUBLE_ACCESS_ENUM__KERNEL :
        {
            bufferVar = bufferDouble_getBufferDoubleKernelBuffer( bufferDoubleVar );
            break;
        }

        default :
        {
            /* PANIC */
            break;
        }
    }

    bufferId = buffer_getBufferId( bufferVar );
    bufferState = buffer_readArray( bufferId, buffer, size );

    return bufferState;
}
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn bufferDouble_writeArray(BitWidthType id, void * buffer, BitWidthType size, CosmOS_BufferDoubleAccessType access)
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
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION CosmOS_BufferStateType bufferDouble_writeArray(BitWidthType id, void * buffer, BitWidthType size, CosmOS_BufferDoubleAccessType access)
{
    BitWidthType bufferId;

    CosmOS_BufferStateType bufferState;

    CosmOS_OsVariableType * osVar;
    CosmOS_BufferVariableType * bufferVar;
    CosmOS_BufferDoubleVariableType * bufferDoubleVar;


    osVar = os_getOsVar();

    bufferDoubleVar = os_getOsBufferDoubleVar( osVar, id );

    switch ( access )
    {
        case BUFFER_DOUBLE_ACCESS_ENUM__USER :
        {
            bufferVar = bufferDouble_getBufferDoubleUserBuffer( bufferDoubleVar );
            break;
        }

        case BUFFER_DOUBLE_ACCESS_ENUM__KERNEL :
        {
            bufferVar = bufferDouble_getBufferDoubleKernelBuffer( bufferDoubleVar );
            break;
        }

        default :
        {
            /* PANIC */
            break;
        }
    }

    bufferId = buffer_getBufferId( bufferVar );
    bufferState = buffer_writeArray( bufferId, buffer, size );

    return bufferState;
}
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/
/********************************************************************************
**                        Function Definitions | Stop                          **
********************************************************************************/
/********************************************************************************
**                           END OF THE SOURCE FILE                            **
********************************************************************************/
