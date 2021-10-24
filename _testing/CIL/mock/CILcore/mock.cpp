#include <gmock/gmock.h>
#include "CILcore.h"
#include "CILcore_mock.h"

std::unique_ptr<CILcore_MOCK> CILcore_TestFixture::_CILcoreMock;

void
CILcore_setCoreVar( CosmOS_OsVariableType * osVar )
{
    CILcore_TestFixture::_CILcoreMock->CILcore_setCoreVar( osVar );
}

CosmOS_CoreVariableType *
CILcore_getCoreVar( void )
{
    return CILcore_TestFixture::_CILcoreMock->CILcore_getCoreVar();
}
