/*
 * Keypad.config.h
 *
 *  Created on: 31/3/2022
 *      Author: Mostafa Diab
 */

#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_

#define ROW_NUM			4
#define COL_NUM			3

#define R1_GRP			_GPIOD_PORT
#define R1_PIN			_PIN_3

#define R2_GRP			_GPIOD_PORT
#define R2_PIN			_PIN_4

#define R3_GRP			_GPIOD_PORT
#define R3_PIN			_PIN_5

#define R4_GRP			_GPIOD_PORT
#define R4_PIN			_PIN_6


#define C1_GRP			_GPIOD_PORT
#define C1_PIN			_PIN_0

#define C2_GRP			_GPIOD_PORT
#define C2_PIN			_PIN_1

#define C3_GRP			_GPIOD_PORT
#define C3_PIN			_PIN_2



#define KEY_VALUES		{{'*','0','#'},\
						 {'7','8','9'},\
						 {'4','5','6'},\
						 {'1','2','3'}}


#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
