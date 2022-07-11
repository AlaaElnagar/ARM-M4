#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"

#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MNVIC_Interface.h"
#include "MEXTI_interface.h"
#include "MSYSTICK_Interface.h"


#define NVIC_EXTI0     6


volatile u8 Global_u8Flag = 0 ;

volatile u32 Global_u32FrameData[50] = {0} ; // 32 + 1 start = 33

volatile u8 Global_u8EdgeCounter   = 0 ;


volatile u8 Global_u8Data =  0 ;

void App_voidPlay(void)
{

	switch(Global_u8Data)
	{
	case 70: MGPIO_voidWriteData(_GPIOA_PORT, _PIN_1, _HIGH);
	break ;
	case 69 : MGPIO_voidWriteData(_GPIOA_PORT, _PIN_1, _LOW);
	break ;
	}
}

/*Called in the End of Frame */
void App_voidTakeAction(void)
{
	//asm("NOP") ;
	u8 i ;

	Global_u8Data = 0 ;
	if((Global_u32FrameData[0]>= 10000) && (Global_u32FrameData[0] <= 14000))
	{
		for(i = 0 ; i<8 ;i++)
		{
			if ((Global_u32FrameData[17+i]>= 2000) && (Global_u32FrameData[17+i] <= 2300))
			{
				/*Logic one*/
				SET_BIT(Global_u8Data,i);
			}
			else
			{
				/*Logic Zero*/
				CLR_BIT(Global_u8Data,i);
			}
		}
		App_voidPlay();
	}
	else
	{
		/*invalid Frame*/
	}
	Global_u8Flag = 0 ;
	Global_u32FrameData[0] = 0 ;
	Global_u8EdgeCounter   = 0 ;
}

void App_voidGetFrame(){

	// asm("NOP") ;

	if(Global_u8Flag == 0)
	{
		/*Start Timer*/
		MSTK_voidSetIntervalSingle(1000000,App_voidTakeAction);
		Global_u8Flag = 1 ;
	}
	else
	{
		Global_u32FrameData[Global_u8EdgeCounter] = MSTK_u32GetElapsedTime() ;
		MSTK_voidSetIntervalSingle(1000000,App_voidTakeAction);
		Global_u8EdgeCounter++;
	}

}



int main(void)
{
	/*System Clock is 16MHz from HSI*/
	MRCC_voidInitSystemClk();

	/*Enable GPIO Peripheral clock*/
	MRCC_voidEnablePeripheralClock(AHB1,_PERIPHERAL_EN_GPIOA ) ;
	MRCC_voidEnablePeripheralClock(APB2, PERIPHERAL_EN_SYSCFG) ;

	for(u8 PIN = 1 ;PIN <=3 ;PIN++ )
	{
		/*Set Pin Mode --> Output*/
		MGPIO_voidSetPinMode(_GPIOA_PORT, PIN, _MODE_OUTPUT) ;
		/*Out put Push Pull*/
		MGPIO_voidSetPinOutPutType(_GPIOA_PORT,PIN,_OUTPUT_TYPE_PUSH_PULL);
		/*Pin Speed*/
		MGPIO_voidSetPinOutSpeed(_GPIOA_PORT, PIN, _OUTPUT_SPEED_LOW);
	}


	/*Set Pin Mode --> Input*/
	MGPIO_voidSetPinMode(_GPIOA_PORT, _PIN_0, _MODE_INPUT) ;     //EXTI0


	/*Input Pull Type*/
	MGPIO_voidSetPullType(_GPIOA_PORT, _PIN_0, _PULL_OFF);


	//Initialize Interrupt Group
	//	MNVIC_voidInitInterruptGroup(NVIC_GroupMode_g16s0);
	//	//NO_SUB_PRIORITY
	//	MNVIC_voidSetInterruptPriority(NVIC_EXTI0,NVIC_GroupMode_g16s0, 1 , 0);
	//	MNVIC_voidSetInterruptPriority(NVIC_EXTI1,NVIC_GroupMode_g16s0, 2 , 0);   //High Priority

	MEXTI0_voidSetCallBack(App_voidGetFrame);


	MEXTI_voidSetEXTIConfiguration(EXTI0, _GPIOA_PORT);

	MEXTI_voidSetSignalLatch(EXTI0, FALLING_EDGE);

	//Enable Peripheral Interrupt
	MNVIC_voidEnableInterrupt(NVIC_EXTI0);

	/*SysTick Init*/
	MSTK_voidInit(); /*Enable SysTick AHB/8 = 2MHZ , 1 count = 0.5 Micro second  */
	/* Loop forever */
	while(1)
	{
	}
}
















