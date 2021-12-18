/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file coreSync.c
*********************************************************************************
<!--                  coreSync Unit Local Group Definition                    -->
*********************************************************************************
** @defgroup Local_coreSync Local
** @ingroup coreSync_unit
** @brief coreSync locals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "coreSync.h"
#include "core.h"
#include "cosmosAssert.h"
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
  * @defgroup Macros_coreSync_c Macros
  * @ingroup Local_coreSync
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_coreSync_c
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
  * @defgroup Variables_coreSync_c Variables
  * @ingroup Local_coreSync
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_coreSync_c
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
  * @defgroup Apis_coreSync_c API's
  * @ingroup Local_coreSync
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_coreSync_c Getters
  * @ingroup Apis_coreSync_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_coreSync_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_coreSync_c Setters
  * @ingroup Apis_coreSync_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_coreSync_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_coreSync_c General
  * @ingroup Apis_coreSync_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_coreSync_c
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
  * @fn coreSync_getBarrier(CosmOS_CoreConfigurationType * core,
  * BitWidthType barrierId)
  *
  * @details The implementation contains obtaining barier variable based on the
  * barrier id argument by the core_getBarrierVar function. Then the state of
  * this barrier variable is set to the BARRIER_STATE_ENUM__REACHED by the
  * coreSync_setBarrierState function.
  * Then we get operating system variable by calling os_getOsCfg function which
  * is later used in os_getOsNumberOfCores function call to get number of cores.
  * Number of synchronized cores is then set to zero and used to obtain the
  * first core configuration by calling os_getCore. Then the barrier variable
  * is obtained by calling core_getBarrierVar. In the implemented while loop we
  * iterate over the all cores and their barriers with specified barrier id.
  * The loop ends if there is only one core configured in the system or if
  * number of synchronized cores is equal to the number of cores.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
coreSync_getBarrier(
    CosmOS_CoreConfigurationType * core,
    BitWidthType barrierId )
{
    BitWidthType numberOfCores, numberOfSynchronizedCores;

    CosmOS_OsConfigurationType * osCfg;
    CosmOS_BarrierVariableType * barrierVar;

    volatile CosmOS_BarrierStateType barrierState;

    barrierVar = core_getBarrierVar( core, barrierId );
    coreSync_setBarrierState( barrierVar, BARRIER_STATE_ENUM__REACHED );

    /* MEMORY BARRIER HAS TO BE IMPLEMENTED */

    osCfg = os_getOsCfg();
    numberOfCores = os_getOsNumberOfCores( osCfg );

    numberOfSynchronizedCores = 0;

    core = os_getCore( osCfg, numberOfSynchronizedCores );
    barrierVar = core_getBarrierVar( core, barrierId );

    while ( numberOfCores AND numberOfSynchronizedCores IS_NOT_EQUAL_TO
                numberOfCores )
    {
        barrierState = coreSync_getBarrierState( barrierVar );

        if ( ( barrierState IS_EQUAL_TO BARRIER_STATE_ENUM__REACHED ) )
        {
            numberOfSynchronizedCores++;

            core = os_getCore(
                osCfg, ( numberOfSynchronizedCores % numberOfCores ) );
            barrierVar = core_getBarrierVar( core, barrierId );
        }
    }
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn coreSync_reactivateBarrier(CosmOS_CoreConfigurationType * core,
  * BitWidthType barrierId)
  *
  * @details The implementation contains reactivation of the scheduler
  * synchronization barriers which are the only barriers that can be currently
  * reactivated. Calling the cosmosAssert function to check if the barrierId
  * is equal to the SCHEDULERS_SYNC_ID and then obtaining barrier variable by
  * calling core_getBarrierVar with the barrier id and setting the barrier
  * variable state by calling coreSync_setBarrierState function with argument
  * BARRIER_STATE_ENUM__ACTIVATED. DEMO
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
coreSync_reactivateBarrier(
    CosmOS_CoreConfigurationType * core,
    BitWidthType barrierId )
{
    CosmOS_BarrierVariableType * barrierVar;

    cosmosAssert( barrierId IS_EQUAL_TO SCHEDULERS_SYNC_ID );

    barrierVar = core_getBarrierVar( core, barrierId );
    coreSync_setBarrierState( barrierVar, BARRIER_STATE_ENUM__ACTIVATED );

    /* MEMORY BARRIER HAS TO BE IMPLEMENTED */
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
