/****************************************************/
/*Author      : Alaa Elnaggar						*/
/*Date        : 25Apr2022							*/
/*Verssion    : V1.0								*/
/****************************************************/
/****************************************************/
/*Author      : Alaa Elnaggar						*/
/*Date        : 25Apr2022							*/
/*Verssion    : V1.0								*/
/****************************************************/
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H


/*Options : 01 - RCC_HSE_CRYSTAL   0
			02 - RCC_HSE_RC        1
			03 - RCC_HSI           2
			04 - RCC_PLL           3
			*/
			
#define RCC_CLOCK_TYPES   RCC_HSE_CRYSTAL


/*Note select value only if you have PLL as input clk source */
#if RCC_CLOCK_TYPES == RCC_PLL
/*Options : 01 - RCC_PLL_IN_HSI_DIV_2
			02 - RCC_PLL_IN_HSE_DIV_2
			03 - RCC_PLL_IN_HSE
*/
#define RCC_PLL_INPUT 
/*OPTIONS : 2 TO 16 select it before PLL EN*/
#define RCC_PLL_MUL_VAL 
#endif 




#endif