
#include "LSTD_TYPES.h"

#include "MRCC_interface.h"
#include "MGPIO_interface.h"

#include "MSYSTICK_Interface.h"


#include "MGPIO_private.h"

#include "file.h"




#define LED_NUM   8

volatile u16 i = 0 ;

void App_voidSetDAC(void);



int main(void)
{

	/*System Clock is 16MHz from HSI*/
	MRCC_voidInitSystemClk();

	/*Enable GPIO Peripheral clock*/
	MRCC_voidEnablePeripheralClock(AHB1,_PERIPHERAL_EN_GPIOA ) ;

	for(u8 PIN_NUM = 0 ; PIN_NUM < LED_NUM ; PIN_NUM++)
	{
		/*Set Pin Mode --> Output*/
		MGPIO_voidSetPinMode(_GPIOA_PORT, PIN_NUM, _MODE_OUTPUT) ;

		/*Out put Push Pull*/
		MGPIO_voidSetPinOutPutType(_GPIOA_PORT,PIN_NUM,_OUTPUT_TYPE_PUSH_PULL);

		/*Pin Speed*/
		MGPIO_voidSetPinOutSpeed(_GPIOA_PORT, PIN_NUM, _OUTPUT_SPEED_LOW);

	}

	MSTK_voidInit() ;

	/*Enable Interrupt*/
    MSTK_voidINTStatus(MSTK_INT_EN) ;

	/*For 125 Micro Second*/
	MSTK_voidStart(250) ;
    /*Set  CallBack*/
	MSTK_voidSetCallBack(App_voidSetDAC) ;

	while(1)
	{
	}
}

void App_voidSetDAC(void)
{

   GPIOA_ODR = FADY_SHAY_raw[i] ;
   i++ ;
   if(i == 20155)
   {
	   i = 0 ;
   }
}

