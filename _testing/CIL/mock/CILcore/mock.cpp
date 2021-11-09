#include <gmock/gmock.h>
#include "CILcore.h"
#include "CILcore_mock.h"

std::unique_ptr<CILcore_MOCK> CILcore_TestFixture::_CILcoreMock;

void
CILcore_setCoreCfg( CosmOS_OsConfigurationType * osCfg )
{
    CILcore_TestFixture::_CILcoreMock->CILcore_setCoreCfg( osCfg );
}

CosmOS_CoreConfigurationType *
CILcore_getCoreCfg( void )
{
    return CILcore_TestFixture::_CILcoreMock->CILcore_getCoreCfg();
}
