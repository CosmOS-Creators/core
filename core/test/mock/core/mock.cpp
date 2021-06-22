#include <gmock/gmock.h>

#include "core_mock.h"

#include "core.h"

// instantiate mocked lib
std::unique_ptr<Core_MOCK> Core_TestFixture::_CoreMock;

// fake lib functions
CosmOS_CoreVariableType * core_getCoreVar()
{
    Core_TestFixture::_CoreMock->core_getCoreVar();

		return (NULL);
}
