/*
 * MRCC_Config.h
 *
 *  Created on: Jul 1, 2022
 *      Author: AlaaElnagar
 */

#ifndef MRCC_CONFIG_H_
#define MRCC_CONFIG_H_


/*

		01-MRCC_HSE_CRYSTAL
		02-MRCC_HSE_RC
		03-MRCC_HSI
		04-MRCC_PLL

*/
#define MRCC_CLOCK_TYPE     MRCC_PLL

#if MRCC_CLOCK_TYPE == MRCC_PLL
/*

		01-MRCC_PLL_IN_HSI
		02-MRCC_PLL_IN_HSE_RC
		03-MRCC_PLL_IN_HSE
*/

#if MRCC_CLOCK_TYPE == MRCC_PLL

#define MRCC_PLL_INPUT    MRCC_PLL_IN_HSE

#endif

/*
 f(VCO clock) = f(PLL clock input) × (PLLN / PLLM)
f(PLL general clock output) = f(VCO clock) / PLLP

The software has to set these bits correctly to ensure that the VCO output
frequency is between 192 and 432 MHz

[Note] PLLN Not allowed to be 0,1 or ">= 433"


	set PLLN_INPUT Between 2 and 432
*/

#define PLLN_INPUT       168

/*

f(PLL clock input)/ (PLLM) = 1 : 2 MHZ to limt getter
	set PLLM_INPUT Between 2 and 63


 */

#define PLLM_INPUT       25



/*

f(PLL general clock output) = f(VCO clock) / PLLP
	01- MRCC_PLLP_EQUAL_2
	02- MRCC_PLLP_EQUAL_4
	03- MRCC_PLLP_EQUAL_6
	04- MRCC_PLLP_EQUAL_8

 */

#define PLLP_INPUT       MRCC_PLLP_EQUAL_2

#endif


#define RCC_AHB_PRESCALLER


/*
		01-MRCC_ENABLE_CS
		02-MRCC_DISABLE_CS

*/




#define MRCC_CS_SYS   MRCC_DISABLE_CS

#endif /* MRCC_CONFIG_H_ */
