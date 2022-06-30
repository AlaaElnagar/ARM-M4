/*
 * Keypad_int.h
 *
 *  Created on: Feb 13, 2022
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef TEMPERATUE_SENSOR_INT_H_
#define TEMPERATUE_SENSOR_INT_H_



/****************************************************/
/*			TEMPERATURE SENSORS CHANNELS Num		*/
/****************************************************/
#define TEMP_ROOM_CHANNEL			0		        //
                                                    //
#define TEMP_KITCHEN_CHANNEL		1               //
                                                    //
#define TEMP_LIVING_CHANNEL			2               //
                                                    //
#define TEMP_HALLWAY_CHANNEL		3               //
                                                    //
#define TEMP_BATHROOM_CHANNEL		4               //
/****************************************************/
/****************************************************/



void TempSensor_vInit(void);

void TempSensor_vGetTemperature(u16 * Copy_pu8Value, u8 Copy_u8Channel);


#endif /* KEYPAD_INT_H_ */
