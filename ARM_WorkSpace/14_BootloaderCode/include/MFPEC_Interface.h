/*
 * MFPEC_Interface.h
 *
 *  Created on: Jul 12, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef MFPEC_INTERFACE_H_
#define MFPEC_INTERFACE_H_



void MFPEC_voidEraseAppArea(void) ;

void MFPEC_voidSectorErase   ( u8 Copy_u8SectorNumber ) ;

void MFPEC_voidFlashWrite( u32 Copy_u32Address , u16 * Copy_u16Data , u8 Copy_u8DataLength ) ;

#endif /* MFPEC_INTERFACE_H_ */
