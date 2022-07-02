/*******************************************************************************************************/
/* Author            : Ahmed khaled Hammad                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 23 May 2022                                                                     */
/* Description       : NVIC_Interface.c --> implementations                                            */
/* Module  Features  :                                                                                 */
/*      01- MEXTI_voidInit                                                                             */
/*      02- MEXTI_voidEnableEXTI                                                                       */
/*      03- MEXTI_voidDisableEXTI                                                                      */
/*      04- MEXIT_voidSoftwareInterrput                                                                */
/*      05- MEXTI_voidSetSignalLatch                                                                   */
/*      06- EXTI_voidSetCallBack                                                                       */
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

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


/***********	Function Intialize EXTI	Line & Mode By #define	***********/

void MEXTI_voidInit(void)  ;

/***********	Function To Choice The Sense Mode At The Line	***********/

void MEXTI_voidSetSignalLatch(u8 Copy_Exti_Line ,u8 Copy_EXTI_Sense_Mode )  ;

/***********		  Function To Enable The Line				***********/

void MEXTI_voidEnableEXTI(u8 Copy_u8Line) ;

/***********	Function To Disable The Line					***********/

void MEXTI_voidDisableEXTI(u8 Copy_u8Line);

/***********	Function Make SoftWare Interrput				***********/

void MEXIT_voidSoftwareInterrput(u8 Copy_u8Line);

/***********	Function Take A Pointer To Function				***********/

void EXTI_voidSetCallBack( void (*ptr) (void) ,u8 Copy_ExtiBit);


#endif  //EXTI_INTERFACE_H
