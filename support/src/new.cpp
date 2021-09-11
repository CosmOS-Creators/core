/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file new.cpp
*********************************************************************************
<!--              	     new Unit Local Group Definition               		    -->
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
#include "cosmosApi.h"

/* LIB interfaces */
#include "stdlib.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
* DOXYGEN START GROUP                                                          **
* ***************************************************************************//**
* @defgroup Macros_new_c Macros
* @ingroup Local_new
* @{
********************************************************************************/
/********************************************************************************
* DOXYGEN STOP GROUP                                                           **
* ***************************************************************************//**
* @}
* Macros_new_c
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
* @defgroup Variables_new_c Variables
* @ingroup Local_new
* @{
********************************************************************************/
/********************************************************************************
* DOXYGEN STOP GROUP                                                           **
* ***************************************************************************//**
* @}
* Variables_new_c
********************************************************************************/
/********************************************************************************
**                              Variables | Stop                               **
********************************************************************************/
/********************************************************************************
**                         Function Prototypes | Start                         **
********************************************************************************/
/********************************************************************************
* DOXYGEN DEF GROUP                                                            **
* ***************************************************************************//**
* @defgroup Apis_new_c API's
* @ingroup Local_new
********************************************************************************/
/********************************************************************************
* DOXYGEN START GROUP                                                          **
* ***************************************************************************//**
* @addtogroup Getters_new_c Getters
* @ingroup Apis_new_c
* @{
********************************************************************************/
/********************************************************************************
* DOXYGEN STOP GROUP                                                           **
* ***************************************************************************//**
* @}
* Getters_new_c
********************************************************************************/
/********************************************************************************
* DOXYGEN START GROUP                                                          **
* ***************************************************************************//**
* @addtogroup Setters_new_c Setters
* @ingroup Apis_new_c
* @{
********************************************************************************/
/********************************************************************************
* DOXYGEN STOP GROUP                                                           **
* ***************************************************************************//**
* @}
* Setters_new_c
********************************************************************************/
/********************************************************************************
* DOXYGEN START GROUP                                                          **
* ***************************************************************************//**
* @addtogroup General_new_c General
* @ingroup Apis_new_c
* @{
********************************************************************************/
/********************************************************************************
* DOXYGEN STOP GROUP                                                           **
* ***************************************************************************//**
* @}
* General_new_c
********************************************************************************/
/********************************************************************************
**                         Function Prototypes | Stop                          **
********************************************************************************/
/********************************************************************************
**                        Function Definitions | Start                         **
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn new(size_t size)
  *
  * @brief NewLib new operator function implementation redesigned for CosmOS DEMO.
  *
  * @param[in]  size_t size
  *
  * @return void *
********************************************************************************/
void * operator new(size_t size) noexcept
{
	void *ptr;

	if ( IS_NOT( size ) )
	{
		++size;
	}

	ptr = malloc(size);

	return ptr;
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn delete(void* ptr)
  *
  * @brief NewLib delete operator function implementation redesigned for CosmOS DEMO.
  *
  * @param[in]  void * ptr
  *
  * @return none
********************************************************************************/
void operator delete(void* ptr) noexcept
{
	free(ptr);
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn delete(void* ptr)
  *
  * @brief NewLib delete operator function implementation redesigned for CosmOS DEMO.
  *
  * @param[in]  void * ptr
  * @param[in]  size_t size
	*
  * @return none
********************************************************************************/
void operator delete(void* ptr, size_t size) noexcept
{
	free(ptr);
	__SUPRESS_UNUSED_VAR(size);
}
/********************************************************************************
**                        Function Definitions | Stop                          **
********************************************************************************/
/********************************************************************************
**                           END OF THE SOURCE FILE                            **
********************************************************************************/