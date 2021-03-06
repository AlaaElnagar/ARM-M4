
#include "LSTD_TYPES.h"

#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MNVIC_Interface.h"
#include "MDMA_Interface.h"
#include "MSPI_Interface.h"
#include "HTFT_Interface.h"
#include "image.h"


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

	MGPIO_voidSetPinMode(_GPIOA_PORT, _PIN_5, _MODE_ALTF);
	MGPIO_voidSetPinMode(_GPIOA_PORT, _PIN_7, _MODE_ALTF);

	MGPIO_voidSetPinAltFn(_GPIOA_PORT, _PIN_5, _ALTFN_5);    //SPI1_SCK-->SPI1
	MGPIO_voidSetPinAltFn(_GPIOA_PORT, _PIN_7, _ALTFN_5);     //SPI1_MOSI-->SPI1
	/*************************************************************************************************************************/
	/********************************************Step 4: initialize Output Pins  in System ***********************************/
	/*************************************************************************************************************************/
	for(int PIN =0; PIN<3; PIN++)
	{                                                                              /* A0   */
		/*Set Pin Mode --> Output*/                                                /* RST  */
		MGPIO_voidSetPinMode(_GPIOA_PORT, PIN, _MODE_OUTPUT) ;                     /* CLK  */
		/*Out put Push Pull*/                                                      /* MOSI */
		MGPIO_voidSetPinOutPutType(_GPIOA_PORT,PIN,_OUTPUT_TYPE_PUSH_PULL);
		/*Pin Speed*/
		MGPIO_voidSetPinOutSpeed(_GPIOA_PORT, PIN, _OUTPUT_SPEED_LOW);
	}


	/*************************************************************************************************************************/
	/********************************************Step 6: Initialize SPI1 ***************************************************/
	/*************************************************************************************************************************/


	MSPI1_voidInit() ;

	/*************************************************************************************************************************/
	/********************************************Step 6:  initialize system Peripherials *************************************/
	/*************************************************************************************************************************/

	/* TFT Init */
	HTFT_voidInitialize();

	/* Display Image */
	HTFT_voidDisplayImage(image);


	/* Loop forever */
	while(1)
	{
	}
}




