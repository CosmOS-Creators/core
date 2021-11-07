#include <gmock/gmock.h>
#include "CILcore.h"
#include "CILcore_mock.h"

std::unique_ptr<CILcore_MOCK> CILcore_TestFixture::_CILcoreMock;

void
CILcore_setCoreCfg( CosmOS_OsVariableType * osVar )
{
    CILcore_TestFixture::_CILcoreMock->CILcore_setCoreCfg( osVar );
}

CosmOS_CoreVariableType *
CILcore_getCoreCfg( void )
{
    return CILcore_TestFixture::_CILcoreMock->CILcore_getCoreCfg();
}
