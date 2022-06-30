/*
 * LED
 *
 * 
 *  Author: ahmed salah elewa
 */ 


#ifndef RELAY_CONFIG_H_
#define RELAY_CONFIG_H_
//#include "GPIO_interface.h"

/* select number of relays */

#define NUM_RELAYS_USED	  2


typedef struct  {
	u8 RELAY_PORT;
	u8 RELAY_PIN;
} RELAY_t ;

RELAY_t RELAY_NUM[NUM_RELAYS_USED] ;


#endif /* relay_CFG_H_ */
