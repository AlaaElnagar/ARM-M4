/*******************************************************************************************************/
/* Author            : Ahmed khaled Hammad                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 23 May 2022                                                                     */
/* Description       : MRCC_Program.c --> implementations                                              */
/* Module  Features  :                                                                                 */
/*      01- MRCC_voidEnablePeripheralClock                                                             */
/*      02- MRCC_voidDisablePeripheralClock                                                            */
/*      03- MRCC_voidEnableSecuritySystem                                                              */
/*      04- MRCC_voidDisableSecuritySystem                                                             */
/*      05- MRCC_voidInitSystemClk                                                                     */
/*      06- MRCC_voidInitClock                                                                         */
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

#include "MRCC_private.h"
#include "MRCC_interface.h"
#include "MRCC_config.h"

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      Functions Implementations                                      */
/*******************************************************************************************************/

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      01- MRCC_voidEnableClock                                       */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Enable Peripheral Clock                                                  */
/* 2- Function Input       -> Copy_uBusName ,   Copy_u8PerNum                                          */
/*   - BusName_t      : The Bus Of The Prepheral ( AHB1 , AHB2 , APB1 , APB2 ) Every One               */
/*                      Detect Which REG To Choice Pripheral From It                                   */ 
/*   - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg                                    */                      
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MRCC_voidEnablePeripheralClock(BusName_t BusName , u8 Copy_u8PerNum )
{
	
	switch(BusName)
	{
		case AHB1_BUS:  SET_BIT(RCC_AHB1ENR,Copy_u8PerNum );         break ;
		case AHB2_BUS:  SET_BIT(RCC_AHB2ENR,Copy_u8PerNum );         break ;
		case APB1_BUS:  SET_BIT(RCC_APB1ENR,Copy_u8PerNum );         break ;
		case APB2_BUS:  SET_BIT(RCC_APB2ENR,Copy_u8PerNum );         break ;
		default :     /*   ERROR   */          break ;
		
	}
}
/*******************************************************************************************************/
/*                                      02- MRCC_voidDisableClock                                       */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Disable Peripheral Clock                                                  */
/* 2- Function Input       -> Copy_uBusName ,   Copy_u8PerNum                                          */
/*   - BusName_t      : The Bus Of The Prepheral ( AHB1 , AHB2 , APB1 , APB2 ) Every One               */
/*                      Detect Which REG To Choice Pripheral From It                                   */ 
/*   - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg                                    */                      
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MRCC_voidDisablePeripheralClock(BusName_t BusName , u8 Copy_u8PerNum )
{
	switch(BusName)
	{
		case AHB1_BUS:  CLR_BIT(RCC_AHB1ENR,Copy_u8PerNum );         break ;
		case AHB2_BUS:  CLR_BIT(RCC_AHB2ENR,Copy_u8PerNum );         break ;
		case APB1_BUS:  CLR_BIT(RCC_APB1ENR,Copy_u8PerNum );         break ;
		case APB2_BUS:  CLR_BIT(RCC_APB2ENR,Copy_u8PerNum );         break ;
		default :     /* ERROR */          break ;
		
	}
}

/*******************************************************************************************************/
/*                                      03- MRCC_voidEnableSecuritySystem                              */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Enable Security System                                                   */
/* 2- Function Input       -> No Thing                                                                 */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MRCC_voidEnableSecuritySystem(void)
{
	SET_BIT( RCC_CR  , CSSON);
	
}
/*******************************************************************************************************/
/*                                      04- MRCC_voidDisableSecuritySystem                              */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Disable Security System                                                   */
/* 2- Function Input       -> No Thing                                                                 */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/


void MRCC_voidDisableSecuritySystem(void)
{
	CLR_BIT( RCC_CR  , CSSON);
	
}
/*******************************************************************************************************/
/*                                      05- MRCC_voidInitSystemClk                                     */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> intialize system clock                                                   */
/*    - CLK		: HSE | HSI |PLL	                                                                   */
/*    - PLLSrc	:PLL_HSE | PLL_HSI                                                                     */
/*    - HSESrc  :HSE_Crystal ,HSE_RC                                                                   */
/* 2- Function Input       -> No Thing                                                                 */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/
void MRCC_voidInitSystemClk(void)
{
	/********** HSI **********/
#if CLKSRC == HSI 
	/* 1- EN HSI */
	SET_BIT(MRCC->CR , 0U);
	/* 2- CLK SYS --> HSI */
	CLR_BIT(MRCC->CFGR, 0U);
	CLR_BIT(MRCC->CFGR, 1U);
	/********** HSE **********/
#elif CLKSRC == HSE
	
	#if HSE_SRC == CRYSTAL 
	/* 1- EN HSE */
		SET_BIT(MRCC->CR , 16U);
		/* 2- Disable BYP */
		CLR_BIT(MRCC->CR,18U);
		/* 3- CLK SYS --> HSE */
		SET_BIT(MRCC->CFGR, 0U);
		CLR_BIT(MRCC->CFGR, 1U);

	#elif HSE_SRC == RC 
		/* 1- EN HSE */
		SET_BIT(MRCC->CR , 16U);
		/* 2- Enable BYP */
		SET_BIT(MRCC->CR,18U);
		/* 3- CLK SYS --> HSE */
		SET_BIT(MRCC->CFGR, 0U);
		CLR_BIT(MRCC->CFGR, 1U);
	#else 
    /* Error*/
	#endif
	
	/********** PLL **********/
#elif CLKSRC == PLL	

    #if PLL_SRC == _HSE_PLL 
     /*1-Enable HSE */
			SET_BIT(MRCC->CR,16U);
			/* while ( GET_BIT(RCC_CR, 17)==0);*/
			/*2- EN PLL*/
			SET_BIT(MRCC->,24U);
			/* while ( GET_BIT(RCC_CR, 25)==0);*/
			/* 3- PLL From HSE */
			SET_BIT(MRCC->PLLCFGR, 22U);
			/* 4- System Clk  PLL */
			CLR_BIT(MRCC->CFGR,0U);
			SET_BIT(MRCC->CFGR,1U);
 
    #elif PLL_SRC == _HSI_PLL  
            /*Enable HSI */
		     SET_BIT(MRCC->CR,0U);
			/*2- EN PLL*/
			SET_BIT(MRCC->CR,24U);
			/* 3- PLL From HSI */
			CLR_BIT(MRCC->PLLCFGR, 22U);
			/* 4- System Clk  PLL */
			CLR_BIT(MRCC->CFGR,0U);
			SET_BIT(MRCC->CFGR,1U);
    #else 
            /* Error*/
	#endif
/****************************************************/

#else 
/* Error*/
#endif // The End Of Big IF	
}

/*******************************************************************************************************/
/*                                      06- MRCC_voidInitClock                                         */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> intialize system clock                                                   */
/*    - CLK		: HSE | HSI |PLL	                                                                   */
/*    - PLLSrc	:PLL_HSE | PLL_HSI                                                                     */
/*    - HSESrc  :HSE_Crystal ,HSE_RC                                                                   */
/* 2- Function Input       -> Copy_uClkSrc   , Copy_uHSESrc    ,Copy_uPLLSrc                           */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/
void MRCC_voidInitClock(CLKSrcName_t Copy_tClkSrc , HSESrc_t Copy_tHSESrc ,PLLSrc_t Copy_tPLLSrc )
{
	switch(Copy_tClkSrc)
	{
		case HSE :
		switch(Copy_tHSESrc)
		{
		  case _HSE_CRYSTAL : 
			/*1-Enable HSE */
			SET_BIT(RCC_CR,16U);
			/* while ( GET_BIT(RCC_CR, 17)==0);*/
			/*Disable BYP*/
			CLR_BIT(RCC_CR,18U);
			/* Input system Clk*/
			SET_BIT(RCC_CFGR,0U);
			CLR_BIT(RCC_CFGR,1U);
		  break ;
		  /************************************************/
          case _HSE_RC :   
			/*Enable HSE */
			SET_BIT(RCC_CR,16U);
            /*2-Disable BYP*/
			SET_BIT(RCC_CR,18U);
				/* Input system Clk*/
			SET_BIT(RCC_CFGR,0U);
			CLR_BIT(RCC_CFGR,1U);

		  break ;

		  /*********************************************/
		  default :  break ;
		}
	    break ;
		/*******************/
		case HSI :
		/*Enable HSI */
		SET_BIT(RCC_CR,0U);
		/* Input system Clk*/
		CLR_BIT(RCC_CFGR,0U);
		CLR_BIT(RCC_CFGR,1U);
	    break ;
		/********************/
		case PLL :
		switch(Copy_tPLLSrc)
		{
			case _HSE_PLL: 
			/*1-Enable HSE */
			SET_BIT(RCC_CR,16U);
			/* while ( GET_BIT(RCC_CR, 17)==0);*/
			/*2- EN PLL*/
			SET_BIT(RCC_CR,24U);
			/* while ( GET_BIT(RCC_CR, 25)==0);*/
			/**/
			SET_BIT(RCC_PLLCFGR, 22U);
			
			CLR_BIT(RCC_CFGR,0U);
			SET_BIT(RCC_CFGR,1U);
			
			break ;
			
			/**************************/
			
			case _HSI_PLL : 
			/*Enable HSI */
		     SET_BIT(RCC_CR,0U);
			/*2- EN PLL*/
			SET_BIT(RCC_CR,24U);
			
			CLR_BIT(RCC_PLLCFGR, 22U);
			
			CLR_BIT(RCC_CFGR,0U);
			SET_BIT(RCC_CFGR,1U);
			
			break ;
		}

	    break ;
		
	}
	
}
/*====================================================   END_ FUNCTION   ====================================================*/
