/*******************************************************************************************************/
/* Author            : Ahmed khaled Hammad                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 29 June 2022                                                                    */
/* Description       : MFPEC_Program.c --> implementations                                             */
/* Module  Features  :                                                                                 */
/*      01- MFPEC_voidEraseAppArea                                                                     */
/*      02- MFPEC_voidPageErase                                                                        */
/*      03- MFPEC_voidFlashWrite                                                                       */
/*******************************************************************************************************/


/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      Standard Types LIB                                             */
/*******************************************************************************************************/

#include "LSTD_TYPES.h"
#include "LERROR_STATES.h"
#include "LBIT_MATH.h"


/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      MCAL Components                                                */
/*******************************************************************************************************/

#include "MFPEC_private.h"
#include "MFPEC_interface.h"
#include "MFPEC_config.h"

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      Functions Implementations                                      */
/*******************************************************************************************************/

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      01- MFPEC_voidEraseAppArea(void)                               */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description ->                                                                          */
/* 2- Function Input       ->                                                                          */
/*                                                                                                     */
/*                                                                                                     */
/*                                                                                                     */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MFPEC_voidEraseAppArea(void){

	u8 LOC_u8Iterator ;
	for ( LOC_u8Iterator = 6 ; LOC_u8Iterator < 64 ; LOC_u8Iterator++ ){

		MFPEC_voidPageErase( LOC_u8Iterator );

	}

}

/*******************************************************************************************************/
/*                                      02- MFPEC_voidPageErase(void)                                  */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description ->                                                                          */
/* 2- Function Input       ->                                                                          */
/*                                                                                                     */
/*                                                                                                     */
/*                                                                                                     */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MFPEC_voidSectorErase   ( u8 Copy_u8SectorNumber ){

	while( GET_BIT( MFPEC -> SR , 0 ) == 1 );

	if( GET_BIT( MFPEC -> CR , 7 ) == 1 ){

		MFPEC -> KEYR = 0x45670123 ;
		MFPEC -> KEYR = 0xCDEF89AB ;

	}

	SET_BIT( MFPEC -> CR , 1 );

	MFPEC -> CR &= SECTOR_MASK  ;
	MFPEC -> CR |=   Copy_u8SectorNumber<<3 ;
	SET_BIT( MFPEC -> CR , 6 );

	while( GET_BIT( MFPEC -> SR , 0 ) == 1 );

	SET_BIT( MFPEC -> SR , 5 );
	CLR_BIT( MFPEC -> CR , 1 );

}

/*******************************************************************************************************/
/*                                      03- MFPEC_voidFlashWrite(void)                                 */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description ->                                                                          */
/* 2- Function Input       ->                                                                          */
/*                                                                                                     */
/*                                                                                                     */
/*                                                                                                     */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MFPEC_voidFlashWrite( u32 Copy_u32Address , u16 * Copy_u16Data , u8 Copy_u8DataLength ){

	u8 LOC_u8Iterator ;

	while( GET_BIT( MFPEC -> SR , 0 ) == 1 );

	if( GET_BIT( MFPEC -> CR , 7 ) == 1 ){

		MFPEC -> KEYR = 0x45670123 ;
		MFPEC -> KEYR = 0xCDEF89AB ;

	}

	for( LOC_u8Iterator = 0 ; LOC_u8Iterator < Copy_u8DataLength ; LOC_u8Iterator++ ){

		SET_BIT( MFPEC -> CR , 0 );

		*( (volatile u16 *)Copy_u32Address ) = Copy_u16Data[ LOC_u8Iterator ] ;
		Copy_u32Address += 2 ;

		while( GET_BIT( MFPEC -> SR , 0 ) == 1 );

		SET_BIT( MFPEC -> SR , 5 );
		CLR_BIT( MFPEC -> CR , 0 );

	}

}
