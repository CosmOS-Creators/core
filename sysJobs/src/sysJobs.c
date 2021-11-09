/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file sysJobs.c
*********************************************************************************
<!--                    sysJobs Unit Local Group Definition                   -->
*********************************************************************************
** @defgroup Local_sysJobs Local
** @ingroup sysJobs_unit
** @brief sysJobs locals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "sysJobs.h"
#include "core.h"

/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_sysJobs Macros
  * @ingroup Local_sysJobs
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_sysJobs
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
  * @defgroup Variables_sysJobs Variables
  * @ingroup Local_sysJobs
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_sysJobs
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
  * @defgroup Apis_sysJobs_c API's
  * @ingroup Local_sysJobs
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_sysJobs_c Getters
  * @ingroup Apis_sysJobs_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_sysJobs_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_sysJobs_c Setters
  * @ingroup Apis_sysJobs_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_sysJobs_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_sysJobs_c General
  * @ingroup Apis_sysJobs_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_sysJobs_c
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
  * @fn sysJobs_dispatcher(BitWidthType entityId)
  *
  * @details The implementation contains obtaining of the core configuration by
  * calling core_getCoreCfg function and using it in the function
  * core_getCoreSysJobs to get system jobs variable for the current core.
  * As the system jobs have internal scheduling the function
  * sysJobs_getSysJobsCurrentTick is used to get its current internal tick.
  * The current tick is then incremented by 1. The number of system jobs groups
  * for the current core is obtained by calling sysJobs_getSysJobsNumOfGroups
  * function and for loop that iterates over all system jobs groups for current
  * core configuration implemented. For every system jobs group the group tick
  * multiplicator is obtained by sysJobs_getSysJobsGroupTickMultiplicator
  * function and then the if condition is implemented to check if the current
  * system jobs tick modulo group tick multiplicator is zero, otherwise the
  * group is skipped. If the result of modulo operation is zero, handlers are
  * obtained from the current system jobs group by calling function
  * sysJobs_getSysJobsGroupHandlers and also the number of handlers is obtained
  * by calling function sysJobs_getSysJobsGroupNumOfHandlers. Then nested for
  * loop is implemented that iterates over all handlers configured in the
  * current group and run them.
  * In the end the system jobs hypertick is obtained by calling function
  * sysJobs_getSysJobsHyperTick and used in modulo operation with the current
  * system jobs tick and the result is set to the current system jobs tick by
  * calling functio sysJobs_setSysJobsCurrentTick.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
sysJobs_dispatcher( BitWidthType entityId )
{
    BitWidthType sysJobsCurrentTick, hyperTick, numOfGroups;

    CosmOS_CoreConfigurationType * coreCfg;
    CosmOS_SysJobsConfigurationType * sysJobsCfg;

    coreCfg = core_getCoreCfg();
    sysJobsCfg = core_getCoreSysJobs( coreCfg );

    sysJobsCurrentTick = sysJobs_getSysJobsCurrentTick( sysJobsCfg );
    sysJobsCurrentTick++;

    numOfGroups = sysJobs_getSysJobsNumOfGroups( sysJobsCfg );

    for ( BitWidthType groupIterator = 0; groupIterator < numOfGroups;
          groupIterator++ )
    {
        BitWidthType groupTickMultiplicator;

        groupTickMultiplicator = sysJobs_getSysJobsGroupTickMultiplicator(
            sysJobsCfg, groupIterator );

        if ( IS_NOT( sysJobsCurrentTick % groupTickMultiplicator ) )
        {
            BitWidthType numOfHandlers;
            CosmOS_GenericVoidType * handlers;

            handlers =
                sysJobs_getSysJobsGroupHandlers( sysJobsCfg, groupIterator );
            numOfHandlers = sysJobs_getSysJobsGroupNumOfHandlers(
                sysJobsCfg, groupIterator );

            for ( BitWidthType handlerIterator = 0;
                  handlerIterator < numOfHandlers;
                  handlerIterator++ )
            {
                handlers[handlerIterator]();
            }
        }
    }

    hyperTick = sysJobs_getSysJobsHyperTick( sysJobsCfg );

    sysJobsCurrentTick = ( sysJobsCurrentTick % hyperTick );
    sysJobs_setSysJobsCurrentTick( sysJobsCfg, sysJobsCurrentTick );

    __SUPRESS_UNUSED_VAR( entityId );
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
