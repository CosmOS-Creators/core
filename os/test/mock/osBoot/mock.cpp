#include <gmock/gmock.h>
#include "osBoot.h"
#include "osBoot_mock.h"

std::unique_ptr<OsBoot_MOCK> OsBoot_TestFixture::_OsBootMock;

void
osBoot_bootValidate()
{
    OsBoot_TestFixture::_OsBootMock->osBoot_bootValidate();
}
