
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"

#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MSYSTICK_Interface.h"
#include "MUSART_Interface.h"

#include "MFPEC_interface.h"
#include "PARSER_interface.h"

volatile u8 u8RecBuffer[100] = {0}   ;
volatile u8 u8RecCounter     =  0    ;
volatile u8 TimeOutFlag      =  0    ;
volatile u8 u8BLWriteReq     =  1    ;

typedef void (*Function_t)(void) ;

Function_t  Addr_To_Call = 0;  // void (*Addr_To_Call)(void)

void Func_CallBack(void){

	/*Some Code*/

	TimeOutFlag = 1 ;

#define SCB_VTOR  *((volatile u32 *)0xE000ED08)

	SCB_VTOR     = 0x08001800 ;

	Addr_To_Call = *(Function_t *)0x08001804 ;

	Addr_To_Call();

}

void main (void){

	u8 LOC_u8RecStatus = 0;


	/*System Clock is 16MHz from HSI*/
	MRCC_voidInitSystemClk();
	/*Enable GPIO Peripheral clock*/
	MRCC_voidEnablePeripheralClock(AHB1,_PERIPHERAL_EN_GPIOA ) ;
	MRCC_voidEnablePeripheralClock(AHB1,_PERIPHERAL_EN_GPIOB ) ;
	MRCC_voidEnablePeripheralClock(AHB2,PERIPHERAL_EN_USART1 ) ;

	//MRCC_voidEnablePerClock( MRCC_AHB  , MRCC_FPEC_EN   );

	/*Set Pin Mode --> Output*/
	MGPIO_voidSetPinMode(_GPIOA_PORT, _PIN_0, _MODE_OUTPUT) ;
	/*Set Pin Mode for UART1 */
	MGPIO_voidSetPinMode(_GPIOB_PORT, _PIN_6, _MODE_OUTPUT) ;//TX
	MGPIO_voidSetPinMode(_GPIOB_PORT, _PIN_7, _MODE_OUTPUT) ;//RX
	MGPIO_voidSetPinAltFn(_GPIOB_PORT, _PIN_6, _ALTFN_8);    //TX-->UART6
	MGPIO_voidSetPinAltFn(_GPIOB_PORT, _PIN_7, _ALTFN_8);    //RX-->UART6

	/*Out put Push Pull*/
	MGPIO_voidSetPinOutPutType(_GPIOA_PORT,_PIN_0,_OUTPUT_TYPE_PUSH_PULL);
	/*Pin Speed*/
	MGPIO_voidSetPinOutSpeed(_GPIOA_PORT, _PIN_0, _OUTPUT_SPEED_LOW);
	/*Pin Value High*/
	MGPIO_voidWriteData(_GPIOA_PORT, _PIN_0, _HIGH) ;

	/*Initialize USART1*/
	MUART_vInit(1) ;

	/*Initialize Systick*/
	MSTK_voidInit();

	MSTK_voidStart(15000000) ;
	MSTK_voidSetCallBack(Func_CallBack) ;

	//MSTK_voidSetIntervalSingle( 15000000 , Func_CallBack );

	while( TimeOutFlag == 0 ){

		LOC_u8RecStatus = MUSART1_u8ReceiveCharSync(&u8RecBuffer[u8RecCounter]);

		if( LOC_u8RecStatus == 1 ){

			MSTK_voidStopTimer();

			if( u8RecBuffer[u8RecCounter] == '\n' ){

				if( u8BLWriteReq == 1 ){

					MFPEC_voidEraseAppArea();
					u8BLWriteReq = 0 ;

				}

				PARSE_voidParseRecord( u8RecBuffer );
				MUSART1_voidSendSrtingSynch((u8 *)"ok");
				u8RecCounter = 0 ;

			}
			else{ u8RecCounter++ ; }

			if( u8RecBuffer[8] == '1' ){

				MSTK_voidSetIntervalSingle( 1000000 , Func_CallBack );
			}

		}

	}

}
