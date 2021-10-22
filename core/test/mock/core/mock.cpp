#include <gmock/gmock.h>
#include "core.h"
#include "core_mock.h"

std::unique_ptr<Core_MOCK> Core_TestFixture::_CoreMock;

CosmOS_CoreVariableType *
core_getCoreVar()
{
    return Core_TestFixture::_CoreMock->core_getCoreVar();
}
