/*******************************************************************************************************/
/* Author            : Ahmed khaled Hammad                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 29 June 2022                                                                    */
/* Description       : MFPEC_Interface.c --> implementations                                           */
/* Module  Features  :                                                                                 */
/*      01- MFPEC_voidEraseAppArea                                                                     */
/*      02- MFPEC_voidPageErase                                                                        */
/*      03- MFPEC_voidFlashWrite                                                                       */
/*******************************************************************************************************/

/*******************************************************************************************************/
/*	* What i sell To Customer                                                                          */
/*		*  The Archictect Give The API	                                                               */
/*						- The Name Of Function                                                         */
/*						- What is The Input                                                            */
/*						- What Is The Output                                                           */
/*						- Macro                                                                        */
/*******************************************************************************************************/

/*******************************************************************************************************/
/*                                   guard of file will call on time in .c                             */
/*******************************************************************************************************/

#ifndef MFPEC_INTERFACE_H_
#define MFPEC_INTERFACE_H_


void MFPEC_voidEraseAppArea(void);

void MFPEC_voidSectorErase   ( u8 Copy_u8SectorNumber );

void MFPEC_voidFlashWrite( u32 Copy_u32Address , u16 * Copy_u16Data , u8 Copy_u8DataLength );


#endif /* MFPEC_INTERFACE_H_ */
