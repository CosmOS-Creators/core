#include "CppUTestExt/MockSupport.h"
#include "core.h"

CosmOS_CoreVariableType * core_getCoreVar()
{
    printf("\n core_getCoreVar called \n");

    mock().actualCall(__func__);

		return NULL;
}
