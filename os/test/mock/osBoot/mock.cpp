#include <gmock/gmock.h>

#include "osBoot_mock.h"

#include "osBoot.h"

// instantiate mocked lib
std::unique_ptr<Os_MOCK> OsBoot_TestFixture::_OsBootMock;

// fake lib functions
void osBoot_bootValidate()
{
    Os_TestFixture::_OsMock->osBoot_bootValidate();

		return (NULL);
}
