/*
 * Keypad.config.h
 *
 *  Created on: Feb 13, 2022
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef HAL_TEMPERATUE_SENSOR_CONFIG_H_
#define HAL_TEMPERATUE_SENSOR_CONFIG_H_

/****************************************************/
/*			TEMPERATURE SENSORS PIN LAYOUT			*/
/****************************************************/
#define TEMP_ROOM_GRP			_GPIOA_PORT         //
#define TEMP_ROOM_PIN			_PIN_0              //
#define TEMP_ROOM_CHANNEL			0		        //
                                                    //
#define TEMP_KITCHEN_GRP		_GPIOA_PORT         //
#define TEMP_KITCHEN_PIN		_PIN_1              //
#define TEMP_KITCHEN_CHANNEL		1               //
                                                    //
#define TEMP_LIVING_GRP			_GPIOA_PORT         //
#define TEMP_LIVING_PIN			_PIN_2              //
#define TEMP_LIVING_CHANNEL			2               //
                                                    //
#define TEMP_HALLWAY_GRP		_GPIOA_PORT         //
#define TEMP_HALLWAY_PIN		_PIN_3              //
#define TEMP_HALLWAY_CHANNEL		3               //
                                                    //
#define TEMP_BATHROOM_GRP		_GPIOA_PORT         //
#define TEMP_BATHROOM_PIN		_PIN_4              //
#define TEMP_BATHROOM_CHANNEL		4               //
/****************************************************/
/****************************************************/

#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
