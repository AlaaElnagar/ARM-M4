/*******************************************************************************************************/
/* Author            : Ahmed khaled Hammad                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 23 May 2022                                                                     */
/* Description       : MUSART_Program.c --> implementations                                              */
/* Module  Features  :                                                                                 */
/*      01- MSTK_voidInit                                                                              */
/*      02- MSTK_voidStart                                                                             */
/*      03- MSTK_voidINTStatus                                                                         */
/*      04- MSTK_u8ReadFlag                                                                            */
/*      05- MSTK_VidSetCallBack                                                                        */
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

#include "MUSART_Private.h"
#include "MUSART_Config.h"
#include "MUSART_Interface.h"

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      Functions Implementations                                      */
/*******************************************************************************************************/

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      01- MSTK_voidInit                                              */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Enable Peripheral Clock                                                  */
/* 2- Function Input       -> Copy_uBusName ,   Copy_u8PerNum                                          */
/*   - BusName_t      : The Bus Of The Prepheral ( AHB1 , AHB2 , APB1 , APB2 ) Every One               */
/*                      Detect Which REG To Choice Pripheral From It                                   */ 
/*   - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg                                    */                      
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/


void MUART_vInit(u8 copy_u8Index){

	/***********	UART_1		***********/
#if (UART1_USED == U_ENABLE)
	UART1_REG->CR1.SBK = UART1_SEND_BREAK;
	UART1_REG->CR1.RE = UART1_RECEIVER;
	UART1_REG->CR1.TE = UART1_TRANSMITTER;
	UART1_REG->CR1.RXNEIE = UART1_RX_INT;
	UART1_REG->CR1.TCIE = UART1_T_COMP_INT;
	UART1_REG->CR1.PCE = UART1_PARITY_ENABLE;
	UART1_REG->CR1.PS = UART1_PARITY_MODE;
	UART1_REG->CR1.M = UART1_WORD_LEN;
	UART1_REG->CR1.OVER8	= UART1_OVER_SAMPLING;

	UART1_REG->BRR = UART1_BUAD_RATE;

	UART1_REG->CR2 |= (UART1_STOP_BITS << 12);
#endif

/***********	UART_2		***********/
#if (UART2_USED == U_ENABLE)
	UART2_REG->CR1.SBK = UART2_SEND_BREAK;
	UART2_REG->CR1.RE = UART2_RECEIVER;
	UART2_REG->CR1.TE = UART2_TRANSMITTER;
	UART2_REG->CR1.RXNEIE = UART2_RX_INT;
	UART2_REG->CR1.TCIE = UART2_T_COMP_INT;
	UART2_REG->CR1.PCE = UART2_PARITY_ENABLE;
	UART2_REG->CR1.PS = UART2_PARITY_MODE;
	UART2_REG->CR1.M = UART2_WORD_LEN;
	UART2_REG->CR1.OVER8	= UART2_OVER_SAMPLING;

	UART2_REG->BRR = UART2_BUAD_RATE;

	UART2_REG->CR2 |= (UART2_STOP_BITS << 12);
#endif

/***********	UART_6		***********/
#if (UART6_USED == U_ENABLE)
	UART6_REG->BRR = UART6_BUAD_RATE;

	UART6_REG->CR2 |= (UART6_STOP_BITS << 12);

	UART6_REG->CR1.SBK = UART6_SEND_BREAK;
	UART6_REG->CR1.RE = UART6_RECEIVER;
	UART6_REG->CR1.TE = UART6_TRANSMITTER;
	UART6_REG->CR1.RXNEIE = UART6_RX_INT;
	UART6_REG->CR1.TCIE = UART6_T_COMP_INT;
	UART6_REG->CR1.PCE = UART6_PARITY_ENABLE;
	UART6_REG->CR1.PS = UART6_PARITY_MODE;
	UART6_REG->CR1.M = UART6_WORD_LEN;
	UART6_REG->CR1.OVER8	= UART6_OVER_SAMPLING;


#endif
}

/*******************************************************************************************************/
/*                                      01- MSTK_voidInit                                              */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Enable Peripheral Clock                                                  */
/* 2- Function Input       -> Copy_uBusName ,   Copy_u8PerNum                                          */
/*   - BusName_t      : The Bus Of The Prepheral ( AHB1 , AHB2 , APB1 , APB2 ) Every One               */
/*                      Detect Which REG To Choice Pripheral From It                                   */ 
/*   - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg                                    */                      
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MUART_vEnable(u8 copy_u8Index){
	switch(copy_u8Index){
		case 1: UART1_REG -> CR1.UE = 1; break;
		case 2: UART2_REG -> CR1.UE = 1; break;
		case 6: UART6_REG -> CR1.UE = 1; break;
	}
}

/*******************************************************************************************************/
/*                                      01- MSTK_voidInit                                              */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Enable Peripheral Clock                                                  */
/* 2- Function Input       -> Copy_uBusName ,   Copy_u8PerNum                                          */
/*   - BusName_t      : The Bus Of The Prepheral ( AHB1 , AHB2 , APB1 , APB2 ) Every One               */
/*                      Detect Which REG To Choice Pripheral From It                                   */ 
/*   - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg                                    */                      
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MUART_vDisable(u8 copy_u8Index){
	switch (copy_u8Index)
	{
		case 1: UART1_REG -> CR1.UE = 0; break;
		case 2: UART2_REG -> CR1.UE = 0; break;
		case 6: UART6_REG -> CR1.UE = 0; break;
	}
}

/*******************************************************************************************************/
/*                                      01- MSTK_voidInit                                              */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Enable Peripheral Clock                                                  */
/* 2- Function Input       -> Copy_uBusName ,   Copy_u8PerNum                                          */
/*   - BusName_t      : The Bus Of The Prepheral ( AHB1 , AHB2 , APB1 , APB2 ) Every One               */
/*                      Detect Which REG To Choice Pripheral From It                                   */ 
/*   - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg                                    */                      
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MUART_u8SendData(u8 copy_u8Index, u8* copy_u8Data, u8 copy_u8Len){

	UART_REG uhandler = MUART_GetHandler(copy_u8Index);
	for(u8 counter = 0; counter < copy_u8Len; counter++){
		uhandler ->DR = copy_u8Data[counter];
		while(!GET_BIT(uhandler->SR, 6));
	}
	 
}

/*******************************************************************************************************/
/*                                      01- MSTK_voidInit                                              */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Enable Peripheral Clock                                                  */
/* 2- Function Input       -> Copy_uBusName ,   Copy_u8PerNum                                          */
/*   - BusName_t      : The Bus Of The Prepheral ( AHB1 , AHB2 , APB1 , APB2 ) Every One               */
/*                      Detect Which REG To Choice Pripheral From It                                   */ 
/*   - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg                                    */                      
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/


u8 MUART_u8ReadData(u8 copy_u8Index){
	UART_REG uhandler = MUART_GetHandler(copy_u8Index);

	return (u8) uhandler->DR;
}

/*******************************************************************************************************/
/*                                      01- MSTK_voidInit                                              */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Enable Peripheral Clock                                                  */
/* 2- Function Input       -> Copy_uBusName ,   Copy_u8PerNum                                          */
/*   - BusName_t      : The Bus Of The Prepheral ( AHB1 , AHB2 , APB1 , APB2 ) Every One               */
/*                      Detect Which REG To Choice Pripheral From It                                   */ 
/*   - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg                                    */                      
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/


UART_REG MUART_GetHandler(u8 copy_u8Index){
	UART_REG L_handle= (UART_REG) UART1_BASE_ADDRESS;
	switch (copy_u8Index)
	{
		case 1: L_handle =  (UART_REG) UART1_BASE_ADDRESS; break;
		case 2: L_handle =  (UART_REG) UART2_BASE_ADDRESS; break;
		case 6: L_handle =  (UART_REG) UART6_BASE_ADDRESS; break;
	}
	return L_handle;
}


u8 MUSART1_u8ReceiveCharSync( u8 copy_u8Index,u8 *  Copy_u8DataCome ){

	UART_REG uhandler = MUART_GetHandler(copy_u8Index);
	u8 LOC_u8Status = 1;

	if( GET_BIT( MUSART1 -> SR , 5 ) == 1 ){

		*Copy_u8DataCome = MUSART1 -> DR ;

	}else{

		LOC_u8Status = 0 ;

	}

	return LOC_u8Status ;

}
