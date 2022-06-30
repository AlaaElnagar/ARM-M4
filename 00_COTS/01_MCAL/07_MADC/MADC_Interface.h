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

#ifndef MADC_INTERFACE_H
#define MADC_INTERFACE_H

/**********REG_SR_BITS********/
#define EOC 1

/********REG_CCR_BITS********/

#define ADCPRE          16
#define ADC_PRESCALAR_by_2   0b10
#define ADC_PRESCALAR_by_4   0b01
#define ADC_PRESCALAR_by_6   0b10
#define ADC_PRESCALAR_by_8   0b11
/*
		options
		1- PCLK2 divided by 2   0b00
		2- PCLK2 divided by 4   0b01
		3- PCLK2 divided by 6   0b10
		4- PCLK2 divided by 8   0b11
*/
/****************************/
/*********ADC_REG_CR1********/

#define RES 24
#define RES_12_bit_      0b00      /*(15 ADCCLK cycles)*/ 
#define RES_10_bit_      0b01      /*(13 ADCCLK cycles)*/ 
#define RES_8_bit_       0b10      /*(11 ADCCLK cycles)*/ 
#define RES_6_bit_       0b11      /*(9 ADCCLK cycles_)*/ 
/******************************/
/********END_OF_CONVERSION_INTERRUPT*********************/
#define EOCIE 5
#define EOC_interrupt_dis 0
#define EOC_interrupt_ena 1
/*******************************/


/**************ADC_REG_CR2*******************/
/*********ADC_ON***************/
#define ADON 		0
#define ADC_DISABLE 1
#define ADC_ENABLE  1
/*********************ADC_CONTINOUS MODE************/
#define CONT 1
#define Single_conversion_mode 0
#define Continuous_conversion_mode  1
/*****************************************************/
/*bit to interrupt either aat the end of a sequence or at the end of  a regular conversion*/
#define EOCS 10                               
#define Regular_conv_Int 1
/***************************************************/
/****************************************************/
/*bits to start software conversion*/
#define SWSTART 30
#define Rest 0
#define Strt 1
/******************ADC_REG_SAMPR1********************/
/*sampling time for each channel sample time selection bits */
#define SMP10 0       
#define SMP11 3
#define SMP12 6
#define SMP13 9
#define SMP14 12
#define SMP15 15
#define SMP16 18
#define SMP17 21
/*sampling time options*/
#define cycles_3      0b000
#define cycles_15     0b001
#define cycles_28     0b010
#define cycles_56     0b011
#define cycles_84     0b100
#define cycles_112    0b101
#define cycles_144    0b110
#define cycles_480    0b111
/***********************************************************/
/*************ADC_REG_SQR1*************/
#define L 20
#define One_Conv 0b0000
/*************ADC_REG_SQR3*************/
#define SQ1       0
#define Channel_1 0b0000
/**************************************/
#define SCAN 8
#define SCN_Disabled 0
#define SCN_Enabled 1
/**************************************/
extern u8 High_Eng_Temp;

/*prototypes*/
void 	MADC_vADC_Init(void);
u16 	MADC_vADC_Read(u8 Copy_u8Channel);
void 	MADC_vStrt (u8 Copy_u8ChannelNum);
void 	MADC_vStop(void);
void 	ADC_IRQHandler(void);
u16 	ADC_GetTemp(void);
u8 		ADC_GetEOC_state(void);
//void MADC_vPollFlag(void);



#endif
