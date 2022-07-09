/*
 * HTFT_Program.c
 *
 *  Created on: Jul 9, 2022
 *      Author: Ahmed Khaled Hammad
 */


#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"

#include "MGPIO_interface.h"
#include "MSPI_Interface.h"
#include "MSYSTICK_Interface.h"

#include "HTFT_Interface.h"
#include "HTFT_Private.h"
#include "HTFT_Config.h"

void HTFT_voidInitialize   (void)
{
	/* Reset Pulse */
	MGPIO_voidWriteData(TFT_RST_PIN,_HIGH);
	MSTK_voidDelayMs(100);
	MGPIO_voidWriteData(TFT_RST_PIN,_LOW);
	MSTK_voidDelayMs(1);
	MGPIO_voidWriteData(TFT_RST_PIN,_HIGH);
	MSTK_voidDelayMs(100);
	MGPIO_voidWriteData(TFT_RST_PIN,_LOW);
	MSTK_voidDelayMs(100);
	MGPIO_voidWriteData(TFT_RST_PIN,_HIGH);
	MSTK_voidDelayMs(120000);

	/* Sleep Out Command */
	voidWriteCommand(0x11);

	/* Wait 150 ms */
	MSTK_voidDelayMs(150000);
	/* Color Mode Command */
	voidWriteCommand(0x3A);
	voidWriteData   (0x05);

	/* Display On Command */
	voidWriteCommand(0x29);
}


void HTFT_voidDisplayImage (const u16* Copy_Image)
{
	u16 counter;
	u8 Data;

	/* Set X Address */
	voidWriteCommand(0x2A);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(127);

	/* Set Y Address */
	voidWriteCommand(0x2B);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(159);

	/* RAM Write */
	voidWriteCommand(0x2C);

	for(counter = 0; counter< 20480;counter++)
	{
		Data = Copy_Image[counter] >> 8;

		/* Write the _HIGH byte */
		voidWriteData(Data);
		/* Write the _LOW byte */
		Data = Copy_Image[counter] & 0x00ff;
		voidWriteData(Data);
	}


}

static void voidWriteCommand(u8 Copy_u8Command)
{

	/* Set A0 Pin to _LOW */
	MGPIO_voidWriteData(TFT_A0_PIN,_LOW);

	/* Send Command over SPI */
	MSPI1_voidSendDataU8(Copy_u8Command) ;
}

static void voidWriteData   (u8 Copy_u8Data)
{

	/* Set A0 Pin to _HIGH */
	MGPIO_voidWriteData(TFT_A0_PIN,_HIGH);

	/* Send data over SPI */
	MSPI1_voidSendDataU8(Copy_u8Data) ;
}



