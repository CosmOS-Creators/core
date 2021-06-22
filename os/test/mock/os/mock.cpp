#include <gmock/gmock.h>

#include "os_mock.h"

#include "os.h"

// instantiate mocked lib
std::unique_ptr<Os_MOCK> Os_TestFixture::_OsMock;

// fake lib functions
CosmOS_OsVariableType * os_getOsVar()
{
    Os_TestFixture::_OsMock->os_getOsVar();

		return (NULL);
}
