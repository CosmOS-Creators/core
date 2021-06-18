#include "CppUTestExt/MockSupport.h"
#include "stackInit.h"

void stackInit_init(CosmOS_CoreVariableType * coreVar)
{
    printf("\n stackInit_initcalled \n");

    mock().actualCall(__func__);
}
