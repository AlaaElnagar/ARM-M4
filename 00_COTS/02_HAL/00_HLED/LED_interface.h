/*
 * LED
 *
 * 
 *  Author: ahmed salah elewa
 */ 


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#include "LIB/STD_TYPES.h"
#include "MCAL/GPIO/GPIO_interface.h"


/* put names of leds according to number of leds (NUM_LEDS_USED) in  LED_config.h    */

enum e_led{
	Room_Light ,
	Living_Light,
	Kitchen_Light,
	Bathroom_Light,
	Hallway_Light
};

void LED_vInit(enum e_led led, u8 _PORT , u8 _PIN);
void LED_ON(enum e_led led);
void LED_OFF(enum e_led led);
void LED_TOG(enum e_led led);



#endif /* LED_H_ */
