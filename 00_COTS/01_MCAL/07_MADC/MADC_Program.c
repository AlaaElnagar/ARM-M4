/*******************************************************************************************************/
/* Author            : Ahmed khaled Hammad                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 23 May 2022                                                                     */
/* Description       : MADC_Program.c --> implementations                                              */
/* Module  Features  :                                                                                 */
/*      01- MEXTI_voidInit                                                                             */
/*      02- MEXTI_voidEnableEXTI                                                                       */
/*      03- MEXTI_voidDisableEXTI                                                                      */
/*      04- MEXIT_voidSoftwareInterrput                                                                */
/*      05- MEXTI_voidSetSignalLatch                                                                   */
/*      06- EXTI_voidSetCallBack                                                                       */
/*******************************************************************************************************/
/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      Standard Types LIB                                             */
/*******************************************************************************************************/

#include "LIB/LSTD_TYPES.h"
#include "LIB/LERROR_STATE.h"
#include "LIB/LBIT_MATH.h"


/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      MCAL Components                                                */
/*******************************************************************************************************/

#include "MADC_private.h"
#include "MADC_interface.h"
#include "MADC_config.h"

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      Functions Implementations                                      */
/*******************************************************************************************************/

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      01- MEXTI_voidInit(void)                                       */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Enable Peripheral Clock                                                  */
/* 2- Function Input       -> Copy_uBusName ,   Copy_u8PerNum                                          */
/*   - BusName_t      : The Bus Of The Prepheral ( AHB1 , AHB2 , APB1 , APB2 ) Every One               */
/*                      Detect Which REG To Choice Pripheral From It                                   */ 
/*   - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg                                    */                      
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "LIB/errorState.h"
#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/ADC/ADC_Zebala.h"
#include "MCAL/ADC/ADC_interface.h"

/************** STEPS TO FOLLOW *****************

1. Enable ADC and GPIO clock
2. Set the prescalar in the Common Control Register (CCR)
3. Set the Scan Mode , Resolution and EOC interrupt in the Control Register 1 (CR1)
4. Set the Continuous Conversion, EOC, and Data Alignment in Control Reg 2 (CR2)
5. Set the Sampling Time for the channels in ADC_SMPRx
6. Set the Regular channel sequence length in ADC_SQR1
7. Set the Respective GPIO PINs in the Analog Mode
 ************************************************/
/*******************ADC_INIT********************/


u16 Temp;


void MADC_vADC_Init(void)
{
	/*Set the prescalar in the Common Control Register (CCR)*/
	/*select prescalar*/
	ADC->CCR   |= (ADC_PRESCALAR_by_4<<ADCPRE);

	/*select resoltuion and eoc int enabled*/
	ADC1->CR1  &= ~(RES_6_bit_<< RES); 		// Clear bits 24:25, 12-bits resolution
	ADC1->CR1  &= ~(1<< 11); 		// Clear bit 11, disable Discontinuous mode on regular	channels
	ADC1->CR1  &= ~(SCN_Enabled<<SCAN);	// Clear bit 8, Scan mode disabled
	ADC1->CR1  |= (EOC_interrupt_ena << EOCIE);	// Set bit 5, Enable End Of Conversion Interrupt

	/*Single mode selected*/
	ADC1->CR2  &= ~(Continuous_conversion_mode  <<  CONT);	// Clear bit 2, Single conversion mode
	/* Clear bit 10,
	 *  The EOC bit is set at the end of each sequence of regular conversions
	 *  Overrun detection is enabled only if DMA=1 */
	ADC1->CR2  &= ~(Regular_conv_Int<< EOCS);
	ADC1->CR2  &= ~(0b11<< 28);		// Clear bits 28:29, Trigger detection disabled
	ADC1->CR2  &= ~(1<< 11);		// Clear bit 11, Right alignment
	ADC1->CR2  &= ~(1<< 8);		// Clear bit 8, DMA mode disabled

	/*15 cycles of sampling for channel one*/
//	ADC1->SMPR2 |= (cycles_15 << SMP10);
	ADC1->SMPR2 = 0x00000000;

	ADC1->SQR1 = 0x00000000;
	ADC1->SQR3 = 0x00000000;

}

void MADC_vStrt(u8 Copy_u8ChannelNum)
{

	ADC1->SQR3 = Copy_u8ChannelNum;
	ADC1->SR = 0;
		u32 delay = 10000;
	/*start ADC conversion*/
	ADC1->CR2  |= (ADC_ENABLE<<ADON);	// Set ADON bit
	while(delay--);				// check if ADON is Set
	ADC1->CR2  |= (Strt<<SWSTART);		// Set (Start conversion of regular channels) bit
	//while (((ADC1->SR) >> 1));
	//ADC1->CR2   |= (Strt<<SWSTART) ;
}

void MADC_vStop(void)
{
	ADC1->CR2  &=~ (ADC_ENABLE<<ADON)|(Strt<<SWSTART);	
}

void ADC_IRQHandler(void)
{
	u16 ADC_Data=0 ;
	ADC_Data=(u16)(ADC1->DR);

	Temp=0;
	//u8 u8_Flag_Clr=0;
//	Temp = (u16)(((u32)ADC_Data*150*3.5)/(4095*1.5));
	Temp = (u16)(((u32)ADC_Data*1.221)/10);

	/*
	if(75<=Temp)
	{
		//GPIOC->ODR=0xFFFFFFFF;
		//u8_High_Eng_Temp=1;
	}
	else
	{
		//GPIOC->ODR&=~0xFFFFFFFF;
		//u8_High_Eng_Temp=2;

	 }
	 */

	//MADC_vStop();
	//u8_Flag_Clr	=((ADC1->SR >> EOC) & 0x01);
}

u16 ADC_GetTemp(void)
{
	return Temp;

}

u8 ADC_GetEOC_state(void)
{
	return ((ADC1->SR >> EOC) & 0x01);
}

/*
void MADC_vPollFlag(void)
{
	u8 Temp=0;
	while (((ADC1->SR >> EOC) & 0x01)==0);
	//GPIOC->ODR=0xFFFFFFFF;
	Temp = (u32)(((u32)((u32)(u16)(ADC1->DR)*150*3.5)/(4095*1.5)));
	if(75<=Temp)
	{
		GPIOC->ODR=0xFFFFFFFF;
	}
	else
	{
		GPIOC->ODR=0xFFFFFFFF;
	}
}
 */
