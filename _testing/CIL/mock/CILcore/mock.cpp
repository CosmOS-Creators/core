#include <gmock/gmock.h>
#include "CILcore.h"
#include "CILcoreMock.h"

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

void
CILcore_systemReset( void )
{
    CILcore_TestFixture::_CILcoreMock->CILcore_systemReset();
}

CosmOS_BooleanType
CILcore_isInPrivilegedMode( void )
{
    return CILcore_TestFixture::_CILcoreMock->CILcore_isInPrivilegedMode();
}
