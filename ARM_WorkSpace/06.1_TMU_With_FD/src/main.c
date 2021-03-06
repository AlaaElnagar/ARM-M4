
#include "LSTD_TYPES.h"

#include "MRCC_interface.h"
#include "MGPIO_interface.h"

#include "STMU_Interface.h"



void APP_LED1(void);
void APP_LED2(void);
void APP_LED3(void);


#define LED_NUM   3

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

    /*Create Tasks*/
	STMU_voidCreateTask(0, 1000, APP_LED1,0) ;
	STMU_voidCreateTask(1, 2000, APP_LED2,1) ;
	STMU_voidCreateTask(2, 3000, APP_LED3,2) ;

	/*Start Scheduling*/
	STMU_voidStart();
	while(1)
	{
	}
}

void APP_LED1(void)
{

 static u8 LOC_u8BitVal = 0 ;
 TOG_BIT(LOC_u8BitVal,0);
 MGPIO_voidWriteData(_GPIOA_PORT, _PIN_0, LOC_u8BitVal) ;

}
void APP_LED2(void)
{

 static u8 LOC_u8BitVal = 0 ;
 TOG_BIT(LOC_u8BitVal,0);
 MGPIO_voidWriteData(_GPIOA_PORT, _PIN_1, LOC_u8BitVal) ;

}
void APP_LED3(void)
{

 static u8 LOC_u8BitVal = 0 ;
 TOG_BIT(LOC_u8BitVal,0);
 MGPIO_voidWriteData(_GPIOA_PORT, _PIN_2, LOC_u8BitVal) ;

}
