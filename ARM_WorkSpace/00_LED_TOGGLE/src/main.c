
#include "LSTD_TYPES.h"
#include "MRCC_interface.h"
#include "MGPIO_interface.h"

void App_voidDelay(void);

int main(void)
{

	/*System Clock is 8MHz from HSI*/
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
	/* Loop forever */
	while(1)
	{
		MGPIO_voidWriteData(_GPIOA_PORT, _PIN_0, _HIGH) ;
		App_voidDelay();
		MGPIO_voidWriteData(_GPIOA_PORT, _PIN_0, _LOW) ;
		App_voidDelay();
	}
}

void App_voidDelay(void)
{
	u32 i  ;
	for(i = 0 ; i<2000000;i++)
	{
		asm("NOP") ;
	}
}
