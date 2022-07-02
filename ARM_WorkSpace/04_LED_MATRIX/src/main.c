
#include "LSTD_TYPES.h"

#include "MRCC_interface.h"
#include "MGPIO_interface.h"

int main(void)
{
	/*System Clock is 16MHz from HSI*/
	MRCC_voidInitSystemClk();

	/*Enable GPIO Peripheral clock*/
	MRCC_voidEnablePeripheralClock(AHB1,_PERIPHERAL_EN_GPIOA ) ;
	MRCC_voidEnablePeripheralClock(AHB1,_PERIPHERAL_EN_GPIOB ) ;
	MRCC_voidEnablePeripheralClock(APB2, PERIPHERAL_EN_SYSCFG) ;

	/*Set Pin Mode --> Output*/
	MGPIO_voidSetPinMode(_GPIOA_PORT, _PIN_0, _MODE_OUTPUT) ;
	/*Out put Push Pull*/
	MGPIO_voidSetPinOutPutType(_GPIOA_PORT,_PIN_0,_OUTPUT_TYPE_PUSH_PULL);
	/*Pin Speed*/
	MGPIO_voidSetPinOutSpeed(_GPIOA_PORT, _PIN_0, _OUTPUT_SPEED_LOW);

	/*Set Pin Mode --> Input*/
	//MGPIO_voidSetPinMode(_GPIOA_PORT, _PIN_1, _MODE_INPUT) ;   //EXTI1
	MGPIO_voidSetPinMode(_GPIOB_PORT, _PIN_0, _MODE_INPUT) ;     //EXTI0

	/*Input Pull Type*/
	//MGPIO_voidSetPullType(_GPIOA_PORT, _PIN_1, _PULL_UP);
	MGPIO_voidSetPullType(_GPIOB_PORT, _PIN_0, _PULL_UP);



	/* Loop forever */
	while(1)
	{
	}
}
















