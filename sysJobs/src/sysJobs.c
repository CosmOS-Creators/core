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
#include "core.h"
#include "sysJobs.h"
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
  * @}  
  * Macros_sysJobs  
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
  * @}  
  * Variables_sysJobs  
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
  * @}       
  * Getters_sysJobs_c
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
  * @}    
  * Setters_sysJobs_c   
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
  * @}
  * General_sysJobs_c  
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
  * @fn sysJobs(void) 
  * 
  * @brief System jobs DEMO FUNCTION.
  * 
  * @param[in]  none
  * 
  * @return none
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION void sysJobs(void)
{
    BitWidthType  sysJobsCurrentTick,
                  maxTickMultiplicator,
                  numOfGroups;

    CosmOS_CoreVariableType * coreVar;
    CosmOS_SysJobsVariableType * sysJobsVar;


    coreVar = core_getCoreVar();
    sysJobsVar = core_getCoreOsSysJobs( coreVar );

    sysJobsCurrentTick = sysJobs_getSysJobsCurrentTick( sysJobsVar );
    numOfGroups = sysJobs_getSysJobsNumOfGroups( sysJobsVar );

    for ( BitWidthType groupIterator = 0; groupIterator < numOfGroups; groupIterator++ )
    { 
        BitWidthType  groupTickMultiplicator;


        groupTickMultiplicator = sysJobs_getSysJobsGroupTickMultiplicator( sysJobsVar, groupIterator );

        if ( IS_NOT( groupTickMultiplicator ) )
        {   
            BitWidthType numOfHandlers;
            CosmOS_GenericVoidType * handlers;


            handlers = sysJobs_getSysJobsGroupHandlers( sysJobsVar, groupIterator );
            numOfHandlers = sysJobs_getSysJobsGroupNumOfHandlers( sysJobsVar, groupIterator );

            for ( BitWidthType handlerIterator = 0; handlerIterator < numOfHandlers; handlerIterator++ )
            {
                handlers[handlerIterator]();
            }
        }
        else
        {
            if ( IS_NOT( sysJobsCurrentTick % groupTickMultiplicator ) )
            {
                BitWidthType numOfHandlers;
                CosmOS_GenericVoidType * handlers;


                handlers = sysJobs_getSysJobsGroupHandlers( sysJobsVar, groupIterator );
                numOfHandlers = sysJobs_getSysJobsGroupNumOfHandlers( sysJobsVar, groupIterator );

                for ( BitWidthType handlerIterator = 0; handlerIterator < numOfHandlers; handlerIterator++ )
                {
                    handlers[handlerIterator]();
                }
            }
        }
    }

    maxTickMultiplicator = sysJobs_getSysJobsMaxTickMultiplicator( sysJobsVar );

    if ( maxTickMultiplicator )
    {
        sysJobsCurrentTick = ( ( sysJobsCurrentTick + 1 ) % maxTickMultiplicator );
        sysJobs_setSysJobsCurrentTick( sysJobsVar, sysJobsCurrentTick );
    }
};
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/
/********************************************************************************
**                        Function Definitions | Stop                          **
********************************************************************************/
/********************************************************************************
**                           END OF THE SOURCE FILE                            **
********************************************************************************/
