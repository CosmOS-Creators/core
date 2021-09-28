/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file osBoot.c
*********************************************************************************
<!--                   osBoot Unit Local Group Definition                     -->
*********************************************************************************
** @defgroup Local_osBoot Local
** @ingroup osBoot_unit
** @brief osBoot locals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "osBoot.h"
#include "osBootCfg.h"
#include "cosmosAssert.h"

/* CIL interfaces */
#include "CILcore.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_osBoot_c Macros
  * @ingroup Local_osBoot
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Macros_osBoot_c
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
  * @defgroup Variables_osBoot_c Variables
  * @ingroup Local_osBoot
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Variables_osBoot_c
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
  * @defgroup Apis_osBoot_c API's
  * @ingroup Local_osBoot
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_osBoot_c Getters
  * @ingroup Apis_osBoot_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Getters_osBoot_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_osBoot_c Setters
  * @ingroup Apis_osBoot_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Setters_osBoot_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_osBoot_c General
  * @ingroup Apis_osBoot_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_osBoot_c
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
  * @fn osBoot_bootSection( unsigned char * sectionStart, unsigned char * sectionEnd)
  *
  * @brief Boot of the section.
  *
  * @param[in]  unsigned char * sectionStart
  * @param[in]  unsigned char * sectionEnd
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void osBoot_clearSection( unsigned char * sectionStart, unsigned char * sectionEnd)
{
	BitWidthType size = (BitWidthType)(sectionEnd - sectionStart);

	unsigned char *pDst = sectionStart;

	for ( BitWidthType i = 0; i < (size * sizeof(unsigned char)); i++ )
	{
		*pDst++=0;
	}
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn osBoot_bootSection( unsigned char * sectionStart, unsigned char * sectionEnd, unsigned char * sectionStartInFlash)
  *
  * @brief Boot of the section.
  *
  * @param[in]  unsigned char * sectionStart
  * @param[in]  unsigned char * sectionEnd
  * @param[in]  unsigned char * sectionStartInFlash
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void osBoot_bootSection( unsigned char * sectionStart, unsigned char * sectionEnd, unsigned char * sectionStartInFlash)
{
	BitWidthType size = (BitWidthType)(sectionEnd - sectionStart);

	unsigned char *pDst = sectionStart;
	unsigned char *pSrc = sectionStartInFlash;

	for ( BitWidthType i = 0; i < (size * sizeof(unsigned char)); i++ )
	{
		*pDst++=*pSrc++;
	}
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn osBoot_boot(void)
  *
  * @brief Boot of operating system.
  *
  * @param[in]  none
  *
  * @return none
********************************************************************************/
void osBoot_boot(void)
{
    BitWidthType  coreId,
					bootSectionsNumber,
					clearSectionsNumber;

	CosmOS_ProgramSectionConfigurationType * bootProgramSections,
											*clearProgramSections;

	coreId = CILcore_getCoreId();

	clearProgramSections = (CosmOS_ProgramSectionConfigurationType *)clearSections[coreId].programSections;
	clearSectionsNumber = clearSections[coreId].programSectionsNumber;


	for (BitWidthType i=0; i < clearSectionsNumber; i++)
	{
		osBoot_clearSection(clearProgramSections[i].startAddress,clearProgramSections[i].endAddress);
	}

	bootProgramSections = (CosmOS_ProgramSectionConfigurationType *)bootSections[coreId].programSections;
	bootSectionsNumber = bootSections[coreId].programSectionsNumber;


	for (BitWidthType i=0; i < bootSectionsNumber; i++)
	{
		osBoot_bootSection(bootProgramSections[i].startAddress,bootProgramSections[i].endAddress,bootProgramSections[i].flashAddress);
	}
};

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn osBoot_validateSection( unsigned char * sectionStart, unsigned char * sectionEnd, unsigned char * sectionStartInFlash)
  *
  * @brief Validation of the section.
  *
  * @param[in]  unsigned char * sectionStart
  * @param[in]  unsigned char * sectionEnd
  * @param[in]  unsigned char * sectionStartInFlash
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void osBoot_validateSection( unsigned char * sectionStart, unsigned char * sectionEnd, unsigned char * sectionStartInFlash)
{
	BitWidthType size = (BitWidthType)(sectionEnd - sectionStart);

	unsigned char *pDst = sectionStart;
	unsigned char *pSrc = sectionStartInFlash;

	for ( BitWidthType i = 0; i < (size * sizeof(unsigned char)); i++ )
	{
		cosmosAssert( (*pDst++) IS_EQUAL_TO (*pSrc++) );
	}
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn osBoot_bootValidate(void)
  *
  * @brief Validation of operating system boot.
  *
  * @param[in]  none
  *
  * @return none
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION void osBoot_bootValidate(void)
{
	BitWidthType  coreId,
					programSectionsNumber;

	CosmOS_ProgramSectionConfigurationType * programSections;

	coreId = CILcore_getCoreId();

	programSections = (CosmOS_ProgramSectionConfigurationType *)bootSections[coreId].programSections;
	programSectionsNumber = bootSections[coreId].programSectionsNumber;


	for (BitWidthType i=0; i < programSectionsNumber; i++)
	{
		osBoot_validateSection(programSections[i].startAddress,programSections[i].endAddress,programSections[i].flashAddress);
	}
};
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/
/********************************************************************************
**                        Function Definitions | Stop                          **
********************************************************************************/
/********************************************************************************
**                           END OF THE SOURCE FILE                            **
********************************************************************************/
