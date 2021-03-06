
#include "LSTD_TYPES.h"

#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MNVIC_Interface.h"
#include "MDMA_Interface.h"
#include "MSPI_Interface.h"

   u8 var = 0 ;
void SPI_Funcation_App(void);
int main(void)
{
	/*************************************************************************************************************************/
	/********************************Step 1: initialize System Clock is 16MHz from HSI****************************************/
	/*************************************************************************************************************************/

	MRCC_voidInitSystemClk();

	/*************************************************************************************************************************/
	/********************************************Step 2: Enable peripherls clock**********************************************/
	/*************************************************************************************************************************/

	/*Enable GPIO Peripheral clock*/
	MRCC_voidEnablePeripheralClock(AHB1,_PERIPHERAL_EN_GPIOA ) ;


	/* Config RCC GPIO SPI */
	MRCC_voidEnablePeripheralClock(APB2, PERIPHERAL_EN_SPI1); //Enable CLK Of UART1   At APB2


	/*************************************************************************************************************************/
	/********************************************Step 3: Configur SPI1  Pins**************************************************/
	/*************************************************************************************************************************/


	/* GPIO At HW MODE MOSI(AF,OUTPUT)Like SPI1--->AF(5)*/
	/* GPIO At HW MODE NSS(AF,OUTPUT)Like SPI1--->AF(5) */
	/* GPIO At HW MODE MISO(AF,INPUT)Like SPI1--->AF(5) */

	//MGPIO_voidSetPinMode(_GPIOA_PORT, _PIN_4, _MODE_ALTF);
	MGPIO_voidSetPinMode(_GPIOA_PORT, _PIN_5, _MODE_ALTF);
	MGPIO_voidSetPinMode(_GPIOA_PORT, _PIN_6, _MODE_ALTF);
	MGPIO_voidSetPinMode(_GPIOA_PORT, _PIN_7, _MODE_ALTF);

	//MGPIO_voidSetPinAltFn(_GPIOA_PORT, _PIN_4, _ALTFN_5);    //SPI1_NSS-->SPI
	MGPIO_voidSetPinAltFn(_GPIOA_PORT, _PIN_5, _ALTFN_5);    //SPI1_SCK-->SPI
	MGPIO_voidSetPinAltFn(_GPIOA_PORT, _PIN_6, _ALTFN_5);     //SPI1_MISO-->SPI
	MGPIO_voidSetPinAltFn(_GPIOA_PORT, _PIN_7, _ALTFN_5);     //SPI1_MOSI-->UART1
	/*************************************************************************************************************************/
	/********************************************Step 4: initialize Output Pins  in System ***********************************/
	/*************************************************************************************************************************/
	for(int PIN =1; PIN<2; PIN++)
	{
		/*Set Pin Mode --> Output*/
		MGPIO_voidSetPinMode(_GPIOA_PORT, PIN, _MODE_OUTPUT) ;
		/*Out put Push Pull*/
		MGPIO_voidSetPinOutPutType(_GPIOA_PORT,PIN,_OUTPUT_TYPE_PUSH_PULL);
		/*Pin Speed*/
		MGPIO_voidSetPinOutSpeed(_GPIOA_PORT, PIN, _OUTPUT_SPEED_LOW);
	}

	/*************************************************************************************************************************/
	/********************************************Step 5: Enable Peripherials interrupt from NVIC *****************************/
	/*************************************************************************************************************************/

	MNVIC_voidEnableInterrupt(35) ;              //Enable SPI from NVIC

	/*************************************************************************************************************************/
	/********************************************Step 6: Initialize USART1 ***************************************************/
	/*************************************************************************************************************************/
    /*Set CallBack Function*/
	MSPI1_voidSetCallBack(SPI_Funcation_App);

	MSPI1_voidInit() ;

	/*************************************************************************************************************************/
	/********************************************Step 6:  initialize system Peripherials *************************************/
	/*************************************************************************************************************************/



	/* Loop forever */
	while(1)
	{
		var = MSPI1_voidSendDataU8((u8)5) ;
	}
}

void SPI_Funcation_App(void){


	u8 LOC_u8Val = MSPI1_voidSendDataU8((u8)0) ;
	if(LOC_u8Val== 1)
	{
		MGPIO_voidWriteData(_GPIOA_PORT, _PIN_1, _HIGH) ;
	}
	else
	{
		/*Do Nothing*/
	}

}







