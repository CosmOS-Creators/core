/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file sysCalls.h
*********************************************************************************
<!--                     sysCalls Module Group Definition                     -->
*********************************************************************************
** @defgroup sysCalls_module sysCalls
** @brief sysCalls Module
** @details lorem
*********************************************************************************
<!--                      sysCalls Unit Group Definition                      -->
*********************************************************************************
** @defgroup sysCalls_unit sysCalls Unit
** @ingroup sysCalls_module
** @brief sysCalls Unit
** @details lorem
*********************************************************************************
<!--                           Version Information                            -->
*********************************************************************************
** @version 1.0.0
** @date 1.8.2020
** @author https://github.com/PavolKostolansky
*********************************************************************************
<!--                          Warnings and License                            -->
*********************************************************************************
** @warning Modifying code can lead to unexpected behaviour of the whole system
** @copyright MIT License
*********************************************************************************
<!--                   sysCalls Unit Global Group Definition                  -->
*********************************************************************************
** @defgroup Global_sysCalls Global
** @ingroup sysCalls_unit
** @brief sysCalls globals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __SYSCALLS_H__
#define __SYSCALLS_H__
/********************************************************************************
**                         START OF C++ SUPPORT SECTION                        **
********************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "cosmosTypes.h"
#include "memoryMapping.h"
#include "sysDefs.h"

/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_sysCalls_h Macros
  * @ingroup Global_sysCalls
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_sysCalls_h
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
  * @defgroup Variables_sysCalls_h Variables
  * @ingroup Global_sysCalls
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_sysCalls_h
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
  * @defgroup Apis_sysCalls_h API's
  * @ingroup Global_sysCalls
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_sysCalls_h Getters
  * @ingroup Apis_sysCalls_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_sysCalls_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_sysCalls_h Setters
  * @ingroup Apis_sysCalls_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_sysCalls_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_sysCalls_h General
  * @ingroup Apis_sysCalls_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn sysCalls_bitWidthType_ret_voidStart(void)
  *
  * @brief System call for bitWidthType args and return none.
  *
  * @param[in]  sysCallId is used during the system call dispatching
  * @param[in]  entityId is used as argument for the system call, if mapped to
  * @param[in]  sysCall is pointer to the function that will be called
  * @param[in]  argsArr array of arguments for the system call
  *
  * @return BitWidthType
********************************************************************************/
__OS_FUNC_SECTION BitWidthType
sysCalls_dispatcher(
    BitWidthType sysCallId,
    BitWidthType entityId,
    CosmOS_GenericVoidType sysCall,
    AddressType * argsArr );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn sysCalls_bitWidthType_ret_voidStart(void)
  *
  * @brief System call for bitWidthType args and return none.
  *
  * @param[in]  id is used during the system call dispatching
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void
sysCalls_bitWidthType_ret_void( BitWidthType id );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn sysCalls_bitWidthType_ret_bitWidthType(BitWidthType id)
  *
  * @brief System call for bitWidthType args and ret bitWidthType.
  *
  * @param[in]  id is used during the system call dispatching
  *
  * @return BitWidthType
********************************************************************************/
__OS_FUNC_SECTION BitWidthType
sysCalls_bitWidthType_ret_bitWidthType( BitWidthType id );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn sysCalls_bitWidthType_bitWidthType_ret_bitWidthType(
  * BitWidthType id, BitWidthType arg)
  *
  * @brief System call for bitWidthType args and ret bitWidthType.
  *
  * @param[in]  id is used during the system call dispatching
  * @param[in]  arg generic bitwidth type argument
  *
  * @return BitWidthType
********************************************************************************/
__OS_FUNC_SECTION BitWidthType
sysCalls_bitWidthType_bitWidthType_ret_bitWidthType(
    BitWidthType id,
    BitWidthType arg );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn sysCalls_bitWidthType_voidPtr_bitWidthType_ret_bitWidthType(
  * BitWidthType id, void * ptr, BitWidthType arg)
  *
  * @brief System call for voidPtr,bitWidthType args and ret bitWidthType.
  *
  * @param[in]  id is used during the system call dispatching
  * @param[in]  ptr void pointer to some address
  * @param[in]  arg generic bitwidth type argument
  *
  * @return BitWidthType
********************************************************************************/
__OS_FUNC_SECTION BitWidthType
sysCalls_bitWidthType_voidPtr_bitWidthType_ret_bitWidthType(
    BitWidthType id,
    void * ptr,
    BitWidthType arg );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn sysCalls_bitWidthType_voidPtr_bitWidthType_ret_bitWidthType(
  * BitWidthType id, void * ptr,BitWidthType arg)
  *
  * @brief System call for voidPtr and ret bitWidthType.
  *
  * @param[in]  id is used during the system call dispatching
  * @param[in]  ptr void pointer to some address
  *
  * @return BitWidthType
********************************************************************************/
__OS_FUNC_SECTION BitWidthType
sysCalls_bitWidthType_voidPtr_ret_bitWidthType( BitWidthType id, void * ptr );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn sysCalls_bitWidthType_voidPtr_voidPtr_bitWidthType_ret_bitWidthType(
  * BitWidthType id,
  * void * ptr,
  * void * ptr1,
  * BitWidthType arg)
  *
  * @brief System call for voidPtr,voidPtr,bitWidthType args and ret
  * bitWidthType.
  *
  * @param[in]  id is used during the system call dispatching
  * @param[in]  ptr void pointer to some address
  * @param[in]  ptr1 void pointer to some address
  * @param[in]  arg generic bitwidth type argument
  *
  * @return BitWidthType
********************************************************************************/
__OS_FUNC_SECTION BitWidthType
sysCalls_bitWidthType_voidPtr_voidPtr_bitWidthType_ret_bitWidthType(
    BitWidthType id,
    void * ptr,
    void * ptr1,
    BitWidthType arg );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn sysCalls_bitWidthType_voidPtr_bitWidthType_bitWidthType_ret_bitWidthType(
  * BitWidthType id,
  * void * ptr,
  * BitWidthType arg,
  * BitWidthType arg1)
  *
  * @brief System call for voidPtr,bitWidthType,bitWidthType args and ret
  * bitWidthType.
  *
  * @param[in]  id is used during the system call dispatching
  * @param[in]  ptr void pointer to some address
  * @param[in]  arg generic bitwidth type argument
  * @param[in]  arg1 generic bitwidth type argument
  *
  * @return BitWidthType
********************************************************************************/
__OS_FUNC_SECTION BitWidthType
sysCalls_bitWidthType_voidPtr_bitWidthType_bitWidthType_ret_bitWidthType(
    BitWidthType id,
    void * ptr,
    BitWidthType arg,
    BitWidthType arg1 );
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_sysCalls_h
********************************************************************************/
/********************************************************************************
**                         Function Prototypes | Stop                          **
********************************************************************************/
/********************************************************************************
**                        Function Definitions | Start                         **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_sysCalls_h Getters
  * @ingroup Apis_sysCalls_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_sysCalls_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_sysCalls_h Setters
  * @ingroup Apis_sysCalls_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_sysCalls_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_sysCalls_h General
  * @ingroup Apis_sysCalls_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_sysCalls_h
********************************************************************************/
/********************************************************************************
**                        Function Definitions | Stop                          **
********************************************************************************/
#ifdef __cplusplus
}
#endif
/********************************************************************************
**                         END OF C++ SUPPORT SECTION                          **
********************************************************************************/
#endif
/********************************************************************************
**                           END OF THE HEADER FILE                            **
********************************************************************************/
