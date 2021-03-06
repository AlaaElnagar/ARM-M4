
#include "LSTD_TYPES.h"

#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MNVIC_Interface.h"
#include "MEXTI_interface.h"


#define NVIC_EXTI0     6
#define NVIC_EXTI1     7

u8 volatile Flag = 0;

void EXT0_CALLBACK(){

	if( Flag == 0 ){
		MGPIO_voidWriteData(_GPIOA_PORT, _PIN_0, _HIGH) ;
		Flag = 1 ;
	}
	else if(Flag == 1)
	{
		MGPIO_voidWriteData(_GPIOA_PORT, _PIN_0, _LOW) ;
		Flag = 0 ;
	}
}

void EXT1_CALLBACK(){

	if( Flag == 1 ){

		MGPIO_voidWriteData(_GPIOA_PORT, _PIN_0, _LOW) ;
		Flag = 0 ;
	}
}


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


	//Initialize Interrupt Group
//	MNVIC_voidInitInterruptGroup(NVIC_GroupMode_g16s0);
//	//NO_SUB_PRIORITY
//	MNVIC_voidSetInterruptPriority(NVIC_EXTI0,NVIC_GroupMode_g16s0, 1 , 0);
//	MNVIC_voidSetInterruptPriority(NVIC_EXTI1,NVIC_GroupMode_g16s0, 2 , 0);   //High Priority

	MEXTI0_voidSetCallBack(EXT0_CALLBACK);
	//MEXTI1_voidSetCallBack(EXT1_CALLBACK);


	//MEXTI_voidSetEXTIConfiguration(EXTI1, _GPIOA_PORT);
	MEXTI_voidSetEXTIConfiguration(EXTI0, _GPIOB_PORT);

	MEXTI_voidSetSignalLatch(EXTI0, FALLING_EDGE);
	//MEXTI_voidSetSignalLatch(EXTI1, FALLING_EDGE);

	//Enable Peripheral Interrupt
	MNVIC_voidEnableInterrupt(NVIC_EXTI0);
	//MNVIC_voidEnableInterrupt(NVIC_EXTI1);

	/* Loop forever */
	while(1)
	{
	}
}
















