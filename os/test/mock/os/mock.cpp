#include <gmock/gmock.h>
#include "os.h"
#include "osMock.h"

std::unique_ptr<Os_MOCK> Os_TestFixture::_OsMock;

CosmOS_OsConfigurationType *
os_getOsCfg()
{
    Os_TestFixture::_OsMock->os_getOsCfg();

    return ( NULL );
}
