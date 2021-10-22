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
** @defgroup Test_os Test
** @ingroup os_unit
** @brief os Tests
** @details lorem
** @version 1.0.0
** @date 10.22.2021
** @author collaborative
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
#include <gtest/gtest.h>
#include <future>
#include "core_mock.h"
#include "os.h"
#include "scheduler_mock.h"
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
* @defgroup Macros_os_ut_c Macros
* @ingroup Test_os
* @{
********************************************************************************/
#define TEST_DESCRIPTION( desc ) RecordProperty( "description", desc )

#define TEST_OS_START_EXECUTIONFLOW() TEST( Test_os, os_start_executionFlow )
#define TEST_OS_GETOSVAR_RETURNVALUE() TEST( Test_os, os_getOsVar_returnValue )
#define TEST_OS_KERNELPANIC_EXECUTIONFLOW() \
    TEST( Test_os, os_kernelPanic_executionFlow )

#define TEST_TIMEOUT_BEGIN                             \
    std::promise<bool> promisedFinished;               \
    auto futureResult = promisedFinished.get_future(); \
 std::thread([](std::promise<bool>& finished) {
#define TEST_TIMEOUT_FAIL_END( X )                                 \
    finished.set_value( true );                                    \
    } , std::ref(promisedFinished)).detach();                      \
    EXPECT_TRUE(                                                   \
        futureResult.wait_for( std::chrono::milliseconds( X ) ) != \
        std::future_status::timeout );
#define TEST_TIMEOUT_SUCCESS_END( X )                              \
    finished.set_value( true );                                    \
    }, std::ref(promisedFinished)).detach();                       \
    EXPECT_FALSE(                                                  \
        futureResult.wait_for( std::chrono::milliseconds( X ) ) != \
        std::future_status::timeout );
/********************************************************************************
* DOXYGEN STOP GROUP                                                           **
* ***************************************************************************//**
* @}
* Macros_os_ut_c
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
* @defgroup Variables_os_ut_c Variables
* @ingroup Test_os
* @{
********************************************************************************/
/********************************************************************************
* DOXYGEN STOP GROUP                                                           **
* ***************************************************************************//**
* @}
* Variables_os_ut_c
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
* @defgroup testcases_os_ut_c Testcases
* @ingroup Test_os
* @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief This test validates execution flow of the os_start function.
  *
  * @see os_start
  * @author https://github.com/PavolKostolansky
********************************************************************************/
TEST_OS_START_EXECUTIONFLOW()
{
    TEST_DESCRIPTION(
        "This test validates execution flow of the os_start function" );

    Scheduler_TestFixture schedulerMock;

    EXPECT_CALL( *schedulerMock._SchedulerMock, scheduler_start() ).Times( 1 );

    os_start( 0 );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief This test validates return value of the os_getOsVar function.
  *
  * @see os_getOsVar
  * @author https://github.com/florianL21
********************************************************************************/
TEST_OS_GETOSVAR_RETURNVALUE()
{
    TEST_DESCRIPTION(
        "This test validates return value of the os_getOsVar function" );

    CosmOS_OsVariableType * osVarRet;

    osVarRet = os_getOsVar();

    ASSERT_EQ( osVarRet, &OsVar );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief This test validates execution flow of the os_kernelPanic function.
  *
  * @see os_kernelPanic
  * @author https://github.com/PavolKostolansky
********************************************************************************/
TEST_OS_KERNELPANIC_EXECUTIONFLOW()
{
    TEST_DESCRIPTION(
        "This test validates execution flow of the os_kernelPanic function" );

    Core_TestFixture coreMock;
    UtCfg_TestFixture utCfgMock;

    EXPECT_CALL( *coreMock._CoreMock, core_getCoreVar() )
        .Times( 1 )
        .WillOnce( Return( &CoresVar[0] ) );
    EXPECT_CALL( *utCfgMock._UtCfgMock, dummyKernelPanic_core0() ).Times( 1 );

    TEST_TIMEOUT_BEGIN
    os_kernelPanic();
    TEST_TIMEOUT_SUCCESS_END( 1000 )
}
/********************************************************************************
* DOXYGEN STOP GROUP                                                           **
* ***************************************************************************//**
* @}
* testcases_os_ut_c
********************************************************************************/
/********************************************************************************
**                           Test Definitions | Stop                           **
********************************************************************************/
/********************************************************************************
**                           END OF THE SOURCE FILE                            **
********************************************************************************/
