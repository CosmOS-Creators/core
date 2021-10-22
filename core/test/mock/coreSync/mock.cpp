#include <gmock/gmock.h>
#include "coreSync.h"
#include "coreSync_mock.h"

std::unique_ptr<CoreSync_MOCK> CoreSync_TestFixture::_CoreSyncMock;

void
coreSync_getBarrier( CosmOS_CoreVariableType * coreVar, BitWidthType barrierId )
{
    CoreSync_TestFixture::_CoreSyncMock->coreSync_getBarrier(
        coreVar, barrierId );
}
