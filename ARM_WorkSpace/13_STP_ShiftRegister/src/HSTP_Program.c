/*
 * HSTP_Program.c
 *
 *  Created on: Jul 11, 2022
 *      Author: Ahmed Khaled Hammad
 */

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"

#include "MGPIO_interface.h"
#include "MSYSTICK_Interface.h"


#include "HSTP_Config.h"
#include "HSTP_Interface.h"

void HSTP_voidSendSynchronus(u8 Copy_u8DataToSend)
{
	s8 Local_s8Counter;
	u8 Local_u8Bit;
	for (Local_s8Counter = 7 ; Local_s8Counter >=0 ; Local_s8Counter--)
	{
		/* Send bit by bit strating from MSb */
		Local_u8Bit =  GET_BIT(Copy_u8DataToSend,Local_s8Counter);

		MGPIO_voidWriteData(HSTP_SERIAL_DATA,Local_u8Bit) ;
		/* Send Pulse to Shift Clock */
		MGPIO_voidWriteData(HSTP_SHIFT_CLOCK,_HIGH) ;
		_delay_us(5);
		MGPIO_voidWriteData(HSTP_SHIFT_CLOCK,_LOW) ;
		_delay_us(5);
	}

			/* Send Pulse to Shift Clock */
	MGPIO_voidWriteData(HSTP_STORE_CLOCK,_HIGH);
	_delay_us(5);
	MGPIO_voidWriteData(HSTP_STORE_CLOCK,_LOW);
	_delay_us(5);

}
