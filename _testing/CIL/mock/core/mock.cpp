#include "CppUTestExt/MockSupport.h"
#include "CILcore.h"

void CILcore_setCoreVar(CosmOS_OsVariableType * osVar)
{
    printf("\n CIL init called \n");

    mock().actualCall(__func__);
}
