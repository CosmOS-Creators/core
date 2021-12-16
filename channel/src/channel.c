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
#include "spinlock.h"
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
  * @fn osEvent_dispatchEvent( void )
  *
  * @details The implementation contains
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
channel_initialize( BitWidthType channelId ){

};
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

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
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
channel_sendConfigureChannelInternal(
    BitWidthType id,
    CosmOS_ChannelConfigurationType * channelCfg,
    AddressType * userReplyDataPool,
    BitWidthType userReplyDataPoolSize )
{
    CosmOS_SchedulableConfigurationType * replyPoolOwner;
    CosmOS_CoreConfigurationType * coreCfg;

    coreCfg = CILcore_getCoreCfg();

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

        CosmOS_BooleanType osEventHandleCore[CORE_NUM];

        for ( BitWidthType coreIt = 0; coreIt < CORE_NUM; coreIt++ )
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
            OS_EVENT_CHANNEL_SIGNALIZESERVER,
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
  * @fn osEvent_triggerEventInternal(
  * BitWidthType id,
  * CosmOS_BooleanType * handleCores,
  * BitWidthType event )
  *
  * @details The implementation contains
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
  * @fn channel_setChannelSendPoolPayloadLengthInternal(
  * BitWidthType id,
  * CosmOS_ChannelConfigurationType * channelCfg,
  * BitWidthType length )
  *
  * @details The implementation contains
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
channel_setChannelSendPoolPayloadLengthInternal(
    BitWidthType id,
    CosmOS_ChannelConfigurationType * channelCfg,
    BitWidthType length )
{
    channel_setChannelSendPoolPayloadLength( channelCfg, length );
};
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn channel_dataPoolCopyInternal(
  * BitWidthType id,
  * AddressType * data,
  * AddressType * dataPool,
  * BitWidthType size )
  *
  * @details The implementation contains
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
channel_dataPoolCopyInternal(
    BitWidthType id,
    AddressType * data,
    AddressType * dataPool,
    BitWidthType size )
{
    supportStdio_memcpy( dataPool, data, size );
};
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

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

                        if ( userSendDataPoolSize < sendPoolSize )
                        {
                            BitWidthType channelSpinlockId;

                            CosmOS_BooleanType channelConnected;
                            CosmOS_ChannelPoolStateType sendPoolState;

                            CosmOS_SpinlockStateType spinlockState;

                            channelSpinlockId =
                                channel_getChannelSpinlockId( channelCfg );

                            channelConnected = False;
                            do
                            {
                                spinlockState =
                                    spinlock_trySpinlock( channelSpinlockId );

                                sendPoolState = channel_getChannelSendPoolState(
                                    channelCfg );

                                if (
                                    sendPoolState IS_EQUAL_TO
                                        CHANNEL_POOL_STATE_ENUM__EMPTY AND
                                            spinlockState IS_EQUAL_TO
                                                SPINLOCK_STATE_ENUM__SUCCESSFULLY_LOCKED )
                                {
                                    AddressType * sendDataPool;

                                    channelConnected = True;

                                    sendDataPool = (AddressType *)
                                        channel_getChannelSendPool( channelCfg );

                                    CosmOS_BooleanType
                                        isChannelWatingForResponse;
                                    BitWidthType dataIndex = 0;

                                    cosmosApiInternal_channel_setChannelSendPoolPayloadLengthInternal(
                                        channelCfg, userSendDataPoolSize );

                                    while ( userSendDataPoolSize )
                                    {
                                        if ( userSendDataPoolSize >=
                                             SYCALL_BYTES_CHUNK )
                                        {
                                            cosmosApiInternal_channel_dataPoolCopyInternal(
                                                ( userSendDataPool + dataIndex ),
                                                sendDataPool,
                                                SYCALL_BYTES_CHUNK );
                                            dataIndex += SYCALL_BYTES_CHUNK;
                                            userSendDataPoolSize -=
                                                SYCALL_BYTES_CHUNK;
                                        }
                                        else
                                        {
                                            cosmosApiInternal_channel_dataPoolCopyInternal(
                                                ( userSendDataPool + dataIndex ),
                                                sendDataPool,
                                                userSendDataPoolSize );
                                            userSendDataPoolSize = 0;
                                        }
                                    }

                                    cosmosApiInternal_channel_sendConfigureChannelInternal(
                                        channelCfg,
                                        userReplyDataPool,
                                        userReplyDataPoolSize );

                                    spinlockState = spinlock_releaseSpinlock(
                                        channelSpinlockId );

                                    cosmosAssert(
                                        spinlockState IS_EQUAL_TO
                                            SPINLOCK_STATE_ENUM__RELEASED );

                                    isChannelWatingForResponse =
                                        channel_getChannelSenderWaitingForResponse(
                                            channelCfg );

                                    if ( isChannelWatingForResponse )
                                    {
                                        CosmOS_ChannelPoolStateType
                                            replyPoolState;

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

                                        replyDataPool = (AddressType *)
                                            channel_getChannelReplyPool(
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

                                            returnValue =
                                                CHANNEL_STATE_ENUM__RECEIVED;
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
                                        returnValue =
                                            CHANNEL_STATE_ENUM__NOT_RECEIVED;
                                    }
                                }
                            } while ( IS_NOT( channelConnected ) );
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
  * @fn osEvent_triggerEventInternal(
  * BitWidthType id,
  * CosmOS_BooleanType * handleCores,
  * BitWidthType event )
  *
  * @details The implementation contains
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
  * @fn osEvent_triggerEvent(
  * BitWidthType event,
  * CosmOS_BooleanType * handleCores,
  * AddressType * data,
  * BitWidthType size )
  *
  * @details The implementation contains
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
                    coreInPrivilegedMode = CILcore_isInPrivilegedMode();

                    if ( IS_NOT( coreInPrivilegedMode ) )
                    {
                        AddressType * sendDataPool;

                        CosmOS_ChannelPoolStateType sendPoolState;

                        sendPoolState =
                            channel_getChannelSendPoolState( channelCfg );

                        while (
                            sendPoolState IS_NOT_EQUAL_TO
                                CHANNEL_POOL_STATE_ENUM__WAITING_TO_BE_PROCESSED )
                        {
                            cosmosApiInternal_channel_receiveInternal(
                                channelCfg );
                            sendPoolState =
                                channel_getChannelSendPoolState( channelCfg );
                        }

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
  * @fn osEvent_triggerEventInternal(
  * BitWidthType id,
  * CosmOS_BooleanType * handleCores,
  * BitWidthType event )
  *
  * @details The implementation contains
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
channel_replyConfigureChannelInternal(
    BitWidthType id,
    CosmOS_ChannelConfigurationType * channelCfg )
{
    CosmOS_BooleanType isSenderWaitingPrioHigher;

    CosmOS_SchedulableConfigurationType * sendPoolOwner;
    CosmOS_ThreadConfigurationType * replyThreadCfg;
    CosmOS_ThreadConfigurationType * sendThreadCfg;
    CosmOS_CoreConfigurationType * coreCfg;

    coreCfg = CILcore_getCoreCfg();

    channel_setChannelReplyPoolState(
        channelCfg, CHANNEL_POOL_STATE_ENUM__WAITING_TO_BE_PROCESSED );

    sendPoolOwner = channel_getChannelSendPoolSchedulableOwner( channelCfg );
    if ( sendPoolOwner->coreId IS_EQUAL_TO coreCfg->coreId )
    {
        sendPoolOwner->var->state = SCHEDULABLE_STATE_ENUM__READY;

        replyThreadCfg = program_getProgramThread(
            (CosmOS_ProgramConfigurationType *)coreCfg->var->programInExecution,
            ( (CosmOS_SchedulableConfigurationType *)
                  coreCfg->var->schedulableInExecution )
                ->instanceId );

        sendThreadCfg = program_getProgramThread(
            (CosmOS_ProgramConfigurationType *)coreCfg->var->programInExecution,
            sendPoolOwner->instanceId );

        if ( replyThreadCfg->priority < sendThreadCfg->priority )
        {
            isSenderWaitingPrioHigher = True;
        }
    }
    else
    {
        CosmOS_ChannelEventType channelEvent;
        CosmOS_OsEventStateType osEventState;

        CosmOS_BooleanType osEventHandleCore[CORE_NUM];

        for ( BitWidthType coreIt = 0; coreIt < CORE_NUM; coreIt++ )
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
            OS_EVENT_CHANNEL_SIGNALIZECLIENT,
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
  * @fn channel_setChannelSendPoolPayloadLengthInternal(
  * BitWidthType id,
  * CosmOS_ChannelConfigurationType * channelCfg,
  * BitWidthType length )
  *
  * @details The implementation contains
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
channel_setChannelReplyPoolPayloadLengthInternal(
    BitWidthType id,
    CosmOS_ChannelConfigurationType * channelCfg,
    BitWidthType length )
{
    channel_setChannelReplyPoolPayloadLength( channelCfg, length );
};
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osEvent_dispatchEvent( void )
  *
  * @details The implementation contains
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

                            if ( userReplyDataPoolSize < replyPoolSize )
                            {
                                CosmOS_ChannelPoolStateType replyPoolState;

                                replyPoolState =
                                    channel_getChannelReplyPoolState(
                                        channelCfg );

                                while ( replyPoolState IS_NOT_EQUAL_TO
                                            CHANNEL_POOL_STATE_ENUM__EMPTY )
                                {
                                    replyPoolState =
                                        channel_getChannelReplyPoolState(
                                            channelCfg );
                                }

                                replyDataPool =
                                    (AddressType *)channel_getChannelReplyPool(
                                        channelCfg );

                                cosmosApiInternal_channel_setChannelReplyPoolPayloadLengthInternal(
                                    channelCfg, userReplyDataPoolSize );

                                dataIndex = 0;
                                while ( userReplyDataPoolSize )
                                {
                                    if ( userReplyDataPoolSize >=
                                         SYCALL_BYTES_CHUNK )
                                    {
                                        cosmosApiInternal_channel_dataPoolCopyInternal(
                                            ( userReplyDataPool + dataIndex ),
                                            replyDataPool,
                                            SYCALL_BYTES_CHUNK );
                                        dataIndex += SYCALL_BYTES_CHUNK;
                                        userReplyDataPoolSize -=
                                            SYCALL_BYTES_CHUNK;
                                    }
                                    else
                                    {
                                        cosmosApiInternal_channel_dataPoolCopyInternal(
                                            ( userReplyDataPool + dataIndex ),
                                            replyDataPool,
                                            userReplyDataPoolSize );
                                        userReplyDataPoolSize = 0;
                                    }
                                }

                                cosmosApiInternal_channel_replyConfigureChannelInternal(
                                    channelCfg );
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
  * @fn osEvent_dispatchEvent( void )
  *
  * @details The implementation contains
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
channel_signalizeServer( void ){

};
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osEvent_dispatchEvent( void )
  *
  * @details The implementation contains
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
channel_signalizeClient( void ){

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
