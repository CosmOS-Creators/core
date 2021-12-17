/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file channel.h
*********************************************************************************
<!--                      channel Module Group Definition                    -->
*********************************************************************************
** @defgroup channel_module channel
** @brief channel Module
** @details lorem
*********************************************************************************
<!--                      channel Unit Group Definition                     -->
*********************************************************************************
** @defgroup channel_unit channel Unit
** @ingroup channel_module
** @brief channel Unit
** @details lorem
*********************************************************************************
<!--                           Version Information                            -->
*********************************************************************************
** @version 1.0.0
** @date 18.08.2021
** @author https://github.com/pavolkostolansky
*********************************************************************************
<!--                          Warnings and License                            -->
*********************************************************************************
** @warning Modifying code can lead to unexpected behaviour of the whole system
** @copyright MIT License
*********************************************************************************
<!--                  channel Unit Global Group Definition                    -->
*********************************************************************************
** @defgroup Global_channel Global
** @ingroup channel_unit
** @brief channel globals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __CHANNEL_H__
#define __CHANNEL_H__
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
  * @defgroup Macros_channel_h Macros
  * @ingroup Global_channel
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/* Macros_channel_h
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
  * @defgroup Variables_channel_h Variables
  * @ingroup Global_channel
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/* Variables_channel_h
********************************************************************************/
/********************************************************************************
**                              Variables | Stop                               **
********************************************************************************/
/********************************************************************************
**                         Function Prototypes | Start                         **
********************************************************************************/
/********************************************************************************
* DOXYGEN DEF GROUP                                                            **
* ***************************************************************************//**
* @defgroup Apis_channel_h API's
* @ingroup Global_channel
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_channel_h Getters
  * @ingroup Apis_channel_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/* Getters_channel_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_channel_h Setters
  * @ingroup Apis_channel_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/* Setters_channel_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_channel_h General
  * @ingroup Apis_channel_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osEvent_dispatchEvent( void )
  *
  * @details The implementation contains
********************************************************************************/
__OS_FUNC_SECTION CosmOS_ChannelStateType
channel_initialize( BitWidthType channelId );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osEvent_triggerEvent(
  * BitWidthType event,
  * CosmOS_BooleanType * handleCores,
  * AddressType * data,
  * BitWidthType size )
  *
  * @details The implementation contains
********************************************************************************/
__OS_FUNC_SECTION CosmOS_ChannelStateType
channel_send(
    BitWidthType channelId,
    AddressType * userSendDataPool,
    BitWidthType userSendPoolSize,
    AddressType * userReplyDataPool,
    BitWidthType userReplyPoolSize );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osEvent_triggerEvent(
  * BitWidthType event,
  * CosmOS_BooleanType * handleCores,
  * AddressType * data,
  * BitWidthType size )
  *
  * @details The implementation contains
********************************************************************************/
__OS_FUNC_SECTION CosmOS_ChannelStateType
channel_receive(
    BitWidthType channelId,
    AddressType * userReceiveDataPool,
    BitWidthType userReceiveDataPoolSize );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osEvent_dispatchEvent( void )
  *
  * @details The implementation contains
********************************************************************************/
__OS_FUNC_SECTION CosmOS_ChannelStateType
channel_reply(
    BitWidthType channelId,
    AddressType * userReplyDataPool,
    BitWidthType userReplyDataPoolSize );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osEvent_dispatchEvent( void )
  *
  * @details The implementation contains
********************************************************************************/
__OS_FUNC_SECTION void
channel_signalizeReply( void );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osEvent_dispatchEvent( void )
  *
  * @details The implementation contains
********************************************************************************/
__OS_FUNC_SECTION void
channel_signalizeSend( void );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osEvent_triggerEventInternal(
  * BitWidthType id,
  * CosmOS_BooleanType * handleCores,
  * BitWidthType event )
  *
  * @details The implementation contains
********************************************************************************/
__OS_FUNC_SECTION void
channel_initializeInternal(
    BitWidthType id,
    CosmOS_ChannelConfigurationType * channelCfg );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osEvent_triggerEventInternal(
  * BitWidthType id,
  * CosmOS_BooleanType * handleCores,
  * BitWidthType event )
  *
  * @details The implementation contains
********************************************************************************/
__OS_FUNC_SECTION void
channel_sendInternal(
    BitWidthType id,
    CosmOS_ChannelConfigurationType * channelCfg,
    BitWidthType sendPoolPayloadLength,
    BitWidthType userReplyDataPoolSize );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osEvent_triggerEventInternal(
  * BitWidthType id,
  * CosmOS_BooleanType * handleCores,
  * BitWidthType event )
  *
  * @details The implementation contains
********************************************************************************/
__OS_FUNC_SECTION void
channel_sendReplyObtainedInternal(
    BitWidthType id,
    CosmOS_ChannelConfigurationType * channelCfg );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osEvent_triggerEventInternal(
  * BitWidthType id,
  * CosmOS_BooleanType * handleCores,
  * BitWidthType event )
  *
  * @details The implementation contains
********************************************************************************/
__OS_FUNC_SECTION void
channel_receiveInternal(
    BitWidthType id,
    CosmOS_ChannelConfigurationType * channelCfg );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osEvent_triggerEventInternal(
  * BitWidthType id,
  * CosmOS_BooleanType * handleCores,
  * BitWidthType event )
  *
  * @details The implementation contains
********************************************************************************/
__OS_FUNC_SECTION void
channel_replyInternal(
    BitWidthType id,
    CosmOS_ChannelConfigurationType * channelCfg,
    BitWidthType replyPoolPayloadLength );

/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/* General_channel_h
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
  * @addtogroup Getters_channel_h Getters
  * @ingroup Apis_channel_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn channel_getChannelId(CosmOS_ChannelConfigurationType * channel)
  *
  * @brief Get channel id.
  *
  * @param[in]  channel configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
channel_getChannelId( CosmOS_ChannelConfigurationType * channel )
{
    return ( BitWidthType )( channel->id );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn channel_getChannelSendPool(CosmOS_ChannelConfigurationType * channel)
  *
  * @brief Get sendPool pointer.
  *
  * @param[in]  channel configuration pointer
  *
  * @return unsigned char *
********************************************************************************/
__STATIC_FORCEINLINE unsigned char *
channel_getChannelSendPool( CosmOS_ChannelConfigurationType * channel )
{
    return (unsigned char *)( channel->sendPool );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn channel_getChannelReplyPool(CosmOS_ChannelConfigurationType * channel)
  *
  * @brief Get replyPool pointer.
  *
  * @param[in]  channel configuration pointer
  *
  * @return unsigned char *
********************************************************************************/
__STATIC_FORCEINLINE unsigned char *
channel_getChannelReplyPool( CosmOS_ChannelConfigurationType * channel )
{
    return (unsigned char *)( channel->replyPool );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn channel_getChannelSendPoolSize(CosmOS_ChannelConfigurationType * channel)
  *
  * @brief Get channel sendPoolSize.
  *
  * @param[in]  channel configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
channel_getChannelSendPoolSize( CosmOS_ChannelConfigurationType * channel )
{
    return ( BitWidthType )( channel->sendPoolSize );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn channel_getChannelReplyPoolSize(CosmOS_ChannelConfigurationType * channel)
  *
  * @brief Get channel replyPoolSize.
  *
  * @param[in]  channel configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
channel_getChannelReplyPoolSize( CosmOS_ChannelConfigurationType * channel )
{
    return ( BitWidthType )( channel->replyPoolSize );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn channel_getChannelSendPermission(CosmOS_ChannelConfigurationType *
  * channel)
  *
  * @brief Get sendPermission pointer.
  *
  * @param[in]  channel configuration pointer
  *
  * @return CosmOS_PermissionsConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_PermissionsConfigurationType *
channel_getChannelSendPermission( CosmOS_ChannelConfigurationType * channel )
{
    return (CosmOS_PermissionsConfigurationType *)( channel->sendPermission );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn channel_getChannelReplyPermission(CosmOS_ChannelConfigurationType *
  * channel)
  *
  * @brief Get replyPermission pointer.
  *
  * @param[in]  channel configuration pointer
  *
  * @return CosmOS_PermissionsConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_PermissionsConfigurationType *
channel_getChannelReplyPermission( CosmOS_ChannelConfigurationType * channel )
{
    return (CosmOS_PermissionsConfigurationType *)( channel->replyPermission );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn channel_getChannelSpinlockId(CosmOS_ChannelConfigurationType * channel)
  *
  * @brief Get channel spinlockId.
  *
  * @param[in]  channel configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
channel_getChannelSpinlockId( CosmOS_ChannelConfigurationType * channel )
{
    return ( BitWidthType )( channel->spinlockId );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn channel_getChannelReplyPoolSchedulableOwner(
  * CosmOS_ChannelConfigurationType * channel)
  *
  * @brief Get channel replyPoolSchedulableOwner.
  *
  * @param[in]  channel configuration pointer
  *
  * @return CosmOS_SchedulableConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_SchedulableConfigurationType *
channel_getChannelReplyPoolSchedulableOwner(
    CosmOS_ChannelConfigurationType * channel )
{
    return (
        CosmOS_SchedulableConfigurationType *)( channel
                                                    ->replyPoolSchedulableOwner );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn channel_getChannelInitialized(CosmOS_ChannelConfigurationType *
  * channel)
  *
  * @brief Get channel initialized.
  *
  * @param[in]  channel configuration pointer
  *
  * @return CosmOS_BooleanType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BooleanType
channel_getChannelInitialized( CosmOS_ChannelConfigurationType * channel )
{
    return ( CosmOS_BooleanType )( channel->var->initialized );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn channel_getChannelSendPoolState(CosmOS_ChannelConfigurationType *
  * channel)
  *
  * @brief Get channel sendPoolState.
  *
  * @param[in]  channel configuration pointer
  *
  * @return CosmOS_ChannelPoolStateType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_ChannelPoolStateType
channel_getChannelSendPoolState( CosmOS_ChannelConfigurationType * channel )
{
    return ( CosmOS_ChannelPoolStateType )( channel->var->sendPoolState );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn channel_getChannelSendPoolPayloadLength(CosmOS_ChannelConfigurationType
  * * channel)
  *
  * @brief Get channel sendPoolPayloadLength.
  *
  * @param[in]  channel configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
channel_getChannelSendPoolPayloadLength(
    CosmOS_ChannelConfigurationType * channel )
{
    return ( BitWidthType )( channel->var->sendPoolPayloadLength );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn channel_getChannelSendPoolSchedulableOwner(
  * CosmOS_ChannelConfigurationType * channel)
  *
  * @brief Get channel sendPoolSchedulableOwner.
  *
  * @param[in]  channel configuration pointer
  *
  * @return CosmOS_SchedulableConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_SchedulableConfigurationType *
channel_getChannelSendPoolSchedulableOwner(
    CosmOS_ChannelConfigurationType * channel )
{
    return (
        CosmOS_SchedulableConfigurationType *)( channel->var
                                                    ->sendPoolSchedulableOwner );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn channel_getChannelSenderWaitingForResponse(
  * CosmOS_ChannelConfigurationType * channel)
  *
  * @brief Get channel senderWaitingForResponse.
  *
  * @param[in]  channel configuration pointer
  *
  * @return CosmOS_BooleanType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BooleanType
channel_getChannelSenderWaitingForResponse(
    CosmOS_ChannelConfigurationType * channel )
{
    return ( CosmOS_BooleanType )( channel->var->senderWaitingForResponse );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn channel_getChannelReplyPoolState(CosmOS_ChannelConfigurationType *
  * channel)
  *
  * @brief Get channel replyPoolState.
  *
  * @param[in]  channel configuration pointer
  *
  * @return CosmOS_ChannelPoolStateType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_ChannelPoolStateType
channel_getChannelReplyPoolState( CosmOS_ChannelConfigurationType * channel )
{
    return ( CosmOS_ChannelPoolStateType )( channel->var->replyPoolState );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn channel_getChannelReplyPoolPayloadLength(CosmOS_ChannelConfigurationType
  * * channel)
  *
  * @brief Get channel replyPoolPayloadLength.
  *
  * @param[in]  channel configuration pointer
  *
  * @return BitWidthType
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType
channel_getChannelReplyPoolPayloadLength(
    CosmOS_ChannelConfigurationType * channel )
{
    return ( BitWidthType )( channel->var->replyPoolPayloadLength );
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/* Getters_channel_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_channel_h Setters
  * @ingroup Apis_channel_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn channel_setChannelSendPoolState(
  * CosmOS_ChannelConfigurationType * channel,
  * CosmOS_BooleanType initializedParam )
  *
  * @brief Set channel initialized.
  *
  * @param[out]  channel configuration pointer
  * @param[in]  initializedParam initialized value
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
channel_setChannelInitialized(
    CosmOS_ChannelConfigurationType * channel,
    CosmOS_BooleanType initializedParam )
{
    channel->var->initialized = initializedParam;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn channel_setChannelSendPoolState(
  * CosmOS_ChannelConfigurationType * channel,
  * CosmOS_ChannelPoolStateType sendPoolStateParam )
  *
  * @brief Set channel sendPoolState.
  *
  * @param[out]  channel configuration pointer
  * @param[in]  sendPoolStateParam send pool state
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
channel_setChannelSendPoolState(
    CosmOS_ChannelConfigurationType * channel,
    CosmOS_ChannelPoolStateType sendPoolStateParam )
{
    channel->var->sendPoolState = sendPoolStateParam;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn channel_setChannelSendPoolPayloadLength(
  * CosmOS_ChannelConfigurationType * channel,
  * BitWidthType sendPoolPayloadLengthParam  )
  *
  * @brief Set channel sendPoolPayloadLength.
  *
  * @param[out]  channel configuration pointer
  * @param[in]  sendPoolPayloadLengthParam send pool payload len
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
channel_setChannelSendPoolPayloadLength(
    CosmOS_ChannelConfigurationType * channel,
    BitWidthType sendPoolPayloadLengthParam )
{
    channel->var->sendPoolPayloadLength = sendPoolPayloadLengthParam;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn channel_setChannelSendPoolSchedulableOwner(
  * CosmOS_ChannelConfigurationType * channel,
  * CosmOS_SchedulableConfigurationType * sendPoolSchedulableOwnerParam )
  *
  * @brief Set channel sendPoolSchedulableOwner.
  *
  * @param[out]  channel configuration pointer
  * @param[in]  sendPoolSchedulableOwnerParam send pool owner
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
channel_setChannelSendPoolSchedulableOwner(
    CosmOS_ChannelConfigurationType * channel,
    CosmOS_SchedulableConfigurationType * sendPoolSchedulableOwnerParam )
{
    channel->var->sendPoolSchedulableOwner = sendPoolSchedulableOwnerParam;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn channel_setChannelSenderWaitingForResponse(
  * CosmOS_ChannelConfigurationType * channel,
  * CosmOS_BooleanType senderWaitingForResponseParam )
  *
  * @brief Set channel senderWaitingForResponse.
  *
  * @param[out]  channel configuration pointer
  * @param[in]  senderWaitingForResponseParam is sender waiting for the response
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
channel_setChannelSenderWaitingForResponse(
    CosmOS_ChannelConfigurationType * channel,
    CosmOS_BooleanType senderWaitingForResponseParam )
{
    channel->var->senderWaitingForResponse = senderWaitingForResponseParam;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn channel_setChannelReplyPoolState(
  * CosmOS_ChannelConfigurationType * channel,
  * CosmOS_ChannelPoolStateType replyPoolStateParam )
  *
  * @brief Set channel replyPoolState.
  *
  * @param[out]  channel configuration pointer
  * @param[in]  replyPoolStateParam reply pool state
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
channel_setChannelReplyPoolState(
    CosmOS_ChannelConfigurationType * channel,
    CosmOS_ChannelPoolStateType replyPoolStateParam )
{
    channel->var->replyPoolState = replyPoolStateParam;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn channel_setChannelReplyPoolPayloadLength(
  * CosmOS_ChannelConfigurationType * channel,
  * BitWidthType replyPoolPayloadLengthParam  )
  *
  * @brief Set channel replyPoolPayloadLength.
  *
  * @param[out]  channel configuration pointer
  * @param[in]  replyPoolPayloadLengthParam reply pool payload len
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
channel_setChannelReplyPoolPayloadLength(
    CosmOS_ChannelConfigurationType * channel,
    BitWidthType replyPoolPayloadLengthParam )
{
    channel->var->replyPoolPayloadLength = replyPoolPayloadLengthParam;
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/* Setters_channel_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_channel_h General
  * @ingroup Apis_channel_h
  * @{
********************************************************************************/

/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/* General_channel_h
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
