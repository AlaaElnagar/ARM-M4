/*******************************************************************************************************/
/* Author            : Ahmed khaled Hammad                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 23 May 2022                                                                     */
/* Description       : MUSART_Program.c --> implementations                                            */
/* Module  Features  :                                                                                 */
/*      01- MSUART_voidInit                                                                            */
/*      02- MUSART_voidEnable                                                                          */
/*      03- MUSART_voidDisable                                                                         */
/*      04- MSUART_u8SendData                                                                          */
/*      05- MUSART_u8ReadData                                                                          */
/*      06- MUSART_GetHandler                                                                          */
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
#include "MUSART_Interface.h"
#include "MUSART_Private.h"
#include "MUSART_Config.h"

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      Functions Implementations                                      */
/*******************************************************************************************************/

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      01- MSUART_voidInit                                            */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Enable Peripheral Clock                                                  */
/* 2- Function Input       -> Copy_uBusName ,   Copy_u8PerNum                                          */
/*   - BusName_t      : The Bus Of The Prepheral ( AHB1 , AHB2 , APB1 , APB2 ) Every One               */
/*                      Detect Which REG To Choice Pripheral From It                                   */ 
/*   - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg                                    */                      
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/


void MSUART_voidInit(void)
{

	/***********	UART_1		***********/
#if (UART1_USED == U_ENABLE)
	USART1_REG->BRR = UART1_BUAD_RATE;
	USART1_REG->CR2 |= (UART1_STOP_BITS << 12);
	USART1_REG->CR1.SBK = UART1_SEND_BREAK;
	USART1_REG->CR1.RE = UART1_RECEIVER;
	USART1_REG->CR1.TE = UART1_TRANSMITTER;
	USART1_REG->CR1.RXNEIE = UART1_RX_INT;
	USART1_REG->CR1.TCIE = UART1_T_COMP_INT;
	USART1_REG->CR1.PCE = UART1_PARITY_ENABLE;
	USART1_REG->CR1.PS = UART1_PARITY_MODE;
	USART1_REG->CR1.M = UART1_WORD_LEN;
	USART1_REG->CR1.OVER8	= UART1_OVER_SAMPLING;

#endif

	/***********	UART_2		***********/
#if (UART2_USED == U_ENABLE)
	USART2_REG->CR1.SBK = UART2_SEND_BREAK;
	USART2_REG->CR1.RE = UART2_RECEIVER;
	USART2_REG->CR1.TE = UART2_TRANSMITTER;
	USART2_REG->CR1.RXNEIE = UART2_RX_INT;
	USART2_REG->CR1.TCIE = UART2_T_COMP_INT;
	USART2_REG->CR1.PCE = UART2_PARITY_ENABLE;
	USART2_REG->CR1.PS = UART2_PARITY_MODE;
	USART2_REG->CR1.M = UART2_WORD_LEN;
	USART2_REG->CR1.OVER8	= UART2_OVER_SAMPLING;

	USART2_REG->BRR = UART2_BUAD_RATE;

	USART2_REG->CR2 |= (UART2_STOP_BITS << 12);
#endif

	/***********	UART_6		***********/
#if (UART6_USED == U_ENABLE)
	USART6_REG->BRR = UART6_BUAD_RATE;

	USART6_REG->CR2 |= (UART6_STOP_BITS << 12);

	USART6_REG->CR1.SBK = UART6_SEND_BREAK;
	USART6_REG->CR1.RE = UART6_RECEIVER;
	USART6_REG->CR1.TE = UART6_TRANSMITTER;
	USART6_REG->CR1.RXNEIE = UART6_RX_INT;
	USART6_REG->CR1.TCIE = UART6_T_COMP_INT;
	USART6_REG->CR1.PCE = UART6_PARITY_ENABLE;
	USART6_REG->CR1.PS = UART6_PARITY_MODE;
	USART6_REG->CR1.M = UART6_WORD_LEN;
	USART6_REG->CR1.OVER8	= UART6_OVER_SAMPLING;


#endif
}

/*******************************************************************************************************/
/*                                      02- MUSART_voidEnable                                          */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Enable Peripheral Clock                                                  */
/* 2- Function Input       -> Copy_uBusName ,   Copy_u8PerNum                                          */
/*   - BusName_t      : The Bus Of The Prepheral ( AHB1 , AHB2 , APB1 , APB2 ) Every One               */
/*                      Detect Which REG To Choice Pripheral From It                                   */ 
/*   - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg                                    */                      
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MUSART_voidEnable(u8 copy_u8Index){
	switch(copy_u8Index){
	case 1: USART1_REG -> CR1.UE = 1; break;
	case 2: USART2_REG -> CR1.UE = 1; break;
	case 6: USART6_REG -> CR1.UE = 1; break;
	}
}

/*******************************************************************************************************/
/*                                      03- MUSART_voidDisable                                         */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Enable Peripheral Clock                                                  */
/* 2- Function Input       -> Copy_uBusName ,   Copy_u8PerNum                                          */
/*   - BusName_t      : The Bus Of The Prepheral ( AHB1 , AHB2 , APB1 , APB2 ) Every One               */
/*                      Detect Which REG To Choice Pripheral From It                                   */ 
/*   - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg                                    */                      
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MUSART_voidDisable(u8 copy_u8Index){
	switch (copy_u8Index)
	{
	case 1: USART1_REG -> CR1.UE = 0; break;
	case 2: USART2_REG -> CR1.UE = 0; break;
	case 6: USART6_REG -> CR1.UE = 0; break;
	}
}

/*******************************************************************************************************/
/*                                      04- MSUART_u8SendData                                          */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Enable Peripheral Clock                                                  */
/* 2- Function Input       -> Copy_uBusName ,   Copy_u8PerNum                                          */
/*   - BusName_t      : The Bus Of The Prepheral ( AHB1 , AHB2 , APB1 , APB2 ) Every One               */
/*                      Detect Which REG To Choice Pripheral From It                                   */ 
/*   - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg                                    */                      
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MUSART_u8SendData(u8 copy_u8Index, u8* copy_u8Data, u8 copy_u8Len){

	UART_REG uhandler = MUSART_GetHandler(copy_u8Index);
	for(u8 counter = 0; counter < copy_u8Len; counter++){
		uhandler ->DR = copy_u8Data[counter];
		while(!GET_BIT(uhandler->SR, 6));
	}

}

/*******************************************************************************************************/
/*                                      05- MUSART_u8ReadData                                          */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Enable Peripheral Clock                                                  */
/* 2- Function Input       -> Copy_uBusName ,   Copy_u8PerNum                                          */
/*   - BusName_t      : The Bus Of The Prepheral ( AHB1 , AHB2 , APB1 , APB2 ) Every One               */
/*                      Detect Which REG To Choice Pripheral From It                                   */ 
/*   - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg                                    */                      
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/


u8 MUSART_u8ReadData(u8 copy_u8Index){
	UART_REG uhandler = MUSART_GetHandler(copy_u8Index);
	return (u8) uhandler->DR;
}

/*******************************************************************************************************/
/*                                      01- MUSART_GetHandler                                          */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Enable Peripheral Clock                                                  */
/* 2- Function Input       -> Copy_uBusName ,   Copy_u8PerNum                                          */
/*   - BusName_t      : The Bus Of The Prepheral ( AHB1 , AHB2 , APB1 , APB2 ) Every One               */
/*                      Detect Which REG To Choice Pripheral From It                                   */ 
/*   - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg                                    */                      
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/


UART_REG MUSART_GetHandler(u8 copy_u8Index){
	UART_REG L_handle= (UART_REG) USART1_BASE_ADRESS;
	switch (copy_u8Index)
	{
	case 1: L_handle =  (UART_REG) USART1_BASE_ADRESS; break;
	case 2: L_handle =  (UART_REG) USART2_BASE_ADRESS; break;
	case 6: L_handle =  (UART_REG) USART6_BASE_ADRESS; break;
	}
	return L_handle;
}
