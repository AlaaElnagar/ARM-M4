/*
 * main.c
 *
 *  Created on: Jul 1, 2022
 *      Author: AlaaElnagar
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_Interface.h"
#include "MGPIO_interface.h"
#include "MGPIO_private.h"
#include "MRCC_Private.h"

int main (){
	MRCC_voidInitSysClock()   ;

	MRCC_voidEnablePerClock(AHB1_bus , GPIOA_PORT) ;
	MRCC_voidEnablePerClock(AHB1_bus , GPIOB_PORT) ;
	MRCC_voidEnablePerClock(AHB1_bus , GPIOC_PORT) ;

    MGPIO_voidSetPinDirection(GPIOA_PORT ,MGPIO_Pin0  ,GPIO_OUTPUT_PP_VeryHighSpeed  ) ;
    MGPIO_voidSetPinDirection(GPIOA_PORT ,MGPIO_Pin1  ,GPIO_INPUT_PD  ) ;
	MGPIO_voidSetPinDirection(GPIOC_PORT ,MGPIO_Pin13 ,GPIO_OUTPUT_PP_VeryHighSpeed  ) ;


	while(1)
	{
	MGPIO_voidSetPinValue(GPIOC_PORT ,MGPIO_Pin13 ,Gpio_Pin_LOW  ) ;
	MGPIO_voidSetPinValue(GPIOA_PORT ,MGPIO_Pin0 ,Gpio_Pin_LOW ) ;

		for(int i=0; i<80000;i++);
	MGPIO_voidSetPinValue(GPIOC_PORT ,MGPIO_Pin13 ,Gpio_Pin_High  ) ;
	MGPIO_voidSetPinValue(GPIOA_PORT ,MGPIO_Pin0 ,Gpio_Pin_High ) ;

		for(int i=0; i<80000;i++);
	volatile u8 x = MGPIO_u8GetPinValue(GPIOA_PORT ,MGPIO_Pin1 );
	}

	return 0;

}

