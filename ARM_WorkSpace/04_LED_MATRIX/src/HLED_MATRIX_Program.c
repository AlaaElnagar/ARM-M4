/*
 * HLED_MATRIX_Program.c
 *
 *  Created on: Jul 11, 2022
 *      Author: Ahmed Khaled Hammad
 */

/*******************************************************************************************************/
/*                                      Standard Types LIB                                             */
/*******************************************************************************************************/

#include "LSTD_TYPES.h"
#include "LERROR_STATES.h"
#include "LBIT_MATH.h"


/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      MCAL Components                                                */
/*******************************************************************************************************/


#include "MGPIO_interface.h"
#include "MSYSTICK_Interface.h"

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      HAL Components                                                */
/*******************************************************************************************************/


#include "HLED_MATRIX_Interface.h"
#include "HLED_MATRIX_Config.h"
#include "HLED_MATRIX_Privaite.h"

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      Functions Implementations                                      */
/*******************************************************************************************************/

/*#####################################################################################################*/
/*#####################################################################################################*/

void HLEDMAT_voidInit(void)
{

	/*Set Pin Mode for Row --> Output*/
	MGPIO_voidSetPinMode( HLEDMAT_ROW_0 , _MODE_OUTPUT) ;
	MGPIO_voidSetPinMode( HLEDMAT_ROW_1 , _MODE_OUTPUT) ;
	MGPIO_voidSetPinMode( HLEDMAT_ROW_2 , _MODE_OUTPUT) ;
	MGPIO_voidSetPinMode( HLEDMAT_ROW_3 , _MODE_OUTPUT) ;
	MGPIO_voidSetPinMode( HLEDMAT_ROW_4 , _MODE_OUTPUT) ;
	MGPIO_voidSetPinMode( HLEDMAT_ROW_5 , _MODE_OUTPUT) ;
	MGPIO_voidSetPinMode( HLEDMAT_ROW_6 , _MODE_OUTPUT) ;
	MGPIO_voidSetPinMode( HLEDMAT_ROW_7 , _MODE_OUTPUT) ;

	/*Set Pin Mode for Col --> Output*/

	MGPIO_voidSetPinMode( HLEDMAT_COL_0 , _MODE_OUTPUT) ;
	MGPIO_voidSetPinMode( HLEDMAT_COL_1 , _MODE_OUTPUT) ;
	MGPIO_voidSetPinMode( HLEDMAT_COL_2 , _MODE_OUTPUT) ;
	MGPIO_voidSetPinMode( HLEDMAT_COL_3 , _MODE_OUTPUT) ;
	MGPIO_voidSetPinMode( HLEDMAT_COL_4 , _MODE_OUTPUT) ;
	MGPIO_voidSetPinMode( HLEDMAT_COL_5 , _MODE_OUTPUT) ;
	MGPIO_voidSetPinMode( HLEDMAT_COL_6 , _MODE_OUTPUT) ;
	MGPIO_voidSetPinMode( HLEDMAT_COL_7 , _MODE_OUTPUT) ;

	/*Out put Push Pull for Row*/
	MGPIO_voidSetPinOutPutType(HLEDMAT_ROW_0,_OUTPUT_TYPE_PUSH_PULL);
	MGPIO_voidSetPinOutPutType(HLEDMAT_ROW_1,_OUTPUT_TYPE_PUSH_PULL);
	MGPIO_voidSetPinOutPutType(HLEDMAT_ROW_2,_OUTPUT_TYPE_PUSH_PULL);
	MGPIO_voidSetPinOutPutType(HLEDMAT_ROW_3,_OUTPUT_TYPE_PUSH_PULL);
	MGPIO_voidSetPinOutPutType(HLEDMAT_ROW_4,_OUTPUT_TYPE_PUSH_PULL);
	MGPIO_voidSetPinOutPutType(HLEDMAT_ROW_5,_OUTPUT_TYPE_PUSH_PULL);
	MGPIO_voidSetPinOutPutType(HLEDMAT_ROW_6,_OUTPUT_TYPE_PUSH_PULL);
	MGPIO_voidSetPinOutPutType(HLEDMAT_ROW_7,_OUTPUT_TYPE_PUSH_PULL);

	/*Out put Push Pull for Col*/
	MGPIO_voidSetPinOutPutType(HLEDMAT_COL_0,_OUTPUT_TYPE_PUSH_PULL);
	MGPIO_voidSetPinOutPutType(HLEDMAT_COL_1,_OUTPUT_TYPE_PUSH_PULL);
	MGPIO_voidSetPinOutPutType(HLEDMAT_COL_2,_OUTPUT_TYPE_PUSH_PULL);
	MGPIO_voidSetPinOutPutType(HLEDMAT_COL_3,_OUTPUT_TYPE_PUSH_PULL);
	MGPIO_voidSetPinOutPutType(HLEDMAT_COL_4,_OUTPUT_TYPE_PUSH_PULL);
	MGPIO_voidSetPinOutPutType(HLEDMAT_COL_5,_OUTPUT_TYPE_PUSH_PULL);
	MGPIO_voidSetPinOutPutType(HLEDMAT_COL_6,_OUTPUT_TYPE_PUSH_PULL);
	MGPIO_voidSetPinOutPutType(HLEDMAT_COL_7,_OUTPUT_TYPE_PUSH_PULL);

	/*Pin Speed for Rows*/
	MGPIO_voidSetPinOutSpeed(HLEDMAT_ROW_0, _OUTPUT_SPEED_LOW);
	MGPIO_voidSetPinOutSpeed(HLEDMAT_ROW_1, _OUTPUT_SPEED_LOW);
	MGPIO_voidSetPinOutSpeed(HLEDMAT_ROW_2, _OUTPUT_SPEED_LOW);
	MGPIO_voidSetPinOutSpeed(HLEDMAT_ROW_3, _OUTPUT_SPEED_LOW);
	MGPIO_voidSetPinOutSpeed(HLEDMAT_ROW_4, _OUTPUT_SPEED_LOW);
	MGPIO_voidSetPinOutSpeed(HLEDMAT_ROW_5, _OUTPUT_SPEED_LOW);
	MGPIO_voidSetPinOutSpeed(HLEDMAT_ROW_6, _OUTPUT_SPEED_LOW);
	MGPIO_voidSetPinOutSpeed(HLEDMAT_ROW_7, _OUTPUT_SPEED_LOW);

	/*Pin Speed for Cols*/
	MGPIO_voidSetPinOutSpeed(HLEDMAT_COL_0, _OUTPUT_SPEED_LOW);
	MGPIO_voidSetPinOutSpeed(HLEDMAT_COL_1, _OUTPUT_SPEED_LOW);
	MGPIO_voidSetPinOutSpeed(HLEDMAT_COL_2, _OUTPUT_SPEED_LOW);
	MGPIO_voidSetPinOutSpeed(HLEDMAT_COL_3, _OUTPUT_SPEED_LOW);
	MGPIO_voidSetPinOutSpeed(HLEDMAT_COL_4, _OUTPUT_SPEED_LOW);
	MGPIO_voidSetPinOutSpeed(HLEDMAT_COL_5, _OUTPUT_SPEED_LOW);
	MGPIO_voidSetPinOutSpeed(HLEDMAT_COL_6, _OUTPUT_SPEED_LOW);
	MGPIO_voidSetPinOutSpeed(HLEDMAT_COL_7, _OUTPUT_SPEED_LOW);

}

void HLEDMAT_voidDisplayFrame(u8 *Copy_u8Frame)
{
	while(1)
	{
		/*Column 0*/
		/*Disable  All Columns*/
		DisableAllCols();
		/*Set Row Value*/
		SetRowValues(Copy_u8Frame[0]);
		/*Enable Column 0*/
		MGPIO_voidWriteData(HLEDMAT_COL_0, _LOW) ;
		_delay_ms(2500) ; //2.5 ms

		/*Column 1*/
		/*Disable  All Columns*/
		DisableAllCols();
		/*Set Row Value*/
		SetRowValues(Copy_u8Frame[1]);
		/*Enable Column 1*/
		MGPIO_voidWriteData(HLEDMAT_COL_1, _LOW) ;
		_delay_ms(2500) ; //2.5 ms

		/*Column 2*/
		/*Disable  All Columns*/
		DisableAllCols();
		/*Set Row Value*/
		SetRowValues(Copy_u8Frame[2]);
		/*Enable Column 2*/
		MGPIO_voidWriteData(HLEDMAT_COL_2, _LOW) ;
		_delay_ms(2500) ; //2.5 ms

		/*Column 3*/
		/*Disable  All Columns*/
		DisableAllCols();
		/*Set Row Value*/
		SetRowValues(Copy_u8Frame[3]);
		/*Enable Column 3*/
		MGPIO_voidWriteData(HLEDMAT_COL_3, _LOW) ;
		_delay_ms(2500) ; //2.5 ms

		/*Column 4*/
		/*Disable  All Columns*/
		DisableAllCols();
		/*Set Row Value*/
		SetRowValues(Copy_u8Frame[4]);
		/*Enable Column 4*/
		MGPIO_voidWriteData(HLEDMAT_COL_4, _LOW) ;
		_delay_ms(2500) ; //2.5 ms

		/*Column 5*/
		/*Disable  All Columns*/
		DisableAllCols();
		/*Set Row Value*/
		SetRowValues(Copy_u8Frame[5]);
		/*Enable Column 5*/
		MGPIO_voidWriteData(HLEDMAT_COL_5, _LOW) ;
		_delay_ms(2500) ; //2.5 ms

		/*Column 6*/
		/*Disable  All Columns*/
		DisableAllCols();
		/*Set Row Value*/
		SetRowValues(Copy_u8Frame[6]);
		/*Enable Column 6*/
		MGPIO_voidWriteData(HLEDMAT_COL_6, _LOW) ;
		_delay_ms(2500) ; //2.5 ms

		/*Column 7*/
		/*Disable  All Columns*/
		DisableAllCols();
		/*Set Row Value*/
		SetRowValues(Copy_u8Frame[7]);
		/*Enable Column 7*/
		MGPIO_voidWriteData(HLEDMAT_COL_7, _LOW) ;
		_delay_ms(2500) ; //2.5 ms

	}
}

static void DisableAllCols(void)
{

	MGPIO_voidWriteData(HLEDMAT_COL_0, _HIGH) ;
	MGPIO_voidWriteData(HLEDMAT_COL_1, _HIGH) ;
	MGPIO_voidWriteData(HLEDMAT_COL_2, _HIGH) ;
	MGPIO_voidWriteData(HLEDMAT_COL_3, _HIGH) ;
	MGPIO_voidWriteData(HLEDMAT_COL_4, _HIGH) ;
	MGPIO_voidWriteData(HLEDMAT_COL_5, _HIGH) ;
	MGPIO_voidWriteData(HLEDMAT_COL_6, _HIGH) ;
	MGPIO_voidWriteData(HLEDMAT_COL_7, _HIGH) ;

}

static void SetRowValues(u8 Copy_u8Value)
{
	u8 Local_u8BIT ;

	Local_u8BIT = GET_BIT(Copy_u8Value,0);
	MGPIO_voidWriteData(HLEDMAT_ROW_0, Local_u8BIT) ;
	Local_u8BIT = GET_BIT(Copy_u8Value,1);
	MGPIO_voidWriteData(HLEDMAT_ROW_1, Local_u8BIT) ;
	Local_u8BIT = GET_BIT(Copy_u8Value,2);
	MGPIO_voidWriteData(HLEDMAT_ROW_2, Local_u8BIT) ;
	Local_u8BIT = GET_BIT(Copy_u8Value,3);
	MGPIO_voidWriteData(HLEDMAT_ROW_3, Local_u8BIT) ;
	Local_u8BIT = GET_BIT(Copy_u8Value,4);
	MGPIO_voidWriteData(HLEDMAT_ROW_4, Local_u8BIT) ;
	Local_u8BIT = GET_BIT(Copy_u8Value,5);
	MGPIO_voidWriteData(HLEDMAT_ROW_5, Local_u8BIT) ;
	Local_u8BIT = GET_BIT(Copy_u8Value,6);
	MGPIO_voidWriteData(HLEDMAT_ROW_6, Local_u8BIT) ;
	Local_u8BIT = GET_BIT(Copy_u8Value,7);
	MGPIO_voidWriteData(HLEDMAT_ROW_7, Local_u8BIT) ;
}


static void _delay_ms( u32 Copy_u32Time ){

	MSTK_voidInit();
	/* Disable INT */
	MSTK_voidINTStatus( MSTK_INT_DIS );
	MSTK_voidStart( Copy_u32Time * 2000 );
	/* Wiat Flag Polling */
	while( MSTK_u8ReadFlag() == 0 );

}
