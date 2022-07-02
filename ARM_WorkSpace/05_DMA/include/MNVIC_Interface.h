/*******************************************************************************************************/
/* Author            : Ahmed khaled Hammad                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 23 May 2022                                                                     */
/* Description       : NVIC_Interface.c --> implementations                                            */
/* Module  Features  :                                                                                 */
/*      01- MNVIC_voidEnableInterrupt                                                                  */
/*      02- MNVIC_voidDisableInterrupt                                                                 */
/*      03- MNVIC_voidEnableInterruptPending                                                           */
/*      04- MNVIC_voidDisableInterruptPinding                                                          */
/*      05- MNVIC_u8IsInterruptActive                                                                  */
/*      06- MNVIC_voidInitInterruptGroup                                                               */
/*      07- MNVIC_voidSetInterruptPriority                                                             */
/*      08- MNVIC_voidGenerateSoftwareInterrupt                                                        */
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

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H


typedef enum{
    NVIC_GroupMode_g16s0 = 3,
    NVIC_GroupMode_g8s2,
    NVIC_GroupMode_g4s4,
    NVIC_GroupMode_g2s8,
    NVIC_GroupMode_g0s16
}NVIC_GroupMode_t;


/*#####################################################################################################*/
/*                                      Function Prototypes                                            */
/*#####################################################################################################*/




void MNVIC_voidEnableInterrupt(u8 copy_u8IntNum);
			
void MNVIC_voidDisableInterrupt(u8 copy_u8IntNum);
			
void MNVIC_voidEnableInterruptPending(u8 copy_u8IntNum);
			
void MNVIC_voidDisableInterruptPinding(u8 copy_u8IntNum);

u8   MNVIC_u8IsInterruptActive(u8 copy_u8IntNum);

void MNVIC_voidInitInterruptGroup(NVIC_GroupMode_t copy_GropMode);
			
void MNVIC_voidSetInterruptPriority(u8 copy_u8IntNum,NVIC_GroupMode_t copy_GropMode, u8 copy_u8IntGroup, u8 copy_u8IntPrio);


void MNVIC_voidGenerateSoftwareInterrupt(u8 copy_u8IntNum);

#endif //NVIC_INTERFACE_H
