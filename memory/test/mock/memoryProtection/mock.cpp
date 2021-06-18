#include "CppUTestExt/MockSupport.h"
#include "memoryProtection.h"

void memoryProtection_init()
{
    printf("\nMemory Protection init called \n");

    mock().actualCall(__func__);
}
