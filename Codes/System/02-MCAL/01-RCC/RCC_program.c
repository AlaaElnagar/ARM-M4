/****************************************************/
/*Author      : Alaa Elnaggar						*/
/*Date        : 25Apr2022							*/
/*Verssion    : V1.0								*/
/****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

/*
Desc intialize system clk
*/
void RCC_voidInitSysClock(void)
{
	#if   RCC_CLOCK_TYPES ==  RCC_HSE_CRYSTAL
	     RCC_CR   = 0X00010000 ;            /*Enable HSE With no bypass*/
		 RCC_CFGR = 0X00000001 ;            /*HSE Selected*/   
	#elif RCC_CLOCK_TYPES ==  RCC_HSE_RC    
	     RCC_CR   = 0X00050000 ;            /*Enable HSE With no bypass*/
		 RCC_CFGR = 0X00000001 ;            /*HSE Selected*/
	#elif RCC_CLOCK_TYPES ==  RCC_HSI   
	     RCC_CR   = 0X00000081 ;            /*Enable HSI + Trimming = 0 */ 
		 RCC_CFGR = 0X00000000 ;            /*HSI Selected*/     
	#elif RCC_CLOCK_TYPES ==  RCC_PLL      
		#if   RCC_PLL_INPUT  == RCC_PLL
		
		#elif RCC_PLL_INPUT  == RCC_PLL_IN_HSE_DIV_2
		
		#elif RCC_PLL_INPUT  == RCC_PLL_IN_HSI_DIV_2
		
		#else
			#error "You chosed Wrong PLL source"
	#else
			#error "You chosed Wrong Clock type"
}

/*
Desc   Activate specific prepherial at specific bus 
*/

void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId) 
{
	if (Copy_u8PerId <=31){
		
		switch Copy_u8BusId 
		{ 
			case RCC_AHB  : SET_BIT(RCC_AHBENR  ,Copy_u8PerId) ; break ;
			case RCC_APB1 : SET_BIT(RCC_APB1ENR ,Copy_u8PerId) ; break ;
			case RCC_APB2 : SET_BIT(RCC_APB2ENR ,Copy_u8PerId) ; break ;
			//default       : /*return error*/  break ; 
			
			
		}
	}	
	else {
		/*return error*/
	}
}

/*
Desc   dActivate specific prepherial at specific bus 
*/

void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId) 
{
	if (Copy_u8PerId <=31){
		
		switch Copy_u8BusId 
		{ 
			case RCC_AHB  : CLR_BIT(RCC_AHBENR  ,Copy_u8PerId) ; break ;
			case RCC_APB1 : CLR_BIT(RCC_APB1ENR ,Copy_u8PerId) ; break ;
			case RCC_APB2 : CLR_BIT(RCC_APB2ENR ,Copy_u8PerId) ; break ;
			//default       : /*return error*/  break ; 
			
			
		}
	}	
	else {
		/*return error*/
	}
}