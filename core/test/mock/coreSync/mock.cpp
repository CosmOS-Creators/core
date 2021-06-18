#include "CppUTestExt/MockSupport.h"
#include "coreSync.h"

void coreSync_getBarrier(CosmOS_CoreVariableType * coreVar, BitWidthType barrierId)
{
    printf("\n coreSync_getBarrier called \n");

    mock().actualCall(__func__);
}
