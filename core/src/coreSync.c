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
#include "os.h"
#include "core.h"
#include "coreSync.h"
#include "cosmosAssert.h"
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
  * @}
  * Macros_coreSync_c
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
  * @}
  * Variables_coreSync_c
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
  * @}
  * Getters_coreSync_c
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
  * @}
  * Setters_coreSync_c
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
  * @}
  * General_coreSync_c
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
  * @fn coreSync_getBarrier(CosmOS_CoreVariableType * coreVar, BitWidthType barrierId)
  *
  * @brief Set barrier with specific id for core X.
  *
  * @param[in]  CosmOS_CoreVariableType * coreVar
  * @param[in]  BitWidthType barrierId
  *
  * @return none
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION void coreSync_getBarrier(CosmOS_CoreVariableType * coreVar, BitWidthType barrierId)
{
	BitWidthType numberOfCores,
					numberOfSynchronizedCores;

	CosmOS_OsVariableType * osVar;
	CosmOS_BarrierVariableType * barrierVar;

	volatile CosmOS_BarrierStateType barrierState;


	barrierVar = core_getBarrierVar( coreVar, barrierId );
	coreSync_setBarrierState( barrierVar, BARRIER_STATE_ENUM__REACHED);

	/* MEMORY BARRIER HAS TO BE IMPLEMENTED */

	osVar = os_getOsVar();
	numberOfCores = os_getOsNumberOfCores( osVar );

	numberOfSynchronizedCores = 0;

	coreVar = os_getCoreVar( osVar, numberOfSynchronizedCores );
	barrierVar = core_getBarrierVar( coreVar, barrierId );

	while( numberOfSynchronizedCores IS_NOT_EQUAL_TO numberOfCores )
	{
		barrierState = coreSync_getBarrierState( barrierVar );

		if ( ( barrierState IS_EQUAL_TO BARRIER_STATE_ENUM__REACHED ) )
		{
			numberOfSynchronizedCores++;

			coreVar = os_getCoreVar( osVar, ( numberOfSynchronizedCores % numberOfCores ) );
			barrierVar = core_getBarrierVar( coreVar, barrierId );
		}
	}
}
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn coreSync_reactivateBarrier(CosmOS_CoreVariableType * coreVar, BitWidthType barrierId)
  *
  * @brief Reactivate barrier with specific barrierId for coreVar.
  *
  * @param[in]  CosmOS_CoreVariableType * coreVar
  * @param[in]  BitWidthType barrierId
  *
  * @return none
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION void coreSync_reactivateBarrier(CosmOS_CoreVariableType * coreVar, BitWidthType barrierId)
{
	CosmOS_BarrierVariableType * barrierVar;

	cosmosAssert( barrierId IS_EQUAL_TO SCHEDULERS_SYNC_ID );

	barrierVar = core_getBarrierVar( coreVar, barrierId );
	coreSync_setBarrierState( barrierVar, BARRIER_STATE_ENUM__ACTIVATED );

	/* MEMORY BARRIER HAS TO BE IMPLEMENTED */
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
