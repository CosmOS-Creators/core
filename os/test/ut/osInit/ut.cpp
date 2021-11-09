/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file ut.cpp
*********************************************************************************
<!--                       os Unit Test Group Definition                      -->
*********************************************************************************
** @defgroup Test_osInit Test
** @ingroup osInit_unit
** @brief osInit Tests
** @details lorem
** @version 1.0.0
** @date 10.22.2021
** @author https://github.com/PavolKostolansky
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
#include <gtest/gtest.h>
#include "CILcore_mock.h"
#include "coreSync_mock.h"
#include "core_mock.h"
#include "memoryManager_mock.h"
#include "memoryProtection_mock.h"
#include "osBoot_mock.h"
#include "osInit.h"
#include "os_mock.h"
#include "utCfg.h"

/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
* DOXYGEN START GROUP                                                          **
* ***************************************************************************//**
* @defgroup Macros_osInit_ut_c Macros
* @ingroup Test_osInit
* @{
********************************************************************************/
#define TEST_DESCRIPTION( desc ) RecordProperty( "description", desc )

#define TEST_OSINIT_INIT_EXECUTIONFLOW() \
    TEST( Test_osInit, osInit_init_executionFlow )

/********************************************************************************
* DOXYGEN STOP GROUP                                                           **
* ***************************************************************************//**
  * @} */
/* Macros_osInit_ut_c
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Stop                           **
********************************************************************************/
/********************************************************************************
**                              Variables | Start                              **
********************************************************************************/
/********************************************************************************
* DOXYGEN START GROUP                                                          **
* ***************************************************************************//**
* @defgroup Variables_osInit_ut_c Variables
* @ingroup Test_osInit
* @{
********************************************************************************/
/********************************************************************************
* DOXYGEN STOP GROUP                                                           **
* ***************************************************************************//**
  * @} */
/* Variables_osInit_ut_c
********************************************************************************/
/********************************************************************************
**                              Variables | Stop                               **
********************************************************************************/
/********************************************************************************
**                           Test Definitions | Start                          **
********************************************************************************/
/********************************************************************************
* DOXYGEN START GROUP                                                          **
* ***************************************************************************//**
* @defgroup testcases_osInit_ut_c Testcases
* @ingroup Test_osInit
* @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @brief This test validates execution flow of the os_start function.
  *
  * @see osInit_init
  * @author https://github.com/PavolKostolansky
********************************************************************************/
TEST_OSINIT_INIT_EXECUTIONFLOW()
{
    TEST_DESCRIPTION(
        "This test validates execution flow of the os_start function" );

    MemoryProtection_TestFixture memoryProtectionMock;
    MemoryManager_TestFixture memoryManagerMock;
    CoreSync_TestFixture coreSyncMock;
    CILcore_TestFixture CILcoreMock;
    Core_TestFixture coreMock;
    Os_TestFixture osMock;
    OsBoot_TestFixture osBootMock;

    EXPECT_CALL( *osMock._OsMock, os_getOsCfg() )
        .Times( 1 )
        .WillOnce( Return( (CosmOS_OsConfigurationType *)NULL ) );
    EXPECT_CALL(
        *CILcoreMock._CILcoreMock,
        CILcore_setCoreCfg( (CosmOS_OsConfigurationType *)NULL ) )
        .Times( 1 );
    EXPECT_CALL( *coreMock._CoreMock, core_getCoreCfg() )
        .Times( 1 )
        .WillOnce( Return( &CoresCfgConst[0] ) );
    EXPECT_CALL(
        *memoryProtectionMock._MemoryProtectionMock,
        memoryProtection_init( 310, 300, 210, 200, 400, 500 ) )
        .Times( 1 );
    EXPECT_CALL( *osBootMock._OsBootMock, osBoot_bootValidate() ).Times( 1 );
    EXPECT_CALL(
        *memoryManagerMock._MemoryManagerMock,
        memoryManager_stackInit( &CoresCfgConst[0] ) )
        .Times( 1 );
    EXPECT_CALL(
        *memoryManagerMock._MemoryManagerMock,
        memoryManager_heapInit( &CoresCfgConst[0] ) )
        .Times( 1 );
    /* EXPECT_CALL(*coreSyncMock._CoreSyncMock,
    coreSync_getBarrier(&CoresCfgConst[0], OS_INIT_ID)).Times(1); */

    osInit_init( 0 );
}
/********************************************************************************
* DOXYGEN STOP GROUP                                                           **
* ***************************************************************************//**
  * @} */
/* testcases_osInit_ut_c
********************************************************************************/
/********************************************************************************
**                           Test Definitions | Stop                           **
********************************************************************************/
/********************************************************************************
**                           END OF THE SOURCE FILE                            **
********************************************************************************/
