/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file channel.c
*********************************************************************************
<!--                   channel Unit Local Group Definition                    -->
*********************************************************************************
** @defgroup Local_channel Local
** @ingroup channel_unit
** @brief channel locals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "channel.h"
#include "core.h"
#include "cosmosApiInternal.h"
#include "cosmosAssert.h"
#include "os.h"
#include "osEvent.h"
#include "permission.h"
#include "program.h"
#include "semaphore.h"
#include "supportStdio.h"

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
  * @defgroup Macros_channel_c Macros
  * @ingroup Local_channel
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_channel_c
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
  * @defgroup Variables_channel_c Variables
  * @ingroup Local_channel
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_channel_c
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
* @defgroup Apis_channel_c API's
* @ingroup Local_channel
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_channel_c Getters
  * @ingroup Apis_channel_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_channel_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_channel_c Setters
  * @ingroup Apis_channel_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_channel_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_channel_c General
  * @ingroup Apis_channel_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_channel_c
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
  * @fn channel_initializeInternal(
  * BitWidthType id,
  * CosmOS_ChannelConfigurationType * channelCfg)
  *
  * @details The implementation contains calling channel_setChannelInitialized
  * function to set current channel configuration state to initialized.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
channel_initializeInternal(
    BitWidthType id,
    CosmOS_ChannelConfigurationType * channelCfg )
{
    channel_setChannelInitialized( channelCfg, True );
};
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn channel_initialize( BitWidthType channelId )
  *
  * @details The implementation contains obtaining of the operating system
  * configuration structure and also core configuration structure by calling
  * functions os_getOsCfg and CILcore_getCoreCfg. Operating system configuration
  * structure is then used to get number of the channels by calling function
  * os_getOsNumberOfChannels. Currently the channels support only threads and
  * therefore in the if condition is checked if the running schedulable is
  * thread type, otherwise CHANNEL_STATE_ENUM__ERROR_ONLY_THREADS_CAN_USE_CHANNEL
  * is returned from the function. The next point is check of the channelId
  * function argument, if the channelId is less than numberOfChannels it means
  * that user tries to initialize channel in the range of configured channels,
  * otherwise CHANNEL_STATE_ENUM__ERROR_INVALID_CHANNEL_ID is returned from the
  * function. Then the channel configuration structure is obtained by calling
  * os_getOsChannelCfg function and used to get isChannelInitialized state by
  * calling function channel_getChannelInitialized. If the channel is not
  * initialized we continue with initialization, otherwise function returns
  * CHANNEL_STATE_ENUM__ERROR_CHANNEL_ALREADY_INITIALIZED state. As the next step
  * the replyPermission are obtained by calling function
  * channel_getChannelReplyPermission because the channel is always initialized
  * by reply (server) thread. The reply permissions are then used to get the
  * access state by calling function permission_tryAccess. If the accessState is
  * equal to the ACCESS_STATE_ENUM__ALLOWED it means that the running thread is
  * the reply (server) thread of the current channel, otherwise the function
  * returns CHANNEL_STATE_ENUM__ERROR_ACCESS_DENIED. As the channels support
  * currently only threads running in the user space, the coreInPrivilegedMode
  * is obtained by calling function CILcore_isInPrivilegedMode. If the core
  * is not in privileged mode we can continue with the initialization, otherwise
  * the function returns
  * CHANNEL_STATE_ENUM__ERROR_CAN_BE_CALLED_ONLY_FROM_UNPRIVILEGED. After this
  * point we can finally call internal function mapped to the system call by
  * function as macro cosmosApiInternal_channel_initializeInternal and function
  * returns in this case CHANNEL_STATE_ENUM__INITIALIZED.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_ChannelStateType
channel_initialize( BitWidthType channelId )
{
    BitWidthType numberOfChannels;

    CosmOS_BooleanType coreInPrivilegedMode;

    CosmOS_ChannelStateType returnValue;

    CosmOS_OsConfigurationType * osCfg;
    CosmOS_CoreConfigurationType * coreCfg;

    osCfg = os_getOsCfg();

    coreCfg = CILcore_getCoreCfg();

    numberOfChannels = os_getOsNumberOfChannels( osCfg );

    if ( ( (CosmOS_SchedulableConfigurationType *)
               coreCfg->var->schedulableInExecution )
             ->instanceType IS_EQUAL_TO SCHEDULABLE_INSTANCE_ENUM__THREAD )
    {
        if ( channelId < numberOfChannels )
        {
            CosmOS_ChannelConfigurationType * channelCfg;
            channelCfg = os_getOsChannelCfg( osCfg, channelId );

            CosmOS_BooleanType isChannelInitialized;

            isChannelInitialized = channel_getChannelInitialized( channelCfg );

            if ( IS_NOT( isChannelInitialized ) )
            {
                CosmOS_AccessStateType accessState;
                CosmOS_PermissionsConfigurationType * replyPermission;

                replyPermission =
                    channel_getChannelReplyPermission( channelCfg );
                accessState = permission_tryAccess( replyPermission, coreCfg );

                if ( accessState IS_EQUAL_TO ACCESS_STATE_ENUM__ALLOWED )
                {
                    coreInPrivilegedMode = CILcore_isInPrivilegedMode();

                    if ( IS_NOT( coreInPrivilegedMode ) )
                    {
                        cosmosApiInternal_channel_initializeInternal(
                            channelCfg );
                        returnValue = CHANNEL_STATE_ENUM__INITIALIZED;
                    }
                    else
                    {
                        returnValue =
                            CHANNEL_STATE_ENUM__ERROR_CAN_BE_CALLED_ONLY_FROM_UNPRIVILEGED;
                    }
                }
                else
                {
                    returnValue = CHANNEL_STATE_ENUM__ERROR_ACCESS_DENIED;
                }
            }
            else
            {
                returnValue =
                    CHANNEL_STATE_ENUM__ERROR_CHANNEL_ALREADY_INITIALIZED;
            }
        }
        else
        {
            returnValue = CHANNEL_STATE_ENUM__ERROR_INVALID_CHANNEL_ID;
        }
    }
    else
    {
        returnValue = CHANNEL_STATE_ENUM__ERROR_ONLY_THREADS_CAN_USE_CHANNEL;
    }

    return returnValue;
};
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn channel_sendInternal(
  * BitWidthType id,
  * CosmOS_ChannelConfigurationType * channelCfg,
  * BitWidthType sendPoolPayloadLength,
  * BitWidthType userReplyDataPoolSize )
  *
  * @details The implementation contains obtaining of the operating system
  * configuration structure and also core configuration structure by calling
  * functions os_getOsCfg and CILcore_getCoreCfg. The sendPoolPayloadLength
  * function argument is then used to set the length of the send pool payload by
  * calling function channel_setChannelSendPoolPayloadLength. If the argument
  * userReplyDataPoolSize is non-zero value it means that sender waits also for
  * the reply. In that case we set the sender waiting for response value to true
  * by calling function channel_setChannelSenderWaitingForResponse and the
  * running schedulable as the send pool owner by calling function
  * channel_setChannelSendPoolSchedulableOwner. Then the state of the running
  * schedulable is set to the SCHEDULABLE_STATE_ENUM__WAITING_FOR_REPLY. If the
  * send thread is not waiting for the reply we set the sender waiting for
  * response value to false by calling function
  * channel_setChannelSenderWaitingForResponse. After this point the reply pool
  * owner is obtained by calling function
  * channel_getChannelReplyPoolSchedulableOwner. In the subsequent if condition
  * we check if the reply owner is running on the same core as the send thread,
  * if yes we can set its state to the SCHEDULABLE_STATE_ENUM__READY and we dont
  * have to call os event to signalize other core that the schedulable is again
  * ready to run and process the data sent by the send thread. Otherwise we have
  * to send os event. First of all we have to configure the array of event
  * handling cores, in our case we just set true the element in that array that
  * belongs to the core where the reply thread is running and leave all other
  * elements set to false. The data transferred by the os event contains just
  * CosmOS_ChannelEventType structure with the channel id set to the current
  * channel id. After this point the osEvent_triggerEvent is called with the
  * OS_EVENT_CHANNEL_SIGNALIZESEND parameter and assertion is called to check if
  * the os event state is OS_EVENT_STATE_ENUM__OK. In the end the if condition is
  * implemented that checks if the running thread is waiting for the reply and if
  * yes the reschedule is triggered by calling function
  * CILinterrupt_contextSwitchRoutineTrigger.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
channel_sendInternal(
    BitWidthType id,
    CosmOS_ChannelConfigurationType * channelCfg,
    BitWidthType sendPoolPayloadLength,
    BitWidthType userReplyDataPoolSize )
{
    CosmOS_SchedulableConfigurationType * replyPoolOwner;
    CosmOS_CoreConfigurationType * coreCfg;
    CosmOS_OsConfigurationType * osCfg;

    osCfg = os_getOsCfg();

    coreCfg = CILcore_getCoreCfg();

    channel_setChannelSendPoolPayloadLength( channelCfg, sendPoolPayloadLength );

    if ( userReplyDataPoolSize )
    {
        channel_setChannelSenderWaitingForResponse( channelCfg, True );
        channel_setChannelSendPoolSchedulableOwner(
            channelCfg,
            ( (CosmOS_SchedulableConfigurationType *)
                  coreCfg->var->schedulableInExecution ) );

        ( (CosmOS_SchedulableConfigurationType *)
              coreCfg->var->schedulableInExecution )
            ->var->state = SCHEDULABLE_STATE_ENUM__WAITING_FOR_REPLY;
    }
    else
    {
        channel_setChannelSenderWaitingForResponse( channelCfg, False );
    }

    channel_setChannelSendPoolState(
        channelCfg, CHANNEL_POOL_STATE_ENUM__WAITING_TO_BE_PROCESSED );

    replyPoolOwner = channel_getChannelReplyPoolSchedulableOwner( channelCfg );
    if ( replyPoolOwner->coreId IS_EQUAL_TO coreCfg->coreId )
    {
        replyPoolOwner->var->state = SCHEDULABLE_STATE_ENUM__READY;
    }
    else
    {
        CosmOS_ChannelEventType channelEvent;
        CosmOS_OsEventStateType osEventState;

        CosmOS_BooleanType osEventHandleCore[osCfg->numberOfCores];

        for ( BitWidthType coreIt = 0; coreIt < osCfg->numberOfCores; coreIt++ )
        {
            if ( replyPoolOwner->coreId IS_EQUAL_TO coreIt )
            {
                osEventHandleCore[coreIt] = True;
            }
            else
            {
                osEventHandleCore[coreIt] = False;
            }
        }

        channelEvent.channelId = channelCfg->id;

        osEventState = osEvent_triggerEvent(
            OS_EVENT_CHANNEL_SIGNALIZESEND,
            osEventHandleCore,
            (AddressType *)&channelEvent,
            sizeof( channelEvent ) );

        cosmosAssert( osEventState IS_EQUAL_TO OS_EVENT_STATE_ENUM__OK );
    }

    if ( userReplyDataPoolSize )
    {
        CILinterrupt_contextSwitchRoutineTrigger();
    }

    __SUPRESS_UNUSED_VAR( coreCfg );
};
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn channel_sendReplyObtainedInternal(
  * BitWidthType id,
  * CosmOS_ChannelConfigurationType * channelCfg)
  *
  * @details The implementation contains calling channel_setChannelReplyPoolState
  * function to set current channel configuration reply pool state to
  * CHANNEL_POOL_STATE_ENUM__EMPTY. This signalize the channel reply thread that
  * the reply pool can be used again and the sender successfully read all the
  * data.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
channel_sendReplyObtainedInternal(
    BitWidthType id,
    CosmOS_ChannelConfigurationType * channelCfg )
{
    channel_setChannelReplyPoolState(
        channelCfg, CHANNEL_POOL_STATE_ENUM__EMPTY );
};
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn channel_send(
  * BitWidthType channelId,
  * AddressType * userSendDataPool,
  * BitWidthType userSendPoolSize,
  * AddressType * userReplyDataPool,
  * BitWidthType userReplyPoolSize )
  *
  * @details The implementation contains obtaining of the operating system
  * configuration structure and also core configuration structure by calling
  * functions os_getOsCfg and CILcore_getCoreCfg. Operating system configuration
  * structure is then used to get number of the channels by calling function
  * os_getOsNumberOfChannels. Currently the channels support only threads and
  * therefore in the if condition is checked if the running schedulable is
  * thread type, otherwise CHANNEL_STATE_ENUM__ERROR_ONLY_THREADS_CAN_USE_CHANNEL
  * is returned from the function. The next point is check of the channelId
  * function argument, if the channelId is less than numberOfChannels it means
  * that user tries to use channel in the range of configured channels,
  * otherwise CHANNEL_STATE_ENUM__ERROR_INVALID_CHANNEL_ID is returned from the
  * function. Then the channel configuration structure is obtained by calling
  * os_getOsChannelCfg function and used to get isChannelInitialized state by
  * calling function channel_getChannelInitialized. If the channel is
  * initialized we continue in the send operation, otherwise function returns
  * CHANNEL_STATE_ENUM__ERROR_CHANNEL_NOT_INITIALIZED state. As the next step
  * the sendPermission are obtained by calling function
  * channel_getChannelSendPermission because the channel send function can be
  * called only by the configured send threads. The send permissions are then
  * used to get the access state by calling function permission_tryAccess.
  * If the accessState is equal to the ACCESS_STATE_ENUM__ALLOWED it means that
  * the running thread is the send (server) thread of the current channel,
  * otherwise the function returns CHANNEL_STATE_ENUM__ERROR_ACCESS_DENIED.
  * As the channels support currently only threads running in the user space,
  * the coreInPrivilegedMode is obtained by calling function
  * CILcore_isInPrivilegedMode. If the core is not in privileged mode we can
  * continue with the send operation, otherwise the function returns
  * CHANNEL_STATE_ENUM__ERROR_CAN_BE_CALLED_ONLY_FROM_UNPRIVILEGED. The next step
  * now is to get send pool size by calling channel_getChannelSendPoolSize
  * function. If the send pool size is more than userSendDataPoolSize function
  * argument we can continue in the send operation, otherwise the function
  * returns CHANNEL_STATE_ENUM__ERROR_DATA_TO_SEND_BIGGER_THAN_POOL. After this
  * point the channel semaphore id is obtained by calling function
  * channel_getChannelSemaphoreId. Here is one improvement
  * As the next point the local variable channelConnected is set to the False and
  * do-while loop is implemented where are the functions semaphore_getSemaphore
  * and channel_getChannelSendPoolState called to try to obtain semaphore for
  * exclusive access to the send pool, but the sendPoolState must be also equals
  * to the CHANNEL_POOL_STATE_ENUM__EMPTY to signalize that reply (server) thread
  * successfully read all the data and its ready to receive data again. If the
  * sendPoolState equals to the CHANNEL_POOL_STATE_ENUM__EMPTY the
  * send thread was successfully connected to the channel and can now send the
  * data and set the local variable channelConnected to the connected that
  * terminates the do-while loop. Next we have to get the sendPool address by
  * calling function channel_getChannelSendPool. As the core is not in the
  * privileged mode the while loop is implemented that writes bytes till the
  * userSendDataPoolSize is non-zero value. Inside this while loop is the if
  * condition implemented to check if the size to write is more than
  * SYCALL_BYTES_CHUNK, if yes only number of bytes defined by SYCALL_BYTES_CHUNK
  * is written to the send data pool to not block system by long too long system
  * call that is called by function as macro
  * cosmosApiInternal_supportStdio_memcpyInternal, the size to write is always
  * decremented by SYCALL_BYTES_CHUNK till its not smaller than
  * SYCALL_BYTES_CHUNK and then is the size set to zero and last bytes are
  * written to the send data pool. After all data are copied from the user space
  * to the channel send data pool in the operating system memory we can then call
  * the function as macro cosmosApiInternal_channel_sendInternal to configure
  * channel and signalize the reply thread that we sent a data. After
  * configurating the channel we can release the semaphore as we leave the
  * critical section by calling function semaphore_releaseSemaphore. The assertion
  * is then  called to check if the semaphore was successfully released.
  * The function channel_getChannelSenderWaitingForResponse is called to check
  * if the send thread is waiting for the response, if not the
  * CHANNEL_STATE_ENUM__NOT_RECEIVED state is returned by this function,
  * otherwise the do-while loop is implemented to wait till replyPoolState is
  * equal to the  CHANNEL_POOL_STATE_ENUM__WAITING_TO_BE_PROCESSED even though
  * the schedulable was in waiting state (blocked) and signalized, there can be
  * still delay till the reply pool contains the correct data and therefore we
  * wait in this do-while loop.
  * After this point the replyDataPool address and replyPoolPayloadSize are
  * obtained by calling the channel_getChannelReplyPool and
  * channel_getChannelReplyPoolPayloadLength functions. Then is checked if the
  * replyPoolPayloadSize is less or equal userReplyDataPoolSize, if yes we can
  * read the data from the replyDataPool by calling function supportStdio_memcpy,
  * then signalize the reply thread that we read all data from reply pool by
  * calling the function as macro
  * cosmosApiInternal_channel_sendReplyObtainedInternal and in the end return
  * CHANNEL_STATE_ENUM__RECEIVED state, otherwise function returns
  * the CHANNEL_STATE_ENUM__ERROR_DATA_TO_RECEIVE_BIGGER_THAN_POOL state.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_ChannelStateType
channel_send(
    BitWidthType channelId,
    AddressType * userSendDataPool,
    BitWidthType userSendDataPoolSize,
    AddressType * userReplyDataPool,
    BitWidthType userReplyDataPoolSize )
{
    BitWidthType numberOfChannels;

    CosmOS_ChannelStateType returnValue;

    CosmOS_OsConfigurationType * osCfg;
    CosmOS_CoreConfigurationType * coreCfg;

    osCfg = os_getOsCfg();

    coreCfg = CILcore_getCoreCfg();

    numberOfChannels = os_getOsNumberOfChannels( osCfg );

    if ( ( (CosmOS_SchedulableConfigurationType *)
               coreCfg->var->schedulableInExecution )
             ->instanceType IS_EQUAL_TO SCHEDULABLE_INSTANCE_ENUM__THREAD )
    {
        if ( channelId < numberOfChannels )
        {
            CosmOS_BooleanType isChannelInitialized;
            CosmOS_ChannelConfigurationType * channelCfg;
            channelCfg = os_getOsChannelCfg( osCfg, channelId );

            isChannelInitialized = channel_getChannelInitialized( channelCfg );

            if ( isChannelInitialized )
            {
                CosmOS_AccessStateType accessState;
                CosmOS_PermissionsConfigurationType * sendPermission;

                sendPermission = channel_getChannelSendPermission( channelCfg );
                accessState = permission_tryAccess( sendPermission, coreCfg );

                if ( accessState IS_EQUAL_TO ACCESS_STATE_ENUM__ALLOWED )
                {
                    CosmOS_BooleanType coreInPrivilegedMode;

                    coreInPrivilegedMode = CILcore_isInPrivilegedMode();

                    if ( IS_NOT( coreInPrivilegedMode ) )
                    {
                        BitWidthType sendPoolSize;

                        sendPoolSize =
                            channel_getChannelSendPoolSize( channelCfg );

                        if ( userSendDataPoolSize <= sendPoolSize )
                        {
                            BitWidthType channelSemaphoreId;

                            CosmOS_BooleanType channelConnected;
                            CosmOS_ChannelPoolStateType sendPoolState;

                            CosmOS_SemaphoreStateType semaphoreState;

                            channelSemaphoreId =
                                channel_getChannelSemaphoreId( channelCfg );

                            channelConnected = False;
                            do
                            {
                                semaphoreState =
                                    semaphore_getSemaphore( channelSemaphoreId );

                                cosmosAssert(
                                    semaphoreState IS_EQUAL_TO
                                        SEMAPHORE_STATE_ENUM__SUCCESSFULLY_LOCKED );

                                sendPoolState = channel_getChannelSendPoolState(
                                    channelCfg );

                                if ( sendPoolState IS_EQUAL_TO
                                         CHANNEL_POOL_STATE_ENUM__EMPTY )
                                {
                                    BitWidthType dataIndex;

                                    const BitWidthType sendPoolPayloadLength =
                                        userSendDataPoolSize;

                                    AddressType * sendDataPool;

                                    channelConnected = True;

                                    sendDataPool = (AddressType *)
                                        channel_getChannelSendPool( channelCfg );

                                    dataIndex = 0;
                                    while ( userSendDataPoolSize )
                                    {
                                        if ( userSendDataPoolSize >=
                                             SYCALL_BYTES_CHUNK )
                                        {
                                            cosmosApiInternal_supportStdio_memcpyInternal(
                                                ( userSendDataPool + dataIndex ),
                                                sendDataPool,
                                                SYCALL_BYTES_CHUNK );
                                            dataIndex += SYCALL_BYTES_CHUNK;
                                            userSendDataPoolSize -=
                                                SYCALL_BYTES_CHUNK;
                                        }
                                        else
                                        {
                                            cosmosApiInternal_supportStdio_memcpyInternal(
                                                ( userSendDataPool + dataIndex ),
                                                sendDataPool,
                                                userSendDataPoolSize );
                                            userSendDataPoolSize = 0;
                                        }
                                    }

                                    cosmosApiInternal_channel_sendInternal(
                                        channelCfg,
                                        sendPoolPayloadLength,
                                        userReplyDataPoolSize );
                                }

                                semaphoreState = semaphore_releaseSemaphore(
                                    channelSemaphoreId );

                                cosmosAssert(
                                    semaphoreState IS_EQUAL_TO
                                        SEMAPHORE_STATE_ENUM__RELEASED );

                            } while ( IS_NOT( channelConnected ) );

                            CosmOS_BooleanType isChannelWatingForResponse;

                            isChannelWatingForResponse =
                                channel_getChannelSenderWaitingForResponse(
                                    channelCfg );

                            if ( isChannelWatingForResponse )
                            {
                                CosmOS_ChannelPoolStateType replyPoolState;

                                AddressType * replyDataPool;
                                BitWidthType replyPoolPayloadSize;

                                do
                                {
                                    replyPoolState =
                                        channel_getChannelReplyPoolState(
                                            channelCfg );
                                } while (
                                    replyPoolState IS_NOT_EQUAL_TO
                                        CHANNEL_POOL_STATE_ENUM__WAITING_TO_BE_PROCESSED );

                                replyDataPool =
                                    (AddressType *)channel_getChannelReplyPool(
                                        channelCfg );

                                replyPoolPayloadSize =
                                    channel_getChannelReplyPoolPayloadLength(
                                        channelCfg );
                                if ( userReplyDataPoolSize >=
                                     replyPoolPayloadSize )
                                {
                                    supportStdio_memcpy(
                                        userReplyDataPool,
                                        replyDataPool,
                                        replyPoolPayloadSize );

                                    returnValue = CHANNEL_STATE_ENUM__RECEIVED;
                                }
                                else
                                {
                                    returnValue =
                                        CHANNEL_STATE_ENUM__ERROR_DATA_TO_RECEIVE_BIGGER_THAN_POOL;
                                }

                                cosmosApiInternal_channel_sendReplyObtainedInternal(
                                    channelCfg );
                            }
                            else
                            {
                                returnValue = CHANNEL_STATE_ENUM__NOT_RECEIVED;
                            }
                        }
                        else
                        {
                            returnValue =
                                CHANNEL_STATE_ENUM__ERROR_DATA_TO_SEND_BIGGER_THAN_POOL;
                        }
                    }
                    else
                    {
                        returnValue =
                            CHANNEL_STATE_ENUM__ERROR_CAN_BE_CALLED_ONLY_FROM_UNPRIVILEGED;
                    }
                }

                else
                {
                    returnValue = CHANNEL_STATE_ENUM__ERROR_ACCESS_DENIED;
                }
            }
            else
            {
                returnValue = CHANNEL_STATE_ENUM__ERROR_CHANNEL_NOT_INITIALIZED;
            }
        }
        else
        {
            returnValue = CHANNEL_STATE_ENUM__ERROR_INVALID_CHANNEL_ID;
        }
    }
    else
    {
        returnValue = CHANNEL_STATE_ENUM__ERROR_ONLY_THREADS_CAN_USE_CHANNEL;
    }

    return returnValue;
};
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn channel_receiveInternal(
  * BitWidthType id,
  * CosmOS_ChannelConfigurationType * channelCfg)
  *
  * @details The implementation contains obtaining of the reply pool owner by
  * calling channel_getChannelReplyPoolSchedulableOwner function, after this
  * point the replyPoolOwner state is set to SCHEDULABLE_STATE_ENUM__LISTENING
  * and channel send pool state to the CHANNEL_POOL_STATE_ENUM__EMPTY by
  * calling function channel_setChannelSendPoolState. This signalize eventual
  * send (client) threads that the reply (server) thread is able to process
  * data again. After this point the reschedule is triggered by calling
  * CILinterrupt_contextSwitchRoutineTrigger function as the thread is now
  * blocked till some data will be sent through the channel.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
channel_receiveInternal(
    BitWidthType id,
    CosmOS_ChannelConfigurationType * channelCfg )
{
    CosmOS_SchedulableConfigurationType * replyPoolOwner;

    replyPoolOwner = channel_getChannelReplyPoolSchedulableOwner( channelCfg );

    replyPoolOwner->var->state = SCHEDULABLE_STATE_ENUM__LISTENING;

    channel_setChannelSendPoolState(
        channelCfg, CHANNEL_POOL_STATE_ENUM__EMPTY );

    CILinterrupt_contextSwitchRoutineTrigger();
};
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn channel_receive(
  * BitWidthType channelId,
  * AddressType * userReceiveDataPool,
  * BitWidthType userReceiveDataPoolSize )
  *
  * @details The implementation contains obtaining of the operating system
  * configuration structure and also core configuration structure by calling
  * functions os_getOsCfg and CILcore_getCoreCfg. Operating system configuration
  * structure is then used to get number of the channels by calling function
  * os_getOsNumberOfChannels. Currently the channels support only threads and
  * therefore in the if condition is checked if the running schedulable is
  * thread type, otherwise CHANNEL_STATE_ENUM__ERROR_ONLY_THREADS_CAN_USE_CHANNEL
  * is returned from the function. The next point is check of the channelId
  * function argument, if the channelId is less than numberOfChannels it means
  * that user tries to use channel in the range of configured channels,
  * otherwise CHANNEL_STATE_ENUM__ERROR_INVALID_CHANNEL_ID is returned from the
  * function. Then the channel configuration structure is obtained by calling
  * os_getOsChannelCfg function and used to get isChannelInitialized state by
  * calling function channel_getChannelInitialized. If the channel is
  * initialized we continue in the reply operation, otherwise function returns
  * CHANNEL_STATE_ENUM__ERROR_CHANNEL_NOT_INITIALIZED state. As the next step
  * the replyPermission are obtained by calling function
  * channel_getChannelReplyPermission because the channel reply function can be
  * called only by the configured reply thread. The reply permissions are then
  * used to get the access state by calling function permission_tryAccess.
  * If the accessState is equal to the ACCESS_STATE_ENUM__ALLOWED it means that
  * the running thread is the reply (server) thread of the current channel,
  * otherwise the function returns CHANNEL_STATE_ENUM__ERROR_ACCESS_DENIED.
  * As the channels support currently only threads running in the user space,
  * the coreInPrivilegedMode is obtained by calling function
  * CILcore_isInPrivilegedMode. If the core is not in privileged mode we can
  * continue with the receive operation, otherwise the function returns
  * CHANNEL_STATE_ENUM__ERROR_CAN_BE_CALLED_ONLY_FROM_UNPRIVILEGED. After this
  * point the function as macro cosmosApiInternal_channel_receiveInternal is
  * called that configure the channel in such a way that send (client) threads
  * know they can send data again and put the running reply (server) thread's
  * schedulable that called this function in the
  * SCHEDULABLE_STATE_ENUM__LISTENING state (watiting state and schedulable is
  * blocked) till the sender thread will signalize that there is data to process
  * again. After unblocking calling thread we get the sendPoolState by calling
  * channel_getChannelSendPoolState function and check if the state is equal to
  * CHANNEL_POOL_STATE_ENUM__WAITING_TO_BE_PROCESSED in the assertion.
  * After this point the sendDataPool address and sendPoolPayloadLength are
  * obtained by calling the channel_getChannelSendPool and
  * channel_getChannelSendPoolPayloadLength functions. Then is checked if the
  * sendPoolPayloadLength is less or equal userReceiveDataPoolSize, if yes we can
  * read the data from the sendDataPool by calling function supportStdio_memcpy
  * and in the end return CHANNEL_STATE_ENUM__RECEIVED state, otherwise function
  * returns the CHANNEL_STATE_ENUM__ERROR_DATA_TO_RECEIVE_BIGGER_THAN_POOL state.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_ChannelStateType
channel_receive(
    BitWidthType channelId,
    AddressType * userReceiveDataPool,
    BitWidthType userReceiveDataPoolSize )
{
    BitWidthType numberOfChannels, sendPoolPayloadLength;

    CosmOS_BooleanType coreInPrivilegedMode;

    CosmOS_ChannelStateType returnValue;

    CosmOS_OsConfigurationType * osCfg;
    CosmOS_CoreConfigurationType * coreCfg;

    osCfg = os_getOsCfg();

    coreCfg = CILcore_getCoreCfg();

    numberOfChannels = os_getOsNumberOfChannels( osCfg );

    if ( ( (CosmOS_SchedulableConfigurationType *)
               coreCfg->var->schedulableInExecution )
             ->instanceType IS_EQUAL_TO SCHEDULABLE_INSTANCE_ENUM__THREAD )
    {
        if ( channelId < numberOfChannels )
        {
            CosmOS_BooleanType isChannelInitialized;
            CosmOS_ChannelConfigurationType * channelCfg;
            channelCfg = os_getOsChannelCfg( osCfg, channelId );

            isChannelInitialized = channel_getChannelInitialized( channelCfg );

            if ( isChannelInitialized )
            {
                CosmOS_AccessStateType accessState;
                CosmOS_PermissionsConfigurationType * replyPermission;

                replyPermission =
                    channel_getChannelReplyPermission( channelCfg );
                accessState = permission_tryAccess( replyPermission, coreCfg );

                if ( accessState IS_EQUAL_TO ACCESS_STATE_ENUM__ALLOWED )
                {
                    coreInPrivilegedMode = CILcore_isInPrivilegedMode();

                    if ( IS_NOT( coreInPrivilegedMode ) )
                    {
                        AddressType * sendDataPool;

                        CosmOS_ChannelPoolStateType sendPoolState;

                        cosmosApiInternal_channel_receiveInternal( channelCfg );

                        sendPoolState =
                            channel_getChannelSendPoolState( channelCfg );

                        cosmosAssert(
                            sendPoolState IS_EQUAL_TO
                                CHANNEL_POOL_STATE_ENUM__WAITING_TO_BE_PROCESSED );

                        sendDataPool = (AddressType *)channel_getChannelSendPool(
                            channelCfg );

                        sendPoolPayloadLength =
                            channel_getChannelSendPoolPayloadLength(
                                channelCfg );

                        if ( userReceiveDataPoolSize >= sendPoolPayloadLength )
                        {
                            supportStdio_memcpy(
                                userReceiveDataPool,
                                sendDataPool,
                                sendPoolPayloadLength );

                            returnValue = CHANNEL_STATE_ENUM__RECEIVED;
                        }
                        else
                        {
                            returnValue =
                                CHANNEL_STATE_ENUM__ERROR_DATA_TO_RECEIVE_BIGGER_THAN_POOL;
                        }
                    }
                    else
                    {
                        returnValue =
                            CHANNEL_STATE_ENUM__ERROR_CAN_BE_CALLED_ONLY_FROM_UNPRIVILEGED;
                    }
                }
                else
                {
                    returnValue = CHANNEL_STATE_ENUM__ERROR_ACCESS_DENIED;
                }
            }
            else
            {
                returnValue = CHANNEL_STATE_ENUM__ERROR_CHANNEL_NOT_INITIALIZED;
            }
        }
        else
        {
            returnValue = CHANNEL_STATE_ENUM__ERROR_INVALID_CHANNEL_ID;
        }
    }
    else
    {
        returnValue = CHANNEL_STATE_ENUM__ERROR_ONLY_THREADS_CAN_USE_CHANNEL;
    }

    return returnValue;
};
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn channel_replyInternal(
  * BitWidthType id,
  * CosmOS_ChannelConfigurationType * channelCfg,
  * BitWidthType replyPoolPayloadLength )
  *
  * @details The implementation contains obtaining of the operating system
  * configuration structure and also core configuration structure by calling
  * functions os_getOsCfg and CILcore_getCoreCfg. Then the reply pool payload
  * length is set by calling the channel_setChannelReplyPoolPayloadLength and
  * channel reply pool state to CHANNEL_POOL_STATE_ENUM__WAITING_TO_BE_PROCESSED
  * by calling function channel_setChannelReplyPoolState. In the subsequent if
  * condition we check if the send pool owner is running on the same core as the
  * reply thread, if yes we can set its state to the
  * SCHEDULABLE_STATE_ENUM__READY and we dont
  * have to call os event to signalize other core that the schedulable is again
  * ready to run and process the data sent by the reply thread. Instead of using
  * os event we get the send pool owner program by calling the function
  * core_getCoreProgramCfg that is used afterwards to get the send pool thread
  * configuration structure by calling the function program_getProgramThread. If
  * the priority of reply (currently running) thread is less than priority of the
  * send (client) thread the isSenderWaitingPrioHigher local variable is set to
  * True, else it is set to the False. If the send pool owner is notrunning on
  * the same core as the currently running reply thread we have to use reply
  * os event. First of all we have to configure the array of event
  * handling cores, in our case we just set true the element in that array that
  * belongs to the core where the send thread is running and leave all other
  * elements set to false. The data transferred by the os event contains just
  * CosmOS_ChannelEventType structure with the channel id set to the current
  * channel id. After this point the osEvent_triggerEvent is called with the
  * OS_EVENT_CHANNEL_SIGNALIZEREPLY parameter and assertion is called to check if
  * the os event state is OS_EVENT_STATE_ENUM__OK. In the end the if condition is
  * implemented that checks if isSenderWaitingPrioHigher is True, if yes the
  * reschedule is triggered by calling function
  * CILinterrupt_contextSwitchRoutineTrigger.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
channel_replyInternal(
    BitWidthType id,
    CosmOS_ChannelConfigurationType * channelCfg,
    BitWidthType replyPoolPayloadLength )
{
    CosmOS_BooleanType isSenderWaitingPrioHigher;

    CosmOS_ProgramConfigurationType * sendThreadProgram;
    CosmOS_SchedulableConfigurationType * sendPoolOwner;
    CosmOS_ThreadConfigurationType * replyThreadCfg;
    CosmOS_ThreadConfigurationType * sendThreadCfg;
    CosmOS_CoreConfigurationType * coreCfg;
    CosmOS_OsConfigurationType * osCfg;

    osCfg = os_getOsCfg();

    coreCfg = CILcore_getCoreCfg();

    channel_setChannelReplyPoolPayloadLength(
        channelCfg, replyPoolPayloadLength );

    channel_setChannelReplyPoolState(
        channelCfg, CHANNEL_POOL_STATE_ENUM__WAITING_TO_BE_PROCESSED );

    isSenderWaitingPrioHigher = False;
    sendPoolOwner = channel_getChannelSendPoolSchedulableOwner( channelCfg );
    if ( sendPoolOwner->coreId IS_EQUAL_TO coreCfg->coreId )
    {
        sendPoolOwner->var->state = SCHEDULABLE_STATE_ENUM__READY;

        sendThreadProgram =
            core_getCoreProgramCfg( coreCfg, sendPoolOwner->programId );

        replyThreadCfg = program_getProgramThread(
            (CosmOS_ProgramConfigurationType *)coreCfg->var->programInExecution,
            ( (CosmOS_SchedulableConfigurationType *)
                  coreCfg->var->schedulableInExecution )
                ->instanceId );

        sendThreadCfg = program_getProgramThread(
            sendThreadProgram, sendPoolOwner->instanceId );

        if ( replyThreadCfg->priority < sendThreadCfg->priority )
        {
            isSenderWaitingPrioHigher = True;
        }
        else
        {
            isSenderWaitingPrioHigher = False;
        }
    }
    else
    {
        CosmOS_ChannelEventType channelEvent;
        CosmOS_OsEventStateType osEventState;

        CosmOS_BooleanType osEventHandleCore[osCfg->numberOfCores];

        for ( BitWidthType coreIt = 0; coreIt < osCfg->numberOfCores; coreIt++ )
        {
            if ( sendPoolOwner->coreId IS_EQUAL_TO coreIt )
            {
                osEventHandleCore[coreIt] = True;
            }
            else
            {
                osEventHandleCore[coreIt] = False;
            }
        }

        channelEvent.channelId = channelCfg->id;

        osEventState = osEvent_triggerEvent(
            OS_EVENT_CHANNEL_SIGNALIZEREPLY,
            osEventHandleCore,
            (AddressType *)&channelEvent,
            sizeof( channelEvent ) );

        cosmosAssert( osEventState IS_EQUAL_TO OS_EVENT_STATE_ENUM__OK );
    }

    if ( isSenderWaitingPrioHigher )
    {
        CILinterrupt_contextSwitchRoutineTrigger();
    }
};
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn channel_reply(
  * BitWidthType channelId,
  * AddressType * userReplyDataPool,
  * BitWidthType userReplyDataPoolSize )
  *
  * @details The implementation contains obtaining of the operating system
  * configuration structure and also core configuration structure by calling
  * functions os_getOsCfg and CILcore_getCoreCfg. Operating system configuration
  * structure is then used to get number of the channels by calling function
  * os_getOsNumberOfChannels. Currently the channels support only threads and
  * therefore in the if condition is checked if the running schedulable is
  * thread type, otherwise CHANNEL_STATE_ENUM__ERROR_ONLY_THREADS_CAN_USE_CHANNEL
  * is returned from the function. The next point is check of the channelId
  * function argument, if the channelId is less than numberOfChannels it means
  * that user tries to use channel in the range of configured channels,
  * otherwise CHANNEL_STATE_ENUM__ERROR_INVALID_CHANNEL_ID is returned from the
  * function. Then the channel configuration structure is obtained by calling
  * os_getOsChannelCfg function and used to get isChannelInitialized state by
  * calling function channel_getChannelInitialized. If the channel is
  * initialized we continue in the reply operation, otherwise function returns
  * CHANNEL_STATE_ENUM__ERROR_CHANNEL_NOT_INITIALIZED state. As the next step
  * the replyPermission are obtained by calling function
  * channel_getChannelReplyPermission because the channel reply function can be
  * called only by the configured reply thread. The reply permissions are then
  * used to get the access state by calling function permission_tryAccess.
  * If the accessState is equal to the ACCESS_STATE_ENUM__ALLOWED it means that
  * the running thread is the reply (server) thread of the current channel,
  * otherwise the function returns CHANNEL_STATE_ENUM__ERROR_ACCESS_DENIED.
  * As the channels support currently only threads running in the user space,
  * the coreInPrivilegedMode is obtained by calling function
  * CILcore_isInPrivilegedMode. If the core is not in privileged mode we can
  * continue with the reply operation, otherwise the function returns
  * CHANNEL_STATE_ENUM__ERROR_CAN_BE_CALLED_ONLY_FROM_UNPRIVILEGED. The next step
  * now is to get reply pool size by calling channel_getChannelReplyPoolSize
  * function. If the reply pool size is more than userReplyDataPoolSize function
  * argument we can continue in the reply operation, otherwise the function
  * returns CHANNEL_STATE_ENUM__ERROR_DATA_TO_SEND_BIGGER_THAN_POOL. After this
  * point a do-while loop is implemented to check the replyPoolState by
  * calling function channel_getChannelReplyPoolState, till the reply pool state
  * is CHANNEL_POOL_STATE_ENUM__EMPTY. As the core is not in the
  * privileged mode the while loop is implemented that writes bytes till the
  * userReplyDataPoolSize is non-zero value. Inside this while loop is the if
  * condition implemented to check if the size to write is more than
  * SYCALL_BYTES_CHUNK, if yes only number of bytes defined by SYCALL_BYTES_CHUNK
  * is written to the reply data pool to not block system by long too long system
  * call that is called by function as macro
  * cosmosApiInternal_supportStdio_memcpyInternal, the size to write is always
  * decremented by SYCALL_BYTES_CHUNK till its not smaller than
  * SYCALL_BYTES_CHUNK and then is the size set to zero and last bytes are
  * written to the reply data pool. After all data are copied from the user space
  * to the channel reply data pool in the operating system memory we can then
  * call the function as macro cosmosApiInternal_channel_replyInternal to
  * configure channel and signalize the send thread that we replied and in the
  * end the CHANNEL_STATE_ENUM__REPLIED is returned by this function.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_ChannelStateType
channel_reply(
    BitWidthType channelId,
    AddressType * userReplyDataPool,
    BitWidthType userReplyDataPoolSize )
{
    BitWidthType numberOfChannels;

    CosmOS_BooleanType coreInPrivilegedMode;

    CosmOS_ChannelStateType returnValue;

    CosmOS_OsConfigurationType * osCfg;
    CosmOS_CoreConfigurationType * coreCfg;

    osCfg = os_getOsCfg();

    coreCfg = CILcore_getCoreCfg();

    numberOfChannels = os_getOsNumberOfChannels( osCfg );

    if ( ( (CosmOS_SchedulableConfigurationType *)
               coreCfg->var->schedulableInExecution )
             ->instanceType IS_EQUAL_TO SCHEDULABLE_INSTANCE_ENUM__THREAD )
    {
        if ( channelId < numberOfChannels )
        {
            CosmOS_ChannelConfigurationType * channelCfg;
            channelCfg = os_getOsChannelCfg( osCfg, channelId );

            CosmOS_BooleanType isChannelSenderWaitingForResponse;

            isChannelSenderWaitingForResponse =
                channel_getChannelSenderWaitingForResponse( channelCfg );

            if ( isChannelSenderWaitingForResponse )
            {
                CosmOS_BooleanType isChannelInitialized;

                isChannelInitialized =
                    channel_getChannelInitialized( channelCfg );

                if ( isChannelInitialized )
                {
                    CosmOS_AccessStateType accessState;
                    CosmOS_PermissionsConfigurationType * replyPermission;

                    replyPermission =
                        channel_getChannelReplyPermission( channelCfg );
                    accessState =
                        permission_tryAccess( replyPermission, coreCfg );

                    if ( accessState IS_EQUAL_TO ACCESS_STATE_ENUM__ALLOWED )
                    {
                        coreInPrivilegedMode = CILcore_isInPrivilegedMode();

                        if ( IS_NOT( coreInPrivilegedMode ) )
                        {
                            BitWidthType replyPoolSize;
                            BitWidthType dataIndex;

                            AddressType * replyDataPool;

                            replyPoolSize =
                                channel_getChannelReplyPoolSize( channelCfg );

                            if ( userReplyDataPoolSize <= replyPoolSize )
                            {
                                CosmOS_ChannelPoolStateType replyPoolState;
                                const BitWidthType replyPoolPayloadLength =
                                    userReplyDataPoolSize;

                                do
                                {
                                    replyPoolState =
                                        channel_getChannelReplyPoolState(
                                            channelCfg );

                                } while ( replyPoolState IS_NOT_EQUAL_TO
                                              CHANNEL_POOL_STATE_ENUM__EMPTY );

                                replyDataPool =
                                    (AddressType *)channel_getChannelReplyPool(
                                        channelCfg );

                                dataIndex = 0;
                                while ( userReplyDataPoolSize )
                                {
                                    if ( userReplyDataPoolSize >=
                                         SYCALL_BYTES_CHUNK )
                                    {
                                        cosmosApiInternal_supportStdio_memcpyInternal(
                                            ( userReplyDataPool + dataIndex ),
                                            replyDataPool,
                                            SYCALL_BYTES_CHUNK );
                                        dataIndex += SYCALL_BYTES_CHUNK;
                                        userReplyDataPoolSize -=
                                            SYCALL_BYTES_CHUNK;
                                    }
                                    else
                                    {
                                        cosmosApiInternal_supportStdio_memcpyInternal(
                                            ( userReplyDataPool + dataIndex ),
                                            replyDataPool,
                                            userReplyDataPoolSize );
                                        userReplyDataPoolSize = 0;
                                    }
                                }

                                cosmosApiInternal_channel_replyInternal(
                                    channelCfg, replyPoolPayloadLength );

                                returnValue = CHANNEL_STATE_ENUM__REPLIED;
                            }
                            else
                            {
                                returnValue =
                                    CHANNEL_STATE_ENUM__ERROR_DATA_TO_SEND_BIGGER_THAN_POOL;
                            }
                        }
                        else
                        {
                            returnValue =
                                CHANNEL_STATE_ENUM__ERROR_CAN_BE_CALLED_ONLY_FROM_UNPRIVILEGED;
                        }
                    }
                    else
                    {
                        returnValue = CHANNEL_STATE_ENUM__ERROR_ACCESS_DENIED;
                    }
                }
                else
                {
                    returnValue =
                        CHANNEL_STATE_ENUM__ERROR_CHANNEL_NOT_INITIALIZED;
                }
            }
            else
            {
                returnValue = CHANNEL_STATE_ENUM__ERROR_NO_REPLY_EXPECTED;
            }
        }
        else
        {
            returnValue = CHANNEL_STATE_ENUM__ERROR_INVALID_CHANNEL_ID;
        }
    }
    else
    {
        returnValue = CHANNEL_STATE_ENUM__ERROR_ONLY_THREADS_CAN_USE_CHANNEL;
    }

    return returnValue;
};
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn channel_signalizeReply(void)
  *
  * @details The implementation contains obtaining of the operating system
  * configuration structure and also core configuration structure by calling
  * functions os_getOsCfg and CILcore_getCoreCfg. Operating system configuration
  * structure is then used to get event configuration by calling function
  * os_getOsEventCfg. Os event configuration structure is used to get the event
  * data pool by calling function osEvent_getOsEventDataPool. The channel event
  * is then extracted from the os event data pool. To check if the channel id
  * stored in the os event data pool is correct we get the number of channels
  * by calling the os_getOsNumberOfChannels function and check it in the
  * assertion. Then the channel configuration is obtained by calling the function
  * os_getOsChannelCfg and used to get the send pool owner by calling the
  * channel_getChannelSendPoolSchedulableOwner function. Then the send pool owner
  * core id is checked in assertion (it has to be exactly the same as the current
  * core id). Send pool owner state is subsequently set to
  * SCHEDULABLE_STATE_ENUM__READY. After this point we have to obtain the send
  * pool owner program by calling the core_getCoreProgramCfg function that is
  * then used to get the send pool owner thread by calling function
  * program_getProgramThread. We need also the current running thread on the
  * core obtained by calling the function program_getProgramThread. If condition
  * is implemented to check if the running thread priority is less than the send
  * (client) thread priority, if yes the reschedule algorithm is triggered by
  * calling function CILinterrupt_contextSwitchRoutineTrigger.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
channel_signalizeReply( void )
{
    BitWidthType numberOfChannels;

    CosmOS_ProgramConfigurationType * sendThreadProgram;
    CosmOS_SchedulableConfigurationType * sendPoolOwner;
    CosmOS_ThreadConfigurationType * sendThreadCfg;
    CosmOS_ThreadConfigurationType * currentThreadCfg;
    CosmOS_CoreConfigurationType * coreCfg;
    CosmOS_OsConfigurationType * osCfg;
    CosmOS_OsEventConfigurationType * eventCfg;
    CosmOS_ChannelConfigurationType * channelCfg;

    osCfg = os_getOsCfg();
    coreCfg = CILcore_getCoreCfg();

    eventCfg = os_getOsEventCfg( osCfg );

    CosmOS_ChannelEventType * channelEvent =
        (CosmOS_ChannelEventType *)osEvent_getOsEventDataPool( eventCfg );

    numberOfChannels = os_getOsNumberOfChannels( osCfg );

    cosmosAssert( channelEvent->channelId < numberOfChannels );

    channelCfg = os_getOsChannelCfg( osCfg, channelEvent->channelId );

    sendPoolOwner = channel_getChannelSendPoolSchedulableOwner( channelCfg );

    cosmosAssert( sendPoolOwner->coreId IS_EQUAL_TO coreCfg->coreId );

    sendPoolOwner->var->state = SCHEDULABLE_STATE_ENUM__READY;

    sendThreadProgram =
        core_getCoreProgramCfg( coreCfg, sendPoolOwner->programId );

    sendThreadCfg =
        program_getProgramThread( sendThreadProgram, sendPoolOwner->instanceId );

    currentThreadCfg = program_getProgramThread(
        (CosmOS_ProgramConfigurationType *)coreCfg->var->programInExecution,
        ( (CosmOS_SchedulableConfigurationType *)
              coreCfg->var->schedulableInExecution )
            ->instanceId );

    if ( sendThreadCfg->priority > currentThreadCfg->priority )
    {
        CILinterrupt_contextSwitchRoutineTrigger();
    }
};
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn channel_signalizeSend(void)
  *
  * @details The implementation contains obtaining of the operating system
  * configuration structure and also core configuration structure by calling
  * functions os_getOsCfg and CILcore_getCoreCfg. Operating system configuration
  * structure is then used to get event configuration by calling function
  * os_getOsEventCfg. Os event configuration structure is used to get the event
  * data pool by calling function osEvent_getOsEventDataPool. The channel event
  * is then extracted from the os event data pool. To check if the channel id
  * stored in the os event data pool is correct we get the number of channels
  * by calling the os_getOsNumberOfChannels function and check it in the
  * assertion. Then the channel configuration is obtained by calling the function
  * os_getOsChannelCfg and used to get the reply pool owner by calling the
  * channel_getChannelSendPoolSchedulableOwner function. Then the reply pool
  * owner core id is checked in assertion (it has to be exactly the same as the
  * current core id). Send pool owner state is subsequently set to
  * SCHEDULABLE_STATE_ENUM__READY. After this point we have to obtain the reply
  * pool owner program by calling the core_getCoreProgramCfg function that is
  * then used to get the reply pool owner thread by calling function
  * program_getProgramThread. We need also the current running thread on the
  * core obtained by calling the function program_getProgramThread. If condition
  * is implemented to check if the running thread priority is less than the reply
  * (server) thread priority, if yes the reschedule algorithm is triggered by
  * calling function CILinterrupt_contextSwitchRoutineTrigger.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
channel_signalizeSend( void )
{
    BitWidthType numberOfChannels;

    CosmOS_ProgramConfigurationType * replyThreadProgram;
    CosmOS_SchedulableConfigurationType * replyPoolOwner;
    CosmOS_ThreadConfigurationType * replyThreadCfg;
    CosmOS_ThreadConfigurationType * currentThreadCfg;
    CosmOS_CoreConfigurationType * coreCfg;
    CosmOS_OsConfigurationType * osCfg;
    CosmOS_OsEventConfigurationType * eventCfg;
    CosmOS_ChannelConfigurationType * channelCfg;

    osCfg = os_getOsCfg();
    coreCfg = CILcore_getCoreCfg();

    eventCfg = os_getOsEventCfg( osCfg );

    CosmOS_ChannelEventType * channelEvent =
        (CosmOS_ChannelEventType *)osEvent_getOsEventDataPool( eventCfg );

    numberOfChannels = os_getOsNumberOfChannels( osCfg );

    cosmosAssert( channelEvent->channelId < numberOfChannels );

    channelCfg = os_getOsChannelCfg( osCfg, channelEvent->channelId );

    replyPoolOwner = channel_getChannelReplyPoolSchedulableOwner( channelCfg );

    cosmosAssert( replyPoolOwner->coreId IS_EQUAL_TO coreCfg->coreId );

    replyPoolOwner->var->state = SCHEDULABLE_STATE_ENUM__READY;

    replyThreadProgram =
        core_getCoreProgramCfg( coreCfg, replyPoolOwner->programId );

    replyThreadCfg = program_getProgramThread(
        replyThreadProgram, replyPoolOwner->instanceId );

    currentThreadCfg = program_getProgramThread(
        (CosmOS_ProgramConfigurationType *)coreCfg->var->programInExecution,
        ( (CosmOS_SchedulableConfigurationType *)
              coreCfg->var->schedulableInExecution )
            ->instanceId );

    if ( replyThreadCfg->priority > currentThreadCfg->priority )
    {
        CILinterrupt_contextSwitchRoutineTrigger();
    }
};
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/
/********************************************************************************
**                        Function Definitions | Stop                          **
********************************************************************************/
/********************************************************************************
**                           END OF THE SOURCE FILE                            **
********************************************************************************/
