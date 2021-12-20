#include <gmock/gmock.h>
#include "sysCalls.h"
#include "sysCallsMock.h"

std::unique_ptr<SysCalls_MOCK> SysCalls_TestFixture::_SysCallsMock;

void
sysCalls_bitWidthType_ret_void( BitWidthType identifier )
{
    SysCalls_TestFixture::_SysCallsMock->sysCalls_bitWidthType_ret_void( identifier );
}
