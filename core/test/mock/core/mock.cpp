#include <gmock/gmock.h>
#include "core.h"
#include "coreMock.h"

std::unique_ptr<Core_MOCK> Core_TestFixture::_CoreMock;

CosmOS_CoreConfigurationType *
core_getCoreCfg()
{
    return Core_TestFixture::_CoreMock->core_getCoreCfg();
}
