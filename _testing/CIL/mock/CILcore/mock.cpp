#include <gmock/gmock.h>

#include "CILcore_mock.h"

#include "CILcore.h"

// instantiate mocked lib
std::unique_ptr<CILcore_MOCK> CILcore_TestFixture::_CILcoreMock;

// fake lib functions
void CILcore_setCoreVar(CosmOS_OsVariableType * osVar)
{
    CILcore_TestFixture::_CILcoreMock->CILcore_setCoreVar(osVar);
}
