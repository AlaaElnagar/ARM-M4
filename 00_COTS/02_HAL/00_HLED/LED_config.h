/*
 * LED
 *
 * 
 *  Author: ahmed salah elewa
 */ 


#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_
//#include "GPIO_interface.h"

/* select number of leds */
#define NUM_LEDS_USED	  5

typedef struct  {
	u8 LED_PORT;
	u8 LED_PIN;
} LED_t ;

LED_t LED_NUM[NUM_LEDS_USED] ;


#endif /* LED_CFG_H_ */
