#include <gmock/gmock.h>

#include "coreSync_mock.h"

#include "coreSync.h"

// instantiate mocked lib
std::unique_ptr<CoreSync_MOCK> CoreSync_TestFixture::_CoreSyncMock;

// fake lib functions
void coreSync_getBarrier(CosmOS_CoreVariableType * coreVar, BitWidthType barrierId)
{
    CoreSync_TestFixture::_CoreSyncMock->coreSync_getBarrier(coreVar,barrierId);
}
