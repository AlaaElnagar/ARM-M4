/*******************************************************************************************************/
/* Author            : Ahmed khaled Hammad                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 23 May 2022                                                                     */
/* Description       : MSTK_Interface.c --> implementations                                           */
/* Module  Features  :                                                                                 */
/*      01- MSTK_voidInit                                                                              */
/*      02- MSTK_voidStart                                                                             */
/*      03- MSTK_voidINTStatus                                                                         */
/*      04- MSTK_u8ReadFlag                                                                            */
/*      05- MSTK_VidSetCallBack                                                                        */
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

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

/*******************************************************************************************************/
/*                                        Macros for Systick State                                     */
/*******************************************************************************************************/


#define MSTK_INT_EN   1
#define MSTK_INT_DIS  0

/*#####################################################################################################*/
/*                                      Function Prototypes                                            */
/*#####################################################################################################*/


void MSTK_voidInit( void );

void MSTK_voidStart( u32 Copy_PreloadValue );

void MSTK_voidINTStatus( u8 Copy_u8Status );

u8 MSTK_u8ReadFlag( void );

void MSTK_voidSetCallBack( void (*ptr)(void) );


void MSTK_voidDelayMs(u32 Copy_u32Delay);

#endif /* SYSTICK_INTERFACE_H_ */
