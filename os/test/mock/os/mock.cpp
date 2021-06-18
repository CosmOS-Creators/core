#include "CppUTestExt/MockSupport.h"
#include "os.h"

CosmOS_OsVariableType * os_getOsVar()
{
    printf("\n os_getOsVar called \n");

    mock().actualCall(__func__);

		return NULL;
}
