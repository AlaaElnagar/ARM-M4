
#include "LSTD_TYPES.h"
#include "MRCC_interface.h"
#include "MSYSTICK_Interface.h"
#include "MGPIO_interface.h"
#include "MNVIC_interface.h"
#include "MEXTI_interface.h"


void EXTI0_IRQHandler(void){

	MGPIO_voidWriteData(_GPIOA_PORT, _PIN_0, _LOW) ;
}

void EXTI1_IRQHandler(void){

	MGPIO_voidWriteData(_GPIOA_PORT, _PIN_0, _HIGH) ;

}

void _delay_us( u32 Copy_u32Time ) ;
void _delay_ms( u32 Copy_u32Time ) ;

int main(void)
{

	/*System Clock is 16MHz from HSI*/
	MRCC_voidInitSystemClk();


	/*Enable GPIO Peripheral clock*/
	MRCC_voidEnablePeripheralClock(AHB1,_PERIPHERAL_EN_GPIOA ) ;

	/*Set Pin Mode --> Output*/
	MGPIO_voidSetPinMode(_GPIOA_PORT, _PIN_0, _MODE_OUTPUT) ;

	/*Out put Push Pull*/
	MGPIO_voidSetPinOutPutType(_GPIOA_PORT,_PIN_0,_OUTPUT_TYPE_PUSH_PULL);

	/*Pin Speed*/
	MGPIO_voidSetPinOutSpeed(_GPIOA_PORT, _PIN_0, _OUTPUT_SPEED_LOW);

	/*Pin Value High*/
	MGPIO_voidWriteData(_GPIOA_PORT, _PIN_0, _HIGH) ;

	MNVIC_VidSetPriority( EXT0 , 1 , NO_SUB_PRIORITY , GROUP3 );
	MNVIC_VidSetPriority( EXT1 , 2 , NO_SUB_PRIORITY , GROUP3 );

	MNVIC_VidEnablePeripheral( EXT0 );
	MNVIC_VidEnablePeripheral( EXT1 );

	/* Loop forever */
	while(1)
	{
		MNVIC_VidSetPending( EXT0 );
		_delay_ms( 1000 );
		MNVIC_VidSetPending( EXT1 );
		_delay_ms( 1000 );

	}
}

void _delay_ms( u32 Copy_u32Time ){

	MSTK_voidInit();
	/* Disable INT */
	MSTK_voidINTStatus( MSTK_INT_DIS );
	MSTK_voidStart( Copy_u32Time * 1000 );
	/* Wiat Flag Polling */
	while( MSTK_u8ReadFlag() == 0 );

}


/* Suppose That The Clock System (AHB) = 8MHZ EXT & The Systick Clock Is = AHB/8 */
void _delay_us( u32 Copy_u32Time ){

	MSTK_voidInit();
	/* Disable INT */
	MSTK_voidINTStatus( MSTK_INT_DIS );
	MSTK_voidStart( Copy_u32Time);
	/* Wiat Flag Polling */
	while( MSTK_u8ReadFlag() == 0 );

}
