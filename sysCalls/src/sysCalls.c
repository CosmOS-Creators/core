/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file sysCalls.c
*********************************************************************************
<!--                   sysCalls Unit Local Group Definition                   -->
*********************************************************************************
** @defgroup Local_sysCalls Local
** @ingroup sysCalls_unit
** @brief sysCalls locals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "sysCalls.h"
#include "os.h"
#include "osBoot.h"
#include "osInit.h"

/* CIL interfaces */
#include "CILsysCalls.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_sysCalls Macros
  * @ingroup Local_sysCalls
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_sysCalls
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
  * @defgroup Variables_sysCalls Variables
  * @ingroup Local_sysCalls
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_sysCalls
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
  * @defgroup Apis_sysCalls_c API's
  * @ingroup Local_sysCalls
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_sysCalls_c Getters
  * @ingroup Apis_sysCalls_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_sysCalls_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_sysCalls_c Setters
  * @ingroup Apis_sysCalls_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_sysCalls_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_sysCalls_c General
  * @ingroup Apis_sysCalls_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_sysCalls_c
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
  * @fn sysCalls_bitWidthType_ret_void(BitWidthType id)
  *
  * @details The implementation contains calling the CIL function
  * CILsysCalls_bitWidthType_ret_void.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
sysCalls_bitWidthType_ret_void( BitWidthType id )
{
    CILsysCalls_bitWidthType_ret_void( id );
};
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn sysCalls_bitWidthType_ret_bitWidthType(BitWidthType id)
  *
  * @details The implementation contains calling the CIL function
  * CILsysCalls_bitWidthType_ret_bitWidthType and returning
  * the result.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION BitWidthType
sysCalls_bitWidthType_ret_bitWidthType( BitWidthType id )
{
    BitWidthType returnValue;

    returnValue = CILsysCalls_bitWidthType_ret_bitWidthType( id );

    return returnValue;
};
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn sysCalls_bitWidthType_bitWidthType_ret_bitWidthType(BitWidthType id,
  * BitWidthType arg)
  *
  * @details The implementation contains calling the CIL function
  * CILsysCalls_bitWidthType_bitWidthType_ret_bitWidthType and returning
  * the result.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION BitWidthType
sysCalls_bitWidthType_bitWidthType_ret_bitWidthType(
    BitWidthType id,
    BitWidthType arg )
{
    BitWidthType returnValue;

    returnValue =
        CILsysCalls_bitWidthType_bitWidthType_ret_bitWidthType( id, arg );

    return returnValue;
};
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn sysCalls_bitWidthType_voidPtr_bitWidthType_ret_bitWidthType(
  * BitWidthType id,
  * void * ptr,
  * BitWidthType arg)
  *
  * @details The implementation contains calling the CIL function
  * CILsysCalls_bitWidthType_voidPtr_bitWidthType_ret_bitWidthType and returning
  * the result.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION BitWidthType
sysCalls_bitWidthType_voidPtr_bitWidthType_ret_bitWidthType(
    BitWidthType id,
    void * ptr,
    BitWidthType arg )
{
    BitWidthType returnValue;

    returnValue = CILsysCalls_bitWidthType_voidPtr_bitWidthType_ret_bitWidthType(
        id, ptr, arg );

    return returnValue;
};
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn sysCalls_bitWidthType_voidPtr_bitWidthType_ret_bitWidthType(
  * BitWidthType id,
  * void * ptr,
  * BitWidthType arg)
  *
  * @details The implementation contains calling the CIL function
  * CILsysCalls_bitWidthType_voidPtr_ret_bitWidthType and returning the result.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION BitWidthType
sysCalls_bitWidthType_voidPtr_ret_bitWidthType( BitWidthType id, void * ptr )
{
    BitWidthType returnValue;

    returnValue = CILsysCalls_bitWidthType_voidPtr_ret_bitWidthType( id, ptr );

    return returnValue;
};
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/
/********************************************************************************
**                        Function Definitions | Stop                          **
********************************************************************************/
/********************************************************************************
**                           END OF THE SOURCE FILE                            **
********************************************************************************/
