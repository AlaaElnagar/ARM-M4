#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"

#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MNVIC_Interface.h"
#include "MEXTI_interface.h"
#include "MSYSTICK_Interface.h"

#include "HSTP_Interface.h"


int main(void)
{
	/*System Clock is 16MHz from HSI*/
	MRCC_voidInitSystemClk();

	/*Enable GPIO Peripheral clock*/
	MRCC_voidEnablePeripheralClock(AHB1,_PERIPHERAL_EN_GPIOA ) ;

	for(u8 PIN = 0 ;PIN <3 ;PIN++ )
	{
		/*Set Pin Mode --> Output*/
		MGPIO_voidSetPinMode(_GPIOA_PORT, PIN, _MODE_OUTPUT) ;
		/*Out put Push Pull*/
		MGPIO_voidSetPinOutPutType(_GPIOA_PORT,PIN,_OUTPUT_TYPE_PUSH_PULL);
		/*Pin Speed*/
		MGPIO_voidSetPinOutSpeed(_GPIOA_PORT, PIN, _OUTPUT_SPEED_LOW);
	}

	/*SysTick Init*/
	MSTK_voidInit(); /*Enable SysTick AHB/8 = 2MHZ , 1 count = 0.5 Micro second  */

    /*Send Data Serial*/

	//HSTP_voidSendSynchronus(0xAA) ; // A = 10101010 --> 4 LEDs ON and 4 LEDs OFF
	/* Loop forever */
	while(1)
	{
		for(u8 i = 0 ; i<8 ;i++ )
		{
			HSTP_voidSendSynchronus(1<<i) ;
			_delay_ms(500);

		}
	}
}
















