#include "utCfg.h"

const CosmOS_CoreConfigurationType CoresCfgConst[CORE_NUM]
IS_INITIALIZED_TO
{
	{
		/* CoresCfgConst[CORE_0_ID]                         */
		(CosmOS_ProgramConfigurationType *)NULL,	 /* const CosmOS_ProgramConfigurationType * programs    */
		2,																				 /* const BitWidthType numberOfPrograms              */
		(CosmOS_SchedulerConfigurationType *)NULL, /* CosmOS_SchedulerConfigurationType * scheduler       */
		0,																				 /* const BitWidthType coreId       */
		(CosmOS_GenericVoidType)NULL,							 /* const CosmOS_GenericVoidType kernelPanicHook   */
		200,																			 /* const AddressType stackMemoryLowAddress   */
		210,																			 /* const AddressType stackMemoryHighAddress   */
		300,																			 /* const AddressType codeMemoryLowAddress   */
		310,																			 /* const AddressType codeMemoryHighAddress   */
		400,		/* const AddressType unprotectedMemoryLowAddress   */
		500,		/* const AddressType unprotectedMemoryHighAddress   */
		10,		/* const BitWidthType msToTicks   */
		11,		/* const BitWidthType numberOfAlarms   */
	},
	{
		/* CoresCfgConst[CORE_0_ID]                         */
		(CosmOS_ProgramConfigurationType *)NULL,	 /* const CosmOS_ProgramConfigurationType * programs    */
		2,																				 /* const BitWidthType numberOfPrograms              */
		(CosmOS_SchedulerConfigurationType *)NULL, /* CosmOS_SchedulerConfigurationType * scheduler       */
		1,
		(CosmOS_GenericVoidType)NULL, /* const CosmOS_GenericVoidType kernelPanicHook   */
		200,													/* const AddressType stackMemoryLowAddress   */
		210,													/* const AddressType stackMemoryHighAddress   */
		300,													/* const AddressType codeMemoryLowAddress   */
		310,													/* const AddressType codeMemoryHighAddress   */
		400,		/* const AddressType unprotectedMemoryLowAddress   */
		500,		/* const AddressType unprotectedMemoryHighAddress   */
		10,		/* const BitWidthType msToTicks   */
		11,		/* const BitWidthType numberOfAlarms   */
	},
};

CosmOS_CoreVariableType CoresVar[CORE_NUM]
IS_INITIALIZED_TO
{
	{
		/* CoresVar[CORE_0_ID]                                  */
		&CoresCfgConst[CORE_0_ID],							/* const CosmOS_CoreConfigurationType *cfg                 */
		(CosmOS_SchedulableVariableType *)NULL, /* CosmOS_SchedulableVariableType * schedulableInExecution    */
		(CosmOS_ProgramVariableType *)NULL,			/* CosmOS_ProgramVariableType * programInCurrentContext       */
		(CosmOS_ProgramVariableType *)NULL,			/* CosmOS_ProgramVariableType * programVars                */
		(CosmOS_SchedulerVariableType *)NULL,		/* CosmOS_SchedulerVariableType * scheduler                */
		(CosmOS_BarrierVariableType *)NULL,			/* CosmOS_BarrierVariableType * barrierVars                */
		OS_STATE_ENUM__NOT_INITIALIZED,					/* CosmOS_OsStateType osState                                  */
		(CosmOS_SysJobsVariableType *)NULL,			/* CosmOS_SysJobsVariableType * const sysJobs               */
	},
	{
		/* CoresVar[CORE_1_ID]                                  */
		&CoresCfgConst[CORE_1_ID],							/* const CosmOS_CoreConfigurationType *cfg                 */
		(CosmOS_SchedulableVariableType *)NULL, /* CosmOS_SchedulableVariableType * schedulableInExecution    */
		(CosmOS_ProgramVariableType *)NULL,			/* CosmOS_ProgramVariableType * programInCurrentContext       */
		(CosmOS_ProgramVariableType *)NULL,			/* CosmOS_ProgramVariableType * programVars                */
		(CosmOS_SchedulerVariableType *)NULL,		/* CosmOS_SchedulerVariableType * scheduler                */
		(CosmOS_BarrierVariableType *)NULL,			/* CosmOS_BarrierVariableType * barrierVars                */
		OS_STATE_ENUM__NOT_INITIALIZED,					/* CosmOS_OsStateType osState                                  */
		(CosmOS_SysJobsVariableType *)NULL,			/* CosmOS_SysJobsVariableType * const sysJobs               */
	},
};
