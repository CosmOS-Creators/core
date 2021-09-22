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
		dummyKernelPanic_core0,							 /* const CosmOS_GenericVoidType kernelPanicHook   */
		200,																			 /* const AddressType stackMemoryLowAddress   */
		210,																			 /* const AddressType stackMemoryHighAddress   */
		300,																			 /* const AddressType codeMemoryLowAddress   */
		310,																			 /* const AddressType codeMemoryHighAddress   */
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

const CosmOS_OsConfigurationType OsCfg
IS_INITIALIZED_TO
{                       /* osCfg                                        */
  (CosmOS_CoreConfigurationType*)NULL,      /* const CosmOS_CoreConfigurationType * cores      */
  2,           /* const BitWidthType numberOfCores             */
  (CosmOS_BufferConfigurationType*)NULL,    /* const CosmOS_BufferConfigurationType * buffers  */
  2,         /* const BitWidthType numberOfBuffers           */
  (CosmOS_RoutesConfigurationType *)NULL,    /* const CosmOS_RoutesConfigurationType route     */
	2,       /* const BitWidthType numberOfSpinlocks           */
};

CosmOS_OsVariableType OsVar
IS_INITIALIZED_TO
{                       /* osVar                                                      */
  &OsCfg,             /* const CosmOS_OsConfigurationType * cfg                     */
  (CosmOS_CoreVariableType*)NULL,           /* CosmOS_CoreVariableType * coreVars                         */
  (CosmOS_BufferVariableType*)NULL,         /* CosmOS_BufferVariableType * bufferVars                     */
  (CosmOS_BufferDoubleVariableType*)NULL,   /* CosmOS_BufferDoubleVariableType * const bufferDoubleVars   */
	(CosmOS_SpinlockVariableType*)NULL,   		/* CosmOS_SpinlockVariableType * const spinlockVars       */
};


// instantiate mocked lib
std::unique_ptr<UtCfg_MOCK> UtCfg_TestFixture::_UtCfgMock;

// fake lib functions
void dummyKernelPanic_core0()
{
    UtCfg_TestFixture::_UtCfgMock->dummyKernelPanic_core0();

}
