/*******************************************************************************************************/
/* Author            : Ahmed khaled Hammad                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 23 May 2022                                                                     */
/* Description       : NVIC_Program.c --> implementations                                              */
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

#include "MNVIC_private.h"
#include "MNVIC_interface.h"
#include "MNVIC_config.h"

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      Functions Implementations                                      */
/*******************************************************************************************************/

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      01- MNVIC_voidEnableInterrupt                                 */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Enable Peripheral Clock                                                  */
/* 2- Function Input       -> Copy_uBusName ,   Copy_u8PerNum                                          */
/*   - BusName_t      : The Bus Of The Prepheral ( AHB1 , AHB2 , APB1 , APB2 ) Every One               */
/*                      Detect Which REG To Choice Pripheral From It                                   */ 
/*   - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg                                    */                      
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

u8 NVIC_G_u8GroupMode = NVIC_GroupMode_g16s0;

/*
* Function: Set The enable for any prefiral
* Range :	copy_u8IntNum -> 84 "Refer to data sheet" */

void MNVIC_voidEnableInterrupt(u8 copy_u8IntNum){
	NVIC_REG->ISER[copy_u8IntNum / 32] = (1U << copy_u8IntNum % 32);
//	NVIC_REG->ISER[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));

}


/*******************************************************************************************************/
/*                                      02- MNVIC_voidDisableInterrupt                                */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Enable Peripheral Clock                                                  */
/* 2- Function Input       -> Copy_uBusName ,   Copy_u8PerNum                                          */
/*   - BusName_t      : The Bus Of The Prepheral ( AHB1 , AHB2 , APB1 , APB2 ) Every One               */
/*                      Detect Which REG To Choice Pripheral From It                                   */ 
/*   - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg                                    */                      
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

/*
* Function: Set The enable for any prefiral
* Range :	copy_u8IntNum -> 84 "Refer to data sheet" */
void MNVIC_voidDisableInterrupt(u8 copy_u8IntNum){
	NVIC_REG->ICER[copy_u8IntNum / 32] = (1U << copy_u8IntNum % 32);
	
}


/*******************************************************************************************************/
/*                                      03- MNVIC_voidEnableInterruptPending                          */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Enable Peripheral Clock                                                  */
/* 2- Function Input       -> Copy_uBusName ,   Copy_u8PerNum                                          */
/*   - BusName_t      : The Bus Of The Prepheral ( AHB1 , AHB2 , APB1 , APB2 ) Every One               */
/*                      Detect Which REG To Choice Pripheral From It                                   */ 
/*   - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg                                    */                      
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/


void MNVIC_voidEnableInterruptPending(u8 copy_u8IntNum){
	NVIC_REG->ISPR[copy_u8IntNum / 32] = (1U << copy_u8IntNum % 32);
	
}

/*******************************************************************************************************/
/*                                      04- MNVIC_voidDisableInterruptPinding                         */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Enable Peripheral Clock                                                  */
/* 2- Function Input       -> Copy_uBusName ,   Copy_u8PerNum                                          */
/*   - BusName_t      : The Bus Of The Prepheral ( AHB1 , AHB2 , APB1 , APB2 ) Every One               */
/*                      Detect Which REG To Choice Pripheral From It                                   */ 
/*   - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg                                    */                      
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MNVIC_voidDisableInterruptPinding(u8 copy_u8IntNum){
	NVIC_REG->ICPR[copy_u8IntNum / 32] = (1U << copy_u8IntNum % 32);
	
}

/*******************************************************************************************************/
/*                                      05- MNVIC_u8IsInterruptActive                                 */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Enable Peripheral Clock                                                  */
/* 2- Function Input       -> Copy_uBusName ,   Copy_u8PerNum                                          */
/*   - BusName_t      : The Bus Of The Prepheral ( AHB1 , AHB2 , APB1 , APB2 ) Every One               */
/*                      Detect Which REG To Choice Pripheral From It                                   */ 
/*   - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg                                    */                      
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/



u8 MNVICE_u8IsInterruptActive(u8 copy_u8IntNum){
	return GET_BIT(NVIC_REG->IABR[copy_u8IntNum / 32], copy_u8IntNum);

}

/*******************************************************************************************************/
/*                                      06- MNVIC_voidInitInterruptGroup                               */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Enable Peripheral Clock                                                  */
/* 2- Function Input       -> Copy_uBusName ,   Copy_u8PerNum                                          */
/*   - BusName_t      : The Bus Of The Prepheral ( AHB1 , AHB2 , APB1 , APB2 ) Every One               */
/*                      Detect Which REG To Choice Pripheral From It                                   */ 
/*   - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg                                    */                      
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/


void MNVIC_voidInitInterruptGroup(NVIC_GroupMode_t copy_GropMode){
		 //Read  SCB_AIRCR First reset the regester first
	SCB_AIRCR = (VECTKEY | (copy_GropMode << 8));
}

/*******************************************************************************************************/
/*                                      07- MNVIC_voidSetInterruptPriority                            */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Enable Peripheral Clock                                                  */
/* 2- Function Input       -> Copy_uBusName ,   Copy_u8PerNum                                          */
/*   - BusName_t      : The Bus Of The Prepheral ( AHB1 , AHB2 , APB1 , APB2 ) Every One               */
/*                      Detect Which REG To Choice Pripheral From It                                   */ 
/*   - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg                                    */                      
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/
 
 
void MNVIC_voidSetInterruptPriority(u8 copy_u8IntNum,NVIC_GroupMode_t copy_GropMode, u8 copy_u8IntGroup, u8 copy_u8IntPrio){
	u8 L_u8PrioValue = 0;
	switch(copy_GropMode){
		case NVIC_GroupMode_g16s0 : L_u8PrioValue =  copy_u8IntGroup; break;
		case NVIC_GroupMode_g8s2  : L_u8PrioValue = (copy_u8IntGroup << 1) | copy_u8IntPrio; break;
		case NVIC_GroupMode_g4s4  : L_u8PrioValue = (copy_u8IntGroup << 2) | copy_u8IntPrio; break;
		case NVIC_GroupMode_g2s8  : L_u8PrioValue = (copy_u8IntGroup << 3) | copy_u8IntPrio; break;
		case NVIC_GroupMode_g0s16 : L_u8PrioValue =  copy_u8IntPrio; break;
	}

	NVIC_REG->IPR[copy_u8IntNum] = L_u8PrioValue << 4;
}

/*******************************************************************************************************/
/*                                      08- MNVIC_voidGenerateSoftwareInterrupt                        */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Enable Peripheral Clock                                                  */
/* 2- Function Input       -> Copy_uBusName ,   Copy_u8PerNum                                          */
/*   - BusName_t      : The Bus Of The Prepheral ( AHB1 , AHB2 , APB1 , APB2 ) Every One               */
/*                      Detect Which REG To Choice Pripheral From It                                   */ 
/*   - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg                                    */                      
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/
 
void MNVIC_voidGenerateSoftwareInterrupt(u8 copy_u8IntNum){
	NVIC_REG->STIR = (copy_u8IntNum << 4);
}
