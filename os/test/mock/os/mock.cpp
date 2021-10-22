#include <gmock/gmock.h>
#include "os.h"
#include "os_mock.h"

std::unique_ptr<Os_MOCK> Os_TestFixture::_OsMock;

CosmOS_OsVariableType *
os_getOsVar()
{
    Os_TestFixture::_OsMock->os_getOsVar();

    return ( NULL );
}
