/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file new.cpp
*********************************************************************************
<!--                      new Unit Local Group Definition                     -->
*********************************************************************************
** @defgroup Local_new Local
** @ingroup new_unit
** @brief new locals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "core.h"
#include "cosmosApi.h"
#include "os.h"
#include "stdlibInt.h"

/* CIL interfaces */
#include "CILcore.h"

/* LIB interfaces */
#include <stdlib.h>
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_new_c Macros
  * @ingroup Local_new
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_new_c
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Stop                           **
********************************************************************************/
/********************************************************************************
**                              Variables | Start                              **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Variables_new_c Variables
  * @ingroup Local_new
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_new_c
********************************************************************************/
/********************************************************************************
**                              Variables | Stop                               **
********************************************************************************/
/********************************************************************************
**                         Function Prototypes | Start                         **
********************************************************************************/
/********************************************************************************
  * DOXYGEN DEF GROUP                                                          **
  * *************************************************************************//**
  * @defgroup Apis_new_c API's
  * @ingroup Local_new
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_new_c Getters
  * @ingroup Apis_new_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_new_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_new_c Setters
  * @ingroup Apis_new_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_new_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_new_c General
  * @ingroup Apis_new_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_new_c
********************************************************************************/
/********************************************************************************
**                         Function Prototypes | Stop                          **
********************************************************************************/
/********************************************************************************
**                        Function Definitions | Start                         **
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn new(size_t size)
  *
  * @details The implementation contains if condition that checks if the size
  * argument is zero value and if it is the size is incremented by 1. Then
  * core id is obtained by calling cosmosApi_CILcore_getCoreId function as macro
  * and operating system variable by calling os_getOsCfg which are then used in
  * function os_getCoreCfg to get core variable. The function
  * core_getCoreOsState called afterwards returns the state of operating system
  * on the current core. The if condition then checks if the operating system
  * state is equal to OS_STATE_ENUM__STARTED, if yes the malloc_internal
  * function is called to allocate memory and the result is then returned as ptr
  * from the function. Otherwise the standard library function malloc is called
  * and the result is then returned as ptr from the function.
********************************************************************************/
void *
operator new( size_t size ) noexcept
{
    BitWidthType coreId;

    CosmOS_OsStateType osState;

    CosmOS_OsConfigurationType * osCfg;
    CosmOS_CoreConfigurationType * coreCfg;

    void * ptr;

    if ( IS_NOT( size ) )
    {
        ++size;
    }

    coreId = cosmosApi_CILcore_getCoreId();
    osCfg = os_getOsCfg();
    coreCfg = os_getCoreCfg( osCfg, coreId );
    osState = core_getCoreOsState( coreCfg );

    if ( osState IS_EQUAL_TO OS_STATE_ENUM__STARTED )
    {
        ptr = malloc_internal( size );
    }
    else
    {
        ptr = malloc( size );
    }

    return ptr;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn delete(void* ptr)
  *
  * @details The implementation contains calling cosmosApi_CILcore_getCoreId
  * function as macro and operating system variable by calling os_getOsCfg
  * which are then used in function os_getCoreCfg to get core variable.
  * The function core_getCoreOsState called afterwards returns the state of
  * operating system on the current core.
  * The if condition then checks if the operating system state is equal to
  * OS_STATE_ENUM__STARTED, if yes the free_internal function is called to
  * allocate memory and the result is then returned as ptr from the function.
  * Otherwise the standard library function free is called and the result is
  * then returned as ptr from the function.
********************************************************************************/
void
operator delete( void * ptr ) noexcept
{
    BitWidthType coreId;

    CosmOS_OsStateType osState;

    CosmOS_OsConfigurationType * osCfg;
    CosmOS_CoreConfigurationType * coreCfg;

    coreId = cosmosApi_CILcore_getCoreId();
    osCfg = os_getOsCfg();
    coreCfg = os_getCoreCfg( osCfg, coreId );
    osState = core_getCoreOsState( coreCfg );

    if ( osState IS_EQUAL_TO OS_STATE_ENUM__STARTED )
    {
        free_internal( ptr );
    }
    else
    {
        free( ptr );
    }
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn delete(void* ptr)
  *
  * @details The implementation contains calling cosmosApi_CILcore_getCoreId
  * function as macro and operating system variable by calling os_getOsCfg
  * which are then used in function os_getCoreCfg to get core variable.
  * The function core_getCoreOsState called afterwards returns the state of
  * operating system on the current core.
  * The if condition then checks if the operating system state is equal to
  * OS_STATE_ENUM__STARTED, if yes the free_internal function is called to
  * allocate memory and the result is then returned as ptr from the function.
  * Otherwise the standard library function free is called and the result is
  * then returned as ptr from the function.
********************************************************************************/
void
operator delete( void * ptr, size_t size ) noexcept
{
    BitWidthType coreId;

    CosmOS_OsStateType osState;

    CosmOS_OsConfigurationType * osCfg;
    CosmOS_CoreConfigurationType * coreCfg;

    coreId = cosmosApi_CILcore_getCoreId();
    osCfg = os_getOsCfg();
    coreCfg = os_getCoreCfg( osCfg, coreId );
    osState = core_getCoreOsState( coreCfg );

    if ( osState IS_EQUAL_TO OS_STATE_ENUM__STARTED )
    {
        free_internal( ptr );
    }
    else
    {
        free( ptr );
    }

    __SUPRESS_UNUSED_VAR( size );
}
/********************************************************************************
**                        Function Definitions | Stop                          **
********************************************************************************/
/********************************************************************************
**                           END OF THE SOURCE FILE                            **
********************************************************************************/
