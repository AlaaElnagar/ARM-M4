/*
 * Keypad_int.h
 *
 *  Created on: Feb 13, 2022
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef KEYPAD_INT_H_
#define KEYPAD_INT_H_


ES_t Keypad_enuInit(void);

ES_t Keypad_enuGetPressedKey(u8 * Copy_pu8Value);

#define KEYPAD_NOT_PRESSED 		0xff

#endif /* KEYPAD_INT_H_ */
