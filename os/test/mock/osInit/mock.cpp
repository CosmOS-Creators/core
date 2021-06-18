#include "CppUTestExt/MockSupport.h"
#include "osInit.h"

void osInit_init()
{
    printf("\n Os init called \n");

    mock().actualCall(__func__);
}
