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
    BitWidthType userReplyPoolSize )
{
    CosmOS_SchedulableConfigurationType * replyPoolOwner;
    CosmOS_ThreadConfigurationType * replyThreadCfg;
    CosmOS_ThreadConfigurationType * sendThreadCfg;
    CosmOS_CoreConfigurationType * coreCfg;

    coreCfg = CILcore_getCoreCfg();

    channel_setChannelSendPoolState(
        channelCfg, CHANNEL_POOL_STATE_ENUM__OCCUPIED );

    if ( userReplyPoolSize )
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

    replyPoolOwner = channel_getChannelReplyPoolSchedulableOwner( channelCfg );
    if ( replyPoolOwner->coreId IS_EQUAL_TO coreCfg->coreId )
    {
        replyPoolOwner->var->state = SCHEDULABLE_STATE_ENUM__READY;

        replyThreadCfg = program_getProgramThread(
            (CosmOS_ProgramConfigurationType *)coreCfg->var->programInExecution,
            replyPoolOwner->instanceId );

        sendThreadCfg = program_getProgramThread(
            (CosmOS_ProgramConfigurationType *)coreCfg->var->programInExecution,
            ( (CosmOS_SchedulableConfigurationType *)
                  coreCfg->var->schedulableInExecution )
                ->instanceId );

        if ( replyThreadCfg->priority > sendThreadCfg->priority )
        {
            CILinterrupt_contextSwitchRoutineTrigger();
        }
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
        channelCfg, CHANNEL_POOL_STATE_ENUM__OCCUPIED );
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
    BitWidthType userSendPoolSize,
    AddressType * userReplyDataPool,
    BitWidthType userReplyPoolSize )
{
    BitWidthType numberOfChannels, sendPoolSize;

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
                    sendPoolSize = channel_getChannelSendPoolSize( channelCfg );

                    if ( userSendPoolSize < sendPoolSize )
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
                                spinlock_getSpinlock( channelSpinlockId );

                            cosmosAssert(
                                spinlockState IS_EQUAL_TO
                                    SPINLOCK_STATE_ENUM__SUCCESSFULLY_LOCKED );

                            sendPoolState =
                                channel_getChannelSendPoolState( channelCfg );

                            if ( sendPoolState IS_EQUAL_TO
                                     CHANNEL_POOL_STATE_ENUM__READY )
                            {
                                AddressType * sendDataPool;

                                channelConnected = True;

                                coreInPrivilegedMode =
                                    CILcore_isInPrivilegedMode();

                                sendDataPool =
                                    (AddressType *)channel_getChannelSendPool(
                                        channelCfg );

                                if ( IS_NOT( coreInPrivilegedMode ) )
                                {
                                    CosmOS_BooleanType
                                        isChannelWatingForResponse;
                                    BitWidthType dataIndex = 0;

                                    cosmosApiInternal_channel_setChannelSendPoolPayloadLengthInternal(
                                        channelCfg, userSendPoolSize );

                                    while ( userSendPoolSize )
                                    {
                                        if ( userSendPoolSize >=
                                             SYCALL_BYTES_CHUNK )
                                        {
                                            cosmosApiInternal_channel_dataPoolCopyInternal(
                                                ( userSendDataPool + dataIndex ),
                                                sendDataPool,
                                                SYCALL_BYTES_CHUNK );
                                            dataIndex += SYCALL_BYTES_CHUNK;
                                            userSendPoolSize -=
                                                SYCALL_BYTES_CHUNK;
                                        }
                                        else
                                        {
                                            cosmosApiInternal_channel_dataPoolCopyInternal(
                                                ( userSendDataPool + dataIndex ),
                                                sendDataPool,
                                                userSendPoolSize );
                                            userSendPoolSize = 0;
                                        }
                                    }

                                    cosmosApiInternal_channel_sendConfigureChannelInternal(
                                        channelCfg,
                                        userReplyDataPool,
                                        userReplyPoolSize );

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
                                                CHANNEL_POOL_STATE_ENUM__OCCUPIED );

                                        replyDataPool = (AddressType *)
                                            channel_getChannelReplyPool(
                                                channelCfg );

                                        replyPoolPayloadSize =
                                            channel_getChannelReplyPoolPayloadLength(
                                                channelCfg );
                                        if ( userReplyPoolSize >=
                                             replyPoolPayloadSize )
                                        {
                                            supportStdio_memcpy(
                                                userReplyDataPool,
                                                replyDataPool,
                                                replyPoolPayloadSize );

                                            returnValue =
                                                CHANNEL_STATE_ENUM__REPLIED;
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
                                            CHANNEL_STATE_ENUM__NOT_REPLIED;
                                    }
                                }
                                else
                                {
                                    returnValue =
                                        CHANNEL_STATE_ENUM__ERROR_CAN_BE_CALLED_ONLY_FROM_UNPRIVILEGED;
                                }
                            }
                            spinlockState =
                                spinlock_releaseSpinlock( channelSpinlockId );

                            cosmosAssert( spinlockState IS_EQUAL_TO
                                              SPINLOCK_STATE_ENUM__RELEASED );
                        } while ( channelConnected );
                    }
                    else
                    {
                        returnValue =
                            CHANNEL_STATE_ENUM__ERROR_DATA_TO_SEND_BIGGER_THAN_POOL;
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
  * @fn osEvent_dispatchEvent( void )
  *
  * @details The implementation contains
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
channel_receive( void ){

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
channel_reply( void ){

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
