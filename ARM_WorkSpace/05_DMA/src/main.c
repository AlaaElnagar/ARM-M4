
#include "LSTD_TYPES.h"

#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MNVIC_Interface.h"
#include "MDMA_Interface.h"

#define SIZE 500

#define DMA1_Stream0    11
#define DMA2_Stream0    56

#define DMA2_CHANNEL0    0

u32 SOURCE2[SIZE]={0};
u32 DESTINATION2[SIZE];



/*  DMA_APP : Copy From Memory ( Source )To Memory ( Distination)  */

/* To Transfer Data From Array To Array :

				- Using Indirect Method : For Loop -----> DST_Array[index]  = SRC_Array[index]
				- Using Direct Method ( Pointer ) : while --> *DST_Array++ = *SRC_Array++
				- Using DMA (source and destination ) the fast methode
				- Try i-- instead of i++

 * DMA Faster then Direct Then Indirect
 */

void DMA_CallBack(void){
	/* Any Action : Indicate That Transfer Complete Comlete Opration Is Done Successfuly */
	MGPIO_voidWriteData(_GPIOA_PORT, _PIN_0, _HIGH) ;
	MDMA_VidClearFlagChannel1 () ;

}
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

	/*1- Enable RCC For DMA_2*/
	//MRCC_voidEnablePeripheralClock(AHB1, _PERIPHERAL_EN_DMA1EN) ;
	MRCC_voidEnablePeripheralClock(AHB1, _PERIPHERAL_EN_DMA2EN) ;

	/* I Will Put Data At source Array And Transfer It From */
	u32 Local_u32SRC_Array[SIZE];
	/*Recive Data From Source Array*/
	u32 Local_u32DST_Array[SIZE];
	/*Init Source Array  */
	u32 Local_u32index=0 ;
	for(Local_u32index =0 ; Local_u32index <=SIZE ; Local_u32index ++)
	{
		/*Init Source Array From 0 Too Size {0,1,,2,3,..............,SIZE}*/
		Local_u32SRC_Array[Local_u32index] =Local_u32index ;
	}

	/*2- EN DMA2 Stream 0 NVIC */
	//MNVIC_voidEnableInterrupt(DMA1_Stream0) ;
	MNVIC_voidEnableInterrupt(DMA2_Stream0);
	/*Set CallBack Function*/
	MDMA_VidSetCallBackChannel1(DMA_CallBack) ;

	/*3- Init DMA */
	MDMA_vInit(DMA2_CHANNEL0);

	/*4- Set Source Address & Distination */
	MDMA_vSetAddress(Local_u32SRC_Array, Local_u32DST_Array, SIZE, DMA2_CHANNEL0) ;

	/*5- Enable DMA_2_CHANNEL0*/

	MDMA_vStreamEnable(DMA2_CHANNEL0) ;

	//For Processor
	u16 i = 0;
	for( i = 0 ; i < SIZE ;i++ ){

		DESTINATION2[i]=SOURCE2[i];

	}
	/* Loop forever */
	while(1)
	{
	}
}












