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
#include "cosmosAssert.h"
#include "osBootCfg.h"

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
  * @} */
/*  Macros_osBoot_c
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
  * @} */
/*  Variables_osBoot_c
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
  * @} */
/*  Getters_osBoot_c
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
  * @} */
/*  Setters_osBoot_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_osBoot_c General
  * @ingroup Apis_osBoot_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osBoot_clearSection( unsigned char * sectionStart,
  * unsigned char * sectionEnd )
  *
  * @brief Clear of the section.
  *
  * @param[out]  sectionStart
  * @param[out]  sectionEnd
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
osBoot_clearSection( unsigned char * sectionStart, unsigned char * sectionEnd );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osBoot_bootSection( unsigned char * sectionStart,
  * unsigned char * sectionEnd,
  * unsigned char * sectionStartInFlash)
  *
  * @brief Boot of the section.
  *
  * @param[out]  sectionStart
  * @param[out]  sectionEnd
  * @param[in]  sectionStartInFlash
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
osBoot_bootSection(
    unsigned char * sectionStart,
    unsigned char * sectionEnd,
    unsigned char * sectionStartInFlash );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osBoot_validateSection( unsigned char * sectionStart,
  * unsigned char * sectionEnd,
  * unsigned char * sectionStartInFlash)
  *
  * @brief Validation of the section.
  *
  * @param[out]  sectionStart
  * @param[out]  sectionEnd
  * @param[in]  sectionStartInFlash
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
osBoot_validateSection(
    unsigned char * sectionStart,
    unsigned char * sectionEnd,
    unsigned char * sectionStartInFlash );
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_osBoot_c
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
  * @fn osBoot_clearSection( unsigned char * sectionStart,
  * unsigned char * sectionEnd )
  *
  * @details The implementation contains clear for loop sequence where is the
  * destination memory filled out with zeroes.
********************************************************************************/
__STATIC_FORCEINLINE void
osBoot_clearSection( unsigned char * sectionStart, unsigned char * sectionEnd )
{
    BitWidthType size = ( BitWidthType )( sectionEnd - sectionStart );

    unsigned char * pDst = sectionStart;

    for ( BitWidthType i = 0; i < ( size * sizeof( unsigned char ) ); i++ )
    {
        *pDst++ = 0;
    }
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osBoot_bootSection( unsigned char * sectionStart,
  * unsigned char * sectionEnd,
  * unsigned char * sectionStartInFlash)
  *
  * @details The implementation contains boot for loop sequence where are all
  * data copied from the flash memory to the destination memory.
********************************************************************************/
__STATIC_FORCEINLINE void
osBoot_bootSection(
    unsigned char * sectionStart,
    unsigned char * sectionEnd,
    unsigned char * sectionStartInFlash )
{
    BitWidthType size = ( BitWidthType )( sectionEnd - sectionStart );

    unsigned char * pDst = sectionStart;
    unsigned char * pSrc = sectionStartInFlash;

    for ( BitWidthType i = 0; i < ( size * sizeof( unsigned char ) ); i++ )
    {
        *pDst++ = *pSrc++;
    }
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osBoot_validateSection( unsigned char * sectionStart,
  * unsigned char * sectionEnd,
  * unsigned char * sectionStartInFlash)
  *
  * @details The implementation contains validate for loop sequence where are all
  * data compared against flash memory and if there is mismatch operating system
  * assertion is triggered.
********************************************************************************/
__STATIC_FORCEINLINE void
osBoot_validateSection(
    unsigned char * sectionStart,
    unsigned char * sectionEnd,
    unsigned char * sectionStartInFlash )
{
    BitWidthType size = ( BitWidthType )( sectionEnd - sectionStart );

    unsigned char * pDst = sectionStart;
    unsigned char * pSrc = sectionStartInFlash;

    for ( BitWidthType i = 0; i < ( size * sizeof( unsigned char ) ); i++ )
    {
        cosmosAssert( (*pDst++)IS_EQUAL_TO( *pSrc++ ) );
    }
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osBoot_boot(void)
  *
  * @details The implementation contains call to get core id and then generated
  * clear sections are used to get specific addresses which are passed to the
  * osBoot_clearSection function to set program uninitialized data sections to
  * zeroes and after this generated boot sections are used to get specific
  * addresses which are passed to the osBoot_bootSection for booting initialized
  * data sections.
********************************************************************************/
void
osBoot_boot( void )
{
    BitWidthType coreId, bootSectionsNumber, clearSectionsNumber;

    CosmOS_ProgramSectionConfigurationType *bootProgramSections,
        *clearProgramSections;

    coreId = CILcore_getCoreId();

    clearProgramSections =
        (CosmOS_ProgramSectionConfigurationType *)clearSections[coreId]
            .programSections;
    clearSectionsNumber = clearSections[coreId].programSectionsNumber;

    for ( BitWidthType i = 0; i < clearSectionsNumber; i++ )
    {
        osBoot_clearSection(
            clearProgramSections[i].startAddress,
            clearProgramSections[i].endAddress );
    }

    bootProgramSections =
        (CosmOS_ProgramSectionConfigurationType *)bootSections[coreId]
            .programSections;
    bootSectionsNumber = bootSections[coreId].programSectionsNumber;

    for ( BitWidthType i = 0; i < bootSectionsNumber; i++ )
    {
        osBoot_bootSection(
            bootProgramSections[i].startAddress,
            bootProgramSections[i].endAddress,
            bootProgramSections[i].flashAddress );
    }
};

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn osBoot_bootValidate(void)
  *
  * @details The implementation contains call to get core id and then generated
  * boot sections are used to get specific addresses which are passed to the
  * osBoot_validateSection to validate it against the flash memory after MPU
  * activation.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
osBoot_bootValidate( void )
{
    BitWidthType coreId, programSectionsNumber;

    CosmOS_ProgramSectionConfigurationType * programSections;

    coreId = CILcore_getCoreId();

    programSections =
        (CosmOS_ProgramSectionConfigurationType *)bootSections[coreId]
            .programSections;
    programSectionsNumber = bootSections[coreId].programSectionsNumber;

    for ( BitWidthType i = 0; i < programSectionsNumber; i++ )
    {
        osBoot_validateSection(
            programSections[i].startAddress,
            programSections[i].endAddress,
            programSections[i].flashAddress );
    }
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
